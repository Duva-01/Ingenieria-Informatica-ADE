/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se pide crear un programa que lea un entero n, y calcule el mínimo número 
	de dígitos que se necesitan para su representación.

		
		Entrada: - NªEntero.
								
						 
		Salida:  - Numero de digitos.
				 - Numero en binario.
				 		
	
*/
/***************************************************************************/

	//Llamada de recursos
	
	#include <iostream>     
 	#include <cmath>
	    

using namespace std;

int main() { 			// Programa Principal
 
 
 	// Variables
 	
 	int numero, bits;
	
	// Entrada de datos
	
	cout << endl;
 	cout << "- Numero para pasar a BINARIO: "; cin >> numero;
 	cout << endl << endl;

	
	if (numero == 0) {
		
		bits = 1;
		cout << "--> TOTAL DE BITS UILIZADOS: " << bits;
		
	}
	
	else if (numero < 0) {
		
		cout << "Error";
		cout << endl << endl;
		
	}
		
	else {
		
	// Cálculos
	
	bits = log(numero) / log(2) + 1;

	// Salida de datos
	
	cout << "--> TOTAL DE BITS UILIZADOS: " << bits;
	cout << endl << endl;
	
	}
		
	

 return 0; 
 
}

