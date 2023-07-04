/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Añadir el método EliminaOcurrencias para eliminar todas las apariciones que
	hubiese de un determinado carácter a_borrar en la secuencia.
	
	Por ejemplo, después de eliminar el carácter ’o’ de la secuencia
	{’S’,’o’,’Y’,’ ’,’y’,’o’} ésta debe quedar: {’S’,’Y’,’ ’,’y’}.
	Para conseguir una buena solución aplicad el algoritmo que emplea dos 
	apuntadores.
	
		
		Entrada: - Secuencias caracteres.
				 - Caracter eliminar.
						 
		Salida:  - Secuencia nueva.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Añade las opciones E/S.
#include <cmath>			// Añade las opciones matematicas
#include <string>			// Añade los recursos de las string

using namespace std;


class Secuencia {			// Clase Secuencia
	
	private: 
		
		// Variables
		
		static const int LARGO = 30;
		char secuencia [LARGO];
		
		int total_utilizados;
		int posicion = 0;
		
	public:
		
	
		Secuencia () : total_utilizados(0){} 	// Constructor
		
/***************************************************************************/
		
		// Metodos Predeterminados
		
		int TotalUtilizados(int contador){
			
			return total_utilizados;
		}
		
		int Capacidad (){
			
			return LARGO;
		}
		
		void Add (char nuevo){
		
			if (total_utilizados < LARGO ){
				
				secuencia[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		
		void Modifica(int posicion, char nuevo) {
			
			if (posicion >= 0 && posicion < total_utilizados) {
				
				secuencia[posicion] = nuevo;
			}
		}
			
		char Elemento (int indice) {
			
			return secuencia[indice];
		}	

/***************************************************************************/
		
		// Metodos Incluidos
		
		// Eliminar Elemento
		
		void Elimina (int posicion) {
			
			int tope = total_utilizados - 1;
			
			for (int i = posicion; i < LARGO; i ++)
				secuencia [i] = secuencia [i + 1];
				
			
			total_utilizados --;
				
		}
		
		// Elimina un caracter de una secuencia
		
		void EliminaOcurrencias (char letra, int rango_izqd, int rango_drcha) {

			if (rango_drcha > total_utilizados){
			
				rango_drcha = total_utilizados;
			} 
			
			for (int i = rango_izqd; i < rango_drcha; i ++){

				if (secuencia [i] == letra){
					
					Elimina(i);
					i = rango_izqd;
				
				}	
				
			}	
		
			cout << "--> Su nueva secuencia es: ";
			for (int cont = 0; cont < total_utilizados; cont ++) {
		
			cout << secuencia [cont];
		
			}
		
			cout << endl << endl;
		
		
		}
		
};

/***************************************************************************/


int main () {				// Programa Principal
	
	
	// Variables
	
	char entrada;
	char letra;
	
	int rango_izqd, rango_drcha;
	int contador = -1;
	
	Secuencia cadena;
	Secuencia objeto;
	
/***************************************************************************/
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca una secuencia (TERMINADOR '*'): "; 
	while (entrada != '*') {
	
	cin >> entrada;
	if (entrada != '*') {cadena.Add(entrada);}
	
	}
	
	
		
	cout << endl;
	cout << "- Introduzca la letra a eliminar de la secuencia: "; 
	cin >> letra;
	cout << endl << endl;
	
	cout << "- Introduzca el rango izquierdo [izq,drch]: "; 
	cin >> rango_izqd; 
	cout << endl;
	cout << "- Introduzca el rango derecho [izq,drch]: ";
	cin >> rango_drcha;
	cout << endl << endl;

/***************************************************************************/

	// Llamada a los metodos de la clase
	
	cadena.TotalUtilizados(contador);
	cadena.EliminaOcurrencias(letra, rango_izqd, rango_drcha);
	

	
	return 0;
}


