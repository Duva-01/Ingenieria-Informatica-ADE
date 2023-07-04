#include "../include/guiatlf.h"
#include <fstream>
#include <stdlib.h> 

int main(int argc , char * argv[]){
  	if (argc!=2){
		cout << "Dime el nombre del fichero con la guia" << endl;
      	return EXIT_FAILURE;
  	}
  	ifstream f(argv[1]);
  	if (!f){
    	cout << "No puedo abrir el fichero" << argv[1] << endl;
		return 0;
	}
  
 	Guia_Tlf g;
 
	f >> g;
   	cout << "La guia fue insertadada con exito\n";
	cin.ignore();
	system("clear");

	int opcion;
	cout << "\n---------------MENU---------------\n1. Ver guia de tlfs\n2. Obtener numero de telefono de un contacto\n3. Borrar contacto\n4. Agregar contacto\n5. Salir" << endl;
	cin >> opcion;
	cin.clear();
	system("clear");

	string n, tlf;

	while(opcion != 5){
		switch(opcion){
			case 1: 
				cout << "-------GUIA DE TELEFONOS-------\n" << g << endl;
				break;

			case 2:
				cout << "Dime un nombre sobre el que quieres obtener el telefono: ";
				
   				while (getline(cin,n)){
					cout << "Buscando " << n << "...." << endl;
					tlf = g.gettelefono(n);
					if (tlf == ""){
						cout<<"No existe ese nombre en la guia"<< endl;
					}else{
						cout<<"El telefono es: " << tlf << endl;
					}
					cout<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono: ";
				}
				cin.clear();
				break;
			
			case 3:
				cout<< "Dime el nombre que quieres borrar: ";
				
 				while (getline(cin,n)){
					cout << "Buscando " << n << "...." << endl;

					if(g.borrar(n)){
						cout << n << " borrado con exito" << endl;
					}else{
						cout<<"No existe ese nombre en la guia" << endl;
					}
					cout << "[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar: ";
				}

				cin.clear();
				break;

			case 4:
				cout << "Nombre del contacto: ";
				getline(cin, n);
				cout << "Introduce un numero de telefono: ";
				getline(cin, tlf);
				g.insert(n, tlf);

				cin.clear();
				break;
				
			default:	
				cout << "Opcion introducida incorrecta" << endl;	

		}
		cout << "\n---------------MENU---------------\n1. Ver guia de tlfs\n2. Obtener numero de telefono de un contacto\n3. Borrar contacto\n4. Agregar contacto\n5. Salir" << endl;
		cin >> opcion;
		cin.ignore();
		system("clear");
	}

	
 
	cin.clear();
	cin.ignore();
 	Guia_Tlf otraguia;
	string nombre;
 	cout << "Introduce otra guia ([Pulse CTRL+D para finalizar])" << endl;
	getline(cin, nombre);
  	ifstream nueva(nombre);
  	if (!nueva){
    	cout << "No puedo abrir el fichero " << nombre << endl;
		return 0;
	}
 	nueva >> otraguia; cin.clear();
 	Guia_Tlf un = g + otraguia;
 	Guia_Tlf dif = g - otraguia;

 	cout << endl << "La union de las dos guias: " << un << endl;
 	cout << endl << "La diferencia de las dos guias: " << dif << endl;
 
 	cout << endl << "Dime un nombre para establecer los previos: " << endl;
 	cin >> n;
 	tlf = g.gettelefono(n);
 	Guia_Tlf p = g.previos(n,tlf);
 	cout << endl <<" Los nombre previos: " << p << endl;
 
 
	cout<<"Listando la guia con iteradores:"<<endl;
	Guia_Tlf::iterator it;
	for (it=g.begin(); it!=g.end(); ++it)
		cout<<*it<<endl;

}