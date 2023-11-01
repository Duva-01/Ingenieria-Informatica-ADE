import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';


class AddStudentPage extends StatefulWidget {
  @override
  _AddStudentPageState createState() => _AddStudentPageState();
}

class _AddStudentPageState extends State<AddStudentPage> {
  final _formKey = GlobalKey<FormState>();
  TextEditingController _dniController = TextEditingController();
  TextEditingController _nameController = TextEditingController();
  TextEditingController _addressController = TextEditingController();
  TextEditingController _dobController = TextEditingController(); // Fecha de nacimiento

  Future<void> _addStudent() async {
    final studentData = {
      "DNI": _dniController.text,
      "nombre": _nameController.text,
      "domicilio": _addressController.text,
      "fecha_nacimiento": _dobController.text,
    };

    final response = await http.post(
      Uri.parse('http://10.0.2.2:3000/alumnos'),
      headers: {"Content-Type": "application/json"},
      body: json.encode(studentData),
    );

    if (response.statusCode == 200) {
      final responseBody = json.decode(response.body);
      if (responseBody['status'] == 'success') {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Alumno añadido exitosamente')),
        );
        Navigator.pop(context);  
      } else {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Error al añadir alumno')),
        );
      }
    } else {
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Error al conectar con el servidor')),
      );
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text("Añadir Alumno")),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: ListView(
            children: [
              TextFormField(
                controller: _dniController,
                decoration: InputDecoration(labelText: 'DNI'),
                validator: (value) => value!.isEmpty ? 'El DNI es obligatorio' : null,
              ),
              TextFormField(
                controller: _nameController,
                decoration: InputDecoration(labelText: 'Nombre'),
                validator: (value) => value!.isEmpty ? 'El nombre es obligatorio' : null,
              ),
              TextFormField(
                controller: _addressController,
                decoration: InputDecoration(labelText: 'Domicilio'),
                validator: (value) => value!.isEmpty ? 'El domicilio es obligatorio' : null,
              ),
              TextFormField(
                controller: _dobController,
                decoration: InputDecoration(labelText: 'Fecha de Nacimiento'),
                validator: (value) => value!.isEmpty ? 'La fecha de nacimiento es obligatoria' : null,
              ),
              ElevatedButton(
                onPressed: () {
                  if (_formKey.currentState!.validate()) {
                    _addStudent();
                  }
                },
                child: Text('Registrar Alumno'),
              )
            ],
          ),
        ),
      ),
    );
  }
}
