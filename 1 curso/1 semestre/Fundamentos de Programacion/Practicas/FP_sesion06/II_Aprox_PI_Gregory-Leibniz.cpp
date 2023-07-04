/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa que lea el valor tope obligando a que esté entre 1 
	y 100000, calcule la aproximación de pi mediante la anterior serie e imprima 
	el resultado.


		Entrada: - Tope
		
						 
		Salida:  - Pi.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>


using namespace std;

int main() {
	
	// Variables
	
	long double pi= 0;
	double calculo_pi;
	double tope, aux_2 = 0, aux = 0;
	int n=0;
	
	const int MIN = 1;
	const int MAX = 10000;
	
	// Entrada de Datos
	
	do {

	cout << endl << endl;
	cout <<"- Introduzca el numero de operaciones para la sucesion: "; 
	cin >> tope;
	
	}while (tope > MAX || tope < MIN);
	
	// Logica y Calculos
	
	// MANERA 1 //
	
	do {
	
	calculo_pi = pow(-1, n)/((2*n)+1);
	pi = pi + calculo_pi;
	n ++;	
	tope --;
	
	}while(tope != 0);
	
		
	//----------------------------------------//
	
	// MANERA 2 //
	/*
	
	for (int aux = tope; aux != 0; aux --) {
		
	if (n % 2 == 0)	{
	calculo_pi = (1/((2*aux_2)+1));	
	pi = pi + (1/((2*aux_2)+1));
	aux_2 ++;
	n ++;
		
	}
	
	else if (n % 2 != 0) {
	
	calculo_pi = (1/((2*aux_2)+1));		
	pi = pi - (1/((2*aux_2)+1));
	aux_2 ++;
	n ++;
	}
			
	}
	
	*/
	//----------------------------------------//
	
	
	// Salida de Datos
	
	cout << endl;
	cout << "--> El valor aproximado de Pi es: " << pi*4;
	cout << endl << endl;
	
	return 0;
	
}
