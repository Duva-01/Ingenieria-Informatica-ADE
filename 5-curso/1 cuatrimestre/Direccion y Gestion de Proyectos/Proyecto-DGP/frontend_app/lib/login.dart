import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart'; // Asegúrate de haber añadido el paquete google_fonts a tu pubspec.yaml
import 'network.dart';

class LoginPage extends StatefulWidget {
  @override
  _LoginPageState createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  final _adminUsernameController = TextEditingController();
  final _adminPasswordController = TextEditingController();

  final _studentUsernameController = TextEditingController();
  final _studentPasswordController = TextEditingController();

  bool _isAdminExpanded = false;
  bool _isStudentExpanded = false;

  Future<void> _loginAdministradores() async {
    final administradores = await fetchAdministradores();
    for (var admin in administradores) {
      if (admin['username'] == _adminUsernameController.text &&
          admin['password'] == _adminPasswordController.text) {
        Navigator.of(context).pushReplacementNamed('/home');
        return;
      }
    }
    ScaffoldMessenger.of(context).showSnackBar(SnackBar(
      content: Text('Credenciales de administrador incorrectas'),
    ));
  }

  Future<void> _loginAlumnos() async {
    // Aquí puedes poner la lógica para validar el inicio de sesión de los alumnos.
    // Por ahora, solo mostrará un SnackBar indicando que esta función aún no se ha implementado.
    ScaffoldMessenger.of(context).showSnackBar(SnackBar(
      content:
          Text('Función de inicio de sesión de alumnos aún no implementada'),
    ));
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            children: [
              // Titulo en la parte superior
              Align(
                alignment: Alignment.topCenter,
                child: Text(
                  'Inicia Sesión',
                  style: GoogleFonts.patrickHand(
                    // Fuente infantil
                    fontSize: 36,
                    color: Colors.blue,
                  ),
                ),
              ),
              SizedBox(height: 32.0),
              ExpansionPanelList(
                expansionCallback: (int index, bool isExpanded) {
                  setState(() {
                    if (index == 0) {
                      _isAdminExpanded = !isExpanded;
                    } else {
                      _isStudentExpanded = !isExpanded;
                    }
                  });
                },
                children: [
                  ExpansionPanel(
                    headerBuilder: (context, isExpanded) => Text(
                      'Administrador',
                      textAlign: TextAlign.center,
                      style: GoogleFonts.patrickHand(
                        // Fuente infantil
                        fontSize: 30,
                        color: Colors.black,
                      ),
                    ),
                    body: Column(
                      children: [
                        TextField(
                          controller: _adminUsernameController,
                          decoration: InputDecoration(
                            labelText: 'Nombre de usuario',
                          ),
                        ),
                        SizedBox(height: 16.0),
                        TextField(
                          controller: _adminPasswordController,
                          decoration: InputDecoration(
                            labelText: 'Contraseña',
                          ),
                          obscureText: true,
                        ),
                        SizedBox(height: 16.0),
                        ElevatedButton(
                          onPressed: _loginAdministradores,
                          child: Text('Iniciar sesión'),
                        ),
                      ],
                    ),
                    isExpanded: _isAdminExpanded,
                  ),
                  ExpansionPanel(
                    headerBuilder: (context, isExpanded) => Container(
                      margin: EdgeInsets.only(
                          top:
                              20.0), // <-- Esto añade un margen en la parte superior del desplegable
                      child: Text('Alumnos',
                          textAlign: TextAlign.center,
                          style: GoogleFonts.patrickHand(
                            fontSize: 30,
                            color: Colors.black,
                          )),
                    ),
                    body: Column(
                      children: [
                        TextField(
                          controller: _studentUsernameController,
                          decoration: InputDecoration(
                            labelText: 'Nombre',
                          ),
                        ),
                        SizedBox(height: 16.0),
                        TextField(
                          controller: _studentPasswordController,
                          decoration: InputDecoration(
                            labelText: 'Contraseña',
                          ),
                          obscureText: true,
                        ),
                        SizedBox(height: 16.0),
                        ElevatedButton(
                          onPressed: _loginAlumnos,
                          child: Text('Iniciar sesión'),
                        ),
                      ],
                    ),
                    isExpanded: _isStudentExpanded,
                  ),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}
