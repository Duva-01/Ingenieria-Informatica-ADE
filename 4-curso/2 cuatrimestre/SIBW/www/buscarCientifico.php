<?php

require_once "/usr/local/lib/php/vendor/autoload.php";
require_once "bd.php";

$gBD = new GestorBD();

if (isset($_POST['busqueda'])) {
    $busqueda = $_POST['busqueda'];
    $resultados = $gBD->buscarCientificosPorNombreYBiografiaPublicado($busqueda);
    echo json_encode(['cientificos' => $resultados]);
}

if (isset($_POST['busquedaAdmin'])){
    $busquedaAdmin = $_POST['busquedaAdmin']; 
    $resultados = $gBD->buscarCientificosPorNombreYBiografia($busquedaAdmin); 
    echo json_encode(['cientificos' => $resultados]);
}

?>
