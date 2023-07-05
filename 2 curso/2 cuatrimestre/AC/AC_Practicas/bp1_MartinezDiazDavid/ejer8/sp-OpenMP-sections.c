// Ejercicio 8 - Seminario 1

#include <stdlib.h>	// biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h>	// biblioteca donde se encuentra la función printf()
#include <omp.h> // biblioteca de openMP

int main(int argc, char** argv){
  int i, j, k, l;
  double *v1, *v2, *v3;

  // comprobación de los argumentos dados
  if (argc<2){
    printf("Faltan nº componentes del vector\n");
    exit(-1);
  }

  // máximo N =2^32-1=4294967295 (sizeof(unsignedint) = 4 B)
  unsigned int N = atoi(argv[1]);

  v1 = (double*) malloc(N*sizeof(double));
  v2 = (double*) malloc(N*sizeof(double));
  v3 = (double*) malloc(N*sizeof(double));

  // si no hay suficiente espacio
  if ((v1 == NULL) || (v2 == NULL) || (v2 == NULL)) {
    printf("No hay suficiente espacio para los vectores \n");
    exit(-2);
  }

  // inicializamos los vectores
  double tiempo_inicial, tiempo_final, tiempo_total;
  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
      for(i=0; i<N/4; i++){
        v1[i] = N*0.1+i*0.1;
        v2[i] = N*0.1-i*0.1;
      }

      #pragma omp section
      for(j=N/4; j<N/2; j++){
        v1[j] = N*0.1+j*0.1;
        v2[j] = N*0.1-j*0.1;
      }

      #pragma omp section
      for(k=N/2; k<3*N/4; k++){
        v1[k] = N*0.1+k*0.1;
        v2[k] = N*0.1-k*0.1;
      }

      #pragma omp section
      for(l=3*N/4; l<N; l++){
        v1[l] = N*0.1+l*0.1;
        v2[l] = N*0.1-l*0.1;
      }
    }

    #pragma omp single
      tiempo_inicial = omp_get_wtime();

    #pragma omp sections
    {
      #pragma omp section
      for(i=0; i<N/4; i++)
        v3[i] = v1[i] + v2[i];

      #pragma omp section
      for(j=N/4; j<N/2; j++)
        v3[j] = v1[j] + v2[j];

      #pragma omp section
      for(k=N/2; k<3*N/4; k++)
        v3[k] = v1[k] + v2[k];

      #pragma omp section
      for(l=3*N/4; l<N; l++)
        v3[l] = v1[l] + v2[l];
    }

    #pragma omp single
      tiempo_final = omp_get_wtime();
  }

  tiempo_total = tiempo_final - tiempo_inicial;

  //Imprimir resultado de la suma y el tiempo de ejecución
  if (N<10) {
  printf("Tiempo:%11.9f\t / Tamaño Vectores:%u\n",tiempo_total,N);
  for(i=0; i<N; i++)
    printf("/ V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n",
           i,i,i,v1[i],v2[i],v3[i]);
  }
  else
    printf("Tiempo:%11.9f\t / Tamaño Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / / V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n",
           tiempo_total,N,v1[0],v2[0],v3[0],N-1,N-1,N-1,v1[N-1],v2[N-1],v3[N-1]);

  free(v1); // libera el espacio reservado para v1
  free(v2); // libera el espacio reservado para v2
  free(v3); // libera el espacio reservado para v3


  return 0;
}
