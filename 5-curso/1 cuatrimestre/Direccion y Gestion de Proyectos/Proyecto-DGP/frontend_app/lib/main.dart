import 'package:flutter/material.dart';
import 'package:frontend_app/loadingPage.dart';
import 'AdminPage/inicio.dart';
import 'login.dart';
import 'AdminPage/Alumnos/agregarEstudiante.dart';


void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      initialRoute: '/',
      routes: {
        '/': (context) => LoadingPage(),
        '/home': (context) => MyHomePage(title: 'Pagina de Inicio'),
        '/addStudent': (context) => AddStudentPage(), 
      },
    );
  }
}
