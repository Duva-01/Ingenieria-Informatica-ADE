//-*-Mode: C++;-*-
#ifndef __COLA_H__
#define __COLA_H__

/**
   TDA Cola::Cola, vacia, cabecera, poner, quitar, ~Cola.

   Cada objeto del TDA Cola, modela una cola de elementos 
   de la clase T.
 
   Una cola es un tipo particular de lista en la que los elementos
   se insertan por un extremo (el final) y se consultan y suprimen
   por el otro (cabecera). Son listas del tipo FIFO (First In,
   First Out).

   Son objetos mutables.
   Residen en memoria din�mica.

   Versi�n: 0.0.1
 */

#include <list>

using namespace std;

template <class T>
class Cola {
public:
  Cola();
  /**
     Constructor primitivo.
     @doc
     Crea una cola vac�a.
   */


  Cola(const Cola<T> & c);
  /**
     Constructor de copia.

     @param c: Cola que se copia.

     @doc
     Crea una cola que es copia de c.
  */

     
  bool vacia() const;
  /**
     Informa si la cola est� vac�a.

     @return true, si la cola est� vac�a.
             false, en otro caso.
  */

     
  T& frente ();
  /**
     Acceso al elemento al principio de la cola.

     @return Referencia al elemento en la cabecera de la cola.
  */


  void poner(const T & elem);
  /**
     A�ade un elemento en la cola.

     @param elem: Elemento que se inserta.
    
     @doc
     Inserta un nuevo elemento al final de la cola.
  */


  void quitar();
  /**
     Quita un elemento de la cola.

     @precondition El receptor no puede estar vac�o.

     @doc
     Elimina el elemento en la cabecera de la cola.
  */


  int num_elementos() const;
  /**
     Obtiene el n�mero de elementos en la cola.

     @return n�mero de elementos incluidos en la cola.
  */


  ~Cola();
  /**
     Destructor.

     @postcondition El receptor es MODIFICADO.

     @doc
     El receptor es destruido liberando todos los recursos que usaba.
  */

private:
  list<T> cola;

};


/*
 ************************************************************
 * Implementaci�n
 ************************************************************
 */

/*

  Funci�n de Abstracci�n:
  ----------------------
  Dado el objeto del tipo rep r, el objeto abstracto al que
  representa es:
    c = l, con la cabecera de la cola en la posici�n l.primero() y 
    el final en la posici�n l.final().

  Invariante de Representaci�n:
  ----------------------------
  - true.
 */



template <class T>
inline Cola<T>::Cola()
{};


template <class T>
inline Cola<T>::Cola(const Cola<T> & c)
  : cola(c.cola)
{};


template <class T>
inline bool Cola<T>::vacia() const
{
  return cola.empty();
}

     
template <class T>
inline T& Cola<T>::frente()
{
  return cola.front();
}


template <class T>
inline void Cola<T>::poner(const T & elem)
{
  cola.push_back(elem);
}


template <class T>
inline void Cola<T>::quitar()
{
  cola.erase(cola.begin());
}


template <class T>
inline int Cola<T>::num_elementos() const
{
  return cola.size();
}


template <class T>
inline Cola<T>::~Cola()
{
}


#endif
