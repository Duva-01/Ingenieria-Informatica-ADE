// Enero2020.cpp : David Martinez Diaz

#include <iostream>
#include "bintree.h"

#include <list>
#include <vector>
#include <set>

using namespace std;


/*

    Ejercicio 1:

    a) Dados dos nodos n1 y n2 en un árbol binario T y dadas las distancias (longitudes de los
    caminos) m1 y m2 de ambos nodos a su antecesor común más cercano (nodo más
    profundo que tiene tanto a n1 como a n2 como descendientes): 
    
        1-a: Si m1=m2=0 los nodos son el mismo nodo 
        1-b: Si m1=0 y m2>0: n2 es sucesor de n1 
        1-c: Si m1=m2=1 los nodos son hermanos; 
        1-d: Todo lo anterior es cierto <--- CORRECTA

    b) Si inserto las claves {15, 7, 11, 23,18, 19, 9, 30, 1} en un AVL de enteros, 
    
        2-a: Hay que hacer dos rotaciones simples y una rotación doble 
        2-b: Hay que hacer tres rotaciones dobles, 
        2-c: Hay que hacer dos rotaciónes dobles 
        2-d: Todo lo anterior es falso <--- CORRECTA

    c) Dados los siguientes recorridos en preorden = (C B F C I H G A J D E), y postorden
    = (F I C B H A D J E G C) 
    
        3-a: No hay ningún árbol binario con esos recorridos asociados; <--- CORRECTA
        3-b: Hay 1 solo árbol binario con esos recorridos asociados: 
        3-c: Hay dos árboles binarios con esos recorridos asociados; 
        3-d: Hay múltiples árboles binarios con esos recorridos asociados;

    d) Dado el siguiente fragmento de código: {map <int,int> M; M[0]=1; map <int,int> ::iterator p; p=M.find(7);}
    ¿Cual de las siguientes afirmaciones es verdadera?

        4-a: M no se modifica y p->first=7 
        4-b: M se modifica y p ->first=7
        4-c: Da un error 
        4-d: M se modifica y p=M.end() <--- CORRECTA
*/

//------------------------------------------------------------------//

/* Ejercicio 2 */

#include <map>
#include <vector>

class conjunto_letras {

private:

    map<char, int> datos;

public:

    conjunto_letras(const vector<char>& orig) {

        vector<char>::const_iterator it = orig.cbegin();
        int contador = 1;

        pair<char, int> aux;

        aux.first = (*it);
        aux.second = 1;

        //El vector esta lleno mamon!

        while (it != orig.cend()) {


            if (aux.first == (*it)) {

                aux.second++;
            }
            else {
                datos.insert(aux);

                aux.first = (*it);
                aux.second = 1;

            }

            ++it;
        }

    }

    char getletra(int posicion)const {

        int contador = 0;
        map<char, int>::const_iterator it = datos.begin();

        while (it != datos.end() && contador < posicion) {

            contador += (*it).second;
            ++it;
        }
        if (it != datos.end()) {

            return (*it).first;
        }
        else {
            return 0;
        }

    }


    class iterator {


    private:
        map<char, int>::iterator it, final;


    public:

        iterator() {}

        iterator(const iterator& orig) {

            it = orig.it;
            final = orig.final;
        }

        iterator& operator=(const iterator& orig) {

            it = orig.it;
            final = orig.final;

            return *this;
        }

        bool operator==(const iterator& i)const {
            return it == i.it;
        }

        bool operator!= (const iterator& i)const {
            return it != i.it;
        }

        pair<const char, int>& operator*() {
            return *it;
        }

        iterator& operator++() {

            bool check = true;
            ++it;

            while (it != final && check) {
                if (((*it).second % 2) != 0) {

                    ++it;
                }
                else {
                    check = false;
                }


            }
            return *this;
        }




        friend class conjunto_letras;
    };



    iterator begin() {

        iterator ite;

        ite.it = datos.begin();

        ite.final = datos.end();

        if (((*ite).second % 2) != 0) {

            ++ite;
        }

        return ite;
    }

    iterator end() {
        iterator ite;

        ite.it = datos.begin();

        ite.final = datos.end();

        return ite;

    }
};


//------------------------------------------------------------------//

/* Ejercicio 3 */

int calcula_suma(list<int> l) {

    int result = 0;

    for (int n : l)
        result += n;

    return result;
}

int minsum(const list<int>& L) {

    list<int> actual, best;

    for (auto it = L.begin(); it != L.end(); ++it) {

        actual.push_back(*it);
        if (calcula_suma(actual) >= 0)
            actual.clear();

        else if (calcula_suma(actual) < calcula_suma(best))
            best = actual;
        
    }

    return calcula_suma(best);
}

/* Ejercicio 4 */

pair<int, list<int>> camino(bintree<int>::node n) {

    if (n.null()) {
        
        return pair <int, list<int>> (numeric_limits<int>::max(), list<int>());
    }
    else if (n.left().null() && n.right().null()) {
        pair<int, list<int>> aux(*n, list<int>(1, *n));
        return aux;
    }
    
    else {

        pair<int, list<int>> aux_izq = camino(n.left());
        pair<int, list<int>> aux_drch = camino(n.right());

        if (aux_izq.first < aux_drch.first) {

            aux_izq.second.push_back(*n);
            aux_izq.first += *n;
            return aux_izq;
        }
        else {

            aux_drch.second.push_back(*n);
            aux_drch.first += *n;
            return aux_drch;
        }
    }


}
list<int> caminodemenores(const bintree<int>& A) {

    return camino(A.root()).second;

}

/* Ejercicio 5 */

bool hay_interseccion(const set<int>& set1, const set<int>& set2) {
    
    for(set<int>::iterator it = set1.begin(); it != set1.end(); ++it){
    
        if (set2.count(*it) > 0)
            return false;
    }

    return true;
}

int mas_conectado(const vector<set<int>>& v) {

    vector<int> contador(v.size(), 0);

    for (int i = 0; i < v.size(); i++) {

        for (int j = i + 1; j < v.size(); j++) {

            if (!hay_interseccion(v[i], v[j])) {
                contador[i]++;
                contador[j]++;
            }
        }
    }

    int pos_best = -1;
    int cont_best = -1;

    for (int i = 0; i < contador.size(); i++) {

        if (cont_best < contador[i]) {
            pos_best = i;
            cont_best = contador[i];
        }
    }

    return pos_best;
}



int main() {
   
    cout << "Ejercicio 3: " << endl;

    list<int> milista = { 1, -2, 3, -3, -1, 2, 5 };

    cout << endl << "Mi lista: " << endl;

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << " ";

    int valor = minsum(milista);

    cout << "El valor minimo de la sumatoria: " << valor;
    cout << endl << "-----------------------------------------" << endl;
    //---------------------------------------------------------------------------//
    
    cout << endl <<  "Ejercicio 4: " << endl;

    bintree<int> ab1(1);
    ab1.insert_left(ab1.root(), 14);
    ab1.insert_right(ab1.root(), 5);

    ab1.insert_left(ab1.root().left(), 77);
    ab1.insert_right(ab1.root().left(), 6);

    ab1.insert_left(ab1.root().left().right(), 3);
    ab1.insert_right(ab1.root().left().right(), 8);

    ab1.insert_left(ab1.root().right(), 109);

    list<int> lista_aux = caminodemenores(ab1);

    cout << endl << "Mi lista: " << endl;

    for (list<int>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it)
        cout << *it << " ";

    cout << endl << "-----------------------------------------" << endl;

    return 0;

}


