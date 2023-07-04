/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	16.
/*  Escriba un programa que calcule el consumo de gasolina. Pedirá la distancia
	recorrida (en kms), los litros de gasolina consumidos y los litros que 
	quedan en el depósito. El programa debe informar el consumo en km/litro, 
	los litros/100 km y cuantos kilómetros de autonomía le restan con ese nivel 
	de consumo.	
		
		Entrada: - Distancia.
				 - Litros consumidos.
				 - Litros que quedan.
				 
		Salida:  - Consumo.
				 - Litros/100km.
				 - Km autonomia.		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S.

using namespace std;

int main() {			 // Programa Principal

	// Variables
	
	double distancia, litros_consumidos, litros_restantes;
	
	// Entrada de datos
	
	cout <<endl;
	cout << " Introduzca la distancia (km): "; cin >> distancia;
	cout <<endl;
	cout << " Introduzca los litros consumidos (l): "; cin >> litros_consumidos;
	cout <<endl;
	cout << " Introduzca los litros restantes (l): "; cin >> litros_restantes;
	cout <<endl << endl;
	
	// Variables
	
	double consumo, litros_km, km_autonomia;
	
	// Cálculos	
	
	consumo= distancia/litros_consumidos;
	litros_km= (100*litros_consumidos)/distancia;
	km_autonomia= litros_restantes*consumo;
	
	// Salida de datos
	
	cout << "- Su consumo es de " << consumo << "km/l.";
		cout <<endl << endl;
	cout << "- Son  " << litros_km << "l cada 100km.";
		cout <<endl << endl;
	cout << "- Tiene una autonomia de " << km_autonomia << "km.";
		cout <<endl << endl;
	
	return 0;
}
