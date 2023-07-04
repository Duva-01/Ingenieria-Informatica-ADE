// Enero2018.cpp : David Martinez Diaz
//

#include <iostream>
#include "bintree.h"

using namespace std;

/* 
    Ejercicio 1:

    (a) La definición priority_queue<int>::iterator p; es correcta. <-- Falso

    (b) Dado un árbol binario cuyas etiquetas están organizadas como un AVL, puedo
    recuperarlo de forma unívoca a partir de su recorrido en inorden. <-- Falso

    (c) El elemento de valor máximo en un ABB<int> se encuentra en el nodo más
    profundo. <-- Falso

    (d) Considerar un map <int, int> M en el que hacemos M[3]=7; Supongamos ==> (3,7) --> p.second = 9 --> (3,9)
    ahora que hacemos
        
        map <int, int> :: iterator p = M. find(3);
        p → second =9;
        Tras hacer eso, el valor de M[3] sigue siendo 7

    Falso

    (e) Si A es una tabla hash cerrada con un 50% de elementos vacíos y un 40% de
    elementos borrados y B una tabla hash cerrada con un 50% de elementos vacíos y
    sin elementos borrados, A y B son igual de eficientes cara a la búsqueda de un
    elemento. <-- Falso
    
*/

//----------------------------------------------------------------------//

#include <set>
#include <list>

bool comparar_sets(set<int>& S1, set<int>& S2) {

    if (S1 == S2)
        return false;

    for (set<int>::iterator it = S1.begin(); it != S1.end(); ++it) {

        set<int>::iterator it_aux = S2.find(*it);
        if (it_aux == S2.end())
            return false;
    }

    return true;
}

bool proper_subset(list< set<int> >& L) {

    bool check = true;
    list<set<int>>::iterator it_aux = L.begin();
    ++it_aux;

    for (list<set<int>>::iterator it = L.begin(); it != L.end() && it_aux!=L.end(); ++it) {

        if (!comparar_sets(*it, *it_aux))
             check = false;

        it_aux++;
    }

    return check;

}

bool contenido(set<int> &contenedor, set<int> &contenido) {

    set<int>::iterator ite = contenedor.begin();

    for (ite; ite != contenedor.end(); ++ite) {

        set<int>::iterator ite_aux = contenido.find(*ite);
        if (ite_aux == contenido.end())
            return false;
    }

    return true;
}

bool migue(list< set<int> >& L) {

    list<set<int>>::iterator it_aux = L.begin();

    list<set<int>>::iterator ite = L.begin();
    set<int>::iterator ite_S;
    set<int>::iterator ite2_S = (*ite).begin();
    ++ite2_S;
    bool esta_contenido = true;

    for (ite; ite != L.end(); ++ite) {

        esta_contenido = true;
        for (ite_S = (*ite).begin(); ite_S != (*ite).end() && esta_contenido; ++ite_S) {

            if (contenido(*ite_S, *ite2_S) == false) {

                esta_contenido = false;
            }

        }

        if (esta_contenido) {

            return true;
        }
    }

    return false;

}






















#include <list>
#include <vector>

int calcula_profundidad(const bintree<int>& A, bintree<int>::node n) {

    int nivel = 0;

    while (n != A.root()) {

        n = n.parent();
        nivel++;
    }

    return nivel;
}

vector<list<int>> secuenciascaminos(bintree<int> A, int level) {

    queue < pair<int, bintree<int>::node>> cola;
    pair<int, bintree<int>::node> par;

    pair<int, bintree<int>::node> par1;
    pair<int, bintree<int>::node> par2;

    par.first = 0;
    par.second = A.root();

    cola.push(par);

    list<pair<int, bintree<int>::node>> lista_aux;

    lista_aux.push_back(par);

    while (!cola.empty()) {

        par = cola.front();

        if (!par.second.left().null()) {

            par1.first = calcula_profundidad(A, par.second.left());
            par1.second = par.second.left();
            cola.push(par1);
            lista_aux.push_back(par1);
        }

        if (!par.second.right().null()) {

            par2.first = calcula_profundidad(A, par.second.right());
            par2.second = par.second.right();
            cola.push(par2);
            lista_aux.push_back(par2);
        }

        cola.pop();
    }

    int longitud_1, longitud_2;
    list<pair<int, bintree<int>::node>>::iterator it_aux;
    vector<list<int>> v;

    list<int> lista_1, lista_2;
    bintree<int>::node n_aux;

    for (list<pair<int, bintree<int>::node>>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it) {

        longitud_1 = 1;
        longitud_2 = 1;

        if ((*it).first == level) {

            it_aux = it;
            if (!(*it_aux).second.left().null() || !(*it_aux).second.right().null()) {
                lista_1.push_back(*(*it_aux).second);
                lista_2.push_back(*(*it_aux).second);
            }

            if (!(*it_aux).second.left().null()) {
                
                n_aux = (*it_aux).second.left();

                while (!n_aux.left().null() || !n_aux.right().null()) {


                    if (!n_aux.left().null()) {
                        lista_1.push_back(*n_aux.left());
                        longitud_1++;
                    }

                    else if (!n_aux.right().null()) {
                        lista_1.push_back(*n_aux.right());
                        longitud_1++;
                    }
                }

            }

            if (!(*it_aux).second.left().null()) {

                n_aux = (*it_aux).second.left();

                while (!n_aux.left().null() || !n_aux.right().null()) {


                    if (!n_aux.left().null()) {
                        lista_2.push_back(*n_aux.left());
                        longitud_2++;
                    }

                    else if (!n_aux.right().null()) {
                        lista_2.push_back(*n_aux.right());
                        longitud_2++;
                    }
                }

            }
            
            if(longitud_1 > 1)
                v.push_back(lista_1);

            else if (longitud_2 > 1)
                v.push_back(lista_2);

            lista_1.clear();
            lista_2.clear();
        }

    }

}
















/* Ejercicio 2 */

#include <map>
#include <set>


// string --> set<int>

#include <vector>


class matriz_sing {

private:

    vector<list<int>> matriz;

public:

    int& operator()(int fila, int col) {

        int cont_filas = 0;
        int cont_col = 0;
        for (vector<list<int>>::iterator it = matriz.begin(); it != matriz.end(); ++it) {

            if (cont_filas == fila) {

                for (list<int > ::iterator it_aux = (*it).begin(); it_aux != (*it).end(); ++it_aux){

                    if (col == cont_col) {
                        return *it_aux;
                    }
                    cont_col++;
                }

            }

            cont_filas++;
        }

    }

    class iterator {

    private:

        vector<list<int>>::iterator it, final;

        bool condicion(list<int>& L) {

            for (list<int>::iterator it = L.begin(); it != L.end(); ++it) {

                if (*it % 2 == 0)
                    return false;
            }

            return true;
        }

    public:

        iterator() {}
        bool operator==(const iterator& i)const {
            return it == i.it;
        }

        bool operator!= (const iterator& i)const {
            return it != i.it;
        }

        list<int> & operator*() {
            return *it;
        }

        iterator& operator++() {

            ++it;

            while (it != final && !condicion(*it)) {
                ++it;
            }

            return *this;
        }

        friend class matriz_sing;

    };


    iterator begin() {

        iterator i;
        i.it = matriz.begin();
        i.final = matriz.end();

        if (!i.condicion(*(i.it)))++i;
        return i;
    }

    iterator end() {

        iterator i;
        i.it = matriz.end();
        i.final = matriz.end();

    }

};

class documentos {

    private:

        map<string, set<int>> datos;
    
    public:

        documentos(const list<string>& texto) {

            int cont = 0;
            for (list<string>::const_iterator it = texto.cbegin(); it != texto.cend(); ++it) {
                
                datos[*it].insert(cont);
                cont++; 
            }
        }

        set<int> posiciones(string palabra) const {

            map<string, set<int>>::const_iterator it = datos.find(palabra);

            if(it != datos.end())
                return (*it).second;
        }

        string palabra(int i) const {

            set<int>::iterator it_s;

            for (map<string, set<int>>::const_iterator it = datos.cbegin(); it != datos.cend(); ++it) {

                it_s = (*it).second.find(i);

                if (it_s != (*it).second.end())
                    return (*it).first;
            }

        }
};

//-----------------------------------------------------------------------------//

/* Ejercicio 3 */

void reemplaza(list<int>& l, const list<int>& seq, const list<int>& reemp){

    list<int>::iterator lit, it_find;
    list<int>::const_iterator seq_it, reem_it;

    lit = l.begin();

    while (lit != l.end()) {

        it_find = lit;
        seq_it = seq.cbegin();

        while (it_find != l.end() && seq_it != seq.cend() && *it_find == *seq_it) {
            ++it_find;
            ++seq_it;
        }

        if (seq_it == seq.cend()) {

            lit = l.erase(lit, it_find);
            reem_it = reemp.cbegin();

            while (reem_it != reemp.cend()) {
                lit = l.insert(lit, *reem_it);
                ++lit;
                ++reem_it;
            }

        }

        else ++lit;
    }



}

//-----------------------------------------------------------------------------//
//-----------------------------------------------------------------------------//

/* Ejercicio 4 */

#include <queue>
int calcula_profundidad(const bintree<int> & A, bintree<int>::node n) {

    int nivel = 0;

    while (n != A.root()) {

        n = n.parent();
        nivel++;
    }

    return nivel;
}


list<int> nivel(const bintree<int>& A) {

    queue < pair<int, bintree<int>::node>> cola;
    pair<int, bintree<int>::node> par;

    pair<int, bintree<int>::node> par1;
    pair<int, bintree<int>::node> par2;

    par.first = 0;
    par.second = A.root();

    cola.push(par);
    
    list<pair<int, bintree<int>::node>> lista_aux;

    while (!cola.empty()) {

        par = cola.front();

        if (!par.second.left().null()) {

            par1.first = calcula_profundidad(A, par.second.left());
            par1.second = par.second.left();
            cola.push(par1);
            lista_aux.push_back(par1);
        }

        if (!par.second.right().null()) {

            par2.first = calcula_profundidad(A, par.second.right());
            par2.second = par.second.right();
            cola.push(par2);
            lista_aux.push_back(par2);
        }

        
        cola.pop();
    }

    list<int> lista_cmp;
    list<int> lista_best;

    int nivel_maximo = 0;

    for (list<pair<int, bintree<int>::node>>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it) {

        if (nivel_maximo < (*it).first)
            nivel_maximo = (*it).first;

    }


    for (int cont = 0; cont <= nivel_maximo; cont++) {

        for (list<pair<int, bintree<int>::node>>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it) {

            if (cont == (*it).first)
                lista_cmp.push_back(*(*it).second);

        }

        if (lista_cmp.size() > lista_best.size()) {
            lista_best.clear();
            lista_best = lista_cmp;
        }

        lista_cmp.clear();

    }

    
    return lista_best;
}

//-----------------------------------------------------------------------------//

/* Ejercicio 6 */

#include <unordered_map>

template<typename T>
class contenedor {

private:

    unordered_map<T, list<int> datos;

public:

    class iterator {

    private:

        map<string, set<int>>::iterator it, final;

        bool condicion(list<int> & L) {

            for (list<int>::iterator it = L.begin(); it != L.end(); ++it) {

                if (*it % 2 != 0)
                    return false;
            }

            return true;
        }

    public:

        iterator() {}
        bool operator==(const iterator& i)const {
            return it == i.it;
        }

        bool operator!= (const iterator& i)const {
            return it != i.it;
        }

        pair<const string, list<int>>& operator*() {
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

    bintree<int> ab1(10);
    ab1.insert_left(ab1.root(), 7);
    ab1.insert_right(ab1.root(), 15);

    ab1.insert_left(ab1.root().left(), 6);
    ab1.insert_right(ab1.root().left(), 9);

    ab1.insert_left(ab1.root().right(), 12);
    ab1.insert_right(ab1.root().right(), 20);

    list<int> milista = nivel(ab1);

    cout << endl << "Lista del nivel: ";

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << " ";

    cout << endl;


    return 0;
}

