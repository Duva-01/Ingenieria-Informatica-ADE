/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	El programa mostrará un menú:
	
		1.- Comparación por número de iteraciones
		2.- Comparación por calidad de la aproximación
		0.- Salir
		
	Dependiendo de la opción escogida:
	
		1 Comparación por número de iteraciones
		2 Comparación por calidad de la aproximación

		
		Entrada: - String.
				 - Caracter.
				
				
						 
		Salida:  - String recortada.
	
*/
/***************************************************************************/


#include <iostream>
#include <cmath>


using namespace std;

/***************************************************************************/
/***************************************************************************/

double funcionMadhava_1 (int iteraciones) {
	
	double result_1 = 0;
	double aux = 0;
	
	do {
		
	result_1 = result_1 + (pow (-1, aux)*pow((1/sqrt(3)), 2*aux + 1)/(2*aux + 1));
	aux ++;
		
	}while (aux != iteraciones);
	
	
	return result_1*6;
	
}

/***************************************************************************/
/***************************************************************************/

double funcionGottfried_1 (int iteraciones) {
	
	long double pi= 0, calculo_pi;
	int n=0;
		
	do {
	
	calculo_pi = pow(-1, n)/((2*n)+1);
	pi = pi + calculo_pi;
	n ++;	
	iteraciones --;
	
	}while(iteraciones != 0);
	
	return pi*4;	

}

/***************************************************************************/
/***************************************************************************/

double funcionWallis_1 (int iteraciones) {

	double numerador = 1, denominador = 1, pi = 1;
		
		for (int i = 0; i <= iteraciones; i++) {
			
			pi = pi * (numerador/denominador);
			
			if (i % 2 == 0) { numerador = denominador + 1; }
			
			else { denominador = numerador + 1; }
		
		}			
	
	return pi*2;

}

/***************************************************************************/
/***************************************************************************/

double funcionMadhava_2 (int decimales, const double PI) {
	
	int iteraciones = 0;
	double result_1 = 0, aux = 0;
	
	do {
		
	result_1 = result_1 + (pow (-1, aux)*pow((1/sqrt(3)), 2*aux + 1)/(2*aux + 1));
	
	aux ++;
	iteraciones ++;

	}while (abs (result_1*6 - PI) > pow(10,-(decimales)));
	
	
	return iteraciones;
	
}

/***************************************************************************/
/***************************************************************************/


double funcionGottfried_2 (int decimales, const double PI) {
	
	long double pi= 0, calculo_pi;
	int n=0, iteraciones = 0;
		
	do {
	
	calculo_pi = pow(-1, n)/((2*n)+1);
	pi = pi + calculo_pi;
	n ++;	
	iteraciones ++;
	
	}while(abs (pi*4 - PI) > pow(10,-(decimales)));
	
	return iteraciones;	

}

/***************************************************************************/
/***************************************************************************/

double funcionWallis_2 (int decimales, const double PI) {

	double numerador = 1, denominador = 1, pi = 1;
	int iteraciones= 0;
		
	int i = 0; 
	
	do {
		
			pi = pi * (numerador/denominador);
			
			if (i % 2 == 0) { numerador = denominador + 1; }
			
			else { denominador = numerador + 1; }
			
			i++;
			iteraciones ++;
			
	}while (abs (pi*2 - PI) > pow(10,-(decimales)));			
	
	return iteraciones;

}

/***************************************************************************/
/***************************************************************************/

int main () {
	
	// Variables
	
	int opcion, iteraciones, veces_M, veces_W, veces_G, decimales, pi;
	double resultado_1, resultado_2, resultado_3;
	const double PI =  3.14159265358979323846;
	
	
	cout << endl;
	cout << "1.- Comparacion por número de iteraciones.";
	cout << endl;
	cout << "2.- Comparacion por calidad de la aproximacion.";
	cout << endl;
	cout << "0.- Salir.";
	cout << endl << endl;
	
	// Entrada de Datos
	
	cout << "- Escoja una opcion: "; cin >> opcion;
	cout << endl << endl;
	
	// Logica
	
	if (opcion == 1) {
		
		do {
		
		cout << "Introduzca un numero de iteraciones: "; cin >> iteraciones;
		
		}while (1 > iteraciones && iteraciones > 100000);
		
		// Llamada de Funciones
		
		resultado_1 = funcionMadhava_1(iteraciones);
		
		resultado_2 = funcionGottfried_1 (iteraciones);
		
		resultado_3 = funcionWallis_1 (iteraciones);
		
		// Salida de Datos
		
		cout << endl;
		cout <<"--> Madhava: " << resultado_1;
		cout << endl << endl;
		
		cout <<"--> Gottfried: " << resultado_2;
		cout << endl;
		
		
		cout << endl;
		cout <<"--> Wallis: " << resultado_3;
		cout << endl << endl;
		
		
		if (abs(resultado_1 - PI) < abs(resultado_2 - PI) 
			&& abs(resultado_1 - PI)< abs(resultado_3 - PI)) {
				
			cout << "El resultado que mas se aproxima es el de Madhava.";
			cout << endl;	
				
			}
			
		else if (abs(resultado_2 - PI) < abs(resultado_1 - PI) 
				&& abs(resultado_2 - PI)< abs(resultado_3 - PI)) {
				
			cout << "El resultado que mas se aproxima es el de Gottfried.";
			cout << endl;	
				
			}
			
		else if (abs(resultado_3 - PI) < abs(resultado_2 - PI) 
				&& abs(resultado_3 - PI)< abs(resultado_1 - PI)) {
				
			cout << "El resultado que mas se aproxima es el de Wallis.";
			cout << endl;	
				
			}
		
	}
	
	else  if (opcion == 2) {
	
		do {
		
		cout << endl;
		cout << "--- Pi = [3.14159265358] ---";
		cout << endl;
		cout << "- Introduzca un numero de decimales: "; cin >> decimales;
		
		}while (1 > decimales && decimales > 10);
		
	
		// Llamada de Funciones 
		
		resultado_1 = funcionMadhava_2(decimales, PI);
		
		resultado_2 = funcionGottfried_2 (decimales, PI);
		
		resultado_3 = funcionWallis_2 (decimales, PI);
		
		
		// Salida de Datos
		
		cout << endl;
		cout <<"--> Madhava: " << resultado_1;
		cout << endl << endl;
		
		cout <<"--> Gottfried: " << resultado_2;
		cout << endl;
		
		
		cout << endl;
		cout <<"--> Wallis: " << resultado_3;
		cout << endl << endl;
		
			
		if (resultado_1 < resultado_2 && resultado_1 < resultado_2) {
				
			cout << "El resultado que mas se aproxima es el de Madhava.";
			cout << endl;	
				
			}
			
		else if (resultado_2 < resultado_1 && resultado_2 < resultado_2) {
				
			cout << "El resultado que mas se aproxima es el de Gottfried.";
			cout << endl;	
				
			}
			
		else if (resultado_3 < resultado_2 && resultado_3 < resultado_1) {
				
			cout << "El resultado que mas se aproxima es el de Wallis.";
			cout << endl;	
				
			}
		
	}
	
	else if (opcion == 0) { return 0;}
	
	
	return 0;
}
