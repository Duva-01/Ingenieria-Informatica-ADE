/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Dado un tiempo de entrada y un tiempo de salida, construya un programa que 
	calcule la tarifa final en euros a cobrar.
	Se acuerda la actualización de las tarifas de aparcamiento incorporando 
	un nuevo tramo (desde el minuto 661 hasta el 900 a un coste de 0.0270 euros 
	cada minuto) y subiendo el coste de la tarifa plana a 35 euros (aplicable 
	ahora desde el minuto 901).

		
		Entrada: - Tiempo de entrada y salida.
				 - Dinero.
				
						 
		Salida:  - Tiempo que puede estar.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;

int main() {					// Programa Principal
   
   
   // Variables

   int min_entrada, seg_entrada, minuto = 0, minuto_final;
   double dinero_entrada, dinero;
   
   const int TIEMPO_1 = 30;
   const int TIEMPO_2 = 90;
   const int TIEMPO_3 = 120;
   const int TIEMPO_4 = 660;
   const int TIEMPO_5 = 990;
   const int DIA = 1440;
   
   const double TARIFA_1 = 0.0412;
   const double TARIFA_2 = 0.0370;
   const double TARIFA_3 = 0.0311;
   const double TARIFA_4 = 0.0305;
   const double TARIFA_5 = 0.0270;
   const double TARIFA_6 = 35;

	// Entrada de Datos

   cout << endl;
   cout << "- Introduzca los minutos de entrada: ";
   cin >> min_entrada; cout << endl;
   
   cout << "- Introduzca los segundos de entrada: ";
   cin >> seg_entrada; cout << endl;
   
   cout << "- Introduzca el dinero disponible: ";
   cin >> dinero_entrada; cout << endl << endl;
   
   // Calculos y Logica
   
	dinero = dinero_entrada;
	
	if (dinero >= TARIFA_6) {
	
	cout << "--> Podra estar 24 h en el parking.";
	cout << endl << endl;
	
	return 0;

	}
	
	else {
	
		while (dinero > 0) {
			
			if (minuto < TIEMPO_1)
				dinero = dinero - TARIFA_1;
			
			else if (minuto < TIEMPO_2)
				dinero = dinero - TARIFA_2;
			
			else if (minuto < TIEMPO_3)
				dinero = dinero - TARIFA_3;
			
			else if (minuto < TIEMPO_4)
				dinero = dinero - TARIFA_4;
				
			else if (minuto < TIEMPO_5)
				dinero = dinero - TARIFA_5;
			
			if (minuto > TIEMPO_5) {
				minuto = TIEMPO_5;
				break;
			}
			
			minuto++;
		}
		
		if (dinero < 0) { minuto = minuto - 1;}
		
		minuto_final = minuto + min_entrada;
		
	}
	
	
	// Salida de Datos
	
	cout << endl << endl;
	cout << "--> Podra estar hasta:  " << minuto_final 
		 << " min : " << seg_entrada << "s.";
		 
	cout << endl << endl;
   
   return 0;  
}
