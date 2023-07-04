/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	18.
/*  Diseñar un algoritmo que calcule las horas, minutos y segundos dentro de su
	rango correspondiente. 
		
		Entrada: - Horas.
				 - Minutos.
				 - Segundos.
				 
		Salida:  - Dias.
				 - Horas.
				 - Minutos.	
				 - Segundos.	
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;

int main() {			 		// Programa Principal


	// Variables
	
	int dias = 0, horas = 0, minutos = 0, segundos = 0;
	
	// Entrada de datos
	
	cout << "Introduzca las horas: "; cin >> horas;
	
	cout << "Introduzca las minutos: ";cin >> minutos;
	
	cout << "Introduzca los segundos: "; cin >> segundos;
	
	
	// Cálculos	
		
	minutos = minutos + segundos / 60;
	segundos = segundos% 60;
	
	horas = horas + minutos / 60;
	minutos = minutos%60;
	
	dias += dias + horas / 24;
	horas = horas %24;
	
	// Salida de datos

	cout << endl;
	cout << "El tiempo total es de: ";
	cout << endl;
	cout <<"-->"<< dias << " dia/s, " <<endl;
	cout <<"-->"<< horas << " h " <<endl;
	cout <<"-->"<< minutos << " min " <<endl;
	cout <<"-->"<< segundos << " s"<<endl; 
	cout << endl;	  
	
	
	return 0;
}
