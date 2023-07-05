const http = require("http");
const url = require("url");
const fs = require("fs");
const path = require("path");
const socketio = require("socket.io");

const MongoClient = require("mongodb").MongoClient;
const mimeTypes = {
  html: "text/html",
  jpeg: "image/jpeg",
  jpg: "image/jpeg",
  png: "image/png",
  js: "text/javascript",
  css: "text/css",
  swf: "application/x-shockwave-flash",
  ico: "image/x-icon",
};

const httpServer = http.createServer((request, response) => {
  
  let uri = url.parse(request.url).pathname;

  if (uri === "/") {
    uri = "./mongo-cliente.html";
  } else if (uri === "/socket.io/socket.io.js") {
    uri = "./node_modules/socket.io/client-dist/socket.io.min.js";
  }

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

MongoClient.connect("mongodb://127.0.0.1:27017/", function(err, db) {
}).then((db) => { 
  
  httpServer.listen(8080);
  var io = socketio(httpServer);

  var dbo = db.db("DSD-P4");

  dbo.collection("test").drop(function (err, delOK) {
    if (err) throw err;
    if (delOK) console.log("Colección existente eliminada");
 });

  dbo.createCollection("test").then( (collection) => {

    io.sockets.on('connection', function(client) {
      
      client.emit('my-address', {
        host: client.request.connection.remoteAddress,
        port: client.request.connection.remotePort,
      });

      client.on('poner', function(data) {
        collection.insertOne(data, {safe:true}).then((result) => {

          console.log(data);
        }).catch((err) => {
          console.error(err);
        });
      });
        
      client.on('obtener', function(data) {
        collection.find(data).toArray().then( (results) => {

          client.emit('obtener', results);
        }).catch((err) => {
          console.error(err);
        });
      });

    });
  }).catch((err) => {
    console.error(err);
  });
});

console.log("Servicio MongoDB iniciado");