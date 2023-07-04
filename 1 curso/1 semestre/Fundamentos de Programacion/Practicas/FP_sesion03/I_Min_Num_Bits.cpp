/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se pide crear un programa que lea un entero n, y calcule el m�nimo n�mero 
	de d�gitos que se necesitan para su representaci�n.

		
		Entrada: - N�Entero.
								
						 
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

	// C�lculos
	
	bits = log(numero) / log(2) + 1;

	// Salida de datos
	
	cout << "--> TOTAL DE BITS UILIZADOS: " << bits;
	cout << endl << endl;

 return 0; 
}

