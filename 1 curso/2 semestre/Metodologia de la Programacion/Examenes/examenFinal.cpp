/* EXAMEN FINAL DE METODOLOGIA DE LA PROGRAMACION
 * DOBLE GRADO INFORMATICA Y ADE
 */

/* 
 * File:   examenFinal.cpp
 * Author: David Martinez Diaz
 * DNI: 44669141J
 * GRUPO: 2
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Clientes.h"
#include "Venta.h"
#include "Ventas.h"

using namespace std;

/* Ejercicio 0:
 * Hacer los mÃ©todos necesarios para obtener el numero total de clientes y ventas 
 * para las clases Clientes y Ventas.  Â¿En necesario poner un argumento para estos metodos?
 */

/* >>>> SOLUCION EJERCICIO 0 */

/* Respuesta Razonada: No necesita ningun argumento porque bla, bla, bla. 
 *  AdemÃ¡s teniendo en cuenta que la la la,  * pues no hace falta
 */

int Clientes::NumClientes() const{
    return num_clientes;
}
int Ventas::NumVentas() const{
    return num_ventas;
}

/* >>>> SOLUCION EJERCICIO 1.1  */

Clientes::Clientes(){
	
	int num_clientes = 0;
	los_clientes = nullptr;	
}

Cliente::Cliente(){
	
	id_cliente = 0;
	descuento = 0.0;
	nombre = "";
	NIF = "";
}

/* 
Respuesta Razonada: Cliente si necesita un contructor sin argumentos ya que cuando 
creas un objeto puede que lo queramos utilizar vacio y poco a poco ir 
asignandole valores.
*/

/* >>>> SOLUCION EJERCIO 1.2  */

Clientes::~Clientes(){	

	delete [] los_clientes;
}

/* 
Respuesta Razonada: En cuanto a los destructores solo necesitamos el destructor
de la clase Clientes, ya que este utiliza memoria dinamica y es necesario eliminar
su memoria reservada.

Sin embargo para clase Cliente no hace falta ya que este no tuliza memoria dinamica.
*/

/* >>>> SOLUCION EJERCICIO 1.3 */

const Cliente & Clientes::GetCliente(int n) const{
	
	return los_clientes[n];
}

void Cliente::clear(){
	
	id_cliente = 0;
	descuento = 0.0;
	nombre = "";
	NIF = "";	
}

void Clientes::clear(){
	
	num_clientes = 0;
	delete [] los_clientes;	
}

Cliente::Cliente(const Cliente & orig){
	
	id_cliente = orig.GetIdCliente();
	descuento = orig.GetDescuentoCliente();
	nombre = orig.GetNombreCliente();
	NIF = orig.GetNIFCliente();
}

Clientes::Clientes (const Clientes & orig){
	
	num_clientes = orig.NumClientes();
	los_clientes = new Cliente [num_clientes];
	
	for(int n=0; n<num_clientes; n++)
		los_clientes[n]=orig.GetCliente(n);
}

Cliente & Cliente::operator=(const Cliente & orig){
	
	if(this != &orig){
		
		clear();
		
		id_cliente = orig.GetIdCliente();
		descuento = orig.GetDescuentoCliente();
		nombre = orig.GetNombreCliente();
		NIF = orig.GetNIFCliente();
		
	}
	
	return *this;
}

Clientes & Clientes::operator=(const Clientes & orig){
	
	if(this != &orig){
		
		clear();
		
		num_clientes = orig.NumClientes();
		los_clientes = new Cliente [num_clientes];
	
		for(int n=0; n<num_clientes; n++)
			los_clientes[n]=orig.GetCliente(n);
	}
	
	return *this;
}

/* 
Respuesta Razonada: Para Cliente y CLientes si son necesarios tanto los contructores
de copia como los operadores de asignacion ya que nos permitiran igualar posteriormente dos
objetos de la misma clase o crear todos.
*/

/* >>>> SOLUCION EJERCICIO 2.1 */

Clientes Clientes::operator+=(const Cliente & cli){
	
	// Impongo la condicion de si se repite
	
	bool se_repite = false;
	
	// Busco en los clientes para ver si se repite
	
	for(int n=0; n<num_clientes; n++){
		
		if(los_clientes[n].GetNIFCliente() == cli.GetNIFCliente()){
			se_repite = true;
		}
	}
	
	// Si se repite entonces hago cambios, si no, no hago nada
	if(se_repite == false){
		
		// Creo un puntero auxiliar y copio todo lo de clientes
		
		Cliente *aux = new Cliente [num_clientes + 1];
		
		for(int n=0; n<num_clientes; n++)
			aux[n]=los_clientes[n];
		
		delete [] los_clientes;
		num_clientes++;
		
		// Genero un nuevo Id y añado el nuevo cliente a aux
		
		cli.SetIdCliente(GeneraIdCliente());
		aux[num_clientes] = cli;
		
		los_clientes = aux;
	}
	
	// Devuelvo el objeto implicito
	
	return *this;
}

/* >>>> SOLUCION EJERCICIO 2.2 */

void Clientes::SetLosClientes(const Cliente * aux){
	
	los_clientes = aux;
}
void Clientes::SetNumClientes(int n){
	
	num_clientes = n;
}

Cliente Clientes::at(int pos)const {
	
	return los_clientes[pos];
}

Clientes Clientes::operator+(const Clientes & orig) const {
	
	// Me creo el objeto que voy a rellenar y un vector para saber si se repiten
	
	Clientes aux;
	bool se_repite[orig.NumClientes()];
	
	// En el bucle veo si se repiten o no y cuales.
	int contador = 0;
	for(int n=0; n<orig.NumClientes(); n++){
		
		se_repite[n] = false;
		for(int i=0; i<num_clientes; i++){
			
			if(orig.at(n).GetNIFCliente() == los_clientes[i].GetNIFCliente()){
				se_repite[n] = true;
				contador ++;
			}
		}
	}
	
	// Creo la capacidad total de clientes que va a tener y el reservo memoria
	
	int num_clientes_aux = num_clientes + (orig.NumClientes() - contador);
	Cliente *los_clientes_aux = new Cliente [num_clientes + (orig.NumClientes() - contador)];
	
	// Voy copiando en el vector auxiliar para cada uno de los objetos
	
	for(int n=0; n<num_clientes; n++)
		los_clientes_aux[n] = los_clientes[n];
	
	int pos = 0;
	
	// Para el segundo objeto, si no se repite le creo una nueva id y lo añado al vector
	
	for(int j=num_clientes; j<num_clientes_aux; j++){
		
		if(se_repite[pos] == false){
			
			orig.at(pos).SetIdCliente(GeneraIdCliente());
			los_clientes_aux[j] = orig.at(pos);
			
		}
		pos ++;
	}
	
	// Por ultimo relleno el objeto y lo devuelvo
	
	aux.SetLosClientes(los_clientes_aux);
	aux.SetNumClientes(num_clientes_aux);
	
	return aux;
}

/* >>>> SOLUCION EJERCICIO 3.1 */

ostream & Clientes::operator << (ostream & flujo) const {
	
	// Hago un bucle for para todos los clientes
	
	for(int n=0; n<num_clientes; n++){
		
		// Ya tengo implementado el operador << de Cliente
		flujo << los_clientes[n];
		flujo << endl;
	}

	return flujo;
}

/* >>>> SOLUCION EJERCICIO 3.2 */

istream & Clientes::operator >>(const istream & archivo){
		
		#include <sstream>
		string cadena;
    	stringstream aux;
    	
    	//Como condicion me hace getlines hasta que no pueda mas
    	
		while (getline(archivo, cadena)) 
		{
			// Cojo la linea y lo transformo en un stringstream
        	Cliente cliente_nuevo;
        	aux.str(cadena);
        	
        	// Tengo implementado el operador >> para Cliente
        	aux >> cliente_nuevo;
        	
        	// Tambien tengo el operador += creador anteriormente
        	this += cliente_nuevo;
    	}
    	
    return archivo;
}	

/* >>>> SOLUCION EJERCICIO 4.1 */

Clientes::Clientes (string & nfichero){
	
	// Abro el fichero
	
	ifstream aux;
	aux.open(nfichero);
	
	string cadena_magica;
	
	// Si esta abierto cojo la primera linea
	
	if(aux.is_open()){
		
		getline(aux, cadena_magica);
		
		// Si la primera linea es igual a FICHEROCLIENTES relleno el objeto implicito
		
		if(cadena_magica == "FICHEROCLIENTES"){
			aux >> *this;
		}
		
		//  Cierro el archivo
		
		aux.close();
	}
}

/* >>>> SOLUCION EJERCICIO 4.2 */

void EscribirClientes (const string & nombre) const{
	
	// Abro el fichero
	
	ofstream escritura;
    escritura.open(nfichero);
	
	// Si esta abierto relleno el fichero
	
	if (escritura.is_open()){
		
		escritura << *this;
		escritura.close();	
	}
}

/* >>>> SOLUCION EJERCICIO 5 */

double Ventas::VentaMedia() const{
	
	// Creo la variable total y voy haciendo una 
	// sumatoria con el total de las ventas
	
	double total = 0;
	
	for(int n=0; n<num_ventas; n++)
		total += las_ventas[n].GetTotal();
	
	// Luego lo divido por el numero total de ventas
	
	total = total/num_ventas;
	
	// Y lo devuelvo
	
	return total;
}

bool Ventas::operator > (const Ventas & orig)const{
	
	// Creo un booleano definido a false
	
	bool es_mayor = false;
	
	// Si se cumple la condicion lo pongo a true
	
	if(VentaMedia() > orig.VentaMedia()){
		es_mayor = true;
	}
	
	// Devuelvo el booleano
	
	return es_mayor;
} 

bool Ventas::operator==(const Ventas & orig) const{
	
	// Creo un booleano definido a false
	
	bool es_igual = false;
	
	// Si se cumple la condicion lo pongo a true
	
	if(VentaMedia() == orig.VentaMedia()){
		es_igual = true;
	}
	
	// Devuelvo el booleano
	
	return es_igual;
} 

/* >>>> SOLUCION EJERCICIO 6 */

void Ventas::clear(){
	
	num_ventas = 0;
	delete [] las_ventas;
	
}
void Ventas::Cargar (string & nfichero){
	
	// Abro el fichero
	
	clear ();
	
	ifstream aux;
	aux.open(nfichero);
	
	string cadena_magica;
	
	// Si esta abierto cojo la primera linea
	
	if(aux.is_open()){
		
		getline(aux, cadena_magica);
		
		// Si la primera linea es igual a FICHEROVENTAS relleno el objeto implicito
		
		if(cadena_magica == "FICHEROVENTAS"){
			aux >> *this;
		}
		
		aux.close();
	}
}

int main(int argc, char** argv) {
   
   	// Creo las variables del mayor
   	
   	int pos_mayor;
   	double valor_mayor;
   	
   	// Los ficheros para poder cargar las ventas
   	
   	string fichero;
   	string fichero_mayor;
   	
   	// Me creo vectores con el espacio de [argc - 1] porque no 
	// cuento el primer argumento (Outpath)
	
   	string *iguales = new string [argc - 1];
   	Ventas *todas_ventas = new Ventas [argc - 1];
   	
   	// Y me creo un objeto con el que ri comparando los argumentos
   	Ventas nuevo;
   	
   	// Hago un bucle para el numero de argumentos que me dan
   	
	for (int n=1; n<argc; n++){
   		
   		// Añado el objeto al vector total de ventas
   		
   		fichero = argv[n];
   		todas_ventas[n-1] =  nuevo.Cargar(fichero);
   		
   		// Para la primera vez le doy valores al mayor
   		if(n==1){
   			
   			pos_mayor = n;
			valor_mayor = nuevo.VentaMedia();
			fichero_mayor = fichero;	
		}
	
		// Luego voy comparando
		
   		else {
   			
   			// Si es mayor que el valor tope lo sustituye
   			
   			if(nuevo.VentaMedia() > valor_mayor){
			   
				pos_mayor = n;
				valor_mayor = nuevo.VentaMedia();
				fichero_mayor = fichero;	
			}
   			
   			// Si son iguales lo meto en un vector de iguales con su fichero
   			
   			else if (nuevo.VentaMedia() == valor_mayor){
   				
   				iguales[n] = fichero;
   				iguales[pos_mayor] = fichero_mayor;
   				
			}
  	
		}
		
		// Mostramos el mayor valor
		
   		cout << "La mayor venta es para: " << todas_ventas[pos_mayor];
		
		// Si tiene iguales se muestra
		
   		cout << "Si hubiese ficheros con mismo valor son: " << endl;
   		
   		for(int n=0; n<argc-1; n++){
   			
   			if(iguales[n] != ""){
   				
   				cout << iguales[n] << endl;
   				
			}		
			
		}
	
	}
    
    return 0;
}

