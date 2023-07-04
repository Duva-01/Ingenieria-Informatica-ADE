// David Martinez Diaz

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <ftw.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char** argv){

    DIR *directorio;
    DIR *directorio_destino;

    char *nombre;
    struct dirent *archivo;

    struct stat *atributos;
    char ruta[1024];

    int entrada;
    char sentencia[1024], frase_enlace[1024];

    int contador_max = 0;

    if (argc != 3){
        
        printf("Mal escritos los paramentros: <ejecutable> <directorio> <directorio> \n");
        exit(-1);
    }

    else {

        nombre = argv[1];
        directorio = opendir(nombre);

        if(directorio == NULL){

            printf("No se ha podido abrir el directorio %s", nombre);
            exit(-2);
        }

        directorio_destino =opendir(argv[2]);

        if(directorio_destino == NULL){
            mkdir(argv[2], 0666);
        }
        
        entrada = open("copiados.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
    }

    while((archivo = readdir(directorio)) != NULL){

        if(strcmp(archivo->d_name, ".") != 0 && strcmp(archivo->d_name, "..") != 0){

            sprintf(ruta, "%s/%s", nombre, archivo->d_name);

            if(stat(ruta, atributos) < 0){
                printf("No se ha podido conseguir los stats del archivo\n");
                exit(-1);
            }

            else {

                if(S_ISREG(atributos->st_mode) && (atributos->st_ino) % 2 == 0){
                    
                    execlp("cp", archivo->d_name, directorio_destino, NULL);

                    sprintf(sentencia, "%s|%d|%s", archivo->d_name, atributos->st_nlink, atributos->st_atim);
                    write(entrada, sentencia, sizeof(sentencia));

                    if (contador_max < atributos->st_nlink){

                        contador_max = atributos->st_nlink;
                    }


                }
            }

        }

    }

    sprintf(frase_enlace, "Max enlaces duros: %d\n", contador_max);


    return 0;
}