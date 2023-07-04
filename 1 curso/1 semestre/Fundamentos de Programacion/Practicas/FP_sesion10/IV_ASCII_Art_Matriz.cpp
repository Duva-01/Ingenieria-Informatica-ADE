/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	 El programa pedirá el valor del centro de la circunferencia y el radio, y 
	 dibujará los puntos que configuran el círculo. A continuación pedirá las 
	 coordenadas que definen un rectángulo y dibujará el círculo (de nuevo) y el 
	 rectángulo en el mismo tablero.


		
		Entrada: - Radio de circunferencia.
				 - 4 esquinas del rectangulo.
				
				
						 
		Salida:  - Su representacion grafica.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;


int main () {
	
	const int MAX = 50;
	int radio_circunf, eje_x, eje_y;
	double distancia_euclidea;
	int j = 0, i = 0, h;
	char matriz [MAX][MAX];
	
	cout << endl;
	cout << "-- CIRCUNFERENCIA --";

	cout << endl << endl;
	cout << "- Introduzca el centro de la circunferencia [P(x,y)]: "; 
	cout << endl << endl;
	cout << "--> Eje X: "; cin >> eje_x;
	cout << endl;
	cout << "--> Eje Y: "; cin >> eje_y;
	cout << endl << endl;
	cout << "- Introduzca el radio de la circunferencia: "; cin >> radio_circunf;
	cout << endl;
	
/***************************************************************************/
	
	int izq_1_x, izq_2_x, drch_1_x, drch_2_x;
	int izq_1_y, izq_2_y, drch_1_y, drch_2_y;
		
	// Rectangulo
	
	cout << endl;
	cout << " *El rectangulo viene definido por 2 puntos (x,y)*";
	cout << endl << endl;
	cout << "--> Punto 1 (superior-izquierda)";
	cout << endl << endl;
	cout << "- Introduzca el valor de x: "; cin >> izq_1_x;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> izq_1_y;
	cout << endl << endl;
	
	cout << "--> Punto 2 (inferior-izquierda)";
	cout << endl << endl;
	cout << "- Introduzca el valor de x: "; cin >> izq_2_x;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> izq_2_y;
	cout << endl << endl;
	
	cout << "--> Punto 3 (superior-derecha)";
	cout << endl << endl;
	cout << "- Introduzca el valor de x: "; cin >> drch_1_x;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> drch_1_y;
	cout << endl << endl;
	
	cout << "--> Punto 4 (inferior-derecha)";
	cout << endl << endl;
	cout << "- Introduzca el valor de x: "; cin >> drch_2_x;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> drch_2_y;
	cout << endl << endl;
	
/***************************************************************************/
	
	// Limpieza
	
	for (int filas = 0; filas != MAX; filas ++) {
	
		for (int columnas = 0; columnas != MAX; columnas ++) {
	
		matriz[filas][columnas] = ' ';
		}
	
	}

/***************************************************************************/
	
	
	for (int filas = 0; filas != MAX; filas ++) {
		
		for (int columnas = 0; columnas != MAX; columnas ++){
			
			distancia_euclidea = sqrt(pow((eje_x - filas),2) 
								   + pow((eje_y - columnas),2));
		
			if (distancia_euclidea <= radio_circunf){
				
				matriz[filas][columnas] = '*';
			
			}
		}
		
	}
	
	
/***************************************************************************/


	for (int filas = izq_1_y ; filas != izq_2_y; filas ++) {
	
		for (int columnas = izq_1_x; columnas != drch_1_x; columnas ++) {
	
		matriz[filas][columnas] = '*';
		}
		cout << endl;
	}

/***************************************************************************/
	
	i = 0;
	j = 0;
	
	matriz[eje_y][eje_x] = '*';
	cout << endl;
	
	
	do {
		
		cout << matriz[i][j];
		
		if (j == 50 && i != 50) {
			
			cout << endl;
			j = 0;
			i ++;
			
		}
		
		j++;
		
	}while (i != MAX || j != MAX);
	
	return 0;
}
