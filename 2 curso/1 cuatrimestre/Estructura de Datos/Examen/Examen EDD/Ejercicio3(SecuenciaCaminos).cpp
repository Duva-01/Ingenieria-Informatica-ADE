/*

	Autor: David Martinez Diaz
	
	Grupo: GII-ADE

	Fichero: Ejercicio3(SecuenciaCaminos).cpp

*/
//----------------------------------------------------------------//

/*	
	3  Dado un árbol binario de enteros A y un nivel en el árbol level, implementar
	una función que encuentre los caminos de longitud mayor o igual que uno desde cualquier
	nodo de ese nivel a una hoja en el árbol. Devolver la solución en un vector de listas.

*/

#include <list>
#include <vector>
#include "bintree.h"

// En primer lugar me creo una funcion que me calcule la profundidad de un cierto node segun un
// arbol A, donde posteriormente lo metere en un par para ir comprobando

int calcula_profundidad(const bintree<int>& A, bintree<int>::node n) {

    int level=0;
    while (n != A.root()){
        n = n.parent();
        level++;
    }

    return level;
}

vector<list<int>> secuenciascaminos(bintree<int> A, int level) {

	// Me creo una cola de pares para poder ir recorriendo el arbol e ir metiendo los
	// pares en una lista
	
    queue < pair<int, bintree<int>::node>> cola;
    
    // Me creo varios pares para poder ir comparando, que tengan su nivel y su nodo
    
    pair<int, bintree<int>::node> par;
    pair<int, bintree<int>::node> par1;
    pair<int, bintree<int>::node> par2;

	// Meto la raiz tanto en la lista como en la cola
    par.first = 0;
    par.second = A.root();
    cola.push(par);

    list<pair<int, bintree<int>::node>> lista_aux;
    lista_aux.push_back(par);


	// Aqui en este bucle voy expandiendo la cola metiendome en sus hijos, a la vez que calculo su profundidad 
	// y los voy metiendo en la lista
	
    while (!cola.empty()) {

        par = cola.front();

        if (!par.second.left().null()) {

			// Le doy valores al par
			
            par1.first = calcula_profundidad(A, par.second.left());
            par1.second = par.second.left();
            
            // Lo inserto en la cola para recorrer sus hijos y tambien en la lista
            // para luego comparar
            
            cola.push(par1);
            lista_aux.push_back(par1);
        }

        if (!par.second.right().null()) {

			// Le doy valores al par
			
            par2.first = calcula_profundidad(A, par.second.right());
            par2.second = par.second.right();
            
            // Lo inserto en la cola para recorrer sus hijos y tambien en la lista
            // para luego comparar
            
            cola.push(par2);
            lista_aux.push_back(par2);
        }

        cola.pop();
    }


	// Una vez tengo la lista con todos los pares con sus respectivos niveles, me creo variables para poder comparar
	
	// Unas longitudes para ver cuanto de largo son los caminos y unas listas para ir metiendo esos caminos
    int longitud_1, longitud_2;
    list<int> lista_1, lista_2;
    
    //Luego me creo un iterador para que vaya recorriendo dentro segun entra en el nivel
    list<pair<int, bintree<int>::node>>::iterator it_aux;
    vector<list<int>> v;
 
    bintree<int>::node n_aux;

    for (list<pair<int, bintree<int>::node>>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it) {

        longitud_1 = 1;
        longitud_2 = 1;

		// Si el nodo es del nivel pedido entramos
		
        if ((*it).first == level) {

			// Utilizamos un iterador auxiliar
			
            it_aux = it;
            
            // Meto en las lista de comaparacion dicho nodo
            
            if (!(*it_aux).second.left().null() || !(*it_aux).second.right().null()) {
                lista_1.push_back(*(*it_aux).second);
                lista_2.push_back(*(*it_aux).second);
            }

			// Me meto dentro de ese nodo y voy recorriendo sus hijos
			
            if (!(*it_aux).second.left().null()) {
                
                n_aux = (*it_aux).second.left();

                while (!n_aux.left().null() || !n_aux.right().null()) {
			
					// Si tiene hijos los meto en la lista y subo la longitud
					
                    if (!n_aux.left().null()) {
                        lista_1.push_back(*n_aux.left());
                        longitud_1++;
                    }

                    else if (!n_aux.right().null()) {
                        lista_1.push_back(*n_aux.right());
                        longitud_1++;
                    }
                    
                    n_aux = (*n_aux).left();
                }

            }

            if (!(*it_aux).second.left().null()) {

                n_aux = (*it_aux).second.left();

                while (!n_aux.left().null() || !n_aux.right().null()) {

					// Si tiene hijos los meto en la lista y subo la longitud
					
                    if (!n_aux.left().null()) {
                        lista_2.push_back(*n_aux.left());
                        longitud_2++;
                    }

                    else if (!n_aux.right().null()) {
                        lista_2.push_back(*n_aux.right());
                        longitud_2++;
                    }
                    
                    n_aux = (*n_aux).right();
                }

            }
            
            // Si la longtiud es mayor de 1, cuenta como camino y lo inserto en el vector
            
            if(longitud_1 > 1)
                v.push_back(lista_1);

            else if (longitud_2 > 1)
                v.push_back(lista_2);

			// Limpio las listas y vuelvo a comparar
			
            lista_1.clear();
            lista_2.clear();
        }

    }


	return v;
}

