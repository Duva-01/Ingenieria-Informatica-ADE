import 'Filtro.dart';

class FiltroContenido implements Filtro {
  late List<String> _palabrasProhibidas;

  FiltroContenido() {
    _palabrasProhibidas = [];
  }

  FiltroContenido.n2(List<String> palabras) {
    _palabrasProhibidas = palabras;
  }

  void aniadePalabras(String palabras) {
    _palabrasProhibidas.add(palabras);
  }

  @override
  String toString() {
    String aux = "Soy un filtro contenido: ";
    for (String pal in _palabrasProhibidas) {
      aux += "$pal ";
    }
    aux += "\n";

    return aux;
  }

  @override
  String ejecutar(String texto) {
    String texto_filtrado = texto;

    if (texto.isNotEmpty) {
      for (String palabra in _palabrasProhibidas) {
        texto_filtrado = texto_filtrado.replaceAll(palabra, "***");
      }
    }

    return texto_filtrado;
  }
}
