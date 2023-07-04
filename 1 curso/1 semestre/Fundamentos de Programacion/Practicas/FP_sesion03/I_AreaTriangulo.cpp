/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Construid un programa que pida al usuario el valor de los dos lados,
	el ángulo que éstos forman (en grados), y muestre el valor del área.

		
		Entrada: - Lado A.
				 - Lado B.
				 - Angulo que forman.
				
								
						 
		Salida:  - Area triangulo.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	double a, b, angulo, area;
	const double RADIANES=0.0174533;
	
	cout << endl;
	cout << "- Introduzca el lado a(cm): "; cin >> a;
	cout << endl;
	cout << "- Introduzca el lado b(cm): "; cin >> b;
	cout << endl;
	cout << "- Introduzca el angulo que forman en grados: "; cin >> angulo;
	cout << endl << endl;
	
	
	angulo = angulo*RADIANES;
	area = 0.5*a*b*sin(angulo);
	
	cout << "--> EL area total del triangulo son " << area <<" cm^2.";
	cout << endl << endl;
	
	return 0;
	
	
}
