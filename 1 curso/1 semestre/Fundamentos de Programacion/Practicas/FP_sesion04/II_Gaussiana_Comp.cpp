/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Realizar un programa que lea los coeficientes reales � y s de una funci�n 
	gaussiana. A continuaci�n el programa leer� un valor de abscisa x y se 
	imprimir� el valor que toma la funci�n en x.

		
		Entrada: - �
				 - s.
						 
		Salida:  - Funcion: f(x).
				 		
	
*/
/***************************************************************************/

#include <iostream>		// Se a�aden los recursos de E/S
#include <cmath>		// Se a�aden los recursos de matematicos

using namespace std;

int main() {			// Programa Principal
	
	// Variables
	
	double esperanza, desviacion_t, valor_abcisa;
	double funcion_1, funcion_2, funcion_total;
	const double PI	= 3.14;

	
	// Entrada de datos
	

	cout << endl;
	cout << "- Introduzca el valor numerico de \"esperanza\": "; 
	cin >> esperanza; cout << endl;

	cout << "- Introduzca el valor numerico de \"desviacion tipica\": "; 
	cin >> desviacion_t; cout << endl << endl;
	
	cout << "- Introduzca un valor de abcisa: "; cin >> valor_abcisa;
	cout << endl;
	
	
	if (desviancion_t <= 0) {
		
	// Salida de datos
	
		cout << "Error";
		cout << endl << endl;
	}
	
	else {
		
	// C�lculos
	
		
		funcion_1 = (1/((desviacion_t)*sqrt(2*PI)));
		funcion_2 = exp(((-0.5)
					*pow(((valor_abcisa - esperanza)/desviacion_t),2)));
	
		funcion_total = funcion_1 * funcion_2;
	
	// Salida de datos
	
	cout << "--> El valor de f(x)= " << funcion_total;
	cout << endl << endl;
	
	}
	
	return 0;
}
