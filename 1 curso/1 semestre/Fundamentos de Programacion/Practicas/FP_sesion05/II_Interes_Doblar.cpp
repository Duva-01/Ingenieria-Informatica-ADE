/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
// 
// 
//	
/*  Realizad un programa que lea una cantidad capital y un inter�s interes 
	desde teclado y calcule en una variable total el dinero que se tendr� al 
	cabo de un a�o, aplicando la f�rmula:

		total = capital + (capital * (interes/100))
		
	- Supongamos que queremos modificar la variable original capital con el 
	nuevo valor de total. �Es posible hacerlo directamente en la expresi�n 
	de arriba?
	
	- No se podria ya que este afectaria a todo el programa y cambiaria el valor
	de todas las variables que estuviesen ligadas en el calculo del total.
	
	
	Ahora se trata de construir un programa para calcular cuantos a�os han de 
	pasar hasta llegar a doblar, como m�nimo, el capital inicial.


		
		Entrada: - Capital.
				 - Interes.
				 
				 
		Salida:  - A�os para doblar.		
	
*/
/***************************************************************************/

#include <iostream>			// Se a�aden los recursos de E/S.

using namespace std;

int main() {				// Programa Principal

	// Variables	
	
	double capital, interes, total;
	int  anos, aux; 
	
	
	
	// Entrada de datos
	
	cout <<endl;
	cout << "- Introduce el interes (%): "; cin>> interes;
	cout <<endl;
	cout << "- Introduce el capital: "; cin>> capital;
	cout <<endl;
	
	
	// C�lculos	
	
	anos = 0;
	aux = capital;
	if ((capital > 0) && (0 < interes <= 10)) {
		
		do {
			
			total = capital + (capital * (interes/100));
			anos ++;
			capital = total;
			
		}while (2*aux > total );
		
		// Salida de Datos //
		
		cout << "Se necesitan " << anos << " anos para doblar su capital.";
		cout << endl << endl;
	}
	
	else { cout << "No cumple con los requisitos";}
	
	return 0;
}
