// DAVID MARTINEZ DIAZ


// EXAMEN CONTINUA


// EJERCICIO 1


Vuelo::Vuelo (){
	
	idVuelo = -1;
	Trayectoria rutaOptima();
	Trayectoria rutaReal();
	
}

Trayectoria::Trayectoria (){
	
	puntos = nullptr;
	numeroPuntos = 0;
}

Punto3D::Puntos3D (){
	
	x = y = z = 0;	
}

Trayectoria::~Trayectoria (){
	
	delete [] puntos;
}

Vuelo::~Vuelo (){
	
}


Vuelo::Vuelo (const Vuelo & orig){
	
	idVuelo = orig.getID();
	
	rutaOptima = orig.GetRutaOptima();
	rutaReal = orig.GetRutaReal();
	
}

Trayectoria::Trayectoria (const Trayectoria & orig){
	
	numeroPuntos = orig.GetNumPuntos();
	puntos = new Punto3D [numeroPuntos];
	
	for(int n=0; n<numeroPuntos; n++)
		puntos[n] = orig[n];
	
}

Punto3D::Punto3D (const Punto3D & orig){
	
	x = orig.GetX();
	y = orig.GetY();
	z = orig.GetZ();
}

void Vuelo::clear (){
	
	idVuelo = 0;
	delete [] rutaOptima;
	delete [] rutaReal;
}
void Trayectoria::clear (){
	
	delete [] puntos;
	numeroPuntos = 0;
}

void Punto3D:: clear (){
	x = y = z = 0;
}

Trayectoria Vuelo::GetRutaReal (){
	return rutaReal;
}

Trayectoria Vuelo::GetRutaOptima (){
	return rutaOptima;
}

int Vuelo::getID(){
	return idVuelo;
}

Vuelo & operator = (const Vuelo & orig){
	
	if(*this != orig){
		
		clear();
		
		idVuelo = orig.getID();
		rutaOptima = orig.GetRutaOptima();
		rutaReal = orig.GetRutaReal();
	}
	
	return *this;
}

Trayectoria & operator = (const Trayectoria & orig){
	
	if(*this != orig){
		
		clear();
		numeroPuntos = orig.numeroPuntos;
		puntos = new Punto3D [numeroPuntos];
	
		for(int n=0; n<numeroPuntos; n++)
			puntos[n] = orig[n];
	}
	
	return *this;
}

Punto3D & Punto3D::operator = (const Punto3D & orig){
	
	if(*this != orig){
		
		clear();
		x = orig.GetX();
		y = orig.GetY();
		z = orig.GetZ();
	}
	
	return *this;
}

Vuelo::Vuelo (int id, Trayectoria ruta_opt){
	
	idVuelo = id;
	rutaOptima = ruta_opt;
	rutaReal();
	
}

Trayectoria::Trayectoria(int num_p, Puntos3D *vector){
	
	numeroPuntos = num_p;
	puntos = new Punto3D [numeroPuntos];
	
	for(int n=0; n<numeroPuntos; n++)
		puntos[n] = vector[n];
	
}

// EJERCICIO 2

Vuelo & operator += (const Punto3D & p){
	
	Punto3D *aux;
	int capacidad = rutaReal.getNumeroPuntos();
 	aux = new Punto3D [capacidad + 1];
 	
	int n=0;
	for(; n < capacidad; n++)
		aux[n] = rutaReal[n];
		
	aux[n] = p;
	
	delete[] rutaReal;
	
	rutaReal (capacidad + 1, aux);
	
}

int & Trayectoria::SetNumPuntos (){
	return numeroPuntos;
}

void Trayectoria::resize(int capacidad){
	
	Punto3D *aux;
	aux = new Punto3D [capacidad];
	
	for(int n=0; n<capacidad; n++){
		aux[n] = puntos[n];
	}
	delete [] puntos;
	
	puntos = aux;	
}

ostream & operator << (const ostream & flujo){
	
	flujo << idVuelo;
	flujo << endl;
	
	flujo << rutaOptima.GetNumPuntos();
	flujo << endl;
	
	for(int n=0; n<rutaOptima.GetNumPuntos(); n++){
		
		flujo << rutaOptima[n].GetX();
		flujo << rutaOptima[n].GetY();
		flujo << rutaOptima[n].GetZ();
		flujo << endl;
	}
	
	flujo << rutaReal.GetNumPuntos();
	flujo << endl;
	
	for(int n=0; n<rutaReal.GetNumPuntos(); n++){
		
		flujo << rutaReal[n].GetX();
		flujo << rutaReal[n].GetY();
		flujo << rutaReal[n].GetZ();
		flujo << endl;
	}
	
	return flujo;
}

istream & operator >> (const istream & salida){
	
	clear();
	string linea;
	stringstream aux;
	
	getline(salida, linea);
	aux.str(linea);
	aux >> idVuelo;
	
	getline(salida, linea);
	aux.str(linea);
	aux >> rutaOptima.SetNumPuntos();
	
	int x, y, z;
	Punto3D *puntos_aux = new Punto3D[rutaOptima.SetNumPuntos()];
	
	for(int n=0; n<rutaOptima.GetNumPuntos(); n++){
		
		getline(salida, linea);
		aux.str(linea);
		
		aux >> x;
		aux >> y;
		aux >> z;
		
		Punto3D p (x,y,z);
		puntos_aux[n] = p;	
	}
	
	rutaOptima(rutaOptima.GetNumPuntos(), puntos_aux);
	delete[] puntos_aux;
	
	getline(salida, linea);
	aux.str(linea);
	aux >> rutaReal.SetNumPuntos();
	
	puntos_aux = new Punto3D[rutaReal.SetNumPuntos()];
	
	for(int n=0; n<rutaReal.GetNumPuntos(); n++){
		
		getline(salida, linea);
		aux.str(linea);
		
		aux >> x;
		aux >> y;
		aux >> z;
		
		Punto3D p (x,y,z);
		puntos_aux[n] = p;	
	}
	
	rutaReal(rutaReal.GetNumPuntos(), puntos_aux);
	delete[] puntos_aux;
	
}

// EJERICIO 3

Vuelo::Vuelo (const string nfichero){
	
	ifstream archivo;
	archivo.open(nfichero);
	string cadena_magica;
	
	if(archivo.is_open){
		
		getline(archivo, cadena_magica);
		if(cadena_magica == "FICHEROVUELO"){
			archivo >> *this;
		}
		
		archivo.close();
	}
	
}

// EJERCICIO 4
// #include <cmath>

double calcularLongitud(const Trayectoria & ruta){
	
	double longitud = 0;
	
	for(int n=0; n<ruta.GetNumPuntos()-1; n++){
		
		longitud += sqrt(pow(ruta[n].GetX - ruta[n+1].GetX, 2) 
				 + pow(ruta[n].GetY - ruta[n+1].GetY, 2) 
				 + pow(ruta[n].GetZ - ruta[n+1].GetZ, 2));
	}
	
	return longitud;
}

double Vuelo::calcularLongitudOptima (){
	
	return calcularLongitud(rutaOptima);	
}

double Vuelo::calcularLongitudReal (){
	
	return calcularLongitud(rutaReal);	
}


double Vuelo::calcularDistanciaMediaTrayectorias (){
	
	bool primera_vez = true;
	
	double distancia_min;
	double distancia;
	
	double distancia_total = 0;
	
	for(int n=0; n<rutaReal.GetNumPuntos(); n++){
		
		for(int j=0; j<rutaOptima.GetNumPuntos(); j++){
			
			distancia = sqrt(pow(ruta[n].GetX - ruta[j].GetX, 2) 
				 	  + pow(ruta[n].GetY - ruta[j].GetY, 2);
			
			if(distancia < distancia_min || primera_vez){
				distancia_min = distancia;
				primera_vez = false;
			} 
		}
		
		primera_vez = true;
		distancia_total += distancia_min;
	}
	
	distancia_total = distancia_total/rutaReal.GetNumPuntos();
	
	return distancia_total;
}

bool Vuelo::operator < (const Vuelo & otro){
	
	double distancia_1 = calcularDistanciaMediaTrayectorias ();
	double distancia_2 = otro.calcularDistanciaMediaTrayectorias ();
	
	bool es_mayor = false;
	
	if(distancia_1 > distancia_2){
		es_mayor = true;
	}
	
	return es_mayor;
}

int Vuelo::GetPuntosReal(){
	
	return rutaReal.GetNumPuntos();
}

int Vuelo::GetPuntosOptima(){
	
	return rutaOptima.GetNumPuntos();
}

void Vuelo::printReal (){
	
	for(int n=0; n<rutaReal.GetNumPuntos(); n++){
		cout << rutaReal[n].GetX() << "," << rutaReal[n].GetY() 
			 << "," << rutaReal[n].GetZ(); 
	}
	
}

void Vuelo::printOptimo(){
	
	for(int n=0; n<rutaOptima.GetNumPuntos(); n++){
		cout << rutaOptima[n].GetX() << "," << rutaOptima[n].GetY() 
			 << "," << rutaOptima[n].GetZ(); 
	}
	
}
//EJERCICIO 5

int main (argc, **argv){
	
	string nfichero1;
	string nfichero2;
	double umbral;
	
	bool pre1 = true, pre2 = true, pre3 = true;
	
	if(argc > 6){
		
		for(int n=0; n<argc; n++){
		
			if(argv[n] == "-f1"){
				nfichero1 = argv[n+1];
				pre1 = false;
			}
		
			else if(argv[n] == "-f2"){
				nfichero2 = argv[n+1];
				pre2 = false;
			}
		
			else if(argv[n] == "-d"){
				umbral = argv[n+1];
				pre3 = false;
			}
			
		}
	}
	
	else {
		cout << "Numero de argumentos invalido";
	}
	
	if (pre1){
		nfichero1 = "fichero1.txt";
	}
	
	else if (pre2){
		nfichero2 = "fichero2.txt";
	}
	
	else if (pre3){
		umbral = 0;
	}
	
	
	Vuelo v1 (nfichero1);
	Vuelo v2 (nfichero2);
	
	if(v1 < v2){
		
		cout << "El menor vuelo es " << v1.getID();
		
		cout << "La longitud real es: " << v1.calcularLongitudReal();
		cout << "Numero puntos real: " << v1.GetPuntosReal();
		
		v1.printReal();
		
		cout << "La longitud optima es: " << v1.calcularLongitudOptima();
		cout << "Numero puntos optimo: " << v1.GetPuntosOptimo();
		
		v1.printOptimo();
		
		if(v1.calcularDistanciaMediaTrayectorias() < umbral){
			cout << "La distancia media es menor que el umbral";
		}
		else {
			cout << "La distancia media es mayor que el umbral";
		}
		
	}
	
	else {
		
		cout << "El menor vuelo es " << v2.getID();
		
		cout << "La longitud real es: " << v2.calcularLongitudReal();
		cout << "Numero puntos real: " << v2.GetPuntosReal();
		
		v2.printReal();
		
		cout << "La longitud optima es: " << v2.calcularLongitudOptima();
		cout << "Numero puntos optimo: " << v2.GetPuntosOptimo();
		
		v2.printOptimo();
		
		if(v2.calcularDistanciaMediaTrayectorias() < umbral){
			cout << "La distancia media es menor que el umbral";
		}
		else {
			cout << "La distancia media es mayor que el umbral";
		}
	}
	
	
	return 0;
}
