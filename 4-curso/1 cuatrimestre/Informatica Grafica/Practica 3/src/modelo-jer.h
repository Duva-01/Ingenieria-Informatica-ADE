// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

#ifndef MODELO_JER_HPP
#define MODELO_JER_HPP

#include "grafo-escena.h"
#include "tup_mat.h"
#include "objeto3d.h"
#include "materiales-luces.h"

using namespace tup_mat ;

// *********************************************************************
// declaración adelantada de estructura para un nodo del grafo de escena

// clase para el nodo del grafo etiquetado como Ventana
class C : public NodoGrafoEscena
{ 
    public:
        Matriz4f * rotacion;
        C(const float velocidad) ; // constructor

        virtual unsigned leerNumParametros() const;
        virtual void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//------------------------------------------------

// Proyecto de IG: Helicoptero

class CuboProyectoUbicado : public NodoGrafoEscena
{ public:

   Matriz4f * rotacion;
   
   CuboProyectoUbicado(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z, float a, float b, float c) ; // constructor
   //unsigned leerNumParametros() const;
   //void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//----------------------------------

class HeliceHelicopteroArriba : public NodoGrafoEscena
{ 
    public:
        Matriz4f * rotacionHeliceArriba;
        HeliceHelicopteroArriba() ; // constructor

        virtual unsigned leerNumParametros() const;
        virtual void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//--------------------------------

class HeliceHelicopteroLateral : public NodoGrafoEscena
{ 
    public:
        Matriz4f * rotacionHeliceLateral;
        HeliceHelicopteroLateral() ; // constructor

        virtual unsigned leerNumParametros() const;
        virtual void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//----------------------------------

class TroncoHelicoptero : public NodoGrafoEscena
{ 
    public:

        TroncoHelicoptero() ; // constructor

} ;

//---------------------------

class ColaHelicoptero : public NodoGrafoEscena
{ 
    public:

        ColaHelicoptero() ; // constructor
} ;

//----------------------------

class ParteAbajoHelicoptero : public NodoGrafoEscena
{ 
    public:
    
        ParteAbajoHelicoptero() ; // constructor

} ;

//----------------------------

class Escenario : public NodoGrafoEscena
{ 
    public:
        
        Escenario() ; // constructor
} ;

class FuegoProyecto : public NodoGrafoEscena
{ 
    public:
        
        Matriz4f * traslacionFuego;

        FuegoProyecto() ; // constructor
        virtual unsigned leerNumParametros() const;
        virtual void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;
//--------------------------

class Helicoptero : public NodoGrafoEscena
{ 
    public:

        Matriz4f * rotacion;
        Matriz4f * traslacion;

        FuegoProyecto * fuego;
        HeliceHelicopteroArriba * helice_arriba;
        HeliceHelicopteroLateral * helice_lateral;
        Helicoptero() ; // constructor

        virtual unsigned leerNumParametros() const;
        virtual void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

#endif