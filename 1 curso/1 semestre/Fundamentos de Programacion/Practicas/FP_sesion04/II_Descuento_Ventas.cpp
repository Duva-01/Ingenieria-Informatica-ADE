/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construya un programa para calcular el importe total a facturar de un 
	pedido. El programa leerá el número de unidades vendidas y el precio de 
	venta de cada unidad.
		
		Entrada: - Unidades.
				 - Precio de unidad
				
						 
		Salida:  - Importe total.
				 		
	
*/
/***************************************************************************/


#include <iostream>			// Se añaden los recursos de E/S
using namespace std;

int main() {				// Programa Principal


	// Variables
	
	double num_unidades, precio, descuento = 0, importe_total;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el numero de unidades: "; cin >> num_unidades;
	cout << endl;
	cout << "- Introduzca el precio: "; cin >> precio;
	cout << endl << endl;
	
	// Calculos
	
	precio = precio*num_unidades;
	
	// Logica y Resultados
	
	if (num_unidades >= 100 ) {
	    
	    descuento = descuento + 3;
	    
	    if (precio >= 700) {
	        
	        descuento = descuento + 2;
	    }
	        
	}
	
	descuento = descuento / 100;
	importe_total = precio - (precio*descuento);
	
	
	cout << "--> El importe total son " << importe_total << "$.";
	cout << endl << endl;
			
	return 0;
}
