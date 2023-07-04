/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa en el que se presente un menú principal para que el 
	usuario pueda elegir entre las siguientes opciones:
		
		A–>Calcular adición.
		P–>Calcular producto.
		X–>Salir.

		
		Entrada: - Opcion
						 
		Salida:  - Resultado.
				 		
	
*/
/***************************************************************************/


#include <iostream>

using namespace std;

int main () {
	
	// Variables
	
	char opcion_1, opcion_2;
	double calculos, num_1, num_2;
	
	do {
	
	cout << endl;
	cout << "\t -- Menu 1 --";
	cout << endl;
	cout << "- [A] Calcular adicion.";
	cout << endl;
	cout << "- [P] Calcular producto.";
	cout << endl;
	cout << "- [X] Para salir.";
	cout << endl << endl;
	cout << "--> Introduzca una opcion: "; cin >> opcion_1;
	
	do {

	if (opcion_1 == 'A') {
		
			cout << endl;
			cout << "\t -- Menu 2 --";
			cout << endl;
			cout << "- [S] Calcular suma.";
			cout << endl;
			cout << "- [R] Calcular resta.";
			cout << endl;
			cout << "- [X] Para salir.";
			cout << endl << endl;
			cout << "--> Introduzca una opcion: "; cin >> opcion_2;
			
	}
	
	if (opcion_1 == 'P') {
		
			cout << endl;
			cout << "\t -- Menu 2 --";
			cout << endl;
			cout << "- [M] Calcular multiplicacion.";
			cout << endl;
			cout << "- [D] Calcular division.";
			cout << endl;
			cout << "- [X] Para salir.";
			cout << endl << endl;
			cout << "--> Introduzca una opcion: "; cin >> opcion_2;
			
	}	
		// Calculos y Logica
		
	if (opcion_2 == 'S') {
			
			// Entrada de Datos
			
			cout << endl;
			cout << "Introduzca el primer numero: "; cin >> num_1;
			cout << endl;
			cout << "Introduzca el segundo numero: "; cin >> num_2;
			cout << endl;
			
			// Calculos
			calculos = num_1 + num_2;
			
			// Salida de Datos
			
			cout << "--> La suma es: " << calculos;
			cout << endl;
			
	}
	
	if (opcion_2 == 'R') {
			
			// Entrada de Datos
			
			cout << endl;
			cout << "Introduzca el primer numero: "; cin >> num_1;
			cout << endl;
			cout << "Introduzca el segundo numero: "; cin >> num_2;
			cout << endl;
			
			// Calculos
			calculos = num_1 - num_2;
			
			// Salida de Datos
			
			cout << "--> La resta es: " << calculos;
			cout << endl;
			
	}
	
	
	if (opcion_2 == 'M') {
			
			// Entrada de Datos
			
			cout << endl;
			cout << "Introduzca el primer numero: "; cin >> num_1;
			cout << endl;
			cout << "Introduzca el segundo numero: "; cin >> num_2;
			cout << endl;
			
			// Calculos
			calculos = num_1 * num_2;
			
			// Salida de Datos
			
			cout << "--> La multiplicacion es: " << calculos;
			cout << endl;
			
	}
	
	if (opcion_2 == 'D') {
			
			// Entrada de Datos
			
			cout << endl;
			cout << "Introduzca el primer numero: "; cin >> num_1;
			cout << endl;
			cout << "Introduzca el segundo numero: "; cin >> num_2;
			cout << endl;
			
			// Calculos
			calculos = num_1 / num_2;
			
			// Salida de Datos
			
			cout << "--> La division es: " << calculos;
			cout << endl;
			
	}
	
	
	
	}while (opcion_2 != 'X');
	
	
	
	}while (opcion_1 != 'X');
	
	
	return 0;
	
}
