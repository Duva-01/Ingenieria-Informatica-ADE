/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Realizar un programa que lea los coeficientes reales µ y s de una función 
	gaussiana. A continuación el programa leerá un valor de abscisa x y se 
	imprimirá el valor que toma la función en x.

		
		Entrada: - µ
				 - s.
				 - Valor de x
				 - Rango
				 - Incremento.
						 
		Salida:  - Funcion: f(x).
				 - CDF(x)
				 		
	
*/
/***************************************************************************/

#include <iostream>		// Se añaden los recursos de E/S
#include <cmath>		// Se añaden los recursos de matematicos

using namespace std;

int main() {			// Programa Principal
	
	// Variables
	
	double esperanza, desviacion_t, valor_abcisa;
	double funcion_1, funcion_2, funcion_total;
	double funcion_aux1, funcion_aux2, funcion_total_CDF, CDF;
	int maximo, minimo, incremento, aux, aux_2;
	const double PI	= 3.14;

	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el valor numerico de \"esperanza\": "; 
	cin >> esperanza; cout << endl;

	cout << "- Introduzca el valor numerico de \"desviacion tipica\": "; 
	cin >> desviacion_t; cout << endl << endl;
	
	cout << "- Introduzca un valor de abcisa: "; cin >> valor_abcisa;
	cout << endl << endl;
	
	cout << "---------------------------------";
	cout << endl << endl;
	
	cout << "Introduzca un rango minimo: "; cin >> minimo;
	cout << endl;
	cout << "Introduzca un rango maximo: "; cin >> maximo;
	cout << endl;
	cout << "Introduzca el incremento: "; cin >> incremento;
	cout << endl << endl;
	
	
	aux_2 = minimo;
	
	// Cálculos
	
	if (valor_abcisa > minimo && valor_abcisa < maximo) {
		

	do {
	
	// CDF
	
	do {
		
	funcion_aux1 = (1/((desviacion_t)*sqrt(2*PI)));
	funcion_aux2 = exp(((-0.5)*pow(((minimo - esperanza)/desviacion_t),2)));
	
	funcion_total_CDF = funcion_total_CDF + (funcion_1 * funcion_2);
	
	minimo ++;
	
	}while (aux_2 =! valor_abcisa);
	
	/*********************************/
	

	funcion_1 = (1/((desviacion_t)*sqrt(2*PI)));
	funcion_2 = exp(((-0.5)*pow(((valor_abcisa - esperanza)/desviacion_t),2)));
	
	funcion_total = funcion_1 * funcion_2;
	
	
	// Salida de datos
	
	cout << "--> El valor de f(" << valor_abcisa << ")= "<< funcion_total;
	cout << endl;
	cout << "- Y su CDF(" << valor_abcisa << ")= "<< funcion_total_CDF;
	cout << endl << endl;
	
	cout << "----------------------";
	cout << endl << endl;
	
	
	valor_abcisa = valor_abcisa+incremento;
	
		}while (maximo >= valor_abcisa);
		
		
	}
	
	else { cout <<"Error";}	
		
	return 0;
}
