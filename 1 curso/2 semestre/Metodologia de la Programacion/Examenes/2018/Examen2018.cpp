//DAVID MARTINEZ DIAZ

// EXAMEN CONTINUA

//EJERCICIO 1

// Apartado a

RedMetro::RedMetro () {
	
	num_lineas = 0;
	lineas = nullptr;
		
}

RedMetro::~RedMetro(){
	
	delete [] lineas;
}

bool RedMetro::EstaVacia(){
	bool esta_vacia = true;
	
	if(lineas != nullptr){
		
		esta_vacia = false;
	}
	
	return esta_vacia;
}

// Apartado b

RedMetro::RedMetro(RedMetro orig){
	
	num_lineas = orig.GetNumLineas();
	
	lineas = new Linea [num_lineas];
	
	for(int n=0; n<num_lineas; n++)
		lineas[n] = orig[n+1];

}

RedMetro & RedMetro::operator = (const RedMetro & red){
	
	if(this != &red){
	
		clear();
	
		num_lineas=red.GetNumLineas();
		lineas=new Linea [num_lineas];
	
		for(int i=1; i<num_lineas; i++){
			lineas[i-1] = red[i];
		
		}
	
	}
	
	return *this;
}

void Redmetro::clear(){
	
	if (lineas != nullptr){
		
		delete[] lineas;
		
		lineas=nullptr;
		
	}
	num_lineas=0;
	
}

// Ejercicio 2

Linea & operator+= (const InfoParada & parada_aux){
	
	InfoParada *aux=new InfoParada[num_paradas+1];
	
	for(int i=0; i<num_paradas; i++){
		
		aux[i]=paradas[i];
		
	}
	
	delete [] paradas;
	aux[num_paradas] = parada_aux;
	
	num_paradas++;
	
	paradas=aux;
	
	
	return *this;
}

ostream & operator << (ostream flujo){
	
	flujo << num_lineas;
	flujo << endl;
	
	for(int n=0; n< num_lineas; n++){
		
		flujo << lineas[n].GetNumParadas();
		flujo < endl;
		
		for(int j=0; j<lineas[n].GetNumParadas();j++){
			
			flujo << lineas[n][j].GetIndice();
			flujo << " ";
			
			if(lineas[n][j].EstaActiva()){
				flujo << "S";
			}
			
			else {
				flujo << "N";
			}
			
			flujo << endl;
		}
	}

}

istream & operator >> (const istream & flujo){
	
	clear();
	
	int paradas;
	
	int indice;
	char actividad;
	
	string linea;
	stringstream aux;
	
	getline(flujo,linea);
	aux.str(linea);
	aux >> num_lineas;
		
	
	lineas=new Linea [num_lineas];
	
	for(int i=0; i<num_lineas; i++){
		
		getline(flujo,linea);
		aux.str(linea);
		aux >> paradas;
		
		lineas[i].SetNumParadas(paradas);
		
		lineas[i] = new InfoParada[stoi(linea)];
		
		for(int j=0; j<lineas[i].GetNumParadas(); j++){
			
			getline(flujo,linea);
			aux.str(linea);
			
			aux >> indice;
			lineas[i][j].SetIndice(indice);
			
			aux >> actividad;
			
			if (actividad == 'S'){
				lineas[i][j].SetActividad(true);
				
			}
			
			else{
				lineas[i][j].SetActividad(false);
			}
					
		}
	}
	
	return flujo;
	
}


// Ejercicio 3

RedMetro::RedMetro (string & nfichero){
	
	ifstream aux;
	aux.open(nfichero);
	
	string cadena_magica;
	
	if(aux.is_open()){
		
		getline(aux, cadena_magica);
		
		if(cadena_magica == "METRO"){
			aux >> *this;
		}
		
		aux.close();
		
	}
}

// Ejercicio 4

double RedMetro::ValorCalidad (){
	
	int n_paradas_total_1 = 0;
	
	double valor_total_1;
	double valor_lineas_1;	
	double valor_paradas_1;

	int repeticiones;
	
	valor_lineas_1 = num_lineas*(0.3);
	
	for(int n=0; n < num_lineas; n++){
		n_paradas_total_1 += lineas[n].GetNumParadas;
	
	valor_paradas_1 = n_paradas_total_1 * (0.7);
	
	valor_total_1 = valor_paradas_1 + valor_lineas_1;
	
	return valor_total_1;
}

bool & operator == (const RedMetro &  orig){
	
	bool son_iguales = false;
	
	if(ValorCalidad() == orig.ValorCalidad()){
		
		son_iguales = true
	}
	
	return son_iguales;
}

bool & operator != (const RedMetro & orig){
	
	bool son_distintos = false;
	
	if(ValorCalidad() != orig.ValorCalidad()){
		
		son_distintos = true
	}
	
	return son_distintos;
}

bool & operator > (RedMetro & const orig){
	
	bool es_mayor = false;
	
	if(ValorCalidad() > orig.ValorCalidad()){
		
		es_mayor = true
	}
	
	return es_mayor;
}

// Ejercicio 5

int Redmetro::GetNumeroTotalParadas(){
	
	int total;
	int n_paradas_max = 0;
	
	bool repetido = false;
	int utilizados = 0;
	
	for(int n=0; n < num_lineas; n++)
		n_paradas_max += lineas[n].GetNumParadas();
	
	int indice_paradas [n_paradas_max];
	
	for(int n=0; n < num_lineas; n++){
		
		for(int j=0; j < lineas[n].GetNumParadas(); j++){
			
			for(int i = 0; i < utilizados){
				if(indice_paradas[i] == lineas[n][j].GetIndice()){
					repetido = true;
				}
			}
			if(!repetido){
				indice_paradas[utilizados] = lineas[n][j].GetIndice();
				utilizados ++;
				
			}
			repetido = false;
		}
	}
	
	return utilizados;
}
int RedMetro::MejorConectada() const{
	
	int *aux=new int [GetNumeroTotalParadas()];
	int maximo = -1;
	int parada;
	
	for(int i=0; i<GetNumeroTotalParadas(); i++){
		aux[i]=0;
	}
	
	
	for(int i=0; i<num_lineas; i++){
		
		for(int j=0; j<lineas[i].GetNumParadas(); j++){
			
			indice = lineas[i][j].GetIndice();
			aux[indice-1]++;
			
		}
	}
	
	for(int i=0; i < GetNumeroTotalParadas(); i++){
		
		if(aux[i] > maximo && aux[i]>0){
			
			maximo = aux[i];
			parada=i-1;
		}
	}
	
	return parada;
}

bool Linea::EstaTotalmenteOperativa()const{
	
	bool esta_operativa=true;
	
		
	for(int j=0; j<GetNumParadas(); j++){
			
		if(!lineas[j].EstaActiva()){
			esta_operativa=false;
				
		}
			
	}
	
	return esta_operativa;
}

// Ejercicio 6

int main(int argc, char **argv){
	
	string cad1, cad2;
	
	bool pre1 = true, pre2 = true;
	
	//4 argumentos (-f1 nfichero1 -f2 nfichero2)
	
	if(argc == 4){
		
		for(int i=1; i<argc; i++){
		
			if(argv[i] == "-f1"){
				
				cad1=argv[i+1];
				pre1 = false;
			}
			
			else if(argv[i] == "-f2"){
				
				cad2=argv[i+1];
				pre2 = false;
			}
		
		}
	}
	
	else{
		
		cout << "Numero de argumentos invalido";
	}
	
	if(pre1){
		cad1 = "fichero1.txt";
	}
	else if(pre2){
		cad2 = "fichero2.txt";
	}
	
	RedMetro red1(cad1);
	RedMetro red2(cad2);
	
	
	if(red1 > red2){
		
		cout << "La red 1 es mejor que la red 2" << endl;
		
		for(int i=0; i<red1.GetNumLineas(); i++){
			
			if(red1[i].EstaTotalmenteOperativa()){
				
				cout << "Las paradas de la Linea " << i << " estan operativas";
				
			}
			else{
				cout << "Las paradas de la Linea " << i;
				cout << " no estan operativas";
			}	
		}
		
		cout << "La mejor parada de la red 1 es la ";
		cout << red1.MejorConectada();
		
	}
	
	else{
		
		cout << "La red 2 es mejor que la red 1" << endl;
		
			for(int i=0; i<red2.GetNumLineas(); i++){
			
			if(red2[i].EstaTotalmenteOperativa()){
				
				cout << "Las paradas de la Linea " << i << " estan operativas";
				
			}
			else{
				cout << "Las paradas de la Linea " << i;
				cout << " no estan operativas";
			}
			
			cout << "La mejor parada de la red 2 es la ";
			cout << red2.MejorConectada();
			
			
		}
	}
	
	return 0;
}


