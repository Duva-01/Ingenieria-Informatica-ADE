// *********************************************************************
// **
// ** Informática Gráfica, curso 22-23
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************


#ifndef PRACTICAS_H
#define PRACTICAS_H

class Escena ;
class ColFuentesLuz ;
class ContextoVis ;
class CamaraInteractiva ;
class Material ;
class Objeto3D ;

#include <string>
#include <tup_mat.h>
#include "materiales-luces.h"
#include "cauce.h"
#include "camara.h"
#include "escena.h"

extern int mouse_pos_factor ; // dirty hack, should be in contexto vis.

// ---------------------------------------------------------------------
// tipo de datos enumerado para los modos de visualización:

enum class ModosVisu
{
   relleno,
   lineas,
   puntos,
   num_modos
} ;
const std::string nombreModoVisu[ int(ModosVisu::num_modos)+1 ] =
{
   "relleno",
   "líneas",
   "puntos",
   "*** NUM. MODOS. VIS. ***"
} ;


// --------------------------------------------------------------------
// Clase para el contexto de visualización
// (parámetros de la visualización, puntero al cauce, diversas variables de estado)

class ContextoVis
{
   public:

   // modo de visualización actual
   ModosVisu modo_visu = ModosVisu::relleno ;

   // Tipo de normales para Phong shading:
   // true  --> usar normales de triángulos 
   // false -->  usar normales de vértices interpoladas (tradicional)
   bool usar_normales_tri = false ;

   // true -> dibujando en modo selección con FBO invisible (puede ser el back-buffer)
   bool modo_seleccion = false ;

   // true -> usar iluminación, false --> usar colores fijados con 'glColor' 'glColorPointer'
   bool iluminacion = true ;

   // dibujar aristas sí/no
   bool dibujar_aristas = false ;

   // visualizar normales si/no (útil para depurar objetos)
   bool visualizar_normales = false ;

   // true sii se está en proceso de visualizar normales durante una llamada a 'Escena::visualizarNormales'
   bool visualizando_normales = false ;

   // 'true'-> dibujar ejes, 'false' -> no dibujar ejes
   bool dibujar_ejes = true ;

   // 'true' -> visualizar FBO de seleccion, 'false' -> no visualizarlo
   bool visualizar_fbo = false ;

   // material actualmente activado (cuando 'iluminacion==true')
   Material * material_act = nullptr ;

   // puntero al cauce activo actual
   Cauce * cauce = nullptr; // puntero al cauce activo

   // numero de columnas (tam_x) y filas (tam_y) del viewport actual
   int ventana_tam_x = -1,
       ventana_tam_y = -1 ;
   
   // suavizar aristas (y puntos) si/no (no funciona en todos los drivers)
   bool suavizar_aristas = false ;
   



};

#endif // PRACTICAS_H
