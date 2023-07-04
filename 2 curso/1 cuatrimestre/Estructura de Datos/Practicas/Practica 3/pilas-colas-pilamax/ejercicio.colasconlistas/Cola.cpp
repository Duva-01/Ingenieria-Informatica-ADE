
using namespace std:



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
