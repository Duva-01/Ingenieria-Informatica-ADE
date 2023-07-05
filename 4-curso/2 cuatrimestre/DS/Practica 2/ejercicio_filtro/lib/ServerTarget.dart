import 'package:tuple/tuple.dart';

class ServerTarget {
  late List<Tuple2<String, String>> _comentarios;

  ServerTarget() {
    _comentarios = [];
  }

  void aniaddeComentario(String comentario, String comentarioFiltrado) {
    _comentarios.add(Tuple2(comentario, comentarioFiltrado));
  }

  List<Tuple2<String, String>> getComentarios() {
    return _comentarios;
  }
}
