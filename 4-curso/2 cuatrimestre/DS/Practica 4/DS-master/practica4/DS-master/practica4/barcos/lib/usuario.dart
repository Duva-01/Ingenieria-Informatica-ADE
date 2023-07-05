import 'barco.dart';

class Usuario {
  final String nick;
  final String correo;
  final String contrasenia;
  List<Barco> barcos = [];

  Usuario(this.nick, this.correo, this.contrasenia);

  
}

class Autenticacion {
  static final Autenticacion _instancia = Autenticacion._();

  factory Autenticacion() {
    return _instancia;
  }

  Autenticacion._() {
    registrarNuevoUsuario(Usuario("admin", "admin@gmail.com", "admin"));
  }

  List<Usuario> _usuarios = [];

  void registrarNuevoUsuario(Usuario usuario) {
    _usuarios.add(usuario);
  }

  bool existeUsuario(String nombreUsuario) {
    return _usuarios.any((usuario) => usuario.nick == nombreUsuario);
  }

  bool existeCorreo(String correo) {
    return _usuarios.any((usuario) => usuario.correo == correo);
  }

  void registrarUsuario(Usuario usuario) {
    _usuarios.add(usuario);
  }

  bool comprobarCredencialesInicio(String nickUsuario, String contrasenia) {
    for (Usuario u in _usuarios) {
      if (u.nick == nickUsuario && u.contrasenia == contrasenia) {
        return true;
      }
    }

    return false;
  }

  bool comprobarCredencialesRegistro(String nickUsuario, String correo) {
    bool existeNick = _usuarios.any((usuario) => usuario.nick == nickUsuario);
    bool existeCorreo = _usuarios.any((usuario) => usuario.correo == correo);

    return existeNick || existeCorreo;
  }

  bool registrar(String nickUsuario, String correo, String contrasenia) {
    if (comprobarCredencialesRegistro(nickUsuario, correo)) {
      return false;
    }

    Usuario nuevoUsuario = Usuario(nickUsuario, correo, contrasenia);
    registrarNuevoUsuario(nuevoUsuario);

    // si es true se vuelve a la pestaña anterior y se inicia sesion
    return true;
  }

  Usuario obtenerUsuario(String nickUsuario, String contrasenia){
    for (Usuario u in _usuarios) {
      if (u.nick == nickUsuario && u.contrasenia == contrasenia) {
        return u;
      }
    }

    return Usuario("", "", "");
  }
}
