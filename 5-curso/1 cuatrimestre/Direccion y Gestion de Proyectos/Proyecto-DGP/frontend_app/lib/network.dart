import 'dart:convert';
import 'package:http/http.dart' as http;

import 'Modelos/ElementoTarea.dart';
import 'Modelos/Tarea.dart';

// Función para obtener administradores
Future<List<dynamic>> fetchAdministradores() async {
  final response = await http.get(Uri.parse('http://10.0.2.2:3000/administradores'));
  if (response.statusCode == 200) {
    return json.decode(response.body);
  } else {
    throw Exception('Failed to load admin data');
  }
}

// Función para obtener alumnos
Future<List<dynamic>> fetchAlumnos() async {
  final response = await http.get(Uri.parse('http://10.0.2.2:3000/alumnos')); // Asumiendo que tienes un endpoint para alumnos
  if (response.statusCode == 200) {
    return json.decode(response.body);
  } else {
    throw Exception('Failed to load student data');
  }
}


//-------------------------------------------------------
// Función para obtener tareas
Future<List<Tarea>> fetchTareas() async {
  final response = await http.get(Uri.parse('http://10.0.2.2:3000/tareas'));
  if (response.statusCode == 200) {
    List jsonResponse = json.decode(response.body);
    return jsonResponse.map((task) => Tarea(
      id: task['id'],
      nombre: task['nombre'],
      tipo: task['tipo'],
    )).toList();
  } else {
    throw Exception('Failed to load tasks');
  }
}


Future<List<ElementoTarea>> fetchElementosTarea(int tareaId) async {
  final response = await http.get(Uri.parse('http://10.0.2.2:3000/tareas/$tareaId/elementos'));
  if (response.statusCode == 200) {
    Map<String, dynamic> jsonResponse = json.decode(response.body);
    List<dynamic> data = jsonResponse['elementos']; // Aquí accedemos al campo 'elementos'
    return data.map((elemento) => ElementoTarea(
      id: elemento['id'],
      pictograma: elemento['pictograma'],
      descripcion: elemento['descripcion'],
      sonido: elemento['sonido'],
      video: elemento['video'],
    )).toList();
  } else {
    throw Exception('Failed to load task elements for task $tareaId');
  }
}


// Función para añadir tarea
Future<Tarea> addTarea(String nombre, String tipo) async {
  final response = await http.post(
    Uri.parse('http://10.0.2.2:3000/tareas'),
    headers: <String, String>{
      'Content-Type': 'application/json; charset=UTF-8',
    },
    body: jsonEncode(<String, String>{
      'nombre': nombre,
      'tipo': tipo,
    }),
  );

  if (response.statusCode == 200) {
    var jsonResponse = json.decode(response.body);
    return Tarea(id: jsonResponse['id'], nombre: nombre, tipo: tipo);
  } else {
    throw Exception('Failed to add task');
  }
}

// Función para añadir un elemento de tarea
Future<ElementoTarea> addElementoTarea(String pictograma, String descripcion, String sonido, String? video, int tareaId) async {
  final response = await http.post(
    Uri.parse('http://10.0.2.2:3000/tareas/$tareaId/elementos'),
    headers: <String, String>{
      'Content-Type': 'application/json; charset=UTF-8',
    },
    body: jsonEncode(<String, dynamic>{
      'pictograma': pictograma,
      'descripcion': descripcion,
      'sonido': sonido,
      'video': video,
    }),
  );

  if (response.statusCode == 200) {
    var jsonResponse = json.decode(response.body);
    return ElementoTarea(
      id: jsonResponse['id'],
      pictograma: pictograma,
      descripcion: descripcion,
      sonido: sonido,
      video: video,
    );
  } else {
    throw Exception('Failed to add task element');
  }
}

