/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa que lea desde teclado un carácter que indique el tipo 
	de radar (F para fijo y cualquier otra letra para móvil), la velocidad 
	captada, e imprima la velocidad imputada.


		
		Entrada: - Radar.
				 - Velocidad Captada.
				
						 
		Salida:  - Velocidad imputada.
				 		
	
*/
/***************************************************************************/


#include <iostream>				// Se añaden los recursos de E/S


using namespace std;

int main () {					// Programa Principal
	
	
	// Variables
	
	char radar;
	double velocidad_captada, velocidad_imputada;
	
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el tipo de radar (F=fijo) (Cualquier otra= Movil): ";
	cin >> radar;
	cout << endl;
	cout << "- Introduzca la velocidad del vehiculo (km/h): " ; 
	cin >> velocidad_captada;
	cout << endl;
	
	
	// Logica y Cálculos
	
	if (radar == 70) {
		
		if (velocidad_captada <= 100) {
			
			velocidad_imputada = velocidad_captada - 5;
		}
		
		else {
			
			velocidad_imputada = velocidad_captada-(velocidad_captada*0.05);
		}
		
	}
	
	if (radar != 70) {
		
		if (velocidad_captada <= 100) {
			
			velocidad_imputada = velocidad_captada - 7;
		}
		
		else {
			
			velocidad_imputada = velocidad_captada-(velocidad_captada*0.07);
		}
		
	}
	
	// Salida de datos
	
	cout << "--> La velocidad del conductor sera aproximadamente: " 
	<< velocidad_imputada << "km/h";
	cout << endl << endl;
	
	return 0;
	
}

