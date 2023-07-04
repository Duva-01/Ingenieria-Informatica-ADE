/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Diseñe e implemente la clase MapaDistancias para representar este tipo 
	de datos. Use como base la clase TablaRectangular. Suponga que nunca se 
	trabajará con más de 50 ciudades.
	
	Proporcione métodos que doten a la clase de funcionalidad para resolver el 
	problema que se detalla a continuación.
	

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


class MapasDistancia {

private:

	static const int TAMANIO = 40; // Número de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

	
public:
	
	MapasDistancia (): total_utilizados(0) {}
	
	void SetTotalUtilizados (int contador) {
		
		total_utilizados = contador;
	}
	
	int GetTotalUtilizados () {
		return total_utilizados;
	}
	
	void Add (double nuevo){
		
		if (total_utilizados < TAMANIO ){
				
			vector_privado[total_utilizados] = nuevo;
			total_utilizados ++;
		}
	}
	
	void LimpiarFila () {
		
		total_utilizados = 0;
	}
	
	double Elemento (int n) {
		
		return vector_privado[n];	
	}
	

};

/***************************************************************************/

class TablaRectangular {
	
	private: 
	
		static const int MAX_FIL = 50; // "filas" disponibles
    	static const int MAX_COL = 40;

    	MapasDistancia vector_privado[MAX_FIL];

    	// PRE: 0 <= filas_utilizadas <= MAX_FIL
    	// PRE: 0 <= cols_utilizadas <= MAX_COL
    
    	int filas_utilizadas;
    	int cols_utilizadas;
		int pos = 0;
		int aux;
	
	public: 
	
		TablaRectangular (): filas_utilizadas(0), cols_utilizadas(0) {}
	
	void Setfilas_utilizadas (int n_ciudades) {
		
		filas_utilizadas = n_ciudades;
	}
	
	int Getfilas_utilizadas () {
		return filas_utilizadas;
	}
	
	void SetAux (int n_ciudades) {
		
		aux = n_ciudades;
	}
	
	int GetAux () {
		return aux;
	}
	
	void Setcols_utilizadas (int n_ciudades) {
		
		cols_utilizadas = n_ciudades;
	}
	
	int Getcols_utilizadas () {
		return cols_utilizadas;
	}
	
	void Add (MapasDistancia fila){
	
			vector_privado[pos] = fila;
			pos++;
	}
	
	int Elemento (int fila, int columna){
		
		return ((vector_privado[fila]).Elemento(columna));
	}

	int MasConexiones () {
		
		const int MAX = 50;
		int contador_distancias [MAX];
		int mayor = 0, pos_mayor = 0;
	
		for (int filas = 0; filas < Getfilas_utilizadas(); filas ++) {
			
			contador_distancias[filas] = 0;
			for (int columnas = 0; columnas < Getcols_utilizadas(); columnas ++) {
			
				if (Elemento(filas,columnas) != 0) {
					contador_distancias [filas] ++;
				} 		
			}
		
		}
	
		for (int filas = 0; filas < Getfilas_utilizadas(); filas ++) {
		
			if (contador_distancias [filas] > mayor){
				
				mayor = contador_distancias [filas];
				pos_mayor = filas; 
				
			}	
		
		}
		
		
		return pos_mayor;
		
	}	
	
	MapasDistancia Ciudad_Conexiones (int ciudad_conex) {
		
		MapasDistancia auxiliar;
		
	
		for (int filas = ciudad_conex; filas != ciudad_conex + 1; filas ++) {
		
			for (int columnas = 0; columnas != GetAux(); columnas ++) {
		
				if (Elemento(filas,columnas) != 0) {
				
					auxiliar.Add(columnas);
				}	
			
			}
		}
		
		
		
		return auxiliar;
	}
	
	void MinimaDistancia_2Ciudades (int ciudad_1, int ciudad_2) {
		
		const int MAX = 50;
		int condicion_1 [MAX];
		int condicion_2 [MAX];
		
		
		double suma_distancia [MAX];
		int posicion [MAX];
		int z = 0;
		
		int ciudad_final, distancia_final;
		
		for (int filas = 0; filas != GetAux(); filas ++) {
		
			if (filas != ciudad_1 && filas != ciudad_2) {
			
				for (int columnas = 0; columnas != GetAux(); columnas ++) {
		
					if (columnas == ciudad_1 ) {
		
						if (Elemento(filas,columnas) != 0) {condicion_1[filas]=1;}
					}
				
					if (columnas == ciudad_2){

						if (Elemento(filas,columnas) != 0) {condicion_2[filas]=1;}
					}
				}
			
			}
		}
	for (int n = 0; n < MAX; n ++) 
		suma_distancia [n] = 0;
		
		
	
	
	for (int n = 0; n < GetAux(); n ++) {
	
		if (condicion_1[n] == 1) {
		
			if (condicion_1[n] == condicion_2[n]) {
				
				suma_distancia[z] = Elemento(ciudad_1, n) + Elemento(ciudad_2, n);
				posicion[z] = n;
				z++;
				
			}
		}
	}
	
	for (int veces = 0; veces != GetAux(); veces++)  {
		
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
		
		
	}
	
};


/***************************************************************************/

int main () {
	
	int contador,  n_ciudades;
	double valor;
	
	MapasDistancia fila;
	TablaRectangular cuadro;
	
	cout << endl;
	cout << "Introduzca el numero de ciudades: "; cin >> n_ciudades;
	cout << endl;
	
	cuadro.Setfilas_utilizadas(n_ciudades);
	cuadro.Setcols_utilizadas(n_ciudades);

	for (int filas = 0; filas != n_ciudades; filas ++) {

		for (int columnas = 0; columnas != n_ciudades; columnas ++) {
			
			if (filas != columnas) {
			
				cout << endl;
				cout << "--> Distancia para ciudad C"<< filas 
					 << " hasta la ciudad C"<< columnas << ": ";
				cin >> valor;
			
				fila.Add(valor);
		
			}
			
			else {fila.Add(0);}	
		}
			
		cuadro.Add(fila);
		fila.LimpiarFila();
		
	}

	cout << endl;
	cout << "- Matriz orginal: " << endl;	
	cout << endl;
		
	for (int filas=0; filas < cuadro.Getfilas_utilizadas(); filas ++) {

		for (int columnas = 0; columnas < cuadro.Getcols_utilizadas(); columnas ++) {
			cout << " "<< cuadro.Elemento(filas,columnas);	
		}
		cout << endl;
	}

/***************************************************************************/

	int pos_mayor;
	
	pos_mayor = cuadro.MasConexiones();
	
	cout << endl;
	cout << "--> La ciudad con mas conexiones directas es la " << pos_mayor;
	cout << endl;
	
/***************************************************************************/

	MapasDistancia solucion_b;
	cuadro.SetAux(n_ciudades);
	
	int ciudad_conex;
	
	cout << endl << endl;
	cout << "- Introduzca la ciudad para ver sus conexiones directas: ";
	cin >> ciudad_conex;
		
	solucion_b = cuadro.Ciudad_Conexiones(ciudad_conex);
	
	for (int n = 0; n < solucion_b.GetTotalUtilizados(); n ++) {
		
		cout << endl;
		cout << "--> Conexion con la Ciudad " << solucion_b.Elemento(n);
		cout << endl;
	}

/***************************************************************************/
	
	int ciudad_1, ciudad_2;
	
	cout << endl;
	cout << "Introduzca la ciudad inicial: "; cin >> ciudad_1;
	cout << endl;
	cout << "Introduzca la ciudad final: "; cin >> ciudad_2;
	cout << endl;
	
	cuadro.MinimaDistancia_2Ciudades(ciudad_1, ciudad_2);
	
	return 0;
	}
