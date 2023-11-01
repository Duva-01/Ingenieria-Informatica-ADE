import 'dart:async';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:frontend_app/login.dart';

import 'package:loading_indicator/loading_indicator.dart';
import 'package:animate_do/animate_do.dart';


class LoadingPage extends StatefulWidget {
  @override
  _LoadingPageState createState() => _LoadingPageState();
}

class _LoadingPageState extends State<LoadingPage> {
  @override
  void initState() {
    super.initState();
    inicializar();
  }

  void inicializar() async {
    Timer(
        Duration(seconds: 5),
        () => Navigator.pushReplacement(
              context,
              PageRouteBuilder(
                pageBuilder: (c, a1, a2) => LoginPage(),
                transitionsBuilder: (c, anim, a2, child) =>
                    FadeTransition(opacity: anim, child: child),
                transitionDuration: Duration(milliseconds: 1000),
              ),
            ));
  }

  @override
  Widget build(BuildContext context) {
    return FlipInY(
      child: Container(
        child: Container(
          margin: EdgeInsets.all(20),
          alignment: Alignment.bottomCenter,
          child: SizedBox(
            width: 50,
            height: 50,
            child: LoadingIndicator(
              indicatorType: Indicator.orbit,
              colors: const [Colors.blue],
            ),
          ),
        ),
        decoration: BoxDecoration(
          color: Colors.white,
          image: DecorationImage(
              image: AssetImage("assets/images/accessibilityCoders.png"),
              fit: BoxFit.fitWidth),
        ),
      ),
    );
  }
}
