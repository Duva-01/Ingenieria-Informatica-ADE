/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa que lea un valor entero en un dato de tipo string y a 
	continuación convertirlo y asignarlo a un dato int.

		
		Entrada: - Valor entero (string).
				
								
						 
		Salida:  - Dato (string).
				 		
	
*/
/***************************************************************************/


#include <iostream>
#include <string>

using namespace std;

int main () {				// Programa Principal
	
	
	// Variables
	
	string entrada, salida;
    int valor_entero, numero_3, numero_2, numero_1;
    
    // Entrada de datos
	
	cout << endl;
    cout << "- Introduzca un entero de 3 digitos: ";
    getline (cin, entrada);
    cout << endl << endl;
    valor_entero = stoi(entrada);
    
	if (entrada.length() == 3) {
		
	// Cálculos
		
    numero_3 = valor_entero / 100;
    numero_2 = (valor_entero - numero_3 * 100) / 10;
    numero_1 = (valor_entero - numero_3 * 100 - numero_2 * 10);
    
    // Salida de datos
	
    salida = to_string(numero_3) + "  ";
    salida += to_string(numero_2) + "  ";
    salida += to_string(numero_1) + "  ";

   
    cout << "--> "<< salida;
    
	}
	
	else {
		
	// Salida de datos
	
		cout << endl << endl;
		cout << "Error";
		cout << endl << endl;
		
	}
    
   
	
	return 0;
	
}
