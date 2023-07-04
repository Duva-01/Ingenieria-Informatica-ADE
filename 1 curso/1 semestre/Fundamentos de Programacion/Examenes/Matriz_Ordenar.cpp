#include <iostream>
#include <cmath>

using namespace std;


int main () {
	
	const int COLS = 4;
	const int FILS = 4;
	
	int matriz [FILS][COLS] = {{12,29,9,20},{38,10,57,71},{120,84,19,1},{25,60,2,16}};
	
	cout << endl;
    cout << "- Primera matriz: ";
    cout << endl;

    for(int filas = 0; filas < FILS; filas ++) {

        for (int columnas = 0; columnas < COLS; columnas++){

            cout << matriz[filas][columnas] << " ";

        }

        cout << endl;

    }

    int vector_auxiliar [COLS];
    int aux;
    int matriz_aux [FILS][COLS];
    int iteraciones = 0;

        for (int columnas = 0; columnas < FILS; columnas ++) {

            for (int n = 0; n < COLS; n ++) {

                vector_auxiliar [n] = matriz [n] [columnas];
            }


            while (iteraciones != COLS) {

                for (int veces = 0; veces + 1 < COLS; veces ++) {

                    if (vector_auxiliar [veces] < vector_auxiliar [veces + 1]) {

                        aux = vector_auxiliar [veces];
                        vector_auxiliar [veces] = vector_auxiliar[veces + 1];
                        vector_auxiliar[veces + 1] = aux;
                    }
                }

                iteraciones ++;
            }

            for (int filas = 0; filas < COLS; filas ++) {


                matriz_aux [filas][columnas] = vector_auxiliar [filas];

            }
            iteraciones = 0;
        }


    cout << endl;
    cout << "- Segunda matriz: ";
    cout << endl;

    for(int filas = 0; filas < FILS; filas ++) {

        for (int columnas = 0; columnas < COLS; columnas++){

            cout << matriz_aux[filas][columnas] << " ";

        }

        cout << endl;

    }
    
    
    
	//-----------------------------------------------------------------------------------//
	
	
	
	int vector_auxiliar_2 [COLS];
    int aux_2;
    int iteraciones_2 = 0;
	int matriz_aux_2 [FILS][COLS];
	
	
	for (int filas = 0; filas < FILS; filas ++) {
		
		for (int columnas = 0; columnas < COLS; columnas++) {
			
			matriz_aux_2 [filas] [columnas] = matriz_aux [filas] [columnas];
			
		}
	}	
	
	//Cogemos el primer valor de cada fila
	
	for (int veces = 0; veces < FILS; veces ++)
		vector_auxiliar_2 [veces] = matriz_aux [0][veces];

	
//-----------------------------------------------------------------------------------//

		for (int filas = 0; filas < FILS; filas ++) {
			
			while (iteraciones_2 != COLS) {
			
				for (int veces = 0; veces + 1 < COLS; veces ++) {
				
					if (vector_auxiliar_2 [veces] > vector_auxiliar_2 [veces + 1]) {
						
						aux = vector_auxiliar [veces];
                        vector_auxiliar [veces] = vector_auxiliar[veces + 1];
                        vector_auxiliar[veces + 1] = aux;
                        
						for (int n = 0; n < FILS; n ++) {
							
							aux_2 = matriz_aux_2 [n] [veces + 1];
							matriz_aux_2 [n] [veces + 1] = matriz_aux_2 [n] [veces];
							matriz_aux_2 [n] [veces] = aux_2;
						}
						
					}
				}
			
				iteraciones_2 ++;
			}
			
			iteraciones_2 = 0;
		}
	
	
	
	cout << endl;
	cout << "- Tercera matriz: ";
	cout << endl;
	
	for(int filas = 0; filas < FILS; filas ++) {
		
		for (int columnas = 0; columnas < COLS; columnas++){
			
			cout << matriz_aux_2 [filas][columnas] << " ";
			
		}
		
		cout << endl;
		
	}
	
	
	
	return 0;
	
}
