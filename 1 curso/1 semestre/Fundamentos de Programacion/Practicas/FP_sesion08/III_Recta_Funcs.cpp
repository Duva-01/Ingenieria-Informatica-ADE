/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	a) Pida los coeficientes de dos rectas.
	
	b) Muestre los puntos (x, y) por los que pasan las rectas.
	
	c) Escriba la ecuación explícita de las dos rectas
		
		I) Con una función que escriba directamente la ecuación.
		
		II) Con una función que devuelva un string con la expresión 
			de la ecuación.	
			
	d) Indique si las rectas son paralelas, secantes o coincidentes.	
		
		Entrada: - Coeficientes.
				 - Punto de Abcisas.
				 - Punto de Ordenadas.
						 
		Salida:  - Puntos de las rectas.
				 - Posicion rectas.
				 		
	
*/
/***************************************************************************/


#include <iostream>			// Se añaden los elementos de E/S.
#include <cmath>			// Se añaden los elementos matematicos.
#include <string>

using namespace std;


/***************************************************************************/
/***************************************************************************/

double funcionPuntos (int cof_A_1, int cof_B_1, int cof_C_1,
					  int cof_A_2, int cof_B_2, int cof_C_2){
		
	int x1= -10;
	double valor_x1, f_x1, y1 = -5;
	
	cout << endl;
	cout << "------------------------------------------------\n";
	cout << "------------------------------------------------\n";
	cout << "-- Recta 1 --";
	cout << endl;
	cout << "- Le damos valores a la x:";
	cout << endl << endl;
	
	//-------------------------------------------------------------//
	do {
		
		f_x1 = -(cof_A_1*x1 + cof_C_1)/cof_B_1;
		
		cout << endl;
		cout << "--> f("<< x1 << ")= " << f_x1;
		cout << endl;
		
		x1++;
		
	}while(x1 != 10);
	//-------------------------------------------------------------//
	
	cout << endl << endl;
	cout << "------------------------------------------------\n";
	cout << endl << endl;
	cout << "Le damos valores a la y:";
	cout << endl << endl;
	
	//-------------------------------------------------------------//
	do {
		
		valor_x1 = -(cof_B_1*y1 + cof_C_1)/cof_A_1;
		
		cout << endl;
		cout << "--> y("<< y1 << ") => " << valor_x1;
		cout << endl;
		
		y1 = y1 + 0.5;
		
	}while(y1 != 5);
	//-------------------------------------------------------------//
	
	cout << endl;
	cout << "------------------------------------------------\n";
	cout << "------------------------------------------------\n";
	
	int x2= -10;
	double valor_x2, f_x2, y2 = -5;
	
	
	cout << "-- Recta 2 --";
	cout << endl;
	cout << "Le damos valores a la x:";
	cout << endl << endl;
	
	//-------------------------------------------------------------//
	do {
		
		f_x2 = -(cof_A_2*x2 + cof_C_2)/cof_B_2;
		
		cout << endl;
		cout << "--> f("<< x2 << ")= " << f_x2;
		cout << endl;
		
		x2++;
		
	}while(x2 != 10);
	//-------------------------------------------------------------//
	
	cout << endl << endl;
	cout << "------------------------------------------------\n";
	cout << endl;
	cout << "Le damos valores a la y:";
	cout << endl << endl;
	
	//-------------------------------------------------------------//
	do {
		
		valor_x2 = -(cof_B_2*y2 + cof_C_2)/cof_A_2;
		
		cout << endl;
		cout << "--> y("<< y2 << ") => " << valor_x2;
		cout << endl;
		
		y2 = y2 + 0.5;
		
	}while(y2 != 5);
	//-------------------------------------------------------------//
	
	cout << "------------------------------------------------\n";
	cout << "------------------------------------------------\n";
	
	return 10;
		
	}
	
/***************************************************************************/
/***************************************************************************/

double funcionAbcisas (int cof_A_1, int cof_B_1, int cof_C_1,
					  int cof_A_2, int cof_B_2, int cof_C_2){
					  	
	double abcisa_1, ordenada_1;
	double abcisa_2, ordenada_2;
	
	
	//-------------------------------------------------------------//
	
	cout << endl;				  	
	cout << "-- Recta 1 --";
	cout << endl;
	
	
	cout << "Introduzca un valor de abcisa: "; cin >> abcisa_1;
	cout << endl;
	
	ordenada_1 = -(cof_A_1*abcisa_1 + cof_C_1)/cof_B_1;
		
		cout << endl;
		cout << "--> f("<< abcisa_1 << ")= " << ordenada_1;
		cout << endl;

	//-------------------------------------------------------------//
	
	
	cout << endl;				  	
	cout << "-- Recta 2 --";
	cout << endl;
	
	cout << "Introduzca un valor de abcisa: "; cin >> abcisa_2;
	cout << endl;
	
	ordenada_2 = -(cof_A_2*abcisa_1 + cof_C_2)/cof_B_2;
		
		cout << endl;
		cout << "--> f("<< abcisa_2 << ")= " << ordenada_2;
		cout << endl;
		
	//-------------------------------------------------------------//
	
	
	return 10;
}

/***************************************************************************/
/***************************************************************************/


double funcionOrdenadas (int cof_A_1, int cof_B_1, int cof_C_1,
					  int cof_A_2, int cof_B_2, int cof_C_2){
					  	
	double abcisa_1, ordenada_1;
	double abcisa_2, ordenada_2;
	
	
	//-------------------------------------------------------------//
	
	cout << endl;				  	
	cout << "-- Recta 1 --";
	cout << endl;
	
	
	cout << "Introduzca un valor de ordenada: "; cin >> ordenada_1;
	cout << endl;
	
	abcisa_1 = -(cof_B_1*ordenada_1 + cof_C_1)/cof_A_1;	
		
		cout << endl;
		cout << "--> y("<< ordenada_1 << ") => " << abcisa_1;
		cout << endl;

	//-------------------------------------------------------------//
	
	
	cout << endl;				  	
	cout << "-- Recta 2 --";
	cout << endl;
	
	cout << "Introduzca un valor de ordenada: "; cin >> ordenada_2;
	cout << endl;
	
	abcisa_2 = -(cof_B_2*ordenada_2 + cof_C_2)/cof_A_2;	
		
		cout << endl;
		cout << "--> y("<< ordenada_2 << ") => " << abcisa_2;
		cout << endl;

		
	//-------------------------------------------------------------//
	
	
	return 10;
}

/***************************************************************************/
/***************************************************************************/


double funcionExplicita_direct (int cof_A_1, int cof_B_1, int cof_C_1,
					  int cof_A_2, int cof_B_2, int cof_C_2){
	
	cout << endl << endl;				  	
	cout << "------------------------------------------------\n";
	cout << endl;
					  	
	cout << "Su funcion de la recta 1 es y = (" 
	<< -(cof_A_1) <<"/"<< cof_B_1 <<")x - "<< cof_C_1 <<"/"<< cof_B_1;		
	cout << endl << endl;				  	
	
					  	
	cout << "Su funcion de la recta 2 es y = (" 
	<< -(cof_A_2) <<"/"<< cof_B_2 <<")x - "<< cof_C_2 <<"/"<< cof_B_2;		  	
					  	
	return 10;				  	
}

/***************************************************************************/
/***************************************************************************/

double funcionExplicita_string (int cof_A_1, int cof_B_1, int cof_C_1,
					 			 int cof_A_2, int cof_B_2, int cof_C_2){
	
	
	string cadena_1, cadena_2;
	
	
	cadena_1 = "-(" + to_string(cof_A_1) + "/" + to_string(cof_B_1) + ")x -" 
				+ '(' + to_string(cof_C_1) + '/' + to_string(cof_B_1) + ")";
	
	cadena_2 = "-(" + to_string(cof_A_2) + "/" + to_string(cof_B_2) + ")x -" 
				+ "(" + to_string(cof_C_2) + "/" + to_string(cof_B_2) + ")";
				
				
	
	cout << endl << endl;				  	
	cout << "------------------------------------------------\n";
	cout << endl;		
							  	
	cout << "Su funcion de la recta 1 es:";
	cout << endl;
	
	cout << cadena_1;
	cout << endl;
	
	cout << "Su funcion de la recta 2 es:";
	cout << endl;
	
	cout << cadena_2;
	cout << endl;
		  	
					  	
	return 10;				  	
}


/***************************************************************************/
/***************************************************************************/


double funcionPosicion (int cof_A_1, int cof_B_1, int cof_C_1,
						int cof_A_2, int cof_B_2, int cof_C_2){
							
	
	if (abs((cof_A_1/cof_A_2) - (cof_B_1/cof_B_2)) < 0.0001  
		&&	abs(((cof_B_1/cof_B_2) - (cof_C_1/cof_C_2))) < 0.0001){
		
		cout << endl;
		cout << "- Las rectas son coincidentes.";
		cout << endl;
	}						
							
	else if (abs((cof_A_1/cof_A_2) - (cof_B_1/cof_B_2)) < 0.0001  
			 &&	abs(((cof_B_1/cof_B_2) - (cof_C_1/cof_C_2))) < 0.0001){
		
		cout << endl;
		cout << "- Las rectas son paralelas.";
		cout << endl;
	}						
	
	else {
		
		cout << endl;
		cout << "- Las rectas son secantes.";
		cout << endl;
	}							
	
	return 10;						

}

int main () {
	
	int cof_A_1, cof_B_1, cof_C_1;
	int cof_A_2, cof_B_2, cof_C_2;
	int parte_1, parte_2, parte_3, parte_4, parte_5, parte_6;
	
	
	cout << endl;
	cout << "--> Sabiendo que una resta tiene esta forma: Ax + By + C = 0 ";
	cout << endl << endl;
	
	cout << "-- Recta 1 --";
	cout << endl << endl;
	cout << "- Introduzca el coeficiente A de la recta 1: "; cin >> cof_A_1;
	cout << endl;
	
	cout << "- Introduzca el coeficiente B de la recta 1: "; cin >> cof_B_1;
	cout << endl;
	
	cout << "- Introduzca el coeficiente C de la recta 1: "; cin >> cof_C_1;
	cout << endl << endl;
	
	
	cout << "-- Recta 2 --";
	
	cout << endl << endl;
	cout << "- Introduzca el coeficiente A de la recta 2: "; cin >> cof_A_2;
	cout << endl;
	
	cout << "- Introduzca el coeficiente B de la recta 2: "; cin >> cof_B_2;
	cout << endl;
	
	cout << "- Introduzca el coeficiente C de la recta 2: "; cin >> cof_C_2;
	cout << endl;
	
	
	parte_1 = funcionPuntos (cof_A_1, cof_B_1, cof_C_1,
							  cof_A_2, cof_B_2, cof_C_2);
	
	parte_2 = funcionAbcisas (cof_A_1, cof_B_1, cof_C_1,
							   cof_A_2, cof_B_2, cof_C_2);
							 
	parte_3 = funcionOrdenadas (cof_A_1, cof_B_1, cof_C_1,
							     cof_A_2, cof_B_2, cof_C_2);
							 
	parte_4 = funcionExplicita_direct (cof_A_1, cof_B_1, cof_C_1,
							 			cof_A_2, cof_B_2, cof_C_2);
							 			
	parte_5 = funcionExplicita_string (cof_A_1, cof_B_1, cof_C_1,
							 			cof_A_2, cof_B_2, cof_C_2);
	
	parte_6 = funcionPosicion (cof_A_1, cof_B_1, cof_C_1,
								cof_A_2, cof_B_2, cof_C_2);
	
	return 0;
	
}
