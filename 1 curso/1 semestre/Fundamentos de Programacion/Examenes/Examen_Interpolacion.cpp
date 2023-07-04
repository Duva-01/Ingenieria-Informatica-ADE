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
#include <iomanip>
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
		
		int TotalUtilizados(){
			
			return total_utilizados;
		}
		
		int Capacidad (){
			
			return LARGO;
		}
		
		void Add (int nuevo){
		
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
			
		int Elemento (int indice) {
			
			return secuencia[indice];
		}	

/***************************************************************************/
	 	int BusquedaInterpolacion (int buscado, int izda, int dcha) {
	 	
	 		int pos;
	 		bool encontrado = false;
	 		int posicion_buscado;
	 		
	 		int right = dcha, left = izda;
	 		
	 		do {
	 			
	 			pos = (((buscado - Elemento(left)) * (right - left))/(Elemento(right)-Elemento(left))) + left;
	 			
	 			if (Elemento(pos) == buscado){
	 				encontrado = true;
	 				posicion_buscado = pos;
	 				
				 }
				
				else if (Elemento(pos) < buscado) {
	 				
	 				right = pos - 1;
	 				
				 }
				 
				else {
	 				
	 				left = pos + 1;
	 				
				 }
				 
			
				
			 }while(!encontrado && izda <= dcha);
	 			
	 			
	 			
				 
	 		if (encontrado == false) {
	 			cout << endl;
	 			cout << "No se ha encontrado el elemento.";
	 			cout << endl;
	 			
	 			posicion_buscado = 0;
			 }
	 		
	 		return posicion_buscado;
	 		
	 	}

};

/***************************************************************************/


int main () {			// Programa Principal
	
	const int NUM_DATOS = 36;
	
	int datos [] = {1,3,5,7,9,10,11,12,13,15,17,19,20,21,23,25,27,29,30,33,35,
					37,38,39,41,43,46,47,49,51,53,55,57,58,59,60};
	
	SecuenciaEnteros v;
	
	for (int i = 0; i< NUM_DATOS; i++)
		v.Add(datos[i]);
		
	for (int i=0; i< v.TotalUtilizados(); i++)
		cout << "Elemento num. " << setw(3) << i 
			<< ": " << setw(3) << v.Elemento(i) << endl;
		
	cout << endl;
			
//------------------------------------------------------------------//
	
	int buscado, izda, dcha, posicion_buscado;
	
	cout << "Introduzca el numero a buscar: ", 
		cin >> buscado;
	cout << endl;
	
	cout << "Introduzca el minimo del intervalo: ",
		cin >> izda;
	cout << endl;
	
	cout << "Introduzca el maximo del intervalo: ",
		cin >> dcha;
	cout << endl;
	
		
		posicion_buscado = v.BusquedaInterpolacion(buscado, izda, dcha);
		
		
	cout << endl;
	cout << "La posicion del buscado es: " << posicion_buscado;
	cout << endl;
	
	
	
	return 0;
}


