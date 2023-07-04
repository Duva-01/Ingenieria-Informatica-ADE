/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
// 
// 
//	11.
/*  Construya un programa para leer el valor de una variable salario_base de 
	tipo double, la incremente un 2 % e imprima el resultado en pantalla. 
	Para realizar este cálculo, multiplique por 1.02 el valor original. 
	Tiene varias alternativas:
		
		a) Calcular 1.02 * salario_base dentro de la sentencia cout.
		b) Introducir una variable salario_final, asignarle la expresión 
		   anterior y mostrar su contenido en la sentencia cout
		c) Modificar la variable original salario_base con el resultado de 
		   incrementarla un 2 %.
		   
		   
	b)
	Yo escojo la opcion b, ya que no tendria logica dar un resultado con la 
	variable salario base, ya que en realidad podemos crear otra variable 
	(salario final) expresando el resultado verdadero.

		Entrada: - Salario_base.	 
				 
		Salida:  - Salario_final.		
	
*/
/***************************************************************************/

#include <iostream>			// Se añaden los recursos de E/S.

using namespace std;

int main() {				// Programa Principal
	
	// Variables
	
	double salario_base, salario_final;
	
	// Entrada de datos
	
	cout <<endl;
	cout << "- Introduzca el salario base: "; cin >> salario_base;
	
	// Cálculos	
	
	salario_final = (salario_base * 1.02);
	
	// Salida de datos
	
	cout <<endl << endl;
	cout << "--> Su salario final es de " << salario_final <<" euros.";
	cout <<endl << endl;
	
	return 0;
}
