/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Analizad cu�les deben ser los par�metros de estas funciones, y qu� valor 
	deben devolver.
	
	a) Una funci�n SumaHasta que calcule la suma de los primeros k valores 
	   de una progresi�n geom�trica. Cread un programa principal que 
	   llame a dicha funci�n.
	
	b) Cambiemos ahora la implementaci�n de la anterior funci�n SumaHasta. 
	   En vez de usar un bucle aplicamos la siguiente f�rmula, que calcula la 
	   sumatoria aplicando �nicamente cinco operaciones.
	
	c) A�adid una funci�n llamada SumaHastaInfinito para que calcular la suma
	   hasta infinito, seg�n la f�rmula.
	   
	d) Una funci�n MultiplicaHasta para que multiplique los k primeros elementos
 	   de la progresi�n, aplicando la f�rmula.
		
		
		
		Entrada: - a1
				 - Razon
				 - K
						 
		Salida:  - Sucesion.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Se a�aden los elementos de E/S.
#include <cmath>			// Se a�aden los elementos matematicos.

using namespace std;

// Funciones Secundarias

/***************************************************************************/
/***************************************************************************/

double funcionSumaHasta_a (int a1, int k, int razon) {

	int i = a1;
	double sucesion_1 = 0;
		
	while (a1 <= k) {
		
		sucesion_1 = sucesion_1 + i;
		i = i * razon;
		
		
		a1 ++;
	}		

	
	return sucesion_1;
	
}

/***************************************************************************/
/***************************************************************************/

double funcionSumaHasta_b (int a1, int k, int razon) {
	
	double sucesion_2 = 0;
		
	sucesion_2 = a1 * ((pow(razon, k)- 1) / (razon - 1));
		
	return sucesion_2;
	
}

/***************************************************************************/
/***************************************************************************/

double funcionSumaHastaInfinito (int a1, int k, int razon) {
	
	double sucesion_3 = 0;
		
	sucesion_3 = a1 / (1-razon);
		
	return sucesion_3;
	
}

/***************************************************************************/
/***************************************************************************/

double funcionMultiplicaHasta (int a1, int k, int razon) {
	
	double sucesion_4 = 0;
	int i = a1;
	
	while (a1 != k) { 
	
	i = i * razon;  
	a1 ++;
	
	}	
	
	sucesion_4 = sqrt(pow((a1*i),k));
		
	return sucesion_4;
	
}

/***************************************************************************/
/***************************************************************************/



int main () {			// Funcion Principal
	
	
	// Variables
	
	int razon, k, a1;
	double resultado_a, resultado_b, resultado_c, resultado_d;
	
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca a1: ";
	cin >> a1;
	
	cout << endl;
	cout << "- Introduzca hasta que numero desea realizar la sucesion: ";
	cin >> k;

	
	cout << endl;
	cout << "- Introduzca una ['r (-1, 1)'] para la sucesion: "; 
	cin >> razon;


	// Llamada de las Funciones
	
	resultado_a = funcionSumaHasta_a (a1, k, razon);
	
	resultado_b = funcionSumaHasta_b (a1, k, razon);
	
	// Para que este resultado de infinito, el unico valor disponible es r=1.
	// Donde el programa dara error y se cerrara inmediatamente.
	
	resultado_c = funcionSumaHastaInfinito (a1, k, razon);
	
	resultado_d = funcionMultiplicaHasta (a1, k, razon);
	
	
	// Salida de Datos
	
	cout << endl << endl;
	cout << " a) La sucesion vale: " << resultado_a;
	cout << endl << endl;
	
	cout << " b) La sucesion vale: " << resultado_b;
	cout << endl << endl;
	
	cout << " c) La sucesion vale: " << resultado_c;
	cout << endl << endl;
	
	cout << " d) La sucesion vale: " << resultado_d;
	cout << endl << endl;
	
	
	return 0;
		
}



