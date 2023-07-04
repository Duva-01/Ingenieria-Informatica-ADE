/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa que lea un entero representando la clave y un car�cter 
	El programa codificar� el car�cter seg�n la clave introducida y lo mostrar� 
	por pantalla.

		
		Entrada: - Clave.
				 - Caracter.
				
						 
		Salida:  - Un caracter (codificado).
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se a�aden los recursos de E/S

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
	
	// C�lculos
	
	letra_1 = letra_1 + clave;

	if (letra_1 > MAX) {
		
		letra_1 = letra_1 - (MAX - MIN + 1);
		
	}
		
		
	// Salida de datos 
	
	cout << "Su letra codificada es: " << letra_1;
	cout << endl << endl;


 return 0;
}	
	
