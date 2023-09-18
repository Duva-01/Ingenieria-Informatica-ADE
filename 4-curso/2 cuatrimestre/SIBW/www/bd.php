<?php

// Usuarios disponibles

// Usuario: David -- Contraseña: camion -- Rol: Super-admin -- Hash: $2y$10$WqfphK/W.CEnaZAvQZxEb.eQVJTswGLwAvxZ59UWN38S2wqaCbwcC
// Usuario: Rico -- Contraseña: tetera -- Rol: Gestor -- Hash: $2y$10$81kZHg/792eY1NSxHGYaJOJ0szQw0m6aWW1mP7gEucoh0nI.84AbG
// Usuario: Pepe -- Contraseña: tonto -- Rol: Moderador -- Hash: $2y$10$rmb84Rf2/PSLjxoUSCsB5..8/.NmlpF2za4zNetXORrdt4zDkWOOO
// Usuario: Antonio -- Contraseña: mando -- Rol: Registrado -- Hash: $2y$10$IMx1D/4X.NMuShhtYwbZBOSqqW.wYSk06nPupkQ.FXK8u0NSbzbvu

class GestorBD{

    private $mysqli;
    public $usuarios = [ ['usuario' => 'Pepe', 'contraseña' => '$2y$10$rmb84Rf2/PSLjxoUSCsB5..8/.NmlpF2za4zNetXORrdt4zDkWOOO', 'rol' => "Super-admin"] ];

    function __construct(){
        $this->conectarDB();
    }

    function getMySQLi(){
        return $this->mysqli;
    }

    private function conectarDB(){
        $this->mysqli=new mysqli("database", "david", "david", "SIBW");

        if($this->mysqli->connect_errno){
            echo("Fallo al conectar: ". $this->mysqli->connect_error);
            exit();
        }
    }

    //-----------------------------------------------------------------
    //-----------------------------------------------------------------

    function obtenerTodosCientificos(){

        $lista_cientificos = array();

        $resultado = $this->mysqli->query("SELECT * FROM cientificos");

        if($resultado->num_rows > 0){
            while($fila = $resultado->fetch_assoc()){
                $cientifico = array('id' => $fila['id'], 'nombre' => $fila['nombre'], 'nacimiento' => $fila['nacimiento'], 'muerte' => $fila['muerte'], 'ciudad' => $fila['ciudad'], 'bibliografia' => $fila['bibliografia'], 'publicado' => $fila['publicado']); 
                array_push($lista_cientificos, $cientifico);
            }
        }

        return $lista_cientificos;
    }

    function obtenerCientifico($scId){

        if ($scId == -1) {
            return null;
        }

        $cientifico = array('id' => $scId, 'nombre'=> 'xxx', 'nacimiento' => 'yyy', 'muerte' => 'zzz', 'ciudad' => 'xxx', 'bibliografia' => 'xxx', 'publicado' => 'x'); 
        
        $sentencia = $this->mysqli->prepare("SELECT * FROM cientificos WHERE id=?");
        $sentencia->bind_param("i", $scId);

        $sentencia->execute();
        $resultado = $sentencia->get_result();

        if($resultado->num_rows > 0){
            $fila = $resultado->fetch_assoc();
            $cientifico = array('id' => $fila['id'], 'nombre' => $fila['nombre'], 'nacimiento' => $fila['nacimiento'], 'muerte' => $fila['muerte'], 'ciudad' => $fila['ciudad'], 'bibliografia' => $fila['bibliografia'], 'publicado' => $fila['publicado']); 
        }

        return $cientifico;
    }

    function insertarCientifico($scId, $nombre_cientifico, $fecha_nacimiento, $fecha_fallecimiento, $ciudad_nacimiento, $bibliografia, $publicado = false){
        $sentencia = $this->mysqli->prepare("INSERT INTO cientificos (id, nombre, nacimiento, muerte, ciudad, bibliografia, publicado) VALUES (?, ?, ?, ?, ?, ?, ?)");
        $sentencia->bind_param("isssssi", $scId, $nombre_cientifico, $fecha_nacimiento, $fecha_fallecimiento, $ciudad_nacimiento, $bibliografia, $publicado);
        $result = $sentencia->execute();
        $sentencia->close();

        return $result;
    }

    function modificarCientifico($scId, $nombre_cientifico, $fecha_nacimiento, $fecha_fallecimiento, $ciudad_nacimiento, $bibliografia, $publicado = false) {
        $publicado = ($publicado) ? 1 : 0; // Convierte el booleano en 1 o 0
    
        $sentencia = $this->mysqli->prepare("UPDATE cientificos SET nombre=?, nacimiento=?, muerte=?, ciudad=?, bibliografia=?, publicado=? WHERE id=?");
        $sentencia->bind_param("ssssssi", $nombre_cientifico, $fecha_nacimiento, $fecha_fallecimiento, $ciudad_nacimiento, $bibliografia, $publicado, $scId);
        $result = $sentencia->execute();
        $sentencia->close();
    
        return $result;
    }
    

    function eliminarCientifico($scId){

        $sentencia = $this->mysqli->prepare("DELETE FROM cientificos WHERE id=?");
        $sentencia->bind_param("i", $scId);
        $result = $sentencia->execute();
        $sentencia->close();

        return $result;
    }

    function obtenerComentariosCientifico($scId){

        if ($scId == -1) {
            return null;
        }

        $lista_comentarios = array();

        $sentencia = $this->mysqli->prepare("SELECT * FROM comentarios WHERE id_c=?");
        $sentencia->bind_param("i", $scId);

        $sentencia->execute();
        $resultado = $sentencia->get_result();

        if($resultado->num_rows > 0){
            while($fila = $resultado->fetch_assoc()){
                $comentario = array('id' => $fila['id'], 'nombre' => $fila['nombre'], 'email' => $fila['email'], 'comentario' => $fila['comentario'], 'fecha' => $fila['fecha']); 
                array_push($lista_comentarios, $comentario);
            }
        }

        return $lista_comentarios;
    }

    function obtenerComentario($idComentario) {

        $sentencia = $this->mysqli->prepare("SELECT * FROM comentarios WHERE id = ?");
        $sentencia->bind_param("i", $idComentario);

        if (!$sentencia->execute()) {
            return null;
        }

        $resultado = $sentencia->get_result();
        $comentario = $resultado->fetch_assoc();

        if (!$comentario) {
            return null;
        }

        return $comentario;
    }

    function insertarComentario($scId, $nombre, $correo, $comentario) {
        $fecha = date('Y-m-d H:i:s');
    
        $sentencia = $this->mysqli->prepare("INSERT INTO comentarios (id_c, nombre, email, comentario, fecha) VALUES (?, ?, ?, ?, ?)");
        $sentencia->bind_param("issss", $scId, $nombre, $correo, $comentario, $fecha);
    
        return $sentencia->execute();
    }

    function borrarComentario($idComentario) {
        
        $sentencia = $this->mysqli->prepare("DELETE FROM comentarios WHERE id=?");
        $sentencia->bind_param("i", $idComentario);
    
        return $sentencia->execute();
    }

    function modificarComentario($idComentario, $nombre, $email, $fecha, $comentario) {
        
        if (strpos($comentario, '("Modificado")') !== 0) {
            $comentario = '("Modificado") ' . $comentario;
        }
    
        $sentencia = $this->mysqli->prepare("UPDATE comentarios SET nombre = ?, email = ?, fecha = ?, comentario = ? WHERE id = ?");
        $sentencia->bind_param("ssssi", $nombre, $email, $fecha, $comentario, $idComentario);
    
        return $sentencia->execute();
    }
    
    public function buscarComentarios($busqueda) {
        $comentarios = [];
    
        $sentencia = $this->mysqli->prepare("SELECT * FROM comentarios WHERE comentario LIKE ?");
        $busquedaConComodines = '%' . $busqueda . '%';
        $sentencia->bind_param("s", $busquedaConComodines);
    
        $sentencia->execute();
        $resultado = $sentencia->get_result();
    
        while ($fila = $resultado->fetch_assoc()) {
            $comentarios[] = array(
                'id' => $fila['id'],
                'nombre' => $fila['nombre'],
                'email' => $fila['email'],
                'fecha' => $fila['fecha'],
                'comentario' => $fila['comentario']
            );
        }
    
        return $comentarios;
    }

    function obtenerImagenesCientifico($scId){

        if ($scId == -1) {
            return null;
        }

        $lista_imagenes = array();

        $sentencia = $this->mysqli->prepare("SELECT * FROM img_cientifico WHERE id_c=?");
        $sentencia->bind_param("i", $scId);

        $sentencia->execute();
        $resultado = $sentencia->get_result();

        if($resultado->num_rows > 0){
            while($fila = $resultado->fetch_assoc()){
                $imagen = array('enlace' => $fila['enlace'], 'id_c' => $fila['id_c']); 
                array_push($lista_imagenes, $imagen);
            }
        }

        return $lista_imagenes;
    }

    function obtenerImagenCientificos() {
        $lista_imagenes = array();
    
        $sentencia = $this->mysqli->prepare("SELECT enlace, id_c FROM img_cientifico WHERE (id_c, enlace) IN (SELECT id_c, MIN(enlace) FROM img_cientifico GROUP BY id_c) ORDER BY id_c");
    
        if ($sentencia === false) {
            die('Error en la consulta: ' . $this->mysqli->error);
        }
    
        $sentencia->execute();
        $resultado = $sentencia->get_result();
    
        if($resultado->num_rows > 0) {
            while($fila = $resultado->fetch_assoc()) {
                $imagen = array('enlace' => $fila['enlace'], 'id_c' => $fila['id_c']); 
                array_push($lista_imagenes, $imagen);
            }
        }
    
        return $lista_imagenes;
    }
    
    

    function insertarImagenCientifico($scId, $file_name){

        $ruta = "/images/" . $file_name;
        $sentencia = $this->mysqli->prepare("INSERT INTO img_cientifico (enlace, id_c) VALUES (?, ?)");
        $sentencia->bind_param("si", $ruta, $scId);
        $sentencia->execute();
        $sentencia->close();
    }

    function obtenerMaxId(){

        $resultado = $this->mysqli->query("SELECT MAX(id) as max_id FROM cientificos");
        $fila = $resultado->fetch_assoc();

        $maxId = $fila['max_id']; 

        return $maxId;
    }

    function buscarCientificosPorNombreYBiografia($busqueda) {
        
        $cientificos = array();
        
        $sentencia = $this->mysqli->prepare("SELECT * FROM cientificos WHERE (nombre LIKE ? OR bibliografia LIKE ?)");
        $sentencia->bind_param("ss", $busquedaConComodines, $busquedaConComodines);
    
        $busquedaConComodines = '%' . $busqueda . '%';
    
        $sentencia->execute();
        $resultado = $sentencia->get_result();
    
        while ($fila = $resultado->fetch_assoc()) {
            $cientificos[] = array(
                'id' => $fila['id'],
                'nombre' => $fila['nombre'],
                'nacimiento' => $fila['nacimiento'],
                'muerte' => $fila['muerte'],
                'ciudad' => $fila['ciudad'],
                'bibliografia' => $fila['bibliografia'],
                'publicado' => $fila['publicado']
            );
        }
    
        return $cientificos;
    }
    
    function buscarCientificosPorNombreYBiografiaPublicado($busqueda) {
        
        $cientificos = array();
        
        $sentencia = $this->mysqli->prepare("SELECT * FROM cientificos WHERE (nombre LIKE ? OR bibliografia LIKE ?) AND publicado=1");
        $sentencia->bind_param("ss", $busquedaConComodines, $busquedaConComodines);
    
        $busquedaConComodines = '%' . $busqueda . '%';
    
        $sentencia->execute();
        $resultado = $sentencia->get_result();
    
        while ($fila = $resultado->fetch_assoc()) {
            $cientificos[] = array(
                'id' => $fila['id'],
                'nombre' => $fila['nombre'],
                'nacimiento' => $fila['nacimiento'],
                'muerte' => $fila['muerte'],
                'ciudad' => $fila['ciudad'],
                'bibliografia' => $fila['bibliografia'],
                'publicado' => $fila['publicado']
            );
        }
    
        return $cientificos;
    }

    function buscarCientificosPorHashtag($busqueda) {
        $cientificos = array();
    
        // Preparamos la consulta SQL
        $sentencia = $this->mysqli->prepare(
            "SELECT c.* FROM cientificos c
            INNER JOIN hashtags h ON c.id = h.id_c
            WHERE h.hashtag = ?"
        );
        
    
        // Enlazamos el parámetro de búsqueda
        $sentencia->bind_param("s", $busqueda);
    
        // Ejecutamos la consulta
        $sentencia->execute();
        $resultado = $sentencia->get_result();
    
        // Procesamos los resultados
        while ($fila = $resultado->fetch_assoc()) {
            $cientificos[] = array(
                'id' => $fila['id'],
                'nombre' => $fila['nombre'],
                'nacimiento' => $fila['nacimiento'],
                'muerte' => $fila['muerte'],
                'ciudad' => $fila['ciudad'],
                'bibliografia' => $fila['bibliografia'],
                'publicado' => $fila['publicado']
            );
        }
    
        return $cientificos;
    }

    function obtenerHashtagsCientifico($scId) {
        
        $hashtags = array();
        $sentencia = $this->mysqli->prepare(
            "SELECT h.hashtag FROM hashtags h
            WHERE h.id_c = ?"
        );
    
        $sentencia->bind_param("i", $scId);
    

        $sentencia->execute();
        $resultado = $sentencia->get_result();

        while ($fila = $resultado->fetch_assoc()) {
            $hashtags[] = $fila['hashtag'];
        }
    
        return $hashtags;
    }

    function insertarHashtagCientifico($idHashtag, $Hashtag){

        $sentencia = $this->mysqli->prepare(
            "INSERT INTO hashtags (hashtag, id_c) VALUES (?, ?)"
        );
    
        // Enlazamos los parámetros
        $sentencia->bind_param("si", $Hashtag, $idHashtag);
    
        // Ejecutamos la consulta
        $resultado = $sentencia->execute();
    
        // Verificamos si la inserción fue exitosa
        if ($resultado) {
            return true;
        } else {
            return false;
        }

    }

    function eliminarHashtagCientifico($idHashtag, $Hashtag) {
        // Preparamos la consulta SQL
        $sentencia = $this->mysqli->prepare(
            "DELETE FROM hashtags WHERE id_c = ? AND hashtag = ?"
        );
    
        // Enlazamos los parámetros
        $sentencia->bind_param("is", $idHashtag, $Hashtag);
    
        // Ejecutamos la consulta
        $resultado = $sentencia->execute();
    
        // Verificamos si la eliminación fue exitosa
        if ($resultado) {
            return true;
        } else {
            return false;
        }
    }
    
    //-----------------------------------------------------------------
    //-----------------------------------------------------------------

    function obtenerPalabrasProhibidas(){

        $lista_palabras = array();

        
        $resultado = $this->mysqli->query("SELECT * FROM palabrasProhibidas");

        if($resultado->num_rows > 0){
            while($fila = $resultado->fetch_assoc()){
                array_push($lista_palabras, $fila['palabra']);
            }
        }

        return $lista_palabras;

    }

    function obtenerPalabrasProhibidasJSON(){
        $lista_palabras = $this->obtenerPalabrasProhibidas();
        return json_encode($lista_palabras);
    }
    
    
    //--------------------------------------------------------//
    // Practica 4

    // Devuelve true si existe un usuario con esa contraseña
    function checkLogin($usuario, $contraseña) {

        $user = $this->obtenerUsuario($usuario);
               
        if ($user != null && password_verify($contraseña, $user['hash'] )) {
            return true;
        }
        else {
            return false;
        }
    }
    
    // Devuelve la información de un usuario a partir de su nick 
    function obtenerUsuario($usuario){

        $sentencia = $this->mysqli->prepare("SELECT * FROM usuarios WHERE usuario=?");
        $sentencia->bind_param("s", $usuario);
    
        $sentencia->execute();
        $resultado = $sentencia->get_result();
    
        if($resultado->num_rows > 0){
            $fila = $resultado->fetch_assoc();
            return array('usuario' => $fila['usuario'], 'rol' => $fila['rol'], 'hash' => $fila['hash'], 'correo' => $fila['correo']);
        } else {
            return null;
        }
    }
    
    function insertarUsuario($usuario, $contraseña, $correo){
        
        $contraseña_hash = password_hash($contraseña, PASSWORD_DEFAULT);

        $sentencia = $this->mysqli->prepare("INSERT INTO usuarios (usuario, rol, hash, correo) VALUES (?, 'Registrado', ?, ?)");
        $sentencia->bind_param("sss", $usuario, $contraseña_hash, $correo);
        $result = $sentencia->execute();
        $sentencia->close();

        return $result;
    }

    function modificarUsuario($usuario, $correo, $contraseña) {
        
        if (!empty($contraseña)) {
            $contraseña_hash = password_hash($contraseña, PASSWORD_DEFAULT);
            $sentencia = $this->mysqli->prepare("UPDATE usuarios SET correo=?, hash=? WHERE usuario=?");
            $sentencia->bind_param("sss", $correo, $contraseña_hash, $usuario);
        } else {
            
            $sentencia = $this->mysqli->prepare("UPDATE usuarios SET correo=? WHERE usuario=?");
            $sentencia->bind_param("ss", $correo, $usuario);
        }
    
        $result = $sentencia->execute();
        $sentencia->close();
    
        return $result;
    }
    
    public function modificarRolUsuario($usuario, $rol) {
        
        $resultado = false;
        
        $sentencia = $this->mysqli->prepare("SELECT rol FROM usuarios WHERE usuario = ?");
        $sentencia->bind_param("s", $usuario);
        $sentencia->execute();
        $sentencia->bind_result($rolActual);
        $sentencia->fetch();
        $sentencia->close();
    
        
        if ($rol === 'Super-admin' || $rolActual !== 'Super-admin') {
            $sentencia = $this->mysqli->prepare("UPDATE usuarios SET rol = ? WHERE usuario = ?");
            $sentencia->bind_param("ss", $rol, $usuario);
    
            if ($sentencia->execute()) {
                $resultado = $sentencia->affected_rows > 0;
            }
    
            $sentencia->close();
        } else {
            
            $sentencia = $this->mysqli->prepare("SELECT COUNT(*) FROM usuarios WHERE rol = 'Super-admin'");
            $sentencia->execute();
            $sentencia->bind_result($numSuperAdmins);
            $sentencia->fetch();
            $sentencia->close();
    
            if ($numSuperAdmins > 1) {
                $sentencia = $this->mysqli->prepare("UPDATE usuarios SET rol = ? WHERE usuario = ?");
                $sentencia->bind_param("ss", $rol, $usuario);
    
                if ($sentencia->execute()) {
                    $resultado = $sentencia->affected_rows > 0;
                }
    
                $sentencia->close();
            } else {
                $resultado = false;
            }
        }
    
        return $resultado;
    }
    
    public function eliminarRolUsuario($usuario, $rol) {
        
        $resultado = false;
    
        $sentencia = $this->mysqli->prepare("SELECT rol FROM usuarios WHERE usuario = ?");
        $sentencia->bind_param("s", $usuario);
        $sentencia->execute();
        $sentencia->bind_result($rolActual);
        $sentencia->fetch();
        $sentencia->close();

        if ($rol === 'Super-admin') {
            
            $sentencia = $this->mysqli->prepare("SELECT COUNT(*) FROM usuarios WHERE rol = 'Super-admin'");
            $sentencia->execute();
            $sentencia->bind_result($numSuperAdmins);
            $sentencia->fetch();
            $sentencia->close();
    
            if ($numSuperAdmins > 1) {
                $sentencia = $this->mysqli->prepare("UPDATE usuarios SET rol = '' WHERE usuario = ? AND rol = ?");
                $sentencia->bind_param("ss", $usuario, $rol);
    
                if ($sentencia->execute()) {
                    $resultado = $sentencia->affected_rows > 0;
                }
    
                $sentencia->close();
            } else {
                $resultado = false;
            }
        } else {
            
            $sentencia = $this->mysqli->prepare("UPDATE usuarios SET rol = '' WHERE usuario = ? AND rol = ?");
            $sentencia->bind_param("ss", $usuario, $rol);
    
            if ($sentencia->execute()) {
                $resultado = $sentencia->affected_rows > 0;
            }
    
            $sentencia->close();
        }
    
        return $resultado;
    }
    
}

?>