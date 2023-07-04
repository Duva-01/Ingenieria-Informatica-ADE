/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se quiere construir un programa que lea un número real r y un número 
	entero n y trunque r a tantas cifras decimales como indique n. El resultado 
	debe guardarse en una variable diferente. La única función que puede usar 
	de cmath es pow.

		
		Entrada: - NªEntero.
				 - NºReal
								
						 
		Salida:  - NºReal Modificado.
				 		
	
*/
/***************************************************************************/

	
	//Llamada de recursos
	
	#include <iostream>     
	#include <cmath>     

using namespace std;


int main() {			// Programa Principal
	
	// Variables
	
	double numero_real, solucion;
	int decimales, aux;
	
	// Entrada de datos

	cout << endl;
	cout << "- Numero REAL con decimales: "; cin >> numero_real;
	cout << endl;
	cout << "- Redondear a cuantos decimales: "; cin >> decimales;
	cout << endl << endl;
	
	numero_real = numero_real * pow(10,decimales);
	aux = numero_real;
	
	solucion = aux/pow(10,decimales);
	
	
	
	// Salida de datos

	cout << "El resultado es: " << solucion;
	cout << endl << endl;
	
	return 0;
}



