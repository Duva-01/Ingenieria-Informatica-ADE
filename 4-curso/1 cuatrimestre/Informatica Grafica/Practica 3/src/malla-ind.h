// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones de la clase Objeto3D.hpp
// **
// *********************************************************************

#ifndef IG_MALLAIND_HPP
#define IG_MALLAIND_HPP

#include <vector>       // usar std::vector
#include "objeto3d.h"   // declaración de 'Objeto3D'

// ---------------------------------------------------------------------
// clase para objetos gráficos genéricos

class MallaInd : public Objeto3D
{
   
   protected:
      // COMPLETAR: incluir aquí las variables y métodos privados que sean
      // necesarios para una malla indexada
      // ......

      std::vector<Tupla3f> vertices ;
      std::vector<Tupla3u> triangulos ;

      std::vector<Tupla3f> col_ver ;  // colores de los vértices
      std::vector<Tupla3f> nor_ver ;  // normales de vértices
      std::vector<Tupla3f> nor_tri ;  // normales de triangulos
      std::vector<Tupla2f> cc_tt_ver ; // coordenadas de textura de los vértices

      // nombres de VAO y VBOs
      GLenum nombre_vao     = 0 , // nombre del VAO con la secuencia de vértices
             nombre_vbo_pos = 0 , // VBO de posiciones (>0) una vez creado el VAO
             nombre_vbo_tri = 0 , // nombre del VBO de triángulos, >0
             nombre_vbo_col = 0 , // nombre del VBO de colores, si hay colores, si no 0 
             nombre_vbo_nor = 0 , // nombre del VBO de normales, si hay normales, si no 0 
             nombre_vbo_cct = 0 ; // nombre del VBO de coords de text., si hay, si no 0
             
      GLenum nombre_vao_geo = 0;


      // normales de triángulos y vértices
      void calcularNormales();

      // calculo de las normales de triángulos (solo si no están creadas ya)
      void calcularNormalesTriangulos() ;



   public:
      // crea una malla vacía (nombre: "malla indexada nueva vacía")
      MallaInd() ;

      // crea una malla vacía con un nombre concreto:
      MallaInd( const std::string & nombreIni );

      // visualizar el objeto con OpenGL
      virtual void visualizarGL( ContextoVis & cv ) ;

      // visualizar pura y simplemente la geometría, sin colores, normales, coord. text. etc...
      // (se supone que el estado de OpenGL está fijado antes de esta llamada de alguna forma adecuada)
      virtual void visualizarGeomGL( ContextoVis & cv ) ;
      



} ;
// ---------------------------------------------------------------------
// Clase para mallas obtenidas de un archivo 'ply'
// es un tipo de malla indexada que define un nuevo constructor
// que recibe el nombre del archivo ply como parámetro

class MallaPLY : public MallaInd
{
   public:
      MallaPLY( const std::string & nombre_arch ) ;
} ;


// ---------------------------------------------------------------------

class Cubo : public MallaInd
{
   public:
      Cubo(float a, float b, float c);
};

class CuboColores : public MallaInd
{
   public:
      CuboColores();
};

//--------------------------------

class Tetraedro : public MallaInd
{
   public:
      Tetraedro();
};

// ---------------------------------------------------------------------

class CuboTejado : public MallaInd
{
   public:
      CuboTejado();
};

// --------------------------------------------------------------------

class Cubo24 : public MallaInd
{
  public:
      Cubo24();
} ;

// ---------------- Ejercicio Adicional 1 ------------------------------

class EstrellaZ : public MallaInd
{
  public:
      EstrellaZ(unsigned n);
} ;

// ---------------- Ejercicio Adicional 2 ------------------------------

class CuboX : public MallaInd
{
  public:
      CuboX();
} ;

// ---------------- Ejercicio Adicional 3 ------------------------------

class MallaTriangulo : public MallaInd
{
  public:
      MallaTriangulo();
} ;

//-----------------

class MallaCuadrado : public MallaInd
{
  public:
      MallaCuadrado();
} ;

//---------------

class MallaPiramideL : public MallaInd
{
  public:
      MallaPiramideL();
};

// ------------------ Practica 2 - Adicionales ------------------//

class PiramideEstrellaZ : public MallaInd
{
  public:
      PiramideEstrellaZ(unsigned n);
} ;

class RejillaY : public MallaInd
{
  public:
      RejillaY(unsigned n, unsigned m);
} ;

class MallaTorre : public MallaInd
{
  public:
      MallaTorre(unsigned n);
} ;

#endif
