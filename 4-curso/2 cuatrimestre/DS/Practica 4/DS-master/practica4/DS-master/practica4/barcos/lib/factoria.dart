import 'barco.dart';
import 'pez.dart';
import 'mar.dart';


abstract class Factoria {

  Mar crearMar( String nombre){
    return Mar(nombre) ; 
  }

  @override

  Barco crearBarco() ;

  @override

  Pez crearPez() ; 

}

class FactoriaGrande extends Factoria {

  @override

  Barco crearBarco(){
    return BarcoGrande() ; 
  }

    @override

    Pez crearPez() {
      return PezGrande() ; 
    } 

}

class FactoriaPequenia extends Factoria {

  @override

  Barco crearBarco(){
    return BarcoPequenio() ; 
  }

  @override

  Pez crearPez() {
    return PezPequenio() ; 
  }

}