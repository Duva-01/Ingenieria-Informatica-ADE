/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	20.
/*  	En atletismo se expresa la rapidez de un atleta en términos de ritmo 
		(minutos y segundos por kilómetro) más que en unidades de velocidad 
		(kilómetros por hora).
		
		Escribid dos programas para convertir entre estas dos medidas:
		a) El primero leerá el ritmo (minutos y segundos, por separado) y 
		mostrará la velocidad (kilómetros por hora).
		b) El segundo leerá la velocidad (kilómetros por hora) y mostrará el 
		ritmo (minutos y segundos).
		
		Entrada: - Horas.
				 - Minutos.
				 - Segundos.
				 
		Salida:  - Segundos.
				 	
	
*/
/***************************************************************************/

#include <iostream>		// Se añaden los recursos de E/S.
#include <cmath>		// Se añaden los recursos matematicos.

using namespace std;

int main () {		// Programa Principal
	
	// Variables
	
	double ritmo_1, velocidad_1, minutos_1, segundos_1;
	
	// Entrada de datos
		
	cout << "Introduzca el ritmo:";
	cout << endl << endl;
	
	cout << "Minutos: "; cin >> minutos_1;
	cout << "Segundos: "; cin >> segundos_1;
	
	// Cálculos	
	
	minutos_1 = minutos_1*60;
	ritmo_1 = minutos_1+segundos_1;
	
	velocidad_1 = 3600/(60*ritmo_1);
	
	// Salida de datos
	
	cout << "La velocidad es de " << velocidad_1 << "km/h";
	
	/***************************************************************************/
								/* Programa 2 */
	/***************************************************************************/
	
	// Variables
	
	double velocidad_2, seg_2;
	int min_2;
	
	// Entrada de datos
	
	cout<< endl <<endl;
	cout << "Introduzca la velocidad en km/h: ";
	cin >> velocidad_2;
	
	// Cálculos	
	
	min_2 = (60 / velocidad_2);
	seg_2 = round((60 / velocidad_2 - min_2) * 60);
	
	// Salida de datos
	
	cout << endl
	<< "El ritmo es de " << min_2 << ":" << seg_2 << " min/km" << endl << endl;
	
	return 0;
	
	
	
	
}
