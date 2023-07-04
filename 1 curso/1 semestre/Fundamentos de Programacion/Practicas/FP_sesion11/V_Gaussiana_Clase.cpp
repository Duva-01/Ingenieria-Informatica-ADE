/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Debe diseñar la clase teniendo en cuenta que la función matemática gaussiana 
	viene determinada unívocamente por el valor de la esperanza y la desviación, 
	es decir, son estos dos parámetros lo que distinguen a una función gaussiana 
	de otra.

		
		Entrada: - µ
				 - s.
				 - Valor de x
						 
		Salida:  - Funcion: f(x).
				 - CDF(x)
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Se añaden los recursos de E/S
#include <cmath>			// Se añaden los recursos matematicos

using namespace std;

class Gaussiana{			// Clase

private:
	
	// Variables
	
    double esperanza;
    double desviacion;
    double x;


public:

	// Funciones
	
  void set_esperanza(double esperanza_entrada){

    esperanza = esperanza_entrada;
  }

  void set_desviacion(double desviacion_entrada){

    desviacion = desviacion_entrada;
  }

  void set_x(double x_entrada){

    x = x_entrada;
  }


  // PRE: Desviacion tipica debe de ser mayor que cero.
	
  double gaussiana_de(Gaussiana gaussiana){

  	const double PI = 3.1415926;

  	double funcion = (exp (-0.5 * pow ((x - gaussiana.esperanza)/
          gaussiana.desviacion, 2)) / (gaussiana.desviacion * sqrt(2*PI)));

  	return(funcion);

  }

  // PRE: Para que el calculo sea correcto gaussiana_de < 0;
  
  double CDF (Gaussiana gaussiana){

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

		double gauss_x =  gaussiana_de(gaussiana);
		double w =  1.0 - gauss_x * (B1*t + B2*t2 + B3*t3 + B4*t4 + B5*t5);

		return (x>=0.0 ? w : 1.0 - w);
	}

};

/***************************************************************************/


int main(){			// Programa Principal

  // Variables
  
  double esperanza_entrada, desviacion_entrada, x_entrada;
  Gaussiana gaussiana;
  
  // Entrada de Datos y llamada de Funciones
  
  cout << endl << "\t -- Gaussiana --" << endl << endl;
  cout << "- Introduzca el valor de la Esperanza: ";
  cin >> esperanza_entrada;

  gaussiana.set_esperanza(esperanza_entrada);

/***************************************************************************/

  do{

    cout << "- Introduzca el valor de la Desviacion tipica: ";
    cin >> desviacion_entrada;
    
  }while(desviacion_entrada < 0);

  gaussiana.set_desviacion(desviacion_entrada);

/***************************************************************************/

  cout << "- Introduzca el valor de X: ";
  cin >> x_entrada;

  gaussiana.set_x(x_entrada);

/***************************************************************************/

  // Salida de Datos
  
  cout << endl << "--> El valor de la gaussiana sera = "
    << gaussiana.gaussiana_de(gaussiana);


  cout << endl << "--> El CDF(x) = " << gaussiana.CDF(gaussiana);

  return 0;
  
}
