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
				 - Valor de x
				 
						 
		Salida:  - Funcion: f(x).
				 		
	
*/
/***************************************************************************/

#include <iostream>		// Se a�aden los recursos de E/S
#include <cmath>		// Se a�aden los recursos de matematicos

using namespace std;

double funcionGaussiana (double valor_abcisa) {
	
	// Variables
	
	double esperanza, desviacion_t;
	double funcion_1, funcion_2;	
	double funcion_total;
	
	const double PI	= 3.141592;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el valor numerico de \"esperanza\": "; 
	cin >> esperanza; cout << endl;
	
	do {

	cout << "- Introduzca el valor numerico de \"desviacion tipica\": "; 
	cin >> desviacion_t; cout << endl << endl;

	}while (desviacion_t <= 0);
	
	// C�lculos

		funcion_1 = (1/((desviacion_t)*sqrt(2*PI)));
		funcion_2 = exp(((-0.5)*pow(((valor_abcisa - esperanza)/desviacion_t),2)));
	
		funcion_total = funcion_1 * funcion_2;
		
	
	
	return funcion_total;
	
	
}

int main() {			// Programa Principal
	
	// Variables
	
 	double valor_abcisa, funcion_total;
	
	
	// Entrada de datos
	
	cout << endl << endl;
	cout << "- Introduzca un valor de abcisa: "; cin >> valor_abcisa;
	cout << endl;
	
	// Llamada de la funcion
	
	funcion_total = funcionGaussiana (valor_abcisa);
	
	// Salida de datos
	
	cout << "--> El valor de f(x)= " << funcion_total;
	cout << endl << endl;
	

	
	return 0;
}
