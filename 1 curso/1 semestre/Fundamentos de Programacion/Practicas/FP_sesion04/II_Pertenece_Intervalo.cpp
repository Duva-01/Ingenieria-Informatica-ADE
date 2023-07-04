/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa que lea e imprima los datos de un intervalo. 
	El programa mostrará en pantalla el mismo intervalo introducido.
		
		Entrada: - Intervalo.
				
						 
		Salida:  - Intervalo.
				 		
	
*/
/***************************************************************************/


#include <iostream>					// Se añaden los recursos de E/S

using namespace std;


int main() {						// Programa Principal
	
	
	// Variables
	
	int cota_izquierda, cota_derecha;
	char inter_1, inter_2;
	double valor;
	
	// Entrada de datos
	
	cout << "Introduzca si el intervalo izquierdo es abierto \"(\" ";
	cout << "o cerrado \"[\": "; cin >> inter_1;
	cout << endl;
	
	cout << "Introduzca el valor real de la cota izqda: "; 
	cin >> cota_izquierda;
	cout << endl;
	
	cout << "Introduzca si el intervalo derecho es abierto \")\" ";
	cout << "o cerrado \"]\": "; cin >> inter_2;
	cout << endl;
	
	cout << "Introduzca el valor real de la cota drcha: "; 
	cin >> cota_derecha;
	cout << endl;
	
	
	cout << "El intervalo es: "<<inter_1<<cota_izquierda<<","
			<<cota_derecha<<inter_2;
	cout << endl << endl;
			
			
	cout << "Introduzca un valor real: "; cin >> valor;
	
	
	// Logica y Resultados
	
	if (inter_1 == '(' && inter_2 == ')') {
		
		if(valor > cota_izquierda && valor < cota_derecha) {
			
			cout << endl;
			cout << "Se encuentra dentro del intervalo";
			
		}
		
		else {
			
			cout << endl;
			cout << "No se encuentra dentro del intervalo";
		}
		
	}
	
	if (inter_1 == '[' && inter_2 == ')') {
		
		if(valor >= cota_izquierda && valor < cota_derecha) {
			
			cout << endl;
			cout << "Se encuentra dentro del intervalo";
			
		}
		
		else {
			
			cout << endl;
			cout << "No se encuentra dentro del intervalo";
		}
		
	}
	
	if (inter_1 == '(' && inter_2 == ']') {
		
		if(valor > cota_izquierda && valor <= cota_derecha) {
			
			cout << endl;
			cout << "Se encuentra dentro del intervalo";
			
		}
		
		else {
			
			cout << endl;
			cout << "No se encuentra dentro del intervalo";
		}
		
	}
	
	if (inter_1 == '[' && inter_2 == ']') {
		
		if(valor >= cota_izquierda && valor <= cota_derecha) {
			
			cout << endl;
			cout << "Se encuentra dentro del intervalo";
			
		}
		
		else {
			cout << endl;
			cout << "No se encuentra dentro del intervalo";
		}
		
	}
	
	
			
return 0;
	
}

