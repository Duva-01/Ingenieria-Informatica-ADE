// Febrero2020.cpp : David Martinez Diaz

#include <iostream>
#include "bintree.h"

#include <set>
#include <list>
#include <map>

using namespace std;


/*
    Ejercicio 1:

    a) El TDA APO puede usarse para representar una cola con prioridad --> Verdadero

    b) Puede hacerse la siguiente definiición prioritỵ_queue <int> :: iterator q; --> Falso

    c) Un ABB puede reconstruirse de de forma unívoca dado su recorrido en inorden --> Falso

    d) En un esquema de hashing cerrado, es correcto el uso como función hash de la función
    h(x)= M - (x% M) con M primo --> Falso

    e) No puede construirse un AVL de profundidad 4 que contenga como etiquetas los
    números enteros del 1 al 12 --> Falso

*/

/* Ejercicio 2 */

void recorrido(const bintree<int>::node n, queue<bintree<int>::node> cola) {

    if (!n.null()) {

        bintree<int>::node izqdo = n.left();
        bintree<int>::node drcho = n.right();

        cout << *n << " ";

        if (!izqdo.null() && !drcho.null()) {

            if (*izqdo < *drcho) {

                cola.push(drcho);
                recorrido(izqdo, cola);
            }

            else {

                cola.push(izqdo);
                recorrido(drcho, cola);
            }
        }

        else if (!izqdo.null() && drcho.null())
            recorrido(izqdo, cola);

        else if (izqdo.null() && !drcho.null())
            recorrido(drcho, cola);

        else {

            if (!cola.empty()) {

                bintree<int>::node siguiente = cola.front();
                cola.pop();
                recorrido(siguiente, cola);
            }

        }

    }

}

void GuideBinario(const bintree<int>& A) {

    queue<bintree<int>::node> micola;
    recorrido(A.root(), micola);
}

//-----------------------------------------------------------------------//

/* Ejercicio 4 */

void ordena_a_trozos(list<int>& L, int m) {

    set<int> conjunto;
    set<int>::iterator it_s;

    list<int>::iterator it = L.begin();

    list<int> aux;

    while (it != L.end()) {

        
        for (int i = 0; i < m && it != L.end(); i++) {

            conjunto.insert(*it);
            ++it;
        }

        for (it_s = conjunto.begin(); it_s != conjunto.end(); ++it_s)
            aux.push_back(*it_s);

        L.erase(L.begin(), it);

        conjunto.clear();

    }

    L = aux;


}

//-----------------------------------------------------------------------//

/* Ejercicio 6 */

class contenedor {

    private:
        map<pair<int, int>, int> datos; 
        static const int v_def;

    public: 
        
        pair < map<pair<int, int>, int>::iterator, bool > insert(pair<pair<int, int>, int> p) {

            pair < map<pair<int, int>, int>::iterator, bool > ret; 
            ret = datos.insert(p);
            return ret;
            
        }

        int& operatorll(const pair<int, int> p) {
            return datos[p];
        }
        
        friend ostream & operator«(ostream & os, const contenedor & cf){
            map<pair<int, int>, int >::const_iterator it; 

            for (it = cf.datos.cbegin(); it != cf.datos.cend(); ++it) 
                os << it->first.first << it->first.second << " " << it->second << endl;
          
            return os;

        }

        class iterator {

        private:

            map<pair<int, int>, int > ::iterator it, final;
            bool condicion(int a) {
                return a != v_def;
            }

        public:

            iterator() {}
            bool operator==(const iterator& i)const {
                return it == i.it;
            }

            bool operator!= (const iterator& i)const {
                return it != i.it;
            }

            pair<const pair<int, int>, int>& operator*() {
                return *it;
            }

            iterator& operator++() {

                ++it;
                while (it != final && !condicion(it->second)) {
                    ++it;
                }
                return *this;
            }
            friend class contenedor;

        };


        iterator begin() {

            iterator i;
            i.it = datos.begin();
            i.final = datos.end();

            if (!i.condicion(i.it->second))++i;
            return i;
        }

        iterator end() {

            iterator i;
            i.it = datos.end();
            i.final = datos.end();

        }
 };



int main(){

    //-----------------------------------------------------------------------//
    cout << "Ejercicio 2: " << endl;

    bintree<int> ab1(21);
    ab1.insert_left(ab1.root(), 8);
    ab1.insert_right(ab1.root(), 5);

    ab1.insert_left(ab1.root().left(), 10);
    ab1.insert_right(ab1.root().left(), 7);

    ab1.insert_left(ab1.root().right(), 4);
    ab1.insert_right(ab1.root().right(), 9);
    ab1.insert_right(ab1.root().right().left(), 2);

    cout << "- Preorden arbol 1: " << endl;

    for (bintree<int>::preorder_iterator i = ab1.begin_preorder(); i != ab1.end_preorder(); ++i) {
        cout << *i << " ";
    }

    cout << endl << "---------------------------------------" << endl;

    GuideBinario(ab1);

    //-----------------------------------------------------------------------//
    //-----------------------------------------------------------------------//

    cout << "Ejercicio 4: " << endl;

    list<int> milista = { 10, 1, 15, 7, 2, 12, 1, 9, 13, 3, 7, 6, 19, 15, 16, 11, 15};

    cout << endl << "Mi lista: " << endl;

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << "-";

    cout << endl << "-----------------------------------------" << endl;

    ordena_a_trozos(milista, 5);
    
    cout << endl << "Mi lista modificada: " << endl;

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << "-";

    cout << endl << "-----------------------------------------" << endl;

    return 0;

}


