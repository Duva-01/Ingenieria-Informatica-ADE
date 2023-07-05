// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

// *********************************************************************
// **
// ** Gestión de una grafo de escena (declaraciones)
// ** Copyright (C) 2014-2017 Carlos Ureña
// **
// ** This program is free software: you can redistribute it and/or modify
// ** it under the terms of the GNU General Public License as published by
// ** the Free Software Foundation, either version 3 of the License, or
// ** (at your option) any later version.
// **
// ** This program is distributed in the hope that it will be useful,
// ** but WITHOUT ANY WARRANTY; without even the implied warranty of
// ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// ** GNU General Public License for more details.
// **
// ** You should have received a copy of the GNU General Public License
// ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
// **
// *********************************************************************

#ifndef GRAFO_ESCENA_HPP
#define GRAFO_ESCENA_HPP

#include "tup_mat.h"
#include "objeto3d.h"
#include "materiales-luces.h"

using namespace tup_mat ;

// *********************************************************************
// declaración adelantada de estructura para un nodo del grafo de escena

class NodoGrafoEscena ;

// *********************************************************************
// tipo enumerado con los tipos de entradas del nodo del grafo de escena

enum class TipoEntNGE { objeto, transformacion, material, noInicializado } ;

// *********************************************************************
// Entrada del nodo del Grafo de Escena

struct EntradaNGE
{
   TipoEntNGE tipo ;   // objeto, transformacion, material
   union
   {  Objeto3D * objeto ;  // ptr. a un objeto (no propietario)
      Matriz4f * matriz ;  // ptr. a matriz 4x4 transf. (propietario)
      Material * material ; // ptr. a material (no propietario)
   } ;
   // constructores (uno por tipo)
   EntradaNGE( Objeto3D * pObjeto ) ;      // (copia solo puntero)
   EntradaNGE( const Matriz4f & pMatriz ); // (crea copia en el heap)
   EntradaNGE( Material * pMaterial ) ;    // (copia solo puntero)
   ~EntradaNGE() ;
} ;

// *********************************************************************
// Nodo del grafo de escena: es un objeto 3D parametrizado, que contiene una lista de entradas

class NodoGrafoEscena : public Objeto3D
{
   protected:
   // COMPLETAR: práctica 3: definir variables y métodos privados del nodo
   // .......
   std::vector<EntradaNGE> entradas ;
   public:

   NodoGrafoEscena() ;

   // visualiza usando OpenGL
   virtual void visualizarGL( ContextoVis & cv ) ;

   // visualizar pura y simplemente la geometría, sin colores, normales, coord. text. etc...
   // (se supone que el estado de OpenGL está fijado antes de esta llamada de alguna forma adecuada)
   virtual void visualizarGeomGL( ContextoVis & cv ) ;

   // añadir una entrada al final, hace copia de la entrada
   // devuelve indice de la entrada dentro del vector de entradas
   unsigned agregar( const EntradaNGE & entrada );

   // construir una entrada y añadirla (al final)
   unsigned agregar( Objeto3D * pObjeto ); // objeto (copia solo puntero)
   unsigned agregar( const Matriz4f & pMatriz ); // matriz (copia objeto)
   unsigned agregar( Material * pMaterial ); // material (copia solo puntero)

   // devuelve el puntero a la matriz en la i-ésima entrada
   Matriz4f * leerPtrMatriz( unsigned iEnt );

   // método para buscar un objeto con un identificador
   virtual bool buscarObjeto( const int ident_busc, const Matriz4f & mmodelado,
                    Objeto3D ** objeto, Tupla3f & centro_wc )  ;

   // si 'centro_calculado' es 'false', recalcula el centro usando los centros
   // de los hijos (el punto medio de la caja englobante de los centros de hijos)
   virtual void calcularCentroOC() ;

} ;

// Ejercicios adicionales 

// Objeto plantilla para hacer modificaciones

class ObjetoModificable : public NodoGrafoEscena
{ public:
   ObjetoModificable(Tupla3f traslacion, float angulo_rotacion, Tupla3f rotacion, Tupla3f escalado, Objeto3D & ObjetoModificable) ; // constructor
} ;


// Ejercicio 1

class ConoUbicado : public NodoGrafoEscena
{ public:
   ConoUbicado(unsigned n, float X, float Y, float Z, float angulo_rotacion, float escalado_X, float escalado_Y, float escalado_Z) ; // constructor
} ;

class ConosEstrella : public NodoGrafoEscena
{ public:
   ConosEstrella(unsigned n) ; // constructor
} ;

//--------------------------------

class CuboUbicado : public NodoGrafoEscena
{ public:
   int eje;
   Matriz4f * rotacion;
   
   CuboUbicado(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z) ; // constructor
   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

class GrafoEstrellaX : public NodoGrafoEscena
{ public:

   Matriz4f * rotacion;

   GrafoEstrellaX(unsigned n) ; // constructor
   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

// Ejercicio 2

class MiniCubosRejilla : public NodoGrafoEscena
{ public:
   CuboUbicado * c1, * c2, * c3, * c4, * c5, * c6;
   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
   MiniCubosRejilla() ; // constructor
} ;

class GrafoCubos : public NodoGrafoEscena
{ public:

   Matriz4f * rotacion;
   MiniCubosRejilla *cubillos;

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );

   GrafoCubos() ; // constructor
} ;

class CuboRejilla : public NodoGrafoEscena
{ public:
   CuboRejilla() ; // constructor
} ;


class RejillaUbicada : public NodoGrafoEscena
{ public:
   RejillaUbicada(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z) ; // constructor
} ;


// Ejercicios para practicar

class Varilla : public NodoGrafoEscena
{ public:
   Varilla(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z) ; // constructor
   Matriz4f * rotacion;
   
   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//-----------

class Soporte : public NodoGrafoEscena
{ public:

   Varilla * v1, * v2, * v3, * v4 , * v5;
   Soporte(int n) ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//----------

class Sombrilla : public NodoGrafoEscena
{ public:

   Soporte *soporte;
   Matriz4f * rotacion;
   Sombrilla() ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;


//---------------------

class AroUbicado : public NodoGrafoEscena
{ public:

   int eje;
   Matriz4f * rotacion;
   AroUbicado(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z, float radio_int, float radio_aro, float a, float b, float c) ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

class MultiplesAros : public NodoGrafoEscena
{ public:

   AroUbicado *a1, *a2, *a3;

   Matriz4f * rotacion;
   MultiplesAros() ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//-------------------

// Examen Excavadora

class PrimerGanchoExcavadora : public NodoGrafoEscena
{ public:

   
   Matriz4f * rotacionPrimerGancho;
   PrimerGanchoExcavadora(Tupla3f traslacion, float angulo_rotacion, Tupla3f rotacion, Tupla3f escalado) ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//-----------------------

class SegundoGanchoExcavadora : public NodoGrafoEscena
{ public:

   Matriz4f * rotacionPrimerGancho;
   SegundoGanchoExcavadora(Tupla3f traslacion, float angulo_rotacion, Tupla3f rotacion, Tupla3f escalado) ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

//------------------------

class GanchoExcavadora : public NodoGrafoEscena
{ public:

   SegundoGanchoExcavadora * segundoGancho;
   PrimerGanchoExcavadora * primerGanchoExcavadora;
   Matriz4f * rotacionGanchoGrande;
   GanchoExcavadora() ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

class ParteArribaExcavadora : public NodoGrafoEscena
{ public:

   GanchoExcavadora * ganchoExcavadora;
   Matriz4f * rotacion;
   ParteArribaExcavadora() ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;

class Excavadora : public NodoGrafoEscena
{ public:

   ParteArribaExcavadora * parteArriba;
   Matriz4f * traslacion;
   Excavadora() ; // constructor

   unsigned leerNumParametros() const;
   void actualizarEstadoParametro( const unsigned iParam, const float tSec );
} ;






#endif // GRAFO_ESCENA_HPP

// *********************************************************************
