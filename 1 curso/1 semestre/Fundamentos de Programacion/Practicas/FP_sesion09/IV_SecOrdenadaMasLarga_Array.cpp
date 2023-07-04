/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	 En la versión anterior no se podíian guardar los valores leidos por lo 
	 que los cálculos se realizaban conforme se iban leyendo los datos. Ahora 
	 la secuencia de temperaturas se puede guardar en un array de datos double 
	 y los cálculos pueden realizarse posteriormente a la lectura. Establecer 
	 el tamaño máximo del vector en 100 casillas.

		
		Entrada: - Temperaturas.
				
				
						 
		Salida:  - Posicion y longitud de subsecuencia.
				 		
	
*/
/***************************************************************************/

#include <iostream>					// Incluye las opciones de E/S.

using namespace std;

int main() {						// Programa Principal
	
	// Variables
	
	double dato_1 [100] ;
	int  n = 0, veces = 0, j = 0,
		 
		 posicion = 1,
		 posicion_2, 
		 longitud = 0, 
		 longitud_2 = 0;
		 

		
	// Entrada de Datos
	
		do {
			
			if (dato_1[n] >= 15 && dato_1[n]<= 25) {n++;}
			
			cout << " - Introduzca un valor de temperatura [15,25]: ";
			cin >> dato_1[n];
				
		}while(dato_1[n] >= 15 && dato_1[n] <= 25);
		
	// Logica y Calculos
		
		do {

			veces ++;
			
			if (dato_1 [j] >= dato_1[j-1]) {longitud++;} 
			
			if (longitud > longitud_2 && (dato_1 [j] <= dato_1[j-1])) {
				
				longitud_2 = longitud;
				longitud = 1;
				posicion_2 = posicion;
				posicion = veces;
			} 	
		
			j ++;
		
		}while (j != n);
	
		if (longitud > longitud_2) {
				
				longitud_2 = longitud;
				longitud = 1;
				posicion_2 = posicion;
				posicion = veces;
		} 	
			
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
