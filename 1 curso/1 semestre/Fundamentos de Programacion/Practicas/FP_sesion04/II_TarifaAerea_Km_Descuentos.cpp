/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
//	
//  "Una compañía aérea establece el precio del billete como sigue: en primer 
//	lugar se fija una tarifa base de 150 euros, la misma para todos los 
//	destinos. A continuación se suman 10 céntimos por cada kilómetro de 
//	distancia al destino".
//	
//
/*  
		Cree un programa que lea el número de kilómetros al destino y calcule 
		el precio final	del billete.
		
		Entrada: - Nº de Kms.
				 - Puntos.
				 
				 
		Salida:  - Precio billete(descuento).
				 	
	
*/
/***************************************************************************/


#include <iostream>			// Se añaden los recursos de E/S

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
	
	// Cálculos	
	
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
