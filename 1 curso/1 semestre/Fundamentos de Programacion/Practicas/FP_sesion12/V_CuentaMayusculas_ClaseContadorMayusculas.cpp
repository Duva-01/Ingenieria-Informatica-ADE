/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Realizar un programa que vaya leyendo caracteres hasta que se encuentre un 
	punto ’.’. Queremos contar el número de veces que aparece cada mayúscula.
	
	Ampliar el programa para que muestre el número de veces que aparece cada 
	mayúscula en un dato string.

	

		
		Entrada: - String.
						 
		Salida:  - Cuantas mayusculas hay.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Añade las opciones E/S.
#include <string>			// Añade las opciones matematicas.

using namespace std;


class ContadorMayusculas {	// Clase Gaussiana
	
	// Variables
	
	private:
	
		int contador_letras [27] = {0};
	
	public:
			
	// Metodos
		
		void ContarLetras (string cadena) {
			
			int aux = 0;
			
			// Logica
			
			for (int pos= 0; pos != cadena.length(); pos++) {
				
				for (char letra = 'A'; letra < 'Z'; letra ++) {
				
					if (cadena.at(pos) == letra){
						contador_letras [aux] ++;
					}
					aux ++;
				}
				
				aux = 0;
			}
			
			// Salida de Datos
			
			aux = 0;
			for (char letra = 'A'; letra < 'Z'; letra ++) {
				
				cout << endl << "--> Para la letra "<< letra << ": " 
					 << contador_letras[aux];
				cout << endl;	
				aux ++;
	
			}
			
		}
		
		int CuantasHay (string cadena) {
			
			int contador = 0;
			bool stop = false;
			
			// Logica
			
			for (int pos= 0; pos != cadena.length(); pos++) {
				
				if (stop == false) {
				
					if(cadena.at(pos) > 65 && cadena.at(pos) < 90) {
						contador ++;
					}
				
					else if (cadena.at(pos) == '.') {stop = true;}
				}
			}
			
			return contador;
		}
	
	
};

int main () {			// Programa Principal
	
	// Variables
	
	string cadena;
	int contador_mayus;
	
	ContadorMayusculas secuencia;
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca la cadena: "; cin >> cadena;
	cout << endl;
	
	// Llamada de funcion
	
	contador_mayus = secuencia.CuantasHay(cadena);
	
	// Salida de Datos
	
	cout << "--> Se han encontrado un total de " << contador_mayus 
		 << " mayusculas antes del punto.";
	cout << endl;
	
	cout << endl << "---------------------------------" << endl;
	secuencia.ContarLetras(cadena);
	
	return 0;
}
