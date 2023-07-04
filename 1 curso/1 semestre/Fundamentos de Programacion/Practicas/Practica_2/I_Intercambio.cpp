/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	17.
/*  Construir un programa que haga lo siguiente:
		• Debe leer desde teclado dos variables caja_izda y caja_dcha.
		• A continuación debe intercambiar sus valores y finalmente, mostrarlos.

		
		Entrada: - Caja derecha.
				 - Caja izquierda.
				
				 
		Salida:  - Caja derecha.
				 - Caja izquierda.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Se añaden los recursos de E/S.

using namespace std;

int main() {			// Programa Principal
	
	
	// Variables	
	
	double caja_drcha, caja_izqd;
	
	// Entrada de datos
	
		cout <<endl;
	cout <<"- Introduca el dinero de la caja derecha: "; cin >> caja_drcha;
		cout <<endl;
	cout <<"- Introduca el dinero de la caja izquierda: "; cin >> caja_izqd;
		cout <<endl << endl;
	
	// Cálculos	
		
	caja_drcha= (caja_drcha*0) + caja_izqd;
	caja_izqd= (caja_izqd*0) + caja_drcha;
	
	// Salida de datos
	
	cout << " *Se intercambian las cajas*";
		cout <<endl << endl;
	cout << "--> La caja derecha vale: " << caja_drcha;
		cout <<endl << endl;
	cout << "--> La caja izquierda vale: " << caja_izqd;
		cout <<endl << endl;
		
	return 0;
}
