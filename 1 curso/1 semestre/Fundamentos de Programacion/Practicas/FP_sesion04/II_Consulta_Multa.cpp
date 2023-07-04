/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escriba un programa que lea la velocidad del vehículo e imprima en pantalla 
	la sanción correspondiente (número de puntos a detraer y multa en euros).


		
		Entrada: - Velocidad.
				 
						 
		Salida:  - Sancion.
				 - Perdida de Puntos.
				 		
	
*/
/***************************************************************************/

#include <iostream> 		// Se añaden los recursos de E/S

using namespace std;		

int main () {				// Programa Principal

	// Variables	
	
	int velocidad, sancion, perdida_puntos;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduce la velocidad(km/h): "; cin >> velocidad;
	cout << endl;
	
	// Logica y Salida de Datos
	
	if (velocidad <= 120) {
		
		sancion = 0;
		perdida_puntos= 0;
		
		cout <<"--> "<<sancion<<"$";
		cout << endl;
		cout <<"--> "<<perdida_puntos<<" puntos";
	}
	
	else if (velocidad > 120) {
		
		if(velocidad > 120 && velocidad<=150) {
			
			sancion = 100;
			perdida_puntos= 0;
		
		cout <<"--> "<<sancion<<"$";
		cout << endl;
		cout <<"--> "<<perdida_puntos<<" puntos";
		}
		
		if(velocidad > 150 && velocidad<=170) {
			
			sancion = 300;
			perdida_puntos= 2;
		
		cout <<"--> "<<sancion<<"$";
		cout << endl;
		cout <<"--> "<<perdida_puntos<<" puntos";
		
		}
		
		if(velocidad > 170 && velocidad<=180) {
			
			sancion = 400;
			perdida_puntos= 4;
		
		cout <<"--> "<<sancion<<"$";
		cout << endl;
		cout <<"--> "<<perdida_puntos<<" puntos";
		
		}
		
		if(velocidad > 180 && velocidad<=190) {
			
			sancion = 500;
			perdida_puntos= 6;
		
		cout <<"--> "<<sancion<<"$";
		cout << endl;
		cout <<"--> "<<perdida_puntos<<" puntos";
		
		}
		
		if(velocidad > 190 && velocidad<9999999999) {
			
			sancion = 600;
			perdida_puntos= 6;
		
		cout <<"--> "<<sancion<<"$";
		cout << endl;
		cout <<"--> "<<perdida_puntos<<" puntos";
		
		}
		
	}
	
	return 0;
}
