#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main () {
	
	const int FILS = 3;
	const int COLS = 5;
	
	int matriz [FILS] [COLS] = {{10, 13, 22, -7, 11}, {24, 35, -27, 42, -2}, {23, 45, 12, 5, 2}};
	
	cout << endl << "- Primera Matriz" << endl;
	int matriz_final [FILS] [COLS];
	
	for (int filas = 0; filas < FILS; filas ++) {
		
		for (int columnas = 0; columnas < COLS; columnas ++) {
			
			cout << setw(4) << matriz [filas] [columnas] << " ";
			matriz_final [filas] [columnas] = 0;
		}
		cout << endl;
		
	}
	
	cout << endl << endl;
	

	int media = 0,  contador = 0;
	
	for (int filas = 0; filas < FILS; filas ++) {
		
		for (int columnas = 0; columnas < COLS; columnas ++) {
			
			if (matriz [filas] [columnas] < 0) {
				
				for (int filas_aux = filas - 1; filas_aux <= filas + 1; filas_aux ++) {
					
					for (int columnas_aux = columnas - 1; columnas_aux <= columnas + 1; columnas_aux ++) {
						
						if (matriz [filas_aux] [columnas_aux] > 0) {
							
							media = media + matriz [filas_aux] [columnas_aux];
							contador ++;
						}
					}
					
				}
				
				matriz_final [filas] [columnas] = media / contador;
				media = 0;
				contador = 0;
				
			}
			
		}
		
	}
	
	for (int filas = 0; filas < FILS; filas ++) {
		
		for (int columnas = 0; columnas < COLS; columnas ++) {
			
			if (matriz_final [filas] [columnas] == 0) {
				
				matriz_final [filas] [columnas] = matriz [filas] [columnas]; 
			};
			
		}
	
		
	}
	
	cout << endl << "- Segunda Matriz" << endl;
	
	for (int filas = 0; filas < FILS; filas ++) {
		
		for (int columnas = 0; columnas < COLS; columnas ++) {
			
			cout << setw(4) << matriz_final [filas] [columnas];
			
		}
		
		cout << endl;
	}
	
	
	
	
	
	return 0;
}
