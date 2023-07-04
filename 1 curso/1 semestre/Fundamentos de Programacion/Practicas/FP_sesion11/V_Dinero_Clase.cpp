/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	 Hacer un programa que calcule el precio final de un producto a partir de 
	 su precio inicial, de un incremento fijo mensual y de un número de meses. 
	 El programa irá mostrando, mes a mes, el precio del producto.


		
		Entrada: - Euros.
				 - Centimos.
				
				
						 
		Salida:  - Dinero reajustado.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class Dinero{ 	// <- clase
 
 private:
	
	// Datos del objeto
	
	int euros = 0;
	int centimos = 0;

 public:
	
	// Funciones
	
	void ReajustarDinero (int euros_entrada, int centimos_entrada, int n) {
		
		cout << endl;
		cout << "\t -- Mes " << n << " --" << endl;
		
		if (n == 1){
			
			centimos = centimos_entrada;
			euros = euros_entrada;
		}
		
		while (centimos >= 100) {
	
			centimos = centimos - 100;
			euros ++;
		}
	}
	
	void Salida () {
	
		if (centimos < 10) {
			
			cout << "--> Su precio reajustado es: " 
						 << euros << ",0" << centimos;
		}
		else {
			cout << "--> Su precio reajustado es: " 
						 << euros << "," << centimos;
		}
	}
	
	void Incremento (int  incremento_euros, int incremento_centimos) {
		
		euros = euros + incremento_euros;
		centimos = centimos + incremento_centimos;
	}
};

/***************************************************************************/

int main () {			// Programa Principal
	
	// Variables
	
	Dinero producto;
	int euros_entrada, centimos_entrada;
	int incremento_euros, incremento_centimos, meses, n = 1;
	

	// Entrada de Datos y Filtro
	
	do {
		
		cout << endl;
		cout << "-- Precio de un producto --";
		cout << endl << endl;
		
		cout << "- Introduzca los euros: "; cin >> euros_entrada;
		cout << endl;
	
		cout << "- Introduzca los centimos: "; cin >> centimos_entrada;
		cout << endl;
		
		if (centimos_entrada < 0 ||euros_entrada < 0) {
			cout << "*El precio debe ser positivo*" << endl;
		}
		
	}while (centimos_entrada < 0 ||euros_entrada < 0);
	
	
	// Incremento
	
	cout << "-- Incremento --";
	cout << endl << endl;
	cout << "- Introduzca los euros: "; cin >> incremento_euros;
	cout << endl;
		
	cout << "- Introduzca los centimos: "; cin >> incremento_centimos;
	cout << endl;
		
	// Meses
	
	cout << "- Introduzca durante cuantos meses: "; cin >> meses;

/***************************************************************************/

	// Logica
	
	do {
		
		// Llamada de funciones
		
		producto.ReajustarDinero(euros_entrada, centimos_entrada, n);
		cout << endl;
		
		producto.Salida();
		
		producto.Incremento(incremento_euros, incremento_centimos);
		cout << endl;
		
		n++;
		meses --;
		
	}while (meses != 0);
	
		
	return 0;
}
