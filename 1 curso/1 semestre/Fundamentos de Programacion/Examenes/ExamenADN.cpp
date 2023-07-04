#include <iostream> 
#include <cmath>

using namespace std;

class SecuenciaADN {
	
	private: 
		
		static const int MAX = 20;
		char secuencia [MAX];
		
		int total_utilizados;
		
	public:
		
		SecuenciaADN (): total_utilizados(0) {}
		
		
		void SetTotalUtilizados (int num) {
			
			total_utilizados = num;
		}
		
		int TotalUtilizados () {
			
			return total_utilizados;
		}
	
		void Aniade (char nuevo, int indice){
		
			if (total_utilizados < MAX ){
				total_utilizados ++;
				
				for (int n = indice; n < total_utilizados; n ++) {
					secuencia [n + 1] = secuencia [n];
					
				}
				secuencia[indice] = nuevo;
			}
		}
		
		void Add (char nuevo) {
			
			if (total_utilizados < MAX ){
			
				secuencia[total_utilizados] = nuevo;
				total_utilizados ++;
			
			}
			
			
			
		}
		char Elemento (int indice) {
			
			return secuencia[indice];
		}
		
		void EliminarPalabra (int indice) {
			
			for (int n = TotalUtilizados(); n > indice; n --) {
				secuencia [n - 1] = secuencia [n];
			}
				
		}
		
		
		bool BuscarEnSecuencia (SecuenciaADN cadena_aux) {
			
			
			bool EstaDentro = false;
		
			int contador = 0, aux = 0;
			
			
			for (int n = 0; n < TotalUtilizados(); n ++) {
				
				
				
				if (contador == cadena_aux.TotalUtilizados()) {
					EstaDentro = true;
				}
				
				else if (cadena_aux.Elemento(aux) != secuencia [n]) {
					contador = 0;
					aux = 0;
				}
				
				if (cadena_aux.Elemento(aux) == secuencia [n]) {
					contador ++;
					aux ++;
				}
				
			
			}
			
			return EstaDentro;
				
		}
	
		SecuenciaADN SustituirSecuencia (SecuenciaADN cadena_aux, char letra_aux){
			
			SecuenciaADN cadena_final;
			int contador = 0, aux = 0;
			int pos;
			
			for (int n = 0; n < TotalUtilizados(); n ++) {
				
					cadena_final.secuencia[n] = secuencia [n];
			}
			
			for (int n = 0; n < TotalUtilizados(); n ++) {
				
				
				
				if (contador == cadena_aux.TotalUtilizados()) {
					
					pos = n - contador;
					
					for (int i = 0; i < contador; i++){	
						cadena_final.EliminarPalabra(contador - i);	
					}
					
					cadena_final.Aniade(letra_aux, pos);
					contador = 0;
					aux = 0;
				}
				
				else if (cadena_aux.Elemento(aux) != secuencia [n]) {
					contador = 0;
					aux = 0;
				}
				
				if (cadena_aux.Elemento(aux) == secuencia [n]) {
					contador ++;
					aux ++;
				}
				
			
			}
			
			cout << endl << endl;
			
			for (int n = 0; n < cadena_final.TotalUtilizados(); n ++)
				cout << cadena_final.secuencia[n] << " ";
			
			return cadena_final;
			
		}
};


//---------------------------------------------------------------------------//


int main () {
	
	
	char letra;
	bool repetir = false;
	SecuenciaADN cadena;
	
	
	do {
		
		cout << endl;
		cout << "- Introduzca la secuencia de ADN: ";
		
		do {
	 		
	 		repetir = false;
			cin >> letra;
			if (letra != '*') {cadena.Add(letra);}
	
		}while (letra != '*' && (letra == 'A' || letra == 'C' || letra == 'T' || letra == 'G'));

		if (letra != '*' && (letra != 'A' && letra != 'C' && letra != 'T' && letra != 'G')) {
			cout << endl << "- La secuencia no es valida" << endl;
			repetir = true;
			cadena.SetTotalUtilizados(0);
		}
		
	}while(repetir == true);
	
	
//--------------------------------------------------------------------------------------------------------//	
	
	SecuenciaADN cadena_buscar;
	
	cout << endl << "- Metodo buscar una secuencia: " << endl;
	
	do {
		
		cout << endl;
		cout << "- Introduzca la secuencia de ADN: ";
		
		do {
	 		
	 		repetir = false;
			cin >> letra;
			if (letra != '*') {cadena_buscar.Add(letra);}
	
		}while (letra != '*' && (letra == 'A' || letra == 'C' || letra == 'T' || letra == 'G'));

		if (letra != '*' && (letra != 'A' && letra != 'C' && letra != 'T' && letra != 'G')) {
			cout << endl << "- La secuencia no es valida" << endl;
			repetir = true;
			cadena_buscar.SetTotalUtilizados(0);
		}
		
	}while(repetir == true);
	
	
	cout << endl << "--> Primera Secuencia: ";
	for (int veces = 0; veces < cadena.TotalUtilizados(); veces ++) 
			cout << cadena.Elemento(veces);
			
	cout << endl << "--> Segunda Secuencia: ";
	for (int veces = 0; veces < cadena_buscar.TotalUtilizados(); veces ++) 
			cout << cadena_buscar.Elemento(veces);		
			
			
	bool EstaDentro;
	
	EstaDentro = cadena.BuscarEnSecuencia(cadena_buscar);
	
	cout << endl << "- Resultado: "<< EstaDentro << endl;
	
	
	SecuenciaADN cadena_aux;
	char letra_aux;
	cout << endl << "- Introduzca la letra a sustituir: "; cin >> letra_aux;
	
	cout << endl << "- Introduzca la secuencia a sustituir: "; 
	
	do {
	
		do {
	 		
	 		repetir = false;
			cin >> letra;
			if (letra != '*') {cadena_aux.Add(letra);}
	
		}while (letra != '*' && (letra == 'A' || letra == 'C' || letra == 'T' || letra == 'G'));

		if (letra != '*' && (letra != 'A' && letra != 'C' && letra != 'T' && letra != 'G')) {
			cout << endl << "- La secuencia no es valida" << endl;
			repetir = true;
			cadena_aux.SetTotalUtilizados(0);
		}
		
	}while(repetir == true);
	
	
	SecuenciaADN final = cadena.SustituirSecuencia(cadena_aux, letra_aux);
	
	
	
	return 0;
}
