/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Cree un programa que lea un número de horas, minutos y segundos.
	
	El programa creará los objetos instante_inial e instante_final y calculará
	el número de segundos que hay de diferencia entre ambos instantes. 
	
	A continuación creará un objeto instante_diferencia correspondiente a la 
	cantidad de horas, minutos y segundos de diferencia entre el instante final 
	y el inicial e imprimirá  en pantalla el valor de instante_diferencia. 

	El programa también imprimirá, por separadoo, el total de segundos y minutos 
	enteros que hay en instante_diferencia..

		
		Entrada: - µ
				 - s.
				 - Valor de x
						 
		Salida:  - Funcion: f(x).
				 - CDF(x)
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;


class Instante {
	
	private:
		
		int horas;
		int minutos;
		int segundos;
	
	public:
		
	// Metodos	
	
/***************************************************************************/
 	
	
	
		void tiempo_transcurrido (int horas_diferencia, int minutos_diferencia,
								  int segundos_diferencia) {
			
			horas = horas_diferencia;
			minutos = minutos_diferencia;
			segundos = segundos_diferencia;
			
			while (segundos >= 60) {
				
				segundos = segundos - 60;
				minutos ++;
			}
			
			while (minutos >= 60) {
				
				minutos = minutos - 60;
				horas ++;
			}
			
			cout << "----------------------------------------------";
			cout << endl << endl;
			
			minutos = minutos + horas*60;
			
			cout << endl;
			cout << "--> Tiempo transcurrido en minutos: " << minutos;
			cout << endl;
			
			segundos = segundos + minutos*60;
			
			cout << endl;
			cout << "--> Tiempo transcurrido en segundos: " << segundos;
			cout << endl;
			
		}
		
/***************************************************************************/
 	
	int tiempo_segundos (int segundos_diferencia_total, int n) {
		
		segundos = segundos_diferencia_total;
		minutos = 0;
		horas = 0;
		
		while (segundos >= 60) {
				
				segundos = segundos - 60;
				minutos ++;
			}
		
		while (minutos >= 60) {
				
				minutos = minutos - 60;
				horas ++;
			}
			
		if ( n <= 2) {
		
			cout << endl;
			cout << " * Tiempo Diferencia => " << horas << ":" 
			 	 << minutos <<":" <<segundos << endl;
		}	 
		
		if (n == 2) {return horas;}
		if (n == 3) {return minutos;}
		if (n == 4) {return segundos;}
	}
	
/***************************************************************************/

	int segundos_totales (int horas_entrada, int minutos_entrada, 
					 	  int segundos_entrada, int horas_salida, 
					 	  int minutos_salida, int segundos_salida,
						  int n) {
		
		if (n == 0) {
		
			horas = horas_entrada;
			minutos = minutos_entrada;
			segundos = segundos_entrada;
		}
		
		if (n == 1){
		
			horas = horas_salida;
			minutos = minutos_salida;
			segundos = segundos_salida;
		}	
				 	
		while (segundos >= 60) {
				
			segundos = segundos - 60;
			minutos ++;
		}
			
		while (minutos >= 60) {
				
			minutos = minutos - 60;
			horas ++;
		}			 	
					 	
		segundos = segundos + minutos*60 + horas*3600;
			
		return segundos;		 	
	}
	
/***************************************************************************/

	int diferencia_segundos (int segundos_inicial, int segundos_final) {
		
		segundos = segundos_final - segundos_inicial;
		
		cout << endl << "- Diferencia en segundos: " << segundos << endl;	
		
		return segundos;
	}
	
};

/***************************************************************************/

int main () {
	
	int minutos_entrada, segundos_entrada, horas_entrada;
	int minutos_salida, segundos_salida, horas_salida;
	int segundos_1, segundos_2, segundos_diferencia_total, n = 0;
	int horas_diferencia, minutos_diferencia, segundos_diferencia;
	
	Instante instante_1;
	Instante instante_2;
	Instante instante_diferencia;
	
	cout << endl << "\t -- Instante Inicial --" << endl << endl;
	
	cout << "- Introduzca las horas: "; cin >> horas_entrada;
	cout << endl;
	cout << "- Introduzca los minutos: "; cin >> minutos_entrada;
	cout << endl;
	cout << "- Introduzca las segundos: "; cin >> segundos_entrada;
	cout << endl;
	
/***************************************************************************/

	cout << endl << "\t -- Instante Final --" << endl << endl;
	
	cout << "- Introduzca las horas: "; cin >> horas_salida;
	cout << endl;
	cout << "- Introduzca los minutos: "; cin >> minutos_salida;
	cout << endl;
	cout << "- Introduzca las segundos: "; cin >> segundos_salida;
	cout << endl;
	
/***************************************************************************/	
	
	segundos_1 = instante_1.segundos_totales(horas_entrada, minutos_entrada, 
								  			 segundos_entrada, horas_salida, 
											 minutos_salida, segundos_salida, n);
	n ++;
	
	segundos_2 = instante_2.segundos_totales(horas_entrada, minutos_entrada, 
								  			 segundos_entrada, horas_salida, 
											 minutos_salida, segundos_salida, n);
								  			 
	segundos_diferencia_total = instante_diferencia.diferencia_segundos(segundos_1, 
																  segundos_2);
	
							  
								  
	
	n ++;
	horas_diferencia = instante_diferencia.tiempo_segundos
						(segundos_diferencia_total, n);
						
	n ++;						  
	minutos_diferencia = instante_diferencia.tiempo_segundos
						(segundos_diferencia_total, n);
						
	n ++;
	segundos_diferencia = instante_diferencia.tiempo_segundos
						  (segundos_diferencia_total, n);
	
	instante_diferencia.tiempo_transcurrido(horas_diferencia, minutos_diferencia,
											segundos_diferencia);
	
							  
	return 0;
}
