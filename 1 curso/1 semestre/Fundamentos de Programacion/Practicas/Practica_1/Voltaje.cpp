/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
/*  Es un programa que pide un valor de intensidad y resistencia, donde imprima
	 el voltaje correspondiente, según la Ley de Ohm:
		voltaje = (intensidad * resistencia) 
	
	Entrada: 	- Intensidad.
	 			- Resistencia.
	 			
	Salida:		- Voltaje.
	
*/
/***************************************************************************/


#include <iostream> 		// Se añaden los recursos de E/S

using namespace std;

int main () {				// Programa Principal
	
	 // Variables
	
		double intensidad, resistencia, voltaje;	
	
	 // Entrada de datos
	
		cout<< "Introduzca el valor de la intensidad: "; cin>> intensidad;
		cout<< "Introduzca el valor de la resistencia: "; cin>> resistencia;
	
	
	 // Cálculos
	
		voltaje= resistencia*intensidad;
		
	 // Salida de datos
	 
		cout<< endl;
		cout <<"-->El valor del voltaje es: "<<voltaje<<" voltios.";
		cout<< endl << endl;
	
	
	return 0;
}

