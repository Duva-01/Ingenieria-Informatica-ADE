// Febrero2017.cpp : David Martinez Diaz

#include <iostream>

using namespace std;

/*

    Ejercicio 1:

    a) El orden en que las hojas se listan en los recorridos preorden, inorden y postorden de un
    arbol binario es el mismo en los tres caso. <-- Verdadero

    b) Dado un arbol binario cuyas etiquetas estan organizadas como un arbol binario de  busqueda 
    puede recuperarlo a partir de su preorden. <-- Verdadero

    c) Dado un arbol binario cuyas etiquetas estan organizadas como un arbol parcialmente ordenado, puedo 
    recuperarlo a partir de su postorden. <-- Verdadero

    d) Es correcto en un esquema de hashing cerrado el uso como funcion hash de la funcion h(k) = [k + ramdom(M)] % M
    M primo y con ramodm(M) una funcion que devuelve un numero entero aleatorio entre 0 y M-1. <-- Falso

    e) Es correcto es un esquema de hashing doble el uso como funcion hash secundaria de la funcion 
    h0(x)= [(B-1)-(x%B)] con B primo. <-- Falso

*/

//-----------------------------------------------------------------------------//

/* Ejercicio 2 */

#include <list>

struct enfrentamiento {

    unsigned char eq1, eq2;
    unsigned int puntos_eq1, puntos_eq2;
};

class liga {

    private:

        list <enfrentamiento> res;

    public:

        int ganados(unsigned char nombre) {

            int contador = 0;

            for (list <enfrentamiento>::iterator it = res.begin(); it != res.end(); ++it) {

                if ((*it).eq1 == nombre && (*it).puntos_eq1 > (*it).puntos_eq2)
                    contador++;

                else if ((*it).eq2 == nombre && (*it).puntos_eq2 > (*it).puntos_eq1)
                    contador++;

            }

            return contador;
        }

        class iterator {

        private:

            list<enfrentamiento>::iterator it, final;

            bool condicion(enfrentamiento& L) {

                if (L.puntos_eq1 != L.puntos_eq2)
                    return false;

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

            enfrentamiento & operator*() {
                return *it;
            }

            iterator& operator++() {

                ++it;

                while (it != final && !condicion(*it)) {
                    ++it;
                }

                return *this;
            }

            friend class liga;

        };


        iterator begin() {

            iterator i;
            i.it = res.begin();
            i.final = res.end();

            if (!i.condicion(*i.it))++i;
            return i;
        }

        iterator end() {

            iterator i;
            i.it = res.end();
            i.final = res.end();

        }

};

//-----------------------------------------------------------------------------//

/* Ejercicio 3 */

int orden(const list<int>& L) {

    list<int>::const_iterator it_aux = L.cbegin();
    it_aux++;

    bool ascendente = true, descendente = true;

    for (list<int>::const_iterator it = L.cbegin(); it != L.cend() && it_aux != L.cend(); ++it) {

        if (*it > * it_aux) {
            ascendente = false;
        }

        else if (*it < *it_aux) {
            descendente = false;
        }

        it_aux++;
    }

    if (ascendente) {
        return 1;
    }

    else if (descendente) {
        return 2;
    }

    else {  
        return 0;
    }


}

//-----------------------------------------------------------------------------//

/* Ejercicio 4 */

#include "bintree.h"

int calcula_profundidad(const bintree<int>& A, bintree<int>::node n) {

    int nivel = 0;

    while (n != A.root()) {

        n = n.parent();
        nivel++;
    }

    return nivel;
}

void ImprimirProfundidad(const bintree<int>& A) {

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

        //---------------------------------------------------------//

        int nivel_maximo = 0;

        for (list<pair<int, bintree<int>::node>>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it) {

            if (nivel_maximo < (*it).first)
                nivel_maximo = (*it).first;

        }


        cout << endl << "- Lista con los nodos de mayor profundidad a menos: ";

        for (int cont = nivel_maximo; cont >= 0; cont--) {

            for (list<pair<int, bintree<int>::node>>::iterator it = lista_aux.begin(); it != lista_aux.end(); ++it) {

                if (cont == (*it).first)
                    cout << *(*it).second << " ";

            }
        }

        cout << endl << endl;
}

//-----------------------------------------------------------------------------//

/* Ejercicio 5 */

#include <unordered_map>

int suma_arbol(const bintree<int>& A) {

    int suma = 0;

    for (bintree<int>::const_preorder_iterator it = A.begin_preorder(); it != A.end_preorder(); ++it)
        suma += *it;

    return suma;
}


template <typename T>
class contenedor {

    private:

        unordered_map<T, bintree<int>> datos;

    public:

        class iterator {

        private:

            unordered_map<T, bintree<int>>::iterator it, final;

            bool condicion(const bintree<int> & A) {

                if (suma_arbol(A) % 2 != 0)
                    return false;

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

            pair<T, bintree<int>> & operator*() {
                return *it;
            }

            iterator& operator++() {

                ++it;

                while (it != final && !condicion(*it)) {
                    ++it;
                }

                return *this;
            }

            friend class liga;

        };


        iterator begin() {

            iterator i;
            i.it = datos.begin();
            i.final = datos.end();

            if (!i.condicion(*i.it))++i;
            return i;
        }

        iterator end() {

            iterator i;
            i.it = datos.end();
            i.final = datos.end();

        }

};

//-----------------------------------------------------------------------------//

/* Ejercicio 6 */





int main(){
   
    
    cout << "Ejercicio 3: " << endl;

    list<int> milista = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    //list<int> milista = { 12, 9, 6, 2, 1 };
    //list<int> milista = { 1, 2, 3, 10, 5, 6, 7, 8, 9 };
    cout << endl << "Mi lista: " << endl;

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << " ";

    int opcion = orden(milista);

    if (opcion == 1) {
        cout << endl << "Lista en orden ascendente" << endl;
    }
    else if (opcion == 2) {
        cout << endl << "Lista en orden descendente" << endl;
    }
    
    else {

        cout << endl << "Lista no ordenada" << endl;
    }
   

    //-----------------------------------------------------------------------------//
    //-----------------------------------------------------------------------------//

    cout << "Ejercicio 4: " << endl;

    bintree<int> ab1(5);
    ab1.insert_left(ab1.root(), 3);
    ab1.insert_right(ab1.root(), 8);

    ab1.insert_left(ab1.root().left(), 1);
    ab1.insert_right(ab1.root().left(), 4);

    ab1.insert_left(ab1.root().right(), 6);
    ab1.insert_right(ab1.root().right(), 9);
    ab1.insert_right(ab1.root().right().left(), 7);

    ImprimirProfundidad(ab1);

    //-----------------------------------------------------------------------------//
    //-----------------------------------------------------------------------------//

    return 0;
}
