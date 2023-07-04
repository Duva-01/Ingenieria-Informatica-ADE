/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Escribir un programa que lea las coordenadas que definen un rectángulo y 
	calcule la circunferencia centrada en el punto de corte de las diagonales 
	del rectángulo tal que su superficie la menor entre todas las 
	circunferencias de área mayor que la del rectángulo.

		Entrada: - Coeficientes.
				 - Punto de Abcisas.
				 - Punto de Ordenadas.
						 
		Salida:  - Puntos de las rectas.
				 - Posicion rectas.
				 		
	
*/
/***************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;


double funcionAreaRectangulo (int x1, int y1, int x2, int y2){
							  	
	
	/************************************************************/
	
	struct Rectangulo {
	
	double punto_y1, punto_y2;
	double punto_x1, punto_x2;
	double area;
	};
	
	Rectangulo rect;
	
	rect.punto_y1 = y1;
	rect.punto_y2 = y2;
	rect.punto_x1 =	x1;
	rect.punto_x2 = x2;
	
	/************************************************************/
	
	rect.area = (rect.punto_y1 - rect.punto_y2) 
				* (rect.punto_x2 - rect.punto_x1);				  	
							  	
	return rect.area;						  	
}
					  
/***************************************************************************/							  
/***************************************************************************/							  
							  
double funcionCircunferencia (int x1, int y1, int x2, 
							  int y2, double area_rect){
	
	
	const double PI = 3.14;
	
	struct Rectangulo {
	
	double punto_y1, punto_y2;
	double punto_x1, punto_x2;
	
	};
	
	Rectangulo rect;
	
	rect.punto_y1 = y1;
	rect.punto_y2 = y2;
	rect.punto_x1 =	x1;
	rect.punto_x2 = x2;
	
	/************************************************************/
	
	struct Punto2D {
	
	double x;
	double y;
	
	};
	
	Punto2D centro;
							  	
	centro.x = 	(x1 + x2)/2;
	
	centro.y = 	(y1 + y2)/2;
	
	/************************************************************/
	
	struct Circunferencia {
	
	double r = 0;
	double area = 0;
	
	};
	
	Circunferencia circunf;					  	
	
	/************************************************************/
	
	cout << "------------------------------------------------\n";
	cout << "------------------------------------------------\n";
	
	while(area_rect > circunf.area) {
		
		circunf.r = circunf.r + 0.25;
		circunf.area =  PI * pow(circunf.r,2);
		
		if (area_rect > circunf.area) {
			
			cout << endl;
			cout << "--> No nos sirve el radio: " << circunf.r;
			cout << endl;
		}
	}
	
	/************************************************************/
	
	cout << endl;
	cout << "------------------------------------------------\n";
	cout << "------------------------------------------------\n";
	cout << endl << endl;
	
	
	
	cout << "El radio necesario es: " << circunf.r;
	cout << endl;						  	
	cout << "La ecuacion de su circunferencia es: "; 
	cout << "(x - " << centro.x << ")^2 + (y - " << centro.y;
	cout << ")^2 = " << circunf.r <<"^2";
	cout << endl << endl;
	
	
	/************************************************************/
	
	return 10; 						  	
 }


/************************************************************/
/************************************************************/

int main () {
	
	int parte_1, x1, y1, x2, y2;
	double area_rect;
	
	
	cout << endl;
	cout << " *El rectangulo viene definido por 2 puntos (x,y)*";
	cout << endl << endl;
	cout << "--> Punto 1 (superior-izquierda)";
	cout << endl << endl;
	cout << "- Introduzca el valor de x: "; cin >> x1;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> y1;
	cout << endl << endl;
	
	cout << "--> Punto 2 (inferior-derecha)";
	cout << endl << endl;
	cout << "- Introduzca el valor de x: "; cin >> x2;
	cout << endl;
	cout << "- Introduzca el valor de y: "; cin >> y2;
	cout << endl << endl;
	
	
	area_rect = funcionAreaRectangulo (x1, y1, x2, y2);
									 
	parte_1 = funcionCircunferencia	(x1, y1, x2, y2, area_rect);
	
	
	
	return 0;
}
