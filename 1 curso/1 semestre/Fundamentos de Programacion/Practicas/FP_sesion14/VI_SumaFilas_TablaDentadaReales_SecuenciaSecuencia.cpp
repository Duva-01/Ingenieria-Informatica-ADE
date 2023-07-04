/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Reescribir el ejercicio 39 de esta misma Relación de Problemas, usando como 
	estructura de datos para almacenar la tabla dentada una secuencia de 
	secuencias de datos double.
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;


/***************************************************************************/

class SecuenciaReales {

private:

	static const int TAMANIO = 40; // Número de casillas disponibles
	double vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

	
public:
	
	SecuenciaReales (): total_utilizados(0) {}
	
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
	
	bool EsIgual (SecuenciaReales otra_secuencia) 
	{
		bool son_iguales = true; 
		
		if (total_utilizados != otra_secuencia.total_utilizados)
		
			son_iguales = false;
		
		else {
				
			bool sigo = true;
			int pos = 0;
			
			while (sigo && (pos < total_utilizados)) {
	
				if (vector_privado[pos]!=otra_secuencia.vector_privado[pos]) {
					sigo = false;
					son_iguales = false;
				}
				else
					pos++; 
			}
		}
			
		return (son_iguales);
	}
	

};

/***************************************************************************/

class TablaDentadaReales {
	
	private: 
	
		static const int MAX_FIL = 50; // "filas" disponibles
    	static const int MAX_COL = 40;

    	SecuenciaReales vector_privado[MAX_FIL];

    	// PRE: 0 <= filas_utilizadas <= MAX_FIL
    	// PRE: 0 <= cols_utilizadas <= MAX_COL
    
    	int filas_utilizadas;
    	int cols_utilizadas;
		
		
	public: 
	
		TablaDentadaReales (): filas_utilizadas(0), cols_utilizadas(0) {}
	
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
	
	int CapacidadFilas (void)
	{
		return (MAX_FIL);
	}


	int CapacidadColumnas (void)
	{
		return (MAX_COL);
	}


	int FilasUtilizadas (void)
	{
		return (filas_utilizadas);
	}

	int ColumnasUtilizadas (void)
	{
		return (cols_utilizadas);
	}

/*****************************************************************/
	
	SecuenciaReales Fila (int indice_fila)
	{
		return (vector_privado[indice_fila]);
	}
	
	void Inserta (int num_fila, SecuenciaReales fila_nueva){
		
		int numero_columnas_fila_nueva = fila_nueva.GetTotalUtilizados();

		if ((filas_utilizadas < MAX_FIL) && 
			(numero_columnas_fila_nueva == cols_utilizadas) && 
			(0<=num_fila) && (num_fila <=filas_utilizadas)) {

			
			for (int fil=filas_utilizadas; fil>num_fila; fil--) 			
				vector_privado[fil]=vector_privado[fil-1];
			
			
			vector_privado[num_fila]=fila_nueva;	
			
			filas_utilizadas++;
		}
	}
	
	void Add (SecuenciaReales fila){
	
			vector_privado[filas_utilizadas] = fila;
			filas_utilizadas ++;
	}
	
	int Elemento (int fila, int columna){
		
		return ((vector_privado[fila]).Elemento(columna));
	}
	
	void Elimina (int num_fila){		
		
		if ((0<=num_fila) && (num_fila <=filas_utilizadas)) {
			
			for (int fil=num_fila; fil<filas_utilizadas-1; fil++) 
				vector_privado[fil]=vector_privado[fil+1];
			
			filas_utilizadas--; 
		}
	}
	
	bool EstaVacia () {
		
		return (filas_utilizadas == 0);
	}	
	
	
	bool EsIgual (TablaDentadaReales otra){
		
		bool son_iguales = true; 
		
		if ((filas_utilizadas != otra.FilasUtilizadas()) ||  
			 (cols_utilizadas != otra.ColumnasUtilizadas())){
			 		
			
			son_iguales = false;
		}
		
		else {
	
			int fil = 0;
			
			while (fil < filas_utilizadas && !son_iguales) {
	
				SecuenciaReales una_fila = Fila (fil);
				SecuenciaReales otra_fila = otra.Fila (fil);	
				
				if (una_fila.EsIgual(otra_fila)){fil++;}
					
				else{son_iguales = false;}	
			} 
					
		} 
	
		return (son_iguales);
	}
	
	void EliminaTodos (){ filas_utilizadas = 0;}
	
	double SumatoriaFila (int indice) {
		
		double sumatoria;
		
		for (int n = 0; n < GetCols(); n++)
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
	
	SecuenciaReales filas;
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
