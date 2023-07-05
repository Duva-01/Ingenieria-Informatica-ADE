#include <stdlib.h>	// biblioteca con funciones atoi(), malloc() y free()
#include <stdio.h>	// biblioteca donde se encuentra la funciÃ³n printf()
#include <time.h>	// biblioteca donde se encuentra la funciÃ³n clock_gettime() 


//#define VECTOR_LOCAL	// descomentar para que los vectores sean variables ...		
//#define VECTOR_GLOBAL // descomentar para que los vectores sean variables ...			
#define VECTOR_DYNAMIC	// descomentar para que los vectores sean variables ...
			

#ifdef VECTOR_GLOBAL
#define MAX 33554432	//=2^25
//#define MAX 4294967295  //=2^32 -1
   
double m1[MAX], m2[MAX], m3[MAX]; 
#endif

int main(int argc, char** argv){ 
  
  int i, j, k, suma; 

  struct timespec cgt1,cgt2; double ncgt; //para tiempo de ejecuciÃ³n

  //Leer argumento de entrada (nÂº de componentes del vector)
  if (argc<2){	
    printf("Faltan nÂº componentes del vector\n");
    exit(-1);
  }
  
  unsigned int N = atoi(argv[1]);	
  #ifdef VECTOR_LOCAL
  double m1[N], m2[N], m3[N];   // TamaÃ±o variable local en tiempo de ejecuciÃ³n ...
				// disponible en C a partir de C99 
  #endif

  #ifdef VECTOR_GLOBAL
  if (N>MAX) N=MAX;
  #endif

// Definir las matrices
  #ifdef VECTOR_DYNAMIC

  int **m1, **m2, **m3;
  m1 = (int**) malloc(N*sizeof(int*));
  m2 = (int**) malloc(N*sizeof(int*));
  m3 = (int**) malloc(N*sizeof(int*));

  for(i=0; i<N; i++){
      m1[i] = (int *) malloc(N*sizeof(int));
      m2[i] = (int *) malloc(N*sizeof(int));
      m3[i] = (int *) malloc(N*sizeof(int));
  }
        

    if ( m1==NULL || m2==NULL || m3==NULL ){
        printf("Error en la reserva de espacio para la matriz");
        exit(-2);

    }
  #endif
 
  //Inicializar matrices 
  if (N>8){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                m1[i][j] = drand48();
                m2[i][j] = drand48();
                m3[i][j] = 0;
            }
        }
  }

  else {
      for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                m1[i][j] = N+i+2;
                m2[i][j] = N+i+4;
                m3[i][j] = 0;
            }
        }
  }
  
clock_gettime(CLOCK_REALTIME,&cgt1);

// Calcular multiplicacion de matrices 

int r = N/4;

for (i = 0; i < N; i++){
    for (j = 0; j < N; j+=4){
        for (k = 0; k < N; ++k){

            m3[i][j] += m1[i][k] * m2[k][j];
            m3[i][j+1] += m1[i][k] * m2[k][j];
            m3[i][j+2] += m1[i][k] * m2[k][j];
            m3[i][j+3] += m1[i][k] * m2[k][j];
        }
    }
}

for (i = 0; i < N; i++)
    for (j = N-r; j < N; j++)
        for (k = 0; k < N; ++k)
            m3[i][j] += m1[i][k] * m2[k][j];


for (i = 0; i < N; i++)
    for (j = N-r; j < N; j++)
        suma += m3[i][j];

clock_gettime(CLOCK_REALTIME,&cgt2);
ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
       (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  //Imprimir resultado de la multiplicacion y el tiempo de ejecucion
  
  printf("Tiempo:%11.9f\t / Tamanio Matriz:%u / Resultado Matriz:%u \n",ncgt,N, suma); 
 

  #ifdef VECTOR_DYNAMIC

    for(i=0; i<N; i++){
        free(m1[i]);
        free(m2[i]);
        free(m3[i]);
    }

    free(m1); // libera el espacio reservado para v1
    free(m2); // libera el espacio reservado para v2
    free(m3); // libera el espacio reservado para v3
 
  #endif
  return 0; 
}