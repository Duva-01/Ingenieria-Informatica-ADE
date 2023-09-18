<?php

$request = $_SERVER['REQUEST_URI'];

switch ($request) {
    case '/':
        require __DIR__ . '/index.php';
        break;

    case '':
        require __DIR__ . '/index.php';
        break;

        case (preg_match('/^\/cientifico\/(\d+)(\/imprimir|\/modificarCientifico|\/modificarComentario\/(\d+))?$/', $request) ? true : false):
            $params = explode('/', trim($request, '/'));
            $_GET['scid'] = $params[1];
            if (isset($params[2])) {
                switch ($params[2]) {
                    case 'imprimir':
                        $_GET['imprimir'] = 'true';
                        break;
                    case 'modificarCientifico':
                        $_GET['modificarCientifico'] = 'true';
                        break;
                    case 'modificarComentario':
                        $_GET['modificarComentario'] = 'true';
                        $_GET['cid'] = $params[3];
                        break;
                }
            }
            require __DIR__ . '/cientifico.php';
            break;
    default:
        http_response_code(404);
        echo "404 Not Found";
        break;
}
?>
