import 'Filtro.dart';

class CadenaFiltros {
  late List<Filtro> _filtros;

  CadenaFiltros() {
    _filtros = [];
  }

  CadenaFiltros.n(List<Filtro> f) {
    _filtros = f;
  }

  String ejecutar(String texto) {
    for (Filtro filtro in _filtros) texto = filtro.ejecutar(texto);

    return texto;
  }

  List<Filtro> getFiltros() {
    return _filtros;
  }

  void aniadeFiltro(Filtro filtro) {
    _filtros.add(filtro);
  }

  void resetCadena() {
    _filtros = [];
  }
}
