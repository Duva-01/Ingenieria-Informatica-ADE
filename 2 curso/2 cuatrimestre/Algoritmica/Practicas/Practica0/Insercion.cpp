// David Martinez Diaz

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <random>

using namespace std;

/* ************************************************************ */
/*  Metodo de ordenacion por insercion  */

/**
   @brief Ordena un vector por el m?todo de inserci?n.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n?mero de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de inserci?n.
*/

inline static
void insercion(int T[], int num_elem);



/**
   @brief Ordena parte de un vector por el m?todo de inserci?n.

   @param T: vector de elementos. Tiene un n?mero de elementos
                   mayor o igual a final. Es MODIFICADO.
   @param inicial: Posici?n que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posici?n detr?s de la ?ltima de la parte del
                   vector a ordenar.
           inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de inserci?n.
*/

static void insercion_lims(int T[], int inicial, int final);



/**
   Implementaci?n de las funciones
**/

inline static void insercion(int T[], int num_elem)
{
    insercion_lims(T, 0, num_elem);
}


static void insercion_lims(int T[], int inicial, int final) {

    int i, j;
    int aux;

    for (i = inicial + 1; i < final; i++) {

        j = i;
        while ((T[j] < T[j - 1]) && (j > 0)) {
            aux = T[j];
            T[j] = T[j - 1];
            T[j - 1] = aux;
            j--;
        }

    }

}



int main() {

    clock_t tantes = clock();
    
    int n;
    cout << "Introduce numero de elementos del vector: ";
    cin >> n;

    int* T = new int[n];
    assert(T);

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        T[i] = rand();
    };

    insercion(T, n);

    clock_t tdespues = clock();
    cout << (double)(tdespues - tantes) / CLOCKS_PER_SEC << endl;
    cout << "El tiempo que tarda en ejecutar es: " << tdespues;
    delete[] T;

    return 0;
};

