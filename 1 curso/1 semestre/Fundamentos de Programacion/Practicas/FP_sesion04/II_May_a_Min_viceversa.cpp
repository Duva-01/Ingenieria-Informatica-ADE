/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se quiere leer un carácter letra_original desde teclado y
	• Si es una letra mayúscula, almacenaremos en la variable letra_convertida
		la correspondiente letra minúscula.
	• Si es una letra minúscula, almacenaremos en la variable letra_convertida
		la correspondiente letra mayúscula.
	• Si es un carácter no alfabético, almacenaremos el mismo carácter en 
	la variable letra_convertida.
		
		Entrada: - Caracter.
				
						 
		Salida:  - Caracter convertido.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;
	
int main () {						// Programa Principal
	
	// Variables
	
	char letra_original, letra_convertida;
	
	// Entrada de datos
		
	cout << endl;
	cout << "- Introduzca un caracter: "; cin >> letra_original;
	cout << endl;
	
	// Logica y Resultados
	
	if (letra_original >= 'A' && letra_original <= 'Z') {
		
		letra_convertida = letra_original + 32;
		
		cout << "--> El caracter era Mayuscula. Su letra en Minuscula es: " 
		<< letra_convertida;
		cout << endl << endl;
		
	}
	
	else if (letra_original >= 'a' && letra_original <= 'z') {
		
		letra_convertida = letra_original - 32;
		
		cout << "--> El caracter era Minuscula. Su letra en Mayuscula es: " 
		<< letra_convertida;
		cout << endl << endl;
		
	}
	
	else {
		
		cout << "--> Su caracter no era una letra";
		cout << endl << endl;
	}
	
	
	return 0;
	
	
}
