/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribid un programa que pida un valor de población y calcule cuántos 
	años (enteros) transcurrirán hasta que la población estimada sea mayor o 
	igual al valor dado.
		
		Entrada: - Poblacion.
				
						 
		Salida:  - Nº de años.
				 		
	
*/
/***************************************************************************/


#include <iostream>					// Se añaden los recursos de E/S


using namespace std;


int main () {						// Programa Principal
	
	
	// Variables
	
	double poblacion, poblacion_1, poblacion_total;
	int anos; 
	
	double const nacimiento_s = 1.87;
	double const muerto_s = 3.27;
	double const emi_s = 71.9;
	double const poblacion_china = 1406862401;
	
	double const SEG_ANO = 31536000;
	
	double const NACIMIENTOS_ANO = SEG_ANO / nacimiento_s;
	double const MUERTOS_ANO = SEG_ANO / muerto_s;
	double const EMIGRADOS_ANO = SEG_ANO / emi_s;
	
	// Entrada de datos
	
	cout << endl;
	cout << "Introduzca el valor de la poblacion (actual = 1.406.862.401): "; 
	cin >> poblacion;
	cout << endl << endl;
	poblacion_1 = 1406862401;
	
	
	// Logica y Calculos
	
	if (poblacion < poblacion_china) {cout << "- La poblacion no dismuniye";}
	 
	 else {
		
		poblacion_1 = poblacion_china;
		
		do {
			
			poblacion_1 = poblacion_1 + NACIMIENTOS_ANO;
			poblacion_1 = poblacion_1 - MUERTOS_ANO;
			poblacion_1 = poblacion_1 - EMIGRADOS_ANO;
			
			anos++;
			
			
		}while(poblacion_1 <= poblacion); 
		
		// Salida de Datos
			
		cout << "--> La poblacion alcanzara el objetivo en " << anos << " anos";
		
	}
	
	return 0;
}
