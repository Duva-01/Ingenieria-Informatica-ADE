/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa que lea un entero representando la clave y un carácter 
	El programa codificará el carácter según la clave introducida y lo mostrará 
	por pantalla.

		
		Entrada: - Clave.
				 - Caracter.
				
						 
		Salida:  - Un caracter (codificado).
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;

int main () {					// Programa Principal
	
	
	// Variables
	
	int clave, total;
	char letra_1;
	const char MIN = 'A';
	const char MAX = 'Z';
	
	// Entrada de datos
	
	cout << "Introduzca el valor de la clave: "; cin >> clave;
	cout << "Introduzca la letra para codificar: "; cin >> letra_1;
	
	// Cálculos
	
	letra_1 = letra_1 + clave;

	if (letra_1 > MAX) {
		
		letra_1 = letra_1 - (MAX - MIN + 1);
		
	}
		
		
	// Salida de datos 
	
	cout << "Su letra codificada es: " << letra_1;
	cout << endl << endl;


 return 0;
}	
	
