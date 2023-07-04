/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Sobre la clase SecuenciaEnteros, defina lo que sea necesario para calcular 
	el número de secuencias ascendientes del vector.
	Por ejemplo, en el vector {2,4,1,1,7,2,1} encontramos 4 secuencias 
	ascencentes, que son: {2,4}, {1,1,7}, {2}, {1}.
	
	
		
		Entrada: - Secuencias entera.
				 
						 
		Salida:  - Numero de secuencias ascendentes.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Añade las opciones E/S.
#include <cmath>			// Añade las opciones matematicas
#include <string>			// Añade los recursos de las string

using namespace std;


class SecuenciaEnteros {			// Clase Secuencia
	
	private: 
		
		// Variables
		
		static const int LARGO = 30;
		int secuencia [LARGO];
		int sec_asc = 0;
		
		int total_utilizados;
		int posicion = 0;
		
	public:
		
		SecuenciaEnteros () : total_utilizados(0){}		// Constructor
		
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
		
		// Numero de Secuencias Ascendentes
		
	int SecuenciasAscendentes () {
		
		int aux = 0, n = 0;
		bool contar = true;
		
		do {
			
			if (secuencia [aux + 1] > secuencia [aux]) {
				
				if (contar) {
					n++; 
					contar = false;
				}
				
			}
			
			else {contar = true;} 
		
		aux ++;	
		}while(total_utilizados != aux);
		
		
		
		return n;
	}
		
};

/***************************************************************************/


int main () {			// Programa Principal
	
	
	// Variables
	
	char entrada;	
	int contador = -1;
	int n_secuencias;
	
	SecuenciaEnteros cadena;

	
/***************************************************************************/
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca una secuencia (TERMINADOR '*'): "; 
	while (entrada != '*') {
	
	cin >> entrada;
	if (entrada != '*') {cadena.Add(entrada);}
	
	}
	

/***************************************************************************/

	// Llamada a los metodos de la clase
	
	cadena.TotalUtilizados(contador);
	n_secuencias = cadena.SecuenciasAscendentes ();
	
	// Salida de Datos
	
	cout << endl;
	cout << "--> Numero de Secuencias Ascendentes: " << n_secuencias;
	
	return 0;
}


