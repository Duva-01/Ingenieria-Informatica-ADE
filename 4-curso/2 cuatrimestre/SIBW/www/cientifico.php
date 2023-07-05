<?php

require_once "/usr/local/lib/php/vendor/autoload.php";
require_once "bd.php";

$loader = new \Twig\Loader\FilesystemLoader('templates');
$twig = new \Twig\Environment($loader);

$scId = (isset($_GET['scid']) && filter_var($_GET['scid'], FILTER_VALIDATE_INT) !== false) ? $_GET['scid'] : -1;
$cid = (isset($_GET['cid']) && filter_var($_GET['cid'], FILTER_VALIDATE_INT) !== false) ? $_GET['cid'] : -1;

$gBD = new GestorBD();

$cientifico = $gBD->obtenerCientifico($scId);
$palabrasProhibidas = $gBD->obtenerPalabrasProhibidas();
$comentario = $cid !== -1 ? $gBD->obtenerComentario($cid) : null;

session_start();

$usuario = null;
if (isset($_SESSION['nickUsuario'])) {
    $usuario = $gBD->obtenerUsuario($_SESSION['nickUsuario']);
}

$comentarios = $gBD->obtenerComentariosCientifico($scId);
$imagenes = $gBD->obtenerImagenesCientifico($scId);

$hashtags = $gBD->obtenerHashtagsCientifico($scId);
$busqueda = "";


$lista_cientificos_filtrados = $gBD->buscarCientificosPorNombreYBiografia($busqueda);
$lista_comentarios_filtrados = $gBD->buscarComentarios($busqueda);


if (isset($_GET['imprimir']) && $_GET['imprimir'] === 'true') {
    $templateName = 'cientifico_imprimir.html';
} elseif (isset($_GET['modificarCientifico']) && $_GET['modificarCientifico'] === 'true') {
    $templateName = 'cientifico_modificar.html';
} elseif (isset($_GET['modificarComentario']) && $_GET['modificarComentario'] === 'true' && $comentario !== null) {
    $templateName = 'comentario_modificar.html';
} else {
    $templateName = 'cientifico.html';
}

echo $twig->render($templateName, [
    'lista_cientificos_filtrados' => $lista_cientificos_filtrados,
    'lista_comentarios_filtrados' => $lista_comentarios_filtrados,
    'hashtags' => $hashtags,
    'cientifico' => $cientifico,
    'palabrasProhibidas' => $palabrasProhibidas,
    'comentarios' => $comentarios,
    'imagenes' => $imagenes,
    'usuario' => $usuario,
    'comentario' => $comentario,
]);
