<?php 

require_once "/usr/local/lib/php/vendor/autoload.php";
require_once "../bd.php";

$loader = new \Twig\Loader\FilesystemLoader('../templates');
$twig = new \Twig\Environment($loader);

$gBD=new GestorBD();

$url = $_SERVER['HTTP_REFERER'];
$resultado = true;

session_start();

$usuario = null;
$errors= array();

if (isset($_SESSION['nickUsuario'])) {
    $usuario = $gBD->obtenerUsuario($_SESSION['nickUsuario']);
}

$cientificos = $gBD->obtenerTodosCientificos();

if (isset($_POST['añadir'])) {
    
    $errors= array();

    $nombre_cientifico = $_POST['nombre'];

    for($i=0; $i<count($cientificos); $i++){
        if($nombre_cientifico == $cientificos[$i]['nombre']){
            $errors[] = "Nombre de cientifico ya en uso";
        }
    }
    $fecha_nacimiento = $_POST['nacimiento'];
    $fecha_fallecimiento = $_POST['muerte'];
    $ciudad_nacimiento = $_POST['ciudad'];
    $bibliografia = $_POST['bibliografia'];
    $publicado = ($_POST['publicado'] === 'true') ? true : false;
    $resultado_img = false;

    if(isset($_FILES['imagen'])){
        
        $file_name = $_FILES['imagen']['name'];
        $file_size = $_FILES['imagen']['size'];
        $file_tmp = $_FILES['imagen']['tmp_name'];
        $file_type = $_FILES['imagen']['type'];
        $temp = explode('.', $_FILES['imagen']['name']);
        $file_ext = strtolower(end($temp));
        
        $extensions= array("jpeg","jpg","png");
        
        if (in_array($file_ext,$extensions) === false){
          $errors[] = "Extensión no permitida, elige una imagen JPEG o PNG.";
        }
        
        if ($file_size > 2097152){
          $errors[] = 'Tamaño del fichero demasiado grande';
        }
        
        if (sizeof($errors) > 0) {
          $varsParaTwig['errores'] = $errors;
        }
    }

    if (empty($errors)==true) {

        $maxId = $gBD->obtenerMaxId();
        $resultado = $gBD->insertarCientifico($maxId+1, $nombre_cientifico, $fecha_nacimiento, $fecha_fallecimiento, $ciudad_nacimiento, $bibliografia, $publicado);
        
        if($resultado === true){
            $resultado_img = $gBD->insertarImagenCientifico($maxId+1, $file_name);
            move_uploaded_file($file_tmp, "../images/" . $file_name);
        }
        
    }

    if ($resultado === false || $resultado_img === false) {
        $errors[] = "Error al insertar el científico/imagen en la base de datos.";
    }

    header("Location: $url");
}

if (isset($_POST['eliminar'])) {

    $id_c = $_POST['id_c'];
    $gBD->eliminarCientifico($id_c);

    header("Location: $url");
}

if (isset($_POST['modificar'])) {

    
    $id_c = $_POST['id_c'];
    $nombre_cientifico = $_POST['nombre'];

    $fecha_nacimiento = $_POST['nacimiento'];
    $fecha_fallecimiento = $_POST['muerte'];

    $ciudad_nacimiento = $_POST['ciudad'];
    $bibliografia = $_POST['bibliografia'];

    $publicado = ($_POST['publicado'] === 'true') ? true : false;

    $resultado = $gBD->modificarCientifico($id_c, $nombre_cientifico, $fecha_nacimiento, $fecha_fallecimiento, $ciudad_nacimiento, $bibliografia, $publicado);
    
    if(isset($_FILES['imagen'])){
        
        $file_name = $_FILES['imagen']['name'];
        $file_size = $_FILES['imagen']['size'];
        $file_tmp = $_FILES['imagen']['tmp_name'];
        $file_type = $_FILES['imagen']['type'];
        $temp = explode('.', $_FILES['imagen']['name']);
        $file_ext = strtolower(end($temp));
        
        $extensions= array("jpeg","jpg","png");
        
        if (in_array($file_ext,$extensions) === false){
          $errors[] = "Extensión no permitida, elige una imagen JPEG o PNG.";
        }
        
        if ($file_size > 2097152){
          $errors[] = 'Tamaño del fichero demasiado grande';
        }
        
        if (sizeof($errors) > 0) {
          $varsParaTwig['errores'] = $errors;
        }
    }

    if (empty($errors)==true) {

        $resultado_img = $gBD->insertarImagenCientifico($id_c, $file_name);
        move_uploaded_file($file_tmp, "../images/" . $file_name); 
    }

    if ($resultado === false) {
        $errors[] = "Error al modificar el científico en la base de datos.";
    }

    header("Location: $url");
}

$busqueda = "";
$lista_cientificos_filtrados = $gBD->buscarCientificosPorNombreYBiografia($busqueda, 1);

if (isset($_POST['busquedaNombre'])) {
    $busqueda = $_POST['filtroNombre'];
    $lista_cientificos_filtrados = $gBD->buscarCientificosPorNombreYBiografia($busqueda, 1);
}

if (isset($_POST['busquedaHashtag'])) {
        $busqueda = $_POST['filtroHashtag'];
        $lista_cientificos_filtrados = $gBD->buscarCientificosPorHashtag($busqueda);
}

if (isset($_POST['añadirHashtag'])) {

    $idHashtag = $_POST['idHashtag'];
    $Hashtag = $_POST['hashtag'];

    $gBD->insertarHashtagCientifico($idHashtag, $Hashtag);
}

if (isset($_POST['eliminarHashtag'])) {

    $idHashtag = $_POST['idHashtag'];
    $Hashtag = $_POST['hashtag'];

    $gBD->eliminarHashtagCientifico($idHashtag, $Hashtag);
}

    echo $twig->render('cientifico_modificar.html', ["Cientificos" => $cientificos, "usuario" => $usuario, 'lista_cientificos_filtrados' => $lista_cientificos_filtrados]);
?>