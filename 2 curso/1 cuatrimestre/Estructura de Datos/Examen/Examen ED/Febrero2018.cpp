// Febrero2018.cpp : David Martinez Diaz
//

#include <iostream>
#include <list>
#include "bintree.h"
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

/* Ejercicio 1 */

void juntalista(list<int>& L, int n) {
    
    int suma;
    
    if (!L.empty()) {

        if (n > 0) {

            list<int>::iterator it_aux;
            for (list<int>::iterator it = L.begin(); it != L.end(); ) {

                it_aux = it;
                suma = 0;

                for (int i = 0; i < n && it != L.end(); i++) {

                    suma += *it;
                    ++it;
                }

                it = L.erase(it_aux, it);
                it = L.insert(it, suma);
                ++it;
            }

        }
    }
}

//-------------------------------------------------------------------------//

struct paciente {

    string dni;
    string nombre;
    string apellido;

};

class urgencias {

    private:
         
        map <int, paciente> datos;

    public:

        urgencias();

        pair <int, paciente> buscar_dni(string dni) {

            for (map<int, paciente>::iterator it = datos.begin(); it != datos.end(); ++it) {

                if (dni == (*it).second.dni) {
                    return *it;
                }
            }

        }

        map<int, paciente>::iterator buscar_dni_it(string dni) {

            for (map<int, paciente>::iterator it = datos.begin(); it != datos.end(); ++it) {

                if (dni == (*it).second.dni) {
                    return it;
                }
            }

        }

        pair <int, paciente> buscar_nombre(string nombre, string apellido) {

            for (map<int, paciente>::iterator it = datos.begin(); it != datos.end(); ++it) {

                if (nombre == (*it).second.nombre && apellido == (*it).second.apellido) {
                    return *it;
                }
            }

        }

        void insertar_paciente(string dni, string nombre, string apellidos, int gravedad) {

            pair<int, paciente> par;
            paciente persona;

            persona.dni = dni;
            persona.nombre = nombre;
            persona.apellido = apellidos;

            par.first = gravedad;
            par.second = persona;

            datos.insert(par);
        }

        void cambiar_gravedad(string dni, int nueva_gravedad) {

            pair<int, paciente> aux;
            aux = buscar_dni(dni);
            aux.first = nueva_gravedad;

            datos.erase(buscar_dni_it(dni));
            datos.insert(aux);
        }

};

//-------------------------------------------------------------------------//

/* Ejercicio 3 */

bool esABB(bintree<int> & A) {

    queue<bintree<int>::node> cola;

    cola.push(A.root());
    bool es_ABB = true;

    bintree<int>::node n;

    while (!cola.empty() && es_ABB) {

        n = cola.front();

        if (!n.left().null()) {

            if (*n.left() > * n)
                es_ABB = false;

            else {
                cola.push(n.left());
            }
        }

        if (!n.right().null()) {

            if (*n.right() < * n)
                es_ABB = false;

            else {

                cola.push(n.right());
            }
        }

        cola.pop();
    }

    return es_ABB;
}

//-------------------------------------------------------------------------//

/* Ejercicio 4 */

bool comparar_sets(set<int>& S1, set<int>& S2) {

    for (set<int>::iterator it = S1.begin(); it != S1.end(); ++it) {

        set<int>::iterator it_aux = S2.find(*it);
        if (it_aux == S2.end())
            return false;
    }

    return true;
}
bool inall(list<set<int>>& LS, set<int>& S) {

    bool check;

    for (list<set<int>>::iterator it = LS.begin(); it != LS.end(); ++it) {
         
        check = true;
        for (list<set<int>>::iterator it_aux = LS.begin(); it_aux != LS.end() && check; ++it_aux) {

            if (it_aux != it) {

                if (!comparar_sets(*it, *it_aux))
                    check = false;

            }
        }
        
        if (check) {
            S = *it;
            return true;
        }

    }

    return false;

}

//-------------------------------------------------------------------------//

/* Ejercicio 6 */

class contenedor {

    private:

        map<string, set<int>> datos;

    public:

        class iterator {

        private:

            map<string, set<int>>::iterator it, final;

            bool condicion(set<int> & S1) {

                for (set<int>::iterator it = S1.begin(); it != S1.end(); ++it) {
                    
                    if (*it < 20)
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

            pair<const string, set<int>>& operator*() {
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

    cout << "Ejercicio 1: " << endl;

    list<int> milista = { 1, 3, 2, 4, 5, 2, 2, 3, 5, 7, 4, 3, 2, 2 };

    cout << endl << "Mi lista: " << endl;

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << " ";

    juntalista(milista, 3);

    cout << endl << "Mi lista modificada: " << endl;

    for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it)
        cout << *it << " ";

    //-------------------------------------------------------------------------//
    
    cout << endl << "----------------------------------------------" << endl;

    cout << endl << "Ejercicio 3: " << endl;

    bintree<int> ab1(10);
    ab1.insert_left(ab1.root(), 7);
    ab1.insert_right(ab1.root(), 15);

    ab1.insert_left(ab1.root().left(), 6);
    ab1.insert_right(ab1.root().left(), 9);

    ab1.insert_left(ab1.root().right(), 12);
    ab1.insert_right(ab1.root().right(), 20);

    bool check = esABB(ab1);

    if (check) {

        cout << endl << "Es ABB." << endl;
    }

    else {
        cout << endl << "No es ABB." << endl;
    }

    //-------------------------------------------------------------------------//

    cout << endl << "----------------------------------------------" << endl;

    cout << endl << "Ejercicio 4: " << endl;

    list <set<int>> LS = { {1, 2, 3}, {2, 3, 4}, {0,2}, {2} };
    set<int> S;

    check = inall(LS, S);


    if (check) {

        cout << endl << "Encima se contiene: ";
    }
    else {

        cout << endl << "No le contiene" << endl;
    }

    
    for (set<int>::iterator it = S.begin(); it != S.end(); ++it)
        cout << *it << " ";

    cout << endl;

    return 0;
}

