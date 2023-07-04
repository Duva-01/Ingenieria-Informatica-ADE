/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	En esta primera versión el programa empezará pidiendo la hora de inicio de 
	la carrera  y la distancia. Después, para cada corredor que llega a meta 
	se pide el número de dorsal y la hora de llegada. 
	Tras leer estos datos el programa mostrará el tiempo que ha empleado en 
	completar la carrera y su ritmo.
		
		Entrada: - Horas.
				 - Distancia
				 - Dorsal.
				
				
						 
		Salida:  - Tiempo.
				 - Ritmo.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S
#include <cmath>
#include <string>
using namespace std;


/***************************************************************************/
/***************************************************************************/

string funcionDif_Tiempo
				(int segundos_1, int minutos_1, int horas_1, 
				int segundos_2, int minutos_2, int horas_2) {
	
	
	int horas_final, minutos_final, segundos_final;	
	int tiempo_1, tiempo_2, tiempo_final;
	string tiempo_fin;	
	
	
	tiempo_1 = segundos_1 + (minutos_1*60)+ (horas_1 * 3600);
	tiempo_2 = segundos_2 + (minutos_2*60)+ (horas_2 * 3600);
	
	tiempo_final = tiempo_2 - tiempo_1;
	

	
	minutos_final = tiempo_final / 60;
	segundos_final = tiempo_final % 60;
	
	if (minutos_final >= 60) {
	
	do {
		
		minutos_final = minutos_final - 60;
		horas_final ++;
		
	}while (minutos_final >= 60);
	
	}
	
	tiempo_fin = to_string(horas_final) + ":" + to_string(minutos_final) + ":" 
				 + to_string(segundos_final);
				 
	return tiempo_fin;

}

/***************************************************************************/
/***************************************************************************/

double funcionKM_H 
	(int segundos_1, int minutos_1, int horas_1, 
	 int segundos_2, int minutos_2, int horas_2, double distancia) {
						
	double km_h;
	const double MIN_H = 0.0166667;
	const double SEG_H = 0.0002777;
	const double SEG_MIN = 0.0166667;
	
	int tiempo_1, tiempo_2, tiempo_final;
	int horas_final, minutos_final, segundos_final;
	
	
	
	tiempo_1 = segundos_1 + (minutos_1*60)+ (horas_1 * 3600);
	tiempo_2 = segundos_2 + (minutos_2*60)+ (horas_2 * 3600);
	
	tiempo_final = tiempo_2 - tiempo_1;
	

	minutos_final = tiempo_final / 60;
	segundos_final = tiempo_final % 60;
	
	if (minutos_final >= 60) {
	
	do {
		
		minutos_final = minutos_final - 60;
		horas_final ++;
		
	}while (minutos_final >= 60);
	
	}
						
	km_h = distancia/(horas_final + (minutos_final*MIN_H) + (segundos_final*SEG_H));				
						
					
	return km_h;					
						
}

/***************************************************************************/
/***************************************************************************/

double funcionKM_MIN 
	(int segundos_1, int minutos_1, int horas_1, 
	 int segundos_2, int minutos_2, int horas_2, double distancia) {
						
	double km_min;
	const double MIN_H = 0.0166667;
	const double SEG_H = 0.0002777;
	const double SEG_MIN = 0.0166667;
	
	int horas_final,  minutos_final,  segundos_final;
	int tiempo_1, tiempo_2, tiempo_final;
		
	
	
	tiempo_1 = segundos_1 + (minutos_1*60)+ (horas_1 * 3600);
	tiempo_2 = segundos_2 + (minutos_2*60)+ (horas_2 * 3600);
	
	tiempo_final = tiempo_2 - tiempo_1;
	

	minutos_final = tiempo_final / 60;
	segundos_final = tiempo_final % 60;
	
	if (minutos_final >= 60) {
	
	do {
		
		minutos_final = minutos_final - 60;
		horas_final ++;
		
	}while (minutos_final >= 60);
	
	}
						
	km_min= (horas_final*60 + (minutos_final) + (segundos_final*SEG_MIN))/distancia;				
						
					
	return km_min;					
						
}

/***************************************************************************/
/***************************************************************************/

int main() {					// Programa Principal
   
   
   // Variables
   
   int horas_1, minutos_1, segundos_1, tiempo_1, tiempo_2, tiempo_final;
   int horas_2, minutos_2, segundos_2, dorsal;
   int horas_final, minutos_final, segundos_final;
   double km_h, km_min;
   double distancia;
   string tiempo_fin;
  
	do {
	
	// Reseteo
	
	horas_1 = 0; horas_2 = 0; horas_final = 0; minutos_1 = 0; minutos_2 = 0;
	minutos_final = 0; segundos_1 = 0; segundos_2 = 0; segundos_final = 0;
	dorsal = 0; km_h = 0; km_min = 0; distancia = 0;
	
	cout <<endl;
	cout << "- Numero de Dorsal: "; cin >> dorsal;
	cout << endl;
	
	if (dorsal > 0) {
	
	// Entrada de datos
	
	cout <<endl;
	cout << "-- Hora de Entrada --";
	cout << endl << endl;
	cout << "- Introduzca las horas: "; cin>> horas_1;
	cout <<endl;
	cout << "- Introduzca los minutos: "; cin>> minutos_1;
	cout <<endl;
	cout << "- Introduzca los segundos: "; cin>> segundos_1;
	cout <<endl << endl;
	
	cout << "Introduzca los kms: "; cin>> distancia;
	cout <<endl << endl;
	
	
	
	
	cout << "-- Hora de Llegada --";
	cout << endl << endl;
	cout << "- Introduzca las horas: "; cin>> horas_2;
	cout <<endl;
	cout << "- Introduzca los minutos: "; cin>> minutos_2;
	cout <<endl;
	cout << "- Introduzca los segundos: "; cin>> segundos_2;
	cout <<endl << endl;
	
	// Calculos
	
	tiempo_fin = funcionDif_Tiempo  
	(segundos_1, minutos_1, horas_1, segundos_2, minutos_2, horas_2);
	
	
	km_h = funcionKM_H (segundos_1, minutos_1, horas_1, segundos_2, 
						minutos_2, horas_2, distancia);
	
	km_min = funcionKM_MIN (segundos_1, minutos_1, horas_1, segundos_2, 
							minutos_2, horas_2, distancia);
	
	
	// Salida de Datos
	
	cout << "-- Resultados --";
	cout << endl << endl;
	
	cout << "Tiempo empleado: " << tiempo_fin;
	cout << endl << endl;
	cout << "Ritmo (km/h): " << km_h;
	cout << endl<< endl;
	cout << "Ritmo (km/min): " << km_min;
	cout << endl<< endl;
	cout << "---------------------------";
	cout << endl<< endl;
	}
	
}while(dorsal>=0);



return 0;

}
	
