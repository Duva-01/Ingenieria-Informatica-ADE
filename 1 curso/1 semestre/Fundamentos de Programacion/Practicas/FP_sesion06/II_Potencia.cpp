/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Calcular mediante un programa la función potencia x^n con n un valor 
	entero y x un valor real. No puede usarse la funciones de la biblioteca cmath.
		
		Entrada: - Numero base.
				 - Exponente.
				
				
						 
		Salida:  - Potencia.
				 		
	
*/
/***************************************************************************/


#include <iostream>				// Se añaden los elementos de E/S.

using namespace std;

int main () {					// Funcion Principal
	
	
	// Variables
	
	int numero, exponente, potencia_final = 1;
	
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca el numero base: "; cin >> numero;
	
	cout << endl;
	cout << "- Introduzca el exponente: "; cin >> exponente;
	cout << endl;
	
	// Logica y Calculos
	
	if (exponente != 0) {

	do {
		
		potencia_final = potencia_final * numero;
		exponente = exponente - 1;
		
	}while(exponente != 0);
	
	}
		
		
	else if ( exponente == 0) {potencia_final = 1;}
	
	
	// Salida de Datos 
	
	cout << "--> Su potencia vale: " << potencia_final;
	cout << endl << endl;
	
	
	return 0;
	
}
