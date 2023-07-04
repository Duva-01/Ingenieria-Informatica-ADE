/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	
/*  Calcular el número de segundos que hay entre dos instantes del mismo día. 
	Cada instante se caracteriza por la hora (entre 0 y 23), minuto 
	(entre 0 y 59) y segundo (entre 0 y 59).
		
		Entrada: - Horas.
				 - Minutos.
				 - Segundos.
				 
		Salida:  - Segundos.
				 - Tipo de dia.
				 	
	
*/
/***************************************************************************/

#include <iostream>			// Se añaden los recursos de E/S.
#include <cmath>			// Se añaden los recursos matematicos.

using namespace std;
	
int main() {			// Programa Principal
		
	// Variables	
	
	int horas_1, minutos_1, segundos_1, total_1, total;
	int horas_2, minutos_2, segundos_2, total_2, dias;
	
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
	
	
	
	// Cálculos	
	
	total_1 = (horas_1*3600)+(minutos_1*60)+segundos_1;
	total_2 = (horas_2*3600)+(minutos_2*60)+segundos_2;
	
	total = abs(total_1-total_2);
	
	
	if (total >= 86400 || abs(horas_1-horas_2)>= 24) {
		
	// Salida de datos
	
		cout << "--> Hay una diferencia de " << total << " s.";
		cout << endl;
		cout << "--> Son dias diferentes.";
		cout <<endl << endl;
	}
	
	else {
		
		cout << "--> Hay una diferencia de " << total << " s.";
		cout << endl;
		cout << "--> Son dias consecutivos.";
		cout <<endl << endl;
		
		
	}
	
	return 0;
	
}

