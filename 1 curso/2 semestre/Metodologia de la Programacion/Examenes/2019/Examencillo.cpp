// Examen Ordinario

// Ejercicio 1

Comentarios::Comentarios (){
	
	num_comentarios = 0;
	los_comentarios = nullptr;
}

Comentarios::~Comentarios (){
	
	delete [] los_comentarios;
}

Comentarios & operator += (string & nuevo_comentario){
	
	string *aux = new string [num_comentarios + 1];	
	
	int n = 0;
	for(; n < num_comentarios; n++){
		aux[n] = los_comentarios[n];
	}
	
	delete[] los_comentarios;
	
	num_comentarios ++;
	aux[n] = nuevo_comentario;

	los_comentarios = aux;
	
}

// Ejercicio 2

Imagen::Imagen(){
	
	filas = columnas = 0;
	valores = nullptr;
	
	comentarios();
	string nuevo = "#Creada vacia";
	
	comentarios += nuevo;
	
}

Imagen::Imagen(int f, int c, int v){
	
	filas = f;
	columnas = c;
	valores = new int * [filas];
	
	for(int fils = 0; fils < filas; fils++){
		
		valores[fils] = new int [columnas];
		for(int cols = 0; cols < columnas; cols++){
			
			valores[fils][cols] = v;
		}
	}
	
	comentarios();
	string nuevo = "#Creada " + to_string(f) + " x " + to_string(c) + " a valor " + to_string(v);
	
	comentarios += nuevo;

}

Imagen & operator = (Imagen & orig){
	
	clear();
	
	filas = orig.filas;
	columnas = orig.columnas;
	
	for(int fils = 0; fils < filas; fils++){
		
		valores[fils] = new int [columnas];
		for(int cols = 0; cols < columnas; cols++){
			
			valores[fils][cols] = orig.at(fils, cols)
		}
	}
	
	comentarios = orig.comentarios;
	
}

Imagen::~Imagen(){
	
	for(int f=0; f<filas; f++){
		delete [] valores[f];
	}
	
	delete[] valores;
	
}

void Imagen::clear(){
	
	for(int f=0; f<filas; f++){
		delete [] valores[f];
	}
	
	delete[] valores;
	delete[] comentarios;
	
	filas = 0;
	columnas = 0;
	
	valores = nullptr;
}

int Imagen::at(int f, int c){
	
	assert(f<=filas && f>= 0);
	assert(c<=columnas && c>= 0);
	
	return valores[f][c];
}

//Ejercicio 3

istream & operator >> (std::istream & flujo){
	
	clear();
	
	string tipo;
	stringstream aux;
	
	int v_max;
	int valor;
	
	string linea;
	
	if(flujo.is_open()){
		
		getline(flujo, tipo);
		
		// Esta ya implementado
		flujo >> comentarios;
		
		getline(flujo, linea);
		aux.str(linea);
		
		aux >> columnas;
		aux >> filas;
		
		flujo >> v_max;
		
		valores = new int * [filas];
		
		for(int f=0; f < filas; f++){
			
			valores[f] = new int [columnas];
			getline(flujo, linea);
			aux.str(linea);
			
			for(int c=0; c < columnas; c++){
				
				aux >> valor;
				valores[f][c] = valor;
			}
			
		}
	
	}
	
}

Imagen::Imagen(string & fichero){
	
	ifstream archivo (fichero);
	archivo.open();
	
	if(archivo.is_open()){		
		archivo >> this;		
	}
	
	archivo.close();
}

// Ejercicio 4

const int & operator() (int f, int c) const {
	
	assert(f<=filas && f>= 1);
	assert(c<=columnas && c>= 1);
	
	return valores[f][c];
}

int & operator() (int f, int c){
	
	assert(f<=filas && f>= 1);
	assert(c<=columnas && c>= 1);
	
	return valores[f][c];
}

string Comentarios::GetComentario (int n){
	return los_comentarios[n];
}

void Comentarios::InsertComment (string comment){
	
	num_comentarios ++;
	string aux = new string [num_comentarios];
	
	for(int n = 0; n < num_comentarios; n++)
		aux[n] = los_comentarios[n];
		
	aux[num_comentarios] = comment;
	delete[] los_comentarios;
	
	los_comentarios = aux;
	
}

Imagen & operator * (Imagen obj){
	
	Imagen aux (filas, columnas, 0);
	
	for(int f=0; f < filas; f++){
		
		for(int c=0; c<columnas; c++){
			
			if(obj.at(f,c) == 0){
				
				aux(f,c) = valores[f][c];
			}
			else {
				aux(f,c) = obj.at(f,c);
			}			
		}	
	}
	
	string guion = "#------------";
	
	for(int n = 0; n < GetNumComentarios(); n++)
		aux.InsertComment(GetComentario (n));
		
	aux.InsertComment(guion);
	
	for(int i = 0; i < objGetNumComentarios(); i++)
		aux.InsertComment(obj.GetComentario(i));
		
	aux.InsertComment(guion);
	
	aux.InsertComment("#Creada por: ENMASCARAMIENTO");	
	
	return aux;
	
}

// Ejercicio 5


Imagen Imagen::SubImagen (int f, int c, int h, int w){
	
	Imagen aux(h,w,0);
	int aux_fils = 0, aux_cols = 0;
	
	
	for(int fila=f; fila < h+f; fila++){
		
		for(int columna = c; columna < w+c; columna++){
			
			aux(aux_fils,aux_cols) = valores[fila][columna];
			aux_cols ++;
		}
		aux_cols = 0;
		aux_fils ++;
	}
	
	for(int n = 0; n < GetNumComentarios(); n++)
		aux.InsertComment(GetComentario (n));
	
	string guion = "#------------";
	aux.InsertComment(guion);
	string final = "#Subimagen desde" + to_string(f) + ", " + to_string(c) + " de dimensiones " + to_string(h) + "x" + to_string(w);
	aux.InsertComment(final);	
	
}

// Private

double Imagen::ValorMedio (){
	
	double sumatoria = 0;
	double ValorMedio = 0;
	for(int f=0; f< filas; f++){
		
		for(int c=0; c<columnas; c++){
			
			sumatoria += valores[f][c];
		}
	}
	
	ValorMedio = sumatoria/(filas*columnas);
	
	return ValorMedio;
}

bool & operator > (Imagen & img){
	
	bool es_mayor = false;
	
	double valormedio_1 = ValorMedio();
	double valormedio_2 = img.ValorMedio();
	
	if(valormedio_1 > valormedio_2){
		es_mayor = true;
	}
	else {
		es_mayor = false;
	}
	
	return es_mayor;
}


// Ejercicio 6

void Imagen::Aplicacion (int f, int c, int h, int w, string archivo_1, string archivo_2){
	
	assert(f<=filas && f>= 0);
	assert(c<=columnas && c>= 0);
	
	Imagen arch_1 (archivo_1);
	Imagen arch_2 (archivo_2);
	
	Imagen subImagen_1 = arch_1.SubImagen(f, c, h, w);
	Imagen subImagen_2 = arch_2.SubImagen(f, c, h, w);
	
	if(subImagen > subImagen2){
		
		cout << "La subImagen del archivo " << archivo_1 << " es mayor";	
	}
	else if(subImagen2 > subImagen){
		
		cout << "La subImagen del archivo " << archivo_2 << " es mayor";	
	}
	else {
		cout << "Las dos subImagenes son igual de grandes";
	}
}
