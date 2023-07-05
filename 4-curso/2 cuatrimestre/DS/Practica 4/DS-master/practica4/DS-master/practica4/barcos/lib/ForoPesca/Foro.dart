import 'Filtro.dart';
import 'FiltroHora.dart';
import 'package:flutter/material.dart';
import 'package:tuple/tuple.dart';
import 'UsuarioCliente.dart';
import 'FiltroContenido.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Patron Filtros',
      theme: ThemeData(primarySwatch: Colors.indigo),
      home: const MyHomePage(title: 'Filtros Intercepcion'),
      routes: {
        '/paginaActual': (context) => MyHomePage(title: 'Filtros Intercepcion'),
      },
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  List<Container> _listamensajes = [];
  UsuarioCliente _uc = UsuarioCliente();
  int contador = 0;

  final _palabrasProhibidas = TextEditingController();
  final _nuevoComentario = TextEditingController();
  final _palabraBuscar = TextEditingController();

  @override
  void initState() {
    super.initState();
  }

  void _addComentario() {
    setState(() {
      _uc.getGestor().aniadeComentario(_nuevoComentario.text);
      _nuevoComentario.text = "";
      _listamensajes.add(_buildComentario(
          _uc
              .getGestor()
              .getComentarios()[_uc.getGestor().getComentarios().length - 1]
              .item1,
          0));
      _listamensajes.add(_buildComentario(
          _uc
              .getGestor()
              .getComentarios()[_uc.getGestor().getComentarios().length - 1]
              .item2,
          1));
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Row(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              "Filtros de Intercepcion",
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
              List<String> lista_filtros = [];

              for (Filtro filtro in _uc.getGestor().getCadena().getFiltros()) {
                lista_filtros.add(filtro.toString());
              }

              _mostrarFiltros(lista_filtros);
            },
            icon: Icon(Icons.info_rounded),
            label: Text("Filtros"),
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
                        controller: _palabrasProhibidas,
                        decoration: InputDecoration(
                          labelText: 'Palabras Prohibidas',
                          border: OutlineInputBorder(),
                        ),
                      ),
                    ),
                  ),
                  Container(
                    margin: EdgeInsets.all(10),
                    child: ElevatedButton(
                      onPressed: () {
                        _uc.getGestor().aniadirFiltro(FiltroContenido.n2(
                            _palabrasProhibidas.text.split(" ")));
                      },
                      child: Text('Prohibir'),
                    ),
                  ),
                  Container(
                    margin: EdgeInsets.all(10),
                    child: ElevatedButton(
                      onPressed: () {
                        _uc.getGestor().resetGestor();
                      },
                      child: Text('Reset'),
                    ),
                  ),
                ],
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
                children: [
                  Expanded(
                    child: Container(
                      margin: EdgeInsets.all(10),
                      child: TextField(
                        controller: _palabraBuscar,
                        decoration: InputDecoration(
                          labelText: 'Buscar Palabra',
                          border: OutlineInputBorder(),
                        ),
                      ),
                    ),
                  ),
                  Container(
                    margin: EdgeInsets.all(10),
                    child: ElevatedButton(
                      onPressed: () {
                        contador = 0;
                        int count = 0;

                        if (!_palabraBuscar.text.contains('*')) {
                          for (Tuple2 comentario
                              in _uc.getGestor().getComentarios()) {
                            RegExp exp = RegExp(_palabraBuscar.text,
                                caseSensitive: false);
                            contador += exp.allMatches(comentario.item2).length;
                          }
                        }

                        _avisoPalabras(_palabraBuscar.text, contador);
                      },
                      child: Text('Buscar'),
                    ),
                  ),
                ],
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
                      onPressed: _addComentario,
                      child: Text('Enviar'),
                    ),
                  ),
                ],
              ),
            ),
          ],
        )),
      ),
    );
  }

  void _avisoPalabras(String palabra, int contador) {
    showDialog(
        context: context,
        builder: (buildcontext) {
          return AlertDialog(
            title: Text("Para la palabra: $palabra"),
            content: Text("$contador coincidencias"),
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

  void _mostrarFiltros(List<String> lista_filtros) {
    showDialog(
        context: context,
        builder: (buildcontext) {
          return AlertDialog(
            title: Text("Filtros Activos"),
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
  print("Soy del tipo: $tipo");

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
