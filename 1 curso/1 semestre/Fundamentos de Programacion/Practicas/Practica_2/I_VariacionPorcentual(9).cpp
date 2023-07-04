/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//
/*  9.
	Se define el concepto variación porcentual como:
	
	VP = abs( 100 × (valor final - valor inicial/ valor inicial))
	
	Escriba un programa en C++ que lea el valor inicial y final de un producto 
	(variables de tipo double) y calcule la variación porcentual del mismo.
		
		Entrada: - Valor inicial.
				 - Valor final.
				 
		Salida:  - Variacion porcentual.		
	
*/
/***************************************************************************/


#include <iostream>		// Se añaden los recursos de E/S.
#include <cmath>		// Se añaden los recursos matematicos.

using namespace std;

int main() {		  // Programa Principal
	
	
	// Variables
	
	double valor_inicial, valor_final, variacion_p;
	
	// Entrada de datos
	
	cout <<endl << endl;
	cout << "- Introduzca el valor inicial del producto: "; cin >> valor_inicial;
	cout <<endl;
	cout << "- Introduzca el valor final del producto: "; cin >> valor_final;
	
	// Cálculos	
	
	variacion_p = abs(100*((valor_final-valor_inicial)/valor_inicial));
	
	// Salida de datos
	
	cout <<endl << endl;
	cout << "--> La variacion porcentual del producto es del " 
	<< variacion_p <<"%.";
	cout <<endl << endl;
	
	return 0;
}
