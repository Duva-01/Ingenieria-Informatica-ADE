/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
/*  Es un programa que directamente  hace una operacion para calcular el 
	salario final de una persona.
	
	 ¿El hecho de realizar la asignación salario_final = salario_base; hace que
	 ambas variables estén ligadas durante todo el programa y que cualquier 
	 modificación posterior de salario_base afecte a salario_final?
	 
	 - Resultados:  -Salario base: 3500 -Salario final: 1200.
	
	 - En cuanto a la expresion ("Salario final = Salario base"), no se quedan 
	   ligadas durante todo el programa, esto solo ocurre en la linea 9, 
	   a partir de ahi, todo lo que ocurra a cada una de ellas sera totalmente 
	   independiente sin afectar al valor de la otra variable.
	
*/
/***************************************************************************/


#include <iostream> 			// Se añaden los recursos de E/S

using namespace std;			// Programa Principal

int main() {
	
	// Variables
	
		int salario_base, salario_final, incremento;
	
	// Calculos
	
		salario_base= 1000;
		salario_final= salario_base;
		
		incremento= 200;
		salario_final= salario_final+incremento;
	
		salario_base= 3500;
		
	 // Salida de datos
	
		cout <<"--> Salario base: " << salario_base;
		cout<< endl;
		cout <<"--> Salario final: " << salario_final;
		cout<< endl;
	
	return 0; 
	
	
}

// Resultados:  -Salario base: 3500 -Salario final: 1200.
// En cuanto a la expresion "Salario final= Salario base", no se quedan ligadas debido a que eso ocurre en la linea 9,
// y lo que ocurra a cada una de ellas sera totalmente independiente sin afectar al valor de la otra variable.

