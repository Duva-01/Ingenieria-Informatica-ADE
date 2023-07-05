import 'Filtro.dart';

class FiltroHora implements Filtro {
  late DateTime _fecha;

  FiltroHora() {
    _fecha = DateTime.now();
  }

  @override
  String ejecutar(String texto) {
    String resultado = '$texto ${_fecha.toString()}';
    return resultado;
  }

  @override
  String toString(){
    return "Soy un filtro hora: ${_fecha.toString()}\n";
  }
}
