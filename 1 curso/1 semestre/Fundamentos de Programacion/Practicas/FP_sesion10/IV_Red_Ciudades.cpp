/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escriba un programa que lea el número de ciudades de la red, y las 
	distancias entre las ciudades (recuerde que 0 indica que entre dos ciudades 
	no existe un camino directo) y rellene adecuadamente la matriz de distancias.
	

	a) Obtener la ciudad (su índice) con mayor número de conexiones directas.
	En el ejemplo, sería la ciudad 3 con 4 conexiones.
	
	b) Dada una ciudad j, obtener las ciudades conectadas directamente con j.
	En el ejemplo, si consideramos la ciudad 4, vemos que está conectada 
	directamente con las ciudades 3 y 5.
	
	c) Dadas dos ciudades i y j para las cuales no existe un camino directo, 
	obtener aquella ciudad intermedia z que permita hacer el trayecto entre i y 
	j de la forma más económica posible. Es decir, se trata de encontrar una 
	ciudad z tal que d(i, z) + d(z, j) sea mínima (d(a, b) es la distancia entre
	las ciudades a y b). Si dicha ciudad no existiera, se indicará expresamente.

	d) Lea una serie de valores int que representan números de ciudades 
	(el terminador será el valor -1) e indique si todas las ciudades tienen 
	conexiones directas entre sí.

		
		Entrada: - Nº Secuencias.
				 - Secuencia caracteres.
				
		 
		Salida:  - Secuencia descodificada/reconstruida.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	int const MAX_CIUDADES = 50;
	int n_ciudades, n_ciudades_aux = 0, i = 0, j = 0, z = 0; 
	int ciudad_conex, contador_final, c_1, c_2, distancia_final, ciudad_final;
		
	double ciudades[MAX_CIUDADES][MAX_CIUDADES];
	int contador [MAX_CIUDADES];
	int condicion_1[MAX_CIUDADES];
	int condicion_2[MAX_CIUDADES];
	int suma_distancia[MAX_CIUDADES];
	int posicion [MAX_CIUDADES];
	int ciudad_comp[MAX_CIUDADES];
	
	
	do {
	
	cout << endl;
	cout << "- Introduzca el numero de ciudades: "; cin >> n_ciudades;

	}while (n_ciudades < 2 || n_ciudades > 50);
	
/***************************************************************************/	
	
	for (int filas = 0; filas != n_ciudades; filas ++) {
		
		
		
		for (int columnas = i; columnas != n_ciudades; columnas ++) {
			
			if (filas != columnas) {
			
			cout << endl;
			cout << "--> Distancia para ciudad C"<< filas 
				 << " hasta la ciudad C"<< columnas << ": ";
			cin >> ciudades[filas][columnas];
			
			ciudades[columnas][filas] = ciudades[filas][columnas];
		
			
			}
			
			else {ciudades[filas][columnas] = 0;}
			
		}
		
		
		i ++;
	}
	
/***************************************************************************/

	cout << endl << endl;
	
	for (int filas = 0; filas != n_ciudades; filas ++) {
		
		for (int columnas = 0; columnas != n_ciudades; columnas ++) {
			
			cout << ciudades[filas][columnas];
			cout << " ";
		}
	
	cout << endl;
	}
	
/***************************************************************************/
	
	for (int filas = 0; filas != n_ciudades; filas ++) {
		
		for (int columnas = 0; columnas != n_ciudades; columnas ++) {
		
		if (ciudades[filas][columnas] != 0) {contador[filas] ++;}
		
		}
		
	}
	
/***************************************************************************/

	for (int veces = 0; veces != n_ciudades; veces++) {
	
		if (veces != n_ciudades - 1){
	
			if (contador[veces] > contador[veces+1]) {
			
				contador_final = veces;
			}
		}	
	}
	
	cout << endl;
	cout << "--> La ciudad con mas conexiones directas es: C" << contador_final;
	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl << endl;

/***************************************************************************/

	cout << endl << endl;
	cout << "- Introduzca la ciudad para ver sus conexiones directas: ";
	cin >> ciudad_conex;
	
	for (int filas = ciudad_conex; filas != ciudad_conex + 1; filas ++) {
		
		for (int columnas = 0; columnas != n_ciudades; columnas ++) {
		
			if (ciudades[filas][columnas] != 0) {
				
				cout << endl;
				cout << "--> Conexion con C"<< columnas;
				cout << endl;
			}
			
		}
	}
	
	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl << endl;
/***************************************************************************/
	
	cout << "- Introduzca la primera ciudad: "; cin >> c_1;
	cout << endl;
	cout << "- Introduzca la segunda ciudad: "; cin >> c_2;
	cout << endl;
	
	for (int filas = 0; filas != n_ciudades; filas ++) {
		
		if (filas != c_1 && filas != c_2) {
			
			for (int columnas = 0; columnas != n_ciudades; columnas ++) {
		
				if (columnas == c_1 ) {
		
					if (ciudades [filas][columnas] != 0) {condicion_1[filas]=1;}
				}
				
				if (columnas == c_2){

					if (ciudades [filas][columnas] != 0) {condicion_2[filas]=1;}
				}
			}
			
		}
	}
	
	
	for (int n = 0; n != n_ciudades; n ++) {
	
		if (condicion_1[n] == 1) {
		
			if (condicion_1[n] == condicion_2[n]) {
				
				suma_distancia[z] = ciudades[c_1][n] + ciudades[c_2][n];
				posicion[z] = n;
				z++;
				
			}
		}
	}
	
	for (int veces = 0; veces != n_ciudades; veces++)  {
		
		if (veces == 0){
			distancia_final = suma_distancia[veces];
			ciudad_final = posicion[veces];
		}
		
		if (suma_distancia[veces] < suma_distancia[veces + 1]){
			
			distancia_final = suma_distancia[veces];
			ciudad_final = posicion[veces];
		}
		
	}
	
	
	cout << endl;
	cout << "- La ciudad entre medias es: C" << ciudad_final;
	cout << endl;
	cout << "--> Distancia: " << distancia_final ;
	cout << endl;
				
	cout << endl;
	cout << "----------------------------------------------------";
	cout << endl << endl;
	
/***************************************************************************/
	
	
	return 0;
	}
