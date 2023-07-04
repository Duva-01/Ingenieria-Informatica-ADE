/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	 Dise�ar un programa para jugar a adivinar un n�mero. En cada jugada el 
	 jugador introducir� un valor y el el juego indicar� si el n�mero 
	 introducido por el jugador est� por encima o por debajo del n�mero 
	 introducido.


		Entrada: - Numero.
				
				
						 
		Salida:  - Si acierta o si no.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main () {
	
	const int MIN = 1;
	const int MAX = 100;
	const int NUM_VALORES = MAX-MIN + 1;
	char salida = 'y';
	int incognita, numero;
	
	time_t t;
	srand(time(&t));
	cout << "Instrucciones: ";
	cout << endl;
	cout << "- Para salir ponga [-1].";
	cout << endl;
	cout << "- Introduce numero hasta poner el numero correcto.";
	cout << endl << endl;
	
	
	bool salida_ok = true;
	

	do {
	
	if (salida_ok) {incognita = (rand() % NUM_VALORES) + MIN;}
	
	salida_ok = false;
	
	cout << "------------------------";
	cout << endl << endl;
	cout << "Introduce un numero: "; cin >> numero;
	cout << endl;
	
	if (numero > incognita && numero > 0) { 
	
	cout << "--> El numero introducido es superior."; 
	cout << endl;
	
	}
	
	else if (numero < incognita && numero > 0) { 
	
	cout << "--> El numero introducido es inferior."; 
	cout << endl;
	
	}
	
	if (numero == -1) {
		cout << endl;
		cout << "�Quiere volver a empezar? [y/n]: "; cin >> salida;
		cout << endl;
		
		if (salida == 'n') {return 0;}
		if (salida == 'y') {salida_ok = true;}
		
		
	}
	
	if (numero == incognita) {
	cout << "Has acertado";
	cout << endl << endl;
	
	cout << "�Quiere volver a empezar? [y/n]: "; cin >> salida;
		cout << endl;
		
		if (salida == 'n') {return 0;}
		if (salida == 'y') {salida_ok = true; numero = 0;}
	
	}
	
	
	
	}while(numero!=incognita);
	
	
	
	
	return 0;
}
