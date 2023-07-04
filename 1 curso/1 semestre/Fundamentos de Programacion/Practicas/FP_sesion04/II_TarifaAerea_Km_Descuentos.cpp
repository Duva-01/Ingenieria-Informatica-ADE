/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
// 
//	
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
				 - Puntos.
				 
				 
		Salida:  - Precio billete(descuento).
				 	
	
*/
/***************************************************************************/


#include <iostream>			// Se a�aden los recursos de E/S

using namespace std;

int main() {			   // Programa Principal
	
	
	// Variables
	
	double billete, kilometros;
	int puntos;
	double descuento = 0;
	
	// Entrada de datos
	
	billete = 150;
	cout <<endl;
	cout << " -- Hola Sr/a --";
	cout <<endl << endl;
	cout << " Introduzca el N de Kms que va a recorrer: ";
	cin >> kilometros;
	cout <<endl;
	cout << " Introduzca el N de puntos de fidelidad: ";
	cin >> puntos;
	cout <<endl;
	
	// C�lculos	
	
	billete = billete + (0.10*kilometros);
	
	if (kilometros > 700) {
		
		descuento = descuento + 2;
		
			
	}
	
	if (puntos >= 100 && puntos < 200) {
		
		descuento = descuento + 3;
		
	}
	
	if (puntos >= 200) {
		
		descuento = descuento + 4;
		
	}
	
	// Salida de datos
	
	billete = billete - (billete*(descuento/100));
	
	cout <<endl;
	cout << " --> EL precio de su billete es de " << billete <<" euros.";
	cout <<endl << endl <<endl << endl;
	
	
	
	cout << " -- Gracias por volar con nosotros --";
	cout <<endl << endl;
	
	return 0;
}
