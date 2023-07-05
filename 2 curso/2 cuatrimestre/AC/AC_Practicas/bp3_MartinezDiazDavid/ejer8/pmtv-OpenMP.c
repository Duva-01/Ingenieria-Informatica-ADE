#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv){

    struct timespec cgt1, cgt2;
    double ncgt, t_ini, t_final, t_total;

    if(argc<2){
        printf("Faltan no componentes del vector\n");
        exit(-1);
    }

    unsigned int N = atoi(argv[1]);
    int i, j, suma;
    int *v, *mv, **m;

    v = (int*) malloc(N*sizeof(int));
    mv = (int*) malloc(N*sizeof(int));
    m = (int*) malloc(N*sizeof(int *));

    for(i=0; i<N; i++)
        m[i] = (int *) malloc(N*sizeof(int));

    if ( v==NULL || mv==NULL || m==NULL ){
        printf("Error en la reserva de espacio para la matriz y el vector");
        exit(-2);

    }

    for(i=0; i<N; i++)
        if(m[i] == NULL){
            printf("Error en la reserva de espacio para la matriz y el vector");
            exit(-3);
        }

    #pragma omp parallel for firstprivate(j) schedule(runtime)
    for(i=0; i<N; i++){

        for(j=i; j<N; j++){
            m[i][j] = 9;
        }

        v[i] = 2;
        mv[i] = 0;
    }

    clock_gettime(CLOCK_REALTIME,&cgt1);

    #pragma omp parallel
    {
      #pragma omp single
        t_ini = omp_get_wtime();

      #pragma omp for schedule(runtime)
      for(int i = 0; i<N ; i++)
        for(int j = 0; j<N; j++)
            mv[i] += m[i][j] * v[i];

      #pragma omp single
        t_final = omp_get_wtime();
    }

    
    t_total= t_final - t_ini;

    clock_gettime(CLOCK_REALTIME,&cgt2);

    printf("Matriz: \n");
    for(i=0; i<N; i++){

        for(j=0; j<N; j++)
            if(j >= i)
                printf("%d ", m[i][j]);
            else 
                printf("0 ");
        printf("\n");
    }

    printf("Vector: \n");
    for(i=0; i<N; i++)
        printf("%d ", v[i]);
    printf("\n");

    printf("Resultado: \n");
    for(i=0; i<N; i++)
        printf("%d ", mv[i]);
    printf("\n");

    ncgt=(double)(cgt2.tv_sec-cgt1.tv_sec)+(double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

    printf("Tamaño de la matriz y vector: %d \t / Tiempo(seg.) %11.9f \n", N, ncgt);

    for(i=0; i<N; i++)
        free(m[i]);
    
    free(m);
    free(v);
    free(mv);

    return 0;

}