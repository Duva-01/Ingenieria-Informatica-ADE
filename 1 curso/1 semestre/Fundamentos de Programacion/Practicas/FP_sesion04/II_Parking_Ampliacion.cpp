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
				
						 
		Salida:  - Tarifa final.
				 		
	
*/
/***************************************************************************/

#include <iostream>				// Se añaden los recursos de E/S

using namespace std;

int main() {					// Programa Principal
   
   
   // Variables
   
   int tiempo_1, tiempo_2, tiempo;
   double precio = 0;
   
 
    int horas_1, minutos_1;
	int horas_2, minutos_2;
	
	// Entrada de datos
	
	cout <<endl;
	cout << "Introduzca las horas: "; cin>> horas_1;
	cout <<endl;
	cout << "Introduzca los minutos: "; cin>> minutos_1;
	cout <<endl;
	
	
	cout << "Introduzca las horas: "; cin>> horas_2;
	cout <<endl;
	cout << "Introduzca los minutos: "; cin>> minutos_2;
	cout <<endl;
	
	
	tiempo_1 = horas_1*60 + minutos_1;
	tiempo_2 = horas_2*60 + minutos_2;
   
    tiempo = tiempo_2 - tiempo_1;
   
   // Logica y Resultados
   
   if (tiempo > 30){
      
      precio = precio + 30*0.0412;
      
      if (tiempo > 90) {
      
         precio = precio + 59*0.0370;
         
         if (tiempo > 120) {
          
            precio = precio + 29*0.0311;
            
            if (tiempo > 660){
               
               if (tiempo > 900) {
               	
               	precio = 35;
			   }
			   
			   else {precio = precio + tiempo * 0.0270;}
               
            } else {precio = precio + tiempo * 0.0305;}
            
         } else {precio = precio + tiempo * 0.0311;}
      
      } else {precio = precio + tiempo * 0.0370;}
      
   } else {precio = precio + tiempo * 0.0412;}
   
   if (tiempo > 1440) {
   	
   	cout << "Error";
   	cout << endl << endl;
   	
   	return 0;
   	
   }
   
   cout << "--> El precio del parking son " << precio << " euros.";
   cout << endl << endl;
   
   
   return 0;  
}
