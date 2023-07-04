#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

/***************************************************************************/
/***************************************************************************/

string funcionEliminaUltimosSeparadores (string cadena,  int i) {
	
	i = cadena.length();
	
	do {

	if (isspace(cadena[i-1]) != 0) {
		
	 	cadena.pop_back();
		i--;
	}	
		
	}while (isspace(cadena[i-1]) == cadena[i-1]);
	
	
	return cadena;
	
}

/***************************************************************************/
/***************************************************************************/

string funcionEliminaPrimerosSeparadores (string cadena_2,  int i) {
	
	string str_aux;
	
	i = 0;
	
	do { i= i + 1; }while (isspace(cadena_2[i]) != 0);
	
	for(int aux = i; aux <= cadena_2.length(); aux++)
        
		str_aux = str_aux + cadena_2[aux];
        
	return str_aux;
	
}

/***************************************************************************/
/***************************************************************************/

int main () {			// Funcion principal
	
	// Variables
	
	int i, opcion, aux, aux_2;
	string cadena , cadena_2, resultado, resultado_2;
	
	
	// Instrucciones
	
	cout << endl;
	cout << "1. Elimina Ultimos Separadores.";
	cout << endl << endl;
	cout << "2. Elimina Primeros Separadores.";
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
	aux = cadena.length();
	cout << aux;
	// Llamada de funcion
	
	resultado = funcionEliminaUltimosSeparadores (cadena, i);
	
	// Salida de Datos
	
	cout << endl << endl;
	cout << "--> La cadena de caracteres es: "<< resultado;
	cout << endl << endl;
	aux_2 = resultado.length();
	cout << aux_2;
	}
	
	else if (opcion == 2) {
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca una cadena de caracteres (borrar primeros): "; 
	getline (cin, cadena_2);
	getline (cin, cadena_2);
	
	cout << endl << endl;
	
	
	
	// Llamada de funcion
	
	resultado_2 = funcionEliminaPrimerosSeparadores (cadena_2, i);
	
	// Salida de Datos
	
	cout << endl << endl;
	cout << "--> La cadena de caracteres es: "<< resultado_2;
	cout << endl << endl;
	
	}
	
	
	return 0;
}


