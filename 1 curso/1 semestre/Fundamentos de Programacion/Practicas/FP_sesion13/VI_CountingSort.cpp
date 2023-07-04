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
		
		static const int LARGO = 27;
		char secuencia [LARGO];
		int secuencia_aux [27];
		
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
		
		// Counting Sort
		
		Secuencia CountingSort() {
			
			Secuencia auxiliar;
			
			// Variables 
			
			auxiliar.total_utilizados = total_utilizados;
			int contador = 0;
			int aux;
			int max = 0, pos_max;
			int min = 1000, pos_min;
			
			// Limpieza 
			
			for (int n = 0; n != 27; n ++)
				auxiliar.secuencia_aux[n] = 0;
				
		
			for (int letra = 'a'; letra != 'z'; letra ++){
		
				auxiliar.secuencia [contador] = letra;
				contador ++;
			}
			
/***************************************************************************/
			
			// Contar numero de palabras
			
			for (int veces = 0; veces != total_utilizados; veces ++){
				
				for (int i = 0; i < 27; i ++){
					
					if (secuencia[veces] == auxiliar.secuencia[i]){
						
						auxiliar.secuencia_aux [i] ++;
					}
				
				}
			} 
			
			// Buscamos posicion max y min
			
			bool contar = true;
			
			for (int n = 0; n != 27; n++){
				
				if (auxiliar.secuencia_aux[n] >= 1) { 
					pos_max = n;
				}
				
				if (contar) {
					contar = false;
					pos_min = n;
				}
			
			}
			
			if (pos_max < pos_min){
				aux = pos_max;
				pos_max = pos_min;
				pos_min = aux; 
			}
			
			// Mostramos su vector frecuencia
			
			cout << "--> Su vector de frecuencia: ";
			
			for (int j = pos_min; j < pos_max + 1; j++){
			
				if (auxiliar.secuencia_aux [j] >= 1){cout << " " << auxiliar.secuencia_aux [j];}
			}
		
			auxiliar.CountingSortEntre(pos_min, pos_max);
		
			
			return auxiliar;
		}

/***************************************************************************/
		
		// Ordenar una secuencia
		
		void CountingSortEntre (int pos_min, int pos_max){
			
			
			char copia [27];
			int contador = 0;
		
			
			for (int n = pos_min; n != pos_max + 1; n ++){
				
				for (int veces = secuencia_aux[n]; veces != 0; veces--){
				
					copia [contador] = secuencia [n];
					contador ++;
				}
			}
			
			total_utilizados = contador;
			
			for (int n = 0; n < total_utilizados; n ++)
				secuencia [n] = copia [n];
			
		}
		
/***************************************************************************/
		
		// Metodo para mostrar una secuencia privada
		
		void Mostrar () {
			
			for (int n = 0; n != total_utilizados; n ++)
				cout << " " << secuencia [n];
		}
};

/***************************************************************************/


int main () {			// Programa Principal
	
	
	// Variables
	
	char entrada = 0;
	int contador = -1;
	int posicion;
	
	Secuencia cadena;
	Secuencia cadena_final;
	
/***************************************************************************/
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca la secuencia (TERMINADOR '*'): "; 
	while (entrada != '*') {
	
	cin >> entrada;
	if (entrada != '*') {cadena.Add(entrada);}
	
	}
	
	cadena.TotalUtilizados();
	
/***************************************************************************/

	// Llamada a los metodos de la clase
	
	cadena_final = cadena.CountingSort();
	
	cout << endl << endl;
	cout << "--> Su vector ordenado quedaria: ";
	
	cadena_final.Mostrar();		
	
	return 0;
}


