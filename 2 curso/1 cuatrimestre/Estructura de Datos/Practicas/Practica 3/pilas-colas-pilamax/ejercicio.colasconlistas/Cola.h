#include <list>
#include <cassert>
#include <fstream>

/**
* ------------------------------------------------------------------------
*
* Se trata de implementar la clase cola a partir de la clase lista. Se dispone
* de la clase lista con toda la implementación ya hecha y se tiene que implementar
* la clase cola a partir de esa implementación sin tener que implementar nuevo
* código. Es decir, la implementación se hará simplemente llamando a funciones ya
* implementadas de las listas.
*
* Se utiliza la clase list de la biblioteca STL.
*
*/

using namespace std;

/**
* @brief T.D.A Cola
*
* Una cola es un tipo de dato que contiene una secuencia de valores y está diseñado
* para realizar inserciones en uno de los extremos (posterior), mientras los
* borrados y los accesos se realizan en el otro (frente o anterior).
*
* Las colas son por ello estructuras FIFO (First In, First Out).
*
* Este tipo de dato abstracto se puede hacer con distintas implementaciones. En
* este caso se usa una lista para almacenar los datos de la cola.
*
*/
template <class T>
class Cola{
private:
  /**
  * @brief lista que contiene los datos almacenados en la cola.
  */
  list<T> cola;
public:
  /**
  * @brief constructor por defecto.
  */
  Cola();
  /**
  * @brief constructor de copia.
  * @paran p cola que queremos copiar.
  */
  Cola(const Cola<T> & p);
  /**
  * @brief destructor.
  */
  ~Cola();
  /**
  * @brief sobrecarga del operador de asignación.
  * @param p cola que queremos asignar.
  */
  Cola & operator=(const Cola<T> & p);
  /**
  * @brief comprueba si la cola está vacía.
  */
  bool vacia() const;
  /**
  * @brief añade un elemento al final de la cola.
  * @param c elemento a añadir.
  */
  void poner(T c);
  /**
  * @brief elimina el elemento del frente.
  * @pre la cola no puede estar vacía.
  */
  void quitar();
  /**
  * @brief devuelve el elemento del frente.
  * @pre la cola no puede estar vacía.
  */
  T frente() const;
  /**
  * @brief Sobrecarga del operador de salida para comprobar los resultados
  * en el main. Se hace sólo con int para evitar fallos de compilación, ya
  * que solo se usa para comprobar que el resto de métodos funciona correctamente.
  *
  */
  
};


template <class T>
Cola<T>::Cola(){}

template <class T>
Cola<T> & Cola<T>::operator=(const Cola<T> & p){
	cola = p.cola;
	return *this;
}


template <class T>
Cola<T>::Cola(const Cola<T> & p){
	cola(p.cola);
}

template <class T>
Cola<T>::~Cola(){
	cola.clear();
}

template <class T>
bool Cola<T>::vacia() const{
		return cola.empty();
}

template <class T>
T Cola<T>::frente() const{
	assert(!cola.empty());
	return cola.front();
}

template <class T>
void Cola<T>::poner(T valor){
	cola.push_back(valor);
}

template <class T>
void Cola<T>::quitar(){
	assert(!cola.empty());
	cola.erase(cola.begin());
}





