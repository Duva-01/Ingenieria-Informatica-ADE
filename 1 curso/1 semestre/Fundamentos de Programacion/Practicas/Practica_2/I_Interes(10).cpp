/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
// 
// 
//	10.
/*  Realizad un programa que lea una cantidad capital y un inter�s interes 
	desde teclado y calcule en una variable total el dinero que se tendr� al 
	cabo de un a�o, aplicando la f�rmula:

		total = capital + (capital * (interes/100))
		
	- Supongamos que queremos modificar la variable original capital con el 
	nuevo valor de total. �Es posible hacerlo directamente en la expresi�n 
	de arriba?
	
	- No se podria ya que este afectaria a todo el programa y cambiaria el valor
	de todas las variables que estuviesen ligadas en el calculo del total.

		
		Entrada: - Capital.
				 - Interes.
				 
		Salida:  - Total.		
	
*/
/***************************************************************************/

#include <iostream>			// Se a�aden los recursos de E/S.

using namespace std;

int main() {				// Programa Principal

	// Variables	
	
	double capital, interes, total;
	
	// Entrada de datos
	
	cout <<endl;
	cout << "- Introduce el interes (%): "; cin>> interes;
	cout <<endl;
	cout << "- Introduce el capital: "; cin>> capital;
	
	// C�lculos	
	
	total = capital + (capital * (interes/100));
	
	// Salida de datos
	
	cout <<endl << endl;
	cout <<"--> El valor total son " << total <<" euros.";
	cout <<endl << endl;
	
	return 0;
}
