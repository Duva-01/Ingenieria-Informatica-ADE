import 'package:barcos/factoria.dart';
import 'dart:math'; 
import 'barco.dart';
import 'pez.dart';

class Mar {
  late String _nombre ; 
  late Pez _pezG ;
  late Pez _pezP ;


  Mar(String nombre) {
    _nombre = nombre ; 
    _pezG = FactoriaGrande().crearPez() ;
    _pezP = FactoriaPequenia().crearPez() ;  
  }

  bool pescar(Barco barco){
    var random = new Random(); 
    double numeroAleatorio = random.nextDouble() ;

    if(numeroAleatorio > barco.getProbabilidad()) {
      return false ; 

    } else {
        int puntacionP = 0 ; 
        if(barco is BarcoGrande) {
           puntacionP = _pezG.getPuntuacion() ; 
        }else{
          puntacionP = _pezP.getPuntuacion(); 
        }

        barco.pescar(puntacionP);
        return true; 
    }

  }

  String getNombre(){
    return _nombre;
  }

}