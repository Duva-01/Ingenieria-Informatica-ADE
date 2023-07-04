/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	 El programa leerá una secuencia de reales representando temperaturas, 
	 hasta llegar al -1 y debe calcular la subsecuencia de números ordenada, 
	 de menor a mayor, de mayor longitud. El programa nos debe decir
	 la posición donde comienza la subsecuencia y su longitud.

		
		Entrada: - Temperaturas.
				
				
						 
		Salida:  - Posicion y longitud de subsecuencia.
				 		
	
*/
/***************************************************************************/

#include <iostream>

using namespace std;

int main() {
	
	// Variables
	
	double dato_1, dato_2 = 0;
	int  veces = 0,
		 posicion = 1,
		 posicion_2, 
		 longitud = 0, 
		 longitud_2 = 0;
	

	
	do {
		
		// Entrada de Datos
		
		cout << " - Introduzca un valor de temperatura [15,25]: ";
		cin >> dato_1;
		
		
		// Logica y Calculos
		
		
		veces ++;
		
		if (dato_1 >= dato_2) {
			longitud++;
		
		} 
		else {
			
			if (longitud > longitud_2) {
				
				longitud_2 = longitud;
				longitud = 1;
				posicion_2 = posicion;
				posicion = veces;
			} 
			
		}
			
		dato_2 = dato_1;
		
	} while (dato_1 >= 15 && dato_1 <= 25);
	
	
	
	// Salida de Datos
	
	
	cout << endl << endl
		  << "Mayor subsecuencia: ";
		cout << endl;
		  cout << "--> Posicion: " << posicion_2;
		cout << endl;
	cout << "--> Longitud: " << longitud_2
		  << endl;
			
	return 0;
}
