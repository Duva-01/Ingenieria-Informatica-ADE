#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
    #include <omp.h>
#else
    #define omp_get_thread_num() 0
#endif

int main(int argc, char **argv) {

    int i, n = 200, chunk, modif, a[n],suma=0;
    omp_sched_t tipo;

    if(argc < 3) {

        fprintf(stderr,"\nFalta chunk \n");
        exit(-1);
    }
    
    chunk = atoi(argv[2]);
    n = atoi(argv[1]);

    if(n>200)
        n=200;

    int dyn_var = omp_get_dynamic();
    int nthreads_var = omp_get_max_threads();
    int thread_limit_var = omp_get_thread_limit();
    omp_get_schedule(&tipo, &modif);

    for (i=0; i<n; i++) 
        a[i] = i;

    #pragma omp parallel for firstprivate(suma) \
    lastprivate(suma) schedule(dynamic,chunk)
    
    for (i=0; i<n; i++){ 

        suma = suma + a[i];
        printf(" thread %d suma a[%d] suma=%d \n", omp_get_thread_num(),i,suma);
    }

    #pragma omp single
        printf("\n thread %d dyn-var %d \n", omp_get_thread_num(), dyn_var);
        printf("\n thread %d nthreads-var %d \n", omp_get_thread_num(), nthreads_var);
        printf("\n thread %d thread-limit-var %d \n", omp_get_thread_num(), thread_limit_var);
        printf("\n thread %d run-sched-var %d \n", omp_get_thread_num(), modif);

    printf("Fuera de 'parallel for' suma=%d\n dyn-var %d\n nthreads-var %d\n thread-limit-var %d\n run-sched-var mod %d\n",suma, dyn_var, nthreads_var, thread_limit_var, modif);
}