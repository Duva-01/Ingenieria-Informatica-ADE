
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VAR_DYNAMIC 


int main(int argc, char ** argv){

    struct timespec cgt1,cgt2;
    double ncgt;

    if(argc < 2){
        printf("ERROR num argumentos.\n",argv[0]);
        printf("USO: %s [TAM]", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned int tam = atoi(argv[1]); 
    printf("DIMENSION DE VECTOR Y MATRIZ: %u (%lu B)\n",tam,sizeof(unsigned int));

    
    #ifdef VAR_DYNAMIC
      
      double ** m;
      double * v;
      double * mv;


      v = (double *) malloc(tam * sizeof(double)); 
      mv = (double *) malloc(tam * sizeof(double)); 
      m = (double **) malloc(tam * sizeof(double *)); 

      
      if(v == NULL || mv == NULL || m == NULL){
          printf("ERROR [1] AL RESERVAR MEMORIA PARA MATRIZ Y/O VECTOR.\n");
          exit(EXIT_FAILURE);
      }

      
      for(int i=0; i<tam;i++){
        m[i] = (double *) malloc(tam * sizeof(double));
        
        if(m[i] == NULL){
            printf("ERROR [2] AL RESERVAR MEMORIA PARA MATRIZ.\n");
            exit(EXIT_FAILURE);
        }
      }
    #endif

    for(int i=0; i<tam; i++){
        v[i] = tam*0.1+i*0.1;
        mv[i] = 0;
        for(int j=0; j<tam; j++){
          if(i<j)
            m[i][j] = 0;
          else
            m[i][j] = tam*0.1+i*0.1-j*0.1;
        }
    }

    double suma;
    clock_gettime(CLOCK_REALTIME,&cgt1);
    for(int i = 0; i<tam ; i++){
        suma = 0;
        for(int j=0; j<i; j++){
            suma += m[i][j] * v[j];
        }
        mv[i] = suma;
    }
    clock_gettime(CLOCK_REALTIME,&cgt2);

    if(tam < 10){
        
        printf("MATRIZ M: \n");
        for(int i=0; i<tam; i++){
            for(int j=0; j<tam; j++){
                printf("%11.9f \t", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        printf("VECTOR V: [");
        for(int i=0; i<tam; i++){
            printf("%11.9f \t", v[i]);
        }
        printf("]\n");

        
        printf("RESULTADO DE MULTIPLICACION: [");
        for(int i=0; i<tam; i++){
            printf("%11.9f \t", mv[i]);
        }
        printf("]\n");
    }
    else{
        
        printf("MATRIZ CREADA: m[0][0]=%11.9f || m[%d][%d]=%11.9f \n", m[0][0],tam-1,tam-1,m[tam-1][tam-1]);
        printf("VECTOR CREADO: v[0]=%11.9f || v[%d]=%11.9f \n", v[0],tam-1,v[tam-1]);
        printf("RESULTADO DE MULTIPLICACION: mv[0]=%11.9f || mv[%d]=%11.9f \n", mv[0], tam-1, mv[tam-1]);
    }

    
    ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));
    printf("TIEMPO DE EJECUCION: %11.9f || DIMENSION: %d \n",ncgt,tam);

    #ifdef VAR_DYNAMIC
      free(v);
      free(mv);
      for(int i=0; i<tam; i++)
        free(m[i]);
      free(m);
    #endif

    return EXIT_SUCCESS;
}
