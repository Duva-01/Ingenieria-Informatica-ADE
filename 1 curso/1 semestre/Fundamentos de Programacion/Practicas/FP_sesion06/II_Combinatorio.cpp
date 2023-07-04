/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Calcular mediante un programa en C++ el combinatorio n,m 
	con n, m valores enteros.
		
		Entrada: - n
				 - m
				
						 
		Salida:  - Combinatorio.
				 		
	
*/
/***************************************************************************/


#include <iostream>

using namespace std;

int main() {
	
	int n, m, combinatorio, n_m; 
	int factorial_n = 1, factorial_m = 1, factorial_n_m = 1;
	
	cout << endl;
	cout << "- Introduzca el valor de n: "; cin >> n;
	cout << endl;
	cout << "- Introduzca el valor de m: "; cin >> m;
	cout << endl;
	
	if (n > m) { n_m = n - m;}
	
	if (n < m) {n_m = m - n;}
	
	
	do {
		
		factorial_n = factorial_n * n;
		n = n - 1;
		
	}while (n != 0);
	
	
	do {
		
		factorial_m = factorial_m * m;
		m = m - 1;
		
	}while (m != 0);
	
	
	do {
		
		factorial_n_m = factorial_n_m * n_m;
		n_m = n_m - 1;
		
	}while (n_m != 0);
	
	
	combinatorio = (factorial_n)/((factorial_m)*(factorial_n_m));
	
	cout << endl;
	cout << "Su combinatorio tiene un valor de: " << factorial_n_m;
	cout << endl;
	
	return 0;
	
}
