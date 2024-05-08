<?php
// Obtengo el valor de la variable de entorno 'SERVER_SOFTWARE' si está definida, de lo contrario, asigna 'Unknown'.
$serverSoftware = isset($_ENV['SERVER_SOFTWARE']) ? $_ENV['SERVER_SOFTWARE'] : 'Desconocido';

// Imprimo un encabezado HTML con mi nombre y el nombre de la asignatura.
echo "<h1>SWAP - dmartinez01</h1> <br>";

// Imprimo el nombre del servidor web obtenido de la variable de entorno 'SERVER_SOFTWARE'.
echo "Servidor Web: " . $serverSoftware . "<br>";

// Imprimo la dirección IP del servidor obtenida de la variable superglobal $_SERVER.
echo "Dirección IP del Servidor: " . $_SERVER['SERVER_ADDR'];
?>