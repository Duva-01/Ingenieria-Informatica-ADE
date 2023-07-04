/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Calcular mediante un programa la función factorial. Se dice que n! es el 
	factorial de un entero n y se define de la forma siguiente:
		
		Entrada: - Numero
				
						 
		Salida:  - Factorial.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los elementos de E/S.


using namespace std;

int main() {					// Funcion Principal
	
	// Variables
	
	int n, factorial = 1;
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca el numero a factorizar: "; cin >> n;
	cout << endl;
	
	// Logica y Calculos
	
	if (n != 0) {
	
	do {
		
		factorial = factorial * n;
		n --;
		
	}while (n != 0);
	
	}
	
	else if (n == 0) { factorial = 1;}
	// Salida de Datos 
	
	cout << "--> Su numero factorizado vale: " << factorial;
	cout << endl << endl;
	
	return 0;
}
