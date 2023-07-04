/**
	DAVID MARTINEZ DIAZ
	
	GRUPO: GII-ADE
	
	RETO 3: EJERCICIO 34
*/

#include <iostream>
#include <list>
#include <iterator>
#include <cmath>

using namespace std;

/**
	@brief Esta funcion que devuelve true si la lista L1 es mayor que la L2 
 *             en sentido “lexicográfico”, y false en caso contrario. 
	
	@param L1, la priemra lista pasada que queremos comparar de cierta manera.
	@param L2, la segunda lista pasada que queremos comparar de cierta manera.
	
 	@return bool, devuelve true si L1 es mayor y false para los demas casos.
*/

bool lexicord (list<int> L1, list<int> L2){

	// Creamos un bool local para retornar
	
    bool mayor = false;
    
    // Creamos los 2 iteradores para comparar
    
    list<int>::iterator p2 = L2.begin();
    list<int>::iterator p1 = L1.begin();
    
    for (p1 = L1.begin(); p1 != L1.end() && mayor != true && p2 != L2.end(); ){
        
        // Comparamos valores
        if (*p1 > *p2){
            
            mayor = true;
        }
        
        // Si en algun caso, se llegase a superar a L1, se devuelve false inmediatamente.
        
        else if(*p1 < *p2) {
            
            return false;
        }
        
        p1++;
        p2 ++;
    }
    
    // Una vez salidos del bucle, si mayor sigue siendo false, comparamos los size, si L1 es
    // mas grande le devolvemos true
    if (!mayor && (L1.size() > L2.size())){
        mayor = true;
    }

    return mayor;
}

int main() {

	// Creamos la lista a traves de un array
	
	int arr1[] = { 1, 3, 2, 4, 6 };
	list<int> l1(arr1, arr1 + 5);
        
        int arr2[] = { 1, 3, 2, 5};
	list<int> l2(arr2, arr2 + 4);
	
	
	// Mostramos la lista antes de ser modificada
	
	cout << "- Lista 1: ";
	for (auto v : l1)
            cout << v << " ";

        
        cout << "- Lista 2: ";
	for (auto v : l2)
            cout << v << " ";
        
	// Llamamos a la funcion
	
	bool mayor = lexicord(l1,l2);

	cout << endl << "------------------------ \n";

	if(mayor){
            
            cout << "La lista 1 es mayor en sentido lexicografico.";
        }
        else {
            
            cout << "La lista 1 no es mayor en sentido lexicografico.";
        }


	return 0;
}
