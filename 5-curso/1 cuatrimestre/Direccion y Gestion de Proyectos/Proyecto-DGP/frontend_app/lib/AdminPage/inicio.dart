import 'package:flutter/material.dart';
import '../Widgets/menuController.dart';
import '../network.dart';

import 'Administradores/AdministradoresPage.dart';
import 'Alumnos/AlumnosPage.dart';
import 'Tareas/TareasPage.dart';

import 'package:flutter_zoom_drawer/flutter_zoom_drawer.dart';

final ZoomDrawerController controller = ZoomDrawerController();

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _selectedIndex = 0; // índice de la página seleccionada

  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index; // actualizar el índice de la página seleccionada
    });
  }

  @override
  Widget build(BuildContext context) {
    final pages = [
      AdministradoresPage(),
      AlumnosPage(),
      TareasPage()
    ]; // lista de páginas

    return ZoomDrawer(
      controller: controller,
      mainScreen: pages[_selectedIndex], // mostrar la página seleccionada
      menuScreen: MenuScreen(controller: controller, onItemTapped: _onItemTapped),
      borderRadius: 24,
      showShadow: true,
      angle: 0.0,
      drawerShadowsBackgroundColor: Colors.grey,
      slideWidth: MediaQuery.of(context).size.width * 0.65,
      menuBackgroundColor: Colors.blue,
    );
  }
}
