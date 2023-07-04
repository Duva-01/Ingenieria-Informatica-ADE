/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Cread un programa que lea los datos fiscales de una persona, reajuste su 
	renta bruto según el criterio que se indica posteriormente e imprima su 
	renta neta final.
		
		Entrada:  -Renta bruta
				  • Si la persona es un trabajador autónomo o no
				  • Si es pensionista o no
				  • Estado civil
				  • Renta bruta (total de ingresos obtenidos)
				  • Retención inicial
						 
		Salida:  - Renta neta final.
				 		
	
*/
/***************************************************************************/


#include <iostream>				// Se añaden los recursos de E/S.

using namespace std;

int main() {					// Programa Principal
	
	
	// Variables
	
	double autonomo, pensionista, renta_bruta;
	double renta_neta, retencion_inicial, estado_civil; 
	
	// Entrada de datos
	
	cout << endl;
	cout << "-- Para decir \"SI\" ponga un 1, para decir \"NO\" ponga un 0 --";
	cout << endl << endl;
	cout << "Eres un trabajador autonomo: "; cin >> autonomo;
	cout << endl;
	
	cout << "Eres un pensionista: "; cin >> pensionista;
	cout << endl;
	
	cout << "Estas casado: "; cin >> estado_civil;
	cout << endl;
	
	cout << "Cuanto es su renta bruta: "; cin >> renta_bruta;
	cout << endl;
	
	cout << "Cuanto es la retencion inicial: "; cin >> retencion_inicial;
	cout << endl;
	
	
	// Logica y Resultados
	
	if (autonomo == 1) {
		
		retencion_inicial = retencion_inicial + 3;
		renta_neta = renta_bruta - renta_bruta * retencion_inicial / 100;
		
		
		cout << "La renta neta final es de " << renta_neta;
		cout << endl << endl;
	}
	
	else {
		
		if (pensionista == 1) {
			
			retencion_inicial = retencion_inicial + 1;
			
		}
		
		else {
			
			retencion_inicial = retencion_inicial + 2;
			
			if (renta_bruta < 20000) {
				
			 retencion_inicial = retencion_inicial + 2;	
			}
			
			else if (estado_civil == 1){
				
			 if (renta_bruta > 20000) {
					
			  retencion_inicial = retencion_inicial + 2.5;
				}
			}
			
			else if (estado_civil == 0) {
				
				if (renta_bruta > 20000) {
					
			  retencion_inicial = retencion_inicial + 3;
				}
				
			}
		}
		
		renta_neta = renta_bruta - renta_bruta * retencion_inicial / 100;
		
	
		cout << "La renta neta final es de " << renta_neta;
		cout << endl << endl;
		
	}
	
	return 0;
}
