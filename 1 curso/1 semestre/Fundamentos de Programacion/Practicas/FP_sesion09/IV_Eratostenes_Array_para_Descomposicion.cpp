/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa que lea un número entero positivo y muestre su 
	descomposición en factores primos. Ahora deberá realizar un programa que 
	lea un número indeterminado de enteros positivos y exprese cada uno de ellos 
	en base al producto de sus factores primos. Exprese el resultado como el 
	producto de potencias.

		
		Entrada: - Numero.
								 
		Salida:  - Descomposicion en factores primos.
				 		
	
*/
/***************************************************************************/

#include <iostream>						// Incluye las opciones de E/S.

using namespace std;

int main () {							// Programa Principal
	
	
	// Lista de Primos //

/***************************************************************************/
	
	// Variables
	
	int const MAX_PRIMO = 200;
	int const MAX_DATOS = 5000;
	
	int n = 0;
	bool es_primo[MAX_PRIMO];
	
	// Asignacion de primos
	
	for (int i=0; i <= MAX_PRIMO; i++)
		es_primo[i] = true;
	
	
	for (int n=2; n*n <= MAX_PRIMO; n++) { 
         
		if (es_primo[n]) {

			for (int aux = 2; aux*n <= MAX_PRIMO; aux ++) { 
				es_primo[aux*n] = false;  
			}
		}

	}

	// Introduccion de primos en lista
	
int numeros_p = 0;
int primos[MAX_DATOS];	 
	 
	for (int j = 1; j <= MAX_PRIMO; j++) {

		if (es_primo[j]) {

			if (numeros_p < MAX_DATOS ) {
			
				primos[numeros_p] = j;  
				numeros_p ++;
			}
		}
	}
	
/***************************************************************************/
/***************************************************************************/

	// Ejercicio //
	
	
	// Variables
	
	int numero;
	int utilizados_descomposicion = 0;
	
	// Entrada de Datos
	
	do {
		
		cout << "Introduzca un numero [n > 2]: ";
		cin >> numero;
		
	}while (numero < 2);
	
	// Creacion de variable para descomponer
		
	struct Pareja {
		
		int primo;
		int potencia;
		
	};

	Pareja descomposicion[50] = {{0,0}}; 	// Limpieza
	
/***************************************************************************/

	// Operaciones //
	
	
	// Variables
	
	int pos_primos = 1;
	int dividendo = numero;
	int divisor = primos[pos_primos]; 

	// Calculos  
	
while (dividendo != 1) {

	if(dividendo % divisor==0) { 

		descomposicion[utilizados_descomposicion].primo = divisor;
		descomposicion[utilizados_descomposicion].potencia = 1;

		dividendo = dividendo / divisor;


		while (dividendo % divisor == 0) {
		
			descomposicion[utilizados_descomposicion].potencia ++;
			dividendo = dividendo / divisor;
		}

		utilizados_descomposicion ++;
	}
	
	pos_primos++;
	divisor = primos[pos_primos];
	
	}
	
/***************************************************************************/

	// Salida de Datos
	
	cout << numero << " = ";

	for (int i=0; i < utilizados_descomposicion-1; i++) {
		
		cout << descomposicion[i].primo << "^"
    	 	 << descomposicion[i].potencia << " + ";
	}
	
	
	cout << descomposicion[utilizados_descomposicion-1].primo
    	 << "^" << descomposicion[utilizados_descomposicion-1].potencia;

	cout << endl << endl; 

	return 0;
}
