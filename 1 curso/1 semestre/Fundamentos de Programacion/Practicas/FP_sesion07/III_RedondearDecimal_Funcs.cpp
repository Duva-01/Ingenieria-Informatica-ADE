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

#include <iostream>				// Se a�aden los elementos de E/S.
#include <cmath>	

using namespace std;

double funcionPotencia (double limite, double numero_redondear) {

	
	// Variables
	
	int numero = 10, potencia_final = 1;
	
	
	// Logica y Calculos
	
	if (limite != 0) {

	do {
		
		potencia_final = potencia_final * numero;
		limite = limite - 1;
		
	}while(limite != 0);
	
	}
		
		
	else if ( limite == 0) {potencia_final = 1;}
	
	numero_redondear = round (numero_redondear * potencia_final);
	
	numero_redondear = numero_redondear / potencia_final;
	
	// Salida de Datos
	
	return numero_redondear;
	
}


int main() {		// Funcion Principal
	
	// Variables
	
	double numero_redondear;
	double aux_2, aux= 0, redondeo, potencia, limite;
	
	// Entrada de Datos
	cout << endl;
	cout << "- Introduzca un numero: "; cin >> numero_redondear;
	cout << endl;
	cout << "- Introduce hasta que numero decimal redondear: "; cin >> limite;
	cout << endl << endl;
	
	// Llamada de Datos
	
	potencia = funcionPotencia(limite, numero_redondear);
	
	
	
	cout << "--> Su numero redondeado es: "<< potencia;
	cout << endl << endl;
	
	
	return 0;
}
