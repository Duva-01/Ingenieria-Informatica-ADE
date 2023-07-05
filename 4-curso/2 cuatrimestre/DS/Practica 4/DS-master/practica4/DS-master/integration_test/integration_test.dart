//import 'dart:js_util';

import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:integration_test/integration_test.dart';


import 'package:barcos/main.dart' as app;
//TODO:  1. Inicializar variable 2. Poner las mismas keys de aqui en el main
void main() {
  IntegrationTestWidgetsFlutterBinding.ensureInitialized(); //hay q inicializarla pero no se como

  group('Integration test', () {
    testWidgets('Test completo: registro + crear barco + comentar',
        (tester) async {
      final registro = RegisterPage("hola", "hola", "hola@hola");
      app.main();
      await tester.pumpAndSettle();
      /*1. Ir al registro
        2. Registrarse
        3. Volver atrás
        4. Iniciar sesion
        5. Ir a crear barco
        6. Dar en un barco grande
        7. Volver atrás
        8. Ir al foro
        9. Escribir hola*/
        //Paso del 1 al 4
        final signupText = find.byKey(Key("Signup"));
        await tester.tap(signupText);
        await tester.pumpAndSettle();
        expect(await registro.registrar(tester),'Registrado');
        //Paso 5 al 7
        final barco = BarcoPage();
        expect(await barco.crearBarco(tester),true);
        //Paso 7 al 9
        final comentario  = ForoPage("hola");
        expect(await comentario.comentar(tester),true);
    });
  });
}

class RegisterPage{
  late final String _user, _password, _mail;

  RegisterPage(String usuario, String contrasea, _email){
    _user = usuario;
    _password = contrasea;
    _mail = _email;
  }

  Future<String> registrar(WidgetTester tester) async {
    //1.Obtener keys de los campos a introducir
    final userField = find.byKey(const Key("IUserRegister"));
    final passField = find.byKey(const Key("IPassRegister"));
    final mailField = find.byKey(const Key("IMailRegister"));
    //2.Introducir campos
    await tester.enterText(userField, _user);
    await tester.enterText(passField, _password);
    await tester.enterText(mailField, _mail);
    //3.Obtener el resultado
    final registerButton = find.text('Registrar');
    await tester.tap(registerButton);
    await tester.pumpAndSettle(); //Estabiliza

    //3.1 Obtener ventana emergente
    final succeedWindow = find.text('Registro exitoso');

    // ignore: unnecessary_null_comparison
    if(tester.widget(succeedWindow) != null ){//Si la ventana aparece
      //3.1.1 Obtener botón aceptar
      final acceptButton = find.text('Aceptar');
      await tester.tap(acceptButton);
      await tester.pumpAndSettle(); //Estabiliza
      return "Registrado";
    }else{
      return "No registrado";
    }
  }

}

class BarcoPage{
  BarcoPage();
  Future<bool> crearBarco(WidgetTester tester) async{
    bool generated;
    //1.Ir a pestaña crear barco
    final addBarcoButton = find.text('Añadir Barco');
    await tester.tap(addBarcoButton);
    await tester.pumpAndSettle();
    //2.Crear un barco
    final crearBarcoGrandeButton = find.byKey(const Key('crearBarcoGrandeButton'));
    await tester.tap(crearBarcoGrandeButton);
    await tester.pumpAndSettle();
    //3. Devolver si se ha creado
    final resultText = find.text('Barco Grande 1');
    // ignore: unnecessary_null_comparison
    if(tester.widget(resultText) != null){
      //3.1.1 Ir hacia atrás 
      final getBackIcon = find.byIcon(Icons.arrow_back);
      await tester.tap(getBackIcon);
      await tester.pumpAndSettle();
      generated = true;
    }else {
      generated = false;
    }
    
    return generated;
  }
}

class ForoPage{
  late final String _text;
  ForoPage(String comentario){
    _text = comentario;
  }

  Future<bool> comentar(WidgetTester tester) async{
    bool commented;
    //1. Ir al foro
    final foroButton = find.text('Foro');
    await tester.tap(foroButton);
    await tester.pumpAndSettle();
    //2. Obtener campos y escribir
    final commentField = find.byKey(const Key("addComment"));
    await tester.enterText(commentField,_text);
    final addCommentButton = find.text('Enviar');
    tester.tap(addCommentButton);
    await tester.pumpAndSettle();
    //3. Obtener resultado
    final commentText = find.text(_text);
    // ignore: unnecessary_null_comparison
    if(tester.widget(commentText) != null){
      commented=true;
    }else{
      commented=false;
    }
    return commented;
  }
}