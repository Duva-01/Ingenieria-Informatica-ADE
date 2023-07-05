import 'package:barcos/barco.dart';
import './ForoPesca/Filtro.dart';
import './ForoPesca/FiltroHora.dart';
import './ForoPesca/UsuarioCliente.dart';
import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import './ForoPesca/FiltroContenido.dart';
import 'package:flutter/material.dart';
import 'ejercicio1.dart' as globals;
import 'usuario.dart';
import 'factoria.dart';
import 'mar.dart';

//---------------------------------------------------------------------------------------------------------------------------------------
class creacionBarco extends StatefulWidget {
  final Usuario usuario;

  creacionBarco({required this.usuario});

  @override
  State<creacionBarco> createState() => _creacionBarcoState();
}

class creacionPez extends StatefulWidget {
  final Usuario usuario;
  late Mar mar;

  creacionPez({required this.usuario}) {
    mar = FactoriaGrande().crearMar("Mar");
  }

  @override
  State<creacionPez> createState() => _creacionPezState();

  // This widget is the root of your application.
}

//---------------------------------------------------------------------------------------------------------------------------------------

class _creacionBarcoState extends State<creacionBarco> {
  List<Barco> _boatList = [];

  void _aniadirGrande() {
    setState(() {
      widget.usuario.barcos.add(BarcoGrande());
    });
  }

  void _aniadirPequenio() {
    setState(() {
      widget.usuario.barcos.add(BarcoPequenio());
    });
  }

  @override
  Widget build(BuildContext context) {
    int contadorGrande = 0;
    int contadorPequenio = 0;
    return Scaffold(
      appBar: AppBar(
        title: Text('Crear Barcos'),
      ),
      body: Column(
        children: [
          Padding(
            padding: EdgeInsets.all(10),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                ElevatedButton(
                  onPressed: () {
                    _aniadirGrande();
                  },
                  child: Text('Crear Barco Grande'),
                ),
                SizedBox(width: 10),
                ElevatedButton(
                  onPressed: () {
                    _aniadirPequenio();
                  },
                  child: Text('Crear Barco Pequeño'),
                ),
              ],
            ),
          ),
          Expanded(
            child: ListView.builder(
              itemCount: widget.usuario.barcos.length,
              itemBuilder: (BuildContext context, int index) {
                String tipo;
                if (widget.usuario.barcos[index] is BarcoPequenio) {
                  contadorPequenio++;
                  return ListTile(
                      title:
                          Text("Barco Pequeño " + contadorPequenio.toString()));
                } else {
                  contadorGrande++;
                  return ListTile(
                      title: Text("Barco Grande " + contadorGrande.toString()));
                }
              },
            ),
          ),
        ],
      ),
    );
  }
}

class _creacionPezState extends State<creacionPez> {
  int dropValue = 0;
  int numeroPeces = globals.mar.getPeces().length;
  _creacionPezState();
  List<Container> _listamensajes = [];
  UsuarioCliente _uc = UsuarioCliente();
  int contador = 0;

  final _nuevoComentario = TextEditingController();
  
  

  void _addComentario() {
    setState(() {
      _uc.getGestor().aniadeComentario(_nuevoComentario.text);
      _nuevoComentario.text = "";
      /*_listamensajes.add(_buildComentario(  //este es el comentario sin filtrar
          _uc
              .getGestor()
              .getComentarios()[_uc.getGestor().getComentarios().length - 1]
              .item1,
          0));*/
      _listamensajes.add(_buildComentario(
          _uc
              .getGestor()
              .getComentarios()[_uc.getGestor().getComentarios().length - 1]
              .item2,
          1));
    });
  }

  int selectedOption = 0;

  @override
  Widget build(BuildContext context) {
    
    int contadorGrande = 0;
    int contadorPequenio = 0;
    String tipoBarcoActual = "Seleccionar barco";

    return Scaffold(
      appBar: AppBar(
        title: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              "Foro de Comentarios",
              style: TextStyle(
                  color: Color.fromARGB(255, 161, 208, 247),
                  fontWeight: FontWeight.w600),
            ),
            //
          ],
        ),
        actions: [
          ElevatedButton.icon(
            onPressed: () {
              /*List<String> lista_filtros = [];

              for (Barco barco in widget.usuario.barcos) {
                lista_filtros.add(barco.getPuntuacion().toString());
              }

              _mostrarFiltros(lista_filtros);*/

              //////////

              /*
              int suma = 0;

              for(int i=0; i<widget.usuario.barcos.length; i++){
                suma += widget.usuario.barcos[i].getPuntuacion();
              }

              showDialog(
                context: context,
                builder: (BuildContext context) {
                  return AlertDialog(
                    title: Text("Suma de puntuaciones"),
                    content: Text("$suma"),
                    actions: [
                      ElevatedButton(
                        onPressed: () {
                          Navigator.of(context).pop();
                        },
                        child: Text("Cerrar"),
                      ),
                    ],
                  );
                },
              ); NOOOO BORRARRRR ME CAGO EN TO */
            },
            icon: Icon(Icons.info_rounded),
            label: Text("Puntuacion"),
          )
        ],
      ),
      body: Container(
        color: Color.fromARGB(255, 169, 216, 254),
        child: Center(
            child: Column(
          children: [
            Expanded(
              flex: 7,
              child: Container(
                padding: EdgeInsets.all(20),
                color: Color.fromARGB(255, 169, 216, 254),
                child: Center(
                    child: Container(
                  height: MediaQuery.of(context).size.height - 300,
                  width: MediaQuery.of(context).size.width - 50,
                  decoration: BoxDecoration(
                    color: Color.fromARGB(255, 250, 250, 250),
                    boxShadow: [
                      BoxShadow(
                        color: Colors.black,
                        spreadRadius: 0.2,
                        blurRadius: 5.0,
                      ),
                    ],
                    borderRadius: BorderRadius.only(
                        topLeft: Radius.circular(10),
                        topRight: Radius.circular(10),
                        bottomLeft: Radius.circular(10),
                        bottomRight: Radius.circular(10)),
                    border: Border.all(color: Colors.black54),
                  ),
                  child: ListView.builder(
                    itemCount: _listamensajes.length,
                    itemBuilder: (BuildContext context, int index) {
                      return _listamensajes[index];
                    },
                  ),
                )),
              ),
            ),
            Container(
              decoration: BoxDecoration(
                color: Color.fromARGB(255, 221, 240, 255),
                border: Border(
                  top: BorderSide(
                    color: Colors.black,
                    width: 4.0,
                  ),
                ),
              ),
              child: Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Expanded(
                    child: Container(
                      margin: EdgeInsets.all(10),
                      child: TextField(
                        controller: _nuevoComentario,
                        decoration: InputDecoration(
                          labelText: 'Añadir Comentario',
                          border: OutlineInputBorder(),
                        ),
                      ),
                    ),
                  ),
                  Container(
                    margin: EdgeInsets.all(10),
                    child: ElevatedButton(
                        onPressed: () {
                          if (_nuevoComentario.text.isNotEmpty) {
                            _addComentario();
                          }
                        },
                        child: Text('Enviar')),
                    //onPressed: _addComentario, child: Text('Enviar')),
                  ),
                  Container(
                    margin: EdgeInsets.all(10),
                    child: ElevatedButton(
                      onPressed: () {
                        //_uc.getGestor().resetGestor(); /////////////////////////////////////////
                        Barco barcoActual =
                            widget.usuario.barcos[selectedOption];

                        if (widget.mar.pescar(barcoActual)) {
                          double _puntosSumados = barcoActual.getPuntuacion() /
                              barcoActual.getPeces();
                          _nuevoComentario.text = widget.usuario.nick +
                              " ha pescado un pez! Has conseguido +" +
                              _puntosSumados.toStringAsFixed(0) +
                              " puntos";
                          _addComentario();
                        }
                      },
                      child: Text('Pescar'),
                    ),
                  ),
                ],
              ),
            ),
            Container(
              margin: EdgeInsets.fromLTRB(0, 10, 0, 10),
              width: MediaQuery.of(context).size.width,
              child: DropdownButton<int>(
                value: selectedOption,
                icon: const Icon(Icons.arrow_downward),
                iconSize: 24,
                elevation: 16,
                style: const TextStyle(
                  color: Colors.blueGrey,
                  fontSize: 24,
                ),
                underline: Container(
                  height: 2,
                  color: Colors.blueGrey,
                ),
                onChanged: (int? newValue) {
                  setState(() {
                    dropValue = newValue!;
                    selectedOption = newValue!;
                  });
                },
                /*items:List.generate(widget.usuario.barcos.length, (index) {
                    return DropdownMenuItem<int>(
                      value: index,
                      child: Center(
                        child: Text(
                          widget.usuario.barcos[index].getTipo(), // Cambia esto por la propiedad adecuada del barco
                          textAlign: TextAlign.center,
                        ),
                      ),
                    );
                  }),*/
                items: <int>[0, 1, 2].map<DropdownMenuItem<int>>((int value) {
                  return DropdownMenuItem<int>(
                    value: value,
                    child: Center(
                        child: Text(
                      "$value",
                      textAlign: TextAlign.center,
                    )),
                  );
                }).toList(),
              ),
            ),
          ],
        )),
      ),
    );
  }

  void _mostrarFiltros(List<String> lista_filtros) {
    showDialog(
        context: context,
        builder: (buildcontext) {
          return AlertDialog(
            title:
                Text("Puntuacion total de " + widget.usuario.nick.toString()),
            content: Container(
              width: double.maxFinite,
              child: ListView.builder(
                shrinkWrap: true,
                itemCount: lista_filtros.length,
                itemBuilder: (BuildContext context, int index) {
                  return ListTile(
                    title: Text(lista_filtros[index]),
                  );
                },
              ),
            ),
            actions: <Widget>[
              ElevatedButton(
                child: Text(
                  "CERRAR",
                  style: TextStyle(color: Colors.white),
                ),
                onPressed: () {
                  Navigator.of(context).pop();
                },
              )
            ],
          );
        });
  }
}

Container _buildComentario(String texto, int tipo) {
  Color backgroundColor;
  if (tipo == 1) {
    backgroundColor = Color.fromARGB(255, 121, 221, 125);
  } else {
    backgroundColor = Colors.grey;
  }

  return Container(
    margin: EdgeInsets.all(20.0),
    child: Flexible(
      child: Container(
        margin: EdgeInsets.all(10.0),
        decoration: BoxDecoration(
          color: backgroundColor,
          boxShadow: [
            BoxShadow(
              color: Colors.black,
              spreadRadius: 0.2,
              blurRadius: 5.0,
            ),
          ],
          borderRadius: BorderRadius.only(
              topLeft: Radius.circular(10),
              topRight: Radius.circular(10),
              bottomLeft: Radius.circular(10),
              bottomRight: Radius.circular(10)),
          border: Border.all(color: Colors.black54),
        ),
        child: Container(
          margin: EdgeInsets.all(10.0),
          child: Center(
            child: Text(texto),
          ),
        ),
      ),
    ),
  );
}

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Inicio de Sesión',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: LoginPage(),
      routes: {
        RegistroPage.routeName: (context) => RegistroPage(),
      },
    );
  }
}

class LoginPage extends StatefulWidget {
  @override
  _LoginPageState createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  final TextEditingController _nombreController = TextEditingController();
  final TextEditingController _contrasenaController = TextEditingController();
  String _mensajeError = '';
  final Autenticacion autenticacion = new Autenticacion();

  void _iniciarSesion() {
    // Comprobar las credenciales
    if (autenticacion.comprobarCredencialesInicio(
        _nombreController.text, _contrasenaController.text)) {
      // Credenciales correctas, redirigir a la siguiente pantalla
      Usuario actualUser = autenticacion.obtenerUsuario(
          _nombreController.text, _contrasenaController.text);
      Navigator.push(
        context,
        MaterialPageRoute(builder: (context) => inicioApp(usuario: actualUser)),
      );
    } else {
      // Credenciales incorrectas, mostrar mensaje de error
      setState(() {
        _mensajeError = 'Credenciales incorrectas. Inténtalo de nuevo.';
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Inicio de Sesión'),
      ),
      body: Padding(
        padding: EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _nombreController,
              decoration: InputDecoration(
                labelText: 'Nombre de usuario',
              ),
            ),
            TextField(
              controller: _contrasenaController,
              decoration: InputDecoration(
                labelText: 'Contraseña',
              ),
              obscureText: true,
            ),
            ElevatedButton(
              onPressed: _iniciarSesion,
              child: Text('Iniciar Sesión'),
            ),
            Text(
              _mensajeError,
              style: TextStyle(
                color: Colors.red,
              ),
            ),
            SizedBox(height: 20),
            GestureDetector(
              onTap: () {
                Navigator.pushNamed(context, RegistroPage.routeName);
              },
              child: Text(
                'Si no tiene una cuenta, regístrese.',
                style: TextStyle(
                  decoration: TextDecoration.underline,
                  color: Colors.blue,
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class RegistroPage extends StatefulWidget {
  static const routeName = '/registro';

  @override
  _RegistroPageState createState() => _RegistroPageState();
}

class _RegistroPageState extends State<RegistroPage> {
  final TextEditingController _nombreController = TextEditingController();
  final TextEditingController _correoController = TextEditingController();
  final TextEditingController _contrasenaController = TextEditingController();
  String _mensajeError = '';

  void _registrar() {
    String nombre = _nombreController.text;
    String correo = _correoController.text;
    String contrasena = _contrasenaController.text;
    final Autenticacion autenticacion = new Autenticacion();

    if (nombre.isNotEmpty && correo.isNotEmpty && contrasena.isNotEmpty) {
      // Verificar si ya existe un usuario con el mismo nombre de usuario o correo electrónico
      if (autenticacion.existeUsuario(nombre) ||
          autenticacion.existeCorreo(correo)) {
        setState(() {
          _mensajeError =
              'El nombre de usuario o correo electrónico ya están en uso. Inténtalo de nuevo.';
        });
      } else {
        // Registrar el nuevo usuario
        Usuario nuevoUser = Usuario(nombre, correo, contrasena);
        autenticacion.registrarUsuario(nuevoUser);
        // Mostrar un diálogo de registro exitoso
        showDialog(
          context: context,
          builder: (context) => AlertDialog(
            title: Text('Registro exitoso'),
            content: Text('Su cuenta ha sido registrada con éxito.'),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.pop(context);
                  Navigator.pop(context);
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                        builder: (context) => inicioApp(usuario: nuevoUser)),
                  );
                },
                child: Text('Aceptar'),
              ),
            ],
          ),
        );
      }
    } else {
      setState(() {
        _mensajeError = 'Por favor, complete todos los campos.';
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Registro de Usuario'),
      ),
      body: Padding(
        padding: EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _nombreController,
              decoration: InputDecoration(
                labelText: 'Nombre de usuario',
              ),
            ),
            TextField(
              controller: _correoController,
              decoration: InputDecoration(
                labelText: 'Correo electrónico',
              ),
            ),
            TextField(
              controller: _contrasenaController,
              decoration: InputDecoration(
                labelText: 'Contraseña',
              ),
              obscureText: true,
            ),
            ElevatedButton(
              onPressed: _registrar,
              child: Text('Registrar'),
            ),
            Text(
              _mensajeError,
              style: TextStyle(
                color: Colors.red,
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Inicio'),
      ),
      body: Center(
        child: Text('¡Inicio de sesión exitoso!'),
      ),
    );
  }
}

class inicioApp extends StatefulWidget {
  final Usuario usuario;

  inicioApp({required this.usuario});

  @override
  State<inicioApp> createState() => _inicioAppState();
}

class _inicioAppState extends State<inicioApp> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Center(child: Text("Juego de Barcos")),
      ),
      body:Container(
        decoration: BoxDecoration(
          // color: Colors.indigo[900],
          image: DecorationImage(
              image: AssetImage("../asset/fondo.jpeg"), fit: BoxFit.cover),
        ),
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.start,
            children: <Widget>[],
          ),
        ),
      ),
      floatingActionButton: Wrap(
        spacing: 340.0, // Espacio entre los botones
        runSpacing: 4.0, // Espacio entre las filas de botones
        children: [
          ElevatedButton(
            onPressed: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                    builder: (context) =>
                        creacionBarco(usuario: widget.usuario)),
              );
            },
            child: Text('Añadir Barco'),
            style: ButtonStyle(
              backgroundColor:
                  MaterialStateProperty.all<Color>(Colors.blueGrey),
            ),
          ),
          SizedBox(width: 16), // Espacio entre los botones
          ElevatedButton(
            onPressed: () {
              Navigator.push(
                context,
                MaterialPageRoute(
                    builder: (context) => creacionPez(usuario: widget.usuario)),
              );
            },
            child: Text('Foro'),
            style: ButtonStyle(
              backgroundColor:
                  MaterialStateProperty.all<Color>(Colors.blueGrey),
            ),
          ),
        ],
      ),
    );
  }
}