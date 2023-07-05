import 'package:flutter/material.dart';
import 'barco.dart';

abstract class  Pez {
  int _puntuacion = 0  ; 
  

  int getPuntuacion() {
    return _puntuacion ; 
  }

}

class PezGrande extends Pez {


  PezGrande(){
    _puntuacion = 100 ; 
  }


}

class PezPequenio extends Pez {

   PezPequenio(){
    _puntuacion = 50 ; 
  }

}