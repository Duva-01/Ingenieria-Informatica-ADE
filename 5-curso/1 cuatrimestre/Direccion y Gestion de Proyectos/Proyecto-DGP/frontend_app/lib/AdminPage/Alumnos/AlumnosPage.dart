import 'package:flutter/material.dart';
import 'package:flutter_zoom_drawer/flutter_zoom_drawer.dart';
import '../../network.dart';
import '../Tareas/agregarTarea.dart';
import 'agregarEstudiante.dart';

class AlumnosPage extends StatefulWidget {
  @override
  _AlumnosPageState createState() => _AlumnosPageState();
}

class _AlumnosPageState extends State<AlumnosPage> {
  late Future<List<dynamic>> futureAlumnos;

  @override
  void initState() {
    super.initState();
    futureAlumnos = fetchAlumnos();
  }

  DataRow _createRow(dynamic alumno) {
    return DataRow(
      cells: [
        DataCell(Text(alumno['DNI'].toString())),
        DataCell(Text(alumno['nombre'].toString())),
        DataCell(Text(alumno['domicilio'].toString())),
        DataCell(Text(alumno['fecha_nacimiento'].toString())),
      ],
    );
  }

  @override
  Widget build(BuildContext context) {
    final controller = ZoomDrawer.of(context);
    return Scaffold(
      appBar: AppBar(
        title: Text('Pagina Alumnos'),
        leading: IconButton(
          icon: Icon(Icons.menu),
          onPressed: () {
            controller?.toggle();
          },
        ),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: <Widget>[
            Text(
              'Alumnos',
              style: TextStyle(
                fontSize: 24,
                fontWeight: FontWeight.bold,
              ),
            ),
            SizedBox(height: 20),
            Expanded(
              child: FutureBuilder<List<dynamic>>(
                future: futureAlumnos,
                builder: (context, snapshot) {
                  if (snapshot.connectionState == ConnectionState.done) {
                    if (snapshot.hasData) {
                      return SingleChildScrollView(
                        scrollDirection: Axis.horizontal,
                        child: DataTable(
                          columns: [
                            DataColumn(label: Text('DNI')),
                            DataColumn(label: Text('Nombre')),
                            DataColumn(label: Text('Domicilio')),
                            DataColumn(label: Text('Fecha Nacimiento')),
                            
                          ],
                          
                          rows: snapshot.data!.map((alumno) => _createRow(alumno)).toList(),
                        ),
                      );
                    } else if (snapshot.hasError) {
                      return Center(child: Text("${snapshot.error}"));
                    }
                  }
                  return Center(child: CircularProgressIndicator());
                },
              ),
            ),
            SizedBox(height: 20),
            ElevatedButton.icon(
              onPressed: () async {
                await Navigator.of(context).push(
                  MaterialPageRoute(
                    builder: (context) => AddStudentPage(),
                  ),
                );
                setState(() {
                  futureAlumnos = fetchAlumnos();
                });
              },
              icon: Icon(Icons.add),
              label: Text('Agregar Alumno'),
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.of(context).push(
                  MaterialPageRoute(
                    builder: (context) => AddTaskPage(),
                  ),
                );
              },
              child: Text('Añadir Tarea'),
            ),
          ],
        ),
      ),
    );
  }
}
