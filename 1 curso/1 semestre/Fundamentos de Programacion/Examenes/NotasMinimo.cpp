#include <iostream>
#include <cmath>


using namespace std;


int main () {
	
	double nota_inicial, nota_final, minimo;
	
	do {
	
		cout << "Introduzca la nota minima: "; cin >> minimo;
		if (minimo < 3 && minimo > 5) {cout << "Error minimo";}
		
	}while (minimo < 3 && minimo > 5);
	
	
	cout << endl << "Introduzca la secuencia de notas [Terminador -1]: ";
	
	do{
		
		cin >> nota_inicial;
		
		if (nota_inicial != -1) {
			
		
			if (nota_inicial < minimo) {
			
				nota_final = (nota_inicial / minimo) * 5;
				cout << nota_final << "  ";
			}
		
			else {
			
				nota_final = ((nota_inicial - minimo)/(10 - minimo))*5 + 5;
				cout << nota_final << "  ";
			}
		}
		
	}while(nota_inicial != -1);
	
	

	
	return 0;
}
