/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Considerar la clase ColeccionPuntos2D que se usará para almacenar y 
	gestionar una colección de datos de tipo Punto2D.
	
	Realizar un programa que lea del teclado un número indeterminado de datos 
	de tipo Punto2D de manera que termine la lectura si el usuario escribe FIN 
	cuando el programa le pide la abscisa de un nuevo punto. Los puntos leídos 
	los almacena en un objeto ColeccionPuntos2D.
	
	A continuación pide los datos necesarios, y crea un objeto Circunferencia,
	y finalmente muestra cuáles de los puntos almacenados en la colección
	ColeccionPuntos2D está en el círculo delimitado por la circunferencia.
	
	
/***************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


class Punto2D {
	
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D
	double x;
	double y;

public:
	
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está creando.
	
	Punto2D (): x(0), y(0) {}
	
	Punto2D (double abscisaPunto, double ordenadaPunto)
	{
		SetCoordenadas (abscisaPunto, ordenadaPunto);
	}

	/***********************************************************************/
	// Método Set para fijar simultaneamente las coordenadas. 
	//
	// Recibe: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// respectivamente del punto que se está modificando.
	
	void SetCoordenadas (double abscisaPunto, double ordenadaPunto)
	{
		x = abscisaPunto;
		y = ordenadaPunto;
	}

	/***********************************************************************/
	// Métodos Get para leer las coordenadas

	double GetX (void)
	{
		return (x);
	}
	double GetY (void)
	{
		return (y);
	}

	/***********************************************************************/
	// Calcula si dos puntos son iguales 
	//
	// Recibe: otro, el punto que se quiere comparar con el objeto implícito. 
	// Devuelve: true, si se consideran iguales los dos objetos. 

	

	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Recibe: otro, el punto respecto al cual que se quiere calcular la 
	// distancia euclídea.
	// Devuelve: la distancia entre los dos puntos. 

	double DistanciaEuclidea (Punto2D otro)
	{
		double dif_x = pow (x - otro.x, 2);
		double dif_y = pow (y - otro.y, 2);

		return (sqrt(dif_x + dif_y));
	}

	/***********************************************************************/

	string ToString ()
	{
		return ("["+to_string(x)+", "+to_string(y)+"]");
	}
	
	/***********************************************************************/

};

/***********************************************************************/

class ColeccionPunto2D {
	
	private: 
	
	int static const MAX = 20;
	Punto2D puntos [MAX];
	
	int total_utilizados;
	
	public:
	
	
	ColeccionPunto2D (): total_utilizados(0){}
	
		
	int GetTotalUtilizados () {
		return total_utilizados;
	}
	
	void SetTotalUtilizados (int contador) {
		total_utilizados = contador;
	} 
	
	Punto2D GetPunto (int pos) {
		return puntos [pos];
	}
	
	void Add (Punto2D punto_nuevo){
		
			if (total_utilizados < MAX ){
				
				puntos[total_utilizados] = punto_nuevo;
				total_utilizados++;
			}
		}	
	
	void MostrarPunto (int posicion) {
		
		Punto2D punto_aux = puntos [posicion];
		
		cout << "--> Punto "<< posicion << ": " << punto_aux.ToString();
		cout << endl << endl;
	}
};

/***********************************************************************/


class Circunferencia
{
private:

	// La constante "PI" es común a todos los objetos de la clase.
	static const double PI;		
	
	// Centro de la circunferencia
	Punto2D centro;	
	
	// Longitud del radio
	// PRE: radio >= 0
	double  radio;	

public:

	/***********************************************************************/
	// Constructor con argumentos
	// Recibe:
	//		el_centro, el punto central de la circunferencia. 
	//		radio, el valor del radio.
	// PRE: radio >= 0

	Circunferencia (Punto2D el_centro, double el_radio) : centro (el_centro)
	{
		// Observad cómo se ha iniciado "centro": como es de clase "Punto2D"
		// se ha empleado la lista de iniciación para que actúe el constructor
		// de la clase "Punto2D" 
		 
		radio  = el_radio; 
	}

	/***********************************************************************/
	// Métodos Get
	
	// Devuelve el punto central de la circunferencia
	Punto2D GetCentro (void)
	{
		return (centro);
	}

	// Devuelve el radio de la circunferencia
	double GetRadio (void)
	{
		return (radio);
	}

	// Devuelve el diámetro de la circunferencia
	double GetDiametro (void)
	{
		return (radio*2);
	}

	/***********************************************************************/
	// Calcula la longitud de la circunferencia

	double Longitud (void)
	{
		return (2.0 * PI * radio);
	}

	/***********************************************************************/
	// Calcula el área del círculo
	
	double Area (void)
	{
		return (PI * radio * radio);
	}

	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado.
	//
	// Recibe: un_punto, el punto del que se quiere evaluar su pertenencia. 
	/*
		Un punto (x, y) está dentro de una circunferencia con 
		centro (x_0, y_0) y radio r si se verifica que:
			(x-0 - x)^2 + (y_0 - y)^2 <= r^2
	*/
	/*
	bool Contiene (Punto2D un_punto)
	{
		double dif_x = pow (centro.GetX() - un_punto.GetX(), 2);
		double dif_y = pow (centro.GetY() - un_punto.GetY(), 2);
		return (dif_x + dif_y <= radio*radio);
	}
	*/
	/***********************************************************************/
	// Calcular si la circunferencia contiene a un punto dado usando un 
	// test explícito sobre la distancia Euclídea del centro de la 
	// circunferencia al punto.
	//
	// Recibe: un_punto, el punto del que se quiere evaluar su pertenencia. 
	/*
		Un punto P(x, y) está dentro de una circunferencia con centro 
		C(x_0, y_0) y radio r si DistaciaEuclidea (P, C) <= r
	*/
	// Esta implementación es preferible a la anterior ya que no requiere 
	// duplicar (aunque sea de manera indiirecta) el código referido al 
	// cálculo de la distancia entre dos puntos. 
	
	bool Contiene (Punto2D un_punto)
	{
		bool contiene = false;
		
		Punto2D el_centro = GetCentro();
		double distancia = el_centro.DistanciaEuclidea (un_punto);
		if (distancia <= radio) {contiene = true;}
		
		return contiene;
	}

	/***********************************************************************/
};

const double Circunferencia :: PI = 3.1415926;

/***********************************************************************/


int main () {
	
	double entrada_x, entrada_y;
	int contador;
	
	double un_radio; 
	double centro_x, centro_y;
	
	ColeccionPunto2D coleccion;
	
	cout << endl;
	cout << "-- [Terminador '-1000'] en el valor de la x --";
	cout << endl;
	
	while (entrada_x != -1000) {
	
		cout << endl;
		cout << "- Valores para el punto " << contador;
		cout << endl;
	
		cout << "--> Valor de la x: "; cin >> entrada_x;
		cout << endl;
		
		if (entrada_x != -1000){
			
		cout << "--> Valor de la y: "; cin >> entrada_y;
		cout << endl;
	
	
		
			
			Punto2D punto_nuevo (entrada_x, entrada_y);
			
			coleccion.Add(punto_nuevo);
		}
		
		contador ++;
	}
	
	coleccion.SetTotalUtilizados(contador);
	
	cout << "Coordenada X del centro = ";
	cin >> centro_x; 

	cout << "Coordenada Y del centro = ";
	cin >> centro_y; 
	
	Punto2D un_punto (centro_x, centro_y);
	
	do{
		
		cout << "Introduzca el radio = ";
		cin >> un_radio; 
		
	}while (un_radio <= 0);
	
	Circunferencia mi_circunferencia (un_punto, un_radio);
	
	
	
	for (int n = 0; n != coleccion.GetTotalUtilizados() - 1; n++) {
		
		
		coleccion.MostrarPunto(n); 
		
		if (mi_circunferencia.Contiene(coleccion.GetPunto(n)) == 1) 
			cout << "--> Esta contenido en la circunferencia." << endl;
		
		else { cout << "--> No esta contenido en la circunferencia." << endl;}
	}
	

/***********************************************************************/
	
	
	
	
	return 0;
}
