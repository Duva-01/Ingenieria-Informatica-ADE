#include <iostream>
#include <cmath>

using namespace std;


int main () {
	
	const int MAX_LETRAS = 200;
	char secuencia [MAX_LETRAS]
	char letra;
	int total_utilizados = 0;
	
	cout <<  endl << "- Introduzca la secuencia: ";
	for (int n = 0; letra != '*' || n < MAX_LETRAS; n++) {

		cin >> letra;
		
		if (letra != '*'){
			secuencia [n] = letra; 
			total_utilizados ++;
		}
		
	}
	
	int pos;
	cout << endl << "- Introduzca la posicion a empezar: "; 
	
	do {
		cin >> pos;	
	}while (pos < 0);
	
	if (pos > total_utilizados) {pos = total_utilizados;}
	
	int numeros;
	
	cout << endl << "- Introduzca cuantos numeros reemplazar: "; 
	
	do {
		cin >> numeros;	
	}while (numeros < 0);
	
	
	char secuencia_sustituir [MAX_LETRAS]
	int total_utilizados_aux = 0;
		
	cout <<  endl << "- Introduzca la cadena para sustituir: ";
	for (int n = 0; letra != '*' || n < MAX_LETRAS; n++) {

		cin >> letra;
		
		if (letra != '*'){
			secuencia_sustituir [n] = letra; 
			total_utilizados_aux ++;
		}
		
	}
	
	for (int n = total_utilizados; n > pos + 2; n --) {
		
		secuencia [n - 1]  = secuencia [n];
	}
	
	for (int n = pos; n < num; n ++) {
		
		
		
		
	}
	
	
	return 0;
}
