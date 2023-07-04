/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Usando como referencia la clase Punto2D para representar un punto en R
	2 diseñar e implementar las clases Rectangulo y Triangulo.
	
	Además de los constructores y los métodos Get que estime oportunos añada 
	el siguiente conjunto mínimo de métodos:
	
	a) calcular el área del rectángulo,
	b) calcular el perímetro del rectángulo,
	c) calcular si un punto está dentro de un rectángulo.
	d) calcular el perímetro del triángulo,
	e) calcular si un triángulo es rectángulo,
	f) obtener el triángulo inferior de un rectángulo, considerando su 
	   diagonal principal.
	g) obtener el triángulo superior de un rectángulo, considerando su 
	   otra diagonal.
	
	
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

class Triangulo {
	
	private: 
	
	Punto2D vertice_a;
	Punto2D vertice_b;
	Punto2D vertice_c;
	
	public: 
	
	Triangulo (Punto2D entrada_vertice_a, Punto2D entrada_vertice_b, 
			   Punto2D entrada_vertice_c):
		
		vertice_a(entrada_vertice_a), vertice_b (entrada_vertice_b), 
		vertice_c (entrada_vertice_c) {}
		
	Punto2D GetA (){
		return (vertice_a);
	}
	
	Punto2D GetB (){
		return (vertice_b);
	}
	
	Punto2D GetC (){
		return (vertice_c);
	}
	
	double Perimetro () {
		
		double suma;
		
		suma = vertice_a.DistanciaEuclidea(vertice_b) 
			 + vertice_a.DistanciaEuclidea(vertice_c) 
			 + vertice_c.DistanciaEuclidea(vertice_b);
		
		return (suma);	
	}
	
	bool EsRectangulo () {
		
		bool es_rectangulo = false;
		double hipotenusa, cateto_1, cateto_2;
		
		if (vertice_a.DistanciaEuclidea(vertice_b) > vertice_a.DistanciaEuclidea(vertice_c) 
			&& vertice_a.DistanciaEuclidea(vertice_b) > vertice_c.DistanciaEuclidea(vertice_b)){
				
				hipotenusa = vertice_a.DistanciaEuclidea(vertice_b);
				cateto_1 = vertice_a.DistanciaEuclidea(vertice_c);
				cateto_2 = vertice_c.DistanciaEuclidea(vertice_b);
			}
			
		else if (vertice_a.DistanciaEuclidea(vertice_c) > vertice_a.DistanciaEuclidea(vertice_b) 
			&& vertice_a.DistanciaEuclidea(vertice_c) > vertice_c.DistanciaEuclidea(vertice_b)){
				
				hipotenusa = vertice_a.DistanciaEuclidea(vertice_c);
				cateto_1 = vertice_a.DistanciaEuclidea(vertice_b);
				cateto_2 = vertice_c.DistanciaEuclidea(vertice_b);
			}
			
		else if (vertice_c.DistanciaEuclidea(vertice_b) > vertice_a.DistanciaEuclidea(vertice_b) 
			&& vertice_c.DistanciaEuclidea(vertice_b) > vertice_a.DistanciaEuclidea(vertice_c)){
				
				hipotenusa = vertice_c.DistanciaEuclidea(vertice_b);
				cateto_1 = vertice_a.DistanciaEuclidea(vertice_b);
				cateto_2 = vertice_c.DistanciaEuclidea(vertice_a);
			}
			
		if (pow (hipotenusa, 2) == pow(cateto_1, 2) + pow(cateto_2, 2) )	
			es_rectangulo = true;
			
		return(es_rectangulo);
	}
	
	
	
};

/***********************************************************************/

class Rectangulo {
	
	private: 
	
	Punto2D punto;
	double base;
	double altura;
	
	public: 
	
	Rectangulo (double entrada_base, double entrada_altura, Punto2D el_punto):
		
		punto(el_punto), base (entrada_base), altura (entrada_altura) {}
		
	double GetpuntoX (){
		return (punto.GetX());
	}
	
	double GetpuntoY (){
		return (punto.GetY());
	}
	
	double Getbase (){
		return (base);
	}
	
	double Getaltura (){
		return (altura);
	}
	
	double Area () {
		
		return (base*altura);	
	}
	
	double Perimetro () {
		return(base*2 + altura*2);
	}
	
	bool Pertenece (Punto2D punto_pertenece) {
		
		bool pertenece = false;
	
		
		if ((punto_pertenece.GetX() <= (punto.GetX() + base) && (punto_pertenece.GetX()>= punto.GetX())) 
		&& (punto_pertenece.GetY() <= (punto.GetY()) && punto_pertenece.GetY() >= punto.GetY() - altura)) {
			
			pertenece = true;
		}	
	
		return pertenece;
	}
	
	Triangulo Calcular_triangulo_superior () {
		
		Punto2D vertice_1 (GetpuntoX() + base, GetpuntoY() - altura);
		Punto2D vertice_2 (GetpuntoX() + base, GetpuntoY());
		
		Triangulo triangulo_sup(punto, vertice_1, vertice_2);

		
		return triangulo_sup;
	}
	
	Triangulo Calcular_triangulo_inferior () {
		
		Punto2D vertice_1 (GetpuntoX(), GetpuntoY() - altura);
		Punto2D vertice_2 (GetpuntoX() + base, GetpuntoY() - altura);
		
		Triangulo triangulo_inf(punto, vertice_1, vertice_2);

		
		return triangulo_inf;
	}
	
};


/***********************************************************************/

int main () {
	
	double entrada_x, entrada_y;
	double entrada_base, entrada_altura;
	
	double area_rect, perimetro_rect;
	bool pertenece;
	
	cout << endl;
	cout << "-- Punto superior izquierda del rectangulo --";
	cout << endl << endl;
	cout << "- Introduzca la coordenada x: "; cin >> entrada_x;
	cout << endl;
	cout << "- Introduzca la coordenada y: "; cin >> entrada_y;
	cout << endl;
	
	Punto2D el_punto (entrada_x, entrada_y); 
	cout << "Punto = " << el_punto.ToString();
	
	cout << endl << endl;
	cout << "- Introduzca la base: "; cin >> entrada_base;
	cout << endl;
	cout << "- Introduzca la altura: "; cin >>entrada_altura;
	cout << endl << endl;
	
	Rectangulo el_rectangulo (entrada_base, entrada_altura, el_punto); 

/***********************************************************************/	
	
	area_rect = el_rectangulo.Area();
	perimetro_rect = el_rectangulo.Perimetro();
	
	cout << "--> Area rectangulo: " << area_rect;
	cout << endl << endl;
	
	cout << "--> Perimetro rectangulo: " << perimetro_rect;
	cout << endl << endl;
	
	cout << "- Metodo 'Pertence Punto':";
	cout << endl << endl;
	cout << "- Introduzca la coordenada x: "; cin >> entrada_x;
	cout << endl;
	cout << "- Introduzca la coordenada y: "; cin >> entrada_y;
	cout << endl;
	Punto2D punto_pertenece (entrada_x, entrada_y); 
	
	cout << "Punto = " << punto_pertenece.ToString();
	cout << endl << endl;
	
	pertenece = el_rectangulo.Pertenece(punto_pertenece);
	
	if (pertenece == 1) {cout << "- Pertenece.";}
	else { cout << "- No pertenece.";}
	
//----------------------------------------------------------------//

	double perimetro_tri;
	bool es_rectangulo;
	
	cout << endl << endl;
	cout << "- Introduzca los vertices del triangulo: ";
	
	cout << endl << endl;
	cout << "-- Vertice a --" << endl;
	cout << "- Introduzca la coordenada x: "; cin >> entrada_x;
	cout << endl;
	cout << "- Introduzca la coordenada y: "; cin >> entrada_y;
	cout << endl;
	Punto2D vertice_a (entrada_x, entrada_y); 
	
	cout << endl << endl;
	cout << "-- Vertice b --" << endl;
	cout << "- Introduzca la coordenada x: "; cin >> entrada_x;
	cout << endl;
	cout << "- Introduzca la coordenada y: "; cin >> entrada_y;
	cout << endl;
	Punto2D vertice_b (entrada_x, entrada_y); 
	
	cout << endl << endl;
	cout << "-- Vertice c --" << endl;
	cout << "- Introduzca la coordenada x: "; cin >> entrada_x;
	cout << endl;
	cout << "- Introduzca la coordenada y: "; cin >> entrada_y;
	cout << endl;
	Punto2D vertice_c (entrada_x, entrada_y);
	
	
	Triangulo el_triangulo(vertice_a, vertice_b, vertice_c);
	
	perimetro_tri = el_triangulo.Perimetro();
	es_rectangulo = el_triangulo.EsRectangulo();
	
	cout << endl;
	cout << "--> Perimetro: " << perimetro_tri;
	cout << endl << endl;
	
	if (es_rectangulo == 1) {cout << "- Es rectangulo.";}
	else { cout << "- No es rectangulo.";}
	
	cout << endl << endl;
	cout << "-- Para el rectangulo anterior, sacamos los dos triangulos --";
	cout << endl << endl;
	
	 
	
	Triangulo tri_inf = el_rectangulo.Calcular_triangulo_inferior();
	Triangulo tri_sup = el_rectangulo.Calcular_triangulo_superior();
	
	Punto2D punto_sup_1 = tri_sup.GetA();
	Punto2D punto_sup_2 = tri_sup.GetB();
	Punto2D punto_sup_3 = tri_sup.GetC();
	
	cout << "-- Triangulo superior --" << endl << endl;
	cout << "- Punto 1: "; 
	cout << punto_sup_1.ToString();
	cout << endl;
	cout << "- Punto 2: "; 
	cout << punto_sup_2.ToString();
	cout << endl;
	cout << "- Punto 3: "; 
	cout << punto_sup_3.ToString();
	cout << endl;
	
	Punto2D punto_inf_1 = tri_inf.GetA();
	Punto2D punto_inf_2 = tri_inf.GetB();
	Punto2D punto_inf_3 = tri_inf.GetC();
	
	cout << "-- Triangulo inferior --" << endl << endl;
	cout << "- Punto 1: "; 
	cout << punto_inf_1.ToString();
	cout << endl << endl;
	cout << "- Punto 2: "; 
	cout << punto_inf_2.ToString();
	cout << endl << endl;
	cout << "- Punto 3: "; 
	cout << punto_inf_3.ToString();
	cout << endl << endl;
	
	
	
	return 0;
}
