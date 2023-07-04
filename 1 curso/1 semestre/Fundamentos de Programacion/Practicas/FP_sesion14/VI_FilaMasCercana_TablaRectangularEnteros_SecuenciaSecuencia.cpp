/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Ampliar la clase TablaRectangularEnteros con un método que busque la fila de
	la matriz que más se parezca a un vector de enteros (clase SecuenciaEnteros) al
	que llamaremos referencia. El método devolverá el número de la fila.
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;


/***************************************************************************/

class SecuenciaNumeros {

private:

	static const int TAMANIO = 40; // Número de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

	
public:
	
	SecuenciaNumeros (): total_utilizados(0) {}
	
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

class TablaRectangularEnteros {
	
	private: 
	
		static const int MAX_FIL = 50; // "filas" disponibles
    	static const int MAX_COL = 40;

    	SecuenciaNumeros vector_privado[MAX_FIL];

    	// PRE: 0 <= filas_utilizadas <= MAX_FIL
    	// PRE: 0 <= cols_utilizadas <= MAX_COL
    
    	int filas_utilizadas;
    	int cols_utilizadas;
  
		
	public: 
	
		TablaRectangularEnteros (): filas_utilizadas(0), cols_utilizadas (0) {}
	
	void Setfilas_utilizadas (int contador) {
		
		filas_utilizadas = contador;
	}
	
	int Getfilas_utilizadas () {
		return filas_utilizadas;
	}
	
	
	void SetCols (int columnas) {
		
		cols_utilizadas = columnas;
	}
	
	int GetCols () {
		
		return cols_utilizadas;
	}

/***************************************************************************/	
	
	void Add (SecuenciaNumeros fila){
	
			vector_privado[filas_utilizadas] = fila;
			filas_utilizadas ++;
	}
	
	int Elemento (int fila, int columna){
		
		return ((vector_privado[fila]).Elemento(columna));
	}
	
	
	int FilaMasCercana (SecuenciaNumeros filas_comprobar, 
						SecuenciaNumeros vector_referencia) {
		
		const int MAX = 30;
		int fila, suma = 0;
		
		int diferencia [MAX];
		int que_fila [filas_comprobar.GetTotalUtilizados()];
		
		for (int n = 0; n < MAX; n ++)
			diferencia [n] = 0;
			
		for (int veces = 0; veces < filas_comprobar.GetTotalUtilizados(); veces ++) {
			
			fila = filas_comprobar.Elemento(veces);
			que_fila [veces] = fila;
			
			for (int columnas = 0; columnas < GetCols(); columnas ++){
				
				suma = suma + abs (Elemento(fila, columnas)
							- 	vector_referencia.Elemento(columnas));
				
				
			}
			diferencia [veces] = suma;
			suma = 0;
		}				
		
		int mas_cercano = 100000;
		int pos_cercano;
		
		for (int n = 0; n < filas_comprobar.GetTotalUtilizados(); n ++) {
			
			if (diferencia[n] < mas_cercano) {
				
				mas_cercano = diferencia[n];
				pos_cercano = que_fila [n];
			}
			
			
		}
		
		return pos_cercano;				
	}
};

/***************************************************************************/	


int main () {
	
	const int MAX = 30;
	
	int columnas, valor = 0;
	int aux_ref, aux_fils;
	char terminador;
	
	SecuenciaNumeros filas;
	TablaRectangularEnteros cuadro;
	
	cout << endl;
	cout << "- Introduzca el numero de columnas: "; cin >> columnas;
	
	cuadro.SetCols(columnas);
	
	while (terminador != '*') {
		
		cout << endl;
		cout << "--> Terminar? [*], para seguir [y]: "; cin >> terminador;
		cout << endl;
		
		if (terminador != '*') {
			
			cout << "- Secuencia: ";
			for (int n = 0; n != columnas; n ++) {
	
		 		cin >> valor;
			 	filas.Add(valor);
			 	
			}
			
		
			cuadro.Add(filas);
			filas.LimpiarFila();
		}
	}
	
	SecuenciaNumeros vector_referencia;
	cout << endl;
	cout << "- Introduzca el vector referencia [-1]: ";
	
	do {
		
		cin >> aux_ref;
		
		if (aux_ref != -1) {
			
			vector_referencia.Add(aux_ref);
		
		}
		
	}while(aux_ref != -1);
	
	
	SecuenciaNumeros filas_comprobar;
	cout << endl;
	cout << "- Introduzca las filas a comprobar [-1]: ";
	
	do {
		
		cin >> aux_fils;
		
		if (aux_fils != -1) {
			
			filas_comprobar.Add(aux_fils); 
			
		}
		
	}while(aux_fils != -1);
	
	int mas_cercano;
	
	mas_cercano = cuadro.FilaMasCercana (filas_comprobar, vector_referencia); 
	 
	cout << endl;
	cout << "--> La fila mas cercana es: "<< mas_cercano;
	cout << endl;
	
	return 0;
}
