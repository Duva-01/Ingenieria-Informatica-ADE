/**
	DAVID MARTINEZ DIAZ
	
	GRUPO: GII-ADE
	
	RETO 3: EJERCICIO 32
*/

#include <iostream>
#include <list>
#include <iterator>
#include <cmath>

using namespace std;

/**
	@brief Esta funcion traslada los primeros n elementos de la lista al final de la misma.
	
	@param L, la lista pasada por referencia que queremos rotar de cierta manera.
	@param n, un entero que indica cuantos elementos hay que rotar
	
 	@return al ser una funcion void, no hace falta devovler nada ya que trabajamos directamente con la referencia.
*/

void rotalista(list<int> & L, int n){
	
	// Creamos una lista auxiliar donde vamos a ir guardando los valores
    list<int> aux(0);
    
    // Luego eliminamos los valores que queremos poner al final y lo guardamos 
    // en el auxiliar.
    
    for (int cont = 0; cont < n; cont++){
            
        aux.push_back(L.front());
        L.pop_front();
    }
    
    // Creamos una copia para que no varia el aux.end(), cuando lo vayamos eliminando.
    
    list<int> copia(aux);
        
    for (list<int>::iterator p = copia.begin(); p != copia.end(); p++) {

        L.push_back(aux.front());
        aux.pop_front();
	}
	
}

int main() {

	// Creamos la lista a traves de un array
	
	int arr1[] = { 1, 2, 3, 4, 5 };
	list<int> l1(arr1, arr1 + 5);
	
	int numero = 2;
	// Mostramos la lista antes de ser modificada
	
	cout << "- Lista: ";
	for (auto v : l1)
		cout << v << " ";

	// Llamamos a la funcion
	
	rotalista(l1,2);

	cout << endl << "------------------------ \n";

	// Mostramos la nueva lista 
	
	cout << "- Lista nueva: ";
	for (auto v : l1)
		cout << v << " ";


	return 0;
}
