/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
/*  
	Construir un programa que imprima el valor de pi calculado a partir de 
	la  fórmula:
		
		PI/6 = arco-seno(0,5)
		
		De esta formula sacamos la conclusion de que pi es igual a:
		
		PI = 6*arco-seno(0,5)
	
*/
/***************************************************************************/

#include <math.h>			// Se añaden los recursos matematicos.
#include <iostream>			// Se añaden los recursos de E/S


using namespace std;

int main() { 				// Programa Principal
	
	double long  num_pi; 	// Variable
	
	// Cálculos	
	
	num_pi = (6*asin (0.5));
	
	// Salida de datos
	
	cout <<endl;
	cout <<"--> El valor del numero Pi es: " << num_pi;
	cout <<endl <<endl;
	
	return 0;
	
	
}
