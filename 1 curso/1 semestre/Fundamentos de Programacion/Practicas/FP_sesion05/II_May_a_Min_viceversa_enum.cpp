/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se quiere leer un car�cter letra_original desde teclado y
	� Si es una letra may�scula, almacenaremos en la variable letra_convertida
		la correspondiente letra min�scula.
	� Si es una letra min�scula, almacenaremos en la variable letra_convertida
		la correspondiente letra may�scula.
	� Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en 
	la variable letra_convertida.
	
	Ahora deber� emplear un tipo enumerado que permita guardar el tipo de 
	car�cter de letra_original. Considere que ahora podr�a ser: una letra 
	may�scula, una letra min�scula, un d�gito u otro car�cter.
		
		Entrada: - Caracter.
				
						 
		Salida:  - Caracter convertido.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se a�aden los recursos de E/S

using namespace std;
	
int main () {						// Programa Principal
	
	// Variables
	
	char letra_original, letra_convertida;
	
	enum class Tipo {mayuscula, minuscula, otro_caracter};

	Tipo caracter;
	// Entrada de datos
		
	cout << endl;
	cout << "- Introduzca un caracter: "; cin >> letra_original;
	cout << endl;
	
	// Logica y Resultados
	
	if (letra_original >= 'A' && letra_original <= 'Z') {
		
		caracter = Tipo::mayuscula;	
	}
	else if (letra_original >= 'a' && letra_original <= 'z') {
		
		caracter = Tipo::minuscula;	
	}
	else {
		
		caracter = Tipo::otro_caracter;
	}
	
	cout << endl;

	switch (caracter) {
		
		case (Tipo::mayuscula) : 
		
		letra_convertida = letra_original + 32;
		
			cout << "--> El caracter era Mayuscula. Su letra en Minuscula es: " 
				 << letra_convertida;
			cout << endl << endl;
			
			break;
				
		case (Tipo::minuscula) : 
		
			letra_convertida = letra_original - 32;
		
		cout << "--> El caracter era Minuscula. Su letra en Mayuscula es: " 
			 << letra_convertida;
		cout << endl << endl;
		
			break;
			
		case (Tipo::otro_caracter) : 
		
		cout << "--> Su caracter no era una letra.";
		cout << endl << endl;
			break;
		
	}
			
	cout << endl;
		
	return 0;
	
	
}
