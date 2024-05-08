#!/bin/bash

# Función para levantar y construir contenedores
configurar_contenedores() {
    # Construye y levanta los contenedores utilizando docker-compose
    echo "Construyendo y levantando contenedores..."
    docker-compose up --build -d
    echo "Contenedores levantados y configuración de red realizada."
}

# Función para limpiar logs antiguos
limpiar_logs() {
    # Limpia los logs dentro de los contenedores que tienen más de 7 días de antigüedad
    echo "Iniciando limpieza de logs dentro de los contenedores..."
    for contenedor in $(docker ps --format "{{.Names}}"); do
        # Comprueba si el contenedor tiene bash antes de intentar ejecutar el comando
        if docker exec $contenedor which bash > /dev/null; then
            docker exec $contenedor bash -c 'find /var/log -type f -name "*.log" -mtime +7 -exec rm -f {} \;'
        else
            echo "El contenedor $contenedor no tiene bash, saltando limpieza de logs."
        fi
    done
    echo "Limpieza de logs completada."
}

# Función para chequear la salud de los contenedores
verificar_salud() {
    # Verifica si los contenedores están en ejecución
    echo "Iniciando chequeo de salud de los contenedores..."
    # Lista de contenedores a verificar
    contenedores=("practica1-web1-1" "practica1-web2-1" "practica1-web3-1" "practica1-web4-1" "practica1-web5-1" "practica1-web6-1" "practica1-web7-1" "practica1-web8-1")

    for contenedor in "${contenedores[@]}"; do
      # Verifica el estado de cada contenedor
      if [ "$(docker inspect --format='{{.State.Running}}' $contenedor)" != "true" ]; then
        echo "Alerta: El contenedor $contenedor no está corriendo."
      fi
    done
    echo "Chequeo de salud completado."
}

# Función para actualizar paquetes dentro de los contenedores
actualizar_paquetes() {
    # Actualiza los paquetes dentro de los contenedores
    echo "Iniciando actualización de paquetes dentro de los contenedores..."
    # Para contenedores basados en Debian/Ubuntu
    for contenedor in $(docker ps --format "{{.Names}}"); do
        # Comprueba si el contenedor tiene apt-get antes de intentar ejecutar el comando
        if docker exec $contenedor which apt-get > /dev/null; then
            docker exec $contenedor bash -c 'apt-get update && apt-get upgrade -y'
        else
            echo "El contenedor $contenedor no soporta apt-get, saltando actualización de paquetes."
        fi
    done
    echo "Actualización de paquetes completada."
}

# Ejecutar las funciones
configurar_contenedores
limpiar_logs
verificar_salud
#actualizar_paquetes
