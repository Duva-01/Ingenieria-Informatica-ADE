/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	a) Leer y almacenar en la matriz m un número indeterminado (no más de 20) 
	secuencias de (no más de 50) caracteres. Mostrar las secuencias que se van 
	a procesar.
	   
	b) Codificar mediante el método RLE. Guardar el resultado de la codificación 
	en otra matriz (m_codificada). Cada secuencia codificada se guarda en una 
	fila. Mostrar las secuencias codificadas.
	
	c) Usando la matriz m_codificada, descodificar las secuencias y almacenar el
	resultado en una tercera matriz (m_reconstruida). Cada secuencia 
	descodificada se guarda en una fila. Mostrar las secuencias reconstruidas.
	
	d) Comparar las secuencias guardadas en m y m_reconstruida e informar del
	resultado de la comparación.


		
		Entrada: - Nº Secuencias.
				 - Secuencia caracteres.
				
		 
		Salida:  - Secuencia descodificada/reconstruida.
				 		
	
*/
/***************************************************************************/

#include <iostream>

using namespace std;

int main () {
	
	int secuencias;
	int const MAX_SECUENCIAS = 20;
	int const MAX_LETRAS = 50;
	
	
	do {
	
		cout << endl;
		cout << "- Introduzca el numero de secuencias: "; cin >> secuencias;
		cout << endl;
	
	}while(secuencias < 0 || secuencias > MAX_SECUENCIAS);
	
/***************************************************************************/

	do {
	
	// Variables
		
	char matriz_normal [MAX_SECUENCIAS] [MAX_LETRAS];
	char matriz_codificada [MAX_SECUENCIAS] [MAX_LETRAS];
	double matriz_codificada_num [MAX_LETRAS];
	char matriz_reconstruida [MAX_SECUENCIAS] [MAX_LETRAS];
	
	int n = 0, i = -1, j = 0, contador = 1, contador_aux, 
		veces = 0, veces_aux, aux = 0;

/***************************************************************************/

	// Limpieza
	
	for (int filas = 0; filas != MAX_SECUENCIAS; filas ++) {
	
		for (int columnas = 0; columnas != MAX_LETRAS; columnas ++) {
	
		matriz_normal[filas][columnas] = ' ';
		matriz_codificada[filas][columnas] = ' ';
		matriz_codificada_num[columnas] = 0;
		
		}
	}
	
/***************************************************************************/
	
		cout << endl;
		cout << "-- Para terminar ponga un '*' --";
		cout << endl;
		cout << "- Introduzca una secuencias de caracteres: "; 
		cout << endl << endl <<  "--> ";
		
	do {
		
		i++;
		cin >> matriz_normal[n][i];
		veces ++;
		
	}while(i != 50 && matriz_normal[n][i] != '*');
	
/***************************************************************************/
	
	i = 0;
	veces_aux = veces;
	cout << endl << endl;
	
	while(veces != 0) {
		
		if (matriz_normal[n][i] == matriz_normal[n][i+1]) {contador ++;}	 
	
		else {
			
			matriz_codificada_num [aux] = contador;
			matriz_codificada[n][j] = matriz_normal[n][i];
			j++;
			aux ++;
			contador = 1;
			
		} 	
			
		i ++;
		veces --;	
	}

/***************************************************************************/
	

	j = 0;
	aux = 0;
	cout << "- Secuencia codificada: ";
	
	do {
		
		if (matriz_codificada[n][j] != '*') {
		
			if (matriz_codificada_num [aux] != 0){
				
				cout << matriz_codificada_num [aux];
			} 
			
			if (matriz_codificada[n][j] != ' ') {
				
				cout << matriz_codificada[n][j]; 
				cout << " ";
			}
		}
		
		aux ++;
		j++;
		veces ++;
		
	}while (veces_aux != veces);
	
/***************************************************************************/
	
	veces = 0;
	j = 0;
	aux = 0;
	
	cout << endl << endl;
	cout << "- Secuencia reconstruida: ";
	
	while(veces_aux != veces && matriz_codificada[n][j] != '*'){
		
		contador_aux = matriz_codificada_num [aux];
		
		do {
			
			cout << matriz_codificada[n][j];
			contador_aux --;	
			veces ++;
			
		}while (contador_aux != 0);
		
		aux ++;
		j++;
		
		
	}
	
	secuencias --;
	cout << endl << endl;
	cout << "--------------------------------------------";
	cout << endl << endl;
	
	
	}while(secuencias != 0);
	

		
	return 0;
}
