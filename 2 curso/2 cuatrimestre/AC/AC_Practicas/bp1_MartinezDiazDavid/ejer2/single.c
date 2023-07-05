#include <stdio.h>
#include <omp.h>

int main(){
    
	int n = 9, i, a, b[n];

	for(i = 0; i < n; i++) b[i] = -1;
	
	#pragma omp parallel
	{
		#pragma omp single
		{
			printf("Introduce valor de inicializacion a: ");
			scanf("%d", &a);
			printf("Single ejecutada por el thread %d\n", omp_get_thread_num());
		}

		#pragma omp for
		for(i = 0; i < n; i++)
			b[i] = a;
	}

	printf("Despues de la región parallel:\n");
	for(i = 0; i < n; i++) printf("b[%d] = %d\n", i, b[i]);

	return 0;
}
