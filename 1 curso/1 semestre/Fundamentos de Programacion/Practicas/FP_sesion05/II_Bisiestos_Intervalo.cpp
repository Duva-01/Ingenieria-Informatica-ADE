/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Programa que acepta el n�mero de un a�o e indique si es bisiesto o no.
	Un a�o es bisiesto si es m�ltiplo de cuatro, pero no de cien. 
	Excepci�n a la regla anterior son los m�ltiplos de cuatrocientos que 
	siempre son bisiestos.
		
		Entrada: - Poblacion.
				
						 
		Salida:  - N� de a�os.
				 		
	
*/
/***************************************************************************/

#include <iostream>

using namespace std;

int main() {
	
   	int	ano_1, ano_2;
   	bool es_bisiesto;


	// Entrada
	
	cout << endl;
	cout << "- Introduzca el primer ano: ";
	cin >> ano_1;
	cout << endl;
	cout << "- Introduzca el segundo ano: ";
	cin >> ano_2;
	cout << endl << endl;

	do {
		
		cout << endl;
		
	bool es_bisiesto = (((ano_1%4 == 0) && (ano_1%100 != 0)) || (ano_1%400 == 0));
	
	if (es_bisiesto)
		cout << "--> El ano " << ano_1 << " es bisiesto." << endl;
	else	
		cout << "--> El ano " << ano_1 << " no es bisiesto." << endl;
		
	cout << endl;
	
	ano_1 ++;
	
	} while (ano_1 != ano_2);


	return 0;
}
