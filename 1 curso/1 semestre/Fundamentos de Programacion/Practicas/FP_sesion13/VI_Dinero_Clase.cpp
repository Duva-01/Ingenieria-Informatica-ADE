/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	En este programa se presenta una versión simple de la clase "Dinero"
	que será útil para trabajar de forma precisa con datos monetarios.

	La clase tiene dos datos miembro: "euros" y "centimos".
	Cuando se modifiquen éstos, la clase debe permitir que se introduzca
	un número de céntimos mayor de 100 y reajustar las cantidades
	adecuadamente.
		Por ejemplo, si asignamos 20 euros y 115 céntimos, el objeto debe
		almacenar 21 en "euros" y 15 en "centimos".
	
	Est programa calcula el precio final de un producto a partir de su 
	precio inicial, de un incremento fijo mensual y de un número de 
	meses. El programa muestra, mes a mes, el precio del producto. 
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// La clase "Dinero" representa cantidades monetarias expresadas en dos
// unidades enteras: euros y céntimos

class Dinero
{

private:

	// PRE: 0 <= euros
	int euros;  // Num. de euros

	// PRE: 0 <= centimos < 100
	int centimos; // Num. de céntimos
	
public:

	/***********************************************************************/
	// Constructor sin argumentos.
	
	Dinero (void) : euros(0), centimos(0)
	{ }
	
	/***********************************************************************/
	// Constructor con argumentos.
	// Ajusta las cantidades para garantizar la validad del campo "centimos"
	// (entre 0 y 99) ya que las otras precondiciones (valores positivos o
	// cero) se garantizan porque son precondicienes del constructor.
	// Recibe:
	//		los_euros, núm. de euros
	//		los_centimos, el núm. de céntimos
	// PRE:  0 <= euros
	// PRE:  0 <= centimos
	// POST: 0 <= centimos < 100

	Dinero (int los_euros, int los_centimos)
	{
		centimos = los_centimos%100;
		euros    = los_euros + los_centimos/100;
	}

	/***********************************************************************/
	// Métodos Get

	int GetEuros (void)
	{
		return (euros);
	}

	int GetCentimos (void)
	{
		return (centimos);
	}

	/***********************************************************************/
	// Métodos que modifican el objeto

	void IncrementaEuros (int euros_suman) {
		euros = euros + euros_suman;
	}

	void IncrementaCentimos (int centimos_suman) {
		int total_centimos = centimos + centimos_suman;
		euros    = euros + (total_centimos / 100);
		centimos = total_centimos % 100;

	}
	
	void Incrementa (int euros_suman, int centimos_suman) {
		IncrementaCentimos (centimos_suman);
		IncrementaEuros (euros_suman);
	}

	/***********************************************************************/
	// Métodos varios

	string ToString (void)
	{
		string cad;
		
		cad = to_string(euros) + ",";
		if (centimos<10) cad = cad+"0"; // CUIDADO CON EL CERO INICIAL!!
		cad = cad + to_string(centimos)+" EUROS";
		return (cad);
	}

	/***********************************************************************/
	
	// Metodos Implementados
	
	bool EsMayor (Dinero nuevo_precio){
		
		bool es_mayor;
		int centimos_aux;
		int euros_2 = nuevo_precio.euros;
		int centimos_2 = nuevo_precio.centimos;
		
		centimos_2 = euros_2 * 100 + centimos_2;
		
		centimos_aux = euros * 100 + centimos;
		
		
		if (centimos_aux > centimos_2) {es_mayor = true;}
		else {es_mayor = false;}
		
		return es_mayor;
	}
	
	bool EsMayor (int euros_2, int centimos_2){
		
		bool es_mayor;
		int centimos_aux;
		
		centimos_2 = euros_2 * 100 + centimos_2;
		
		centimos_aux = euros * 100 + centimos;
		
		
		if (centimos_aux > centimos_2) {es_mayor = true;}
		else {es_mayor = false;}
		
		return es_mayor;
	}
	
	bool EsMayor (double cantidad){
		
		bool es_mayor;
		double centimos_aux;
		int aux, aux_eur;
		double aux_cent;
		
		if (cantidad*pow(10,3) > 1000) {
			
			aux = cantidad*pow(10,2);
			aux = aux * 10;
			
			if (cantidad*pow(10,3) - aux >= 5) {
				aux = aux + 10;
			}
		}
		
		aux_eur = aux / pow(10,3);
		aux_cent = aux_eur * 100 + (aux / pow (10,3) - aux_eur)*pow(10,2); 
		
		centimos_aux = euros * 100 + centimos;
		
		
		if (centimos_aux > aux_cent) {es_mayor = true;}
		else {es_mayor = false;}
		
		return es_mayor;
	}
	
	Dinero Incrementa(Dinero cantidad){
		
		int euros_aux = cantidad.euros;
		int centimos_aux = cantidad.centimos;
		
		IncrementaEuros(euros_aux);
		IncrementaCentimos(centimos_aux);
		
		//return (euros, centimos);
	}
	
	Dinero Decrementa(Dinero cantidad){
		
		int euros_aux = -1*cantidad.euros;
		int centimos_aux = -1*cantidad.centimos;
		
		IncrementaEuros(euros_aux);
		IncrementaCentimos(centimos_aux);
		
		//return (euros, centimos);
	}
	
	Dinero Modifica (double cantidad, int opcion) {
	
		double centimos_aux;
		int aux, aux_eur;
		double aux_cent;
		
		int cent_total = 0;
		int eur_total = 0;
		
		if (cantidad*pow(10,3) > 1000) {
			
			aux = cantidad*pow(10,2);
			aux = aux * 10;
			
			if (cantidad*pow(10,3) - aux >= 5) {
				aux = aux + 10;
			}
		}
		
		aux_eur = aux / pow(10,3);
		aux_cent = aux_eur * 100 + (aux / pow (10,3) - aux_eur)*pow(10,2); 
		
		centimos_aux = euros * 100 + centimos;
		
		if (opcion == 1) {
			
			cent_total = centimos_aux  + aux_cent;
			
			while (cent_total > 100){
				cent_total = cent_total - 100;
				eur_total ++;
			}
			
			euros = eur_total;
			centimos = cent_total;
 		}
 		
 		if (opcion == 2) {
			
			cent_total = centimos_aux  - aux_cent;
			
			while (cent_total > 100){
				cent_total = cent_total - 100;
				eur_total ++;
			}
			
			euros = eur_total;
			centimos = cent_total;
 		}
 		
 		//return (euros, centimos);
    }	
 	
	Dinero Diferencia(Dinero otro){
		
		int euros_aux = otro.euros;
		int centimos_aux = otro.centimos;
		int centimos_dif, eur_dif = 0;
		
		centimos_aux = euros_aux * 100 + centimos_aux;
		
		centimos = euros * 100 + centimos;
		
		centimos_dif = abs(centimos_aux - centimos);
		
		while(centimos_dif > 100) {
			centimos_dif = centimos_dif - 100;
			eur_dif ++;
		}
		
		euros = eur_dif;
		centimos = centimos_dif;
		
		//return (euros, centimos);
	}
	
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/*
	Una sencilla aplicación: programa que solicita un precio ("Dinero") y a
	continuación un incremento mensual ("Dinero").
	Muestra una tabla indicando cómo aumenta el precio inicial durante un 
	número de meses dado de acuerdo al incremento indicado.
*/

int main()
{	
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	// Lectura de precio inicial
	
	double euros, centimos;

	cout << "Introduce precio: " << endl;
	do {
		cout << "\tEuros = ";
		cin >> euros;
	} while (euros < 0);

	do {
		cout << "\tCents = ";
		cin >> centimos;
	} while (centimos < 0);
	
	// Crea un dato "Dinero" y rellena los campos con los valores leidos

	Dinero precio_producto (euros, centimos);
	cout << "Precio inicial = " << precio_producto.ToString() << endl;
	
	
	// Lectura de incremento

	double euros_inc, centimos_inc;
	
	cout << endl;
	cout << "Introduce incremento mensual: " << endl;
	do {
		cout << "\tEuros = ";
		cin >> euros_inc;
	} while (euros_inc < 0);

	do {
		cout << "\tCents = ";
		cin >> centimos_inc;
	} while (centimos_inc < 0);

	// Crea un dato "Dinero" y rellena los campos con los valores leidos

	Dinero subida (euros_inc, centimos_inc);
	cout << "Incremento mensual = " << subida.ToString() << endl;
	

	// Lectura de meses
	
	int meses;
	
	cout << endl;
	do {
		cout << "Meses = ";
		cin >> meses;
	} while (meses < 0);
	
	
	// Guardamos el precio inicial, no lo modificamos
	Dinero nuevo_precio = precio_producto;
	
	// Resultados
	
	cout << endl << endl;
		
	for (int n=1; n<=meses; n++) {
		
		nuevo_precio.Incrementa (subida.GetEuros(), subida.GetCentimos());
		
		cout << "Precio mes " << setw(3) << n << " = "
		     << nuevo_precio.ToString() << endl;
	}
	
	cout << endl;
	cout << "Precio inicial = " << precio_producto.ToString() << endl;
	cout << "Precio final   = " << nuevo_precio.ToString() << endl;
	cout << endl << endl;

//---------------------------------------------------------------------//

	cout << endl;    
	cout << "----------------------------------------------";
    cout << endl;
    
    // Llamada de Metodos
    
	cout << endl;
	cout << "- Metodo 'Es Mayor booleano: [Con precio final]'";
	cout << endl << endl;

	if (precio_producto.EsMayor(nuevo_precio) == 1) {cout << "--> Verdadero";}
	else {cout << "--> Falso";}
	
	int euros_aux, centimos_aux;
	
	cout << endl;    
	cout << "----------------------------------------------";
    cout << endl;
    
	cout << endl;
	cout << "- Metodo 'Es Mayor booleano: [Con euros y cents]'";
	cout << endl << endl;
	
	cout << "Introduzca los euros a comparar: "; cin >> euros_aux;
	cout << "Introduzca los centimos a comparar: "; cin >> centimos_aux;
	cout << endl;
	
	if (precio_producto.EsMayor(euros_aux, centimos_aux) == 1) {cout << "--> Verdadero";}
	else {cout << "--> Falso";}
	
	
	cout << endl;    
	cout << "----------------------------------------------";
    cout << endl;
    
    double cantidad_aux;
    
    cout << endl;
	cout << "- Metodo 'Es Mayor booleano: [Con cantidad]'";
	cout << endl << endl;
	
	cout << "Introduzca la cantidad a comparar: "; cin >> cantidad_aux;
	cout << endl;
	
	if (precio_producto.EsMayor(cantidad_aux) == 1) {cout << "--> Verdadero";}
	else {cout << "--> Falso";}
    
    
    cout << endl;    
	cout << "----------------------------------------------";
    cout << endl;
    
	int opcion, centimos_opc, euros_opc;
    double cantidad_opc;
    
    cout << endl << endl;
	cout << "Elija una opcion:" << endl << endl;
	cout << "1.- Metodo 'Incrementa': ";
	cout << endl;
	cout << "2.- Metodo 'Decrementa': ";
	cout << endl;
	cout << "3.- Metodo 'Modifica': ";
	cout << endl;
	cout << "4.- Metodo 'Diferencia': ";
	cout << endl;
	
	do {
		
		cout << endl << "--> "; cin >> opcion;
	}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
	
	
	if (opcion == 1) {
	
		cout << "- Euros: "; cin >> euros_opc;
		cout << "- Centimos: "; cin >> centimos_opc;
	
		Dinero opcion (euros_opc, centimos_opc);
	
		precio_producto.Incrementa(opcion);
	
		cout << endl;
		cout << "Precio Resultante = " << opcion.ToString() << endl;
	
	}
	
	if (opcion == 2) {
	
		cout << "- Euros: "; cin >> euros_opc;
		cout << "- Centimos: "; cin >> centimos_opc;
	
		Dinero opcion (euros_opc, centimos_opc);
	
		precio_producto.Decrementa(opcion);
	
		cout << endl;
		cout << "Precio Resultante = " << opcion.ToString() << endl;
	
	}
	
	if (opcion == 3) {
		
		int opcion_aux;
		
		cout << endl << endl;
		cout << "1. Sumar" << endl;
		cout << "2. Restar" << endl;
		cout << endl << "--> "; cin >> opcion_aux;
		
		cout << "- Cantidad: "; cin >> cantidad_opc;
	
		precio_producto.Modifica(cantidad_opc, opcion_aux);
	
		cout << endl;
		cout << "Precio Resultante = " << precio_producto.ToString() << endl;
	
	}
	
	if (opcion == 4) {
		
		cout << "Diferencia de Dinero con el producto inicial: " << endl;
		cout << "- Euros: "; cin >> euros_opc;
		cout << "- Centimos: "; cin >> centimos_opc;
		
		Dinero otro (euros_opc, centimos_opc);
		
		precio_producto.Diferencia(otro);
	
		cout << endl;
		cout << "Precio Resultante = " << precio_producto.ToString() << endl;
	
	}
	
	
	return (0);


}
