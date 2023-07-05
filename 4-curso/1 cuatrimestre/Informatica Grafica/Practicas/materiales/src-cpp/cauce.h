// *********************************************************************
// **
// ** Gestión del cauce gráfico (clase 'Cauce') (declaración)
// **
// ** Copyright (C) 2017-2022 Carlos Ureña
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


#ifndef CAUCE_HPP
#define CAUCE_HPP

#include <vector>
#include "ig-aux.h"

using namespace tup_mat ;

// mapeo de atributos usados con índices de atributos enteros
// índices de los atributos en los shaders de este cauce

constexpr GLuint 
   ind_atrib_posiciones   = 0 , 
   ind_atrib_colores      = 1 , 
   ind_atrib_normales     = 2 , 
   ind_atrib_coord_text   = 3 ,
   numero_atributos_cauce = 4 ;

// -------------------------------------------------------------------------------------
// Clase para el cauce de funcionalidad programable (OpenGL 3.3 o superior)

class Cauce 
{
   public:

   Cauce() ;

   // devuelve el color actual
   Tupla4f leerColorActual() const ;

   void activar();
   void fijarColor           ( const float r, const float g, const float b );
   void fijarMatrizVista     ( const Matriz4f & nue_mat_vista      );
   void fijarMatrizProyeccion( const Matriz4f & nue_mat_proyeccion );

   void fijarEvalMIL         ( const bool nue_eval_mil );
   void fijarUsarNormalesTri ( const bool nue_usar_normales_tri );
   void fijarParamsMIL       ( const float k_amb, const float k_dif,
                               const float  k_pse, const float exp_pse )  ;
   void fijarEvalText        ( const bool nue_eval_text, const int nue_text_id = -1 )  ;
   void fijarTipoGCT         ( const int nue_tipo_gct,
                                       const float * coefs_s =nullptr, const float * coefs_t =nullptr)  ;

   void pushMM() ;  // inserta copia de la matriz de modelado actual (en el tope de la pila)
   void popMM()  ;   // extrae tope de la pila y sustituye la matriz de modelado actual
   void compMM( const Matriz4f & mat_componer )  ;  // compone matriz de modelado actual con la matriz dada.
   void fijarFuentesLuz( const std::vector<Tupla3f> & color,
                                 const std::vector<Tupla4f> & pos_dir_wc  ) ;

   // lee el nombre o descripción del cauce
   std::string descripcion()  ;

    // métodos de apoyo para compilar/enlazar un shader:
   static char * leerArchivo( const std::string & nombreArchivo ) ;
   static GLuint compilarShader( const std::string & nombreArchivo, GLenum tipoShader );

   // versiones alternativas de 'fijarColor', que aceptan tuplas (el 4o componente se ignora)
   inline void fijarColor( const Tupla3f & c ) { fijarColor( c(0), c(1), c(2) ); }
   inline void fijarColor( const Tupla4f & c ) { fijarColor( c(0), c(1), c(2) ); }


   // devuelve el máximo número de fuentes de luz permitidas:
   // (según el estándar OpenGL, ese número debe ser como minimo 8) (aunque en OpenGL 4.1 quizás no tiene sentido!)
   unsigned maxNumFuentesLuz() { return 8 ; } ;

   private:

   GLuint
      id_frag_shader   = 0,       // identificador del fragment shader
      id_vert_shader   = 0;       // identificador del vertex shader
   GLint
      id_prog               = 0 ,  // identificador del 'shader program'
      loc_mat_modelado      = -1,  // 'localizaciones' de los parámetros uniform
      loc_mat_modelado_nor  = -1,
      loc_mat_vista         = -1,
      loc_mat_proyeccion    = -1,
      loc_tipo_gct          = -1,
      loc_eval_mil          = -1,
      loc_usar_normales_tri = -1,
      loc_eval_text         = -1,
      loc_coefs_s           = -1,
      loc_coefs_t           = -1,
      loc_mil_ka            = -1,
      loc_mil_kd            = -1,
      loc_mil_ks            = -1,
      loc_mil_exp           = -1,
      loc_num_luces         = -1,
      loc_color_luz         = -1,
      loc_pos_dir_luz_ec    = -1 ;

   bool
      eval_mil          = false, // true -> evaluar MIL, false -> usar color plano
      usar_normales_tri = false, // true -> usar normal del triángulo, false -> usar interp. de normales de vértices
      eval_text         = false; // true -> eval textura, false -> usar glColor o glColorPointer
   int
      tipo_gct         = 0 ;     // tipo de generación de coordenadas de textura

   Tupla3f 
      color            = { 0.0, 0.0, 0.0}; // color actual para visualización sin tabla de colores
      
   Matriz4f
      mat_modelado     = MAT_Ident(),  // matriz de modelado
      mat_modelado_nor = MAT_Ident(),  // matriz de modelado para normales
      mat_vista        = MAT_Ident(),  // matriz de vista
      mat_proyeccion   = MAT_Ident();  // matriz de proyección

   float
      coefs_s[4]       = {1.0,0.0,0.0,0.0},
      coefs_t[4]       = {0.0,1.0,0.0,0.0};

   std::vector<Matriz4f>   // pilas de la matriz de modelado y de la matriz de modelado de normales.
      pila_mat_modelado,
      pila_mat_modelado_nor ;

   std::string
      frag_fn,      // nombre del archivo con el fragment shader
      vert_fn ;     // nombre del archivo con el vertex shader

   // fijar (con glUniform) las matrices de modelado y de normales en el shader prog.
   void actualizarMatricesMN();
} ;







#endif
