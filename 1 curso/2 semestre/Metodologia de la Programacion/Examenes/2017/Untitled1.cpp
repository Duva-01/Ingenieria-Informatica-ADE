/*
Nombre: DAVID MARTINEZ DIAZ
DNI: 44669141J
Grupo: 2
*/


// EXAMEN FINAL
// EJERCICIO 1

//Metodos necesarios supuestamente implementados

GruposTuristas::~GruposTuristas(){}
Turista::~Turista(){}

ReservasGrupos::ReservasGrupos(){
	
	ngrupos = 0;
	grupos = nullptr;	
}

ReservasGrupos::~ReservasGrupos(){
	delete [] grupos;
}

//-----------------------------------------//

int ReservasGrupos::GetNumGrupos() const {
	return ngrupos;
}

int ReservasGrupos::GetGrupo(int n) const {
	return grupos[n];
}

void ReservasGrupos::clear(){
	delete[] grupos;
	ngrupos=0;
}
ReservasGrupos::ReservasGrupos(const ReservasGrupos & orig){
	
	ngrupos = orig.GetNumGrupos(); // orig.ngrupos;
	grupos = new GrupoTuristas [ngrupos];
	
	for(int n=0; n<ngrupos; n++)
		grupos[n] = orig.GetGrupo(n); //orig.grupos[n]
}

ReservasGrupos & ReservasGrupos::operator=(const ReservasGrupos & orig){

	if(this != &orig){
		
		clear();
		
		ngrupos = orig.GetNumGrupos(); // orig.ngrupos;
		grupos = new GrupoTuristas [ngrupos];
		
		for(int n=0; n<ngrupos; n++)
			grupos[n] = orig.GetGrupo(n); //orig.grupos[n]
	
	}
	
	return *this;
}

//------------------------------------------------------//

// EJERCICIO 2

ReservaGrupos & ReservaGrupos::operator+ (const ReservaGrupos & otro){
    // creo nuevo puntero con la memoria maxima
    GrupoTuristas *aux = new GrupoTuristas[ngrupos + otro.ngrupos];
    int usados_aux = 0;
    
    // copio el contenido del implicito al nuevo puntero
    for (int i = 0; i < ngrupos; i++){
        aux[i] = grupos[i];
    }
    usados_aux = ngrupos;
    
    // bucle anidado para comprobar cada grupo de mi nuevo puntero con el del
    // explicito
    // si encuentra la misma hora sale del bucle y suma los turistas de ambos
    // si no lo añade al final
    bool misma_hora = false;
    for (int i = 0; i < otro.ngrupos; i++){
        misma_hora = false;
        int j;
        for (j = 0; j < ngrupos && !misma_hora; j++){
            if (otro.grupos[i].getHora() == aux[j].getHora()){
                misma_hora = true;
            }
        }
        if (!misma_hora){
            aux[usados_aux] = otro.grupos[i];
            usados_aux++;
            
        } else {
            // asumo void GrupoTuristas::sumarTuristas (const GrupoTuristas & grupo)
            aux[j].sumarTuristas(otro.grupos[i]);
        }
    }
    
    // una vez tengo el puntero con todos los grupos borro el implicito para
    // declararlo con la nueva memoria y copio el contenido
    delete [] grupos;
    grupos = new GrupoTuristas [usados_aux];
    for (int i = 0; i < usados_aux; i++){
        grupos[i] = aux[i];
    }
    delete [] aux;
    ngrupos = usados_aux;
    
    return *this;
} 

//-----------------------------------------------------//

// Supongo Implementado el operador [];
// Supongo Implmentado << para Hora;

int GrupoTuristas::GetNumTuristas() const{
	return nturistas;
}

ostream & ReservasGrupos::operator << (ostream flujo) const {
	
	flujo << ngrupos;
	flujo << endl;
	
	for(int n=0; n<ngrupos; n++){
		
		flujo << grupos[n].GetNumTuristas();
		flujo << endl;
		
		for(int j=0; j < grupos[n].GetNumTuristas(); j++){
			
			flujo << grupos[n][j].GetID() << endl;
			flujo << grupos[n][j].GetNombre() << endl;
			flujo << grupos[n][j].GetCodigo() << endl;
		}
		
		flujo << grupos[n].GetHora();
	}
	
	return flujo;
}

// Supongo que esta implementado el operator >> en la clase GrupoTuristas();

istream & ReservasGrupos::operator >> (const istream & archivo){
	
	clear();
	
	string linea;
	stringstream aux;
	
	getline(archivo,linea);
	aux.str(linea);
	
	aux >> ngrupos;
	
	grupos = new GrupoTuristas [ngrupos];
	
	for(int n=0; n<ngrupos; n++)
		archivo >> grupos[n];
	
	return archivo;
}

//------------------------------------------------------//

// Ejercicio 3

bool Cargar (string nfichero, ReservasGrupos & obj) const{
	
	ifstream archivo (nfichero);
	archivo.open();
	
	bool correcto = false;
	
	if(archivo.is_open()){
		
		correcto = true;	
		archivo >> obj;		
		archivo.close();
	}
	
	return correcto;
}

bool Salvar (string nfichero, const ReservasGrupos & obj) const {

	ofstream archivo (nfichero);
	archivo.open();
	
	bool correcto = false;
	
	if(archivo.is_open()){
		
		correcto = true;	
		obj.operator<<(archivo);
			
		archivo.close();
	}
	
	return correcto;
}

//-------------------------------------------------------//

void ReservasGrupos::EliminarReserva(const Hora & hora){
	
	GrupoTuristas *aux;
	aux = new GrupoTuristas [ngrupos - 1]
	int pos;
	
	for(int n=0; n<ngrupos; n++){
		
		if(grupos[n].GetHora() == hora){
			pos = n;
		}
	}
	
	for(int j=0; j<ngrupos; j++){
		
		if(j!=pos){
			aux[n] = grupos[n];
		}
	}
	
	delete [] grupos;
	grupos = aux;
	ngrupos --;
	
}

//----------------------------------------------------------//

// EJERCICIO 5


int main (argc, **argv){
	
	string nfichero1;
	string nfichero2;
	
	for(int n=0; n<argc; n++){
		
		if(argv[n] == "-f1" && argv[n+1] != "-"){
			
			nfichero1 = argv[n+1];
		}
		
		else if(argv[n] == "-f2" && argv[n+1] != "-"){
			
			nfichero2 = argv[n+1];
		}
		
	}
	
	ReservasGrupos res1;
	Cargar(nfichero1, res1);
	
	ReservasGrupos res2;
	Cargar(nfichero2, res2);
	
	
}

