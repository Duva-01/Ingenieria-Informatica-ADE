/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construir un programa que lea la latitud y longitud (posición en el plano) 
	de dos puntos y calcule la distancia sobre plano y real entre los dos puntos.

		
		Entrada: - Latitud 1/2
				 - Longitud 1/2
								
						 
		Salida:  - Distancia 1/2 plano.
				 - Distancia real.
				 		
	
*/
/***************************************************************************/


	//Llamada de recursos

	#include <iostream>
	#include <cmath>
	#include <algorithm>

using namespace std;

int main () {			// Programa Principal
	
	// Variables
	
	double lat_1, lat_2, long_1, long_2, a, dist_plano, dist_r, c;
	double dif_altura, alt_1, alt_2, minimo;
	
	const double M_KM = 1000;
	const double R = 6372797.560856, RADIANES=0.0174533;
	
	// Entrada de datos
	
	
	cout << endl;
	cout << "- Introduzca la latitud del punto 1: "; cin >> lat_1;
	cout << endl;
	cout << "- Introduzca la longitud del punto 1: "; cin >> long_1;
	cout << endl;
	cout << "- Introduzca la altura del punto 1: "; cin >> alt_1;
	
	cout << endl << endl;
	
	cout << "- Introduzca la latitud del punto 2: "; cin >> lat_2;
	cout << endl;
	cout << "- Introduzca la longitud del punto 2: "; cin >> long_2;
	cout << endl;
	cout << "- Introduzca la altura del punto 2: "; cin >> alt_2;
	cout << endl << endl;
	
	// Logica y Cálculos
	
	
	
	lat_1 = lat_1*RADIANES;
	lat_2 = lat_2*RADIANES;
	long_1 = long_1*RADIANES;
	long_2 = long_2*RADIANES;
		
	a = pow(sin(0.5 * (lat_2 - lat_1)), 2) + cos(lat_1) * cos(lat_2) * 
         pow(sin(0.5 * (long_2 - long_1)), 2);
         
    
	
	if (1.0 < sqrt(a)) {
		
		minimo = 1.0;
	}
	
	else if (sqrt(a)< 1.0) {
		
		minimo = sqrt(a);	
	}
              
	c = 2 * asin(minimo);
	
	
	dist_plano = R * c / M_KM;
	
	dif_altura = abs(alt_1-alt_2);
	
	dist_r = sqrt(pow(dist_plano,2)+pow(dif_altura,2));
	
	// Salida de datos
	
	cout << "--> La distancia plano entre los puntos es: " << dist_plano;
	cout << endl << endl;
	cout << "--> La distancia real entre los dos puntos es: " << dist_r;
	cout << endl << endl;
	
	
	return 0;
	
}
