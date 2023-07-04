/**
	DAVID MARTINEZ DIAZ
	
	GRUPO: GII-ADE
	
	RETO 3: EJERCICIO 44
*/

#include <iostream>
#include <list>
#include <iterator>
#include <cmath>
#include <vector>

using namespace std;

/**
	@brief devuelve en L aquella lista VL[j] que contiene la máxima cantidad de elementos 
	pares en el mismo orden. Solo debe devolver los elementos pares 
	
	@param VL, vector de lista, se almacenan todas las listas
	@param L, la sublista donde se va a guardar la secuencia.
	
 	@return al ser una funcion void, no hace falta devovler nada ya que trabajamos directamente con la referencia.
*/

void large_even_list(vector< list<int> >&VL,list<int>&L) {

	// Creamos una lista temporal para ir guardando las secuencias.
    list<int> tmp (0);
    
    // Creamos variables de control para ir sabiendo el tope.
    int tam_final, cont;
    
    // Creamos un iterador para ir pasando por la lista.
    list<int>::iterator aux;
    
    // Realizamos dos bucles uno grand epara ir eligiendo las lista y 
    // un segundo para ir guardando en tmp los numeros pares de cada lista.
    for (int n=0; n<VL.size(); n++){
        
        for (list<int>::iterator p = VL[n].begin(); p != VL[n].end(); p++){
            
            if(*p % 2 == 0){
                tmp.push_back(*p);
            }
        }

		// Si temporal es mas grande que la sublista anterior, lo sustituye.
            if (tmp.size()>L.size()){
            
                tam_final = L.size();
                for(cont = 0; cont < tam_final; cont++){
                    L.pop_front();
                }
            
                for(aux = tmp.begin(); aux != tmp.end(); aux++)
                    L.push_back(*aux);
            }
        
		// Finalmente vamos limpiando la lista temporal 
        tam_final = tmp.size();
        
        for(cont = 0; cont < tam_final; cont++)
            tmp.pop_front();
    }  
}

int main() {

	// Creamos las listas a traves de un array
	
	int arr1[] = { 0, 1, 2, 3, 4, 5, 7 };
	list<int> l1(arr1, arr1 + 7);
	
        int arr2[] = { 0, 1, 2, 3 };
        list<int> l2(arr2, arr2 + 4);
        
        int arr3[] = { 2, 2, 2, 1, 0 };
         list<int> l3(arr3, arr3 + 5);
        
        list<int> sublist (0);	
        
    // Tambien creamos nuestro vector y le asignamos las listas
    
        vector<list<int>> vect1;
        
        vect1.push_back(l1);
        vect1.push_back(l2);
        vect1.push_back(l3);
        
        int tam_v = 3;
        
	// Mostramos la lista antes de ser modificada
	
        for(int n=0; n<tam_v; n++){
            
            cout << "- Lista " << n <<": ";
            for (auto v : vect1[n])
                cout << v << " ";
            
            cout << endl;
        }
	
        
	// Llamamos a la funcion
	
	large_even_list (vect1, sublist);

	cout << endl << "------------------------ \n";
        
        cout << "- Sublista: ";
	for (auto v : sublist)
            cout << v << " ";
	
	return 0;
}
