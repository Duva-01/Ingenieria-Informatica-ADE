import 'package:ejercicio_filtro/Filtro.dart';
import 'package:tuple/tuple.dart';

import 'ServerTarget.dart';
import 'CadenaFiltros.dart';
import 'FiltroHora.dart';

class GestorFiltros {
  late ServerTarget _target;
  late CadenaFiltros _cadena;

  GestorFiltros() {
    _cadena = CadenaFiltros();
    _target = ServerTarget();

    aniadirFiltro(FiltroHora());
  }

  GestorFiltros.n2(CadenaFiltros cad) {
    _cadena = cad;
    _target = ServerTarget();
  }

  GestorFiltros.n3(ServerTarget servidor) {
    _target = servidor;
    _cadena = CadenaFiltros();

    aniadirFiltro(FiltroHora());
  }

  void aniadeComentario(String comentario) {
    
    _target.aniaddeComentario(comentario, _cadena.ejecutar(comentario));
  }

  Tuple2 getComentario(int i) {
    return _target.getComentarios()[i];
  }

  List<Tuple2> getComentarios() {
    return _target.getComentarios();
  }

  CadenaFiltros getCadena() {
    return _cadena;
  }

  void aniadirFiltro(Filtro filtro) {
    _cadena.aniadeFiltro(filtro);
  }

  void resetGestor() {
    _cadena.resetCadena();

    aniadirFiltro(FiltroHora());
  }
}
