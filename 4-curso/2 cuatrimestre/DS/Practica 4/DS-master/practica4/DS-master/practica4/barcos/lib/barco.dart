import 'package:flutter/material.dart';
import 'pez.dart';

//No tener un list de peces si no un int 

class Barco {
  late double _probabilidad ;
  late int _peces  ; 
  late int _puntuacion ; 

  double getProbabilidad(){
    return _probabilidad ; 
  } 

  void setProbabilidad(double probabilidad) {
    _probabilidad = probabilidad ; 
  }

  Barco(double probabilidad) {
    setProbabilidad(probabilidad); 
    _peces = 0 ; 
    _puntuacion = 0 ; 
  }
  
  bool pescar(int puntuacion) {
    _peces++ ;  
    _puntuacion += puntuacion ; 
    return true ; 
  }

  int getPeces(){
    return _peces ; 
  }

  int getPuntuacion(){
  return _puntuacion ; 
  }

  String getTipo(){
    if (this is BarcoGrande) {
      return "Grande" ; 
    } else {
      return "Pequenio" ; 
    } 
  }

}


  class BarcoGrande extends Barco {

    BarcoGrande() : super(0.6) ; 
  

  }

    class BarcoPequenio extends Barco {

     BarcoPequenio() : super(0.3) ; 
     
  }
  

  




