<?php 

require_once "/usr/local/lib/php/vendor/autoload.php";
require_once "bd.php";

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig = new \Twig\Environment($loader);

$gBD=new GestorBD();

session_start();

$usuario = null;
if (isset($_SESSION['nickUsuario'])) {
    $usuario = $gBD->obtenerUsuario($_SESSION['nickUsuario']);
}

$cientificos = $gBD->obtenerTodosCientificos();
$lista_imagenes = $gBD->obtenerImagenCientificos();

echo $twig->render('index.html', [
    "Cientificos" => $cientificos,
    "usuario" => $usuario,
    "lista_imagenes" => $lista_imagenes, 
]);

?>