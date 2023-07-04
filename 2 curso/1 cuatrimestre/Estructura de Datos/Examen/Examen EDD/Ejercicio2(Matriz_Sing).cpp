/*

	Autor: David Martinez Diaz
	
	Grupo: GII-ADE

	Fichero: Ejercicio2(Matriz_Sing).cpp

*/
//----------------------------------------------------------------//

/*	
	2 a) el operator() que devuelva el elemento en la fila fil, columna col.
	un iterador que itere sobre los elementos impares de la matriz. Han de implementarse
	(aparte de las de la clase iteradora) las funciones begin() y end().

*/

#include <vector>
#include <list>

class matriz_sing {

private:

    vector<list<int>> matriz;

public:

    int& operator()(int fila, int col) {

		// Me creo un contador para saber en que fila o columna me tengo que parar
		
        int cont_filas = 0;
        int cont_col = 0;
        
        for (vector<list<int>>::iterator it = matriz.begin(); it != matriz.end(); ++it) {

			// Comparo las filas y entro en las cols de la lista seleccionada
			
            if (cont_filas == fila) {

                for (list<int > ::iterator it_aux = (*it).begin(); it_aux != (*it).end(); ++it_aux){

					// Comparo las cols, si la encuentro devuelvo el valor de la lista
					
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

		// Me creo una funcion privada para poder utilizarlo de manera mas rapida
		
        bool condicion(list<int>& milista) {

            for (list<int>::iterator it = milista.begin(); it != milista.end(); ++it) {

				// Compruebo que el valor dentro de la lista no sea par si lo es, devuelvo false
				
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

			// Incremento una vez, para ver si el siguiente elemento es valido,
			// ya que no voy a coger el mismo que si la cumplia
			
            ++it;

			// Voy recorriendo hasta que encuentre con mi funcion condicion
			
            while (it != final && !condicion(*it)) {
                ++it;
            }

            return *this;
        }

		// Pongo friend class para que pueda utilizarla en la clase Matriz_sing
		
        friend class matriz_sing;

    };


    iterator begin() {

        iterator i;
        i.it = matriz.begin();
        i.final = matriz.end();

		// Mi inicio estara donde se cumpla por primera vez la condicion
		
        if (!i.condicion(*(i.it)))
			++i;
        return i;
    }

    iterator end() {

        iterator i;
        i.it = matriz.end();
        i.final = matriz.end();

    }

};
