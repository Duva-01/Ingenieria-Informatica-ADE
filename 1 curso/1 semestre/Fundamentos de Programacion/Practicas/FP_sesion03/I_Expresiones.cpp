/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Declarar las variables necesarias y traducir las siguientes fórmulas a 
	expresiones válidas del lenguaje C++.

		
		Entrada: - Variables.
				
								
						 
		Salida:  - Resultado de operaciones.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Se añaden los recursos de E/S
#include <cmath>			// Se añaden los recursos matematicos

using namespace std;


int main () {			// Programa Principal
	
	// Variables
	
	int x, y ,h;
	int a, b, c;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el valor de x: "; cin >> x;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> y;
	cout << endl;
	cout << "- Introduzca el valor de h: "; cin >> h;
	cout << endl << endl;
	
	// Cálculos
	
	a = (1+(pow(x,2)/y))/((pow(x,3))/(1+y));
	
	b = (1+0.33*sin(h)-0.1428*cos(h))/2*h;
	
	c = sqrt(1+pow((exp(x)/pow(x,2)),2));
	
	// Salida de datos
	
	cout << "--> El apartado a) vale: " << a;
	cout << endl<< endl;
	cout << "--> El apartado b) vale: " << b;
	cout << endl<< endl;
	cout << "--> El apartado c) vale: " << c;
	cout << endl << endl;
	
	return 0;
	

}
