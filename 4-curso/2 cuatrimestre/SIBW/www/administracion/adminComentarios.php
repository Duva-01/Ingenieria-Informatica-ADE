<?php

require_once "/usr/local/lib/php/vendor/autoload.php";
require_once "../bd.php";

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig = new \Twig\Environment($loader);

$gBD = new GestorBD();

$url = $_SERVER['HTTP_REFERER'];

session_start();

if (isset($_POST['enviarComentario'])) {

    $scId = $_POST['idCientificoComentario'];
    $nombre = $_POST['nombreFormulario'];
    $correo = $_POST['emailFormulario'];
    $comentario = $_POST['textoComentario'];

    $resultado = $gBD->insertarComentario($scId, $nombre, $correo, $comentario);

    if ($resultado === false) {
        $errors[] = "Error al enviar el comentario en la base de datos.";
    }

    header("Location: $url");
    exit; 
}

if (isset($_POST['borrarComentario'])) {

    $scId = $_POST['idCientificoComentario'];
    $idComentario = $_POST['idComentario'];

    $resultado = $gBD->borrarComentario($idComentario);

    if ($resultado === false) {
        $errors[] = "Error al enviar el comentario en la base de datos.";
    }

    header("Location: $url");
    exit; 
}

if (isset($_POST['modificarComentario'])) {

    $scId = $_POST['idCientificoComentarioM'];
    $idComentario = $_POST['idComentarioM'];
    $nombre = $_POST['nombreComentarioM'];
    $email = $_POST['emailComentarioM'];
    $fecha = $_POST['fechaComentarioM'];
    $comentario = $_POST['textoComentarioM'];


    $resultado = $gBD->modificarComentario($idComentario, $nombre, $email, $fecha, $comentario);

    if ($resultado === false) {
        $errors[] = "Error al modificar el comentario en la base de datos.";
    }

    header("Location: $url");
    exit; 
}

$usuario = null;
if (isset($_SESSION['nickUsuario'])) {
    $usuario = $gBD->obtenerUsuario($_SESSION['nickUsuario']);
}

$busqueda = "";

if (isset($_POST['busquedaComentarios'])) {
    $busqueda = $_POST['filtroComentario'];
}

$lista_comentarios_filtrados = $gBD->buscarComentarios($busqueda);
$cientificos = $gBD->obtenerTodosCientificos();

echo $twig->render('comentario_modificar.html', ["Cientificos" => $cientificos, "usuario" => $usuario, 'lista_comentarios_filtrados' => $lista_comentarios_filtrados]);

?>
