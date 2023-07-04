/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Recuperad la solución del ejercicio 7 de esta relación en el que construíamos 
	la clase Gausssiana. En ese ejercicio se pedía calcular y mostrar, para 
	valores x [µ - 3 s, µ + 3 s] con x = 0,5 los valores de g(x) y CF D(x).
	
	Ahora, además, deberá mostrar las gráficas de g(x) y CF D(x). Para esta 
	tarea recordad el ejercicio 32 en el empleábamos una matriz de char como 
	“tablero” en el que “dibujar”.
	

		Entrada: - µ
				 - s.
				 - Valor de x
						 
		Salida:  - Funcion: f(x).
				 - CDF(x)
	
*/
/***************************************************************************/

#include <iostream>			// Añade las opciones E/S.
#include <cmath>			// Añade las opciones matematicas

using namespace std;

class Gaussiana{			// Clase Gaussiana

private:
	
	// Variables
	
    double esperanza;
    double desviacion;
    double x;

public:

	// Metodos
	
  void set_esperanza(double esperanza_entrada){

    esperanza = esperanza_entrada;
  }

  void set_desviacion(double desviacion_entrada){

    desviacion = desviacion_entrada;
  }

  void set_x(double x_entrada){

    x = x_entrada;
  }

   // Metodo Gaussiana
   
  // PRE: Desviacion tipica debe de ser mayor que cero.
	
  double gaussiana(Gaussiana gaussiana){

  	const double PI = 3.1415926;

  	double funcion = (exp (-0.5 * pow ((x - gaussiana.esperanza)/
          gaussiana.desviacion, 2)) / (gaussiana.desviacion * sqrt(2*PI)));

  	return(funcion);

  }

/***************************************************************************/

   // Metodo CDF
   
  // PRE: Para que el calculo sea correcto gaussiana < 0;
  
  double CDF (Gaussiana gaussiana){
	
	double resultado;
	
		const double B0 =  0.231641900;
		const double B1 =  0.319381530;
		const double B2 = -0.356563782;
		const double B3 =  1.781477937;
		const double B4 = -1.821255978;
		const double B5 =  1.330274429;

		double t = 1.0 / (1 + B0*fabs(x));
		double t2 = t*t;
		double t3 = t2*t; 
		double t4 = t3*t; 
		double t5 = t4*t; 

		double gauss_x =  gaussiana.gaussiana(gaussiana);
		double w =  1.0 - gauss_x * (B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5);
		
	if (x >= 0.0){resultado = w;} 
	else {resultado = 1.0 - w;}
	
	return resultado;
	
	}
  
/***************************************************************************/

   // Matriz de la gaussiana
   
  // Para la funcion g(x)
  
  void CuadroGx (Gaussiana gaussiana) {
  	
  	char matriz [20] [80];
  	int x_aux = x;
  	int contador = 0;
  	int  contador_filas = 19, gaussiana_aux;
  	double gaussiana_aux2, n = 0;
  	bool condicion = false;
  	
  	// Limpieza
  	
  	for (int filas = 0; filas != 20; filas ++) {
	  
  		for (int columnas = 0; columnas != 80; columnas ++) {
  			
  			matriz [filas] [columnas] = ' ';
  			
		  }
  	}
  	
/***************************************************************************/
 	
  	// Damos valor a la x
  	
	x = 0;
  	x = (esperanza - 3*desviacion) + x;
  	
  	do {
  		
	gaussiana.set_x(x);
  	n = 0;	
  	contador_filas = 19;
	    	
  	// Logica 
  	
  	for (int cont_filas = 19; cont_filas > 0; cont_filas --) {
  		
		n = n + 0.015;
  		gaussiana_aux = gaussiana.gaussiana(gaussiana) * pow(10,3);
  		gaussiana_aux2 = gaussiana_aux / pow(10,3);
  		
  		if (condicion == false) {
		  
  			if (gaussiana_aux2 - n < 0){
		
  				matriz [cont_filas] [contador] = '*';
  				condicion = true;
  			}
  		}
	}	
  		
	
  	condicion = false;
  	contador ++;
  	x = x + 0.5;
  	
  }while (x > (esperanza - 3*desviacion) 
  		  && x < (esperanza + 3*desviacion) 
		  || x < x_aux);

/***************************************************************************/
	
	// Relleno la funcion gaussiana
	
	for (int columnas = 0; columnas != 80; columnas ++){
		
		for (int filas = 0; filas != 21; filas ++) {
			
			if(matriz [filas] [columnas] == '*') {
				
				while (filas != 20) {
					
					matriz [filas] [columnas] = '*';
					filas ++;
				}
			
			}
		}
	}
  	
	// Representamos la matriz
	
  	for (int filas = 0; filas != 20; filas ++) {
	  
  		for (int columnas = 0; columnas != 80; columnas ++) {
  			
  			cout << matriz [filas] [columnas];
  			
		  }
  	}
  	
  }

/***************************************************************************/
  
  void CuadroCDF (Gaussiana gaussiana) {
  	
  	
  	// Matriz de la CDF
   
  	char matriz [20] [80];
  	int x_aux = x;
  	int contador = 0;
  	int  contador_filas = 19, gaussiana_aux;
  	double gaussiana_aux2, n = 0.05;
  	bool condicion = false;
  	
  	// Limpieza
  	
  	for (int filas = 0; filas != 20; filas ++) {
	  
  		for (int columnas = 0; columnas != 80; columnas ++) {
  			
  			matriz [filas] [columnas] = ' ';
  			
		  }
  	}
  	
/***************************************************************************/
  	
  	// Damos valor a la x
  	
  	x = 0;
  	x = (esperanza - 3*desviacion) + x;
  	
  	do {
  		
	gaussiana.set_x(x);
  	n = 0.05;	
  	contador_filas = 19;
	    	
  	// Logica 
  	
  	for (int cont_filas = 19; cont_filas > 0; cont_filas --) {
  		
		n = n + 0.05;
  		gaussiana_aux = gaussiana.CDF(gaussiana) * pow(10,3);
  		gaussiana_aux2 = gaussiana_aux / pow(10,3);
  		
  		if (condicion == false) {
		  
  			if (gaussiana_aux2 - n < 0){
		
  				matriz [cont_filas] [contador] = '#';
  				condicion = true;
  			}
  		}
	}	
  		
	
  	condicion = false;
  	contador ++;
  	x = x + 0.5;
  	
  }while (x > (esperanza - 3*desviacion) 
  		  && x < (esperanza + 3*desviacion) 
		  || x < x_aux);
	
/***************************************************************************/
	
	// Relleno la funcion gaussiana
	
	for (int columnas = 0; columnas != 80; columnas ++){
		
		for (int filas = 0; filas != 21; filas ++) {
			
			if(matriz [filas] [columnas] == '#') {
				
				while (filas != 20) {
					
					matriz [filas] [columnas] = '#';
					filas ++;
				}
			
			}
		}
	}
  	
 	// Representamos la matriz
 	
  	for (int filas = 0; filas != 20; filas ++) {
	  
  		for (int columnas = 0; columnas != 80; columnas ++) {
  			
  			cout << matriz [filas] [columnas];
		}
  	}
  	
  }
  
  
};

/***************************************************************************/


int main(){			// Programa Principal

  // Variables
  
  double esperanza_entrada, desviacion_entrada, x_entrada, x_entrada_aux;
  Gaussiana gaussiana;
  
  // Entrada de Datos y llamada de Funciones
  
  cout << endl << "\t -- Gaussiana --" << endl << endl;
  cout << "- Introduzca el valor de la Esperanza: ";
  cin >> esperanza_entrada;

  gaussiana.set_esperanza(esperanza_entrada);


  do{

    cout << "- Introduzca el valor de la Desviacion tipica: ";
    cin >> desviacion_entrada;
    
  }while(desviacion_entrada < 0);

  gaussiana.set_desviacion(desviacion_entrada);

  cout << "- Introduzca el valor de X: ";
  cin >> x_entrada;
  
 /***************************************************************************/
  
  // Salida de Datos
  
  gaussiana.CuadroGx(gaussiana); 
  
  gaussiana.CuadroCDF(gaussiana);

  return 0;
  
}


