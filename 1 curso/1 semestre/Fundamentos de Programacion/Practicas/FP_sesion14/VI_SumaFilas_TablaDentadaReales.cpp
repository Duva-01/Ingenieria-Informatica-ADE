/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa que escriba en la salida estándar la suma de los 
	valores de cada grupo.
	
	Por ejemplo, en el caso anterior, debería escribir: 3.5, 5.0 y 9.9
	Implementar la clase TablaDentadaReales usando como dato privado una matriz
	clásica de datos double.
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;


/***************************************************************************/

class SecuenciaNumeros {

private:

	static const int TAMANIO = 40; // Número de casillas disponibles
	double vector_privado[TAMANIO];
	
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

class TablaDentadaReales {
	
	private: 
	
		static const int MAX_FIL = 50; // "filas" disponibles
    	static const int MAX_COL = 40;

    	SecuenciaNumeros vector_privado[MAX_FIL];

    	// PRE: 0 <= filas_utilizadas <= MAX_FIL
    	// PRE: 0 <= cols_utilizadas <= MAX_COL
    
    	int filas_utilizadas;
    	int cols_utilizadas[MAX_COL];
		int aux = 0;
		int pos = 0;
		
	public: 
	
		TablaDentadaReales (): filas_utilizadas(0) {}
	
	void Setfilas_utilizadas (int contador) {
		
		filas_utilizadas = contador;
	}
	
	int Getfilas_utilizadas () {
		return filas_utilizadas;
	}
	
	
	void SetCols (int columnas) {
		
		cols_utilizadas [aux] = columnas;
		aux ++;
	}
	
	int GetCols (int indice) {
		
		return cols_utilizadas [indice];
	}

/***************************************************************************/	
	
	void Add (SecuenciaNumeros fila){
	
			vector_privado[pos] = fila;
			pos++;
	}
	
	int Elemento (int fila, int columna){
		
		return ((vector_privado[fila]).Elemento(columna));
	}

	double SumatoriaFila (int indice) {
		
		double sumatoria;
		
		for (int n = 0; n < GetCols(indice); n++)
			sumatoria = sumatoria + vector_privado[indice].Elemento(n);
			
		return sumatoria;
	}
};


int main () {
	
	const int MAX = 30;
	double valor;
	int valor_aux;
	int contador = 0, contador_columnas = 0;
	
	double sumatoria [MAX];
	
	cout << endl;
	cout << "- Introduzca la secuencia de numeros [-1]: ";
	
	SecuenciaNumeros filas;
	TablaDentadaReales cuadro;
	
	do {
		
		cin >> valor;
		valor_aux = valor;
		
		if (valor != -1) {
	
		if (valor == valor_aux) {
			
			contador_columnas = valor;
			cuadro.SetCols(contador_columnas);
		
			while (contador_columnas != 0) {
	
				cin >> valor;
				valor_aux = valor;
		
				if (valor != valor_aux) {
			
					filas.Add(valor);
				}
				contador_columnas --;
			}	
			
		} 
		
		
		cuadro.Add(filas);
		filas.LimpiarFila();
		contador ++;
		
		}
	}while (valor != -1);
	
	cuadro.Setfilas_utilizadas(contador);
	
	for (int n = 0; n < cuadro.Getfilas_utilizadas(); n ++){
	
		sumatoria [n] = cuadro.SumatoriaFila(n);
		cout << endl;
		cout << "--> Para la secuencia "<<n<<": "<< sumatoria[n];
	
	}
	

	
	return 0;
}
