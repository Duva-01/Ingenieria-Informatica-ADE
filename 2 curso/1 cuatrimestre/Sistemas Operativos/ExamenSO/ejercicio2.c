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

void mi_handler (int SIGNAL){
    pid_t child;
    int situacion;
    child = wait(&situacion);
    printf("Mi hijo a terminado con PID: %d\n", child);
}
  
int main(int argc, char** argv){

    signal(SIGCHLD, mi_handler);
    pid_t hijo1, hijo2;

    int num_read;
    char flujo[108];

    int num_1;

    int fd[2];
    pipe(fd);

    int entrada;


    if(hijo1 = fork() < 0){
        
        perror("No se ha realizado el hijo1 correctamente\n");
        exit(-1);
    }

    if(hijo1 != 0){

        if(hijo2 = fork() < 0){
        
            perror("No se ha realizado el hijo2 correctamente\n");
            exit(-1);
        }

    }
    
    while(1){

        if (hijo1 != 0 && hijo2 != 0){

            
            num_read = read(STDIN_FILENO, flujo, sizeof(flujo));

            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);

            write(fd[1], flujo, sizeof(flujo));

        }
        if (hijo1 == 0){

            int primos, sig_primo;
            close(fd[1]);
            dup2(fd[0],STDIN_FILENO);

            if(read(fd[0],  num_1, sizeof(num_1)) < 0){
                printf("Mal leido\n");
                exit(-1);
            }

            for(int i=1; i<=num_1; i++){

                if(num_1%i == 0){
                    
                    primos++;
                    sig_primo = i;
                }
                    
            }

            if(primos == 2)
                printf("Soy el hijo 2 y el número %d recibido es primo", num_1);

            else{

                printf("No es primo y el siguiente número primo es %d", sig_primo); 
            }
            
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);

            write(fd[1], num_1, sizeof(num_1));

            exit (EXIT_SUCCESS);
        }

        if (hijo2 == 0){

            int num_out;
            if(entrada = open("resultados.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR) < 0){

                printf("Error al abrir el archivo\n");
                exit(-1);
            }

            close(fd[1]);
            dup2(fd[0],STDIN_FILENO);
            
            if(read(fd[0],  num_out, sizeof(num_out)) < 0){
                
                printf("Mal leido\n");
                exit(-1);
            }

            write(entrada, num_out, sizeof(num_out));

            if(fchmod(entrada, 0644)<0){
                printf("Error a la hora de darle permisos\n");
            }

            exit (EXIT_SUCCESS);

        }

        if(strcmp(flujo, "fin") == 0){
            return 0;
        }

        printf("Me ha llegado un dato\n");
    }
    

    return 0;
}