/**
	DAVID MARTINEZ DIAZ
	
	GRUPO: GII-ADE
	
	RETO 3: EJERCICIO 31
*/


#include <iostream>
#include <list>
#include <iterator>
#include <cmath>

using namespace std;

/**
	@brief Esta funcion  permita "duplicar" una lista L (intercalar alternativamente tras cada elemento
	en la posición i, el elemento que está en la posición n-i-1 (i=0,1,...,n-1).
	
	@param L, la lista pasada por referencia que queremos duplicar de cierta manera.
	
 	@return al ser una funcion void, no hace falta devovler nada ya que trabajamos directamente con la referencia.
*/

template <class T> void duplicarlista(list<T>& L) {

	// Primero me creo un axiliar para no tener que altera el L.end() en el bucle, 
	// ya que este iria variando
	
	list<int> L_aux(L);
	
	// Creamos una lista vacia, donde iremos metiendo los valores de L poco a poco.
	list<int> aux(0);
	
	//Luego creamos el iterador p, para poder ir guiandonos por las listas
	list<int>::iterator p = L_aux.begin();

	// Por ultimo nos creamos un indice para saber en que posicion nos encontramos
	int indice = distance(p, L_aux.begin()), cont = 0;


	for (p = L_aux.begin(); p != L_aux.end(); ) {

		// Vamos haciendo comparaciones para saber cuando meter el numero normal 
		// o aplicar la segunda condicion.
		if (indice % 2 == 0) {

			aux.push_back(L.front());
			L.pop_front();
			p++;
		}
		else {

			aux.push_back(L_aux.back() - cont);
			cont++;
		}

		indice++;
	}

	// Realizamos un ultimo push back para el ultimo valor restante, el cual se queda suelto.
	aux.push_back(L_aux.back() - cont);

	// Por ultmo, realizamos la copia de la lista de vuelta a L
	
	list<int> copia(aux);
	for (p = copia.begin(); p != copia.end(); p++) {

		L.push_back(aux.front());
		aux.pop_front();
	}

}

int main() {

	// Creamos la lista a traves de un array
	
	int arr1[] = { 1, 2, 3, 4, 5 };
	list<int> l1(arr1, arr1 + 5);

	// Mostramos la lista antes de ser modificada
	
	cout << "- Lista: ";
	for (auto v : l1)
		cout << v << " ";

	// Llamamos a la funcion
	
	duplicarlista(l1);

	cout << endl << "------------------------ \n";

	// Mostramos la nueva lista 
	
	cout << "- Lista nueva: ";
	for (auto v : l1)
		cout << v << " ";


	return 0;
}
