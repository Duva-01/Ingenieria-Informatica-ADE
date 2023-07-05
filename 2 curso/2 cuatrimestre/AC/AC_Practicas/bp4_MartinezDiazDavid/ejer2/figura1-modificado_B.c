#include <stdlib.h>	
#include <stdio.h>	
#include <time.h>	

int main(int argc, char** argv){ 
  
  int i, j, k, suma; 
  struct timespec cgt1,cgt2; double ncgt; 

  if (argc<3){	
    printf("Faltan n componentes del vector\n");
    exit(-1);
  }
  
  unsigned int N = atoi(argv[1]);	
  unsigned int M = atoi(argv[2]);	

  struct {
    int a[N];
    int b[N];
  }s;
    int *R;
    int X1, X2;
    R = (int*) malloc(N*sizeof(int));
 
  //Inicializar vectores 
  if (N > 8){

    srand(time(0));
    for (i = 0; i < N; i++){

        s.a[i] = rand();
        s.b[i] = rand();
        R[i] = 0;
    }
  }

  else{
    
    for (i = 0; i < N; i++){

        s.a[i] =  N+i+2;
        s.b[i] = N+i+4;
        R[i] = 0;
    }
  }
 
  clock_gettime(CLOCK_REALTIME,&cgt1);

  for (i=0; i<M; i++) {

        X1=0; X2=0;
        for(j=0; j<N; j++)  
            X1+=2*s.a[j]+i;

        for(k=0; k<N; k++)  
            X2+=3*s.b[k]-i;
 
        if (X1<X2){
            R[i]=X1;
        } 
            
        else{
            R[i]=X2;
        }  
   }

  clock_gettime(CLOCK_REALTIME,&cgt2);

  //Calcular suma de vectores 
  for(i=0; i<N; i++) 
    suma += R[i];
  
  ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
       (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  //Imprimir resultado de la suma y el tiempo de ejecucion
  printf("Tiempo:%11.9f\t / Tamanio vector:%u / Resultado Vector:%u \n",ncgt,N, suma); 
 
  return 0; 
}