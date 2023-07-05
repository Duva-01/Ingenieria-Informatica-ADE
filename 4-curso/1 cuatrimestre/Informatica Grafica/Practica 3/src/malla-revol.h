// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones de la clase MallaRevol
// **
// *********************************************************************

#ifndef IG_MALLAREVOL_HPP
#define IG_MALLAREVOL_HPP

#include <vector>          // usar std::vector
#include <string>

#include "malla-ind.h"   // declaración de 'Objeto3D'
// ---------------------------------------------------------------------
// clase para mallas indexadas obtenidas a partir de la revolución de un perfil

class MallaRevol : public MallaInd
{
   private:



   protected: //

   MallaRevol() {} // solo usable desde clases derivadas con constructores especificos

   // Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
   // a partir de un perfil y el número de copias que queremos de dicho perfil.
   void inicializar
   (
      const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
      const unsigned               num_copias  // número de copias del perfil
   ) ;
} ;
// --------------------------------------------------------------------- lauvivaldi@hotmail.com


class MallaRevolPLY : public MallaRevol
{
   public:
   MallaRevolPLY( const std::string & nombre_arch,
                  const unsigned nperfiles ) ;
} ;

class Cilindro : public MallaRevol
{
public:
   // Constructor: crea el perfil original y llama a inicializar
   // la base tiene el centro en el origen, el radio y la altura son 1
   Cilindro(
       const int num_verts_per,   // número de vértices del perfil original (m)
       const unsigned nperfiles, // número de perfiles (n)
       Tupla3f colores 
   );
};

class Cono : public MallaRevol
{
public:
   // Constructor: crea el perfil original y llama a inicializar
   // la base tiene el centro en el origen, el radio y altura son 1
   Cono(
       const int num_verts_per,   // número de vértices del perfil original (m)
       const unsigned nperfiles // número de perfiles (n)
   );
};


class Esfera : public MallaRevol
{
public:
   // Constructor: crea el perfil original y llama a inicializar
   // La esfera tiene el centro en el origen, el radio es la unidad
   Esfera(const int num_verts_per,   // número de vértices del perfil original (M)
          const unsigned nperfiles // número de perfiles (N)
   );
};

class SemiEsfera : public MallaRevol
{
public:
   // Constructor: crea el perfil original y llama a inicializar
   // la base tiene el centro en el origen, el radio y la altura son 1
   SemiEsfera(
       const int num_verts_per,   // número de vértices del perfil original (m)
       const unsigned nperfiles, // número de perfiles (n)
       Tupla3f colores  
   );
};
//-----------------

class Aro : public MallaRevol
{
public:
   // Constructor: crea el perfil original y llama a inicializar
   // La esfera tiene el centro en el origen, el radio es la unidad
   Aro(const int num_verts_per,   // número de vértices del perfil original (M)
          const unsigned nperfiles, // número de perfiles (N)
         float radio_int, float radio_aro, float a, float b, float c
   );
};
#endif
