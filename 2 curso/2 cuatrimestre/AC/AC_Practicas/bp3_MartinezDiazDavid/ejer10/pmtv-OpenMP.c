
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _OPENMP
  #include <omp.h>
#else
  #define omp_get_num_threads() 0
#endif

#define VAR_DYNAMIC 


int main(int argc, char ** argv){
    
    if(argc < 2){
        printf("ERROR [O] AT %s. NUMERO DE ARGUMENTOS INSUFICIENTE.\n",argv[0]);
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
       
        for(int j=0; j<tam; j++){
          m[i][j] = 9;
        }
        v[i] = 2;
        mv[i] = 0;
    }

    
    omp_sched_t kind; int chunk_value;

 
    double ncgt, t_inicial, t_final;
    double suma;

    #pragma omp parallel
    {
      #pragma omp single
        t_inicial = omp_get_wtime();

      #pragma omp for firstprivate(suma) schedule(runtime)
      for(int i = 0; i<tam ; i++){
          #ifdef SEE_CHUNK_DEFAULT
            if(i==0){
                omp_get_schedule(&kind,&chunk_value);
                printf("KIND: %d | CHUNK: %d \n",kind,chunk_value);
            }
          #endif

          suma = 0;
          for(int j=i; j<tam; j++){
              suma += m[i][j] * v[j];
          }
          mv[i] = suma;
      }

      #pragma omp single
        t_final = omp_get_wtime();
    }



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

 
    ncgt=t_final - t_inicial;
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
