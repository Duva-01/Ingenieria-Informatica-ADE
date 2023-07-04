/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Sobre la clase SecuenciaCaracteres, defina un método que inserte otra 
	secuencia (otra) a partir de una posición (pos_insercion).
	
		
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
		
		Secuencia () : total_utilizados(0){}		// Constructor
		
/***************************************************************************/
		
		
		// Metodos Predeterminados
		
		int TotalUtilizados(){
			
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
		
		void Inserta(int pos_insercion, char valor_nuevo) {
			
			
			
			int aux = total_utilizados;

			while(pos_insercion != aux){
			
				
				secuencia [aux] =  secuencia [aux - 1];
				aux --;
			}
			
			secuencia [pos_insercion] = valor_nuevo;
	
				
		}

	void InsertaSecuenciaCaracteres (int pos_insercion, Secuencia cadena_2){
		
		Secuencia cadena_copiar;
		for (int veces = 0; veces != total_utilizados; veces ++)
			cadena_copiar.secuencia[veces] = secuencia [veces];
		
		cadena_copiar.total_utilizados = total_utilizados;
		
		if (pos_insercion > cadena_copiar.total_utilizados){
			
			pos_insercion = cadena_copiar.total_utilizados;
		} 
		
		int contador = 0;
		
		do {
			
			cadena_copiar.Inserta(pos_insercion, cadena_2.secuencia[contador]);
			contador ++;
			pos_insercion ++;
			cadena_copiar.total_utilizados ++;
			
		}while (cadena_2.total_utilizados != contador);
		
		cout << "--> La cadena resultante seria: ";
		for (int veces = 0; veces < cadena_copiar.total_utilizados; veces++)
				cout << cadena_copiar.secuencia [veces];
				
	}
	
		
};

/***************************************************************************/


int main () {			// Programa Principal
	
	
	// Variables
	
	char entrada = 0;
	int contador = -1;
	int posicion;
	
	Secuencia cadena_1;
	Secuencia cadena_2;

	
/***************************************************************************/
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca la primera secuencia (TERMINADOR '*'): "; 
	while (entrada != '*') {
	
	cin >> entrada;
	if (entrada != '*') {cadena_1.Add(entrada);}
	
	}
	
	entrada = 0;
	cout << endl;
	cout << "- Introduzca la segunda secuencia (TERMINADOR '*'): "; 
	while (entrada != '*') {
	
	cin >> entrada;
	if (entrada != '*') {cadena_2.Add(entrada);}
	
	}
	
	cout << endl << "Introduzca desde que posicion quiere anadir la secuencia: ";
	cin >> posicion;
	cout << endl;
	cadena_1.TotalUtilizados();
	cadena_2.TotalUtilizados();

	
/***************************************************************************/

	// Llamada a los metodos de la clase
	
	cadena_1.InsertaSecuenciaCaracteres(posicion, cadena_2);
	

	
	return 0;
}


