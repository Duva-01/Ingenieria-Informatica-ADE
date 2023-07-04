// DAVID MARTINEZ DIAZ

// EXAMEN CONTINUA

// EJERCICIO 1

VectorPuntos::VectorPuntos (){
	
	puntos = new Punto [10];
	nPuntos = 0;
	reservados = 10;
		
}

KMedias::KMedias () {
	
	int K = 2;
	clusters = new  Cluster [2];
	
}

//-------------------------------------------------//

int VectorPuntos::Capacity() const {
	return reservados;
}

Punto * VectorPuntos::GetPuntos() const {
	return puntos;
}

void VectorPuntos::clear(){
	
	if(puntos != nullptr){
		delete [] puntos;
	}
	
	nPuntos = 0;
	reservados = 0;	
}

VectorPuntos::VectorPuntos (const VectorPuntos & orig){
	
	nPuntos = orig.Size();
	reservados = orig.Capacity();
	
	puntos = new Punto [reservados];
	
	for(int n=0; n<reservados; n++){
		puntos[n].SetXY(orig.puntos[n].getX(), orig.puntos[n].getY());
	}
}

VectorPuntos & VectorPuntos::operator = (const VectorPuntos & orig){
	
	if(this != & orig){
		
		clear();
		
		nPuntos = orig.Size();
		reservados = orig.Capacity();
		puntos = new Punto [reservados];
	
		for(int n=0; n<reservados; n++){
			puntos[n].SetXY(orig.puntos[n].getX(), orig.puntos[n].getY());
		}	
	}	
	
	return *this;

}

VectorPuntos::~VectorPuntos(){
	
	delete [] puntos;
}

//------------------------------------------------//

Cluster::~Cluster (){}
Cluster::CLuster(){}

void Punto::clear(){	
	x=y=0;
}

void Cluster::clear(){
	
	puntos.clear();
	centroide.clear();
}

Cluster::Cluster (const Cluster & orig){
	
	puntos = orig.GetPuntos();
	setCentroide(orig.getCentroide());
}

Cluster & Cluster::operator=(const Cluster & orig){
	
	if(this != & orig){
		
		clear();
		puntos = orig.GetPuntos();
		setCentroide(orig.getCentroide());
	}
	
	return *this;
}

// EJERCICIO 2

void VectorPuntos::add(const Punto & p){
	
	if(nPuntos+1 >= reservados){
		reservados = reservados * 2;
		
		Punto *aux = new Punto [reservados];
	
	for(int n=0; n<nPuntos; n++)
		aux[n] = puntos[n];
	
	delete [] puntos;
	puntos = aux;
	
	}
	
	nPuntos ++;
	puntos[nPuntos] = p;
		
}

void KMedias::clear(){
	
	for(int n=0; n<K; n++){
		clusters[n].clear();
	}
	
	K=0;
}
void KMedias::clearAndSetK(const int k){
	
	clear();
	K = k;
	clusters = new Cluster [k];	
}

// EJERCICIO 3

Punto & VectorPuntos::operator [] (int n){
	return puntos[n];
}

Punto VectorPuntos::operator [] (int n) const {
	return puntos[n];
}

ostream & Cluster::operator << (ostream & flujo){
	
	flujo << centroide << endl;
	
	// Ya viene implementado
	
	flujo << puntos << endl;
	
	return flujo;
}
ostream & KMedias::operator << (ostream & flujo) const {
	
	flujo << K;
	flujo << endl;
	
	for(int n = 0; n< K; n++){
		flujo << clusters[n];
	}
	
	return flujo;
}

istream & Cluster::operator >>(const istream & archivo){
	
	archivo >> centroide;
	
	// Ya viene implementado
	
	archivo >> puntos;
}

istream & KMedias::operator >>(const istream & archivo){
	
	clear();
	
	string linea;
	stringstream aux;
	
	getline(archivo, linea);
	aux.str(linea);
	
	aux >> K;
	
	clusters = new Cluster [K];
	
	for(int n=0; n < K; n++){	
		archivo >> cluster[n];	
	}
	
}

// EJERCICIO 4

void Cluster::calcularCentroide(){
	
	double mediaX = 0;
	double mediaY = 0;
	
	for(int n=0; n<puntos.size(); n++){
		
		mediaX += puntos[n].GetX();
		mediaY += puntos[n].GetY();
	}
	
	mediaX = mediaX/puntos.size();
	mediaY = mediaY/puntos.size();
	
	centroide.setXY(mediaX, mediaY);
}

int KMedia::clusterMasCercano(const Punto & p){
	
	bool primera_vez = true;
	
	double distancia_min;
	int pos_min;
	
	double distancia;
	
	for(int n=0; n<K; n++){
		
		distancia = clusters[n].getDistancia(p);
		
		if(distancia < distancia_min || primera_vez == true){
			
			primera_vez = false;
			distancia_min = distancia;
			pos_min = n;
		}
		
		distancia = 0;
	}
	
	return pos_min;
}

double KMedias::cohesion() const{
	
	double distancia_media = 0;
	int combinaciones = 0;
	
	for(int n=0; n<K; n++){
		
		for(int j=n+1; j<K; j++){
			
			distancia_media += cluster[n].getCentroide().getDistancia(cluster[j].getCentroide());
			combinaciones++;
		}
	}
	
	distancia_media = distancia_media/combinaciones;
	
	return distancia_media;
}



