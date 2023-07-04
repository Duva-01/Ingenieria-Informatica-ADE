/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
/*  Es un programa que nos pide la longitud del radio, calculemos el 
	área del círculo y la longitud de la circunferencia, y nos muestre los 
	resultados en pantalla.  
	
	Entrada: 	- Radio
	Salida: 	- Longitud circunferencia = 2pir 
                - Area circulo = pir2
	
*/
/***************************************************************************/


#include <iostream>  	// Se añaden los recursos de E/S.
#include <math.h>		// Se añaden de los recursos matemáticos.

using namespace std;	

int main() {			// Programa Principal
	
	const double PI= 3.1415927;  	// Constante
	
	double radio, area_circulo, long_circunf;  // Variables
	
	// Entrada de datos
	
	cout<<"Introduce un radio(m): "; cin>> radio;
	
	// Cálculos
	
	area_circulo= pow(radio, 2)*3.1416;
	long_circunf= 2*3.1416*radio;
	
	// Salida de datos
	
	cout<< endl;
	cout<<"-->El area del circulo vale "<< area_circulo <<" m^2. \n";
	cout<<"-->La longitud de la circunferencia son "<< long_circunf <<" m.";
	cout<< endl << endl;
	
	return 0;
}
