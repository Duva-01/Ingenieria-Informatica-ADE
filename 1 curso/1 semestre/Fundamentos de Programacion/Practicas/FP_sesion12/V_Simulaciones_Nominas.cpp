/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Implementad la clase NominaEmpleado y un programa que muestre el salario 
	neto que cobrará un empleado de cada categoría bajo las mismas condiciones 
	de antigüedad y horas extras. 
	
	El programa pedirá los años de antigüedad y las horas extras.
	Ampliad el programa para que a continuación indique cuántas horas extra debe 
	trabajar un trabajador de la categoría Operario para ganar lo mismo que otro 
	de la categoría Directivo. Ambos tienen la misma antigüedad
	
	

		
		Entrada: - Años de Antiguedad.
				 - Horas extras.
						 
		Salida:  - Salario neto.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Añade las opciones E/S.
#include <cmath>			// Añade las opciones matematicas

using namespace std;

class NominaEmpleado {		// Clase NominaEmpleado
	
	private:
		
		// Variables 
		
		static const int INICIAL_OPERARIO= 900;
		static const int INICIAL_BASE=1100;
		static const int INICIAL_ADMINISTRADOR=1200;
		static const int INICIAL_DIRECTIVO=2000;
		static const int HORA_OPERARIO=16;
		static const int HORA_BASE=23;
		static const int HORA_ADMINISTRADOR=25;
		static const int HORA_DIRECTIVO=30;
		
		int anios_trabajados;
		double horas_extra;
	
	public:
		
		// Metodos Generales
		
	NominaEmpleado(int anios_antiguedad, double h_extras){
		
		anios_trabajados =	anios_antiguedad;
		horas_extra= h_extras;	
	}
	
	double Incremento_Anio(const int base){
		
		double calculo;
		calculo = base + (base * (anios_trabajados/100.0));
		
		return calculo;
	}
	
	double Incremento_Horas(const int base, const int hora_const){
		
		double calculo;
		calculo = (horas_extra * hora_const) + Incremento_Anio(base);
												 	
		return calculo;
	}

/***************************************************************************/
		
		// Metodo Especificos
		
	double nomina_Operario(){
		
		double calculo;
		
		calculo = Incremento_Horas(INICIAL_OPERARIO, HORA_OPERARIO);
		return calculo;
	}
	
	double nomina_Base(){
		
		double calculo;
		
		calculo = Incremento_Horas(INICIAL_BASE, HORA_BASE);
		return calculo;
	}
	
	double nomina_Administrador(){
		
	double calculo;
		
		calculo = Incremento_Horas(INICIAL_ADMINISTRADOR, HORA_ADMINISTRADOR);
		return calculo;
	}
	
	double nomina_Directivo(){
		
		double calculo;	
		
		calculo = Incremento_Horas(INICIAL_DIRECTIVO, HORA_DIRECTIVO);
		return calculo;
	}

/***************************************************************************/
	
	// Apartado 2
	
	double Horas_Extra_Operario_Directivo (){
		
		double salario_direc = Incremento_Anio (INICIAL_DIRECTIVO);
		double salario_oper =  Incremento_Anio (INICIAL_OPERARIO);
		
		double dif =  salario_direc - salario_oper;
		int suma = 0;
		int cont=0;
		
		while (suma < dif){
		
		cont++;
		suma = suma + HORA_OPERARIO;
		
		}
		
		return cont;
}

};

/***************************************************************************/

int main() {			// Programa Principal
	
	// Variables
	
	double h_extras;
	int anios_antiguedad;
	
	
	double salario_operario, salario_base, 
		   salario_administrador, salario_directivo;
		   
	double horas_extra_operario;
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca el numero de anios de antiguedad: "; 
	cin >> anios_antiguedad;
	
	cout << endl << "- Introduzca el numero de horas extras: "; 
	cin >> h_extras;
	cout << endl << endl;
	
	NominaEmpleado nomina (anios_antiguedad, h_extras);
	
	
/***************************************************************************/	
	
	// Calculos y Salida de Datos
	
	salario_operario = nomina.nomina_Operario();
	
	cout << "--> El salario de un operario seria: " << salario_operario 
		 <<" euros.";
	cout << endl << endl;
	
	salario_base = nomina.nomina_Base();
	
	cout << "--> El salario de un empleado base seria: " << salario_base
		 <<" euros.";
	cout << endl << endl;
	
	salario_administrador = nomina.nomina_Administrador();
	
	cout << "--> El salario de un administrador seria: " << salario_administrador
		 <<" euros.";
	cout << endl << endl;
	
	salario_directivo = nomina.nomina_Directivo();
	
	cout << "--> El salario de un directivo seria: " << salario_directivo
		 <<" euros.";
	cout << endl << endl;
	
/***************************************************************************/
	
	// Salida de Datos para el apartado 2
	
	horas_extra_operario = nomina.Horas_Extra_Operario_Directivo();
	
	cout << "--> Son necesarias: " << horas_extra_operario <<" horas extras "
	"para que \n    el operario tenga el mismo dinero que el \n    directivo.";
	cout << endl << endl;
	
	return 0;
}
