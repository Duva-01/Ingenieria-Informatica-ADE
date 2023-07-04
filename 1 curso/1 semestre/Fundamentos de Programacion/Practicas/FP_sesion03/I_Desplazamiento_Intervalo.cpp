/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se pide construir un programa que lea dos enteros minimo y maximo que 
	determinar�n el intervalo. A continuaci�n el programa leer� un valor entero 
	desplazamiento. El programa sumar� al valor leido el desplazamiento y lo 
	convertir� en un entero dentro del intervalo.
		
		Entrada: - Intervalo
				 - Numero.
				 - Desplazamiento.
				 
		Salida:  - Numero desplazado.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Se a�aden los recursos de E/S

using namespace std;

int main () {				// Programa Principal

	// Variables

	int maximo, minimo, num_ent, desplazamiento, total;

	// Entrada de datos
	
	cout << endl << endl;
	cout <<"- Introduzca el minimo del intervalo: "; cin >> minimo;
	cout << endl;
	cout <<"- Introduzca el maximo del intervalo: "; cin >> maximo;
	cout << endl << endl;



	cout <<"- Introduzca el numero entero: "; cin >> num_ent;
	cout << endl;
	cout <<"- Introduzca el numero de desplazamientos: "; cin >> desplazamiento;
	cout << endl << endl;

	// C�lculos

	num_ent = num_ent + desplazamiento;



if (num_ent>maximo) {

	total = num_ent - maximo;
	num_ent = minimo + total - 1;

	
	// Salida de datos (1)

	cout <<"--> El numero ha sido desplazado hasta el " << num_ent;
	cout << endl << endl;
}

else {
	
	// Salida de datos (2)
	
	cout <<"--> El numero ha sido desplazado hasta el "<< num_ent;
	cout << endl << endl;
}

 return 0;
}


