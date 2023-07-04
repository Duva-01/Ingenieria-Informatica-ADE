/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
// 
//	7.
//  "Una compa��a a�rea establece el precio del billete como sigue: en primer 
//	lugar se fija una tarifa base de 150 euros, la misma para todos los 
//	destinos. A continuaci�n se suman 10 c�ntimos por cada kil�metro de 
//	distancia al destino".
//	
//
/*  
		Cree un programa que lea el n�mero de kil�metros al destino y calcule 
		el precio final	del billete.
		
		Entrada: - N� de Kms.
				 
				 
		Salida:  - Precio billete.
				 	
	
*/
/***************************************************************************/


#include <iostream>			// Se a�aden los recursos de E/S

using namespace std;

int main() {			   // Programa Principal
	
	
	// Variables
	
	double billete, kilometros;
	
	// Entrada de datos
	
	billete = 150;
	cout <<endl;
	cout << " -- Hola Sr/a --";
	cout <<endl << endl;
	cout << " Introduzca el N de Kms que va a recorrer: ";
	cin >> kilometros;
	
	// C�lculos	
	
	billete = billete + (0.10*kilometros);
	
	// Salida de datos
	
	cout <<endl;
	cout << " --> EL precio de su billete es de " << billete <<" euros.";
	cout <<endl << endl <<endl << endl;
	
	cout << " -- Gracias por volar con nosotros --";
	cout <<endl << endl;
	
	return 0;
}
