/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Cread un programa que lea el valor de la edad (dato de tipo entero) y 
	salario (dato de tipo real) de una persona. Subid el salario un 4 % si es 
	mayor de 65 o menor de 35 años. Si además de cumplir la anterior condición, 
	también tiene un salario inferior a 300 euros, se le subirá otro 3 %, 
	mientras que si su salario es mayor o igual que 300 euros pero inferior a 
	900 euros se le subirá un sólo el 1.5 %.

		
		Entrada: - Edad.
				 - Salario
				
						 
		Salida:  - Salario final.
				 - Descuentos.
				 		
	
*/
/***************************************************************************/


#include <iostream>				// Se añaden los recursos de E/S


using namespace std;


int main () {					// Programa Principal
	
	
	// Variables
	
	int edad, salario;
	double  subida, subida_total = 0, salario_total;
	
	double const SUB_1 = 4;
	double const SUB_2 = 7;
	double const SUB_3 = 5.5;
	
	enum class Subida {subida_baja, subida_media, subida_alta};
	
	Subida porcentaje;
	
	
	// Entrada de datos
	
	cout << endl;
	cout << "- Introduzca la edad: "; cin >> edad;
	cout << endl;
	cout << "- Introduzca el salario: "; cin >> salario;
	
	// Logica y Resultados
	
	
	if (65 > edad  &&  edad > 35) {
		
		porcentaje =  Subida::subida_baja;
		
		if (300 > salario) {
			
			porcentaje = Subida::subida_media;
		}
		
		if (300 <= salario && 900 > salario) {
			
			porcentaje = Subida::subida_alta;
		}
	}
	
	else {
		
		salario_total = salario;
		subida_total = 0;
		subida = 0;
		
		cout << endl << endl;
		cout << "--> Su salario total es de " << salario_total << " euros.";
		cout << endl << endl << endl;
		cout << "--> Su subida ha sido del " << subida << "%";
		cout << endl << endl;
		
		return 0;	
	}
	
	cout << endl;

	switch (porcentaje) {
		
		case (Subida::subida_baja) :
			subida = SUB_1; 
			subida_total = subida/100;
			salario_total = salario + (salario * subida_total);
			
			cout << endl << endl;
			cout << "--> Su salario total es de " << salario_total << " euros.";
			cout << endl << endl << endl;
			cout << "--> Su subida ha sido del " << subida << "%";
			cout << endl << endl; 
			
			break;
			
			
		case (Subida::subida_media) :
			subida = SUB_2; 
			subida_total = subida/100;
			salario_total = salario + (salario * subida_total);
			
			cout << endl << endl;
			cout << "--> Su salario total es de " << salario_total << " euros.";
			cout << endl << endl << endl;
			cout << "--> Su subida ha sido del " << subida << "%";
			cout << endl << endl; 
			
			break;
			
		case (Subida::subida_alta) :
			subida = SUB_3; 
			subida_total = subida/100;
			salario_total = salario + (salario * subida_total);
			
			cout << endl << endl;
			cout << "--> Su salario total es de " << salario_total << " euros.";
			cout << endl << endl << endl;
			cout << "--> Su subida ha sido del " << subida << "%";
			cout << endl << endl; 
			
			break;
	}
		
	
	return 0;
	
}

