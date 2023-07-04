/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Si MAX_PRIMO es el mayor número que se va a considerar (establezca su 
	valor a 5000, p.e.) escribir un programa que lea un valor n 
	(1 = n =MAX_PRIMO) y calcule y muestre todos los primos menores o 
	iguales que n.

		
		Entrada: - Numero tope de primos.
								 
		Salida:  - Numero de primos desde 0 hasta ese intervalo.
				 		
	
*/
/***************************************************************************/

#include <iostream>

using namespace std;

int main () {
	
	// Variables
	
	int const MAX_DATOS = 5000;
	int limite;
	int n = 0, j = 0;
	
	
	// Entradas de Datos
	
	cout << endl
		 << "- Introduzca hasta que numero desea encontrar sus primos: ";
	cin >> limite;
	cout << endl << endl;
	
	
/***************************************************************************/
	
	// Calculo de primos
	
	bool es_primo[limite];
	
	for (int i=0; i <= limite; i++)
		es_primo[i] = true;
	
	
	for (int n=2; n*n <= limite; n++) { 
         
		if (es_primo[n]) {

			for (int aux = 2; aux*n <= limite; aux ++) { 
				es_primo[aux*n] = false;  
			}
		}
	}
	
	
/***************************************************************************/
	
	// Introduccion de primos en lista
	
int numeros_p = 0;
int primos[MAX_DATOS];	 
	 
	for (int j = 1; j <= limite; j++) {

		if (es_primo[j]) {

			if (numeros_p < MAX_DATOS ) {
			
				primos[numeros_p] = j;  
				numeros_p ++;
			}
		}
	}
	
/***************************************************************************/	
	
	// Salida de Datos
	
	do {
		
		cout << endl;
		cout << "--> Su numero primo es  " << primos[j];
		cout << endl;
		
		j++;
		
	}while (j != numeros_p);
	
	
	return 0;
}
