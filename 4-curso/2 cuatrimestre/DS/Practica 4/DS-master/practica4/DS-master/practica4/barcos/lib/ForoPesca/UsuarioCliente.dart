import 'GestorFiltros.dart';
import 'ServerTarget.dart';

class UsuarioCliente {
  late GestorFiltros _gestor;

  UsuarioCliente() {
    _gestor = GestorFiltros();
  }

  UsuarioCliente.n2(ServerTarget server) {
    _gestor = GestorFiltros.n3(server);
  }

  GestorFiltros getGestor() {
    return _gestor;
  }
}
