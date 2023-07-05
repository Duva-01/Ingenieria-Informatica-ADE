// *********************************************************************
// **
// ** Conjunto de funciones auxiliares (declaraciones)
// **
// ** Copyright (C) 2014-2022 Carlos Ureña
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

#ifndef AUX_HPP
#define AUX_HPP

// includes de la librería estandard y otras

#include <cctype>     // toupper
#include <algorithm>  // std::min y std::max
#include <cassert>    // assert
#include <cctype>     // toupper
#include <cstdlib>
#include <cmath>      // std::sin, std::cos, etc...
#include <fstream>    // std::ifstream
#include <iostream>   // std::cout
#include <iomanip>    // std::setprecision, std::fixed, etc....
#include <map>        // std::map<K,V>
#include <string>     // std::string
#include <vector>     // std::vector
#include <chrono>     // std::chrono::time_point, std::chrono::duration (para medir FPS)

// includes de OpenGL/Glut/Glew/Glu (dependen del S.O.)
// ver: https://stackoverflow.com/questions/5919996/how-to-detect-reliably-mac-os-x-ios-linux-windows-in-c-preprocessor

#ifdef __linux__
//#pragma message "Usando includes para LINUX"
#include <GL/glew.h>   // nota: define GLEW_OK
#include <GLFW/glfw3.h>  // glfw (incluye OpenGL?)
#include <GL/glu.h>
#define NOMBRE_OS "Linux"

#elif __APPLE__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" // ignora advertencias por uso de funciones obsoletas
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>  // glfw
#define NOMBRE_OS "macOS"

#elif _WIN32
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <jpeglib.h>
#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCTION__ // https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2019
#endif
#define NOMBRE_OS "Windows"

#else
#pragma error "No está definido el símbolo '__APPLE__' ni '__linux__', ni 'WINDOWS'."

#endif

//------------------------------------------------------
// por si acaso ...(en windows se usa)
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

// includes en 'recursos/include'

#include "tup_mat.h"
#include "lector-jpg.h"
#include "fbo.h"
#include "cauce.h"

using namespace tup_mat ;

// ---------------------------------------------------------------------
// número aleatorio entre 0 y 1
inline float alea01() { return float(std::rand())/float(RAND_MAX); }

// ---------------------------------------------------------------------
// quita el path de un nombre de archivo con path
std::string QuitarPath( const std::string & path_arch ) ;

// ---------------------------------------------------------------------
// traza la ejecución
#define traza() { std::cout << "archivo: " << __FILE__ << ", linea: " << __LINE__ << std::endl << std:: flush ;}

// ---------------------------------------------------------------------
// log macro log(a,b,c,..)
// see: https://gist.github.com/carlos-urena/6290b4fa0a5c50efd7bd2c4f0b5c54d8

inline void log_func_aux()
{
    using namespace std ;
    cout << endl ;
}

template<typename T, typename ...Tipos> 
inline void log_func_aux( const T & first, const Tipos & ...parametros )
{
   using namespace std ;
   cout << first << " ";
   log_func_aux( parametros... );
}

template<typename ...Tipos> 
inline void log_func( const std::string & file, const std::string & func_name, const int line_num, 
           const Tipos & ...parametros )
{
   using namespace std ;
   cout << QuitarPath( file ) << ", " << func_name << "(...), " << line_num << ": " ; 
   log_func_aux<Tipos...>( parametros... );
}

#define log( ... )  log_func( __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__ )

// ---------------------------------------------------------------------
// comprobación de errores de OpenGL
#define CError() CompruebaErrorOpenGL(__FILE__,__LINE__)
void CompruebaErrorOpenGL( const char * nomArchivo, int linea ) ;

// ---------------------------------------------------------------------
// gestion de un error
#define Error(msg)   GestionarError(msg,__FILE__,__LINE__)
void GestionarError( const char * msg, const char * nomArchivo, int linea ) ;

// ---------------------------------------------------------------------
// true solo si el rendering context activo soporta al menos una versión de openGL
bool SoportaGL( const int min_major, const int min_minor ) ;

// ---------------------------------------------------------------------
// true solo si el rendering context activo soporta al menos una versión de GLSL
bool SoportaGLSL( const int min_major, const int min_minor ) ;

//----------------------------------------------------------------------
// aborta si no se soporta una versión de OpenGL
void ExigirVersionGL( const int min_major, const int min_minor, const char * msg ) ;

//----------------------------------------------------------------------
// comprobar si está GLEW, si está inicializarlo, en otro caso error y aborta
void Inicializa_GLEW() ;

// ----------------------------------------------------------------------------
// fijar el icono que se usa para la ventana GLFW, usando imagen UGR
void FijarIconoVentanaGLFW( GLFWwindow * glfw_window ) ;

// ---------------------------------------------------------------------
// GLFW: especificar 'hints' para inicialización del rendering
// context de la ventana GLFW (se puede pedir uOpenGL 4 aquí)
void ConfigurarGLFW() ;

// ----------------------------------------------------------------------------------
// calcula posicion y tamaño de la ventana GLFW en función de la resolucion del escritorio
void TamPosVentanaGLFW( int & tamx, int & tamy, int & posx, int & posy );

// ----------------------------------------------------------------------------
// función que gestiona un error en GLFW, se fija con 'glfwSetErrorCallback'
// se imprimer código, mensaje, y se aborta
void ErrorGLFW( int codigo, const char * mensaje );

// ---------------------------------------------------------------------
// escribe en stdout características de opengl
void InformeOpenGL() ;

// ---------------------------------------------------------------------
// devuelve 'true' si está disponible el buffer de acumulación para
// usar super-sampling de 'fuerza bruta'
bool BufferAcumulacionDisponible( GLint & nb_accum_r, GLint & nb_accum_g, GLint & nb_accum_b );

// ---------------------------------------------------------------------
// crear una ventana glut centrada en el escritorio
void CrearVentanaGLUT( const char * titulo, const  float fr_alto ) ;

// ----------------------------------------------------------------------------
// funciones auxiliares para dibujar los ejes

//void CrearObjetoCuadrica() ;
void DibujarCono( GLdouble base, GLdouble height, GLdouble slices, GLdouble stacks );
void DibujarEsfera( GLdouble radius, GLdouble slices, GLdouble stacks ) ;
void DibujarCilindro( GLdouble radius, GLdouble height, int slices, int stacks );
void DibujarEjeZ( Cauce & cauce );
void DibujarEjesSolido( Cauce & cauce );
void DibujarEjesLineas( Cauce & cauce );

// -----------------------------------------------------------------------------
// imprimie en 'cout' una línea con información de la frecuencia con la que se llama
// a la función

void ImprimirFPS();

// -----------------------------------------------------------------------------
// dibujar una cruz
void DibujarCruz( Cauce & cauce, const float d );

// -----------------------------------------------------------------------------
// dibuja un FBO en un rectángulo en la parte superior izquierda
void DibujarFBO( Cauce & cauce, Framebuffer & fbo );

// -----------------------------------------------------------------------------
// Si el nombre de un archivo tiene la barra invertida ('\') pero no estamos
// en windows, sustituir la barra invertida '\' por la barra normal '/'
//std::string ProcesarNombreArchivo( const std::string & sorg );

// -----------------------------------------------------------------------------
// calcula (la primera vez) y devuelve el path hasta la carpeta de materiales 

std::string PathCarpetaMateriales(  );

// -----------------------------------------------------------------------------
// buscar un archivo en la carpeta de materiales o en la carpeta de archivos de alumno

std::string BuscarArchivo( const std::string & nombre_arch, const std::string & subcarpeta );

// -----------------------------------------------------------------------------

inline constexpr int CodificaBytes( const unsigned char b0, const unsigned char b1, const unsigned char b2)
{
   return int(b0) + ( int(0x100U)*int(b1) ) + ( int(0x10000U)*int(b2) ) ;
}

// --------------------------------------------------------------------------
// Creación y/o activación de VBOs y VAOs

// VBOs de atributos
GLenum CrearVBOAtrib( GLuint ind_atributo,   GLenum  tipo_datos, 
                      GLint  num_vals_tupla, GLsizei num_tuplas, 
                      const GLvoid * datos );
GLenum CrearVBOAtrib( unsigned indice_atrib, const std::vector<Tupla3f> & tabla );
GLenum CrearVBOAtrib( unsigned indice_atrib, const std::vector<Tupla2f> & tabla );


// VBOs de índices
GLenum CrearVBOInd( GLenum tipo_indices, GLint num_indices, const void * indices );
GLenum CrearVBOInd( unsigned num_indices, const unsigned * indices );
GLenum CrearVBOInd( const std::vector<unsigned> & indices );
GLenum CrearVBOInd( const std::vector<Tupla3u>  & indices );

// VAOs
GLenum CrearVAO();



#endif // AUX_HPP
