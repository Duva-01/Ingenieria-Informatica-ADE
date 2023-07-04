/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	15.
/*  Realizar un programa que nos pida una longitud cualquiera dada en metros. 
	El programa deberá calcular el equivalente de dicha longitud en pulgadas, 
	pies, yardas y millas, y mostrarnos los resultados en pantalla. 
	
		1 pulgada= 25,4 milímetros 
		1 yarda = 0,9144 metros
		1 pie = 30,48 centímetros 
		1 milla = 1609,344 metros

		
		Entrada: - Capital.
				 - Interes.
				 
		Salida:  - Total.		
	
*/
/***************************************************************************/


#include <iostream>		// Se añaden los recursos de E/S.

using namespace std;

int main() {			// Programa Principal
	
	// Variables
	
	double longitud, pulgadas, yardas, pies, millas;
		
	// Entrada de datos
	
	cout <<endl;
	cout << "- Introduzca la longitud en metros: "; cin >> longitud;
	cout <<endl << endl;
	
	// Cálculos	
	
	pulgadas= longitud/0.0254;
	yardas= longitud/0.9144;
	pies= longitud/0.3048;
	millas= longitud/1609,344;
	
	
	// Salida de datos
	
	cout << "- Pulgadas: " << pulgadas; cout <<endl;
	
	cout << "- Yardas: " << yardas; cout <<endl;
	
	cout << "- Pies: " << pies;	cout <<endl;
	
	cout << "- Millas: " << millas; 	
	cout <<endl << endl;
	
	return 0;
}
