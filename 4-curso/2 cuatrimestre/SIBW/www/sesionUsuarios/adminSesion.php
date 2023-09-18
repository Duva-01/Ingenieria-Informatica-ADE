<?php
  require_once "/usr/local/lib/php/vendor/autoload.php";

  $loader = new \Twig\Loader\FilesystemLoader('../templates');
  $twig = new \Twig\Environment($loader);
  
  require_once '../bd.php';

  $gBD=new GestorBD();

  $url = $_SERVER['HTTP_REFERER'];

  if (isset($_POST['iniciarSesion'])) {

        $usuario = $_POST['usuario'];
        $contraseña = $_POST['contraseña'];

        if ($gBD->checkLogin($usuario, $contraseña)) {
        
            session_start();
            
            $_SESSION['nickUsuario'] = $usuario;  // guardo en la sesión el nick del usuario que se ha logueado
            header("Location: $url");
            
            exit();
        }
    }

    if (isset($_POST['registrar'])) {

        $usuario = $_POST['usuarioR'];
        $contraseña = $_POST['contraseñaR'];
        $correo = $_POST['correoR'];

        $user = $gBD->obtenerUsuario($usuario);

        if ($user == null) {
            
            $result = $gBD->insertarUsuario($usuario, $contraseña, $correo);
            session_start();
            
            $_SESSION['nickUsuario'] = $usuario;  // guardo en la sesión el nick del usuario que se ha logueado
            header("Location: $url");
            
            exit();
        }
    }

    if (isset($_POST['modificar'])) {

        $usuario = $_POST['usuarioM'];
        $contraseña = $_POST['contraseñaM'];
        $correo = $_POST['correoM'];

        $user = $gBD->modificarUsuario($usuario, $correo, $contraseña);

        header("Location: $url");
            
        exit();
    }
    
    if (isset($_POST['añadirRol'])) {
        
        $usuario = $_POST['usuarioRol'];
        $rol = $_POST['rol'];

        $result = $gBD->modificarRolUsuario($usuario, $rol);

        header("Location: $url");
            
        exit();
    }

    if (isset($_POST['eliminarRol'])) {
        
        $usuario = $_POST['usuarioRol'];
        $rol = $_POST['rol'];

        $result = $gBD->eliminarRolUsuario($usuario, $rol);

        header("Location: $url");
            
        exit();
    }
    
?>
