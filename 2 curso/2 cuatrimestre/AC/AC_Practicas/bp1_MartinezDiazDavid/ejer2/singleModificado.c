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
			printf("Single(introducir valor) ejecutada por el thread %d\n", omp_get_thread_num());
		}

		#pragma omp for
		for(i = 0; i < n; i++)
			b[i] = a;

		#pragma omp single
		{
			printf("\n Impresion ejecutada por el thread %d\n", omp_get_thread_num());
			for(i = 0; i < n; i++) printf("b[%d] = %d [hebra %d]\n", i, b[i], omp_get_thread_num());	
		}

	}

	return 0;
}
