/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa que lea un n�mero indeterminado de caracteres 
	(la lectura termina cuando se introduce un *) y muestre el n�mero total 
	de apariciones cada letra.
	
	Despu�s indicar� cu�ntos caracteres (total) se han le�do, y de ellos, 
	cu�ntos son letras y cu�ntos son separadores.
	
	A continuaci�n mostrar� cu�ntas letras no han aparecido ninguna vez, y 
	cu�les son. Finalmente mostrar� cu�les son las letras m�s y menos 
	frecuentes y el n�mero de veces que aparecen (no tenga en cuenta para el 
	c�lculo de la letra menos frecuente aquellas que no aparecen ninguna vez).	
		
		Entrada: - Caracteres.
						 
		Salida:  - Caracteres si aparecen o no.
				 - Caracter mas frecuente y menos.
				 - Numero de caracteres introducidos.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Incluye las opciones de E/S.
#include <cmath>				// Incluye las opciones matematicas.

using namespace std;


int main () {					// Programa Principal

	
	// Variables
	
	int n = 0, pos = 0, aux, contador = 0, contador_aux = 0, contador_aux2 = 200;
	char letra, letra_aux = 'a', Mas_frecuente, Menos_frecuente;
	char caracteres [200];
 	
 	
 	// Entrada de Datos
 	
	cout << "-- Introduzca una serie de caracteres --"; 
	cout << endl;
	cout << "-- Para parar ponga un '*' --"; 
	cout << endl;
	
	do {
		
		cout << endl << endl;
		cin >>"- Aqui: " letra;
		if (letra != '*') {caracteres[n] = letra; n++;}
		
	}while (letra != '*');	
	
	/************************************************************************/
	
	// Limpieza
	
	aux = n;
	
	do {
	
	aux = aux + 1;
	caracteres[aux] = 0;
		
	}while (aux != 200);
	
	/************************************************************************/
	
	// Calculos
	
	cout << endl;
	
	do {
		
		do {
		
			if (caracteres[pos] == letra_aux || caracteres[pos] == letra_aux - 32){
			
			contador ++;
			};
	
			pos ++;
		
		}while (pos != 200);
		
		if (contador != 0) {
		
			cout << "--> La letra "<< letra_aux <<" aparece " << contador << " veces.";
			cout << endl << endl;
		
			if (contador > contador_aux) { 
			
				Mas_frecuente = letra_aux; 
				contador_aux = contador;
			}
			
			if (contador < contador_aux2) { 
			
				Menos_frecuente = letra_aux; 
				contador_aux2 = contador;
			}
		}	
			
		else if (contador == 0) {
			
			cout << "--> La letra " << letra_aux << " no aparece.";
			cout << endl << endl;
		}
		
		
		pos = 0;
		letra_aux ++;
		contador = 0;
		
		
		
	}while (letra_aux <= 'z');
	
	
	// Salida de Datos
	
	cout << endl;
	cout << "-- Se han introducido un total de "<< n - 1 << " caracteres. --";
	cout << endl << endl;
	
	cout << endl;
	cout << "- La letra mas frecuente es " << Mas_frecuente;
	cout << endl << endl;
	
	cout << endl;
	cout << "- La letra menos frecuente es " << Menos_frecuente;
	cout << endl << endl;
	
	
	return 0;
		
}


