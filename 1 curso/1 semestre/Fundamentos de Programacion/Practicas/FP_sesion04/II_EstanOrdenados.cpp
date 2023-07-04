/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribid un programa que lea tres enteros desde teclado y nos diga si 
	están ordenados (da igual si es de forma ascendente o descendente) o no 
	lo están.
		
		Entrada: - Numeros.
				
						 
		Salida:  - Estan o no ordenados.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Se añaden los recursos de E/S

using namespace std;


int main() {				// Programa Principal
	
	
	// Variables
	
	int num_1, num_2, num_3;
	
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el primer numero: "; cin >> num_1;
	cout << endl;
	cout << "- Introduzca el segundo numero: "; cin >> num_2;
	cout << endl;
	cout << "- Introduzca el tercer numero: "; cin >> num_3;
	cout << endl;
	
	// Logica y Resultados
	
	if ((num_1 >= num_2) && (num_1 >= num_3) && (num_2 >= num_3)) {
		
		cout << "--> Estan ordenados";
		cout << endl << endl;
	}
	
	else if ((num_3 >= num_2) && (num_3 >= num_1) && (num_2 >= num_1)) {
		
		cout << "--> Estan ordenados";
		cout << endl << endl;
		
	}
	
	else {
		
		cout << "--> No estan ordenados";
		cout << endl;
	}
	
	return 0;
}

