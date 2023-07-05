import 'Filtro.dart';
import 'package:intl/intl.dart';


class FiltroHora implements Filtro {
  late DateTime _fecha;
  late String _fechaDia;

  FiltroHora() {
    _fecha = DateTime.now();

    _fechaDia = DateFormat('yyyy-MM-dd').format(_fecha);
  }

  @override
  String ejecutar(String texto) {
    String resultado = '$texto ${_fechaDia.toString()}';
    return resultado;
  }

  @override
  String toString(){
    return "Soy un filtro hora: ${_fechaDia.toString()}\n";
  }
}
