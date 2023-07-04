/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
// 
// 
//	19.
/*  Calcular el n�mero de segundos que hay entre dos instantes del mismo d�a. 
	Cada instante se caracteriza por la hora (entre 0 y 23), minuto 
	(entre 0 y 59) y segundo (entre 0 y 59).
		
		Entrada: - Horas.
				 - Minutos.
				 - Segundos.
				 
		Salida:  - Segundos.
				 	
	
*/
/***************************************************************************/

#include <iostream>			// Se a�aden los recursos de E/S.
#include <cmath>			// Se a�aden los recursos matematicos.

using namespace std;
	
int main() {			// Programa Principal
		
	// Variables	
	
	int horas_1, minutos_1, segundos_1, total_1, total;
	int horas_2, minutos_2, segundos_2, total_2;
	
	// Entrada de datos
	
	cout <<endl;
	cout << "Introduzca las horas: "; cin>> horas_1;
	cout <<endl;
	cout << "Introduzca los minutos: "; cin>> minutos_1;
	cout <<endl;
	cout << "Introduzca los segundos: "; cin>> segundos_1;
	cout <<endl << endl;
	
	cout << "Introduzca las horas: "; cin>> horas_2;
	cout <<endl;
	cout << "Introduzca los minutos: "; cin>> minutos_2;
	cout <<endl;
	cout << "Introduzca los segundos: "; cin>> segundos_2;
	cout <<endl << endl;
	
	// C�lculos	
	
	total_1 = (horas_1*3600)+(minutos_1*60)+segundos_1;
	total_2 = (horas_2*3600)+(minutos_2*60)+segundos_2;
	
	total = abs(total_1-total_2);
	
	// Salida de datos
	
	cout << "--> Hay una diferencia de " << total << " s.";
	cout <<endl << endl;
	
	return 0;
	
	
}

