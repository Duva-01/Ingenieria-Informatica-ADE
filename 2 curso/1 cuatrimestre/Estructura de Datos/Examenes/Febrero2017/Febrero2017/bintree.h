#ifndef __BINTREE_H__
#define __BINTREE_H__

/**
 TDA bintree.

 Representa un árbol binario con nodos etiquetados con datos del tipo T.

 T debe tener definidas las operaciones:

 - T & operator=(const T & e);
 - bool operator!=(const T & e);
 - bool operator==(const T & e);

 Son mutables.
 Residen en memoria dinámica.

 Un ejemplo de su uso:
 @include usobintree.cpp
 @author{Miguel Garcia Silvente}
 @author{Juan F. Huete Guadix}
 */

#include <queue>


template <typename T>
class bintree {
public:
    class node;
    typedef unsigned int size_type;

    //Métodos públicos clase bintree


    /**
     @brief Constructor primitivo por defecto.

     Crea un árbol nulo.
     */
    bintree();


    /**
     @brief Constructor primitivo.

     @param e Etiqueta para la raíz.

     Crea un árbol con un único nodo etiquetado con e.
     */
    bintree(const T& e);


    /**
     @brief Constructor de copia.

     @param a árbol que se copia.

     Crea un árbol duplicado exacto de a.
     */
    bintree(const bintree<T>& a);


    /**
     @brief Reemplaza el receptor por una copia de subárbol.

     @param a Arbol desde el que se copia.
     @param n nodo raíz del subárbol que se copia.

     El receptor se hace nulo y después se le asigna una copia
     del subárbol de a cuya raíz es n.
     */
    void assign_subtree(const bintree<T>& a, node n);


    /**
     @brief Destructor.

     Destruye el receptor liberando los recursos que ocupaba.
     */
    ~bintree();


    /**
     @brief Operador de asignación.

     @param a árbol que se asigna.

     Destruye el contenido previo del receptor y le asigna un
     duplicado de a.
     */
    bintree<T>& operator=(const bintree<T>& a);


    /**
     @brief Obtener el nodo raíz.

     @return nodo raíz del receptor.
     */
    node root() const;


    /**
     @brief Podar el subárbol a la izquierda de un nodo.

     @param n nodo del receptor. !n.null().
     @param dest subárbol a la izquierda de n. Es MODIFICADO.

     Desconecta el subárbol a la izquierda de n, que pasa a
     ser un árbol nulo. El subárbol anterior se devuelve sobre
     dest.
     */
    void prune_left(node n, bintree<T>& dest);


    /**
     @brief Podar el subárbol a la derecha de un nodo.

     @param n nodo del receptor. !n.null().
     @param dest subárbol a la derecha de n. Es MODIFICADO.

     Desconecta el subárbol a la derecha de n, que pasa a
     ser un árbol nulo. El subárbol anterior se devuelve sobre
     dest.
     */
    void prune_right(node n, bintree<T>& dest);


    /**
     @brief Insertar un nodo como hijo a la izquierda de un nodo.

     @param n nodo del receptor. !n.null().
     @param e etiqueta del nuevo nodo.

     Desconecta y destruye el subárbol a la izquierda de n, inserta
     un nuevo nodo con etiqueta e como hijo a la izquierda
     */
    void insert_left(const bintree<T>::node& n, const T& e);


    /**
     @brief Insertar un árbol como subárbol a la izquierda de un nodo.

     @param n nodo del receptor. n != nodo_nulo.
     @param rama subárbol que se inserta. Es MODIFICADO.

     Desconecta y destruye el subárbol a la izquierda de n, le
     asigna el valor de rama como nuevo subárbol a la izquierda
     y rama se hace árbol nulo.
     */
    void insert_left(node n, bintree<T>& rama);


    /**
     @brief Insertar un nodo como hijo a la derecha de un nodo.

     @param n nodo del receptor. !n.Nulo().
     @param e etiqueta del nuevo nodo.

     Desconecta y destruye el subárbol a la derecha de n, inserta
     un nuevo nodo con etiqueta e como hijo a la derecha
     */
    void insert_right(node n, const T& e);


    /**
     @brief Insertar un árbol como subárbol a la derecha de un nodo.

     @param n nodo del receptor. !n.Nulo().
     @param rama subárbol que se inserta. Es MODIFICADO.

     Desconecta y destruye el subárbol a la izquierda de n, le
     asigna el valor de rama como nuevo subárbol a la derecha
     y rama se hace árbol nulo.
     */
    void insert_right(node n, bintree<T>& rama);


    /**
     @brief Hace nulo un árbol.

     Destruye todos los nodos del árbol receptor y lo hace
     un árbol nulo.
     */
    void clear();


    /**
     @brief Obtiene el número de nodos.

     @return número de nodos del receptor.
     */
    size_type size() const;


    /**
     @brief Comprueba si un árbol está vacío (es nulo).

     @return true, si el receptor está vacío (es nulo).
     false, en otro caso.
     */
    bool empty() const;


    /**
     @brief Operador de comparación de igualdad.

     @param a árbol con que se compara el receptor.

     @return  true, si el receptor es igual, en estructura y
     etiquetas a a.
     false, en otro caso.
     */
    bool operator==(const bintree<T>& a) const;


    /**
     @brief Operador de comparación de desigualdad.

     @param a árbol con que se compara el receptor.

     @return  true, si el receptor no es igual, en estructura o
     etiquetas a a.
     false, en otro caso.
     */
    bool operator!=(const bintree<T>& a) const;


    /**
     @brief Reemplaza el subárbol a partir de pos por una copia de subárbol.

     @param pos nodo a partir del que se colagará la copia
     @param a Arbol desde el que se copia.
     @param n nodo raíz del subárbol que se copia.

     El receptor se modifica colocando a partir de pos una copia
     del subárbol de a cuya raíz es n.
     */
    void replace_subtree(node pos, const bintree<T>& a, node n);


    /////////////////////////////////////
    //  ITERADORES
    /////////////////////////////////////


    /**
     Clase iterator para recorrer el árbol en preorden
     */
    class preorder_iterator {
    private:
        node elnodo;
        preorder_iterator(node n);
        friend class bintree<T>;
    public:
        preorder_iterator();
        preorder_iterator(const preorder_iterator& i);
        bool operator!=(const preorder_iterator& i) const;
        bool operator==(const preorder_iterator& i) const;
        preorder_iterator& operator=(const preorder_iterator& i);
        T& operator*();
        preorder_iterator& operator++();
    };

    preorder_iterator begin_preorder();
    preorder_iterator end_preorder();

    class const_preorder_iterator {
    private:
        node elnodo;
        const_preorder_iterator(node n);
        friend class bintree<T>;
    public:
        const_preorder_iterator();
        const_preorder_iterator(const const_preorder_iterator& i);
        const_preorder_iterator(const preorder_iterator& i);
        bool operator!=(const const_preorder_iterator& i) const;
        bool operator==(const const_preorder_iterator& i) const;
        const_preorder_iterator& operator=(const const_preorder_iterator& i);
        const T& operator*() const;
        const_preorder_iterator& operator++();
    };

    const_preorder_iterator begin_preorder() const;
    const_preorder_iterator end_preorder() const;



    /**
     Clase iterator para recorrer el árbol en Inorden
     */

    class inorder_iterator {
    private:
        node elnodo;
        inorder_iterator(node n);
        friend class bintree<T>;
    public:
        inorder_iterator();
        inorder_iterator(const inorder_iterator& i);
        bool operator!=(const inorder_iterator& i) const;
        bool operator==(const inorder_iterator& i) const;
        inorder_iterator& operator=(const inorder_iterator& i);
        T& operator*();
        inorder_iterator& operator++();
    };

    inorder_iterator begin_inorder();
    inorder_iterator end_inorder();

    class const_inorder_iterator
    {
    private:
        node elnodo;
        const_inorder_iterator(node n);
        friend class bintree<T>;
    public:
        const_inorder_iterator();
        const_inorder_iterator(const const_inorder_iterator& i);
        bool operator!=(const const_inorder_iterator& i) const;
        bool operator==(const const_inorder_iterator& i) const;
        const_inorder_iterator& operator=(const const_inorder_iterator& i);
        const T& operator*() const;
        const_inorder_iterator& operator++();
    };

    const_inorder_iterator begin_inorder() const;
    const_inorder_iterator end_inorder() const;


    /**
     Clase iterator para recorrer el árbol en PostOrden
     */

    class postorder_iterator {
    public:
        postorder_iterator();
        postorder_iterator(const postorder_iterator& i);
        bool operator!=(const postorder_iterator& i) const;
        bool operator==(const postorder_iterator& i) const;
        postorder_iterator& operator=(const postorder_iterator& i);
        T& operator*();
        postorder_iterator& operator++();
    private:
        node elnodo;
        postorder_iterator(node n);
        friend class bintree<T>;
    };

    postorder_iterator begin_postorder();
    postorder_iterator end_postorder();

    class const_postorder_iterator {
    private:
        node elnodo;
        const_postorder_iterator(node n);
        friend class bintree<T>;
    public:
        const_postorder_iterator();
        bool operator!=(const const_postorder_iterator& i) const;
        bool operator==(const const_postorder_iterator& i) const;
        const T& operator*() const;
        const_postorder_iterator& operator=(const const_postorder_iterator& i);
        const_postorder_iterator& operator++();
    };

    const_postorder_iterator begin_postorder() const;
    const_postorder_iterator end_postorder() const;


    /**
     Clase iterator para recorrer el árbol por niveles
     */

    class level_iterator {
    private:
        std::queue<node> cola_Nodos;
        level_iterator(node n);
        friend class bintree<T>;
    public:
        level_iterator();
        level_iterator(const level_iterator& i);
        bool operator!=(const level_iterator& i) const;
        bool operator==(const level_iterator& i) const;
        level_iterator& operator=(const level_iterator& i);
        T& operator*();
        level_iterator& operator++();
    };

    level_iterator begin_level();
    level_iterator end_level();

    class const_level_iterator {
        std::queue<node> cola_Nodos;
        const_level_iterator(node n);
        friend class bintree<T>;
    public:
        const_level_iterator();
        bool operator!=(const const_level_iterator& i) const;
        bool operator==(const const_level_iterator& i) const;
        const_level_iterator& operator=(const const_level_iterator& i);
        const T& operator*() const;
        const_level_iterator& operator++();
    private:
    };

    const_level_iterator begin_level() const;
    const_level_iterator end_level() const;


    ////////////////////////////////////
    //  FIN ITERADORES
    ////////////////////////////////////



private:

    //////////////////////////////////////////
    //Funciones auxiliares de la clase bintree
    //////////////////////////////////////////

    /**
     @brief Destruir subárbol.

     @param n nodo raíz del subárbol que se destruye.
     @doc:
     Destruye el subárbol cuya raíz es n.
     */
    void destroy(bintree<T>::node n);


    /**
     @brief Copia subárbol.

     @param dest nodo sobre el que se copia. dest.null().
     Es MODIFICADO.
     @param orig raíz del subárbol que se copia.

     @doc
     Destruye el subárbol con raíz en dest. Sobre éste realiza
     un duplicado del subárbol con raíz en orig.
     */
    void copy(node& dest, const node& orig);


    /**
     @brief Cuenta el número de nodos.

     @param n raíz del subárbol a contar.

     @return devuelve el número de nodos del subárbol que
     tiene n como raíz.

     Cuenta el número de nodos en el subárbol cuya raíz es n.
     */
    int count(node n) const;


    /**
     @brief Comparación de igualdad.

     @param n1 raiz del primer subárbol.
     @param n2 raiz del segundo subárbol.

     @return true, si los dos subárboles son iguales, en
     estructura y etiquetas.
     false, en otro caso.
     */
    bool equals(node n1, node n2) const;

    //////////////////////////////////////////
    //Fin funciones auxiliares
    //////////////////////////////////////////




    /**
     TDA nodo.
     Modela los nodos del árbol binario.
     */

    class nodewrapper {
    public:
        //Constructores
        nodewrapper();
        nodewrapper(const T& e);
        //Representación
        T etiqueta;
        node pad;
        node izda;
        node dcha;
    };

public:

    class node {
    private:
        nodewrapper* elnodo;

    public:
        /**
         @brief Constructor primitivo
         */
        node();

        /**
         @brief Constructor primitivo
         @param e Etiqueta del nodo
         */
        node(const T& e);

        /**
         @brief Constructor de copia
         @param n Nodo que se copia
         */
        node(const node& n);

        /**
         @brief Determina si el nodo es nulo
         */
        bool null() const;

        /**
         @brief Devuelve el padre del nodo receptor
         @pre !null()
         */
        node parent() const;

        /**
         @brief Devuelve el hizo izquierdo del nodo receptor
         @pre !null()
         */
        node left() const;

        /**
         @brief Devuelve el hizo izquierdo del nodo receptor
         @pre !null()
         */
        node right() const;

        /**
         @brief Devuelve la etiqueta del nodo
         @pre Si se usa como consultor, !null()
         */
        T& operator*();

        /**
         @brief Devuelve la etiqueta del nodo
         @pre !null()
         */
        const T& operator*() const;

        /**
         @brief Elimina el nodo actual
         @pre !null()
         */
        void remove();

        /**
         @brief Operador de asignación
         @param n el nodo a asignar
         */
        node& operator=(const node& n);

        /**
         @brief Operador de comparación de igualdad
         @param n el nodo con el que se compara
         */
        bool operator==(const node& n) const;

        /**
         @brief Operador de comparación de desigualdad
         @param n el nodo con el que se compara
         */
        bool operator!=(const node& n) const;

    private:
        // Las siguientes funciones son privadas para uso exclusivo en bintree
        friend class bintree<T>;

        /**
         @brief Coloca el nodo padre de un nodo
         @param n El nodo que será padre del receptor. No nulo.
         */
        inline void parent(node n);

        /**
         @brief Coloca el nodo hijo izquierda de un nodo
         @param n El nodo que será hijo izquierdo del receptor. No nulo
         */
        inline void left(node n);

        /**
         @brief Coloca el nodo hijo derecho de un nodo
         @param n El nodo que será hijo derecho del receptor. No nulo
         */
        inline void right(node n);

    };

    // Fin clase node

    // Representación
    node laraiz;
    size_type num_nodos;

};

/*
 ************************************************************
 * Implementación
 ************************************************************
 */

 /*
  Función de Abstracción:
  ----------------------
  Dado el objeto del tipo rep r, r = {laraiz}, el objeto
  abstracto al que representa es:
  a) Arbol nulo, si r.laraiz.null().
  b) Arbol con un único nodo de etiqueta *(r.laraiz)
  si r.laraiz.left().null() y r.laraiz.dcha().null()

  c)                    *(r.laraiz)
                         /       \
                        /         \
      Arbol(r.laraiz.left())    Arbol(r.laraiz.right())


  Invariante de Representación:
  ----------------------------
  Si !r.laraiz.null(),
  -   r.laraiz.parent().null().

  Para cualquier nodo n del árbol:
  Si !n.left().null()
      n.left().parent() == n;
  Si !n.right().null()
      n.right().parent() == n;

  */


#include <cassert>
  //#include "bintree.h"


  /*____________________________________________________________ */
  /*____________________________________________________________ */
  //               FUNCIONES PRIVADAS
  /*____________________________________________________________ */
  /*____________________________________________________________ */

template <typename T>
void bintree<T>::destroy(bintree<T>::node n) {
    if (!n.null()) {
        destroy(n.left());
        destroy(n.right());
        n.remove();
    }
}

template <typename T>
void bintree<T>::copy(bintree<T>::node& dest,
    const bintree<T>::node& orig) {
    if (orig.null())
        dest = node();
    else {
        dest = node(*orig);
        typename bintree<T>::node aux(dest.left());
        copy(aux, orig.left());
        dest.left(aux);
        if (!dest.left().null())
            dest.left().parent(dest);
        aux = dest.right();
        copy(aux, orig.right());
        dest.right(aux);
        if (!dest.right().null())
            dest.right().parent(dest);
    }
}

template <typename T>
int bintree<T>::count(bintree<T>::node n) const {
    if (n.null())
        return 0;
    else
        return 1 + count(n.left()) + count(n.right());
}

template <typename T>
bool bintree<T>::equals(bintree<T>::node n1, bintree<T>::node n2) const {
    if (n1.null() && n2.null())
        return true;
    if (n1.null() || n2.null())
        return false;
    if (*n1 != *n2)
        return false;
    if (!equals(n1.left(), n2.left()))
        return false;
    if (!equals(n1.right(), n2.right()))
        return false;
    return true;
}


/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <typename T>
bintree<T>::bintree() {
    num_nodos = 0;
}

template <typename T>
bintree<T>::bintree(const T& e) : laraiz(e), num_nodos(1) {}

template <typename T>
bintree<T>::bintree(const bintree<T>& a) {
    copy(laraiz, a.laraiz);
    if (!laraiz.null())
        laraiz.parent(typename bintree<T>::node());
    num_nodos = a.num_nodos;
}

template <typename T>
void bintree<T>::assign_subtree(const bintree<T>& a,
    typename bintree<T>::node n) {
    if (&a != this) {
        destroy(laraiz);
        num_nodos = count(n);
        copy(laraiz, n);
        if (!laraiz.null())
            laraiz.parent(typename bintree<T>::node());
    }
    else {  // Reemplazar el receptor por un subárbol suyo.
        if (laraiz != n) {
            typename bintree<T>::node nod(laraiz);
            num_nodos = count(n);
            laraiz = n;
            if (!n.null()) {
                typename bintree<T>::node aux(n.parent());
                if (n.parent().left() == n)
                    aux.left(typename bintree<T>::node());
                else
                    aux.right(typename bintree<T>::node());
            }
            destroy(nod);
            laraiz.parent(typename bintree<T>::node());
        }
    }
}

template <typename T>
bintree<T>::~bintree() {
    destroy(laraiz);
}

template <typename T>
bintree<T>& bintree<T>::operator=(const bintree<T>& a) {
    if (&a != this) {
        destroy(laraiz);
        num_nodos = a.num_nodos;
        copy(laraiz, a.laraiz);
        if (!laraiz.null())
            laraiz.parent(typename bintree<T>::node());
    }
    return *this;
}


template <typename T>
typename bintree<T>::node bintree<T>::root() const {
    return laraiz;
}

template <typename T>
void bintree<T>::prune_left(typename bintree<T>::node n,
    bintree<T>& orig) {
    assert(!n.null());
    destroy(orig.laraiz);
    num_nodos = num_nodos - count(n.left());
    orig.laraiz = n.left();
    if (!orig.laraiz.null())
        orig.laraiz.parent(typename bintree<T>::node());
    n.left(typename bintree<T>::node());
}


template <typename T>
void bintree<T>::prune_right(typename bintree<T>::node n,
    bintree<T>& orig) {
    assert(!n.null());
    destroy(orig.laraiz);
    num_nodos = num_nodos - count(n.right());
    orig.laraiz = n.right();
    num_nodos = num_nodos - count(n.right());
    if (!orig.laraiz.null())
        orig.laraiz.parent(typename bintree<T>::node());
    n.right(typename bintree<T>::node());
}

template <typename T>
void bintree<T>::insert_left(const typename bintree<T>::node& n,
    const T& e) {
    bintree<T> aux(e);
    insert_left(n, aux);
}

template <typename T>
void bintree<T>::insert_left(typename bintree<T>::node n,
    bintree<T>& rama) {
    assert(!n.null());
    num_nodos = num_nodos - count(n.left()) + rama.num_nodos;
    typename bintree<T>::node aux(n.left());
    destroy(aux);
    n.left(rama.laraiz);
    if (!n.left().null())
        n.left().parent(n);
    rama.laraiz = typename bintree<T>::node();
}

template <typename T>
void bintree<T>::insert_right(typename bintree<T>::node n,
    const T& e) {
    bintree<T> aux(e);
    insert_right(n, aux);
}


template <typename T>
inline
void bintree<T>::insert_right(typename bintree<T>::node n,
    bintree<T>& rama) {
    assert(!n.null());
    num_nodos = num_nodos - count(n.right()) + rama.num_nodos;
    typename bintree<T>::node aux(n.right());
    destroy(aux);
    n.right(rama.laraiz);
    if (!n.right().null())
        n.right().parent(n);
    rama.laraiz = typename bintree<T>::node();
}


template <typename T>
void bintree<T>::clear() {
    destroy(laraiz);
    laraiz = bintree<T>::node();
}


template <typename T>
typename bintree<T>::size_type bintree<T>::size() const {
    return num_nodos;
}


template <typename T>
bool bintree<T>::empty() const {
    return laraiz == bintree<T>::node();
}


template <typename T>
bool bintree<T>::operator==(const bintree<T>& a) const {
    return equals(laraiz, a.laraiz);
}


template <typename T>
inline bool bintree<T>::operator!=(const bintree<T>& a) const {
    return !(*this == a);
}

/*
 ************************************************************
 Iteradores
 ************************************************************
 */


 /*
  Iterador para recorrido en Preorder
  */

template <typename T>
inline
bintree<T>::preorder_iterator::preorder_iterator()
{
    elnodo = typename bintree<T>::node();
}


template <typename T>
inline
bintree<T>::preorder_iterator::preorder_iterator(
    const bintree<T>::preorder_iterator& i)
    : elnodo(i.elnodo)
{
}


template <typename T>
inline
bintree<T>::preorder_iterator::preorder_iterator(bintree<T>::node n)
    : elnodo(n)
{
}

template <typename T>
inline
bool bintree<T>::preorder_iterator::operator!=(
    const bintree<T>::preorder_iterator& i) const
{
    return elnodo != i.elnodo;
}


template <typename T>
inline
bool bintree<T>::preorder_iterator::operator==(
    const bintree<T>::preorder_iterator& i) const
{
    return elnodo == i.elnodo;
}


template <typename T>
inline
typename bintree<T>::preorder_iterator&
bintree<T>::preorder_iterator::operator=(const bintree<T>::preorder_iterator& i)
{
    elnodo = i.elnodo;
    return *this;
}


template <typename T>
inline
T& bintree<T>::preorder_iterator::operator*()
{
    return *elnodo;
}


template <typename T>
typename bintree<T>::preorder_iterator&
bintree<T>::preorder_iterator::operator++()
{
    if (elnodo.null())
        return *this;

    if (!elnodo.left().null())
        elnodo = elnodo.left();
    else if (!elnodo.right().null())
        elnodo = elnodo.right();
    else {
        while ((!elnodo.parent().null()) &&
            (elnodo.parent().right() == elnodo ||
                elnodo.parent().right().null()))
            elnodo = elnodo.parent();
        if (elnodo.parent().null())
            elnodo = typename bintree<T>::node();
        else
            elnodo = elnodo.parent().right();
    }

    return *this;
}


template <typename T>
inline
typename bintree<T>::preorder_iterator
bintree<T>::begin_preorder()
{
    return preorder_iterator(laraiz);
}

template <typename T>
inline
typename bintree<T>::preorder_iterator
bintree<T>::end_preorder()
{
    return preorder_iterator(typename bintree<T>::node());
}

/*____________________________________________________________ */

/*
 Iterador para recorrido en Inorder
 */


template <typename T>
inline
bintree<T>::inorder_iterator::inorder_iterator()
{
}


template <typename T>
inline bintree<T>::inorder_iterator::inorder_iterator(
    bintree<T>::node n)
    : elnodo(n)
{
}

template <typename T>
inline bool bintree<T>::inorder_iterator::operator!=(
    const typename bintree<T>::inorder_iterator& i) const
{
    return elnodo != i.elnodo;
}


template <typename T>
inline bool bintree<T>::inorder_iterator::operator==(
    const typename bintree<T>::inorder_iterator& i) const
{
    return elnodo == i.elnodo;
}


template <typename T>
inline
typename bintree<T>::inorder_iterator&
bintree<T>::inorder_iterator::operator=(
    const bintree<T>::inorder_iterator& i)
{
    elnodo = i.elnodo;
    return *this;
}


template <typename T>
inline T& bintree<T>::inorder_iterator::operator*()
{
    return *elnodo;
}


template <typename T>
typename bintree<T>::inorder_iterator&
bintree<T>::inorder_iterator::operator++()
{
    if (elnodo.null())
        return *this;

    if (!elnodo.right().null()) {
        elnodo = elnodo.right();
        while (!elnodo.left().null())
            elnodo = elnodo.left();
    }
    else {
        while (!elnodo.parent().null() &&
            elnodo.parent().right() == elnodo)
            elnodo = elnodo.parent();
        // Si (padre de elnodo es nodo_nulo), hemos terminado
        // En caso contrario, el siguiente node es el padre
        elnodo = elnodo.parent();
    }
    return *this;
}

template <typename T>
typename bintree<T>::inorder_iterator
bintree<T>::begin_inorder()
{
    node n(laraiz);

    if (!n.null())
        while (!n.left().null())
            n = n.left();
    return inorder_iterator(n);
}


template <typename T>
inline
typename bintree<T>::inorder_iterator
bintree<T>::end_inorder()
{
    return inorder_iterator(typename bintree<T>::node());
}

/*____________________________________________________________ */

/*
 Iterador para recorrido en Postorder
 */


template <typename T>
inline
bintree<T>::postorder_iterator::postorder_iterator()
{
}

template <typename T>
inline
bintree<T>::postorder_iterator::postorder_iterator(
    bintree<T>::node n)
    : elnodo(n)
{
}

template <typename T>
inline
bool bintree<T>::postorder_iterator::operator!=(
    const bintree<T>::postorder_iterator& i) const
{
    return elnodo != i.elnodo;
}

template <typename T>
inline
bool bintree<T>::postorder_iterator::operator==(
    const bintree<T>::postorder_iterator& i) const
{
    return elnodo == i.elnodo;
}


template <typename T>
inline
typename bintree<T>::postorder_iterator&
bintree<T>::postorder_iterator::operator=(
    const bintree<T>::postorder_iterator& i)
{
    elnodo = i.elnodo;
    return *this;
}


template <typename T>
inline
T& bintree<T>::postorder_iterator::operator*()
{
    return *elnodo;
}


template <typename T>
typename bintree<T>::postorder_iterator&
bintree<T>::postorder_iterator::operator++()
{
    if (elnodo.null())
        return *this;

    if (elnodo.parent().null())
        elnodo = typename bintree<T>::node();
    else
        if (elnodo.parent().left() == elnodo) {
            if (!elnodo.parent().right().null()) {
                elnodo = elnodo.parent().right();
                do {
                    while (!elnodo.left().null())
                        elnodo = elnodo.left();
                    if (!elnodo.right().null())
                        elnodo = elnodo.right();
                } while (!elnodo.left().null() ||
                    !elnodo.right().null());
            }
            else
                elnodo = elnodo.parent();
        }
        else // elnodo es hijo a la derecha de su padre
            elnodo = elnodo.parent();

    return *this;
}

template <typename T>
inline
typename bintree<T>::postorder_iterator bintree<T>::begin_postorder()
{
    node n(laraiz);

    do {
        while (!n.left().null())
            n = n.left();
        if (!n.right().null())
            n = n.right();
    } while (!n.left().null() || !n.right().null());

    return postorder_iterator(n);
}

template <typename T>
inline
typename bintree<T>::postorder_iterator
bintree<T>::end_postorder()
{
    return postorder_iterator(typename bintree<T>::node());
}

/*____________________________________________________________ */

/*
 Iterador para recorrido por Niveles
 */

template <typename T>
inline
bintree<T>::level_iterator::level_iterator()
{
}

template <typename T>
inline bintree<T>::level_iterator::level_iterator(
    bintree<T>::node n)
{
    cola_Nodos.push(n);

}
template <typename T>
inline bool bintree<T>::level_iterator::operator!=(
    const bintree<T>::level_iterator& i) const
{
    if (cola_Nodos.empty() && i.cola_Nodos.empty())
        return false;
    if (cola_Nodos.empty() || i.cola_Nodos.empty())
        return true;
    if (cola_Nodos.front() != i.cola_Nodos.front())
        return false;
    if (cola_Nodos.size() != i.cola_Nodos.size())
        return false;
    return (cola_Nodos == i.cola_Nodos);
}

template <typename T>
inline
bool bintree<T>::level_iterator::operator==(
    const bintree<T>::level_iterator& i) const
{
    return  !(*this != i);
}

template <typename T>
inline
typename bintree<T>::level_iterator&
bintree<T>::level_iterator::operator=(
    const bintree<T>::level_iterator& i)
{
    cola_Nodos = i.cola_Nodos;
    return *this;
}


template <typename T>
inline
T& bintree<T>::level_iterator::operator*()
{
    return *cola_Nodos.front();
}


template <typename T>
typename bintree<T>::level_iterator&
bintree<T>::level_iterator::operator++()
{
    if (!cola_Nodos.empty()) {
        typename bintree<T>::node n = cola_Nodos.front();
        cola_Nodos.pop();
        if (!n.left().null())
            cola_Nodos.push(n.left());
        if (!n.right().null())
            cola_Nodos.push(n.right());
    }

    return *this;
}


template <typename T>
inline typename bintree<T>::level_iterator
bintree<T>::begin_level()
{
    if (!root().null())
        return level_iterator(laraiz);
    else
        return level_iterator();
}

template <typename T>
inline typename bintree<T>::level_iterator
bintree<T>::end_level()
{
    return level_iterator();
}

/*
 ************************************************************
 Iteradores constantes
 ************************************************************
 */


 /*
  Iterador cosntante para recorrido en Preorder
  */

template <typename T>
inline
bintree<T>::const_preorder_iterator::const_preorder_iterator()
{
}


template <typename T>
inline
bintree<T>::const_preorder_iterator::const_preorder_iterator(
    bintree<T>::node n)
    : elnodo(n)
{
}

template <typename T>
bintree<T>::const_preorder_iterator::const_preorder_iterator(const typename bintree<T>::preorder_iterator& i) {
    elnodo = i.elnodo;
}

template <typename T>
inline
bool bintree<T>::const_preorder_iterator::operator!=(
    const bintree<T>::const_preorder_iterator& i) const
{
    return elnodo != i.elnodo;
}


template <typename T>
inline
bool bintree<T>::const_preorder_iterator::operator==(
    const bintree<T>::const_preorder_iterator& i) const
{
    return elnodo == i.elnodo;
}


template <typename T>
inline
typename bintree<T>::const_preorder_iterator&
bintree<T>::const_preorder_iterator::operator=(
    const bintree<T>::const_preorder_iterator& i)
{
    elnodo = i.elnodo;
    return *this;
}


template <typename T>
inline
const T& bintree<T>::const_preorder_iterator::operator*() const
{
    return *elnodo;
}


template <typename T>
typename bintree<T>::const_preorder_iterator&
bintree<T>::const_preorder_iterator::operator++()
{
    if (elnodo.null())
        return *this;

    if (!elnodo.left().null())
        elnodo = elnodo.left();
    else if (!elnodo.right().null())
        elnodo = elnodo.right();
    else {
        while ((!elnodo.parent().null()) &&
            (elnodo.parent().right() == elnodo
                || elnodo.parent().right().null()))
            elnodo = elnodo.parent();
        if (elnodo.parent().null())
            elnodo = typename bintree<T>::node();
        else
            elnodo = elnodo.parent().right();
    }

    return *this;
}


template <typename T>
inline
typename bintree<T>::const_preorder_iterator
bintree<T>::begin_preorder() const
{
    return const_preorder_iterator(laraiz);
}

template <typename T>
inline
typename bintree<T>::const_preorder_iterator
bintree<T>::end_preorder() const
{
    return const_preorder_iterator(typename bintree<T>::node());
}

/*____________________________________________________________ */

/*
 Iterador constante para recorrido en Inorder
 */


template <typename T>
inline
bintree<T>::const_inorder_iterator::const_inorder_iterator()
{
    elnodo = typename bintree<T>::node();
}

template <typename T>
inline
bintree<T>::const_inorder_iterator::const_inorder_iterator(const const_inorder_iterator& i)
{
    elnodo = i.elnodo;
}

template <typename T>
inline
bintree<T>::const_inorder_iterator::const_inorder_iterator(
    bintree<T>::node n)
    : elnodo(n)
{
}

template <typename T>
inline
bool bintree<T>::const_inorder_iterator::operator!=(
    const bintree<T>::const_inorder_iterator& i) const
{
    return elnodo != i.elnodo;
}


template <typename T>
inline
bool bintree<T>::const_inorder_iterator::operator==(
    const bintree<T>::const_inorder_iterator& i) const
{
    return elnodo == i.elnodo;
}

template <typename T>
inline
typename bintree<T>::const_inorder_iterator&
bintree<T>::const_inorder_iterator::operator=(
    const bintree<T>::const_inorder_iterator& i)
{
    elnodo = i.elnodo;
    return *this;
}


template <typename T>
inline
const T& bintree<T>::const_inorder_iterator::operator*() const
{
    return *elnodo;
}


template <typename T>
typename bintree<T>::const_inorder_iterator&
bintree<T>::const_inorder_iterator::operator++()
{
    if (elnodo.null())
        return *this;

    if (!elnodo.right().null()) {
        elnodo = elnodo.right();
        while (!elnodo.left().null())
            elnodo = elnodo.left();
    }
    else {
        while (!elnodo.parent().null() &&
            elnodo.parent().right() == elnodo)
            elnodo = elnodo.parent();
        // Si (el padre de elnodo es nodo_nulo), hemos terminado
        // En caso contrario, el siguiente Nodo es el padre
        elnodo = elnodo.parent();
    }
    return *this;
}

template <typename T>
inline
typename bintree<T>::const_inorder_iterator
bintree<T>::begin_inorder() const
{
    node n(laraiz);

    if (!n.null())
        while (!n.left().null())
            n = n.left();
    return const_inorder_iterator(n);
}


template <typename T>
inline
typename bintree<T>::const_inorder_iterator
bintree<T>::end_inorder() const
{
    return const_inorder_iterator(typename bintree<T>::node());
}

/*____________________________________________________________ */

/*
 Iterador constante para recorrido en Postorder
 */


template <typename T>
inline
bintree<T>::const_postorder_iterator::const_postorder_iterator()
{
    elnodo = typename bintree<T>::node();
}


template <typename T>
inline
bintree<T>::const_postorder_iterator::const_postorder_iterator(
    typename bintree<T>::node n)
    : elnodo(n)
{
}

template <typename T>
inline
bool bintree<T>::const_postorder_iterator::operator!=(
    const bintree<T>::const_postorder_iterator& i) const
{
    return elnodo != i.elnodo;
}


template <typename T>
inline
bool bintree<T>::const_postorder_iterator::operator==(
    const bintree<T>::const_postorder_iterator& i) const
{
    return elnodo == i.elnodo;
}


template <typename T>
inline
typename bintree<T>::const_postorder_iterator&
bintree<T>::const_postorder_iterator::operator=(
    const bintree<T>::const_postorder_iterator& i)
{
    elnodo = i.elnodo;
    return *this;
}


template <typename T>
inline
const T& bintree<T>::const_postorder_iterator::operator*() const
{
    return *elnodo;
}


template <typename T>
typename bintree<T>::const_postorder_iterator&
bintree<T>::const_postorder_iterator::operator++()
{
    if (elnodo.null())
        return *this;

    if (elnodo.parent().null())
        elnodo = typename bintree<T>::node();
    else
        if (elnodo.parent().left() == elnodo) {
            if (!elnodo.parent().right().null()) {
                elnodo = elnodo.parent().right();
                do {
                    while (!elnodo.left().null())
                        elnodo = elnodo.left();
                    if (!elnodo.right().null())
                        elnodo = elnodo.right();
                } while (!elnodo.left().null() ||
                    !elnodo.right().null());
            }
            else
                elnodo = elnodo.parent();
        }
        else // elnodo es hijo a la derecha de su padre
            elnodo = elnodo.parent();

    return *this;
}


template <typename T>
inline
typename bintree<T>::const_postorder_iterator
bintree<T>::begin_postorder() const
{
    node n = root();

    do {
        while (!n.left().null())
            n = n.left();
        if (!n.right().null())
            n = n.right();
    } while (!n.left().null() || !n.right().null());

    return const_postorder_iterator(n);
}

template <typename T>
inline
typename bintree<T>::const_postorder_iterator
bintree<T>::end_postorder() const
{
    return const_postorder_iterator(typename bintree<T>::node());
}

/*____________________________________________________________ */

/*
 Iterador cosntante para recorrido por Niveles
 */


template <typename T>
inline
bintree<T>::const_level_iterator::const_level_iterator()
{
}


template <typename T>
inline
bintree<T>::const_level_iterator::const_level_iterator(
    bintree<T>::node n)
{
    cola_Nodos.push(n);
}


template <typename T>
inline
bool bintree<T>::const_level_iterator::operator!=(
    const bintree<T>::const_level_iterator& i) const
{
    if (cola_Nodos.empty() && i.cola_Nodos.empty())
        return false;
    if (cola_Nodos.empty() || i.cola_Nodos.empty())
        return true;
    return cola_Nodos.front() != i.cola_Nodos.front();
}


template <typename T>
inline
bool bintree<T>::const_level_iterator::operator==(
    const bintree<T>::const_level_iterator& i) const
{
    return !(*this != i);
}


template <typename T>
inline
typename bintree<T>::const_level_iterator&
bintree<T>::const_level_iterator::operator=(
    const bintree<T>::const_level_iterator& i)
{
    cola_Nodos = i.cola_Nodos;
    return *this;
}


template <typename T>
inline const T& bintree<T>::const_level_iterator::operator*() const
{
    return *cola_Nodos.front();
}


template <typename T>
typename bintree<T>::const_level_iterator&
bintree<T>::const_level_iterator::operator++()
{
    if (!cola_Nodos.empty()) {
        typename bintree<T>::node n = cola_Nodos.front();
        cola_Nodos.pop();
        if (!n.left().null())
            cola_Nodos.push(n.left());
        if (!n.right().null())
            cola_Nodos.push(n.right());
    }

    return *this;
}


template <typename T>
inline
typename bintree<T>::const_level_iterator
bintree<T>::begin_level() const
{
    if (!root().null())
        return const_level_iterator(laraiz);
    else
        return const_level_iterator();
}

template <typename T>
inline
typename bintree<T>::const_level_iterator
bintree<T>::end_level() const
{
    return const_level_iterator();
}

template <typename T>
void bintree<T>::replace_subtree(typename bintree<T>::node pos, const bintree<T>& a, typename bintree<T>::node n)
{
    if (&a != this) {
        if (pos == laraiz) {  // pos es la raiz
            destroy(laraiz);
            copy(laraiz, n);
            if (!laraiz.null())
                laraiz.parent(typename bintree<T>::node());
        }
        else {  // Pos no esta en la raiz
            typename bintree<T>::node padre = pos.parent(), aux;
            if (padre.left() == pos) {
                destroy(padre.left());
                copy(aux, n);
                padre.left(aux);
            }
            else {
                destroy(padre.right());
                copy(aux, n);
                padre.right(aux);
            }
        }
    }
}



#include <cassert>

//
// Operaciones de nodewrapper
//
template <typename T>
bintree<T>::nodewrapper::nodewrapper()
//:pad(0),izda(0),dcha(0)
{
}


template <typename T>
bintree<T>::nodewrapper::nodewrapper(const T& e) :etiqueta(e)
//,pad(0),izda(0),dcha(0)
{
}


//
// Operaciones de node
//

template <typename T>
bintree<T>::node::node() {
    elnodo = 0;
};


template <typename T>
bintree<T>::node::node(const T& e) {
    elnodo = new nodewrapper(e);
}


template <typename T>
bintree<T>::node::node(const typename bintree<T>::node& n) : elnodo(n.elnodo) {
}


template <typename T>
typename bintree<T>::node&
bintree<T>::node::operator=(const typename bintree<T>::node& n) {
    if (this != &n)
        elnodo = n.elnodo;
    return *this;
}

template <typename T>
bool bintree<T>::node::null() const {
    return elnodo == 0;
}


template <typename T>
typename bintree<T>::node bintree<T>::node::parent() const {
    return (elnodo->pad);
}


template <typename T>
typename bintree<T>::node bintree<T>::node::left() const {
    return (elnodo->izda);
}


template <typename T>
typename bintree<T>::node bintree<T>::node::right() const {
    return (elnodo->dcha);
}


template <typename T>
T& bintree<T>::node::operator*() {
    return elnodo->etiqueta;
}


template <typename T>
const T& bintree<T>::node::operator*() const {
    return elnodo->etiqueta;
}


template <typename T>
void bintree<T>::node::remove() {
    delete elnodo;
    elnodo = 0;
}


template <typename T>
bool bintree<T>::node::operator==(const node& n) const {
    return elnodo == n.elnodo;
}


template <typename T>
bool bintree<T>::node::operator!=(const node& n) const {
    return elnodo != n.elnodo;
}


//Funciones privadas para uso exclusivo de bintree


template <typename T>
void bintree<T>::node::parent(typename bintree<T>::node n) {
    elnodo->pad = n;
}


template <typename T>
void bintree<T>::node::left(typename bintree<T>::node n) {
    elnodo->izda = n;
}


template <typename T>
void bintree<T>::node::right(typename bintree<T>::node n) {
    elnodo->dcha = n;
}






#endif



