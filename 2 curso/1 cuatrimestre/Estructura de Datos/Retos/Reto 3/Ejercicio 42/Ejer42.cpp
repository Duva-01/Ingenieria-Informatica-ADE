/**
	DAVID MARTINEZ DIAZ
	
	GRUPO: GII-ADE
	
	RETO 3: EJERCICIO 42
*/

#include <iostream>
#include <list>
#include <iterator>
#include <cmath>

using namespace std;

/**
	@brief Esta funcion dada una lista de enteros, L encuentre y devuelva la sublista más larga de
	elementos consecutivos todos ellos pares. Si hay varias con el mismo tamaño, debe devolver cualquiera de ellas.  
	
	@param L, la lista pasada por referencia que queremos observar.
	@param subl, la lista donde le pasaremos la secuencia mas pequeña.
	
 	@return el tamaño de la lista.
*/

int max_sublist_par(list<int> &L, list<int> &subl) {

	// Flags de estado para saber si limpiar o comparar.
    bool comparar = false, reset = false;
    
    // Lista auxiliar para ir guardando las secuencias
    list<int> tmp (0);
    
    // Variables de control
    int tam_final, cont; 
    
    // Iterador auxiliar
    list<int>::iterator aux;
    
    for (list<int>::iterator p = L.begin(); p != L.end(); p++){
        
        // Reseteamos el tmp
        if (reset){
            
            tam_final = tmp.size();
            for(cont = 0; cont < tam_final; cont++){
                tmp.pop_front();
            }
            reset = false;
        }
        
        // Comparamos valores si son pares.
        if(*p % 2 == 0){
            
            tmp.push_back(*p);
        }
        
        if(*p % 2 != 0 && tmp.size()>0){
            comparar = true;
        }
        
        // Comparamos las sublistas auxiliares
        if (comparar && tmp.size()>subl.size()){
            
            tam_final = subl.size();
            for(cont = 0; cont < tam_final; cont++){
                subl.pop_front();
            }
            
            for(aux = tmp.begin(); aux != tmp.end(); aux++)
                subl.push_back(*aux);
            
            comparar = false;
            reset = true;
        }
        
    }
    
    // Devolvemos el tamaño de la sublista
    return subl.size();
}

int main() {

	// Creamos la lista a traves de un array
	
	int arr1[] = { 5, 4, 5, 8, 6, 2, 10, 9, 3, 1 };
	list<int> l1(arr1, arr1 + 10);
	
        list<int> sublist (0);	
	// Mostramos la lista antes de ser modificada
	
	cout << "- Lista 1: ";
	for (auto v : l1)
            cout << v << " ";
        
	// Llamamos a la funcion
	
	int tam = max_sublist_par(l1, sublist);

	cout << endl << "------------------------ \n";
        
        cout << "- Sublista [" << tam << "]: ";
	for (auto v : sublist)
            cout << v << " ";
	
	return 0;
}
