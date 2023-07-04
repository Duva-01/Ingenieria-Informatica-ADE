/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Diseñar un programa que lea un carácter (supondremos que el usuario 
	introduce una mayúscula), lo pase a minúscula y lo imprima en pantalla.

		
		Entrada: - Un caracter (mayuscula).
				
						 
		Salida:  - Un caracter (minuscula).
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;

int main () {					// Programa Principal
	
	// Variables
		
	char letra_mayus, letra_minus;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca una letra en mayusculas: "; cin >> letra_mayus;
	cout << endl;
	
	if (letra_mayus >= 65 && letra_mayus<= 90) {
		
	// Cálculos
	
	letra_minus = letra_mayus + 32;
	
	// Salida de datos
	
	cout << "--> La letra en minuscula seria: " << letra_minus;
	cout << endl << endl;
	
	}
	
	else {
		
		cout << "Error" ;
		
	}
	
	
	return 0;
	
	
}
