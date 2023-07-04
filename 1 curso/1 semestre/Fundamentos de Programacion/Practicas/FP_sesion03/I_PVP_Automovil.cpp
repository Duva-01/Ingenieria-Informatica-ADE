/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Diseñar un algoritmo para obtener el precio final de un automóvil sabiendo 
	que el porcentaje de ganancia de este vendedor es del 20 % y el I.V.A. 
	aplicable es del 16 %.

		
		Entrada: - Precio coche.
				 
				
						 
		Salida:  - Precio coche real.
				 		
	
*/
/***************************************************************************/

#include <iostream> 		// Se añaden los recursos de E/S

using namespace std;

int main () {				// Programa Principal
	
	// Variables
	
	double precio_coche, precio_ganancias, precio_total;
	
	// Entrada de datos
	
	cout << endl;
	cout << "Introduzca el precio del coche($): "; cin >> precio_coche;
	cout << endl;
	
	// Cálculos

	precio_ganancias = precio_coche + (precio_coche*0.2);
	precio_total = (precio_ganancias*0.16)+ precio_ganancias;
	
	//Salida de datos
		
	cout << "El precio real de su coche es de " << precio_total << "$.";
	cout << endl << endl;
	
	return 0;
}
