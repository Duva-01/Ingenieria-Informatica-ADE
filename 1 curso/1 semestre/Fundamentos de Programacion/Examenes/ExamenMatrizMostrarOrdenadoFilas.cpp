#include <iostream>
#include <cmath>

using namespace std;


int main () {
	
	const int FILS = 4;
	const int COLS = 4;
	
	int matriz [FILS][COLS] = {{12,28,9,20},{38,33,57,71},{11,87,9,15},{25,60,1,2}};
	
	int elemento_mayor = 0, pos_mayor;
	int aux, iteraciones = 0;
	
	cout << endl << "- Matriz: " << endl;
	
	for (int filas = 0; filas <FILS; filas++) {
		
		for(int columnas = 0; columnas < COLS; columnas ++) {
			
			cout << matriz [filas] [columnas] << " ";
			if (matriz [filas] [columnas] > elemento_mayor) {
				
				pos_mayor = filas;
				elemento_mayor = matriz [filas] [columnas];
			}
		}
		
		 cout << endl;
	}	
	
	do {
	
		for (int n = 0; n + 1 < COLS ; n ++){
		
			if (matriz [pos_mayor] [n] > matriz [pos_mayor] [n + 1]) {
			
				aux = matriz [pos_mayor] [n];
				matriz [pos_mayor] [n] = matriz [pos_mayor] [n + 1];
				matriz [pos_mayor] [n + 1] = aux;
			
			}
		
		
		}
	
		iteraciones ++;
		
	}while(iteraciones != 2);
	cout << endl << "El resultado final es: ";
	
	for (int n = 0; n < COLS; n ++) 
		cout << matriz [pos_mayor] [n] << " ";
	
	
	return 0;
	
}
