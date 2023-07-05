#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define TAM_MAX 134217728

double x[TAM_MAX];
double y[TAM_MAX];
double a=12345.6789;

int main(int argc, char ** argv){
    
    if((argc != 2) && (argc != 1)){
        printf("NUMERO DE PARAMETROS INTRODUCIDOS INCORRECTO\n");
        exit(EXIT_FAILURE);
    }

    int tam;
    if(argc == 2){
      tam = atoi(argv[1]);

      if(tam > TAM_MAX)
        tam = TAM_MAX;
    }
    if(argc == 1){
      tam = TAM_MAX;
    }

    for(int i=0; i<tam; i++){
        y[i] = a-i*0.1234;
        x[i] = a+i*0.1234;
    }

    struct timespec cgt1,cgt2;
    double ncgt;

    clock_gettime(CLOCK_REALTIME,&cgt1);
    for(int i=0; i<tam; i++){
        y[i] = a*x[i] + y[i];s
    }
    clock_gettime(CLOCK_REALTIME,&cgt2);

    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
    
    printf("\n>> TIEMPO DE EJECUCION: %11.9f | DIMENSION: %d\n", ncgt, tam);

    return EXIT_SUCCESS;
}
