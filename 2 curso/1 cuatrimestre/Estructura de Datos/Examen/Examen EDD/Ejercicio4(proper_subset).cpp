/*

	Autor: David Martinez Diaz
	
	Grupo: GII-ADE

	Fichero: Ejercicio4(proper_subset).cpp

*/
//----------------------------------------------------------------//

/*	
	4  Dada una lista de conjuntos list< set<int> > L, implementar una función
 	que devuelve true si los conjuntos de la lista L son subconjuntos propios en forma
	consecutiva. Es decir, si L = (A0,A1, ....,An-1), debe ocurrir que que Aj Aj+1 para j = ?
	0, ..., n - 2. (A B indica inclusión propia, es decir A B y A != B.) 

*/


#include <set>
#include <list>

// En primer lugar tengo una funcion que me permite ver si S1 se encuentra dentro de S2

bool comparar_sets(set<int>& S1, set<int>& S2) {

	// Si son el mismo no nos vale
	
    if (S1 == S2)
        return false;

	// Voy comprobando uno a uno, y con la funcion find() veo si encuentro el valor
	// Si apunta a end() quiere decir que no es subconjunto y devuelvo false
	
    for (set<int>::iterator it = S1.begin(); it != S1.end(); ++it) {

        set<int>::iterator it_aux = S2.find(*it);
        if (it_aux == S2.end())
            return false;
    }

    return true;
}

bool proper_subset(list< set<int> >& L) {

	// Booleano de comprobacion
    bool check = true;
    
    // Me creo un iterado auxiliar que vaya 1 posicion por delante
    
    list<set<int>>::iterator it_aux = L.begin();
    ++it_aux;

	// Recorro la lista de sets y voy llamando a la funcion, si se cumple check es true sino false
	
    for (list<set<int>>::iterator it = L.begin(); it != L.end() && it_aux!=L.end(); ++it) {

        if (!comparar_sets(*it, *it_aux))
             check = false;

        it_aux++;
    }

	// Devuelvo el booleano
	
    return check;

}
