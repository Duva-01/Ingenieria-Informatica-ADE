/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa que lea un valorn entero en u dato de tipo string y a 
	continuación convertirlo y asignarlo a un dato int., y que ahora estén
	claramente diferenciadas las etapas de entrada, cálculos y salidas.

		
		Entrada: - Valor entero (string).
				
								
						 
		Salida:  - Dato (string).
				 		
	
*/
/***************************************************************************/

#include <iostream>					// Se añaden los recursos de E/S
#include <string>
#include <cmath>

using namespace std;

int main() {						// Programa Principal

	// Variables //
    
    int valor_entero, n, entero, aux;
    
    string entrada_string, resultado;

	/****************************************/
				
	// Entrada de datos //

	cout << "- Introduzca un entero: ";
    cin>> valor_entero;

    
	/****************************************/
	
	
    if (valor_entero > 0) {
		
		
		// Calculos //
	
        entero = valor_entero;

        entrada_string = to_string(valor_entero); 
        n = entrada_string.length();
		
		
		/****************************************/
	
        if (n > 1) {

            do {
            	
            	// Calculos //
            	
                aux = entero / pow(10, n - 1);
                resultado = resultado + '|' + to_string(aux);
                entero = entero - aux * pow(10, n - 1) ;

                n--;
				
				/****************************************/
				
            } while (n > 0);

            

        } else {
        	
        	// Salida de datos //
        	
			
            resultado = '|' + entrada_string + '|';
            
            /****************************************/
			
        }
		
		// Salida de datos //
		
        cout << resultado;
        
		/****************************************/

    } else 
    
    // Salida de datos //

        cout << "El entero no es positivo";
        
	/****************************************/

    return 0;
}




