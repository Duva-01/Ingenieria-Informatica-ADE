// Solicitamos los modulos necesarios para la implementacion del sistema

var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");

var socketio = require("socket.io");

var MongoClient = require('mongodb').MongoClient;
var MongoServer = require('mongodb').Server;

var mimeTypes = { "html": "text/html", "jpeg": "image/jpeg", "jpg": "image/jpeg", "png": "image/png", "js": "text/javascript", "css": "text/css", "swf": "application/x-shockwave-flash" };

// Añadimos la funcionalidad de los correos
const nodemailer = require('nodemailer');

const transporter = nodemailer.createTransport({
   service: 'Gmail',
   auth: {
     user: 'martdiaz01.d@gmail.com',
     pass: 'fejseqbjomcawulf',
   },
 });

 const mailOptions = {
   from: 'martdiaz01.d@gmail.com',
   to: 'martdiaz01.d@gmail.com',
   subject: 'Alerta',
   text: '',
 };

// Nos creamos el servicio HTTP y dependiendo de la URI, le indicamos que utilice un archivo html u otro.

const httpServer = http.createServer((request, response) => {

   let uri = url.parse(request.url).pathname;
   if (uri == "/")
      uri = "/sistema_domotico.html";
   else if (uri == "/cliente")
      uri = "/cliente.html";

   const filename = path.join(process.cwd(), uri);

   fs.exists(filename, (exists) => {
      if (exists) {
         fs.readFile(filename, (err, data) => {
            if (!err) {
               const extension = path.extname(filename).split(".")[1];
               const mimeType = mimeTypes[extension];
               response.writeHead(200, { "Content-Type": mimeType });
               response.write(data);
               response.end();
            } else {
               response.writeHead(500, { "Content-Type": "text/plain" });
               response.write(`Error de lectura en el fichero: ${uri}`);
               response.end();
            }
         });
      } else {
         console.log(`Peticion invalida: ${uri}`);
         response.writeHead(404, { "Content-Type": "text/plain" });
         response.write("404 Not Found\n");
         response.end();
      }
   });
});

// Aqui implementamos las medidas que se van a tomar y almacenar en la base de datos

var tiempo = new Date();
var medidas_sensores = { temperatura: 0, luminosidad: 0, tiempo: tiempo };

// MongoDB para almacenar el registro de los valores tomados

MongoClient.connect("mongodb://127.0.0.1:27017/", function (err, db) {
}).then((db) => {

   // Escuchamos en el puerto 8080
   httpServer.listen(8080);

   // Iniciamos el servicio de socketio
   var io = socketio(httpServer);
   console.log("Servicio Sistema Domotico iniciado");

   // Cargamos la base de datos
   var dbo = db.db("DSD-P4");

   // Eliminamos la coleccion para solventar el problema de crear una coleccion existente
   dbo.collection("Sistema-Domotico").drop(function (err, delOK) {
      if (err) throw err;
      if (delOK) console.log("Colección existente eliminada");
   });

   // Nos creamos y conectamos a la coleccion
   dbo.createCollection("Sistema-Domotico").then((collection) => {
      // Envío y recepción de mensajes con el servicio IOT
      io.sockets.on('connection',
         function (client) {

            console.log('Nueva conexión del cliente ' + client.request.connection.remoteAddress + ':' + client.request.connection.remotePort);

            // Mostramos las medidas que haya para todos los clientes conectados
            
            io.sockets.emit('medidas-casa', medidas_sensores);
            collection.find().toArray(function (err, results) {
               client.emit('obtener-medidas', results);
            });

            // Los sensores envían los datos, y añadimos los valores al registro de la BD.
            client.on('obtener-sensores', function (data) {

               // Obtiene los valores de los sensores
               console.log(data);
               medidas_sensores = data;

               // Los mete en la coleccion creada
               collection.insertOne(data, { safe: true }).then((result) => { }).catch((err) => {
                  console.error(err);
               });

               var alerta = "Los sensores tienen unos valores correctos. Ninguna Alerta.";

               // Implementacion del agente, el cual detecta si se ha superado los umbrales 
               // establecidos y procede a regularlo.

               switch (true) {
                  case data.temperatura > 100 && data.luminosidad > 100:
                    alerta = "⚠️ ALERTA: La temperatura y la luminosidad están demasiado altas. Se cerrará la persiana y se encenderá el aire acondicionado.";
                    io.sockets.emit('cierra-persiana');
                    io.sockets.emit('enciende-aire');
                     
                    mailOptions.text = '¡Alerta! La temperatura y la luminosidad son demasiado altas en el sistema domótico.';

                    transporter.sendMail(mailOptions, (error, info) => {
                     if (error) {
                       console.log('Error al enviar el correo:', error);
                     } else {
                       console.log('Correo enviado:', info.response);
                     }
                   });
                    

                    break;
                  case data.temperatura > 100 && data.luminosidad < 0:
                    alerta = "⚠️ ALERTA: La temperatura está demasiado alta y la luminosidad demasiado baja. Se abrirá la persiana y se encenderá el aire acondicionado.";
                    io.sockets.emit('abre-persiana');
                    io.sockets.emit('enciende-aire');

                    // Envío del tweet en Twitter

                    mailOptions.text = '¡Alerta! La temperatura es demasiado alta y la luminosidad es demasiado baja en el sistema domótico.';

                    transporter.sendMail(mailOptions, (error, info) => {
                     if (error) {
                       console.log('Error al enviar el correo:', error);
                     } else {
                       console.log('Correo enviado:', info.response);
                     }
                   });

                    break;
                  case data.temperatura > 100:
                    alerta = "⚠️ ALERTA: La temperatura está demasiado alta. Se encenderá el aire acondicionado.";
                    io.sockets.emit('enciende-aire');
                    break;
                  case data.temperatura < -100 && data.luminosidad > 100:
                    alerta = "⚠️ ALERTA: La temperatura está demasiado baja y la luminosidad demasiado alta. Se cerrará la persiana y se apagará el aire acondicionado.";
                    io.sockets.emit('cierra-persiana');
                    io.sockets.emit('apaga-aire');
                    break;
                  case data.temperatura < -100 && data.luminosidad < 0:
                    alerta = "⚠️ ALERTA: La temperatura está demasiado baja y la luminosidad demasiado baja. Se abrirá la persiana y se apagará el aire acondicionado.";
                    io.sockets.emit('abre-persiana');
                    io.sockets.emit('apaga-aire');
                    break;
                  case data.temperatura < -100:
                    alerta = "⚠️ ALERTA: La temperatura está demasiado baja. Se apagará el aire.";
                    io.sockets.emit('apaga-aire');
                    break;
                  case data.luminosidad > 100:
                    alerta = "⚠️ ALERTA: La luminosidad está demasiado alta. Se cerrará la persiana.";
                    io.sockets.emit('cierra-persiana');
                    break;
                  case data.luminosidad < 0:
                    alerta = "⚠️ ALERTA: La luminosidad está demasiado baja. Se abrirá la persiana.";
                    io.sockets.emit('abre-persiana');
                    break;
                }                

               // Se envía a los clientes el mensaje de alerta
               io.sockets.emit("info-alertas", alerta, data);

               // Se envía a los clientes las nuevas medidas que nos dan los sensores
               io.sockets.emit('medidas-casa', data);
            });
            
            client.on('estado-controladores', function (data) {

               var persianaAbierta = data.estadoPersiana;
               var aireEncendido = data.estadoAire

               if(persianaAbierta == 1 && aireEncendido == 1){

                  console.log("Entro dentro de la alerta compleja");
                  var alerta = "⚠️⚠️⚠️ ALERTA COMPLEJA: El aire y la persiana estan activos a la vez";
                  io.sockets.emit('alerta-compleja', alerta);
               }
               else if (persianaAbierta == 0 && aireEncendido == 0){
                  console.log("Entro dentro de la alerta compleja");
                  var alerta = "⚠️⚠️⚠️ ALERTA COMPLEJA: El aire y la persiana estan desactivados a la vez";
                  io.sockets.emit('alerta-compleja', alerta);
               }
               else {
                  console.log("Entro dentro de la alerta compleja");
                  var alerta = "";
                  io.sockets.emit('alerta-compleja', alerta);
               }
               
            });

            // El cliente solicita apagar el aire, por lo que se llama al servidor para que lo realice.
            client.on('apaga-aire-cliente', function () {
               io.sockets.emit('apaga-aire');
            });

            // El cliente solicita encender el aire, por lo que se llama al servidor para que lo realice.
            client.on('enciende-aire-cliente', function () {
               console.log("Enciendo el aire caliente");
               io.sockets.emit('enciende-aire');
            });

            // El cliente solicita cerrar la persiana, por lo que se llama al servidor para que lo realice.
            client.on('cierra-persiana-cliente', function () {
               io.sockets.emit('cierra-persiana');
            });

            // El cliente solicita abrir la persiana, por lo que se llama al servidor para que lo realice.
            client.on('abre-persiana-cliente', function () {
               io.sockets.emit('abre-persiana');
            });

            // Se obtienen de la base de datos todas las medidas registradas y se emiten.
            client.on('obtener-medidas', function (data) {
               collection.find(data).toArray().then((results) => {
                  client.emit('obtener-medidas', results);
               }).catch((err) => {
                  console.error(err);
               });
            });

            // Borramos los datos de la coleccion.
            client.on('borrar-historial', function () {
               collection.drop();
               client.emit('obtener-medidas', null);
            });

            // Para cuando se desconecta un cliente
            client.on('disconnect', function () {
               console.log('El cliente ' + client.request.connection.remoteAddress + ' se ha desconectado');
            });
         });
   }).catch((err) => {
      console.error(err);
   });

}).catch((err) => {
   console.error(err);
});

console.log("Servicio MongoDB iniciado");