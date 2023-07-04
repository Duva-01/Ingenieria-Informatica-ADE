// DAVID MARTINEZ DIAZ

// EXAMEN CONTINUA


// EJERCICIO 1

RedCiudades::RedCiudades(){
	
	num_ciudades = 0;
	info = nullptr;
	distancia = nullptr;	
}

RedCiudades::~RedCiudades(){
	
	delete [] info;
	
	for(int n=0; n<num_ciudades; n++)
		delete [] distancia[n];
	
	delete [] distancia;
	
}

bool RedCiudades::EstaVacia(){
	
	bool esta_vacia = true;
	
	if(distancia != nullptr){
		esta_vacia = false;
	}
	
	return esta_vacia;
}

RedCiudades::RedCiudades (const RedCiudades & orig){
	
	num_ciudades = orig.NumCiudades();
	
	info = orig.info; // ?
	
	distancia = new double* [num_ciudades];
	
	for(int n =0; n < num_ciudades; n++){
		
		distancia[n] = new double [num_ciudades];
		
		for(int j=0; j< num_ciudades; j++)
			distancia[n][j] = orig.Distancia(i,j);
				
	}
	
}

RedCiudades & operator = (const RedCiudades & orig){
	
	if(*this != orig){
		
		clear();
		
		num_ciudades = orig.NumCiudades();
	
		info = orig.info; // ?
	
		distancia = new double* [num_ciudades];
	
		for(int n =0; n < num_ciudades; n++){
		
			distancia[n] = new double [num_ciudades];
		
			for(int j=0; j< num_ciudades; j++)
				distancia[n][j] = orig.Distancia(i,j);
				
		}	
				
	}
		
}

RedCiudades::clear(){
	
	if(info != nullptr)
		delete [] info;
	
	if(distancia != nullptr){
		
		for(int n=0; n<num_ciudades; n++)
			delete [] distancia[n];
	
		delete [] distancia;
		
	}
	
	num_ciudades = 0;
	
}

// EJERCICIO 2

ostream & operator << (ostream flujo){
	
	flujo << num_ciudades;
	flujo << endl;
	
	for(int n = 0; n < num_ciudades; n++){
		
		flujo << n;
		flujo << info[n].NombreCiudad;
		flujo << info[n].PoblacionCiudad;
	}
		
	for(int i = 0; i<num_ciudades; i++){
		
		for(int j = i + 1; j<num_ciudades; j++){
			
			flujo << i;
			flujo << " ";
			flujo << j;
			flujo << " ";
			flujo << distancia[i][j];
		}
		
	}
	
	return flujo;
}

istream & operator >> (istream archivo){
	
	clear();
	
	string linea;
	getline(archivo,linea);
	
	num_ciudades = stoi(linea);
	
	info = new info [num_ciudades];
	distancia = new double* [num_ciudades];
	
	stringstream aux;
	int indice;
	
	for(int n=0; n<num_ciudades; n++){
		
		getline(archivo,linea);
		aux.str(linea);
		
		aux >> indice;
		aux >> info[indice].NombreCiudad();
		aux >> info[indice].PoblacionCiudad();
	}
	
	int indice_1;
	int indice_2;
	int dist;
	
	for(int i = 0; i < num_ciudades; i++){
		
		distancia[n] = new double [num_ciudades];
		
		for(int j = i + 1; j<num_ciudades; j++){
			
			getline(archivo,linea);
			aux.str(linea);
			
			aux >> indice_1;
			aux >> indice_2;
			aux >> dist;
			
			distancia[indice_1][indice_2] = dist;
			distancia[indice_2][indice_1] = dist;
		}
		
	}
	
	return archivo;
}

// EJERCICIO 3

RedCiudades::RedCiudades (string nfichero){
	
	ifstream aux;
	aux.open(nfichero);
	
	string cadena_magica;
	
	if(aux.is_open()){
		
		getline(aux, cadena_magica);
		
		if(cadena_magica == "RED"){
			aux >> *this;
		}
		
		aux.close();
	}
}

RedCiudades::LeerRedCiudades();

ofstream RedCiudades::EscribirRedCiudades(string nfichero){
	
	ofstream escritura;
    escritura.open(nfichero);
	
	bool correcto = false;
	
	if (escritura.is_open()){
		
		escritura << *this;
		correcto = true;
		escritura.close();	
	}
	
	return correcto;
}

// EJERCICIO 4

int RedCiudades::CiudadMejorConectada(){
	
	int conexiones [num_ciudades];
	
	for(int j=0; j<num_ciudades; j++)
		conexiones[j] = 0;
	
	for(int n=0; n<num_ciudades; n++){
				
		for(int i=0; i<num_ciudades; i++){
			
			if(distancia[n][i]	!= 0){
				conexiones[n]++;
			}
		}
	}
	
	int pos_mayor = -1;
	int mayor_valor = 0;
	
	for(int n=0; n<num_ciudades; n++){
		if(conexiones[n] > mayor_valor){
			pos_mayor = n;
			mayor_valor = conexiones[n];
		}
	}
	
	return pos_mayor;
}

InfoCiudad RedCiudades::MejorEscalaEntre (string ciudad_1, string ciudad_2){
	
	int min_dist = 99999999999;
	int pos_min = -1;
	
	int dist;
	
	int pos_1;
	int pos_2;
	
	for(int veces = 0; veces < num_ciudades; veces++){
		
		if(info[veces].NombreCiudad() == ciudad_1){
			pos_1 = veces;
		}
		else if(info[veces].NombreCiudad() == ciudad_2){
			pos_2 = veces;
		}
	}
	
	for(int n=0; n<num_ciudades; n++){
		
		if(distancia[pos_1][n] != 0 && distancia[pos_2][n] != 0){
			dist = distancia[pos_1][n] + distancia[pos_2][n];
		}
		
		else if(dist < min_dist){
			
			min_dist = dist;
			pos_min = n;
		}
	}
	
	return pos_min;	
}

int main (argc, char **argv){
	
	string nfichero;
	bool pred = true;
	
	for(int n=0; n<argc; n++){
		
		if(argc[n] == "-f"){
			nfichero = argc[n+1];
			pred = false;
		}
	}
	
	if(pred){
		nfichero = "fichero.txt";
	}
	
	RedCiudades red(nfichero);
	
	for(int n=0; n<red.NumCiudades(); n++){
		
		for(int j=n+1; j<red.NumCiudades(); j++){
			
			if(red.MejorEscalaEntre(red.NombreCiudad(n), red.NombreCiudad(j)) != -1){
				
				cout << "La mejor escala entre " << red.NombreCiudad(n) << " y " << red.NombreCiudad(n) 
					 << " es " << red.NombreCiudad(red.MejorEscalaEntre(red.NombreCiudad(n), red.NombreCiudad(j)));	
			}
			
			else {
				
				cout << "No existe escala entre " << red.NombreCiudad(n) << " y " << red.NombreCiudad(n) 
			}
		}
			
	}
}
