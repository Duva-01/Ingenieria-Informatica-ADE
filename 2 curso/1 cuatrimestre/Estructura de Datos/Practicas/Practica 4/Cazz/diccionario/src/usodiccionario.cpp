//REALIZAR 3 NUEVAS FUNCIONES Y ADEMAS ARREGLAR PROBLEMA VIOLACION SEGMENTO
//Leerlo con ifstream, no de manera chapuza
//diccionario.h, o por separado, declaraciones, cabezera en .h
//y en el .cpp implementaciones, y luego en .h poner include .cpp

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
#include "diccionario.cpp"

using namespace std;


/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre 
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os, const Diccionario<string,string> &D){
	  Diccionario<string,string>::const_iterator it;
	  
	  for (it=D.begin(); it!=D.end(); ++it){
	  
		    list<string>::const_iterator it_s;
		    
		    os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }
	  
	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is, Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave); 
		    
		    int ns;
		    is>>ns; 
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);
			      
			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);		      
	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){		 
	  list<string>::const_iterator it_s;
	  
	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}	


/*Lee un diccioario e imprime datos asociados a una clave. 
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe: 
                  ./usodiccionario < data.txt 
*/
int main(int argc , char * argv[]){
	const int FIN_MENU = 8;
	if (argc!=2){
    	cout<<"Dime el nombre del fichero con la guia"<<endl;
    	return EXIT_FAILURE;
 	 }

  	ifstream f(argv[1]);
  	if (!f){
   	   cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
   	   return EXIT_FAILURE;
  	}

	Diccionario<string,string> D;

	f >> D;
	cout << "¡Diccionario leido con exito!" << endl;
	// cout<<D;
	cin.ignore();
	system("clear");

	
	int opcion;
	cout << "\n------------------MENU------------------\n1. Visualizar todo el diccionario\n2. Obtener información sobre una palabra\n3. Insertar una nueva palabra y significados\n4. Añadir significado a una palabra\n5. Eliminar una palabra\n6. Filtrar en un rango\n7. Invertir diccionario\n8. Salir" << endl;
	cin >> opcion;
	cin.ignore();

	string palabra;
	string significados;
	list<string> l;
	char opcion2;
	char filtro1, filtro2;

	while(opcion != FIN_MENU){
			switch (opcion){
		case 1:
			cout << D;
			break;
		
		case 2:
			cout << "Introduce una palabra: ";
			cin >> palabra;

			l = D.getInfo_Asoc(palabra);

			if(l.size() > 0){
				EscribeSigni(l);
			}
			break;
		
		case 3:			
			cout << "Introduce una nueva palabra: ";
			cin >> palabra;
			cin.ignore();

			cout << "Introduce la definicion: ";
			getline(cin, significados);
			l.push_back(significados);

		
			cout << "¿Desea introducir una definicion(y/n)?: ";
			cin >> opcion2;
			cin.ignore();
			while(opcion2 != 'n'){
				cout << "Introduce la definicion: ";
				getline(cin, significados, '\n');
				l.push_back(significados);
				cout << "¿Desea introducir una definicion(y/n)?: ";
				cin >> opcion2;
				cin.ignore();
			}

			D.Insertar(palabra, l);
			break;

		case 4:
			cout << "Introduzca la clave a la cual añadir significados: ";
			getline(cin, palabra);

			cout << "Introduzca el significado a introducir: ";
			getline(cin, significados);

			D.AddSignificado_Palabra(significados, palabra);
			break;
		
		case 5:
			cout << "Introduzca la palabra a eliminar del diccionario: ";
			getline(cin, palabra);

			D.Elimina_Palabra(palabra);
			break;

		case 6:
			cout << "Introduzca entre que letras quiere hacer el filtro: ";
			cin >> filtro1 >> filtro2;
			filtro1 = toupper(filtro1);
			filtro2 = toupper(filtro2);

			D.filtra_Diccionario(filtro1, filtro2, D);
			break;
		
		case 7:
			cout << "Diccionario invertido!" << endl;
			D.invierte_Diccionario();
			cout << D << endl;

		default:
			cout << "Opcion introducida erronea" << endl;
			break;
		}

		cout << "\n------------------MENU------------------\n1. Visualizar todo el diccionario\n2. Obtener información sobre una palabra\n3. Insertar una nueva palabra y significados\n4. Añadir significado a una palabra\n5. Eliminar una palabra\n6. Filtrar en un rango\n7. Invertir diccionario\n8. Salir" << endl;
		cin >> opcion;
		cin.ignore();
		system("clear");
	}
}

