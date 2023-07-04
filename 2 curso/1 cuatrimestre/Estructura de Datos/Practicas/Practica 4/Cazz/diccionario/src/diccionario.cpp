#include <iostream>
#include <string>
#include <list>
#include "../include/diccionario.h"

using namespace std;

template <class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
    if (datos.size()>0){
        typename list<data<T,U> >::iterator it;
    
        for (it=datos.begin(); it!=datos.end() ;++it){
            if ((*it).clave==p) {
                it_out=it;
                return true;
             }else if ((*it).clave>p){
                it_out=it;
                return false;
            }	  
        
        }
    
        it_out=it;
        return false;
    }else{	
        it_out=datos.end();
        return false;
    }	    
}

template <class T, class U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(clave,it)){
        data<T,U> p;
        p.clave = clave;
        p.info_asoci=info;
    
        datos.insert(it,p);
    }
}

template <class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){ //Si no esta la creo, y añado
        cout << "La palabra no esta en el diccionario" << endl;

    }else{ //Si esta la clave añado significado
        (*it).info_asoci.insert((*it).info_asoci.end(),s);
    }
}

template <class T, class U>
list<U>  Diccionario<T,U>::getInfo_Asoc(const T & p) {
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){
        cout << "La palabra no esta en el diccionario" << endl;
        return list<U>();
    }
    else{
        return (*it).info_asoci;
    }
}

//Nuevos metodos implementados
template <class T, class U>
void Diccionario<T,U>::Elimina_Palabra(const T& clave){
    typename list<data<T,U> >::iterator it;

    if(!Esta_Clave(clave, it)){
        cout << "La palabra no esta en el diccionario" << endl;
    }else{
        datos.erase(it);
    }
}

template <class T, class U>
void Diccionario<T,U>::filtra_Diccionario(const char letra, const char letra1, const Diccionario<T,U>& D){
    Diccionario<string,string>::const_iterator it;
	
    for (it=D.begin(); it!=D.end(); ++it){
        if( (*it).clave[0] >= letra && (*it).clave[0] <= letra1){ //Compruebe que la primera letra de clave este entre las dos letras
            list<string>::const_iterator it_s;
            cout<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
                        
            for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
                cout<<(*it_s)<<endl;
            }
        cout <<"**************************************"<<endl;
        }   
    }
}

template <class T, class U>
void Diccionario<T,U>::invierte_Diccionario(){
    datos.reverse();
}
