#!/bin/bash

# Defino los nombres de mis contenedores Apache, Nginx y Lighttpd
apache_containers=("practica1-web1-1" "practica1-web2-1" "practica1-web3-1" "practica1-web4-1" "practica1-web5-1" "practica1-web6-1")
nginx_containers=("practica1-web7-1")
lighttpd_containers=("practica1-web8-1")

# Función para monitorear el uso de recursos usando el comando top
monitorear_uso_recursos() {
  # Itero sobre los contenedores Apache
  for contenedor in "${apache_containers[@]}"; do
    echo "Monitoreando uso de recursos en $contenedor"
    # Ejecuto el comando top dentro del contenedor Apache actual
    docker exec -it $contenedor top -b -n 1
  done
}

# Función para verificar los puertos abiertos usando el comando netstat
chequear_puertos() {
  # Itero sobre los contenedores Apache
  for contenedor in "${apache_containers[@]}"; do
    echo "Puertos abiertos en $contenedor"
    # Ejecuto el comando netstat dentro del contenedor Apache actual
    docker exec -it $contenedor netstat -tuln
  done
}

# Función para verificar la configuración de Apache usando el comando apache2ctl
verificar_configuracion_apache() {
  # Itero sobre los contenedores Apache
  for contenedor in "${apache_containers[@]}"; do
    echo "Verificando configuración de Apache en $contenedor"
    # Ejecuto el comando apache2ctl dentro del contenedor Apache actual para mostrar la configuración
    docker exec -it $contenedor apache2ctl -S
  done
}

# Función para mostrar los últimos logs de acceso y error de Nginx y Lighttpd
mostrar_logs() {

  # Itero sobre los contenedores Apache
  for contenedor in "${apache_containers[@]}"; do
    echo "Guardando últimos logs de Apache del contenedor $contenedor"
    # Guardo los últimos 100 registros de los logs de Apache en un archivo
    docker logs $contenedor 2>&1 | tail -n 100 > "./logs/${contenedor}_combined.log"
  done

  # Itero sobre los contenedores Nginx
  for contenedor in "${nginx_containers[@]}"; do
    echo "Guardando últimos logs de Nginx del contenedor $contenedor"
    # Guardo los últimos 100 registros de los logs de Nginx en un archivo
    docker logs $contenedor 2>&1 | tail -n 100 > "./logs/${contenedor}_combined.log"
  done

  # Itero sobre los contenedores Lighttpd
  for contenedor in "${lighttpd_containers[@]}"; do
    echo "Guardando últimos logs de Lighttpd del contenedor $contenedor"
    # Guardo los últimos 100 registros de los logs de Lighttpd en un archivo
    docker logs $contenedor 2>&1 | tail -n 100 > "./logs/${contenedor}_combined.log"
  done
}

# Ejecutar las funciones definidas anteriormente
monitorear_uso_recursos
chequear_puertos
verificar_configuracion_apache
mostrar_logs
