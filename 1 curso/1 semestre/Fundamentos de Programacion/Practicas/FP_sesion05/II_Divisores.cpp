/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Realizar un programa que lea desde teclado un entero positivo e imprima en 
	pantalla todos sus divisores propios. Para obtener los divisores, basta 
	recorrer todos los enteros menores que el valor introducido y comprobar si 
	lo dividen.
		
		Entrada: - Numero entero.
				
						 
		Salida:  - Divisores.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;


int main () {					// Programa Principal
	
	// Variables
	
	int numero, aux;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca un numero para calcular sus divisores: "; 
	cin >> numero;
	cout << endl << endl;
	
	aux = numero;
	
	cout << "--> Los divisores son:";
	cout << endl << endl;
	
	// Logica y Resultados
	
	if (numero > 0) {
	
	do {
		
		if (numero % aux == 0){
			
			cout<<aux<<" ";	
		}
		
		aux --;
		
	} while (aux !=0);
	
	}
	
	return 0;
}
