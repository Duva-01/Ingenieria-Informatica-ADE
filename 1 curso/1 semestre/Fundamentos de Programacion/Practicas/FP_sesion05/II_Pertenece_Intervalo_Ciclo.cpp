//***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa que lea e imprima los datos de un intervalo. 
	El programa mostrará en pantalla el mismo intervalo introducido.
		
		Entrada: - Intervalo
				 - Nº Ciclos
				 - Valor entero.
				
						 
		Salida:  - Intervalo.
				 - Pertenece o no al intervalo.
				 		
	
*/
/***************************************************************************/


#include <iostream>					// Se añaden los recursos de E/S

using namespace std;


int main() {						// Programa Principal
	
	
	// Variables
	
	int cota_izquierda, cota_derecha;
	char inter_1, inter_2;
	double valor, ciclo;
	
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
	
	cout << "Introduzca el numero de veces (ciclos): "; cin >> ciclo;
	cout << endl;

	
	// Logica y Resultados
	
	if (ciclo > 0) {
	
	do {
		
	cout << "- Introduzca un valor real: "; cin >> valor;

	
	if (inter_1 == '(' && inter_2 == ')') {
		
		if(valor > cota_izquierda && valor < cota_derecha) {
			
			cout << endl;
			cout << "--> Se encuentra dentro del intervalo";
			cout << endl << endl;
			
		}
		
		else {
			
			cout << endl;
			cout << "--> No se encuentra dentro del intervalo";
			cout << endl << endl;
		}
		
	}
	
	if (inter_1 == '[' && inter_2 == ')') {
		
		if(valor >= cota_izquierda && valor < cota_derecha) {
			
			cout << endl;
			cout << "--> Se encuentra dentro del intervalo";
			cout << endl << endl;
			
		}
		
		else {
			
			cout << endl;
			cout << "--> No se encuentra dentro del intervalo";
			cout << endl << endl;
		}
		
	}
	
	if (inter_1 == '(' && inter_2 == ']') {
		
		if(valor > cota_izquierda && valor <= cota_derecha) {
			
			cout << endl;
			cout << "--> Se encuentra dentro del intervalo";
			cout << endl << endl;
			
		}
		
		else {
			
			cout << endl;
			cout << "--> No se encuentra dentro del intervalo";
			cout << endl << endl;
		}
		
	}
	
	if (inter_1 == '[' && inter_2 == ']') {
		
		if(valor >= cota_izquierda && valor <= cota_derecha) {
			
			cout << endl;
			cout << "--> Se encuentra dentro del intervalo";
			cout << endl << endl;
			
		}
		
		else {
			cout << endl;
			cout << "--> No se encuentra dentro del intervalo";
			cout << endl << endl;
		}
		
	}
	
	ciclo--;		

	}while(ciclo > 0);
	
	}
	
	else { cout << "ERROR";}
		
		return 0;
		
		
	}
	
