/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Cree un programa que lea un nombre completo, y que despues sugiera un 
	nickname para este, segun el numero de palabras que quiera el usuario.
	
	

		
		Entrada: - Nombre.
				 - Numero de letras.
						 
		Salida:  - Nickname.
				 		
	
*/
/***************************************************************************/


#include <iostream>			// Añade las opciones E/S.
#include <cmath>			// Añade las opciones matematicas

using namespace std;

class Login {				// Clase 
	
	private:
		
		// Variables 
		
		int num_caracteres_a_coger;
	
	public:
		
		// Metodos
		
		Login (int n_letras_entrada):num_caracteres_a_coger (n_letras_entrada){}
	
		string Limpiar (string nombre_entrada) {
			
			string limpiar_local;
			char aux;
			
			for (int i = 0; i != nombre_entrada.length(); i ++){
				
				if (nombre_entrada.at(i) >= 65 && nombre_entrada.at(i) <= 90) {
					
					aux = nombre_entrada.at(i) + 32;
					limpiar_local = limpiar_local + aux;
				}
				
				else {limpiar_local = limpiar_local + nombre_entrada.at(i);}
			}
				
			return limpiar_local;
		
		}
		
/***************************************************************************/


		void Codificar (int n_letras_entrada, string nombre_entrada) {
			
			string nombre_local;
			int cont = 0;
			
			for (int pos = 0; pos < nombre_entrada.length(); pos ++) {
				
				if (cont < n_letras_entrada ) {
					
					nombre_local = nombre_local + nombre_entrada.at(pos);
					cont ++;
				}
				
				else if (nombre_entrada.at(pos) == ' ') {cont = 0;}
				
			}	
		
		cout << "Su string: " << nombre_local;
			
		}
		
};

/***************************************************************************/

int main () {			// Programa Principal
	
	// Variables
	
	string nombre_entrada;
	int n_letras_entrada;
	
	// Entrada de Datos
	
	cout << endl << "- Introduzca su nombre: "; 
	getline (cin, nombre_entrada);
	
	cout << endl;
	cout  << "- Introduzca el numero de letras a coger: "; 
	cin >> n_letras_entrada;
	
	// Llamada de Funciones
	
	Login nombre(n_letras_entrada);
	
	nombre_entrada = nombre.Limpiar (nombre_entrada);
	
	nombre.Codificar(n_letras_entrada, nombre_entrada);
	
	return 0;
}
