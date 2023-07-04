/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribid una expresión lógica que sea verdadera si una variable de tipo 
	carácter llamada letra es una letra mayúscula y falso en otro caso.
	
	Escribid una expresión lógica que sea verdadera si una variable de tipo 
	entero llamada edad es mayor o igual que 18 y menor que 67.

	Escribid una expresión lógica que nos informe cuando un año es bisiesto. 
	Los años bisiestos son aquellos que o bien son divisibles por 4 pero no 
	por 100, o bien son divisibles por 400.	
	
	Escribid una expresión lógica que nos informe si el valor de una variable 
	double llamada distancia es menor que la constante LIMITE.	
	
	Usad una variable lógica que registre si el valor de una variable int es 
	menor que otra, otra que informe si son iguales y otra que informe si es 
	mayor. Asegúrese que sólo una, y sólo una de las tres trendrá el valor true.
		
		
		Entrada: - Letra.
				 - Edad.
				 - Año
				 - Distancia
				 - Limite
				 - Num 1/2
				
				
						 
		Salida:  - V/F.
				 - Bisiesto/No Bisiesto
				 - Mayor/Menor
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;

int main () {					// Programa Principal
	
	// Variables (1)
	char letra_1;
	bool logic_1;
	
	// Entrada de datos(1)
	
	cout << endl;
	cout << "-- Si el resultado sale 1 = (True) y si sale 0 = (False) --";
	cout << endl << endl;
	cout << "- Introduzca una letra para comprobar si es mayuscula: "; cin>> letra_1;
	cout << endl << endl;
	
	
	//Salida de datos y logica(1)
	
	logic_1 = (letra_1 <= 90);

	cout << "--> " << logic_1;
	cout << endl << endl;
	

/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
	
	// Variables(2)
	
	int edad;
	bool logic_2;
	
	// Entrada de datos(2)
	
	cout << "- Introduzca una edad: "; cin>> edad;
	cout << endl;
	
	//Salida de datos y logica(2)
	
	logic_2 = (18 <= edad && edad <= 67);
	
	cout << "--> " << logic_2;
	cout << endl << endl;
	
	
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
	
	// Variables(3)
	
	int anio;
	bool logic_3;
	
	// Entrada de datos(3)
	
	cout << "- Introduzca el \"anio\": "; cin >> anio;
	cout << endl;
	
	//Salida de datos y logica(3)
	
	logic_3 = (anio%4 == 0 && anio%100 != 0) || (anio%400 == 0);
	
	cout << "--> " << logic_3;
	cout << endl << endl;
	
	
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
	
	// Variables(4)
	
	double distancia, limite;
	bool logic_4;
	
	// Entrada de datos(4)
	
	cout << "- Introduzca el valor de la distancia: "; cin >> distancia;
	cout << endl;
	cout << "- Introduzca la constante LIMITE: "; cin >> limite;
	cout << endl;
	cout << "Si la distancia es mayor que el LIMITE saldra 0, y sino saldra 1";
	cout << endl << endl;
	
	//Salida de datos y logica(4)
	
	logic_4 = (distancia < limite);
	
	cout << "--> " << logic_4;
	cout << endl << endl;
	
	
	
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/

	// Variables(5)
	
	int num_1, num_2;
	bool logic_5_1, logic_5_2, logic_5_3;
	
	
	// Entrada de datos(5)
	
	cout << "- Introduzca el primer numero: "; cin >> num_1;
	cout << endl;
	cout << "- Introduzca el segundo numero: "; cin >> num_2;
	cout << endl;
	
	//Salida de datos y logica(5)
	
	logic_5_1 = (num_1 > num_2);
	logic_5_2 = (num_1 < num_2);
	logic_5_3 = (num_1 == num_2);
	
	cout << "--> Si el numero 1 es mayor que el 2: " << logic_5_1;
	cout << endl << endl;
	cout << "--> Si el numero 2 es mayor que el 1: " << logic_5_2;
	cout << endl << endl;
	cout << "--> Si son iguales " << logic_5_3;
	cout << endl << endl;
	


return 0;
}
