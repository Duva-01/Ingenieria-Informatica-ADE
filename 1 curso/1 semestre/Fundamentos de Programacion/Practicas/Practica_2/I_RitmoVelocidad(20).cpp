/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
// 
// 
//	20.
/*  	En atletismo se expresa la rapidez de un atleta en t�rminos de ritmo 
		(minutos y segundos por kil�metro) m�s que en unidades de velocidad 
		(kil�metros por hora).
		
		Escribid dos programas para convertir entre estas dos medidas:
		a) El primero leer� el ritmo (minutos y segundos, por separado) y 
		mostrar� la velocidad (kil�metros por hora).
		b) El segundo leer� la velocidad (kil�metros por hora) y mostrar� el 
		ritmo (minutos y segundos).
		
		Entrada: - Horas.
				 - Minutos.
				 - Segundos.
				 
		Salida:  - Segundos.
				 	
	
*/
/***************************************************************************/

#include <iostream>		// Se a�aden los recursos de E/S.
#include <cmath>		// Se a�aden los recursos matematicos.

using namespace std;

int main () {		// Programa Principal
	
	// Variables
	
	double ritmo_1, velocidad_1, minutos_1, segundos_1;
	
	// Entrada de datos
		
	cout << "Introduzca el ritmo:";
	cout << endl << endl;
	
	cout << "Minutos: "; cin >> minutos_1;
	cout << "Segundos: "; cin >> segundos_1;
	
	// C�lculos	
	
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
	
	// C�lculos	
	
	min_2 = (60 / velocidad_2);
	seg_2 = round((60 / velocidad_2 - min_2) * 60);
	
	// Salida de datos
	
	cout << endl
	<< "El ritmo es de " << min_2 << ":" << seg_2 << " min/km" << endl << endl;
	
	return 0;
	
	
	
	
}
