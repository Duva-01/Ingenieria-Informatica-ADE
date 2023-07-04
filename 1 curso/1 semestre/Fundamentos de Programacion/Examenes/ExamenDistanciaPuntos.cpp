#include <iostream>
#include <cmath>

using namespace std;


int main () {
	
	double const R = 6372797.560856;
	double lon_1, lon_2, lat_1, lat_2;
	double inc_lon, inc_lat;
	
	double a, c;
	
	double distancia;
	
	cout << "-- Punto 1 --" << endl;
	
	cout << "- Introduce la longitud: "; cin >> lon_1;
	cout << endl;
	cout << "- Introduce la latitud: "; cin >> lat_1;
	cout << endl;
	
	
	cout << "-- Punto 2 --" << endl;
	
	cout << "- Introduce la longitud: "; cin >> lon_2;
	cout << endl;
	cout << "- Introduce la latitud: "; cin >> lat_2;
	cout << endl;
	
	
	// Calculos
	
	inc_lon = lon_2 - lon_1;
	inc_lat = lat_2 - lat_1;
	
	a = pow (sin(0.5 * inc_lat), 2) + cos (lat_1) * cos(lat_2) 
		* pow (sin(0.5 * inc_lon), 2);
		
	c = 2* asin(min(1.0,sqrt(a)));
	
	distancia = R*c;


	cout << endl << "--> La distancia final es: " << distancia << endl;

	return 0;

}	
