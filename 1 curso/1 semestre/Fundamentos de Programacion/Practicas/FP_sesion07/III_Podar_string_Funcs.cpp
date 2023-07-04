/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escriba la función EliminaPrimeros que elimine todos los caracteres 
	iniciales de un string que sean igual a un carácter determinado.
	
	Por ejemplo, al borrar la T del inicio de la cadena TabcTdTTTT se obtendría 
	la cadena abcTdTTTT. Si la cadena fuese abcTdTTTT, el resultado de borrar la
	T del inicio de la cadena sería la misma cadena abcTdTTTT, ya que no hay 
	ninguna T al principio.

		
		Entrada: - String.
				 - Caracter.
				
				
						 
		Salida:  - String recortada.
	
*/
/***************************************************************************/


#include <iostream>
#include <string>


using namespace std;

/***************************************************************************/
/***************************************************************************/

string funcionEliminaUltimos (string cadena, char caracter, int i) {
	
	i = cadena.length();
	
	do {

	if (caracter == cadena[i-1]) {
		
	 	cadena.pop_back();
		i--;
	}	
		
	}while (caracter == cadena[i-1]);
	
	
	return cadena;
	
}

/***************************************************************************/
/***************************************************************************/

string funcionEliminaPrimeros (string cadena_2, char caracter_2, int i) {
	
	string str_aux;
	i = 0;
	
	do { i= i + 1; }while (caracter_2 == cadena_2[i]);
	
	for(int aux = i; aux <= cadena_2.length(); aux++)
        
		str_aux = str_aux + cadena_2[aux];
        
	return str_aux;
	
}

/***************************************************************************/
/***************************************************************************/

int main () {			// Funcion principal
	
	// Variables
	
	int i, opcion;
	string cadena , cadena_2, resultado, resultado_2;
	char caracter, caracter_2;
	
	// Instrucciones
	
	cout << endl;
	cout << "1. Elimina Ultimos.";
	cout << endl << endl;
	cout << "2. Elimina Primeros.";
	cout << endl<< endl;
	cout << "- Introduzca una opcion: "; cin >> opcion;
	
	// Logica
	
	if (opcion == 1) {
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca una cadena de caracteres (borrar ultimos): "; 
	getline (cin, cadena);
	getline (cin, cadena);
	
	cout << endl << endl;
	
	cout << "- Introduce un caracter: "; cin >> caracter;
	cout << endl;
	
	// Llamada de funcion
	
	resultado = funcionEliminaUltimos (cadena,  caracter, i);
	
	// Salida de Datos
	
	cout << endl << endl;
	cout << "--> La cadena de caracteres es: "<< resultado;
	cout << endl << endl;
	
	}
	
	else if (opcion == 2) {
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca una cadena de caracteres (borrar primeros): "; 
	getline (cin, cadena_2);
	getline (cin, cadena_2);
	cout << endl << endl;
	
	cout << "- Introduce un caracter: "; cin >> caracter_2;
	cout << endl;
	
	// Llamada de funcion
	
	resultado_2 = funcionEliminaPrimeros (cadena_2,  caracter_2, i);
	
	// Salida de Datos
	
	cout << endl << endl;
	cout << "--> La cadena de caracteres es: "<< resultado_2;
	cout << endl << endl;
	
	}
	
	
	return 0;
}
