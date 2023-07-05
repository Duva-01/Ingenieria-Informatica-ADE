// *********************************************************************
// **
// ** Rutinas auxiliares:
// ** - Gestión de errores en general
// ** - Comprobación de errores de OpenGL (implementacion)
// ** - Inicialización de glew,
// ** - Comprobacion de la versión de OpenGL
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

#include <sys/types.h>  // para buscar carpetas con 'stat'
#include <sys/stat.h>   // para buscar carpetas con 'stat'
#include <unistd.h>      // para 'getcwd' y otros ...

#include "ig-aux.h"

// *********************************************************************
// gestion de errores

void GestionarError( const char * msg, const char * nomArchivo, int linea )
{
   std::cout
         << std::endl
         << "-----------------------------------------------------------" << std::endl
         << "Error detectado:" << std::endl
         << "   descripción : " << msg  << "." << std::endl
         << "   archivo     : " << nomArchivo << std::endl
         << "   línea       : " << linea << std::endl
         << "-----------------------------------------------------------" << std::endl
         << "programa abortado." << std:: endl
         << std::flush ;

    exit(1) ;
}



// -----------------------------------------------------------------------------
// códigos y descripciones de errores detectado por 'glGetError'

const unsigned numErrors = 6 ;

const GLenum errCodes[numErrors] =
{
   GL_NO_ERROR ,
   GL_INVALID_ENUM ,
   GL_INVALID_VALUE ,
   GL_INVALID_OPERATION ,
   GL_INVALID_FRAMEBUFFER_OPERATION ,  // REVISAR (pq no está definido con glfw?)
   GL_OUT_OF_MEMORY
} ;

const char * errDescr[numErrors] = 
{
   "Error when trying to report an error: no error has been recorded",
   "An unacceptable value is specified for an enumerated argument",
   "A numeric argument is out of range",
   "The specified operation is not allowed in the current state",
   "The command is trying to render to or read from the framebuffer while the currently bound framebuffer is not framebuffer complete (i.e. the return value from 'glCheckFramebufferStatus' is not GL_FRAMEBUFFER_COMPLETE)",
   "There is not enough memory left to execute the command"
} ;

const char * errCodeString[numErrors] =
{
   "GL_NO_ERROR",
   "GL_INVALID_ENUM",
   "GL_INVALID_VALUE",
   "GL_INVALID_OPERATION",
   "GL_INVALID_FRAMEBUFFER_OPERATION",
   "GL_OUT_OF_MEMORY"
} ;

// ---------------------------------------------------------------------
// devuelve descripción de error dado el código de error opengl

std::string ErrorDescr( GLenum errorCode )
{
   int iErr = -1 ;
   for ( unsigned i = 0 ; i < numErrors ; i++ )
   {  if ( errCodes[i] == errorCode)
      {  iErr = i ;
         break ;
      }
   }
   if ( iErr == -1 )
      return std::string("Error when trying to report an error: error code is not a valid error code for 'glGetError'") ;
   return std::string( errDescr[iErr] ) ;
}

std::string ErrorCodeString( GLenum errorCode )
{
   int iErr = -1 ;
   for ( unsigned i = 0 ; i < numErrors ; i++ )
   {  if ( errCodes[i] == errorCode)
      {  iErr = i ;
         break ;
      }
   }
   if ( iErr == -1 )
      return std::string("** invalid error code **") ;
   return std::string( errCodeString[iErr] ) ;
}

//----------------------------------------------------------------------

void CompruebaErrorOpenGL( const char * nomArchivo, int linea )
{
   const GLint codigoError = glGetError() ;

   if ( codigoError != GL_NO_ERROR )
   {  std::cout
         << std::endl
         << "Detectado error de OpenGL. Programa abortado." << std::endl
         << "   archivo (linea) : " << QuitarPath(nomArchivo) << " (" << linea << ")" << std::endl
         << "   código error    : " << ErrorCodeString( codigoError )  << std::endl
         << "   descripción     : " << ErrorDescr( codigoError )  << "." << std::endl
         << std::endl << std::flush ;
      exit(1);
   }
}

//----------------------------------------------------------------------

void CalculaVersion(  const char *str, int & major, int & minor )
{
   // podría hacerse así, pero las primeras versiones (1.5-) al parecer no tienen GL_MAJOR_VERSION.... :-(
      // glGetIntegerv( GL_MAJOR_VERSION, &major ) ;
      // glGetIntegerv( GL_MINOR_VERSION, &minor ) ;

   using namespace std ;
   const
      std::string ver(str) ;
   size_t //auto
      blanco = ver.find_first_of(' ') ;
   if ( blanco == string::npos )
      blanco = ver.length() ;

   const size_t //auto
      punto = ver.find_first_of('.') ;
   assert( punto != string::npos ); // salta si no encuentra el punto
   assert( punto+1 < blanco );

   const string
      smajor = ver.substr( 0, punto ),
      sminor = ver.substr( punto+1, blanco-punto-1 );

   major = atoi(smajor.c_str());
   minor = atoi(sminor.c_str());
}

// ---------------------------------------------------------------------
// quita el path de un nombre de archivo con path

std::string QuitarPath( const std::string & path_arch )
{
   const size_t pos_barra = path_arch.find_last_of('/') ;

   if ( pos_barra == std::string::npos ) 
      return path_arch ;
   else
      return path_arch.substr( pos_barra+1 );
}

// ---------------------------------------------------------------------
// devuelve true si se soporta al menos una versión de OpenGL, se
// proporciona el número de version dividido en "major" y "minor"

bool SoportaGL( const int min_major, const int min_minor )
{
   static GLint major,minor ;
   static bool primera = true ;

   if ( primera )
   {
      // parser de la cadena (GL_VERSION)
      using namespace std ;
      CalculaVersion( (const char *) glGetString(GL_VERSION), major, minor ) ;
      cout << "calculada version de OpenGL: " << major << "." << minor << " (" << glGetString(GL_VERSION) << ")" << endl << flush ;
      primera = false ;
   }

   if ( min_major < major )
      return true;
   if ( min_major == major )
      if ( min_minor <= minor )
         return true;
   return false ;
}

// ---------------------------------------------------------------------

bool SoportaGLSL( const int min_major, const int min_minor )
{
   static GLint major,minor ;
   static bool primera = true ;

   if ( primera )
   {
      // parser de la cadena (GL_VERSION)
      using namespace std ;
      CalculaVersion( (const char *) glGetString(GL_SHADING_LANGUAGE_VERSION), major, minor ) ;
      cout << "calculada version de GLSL: " << major << "." << minor << " (" << glGetString(GL_SHADING_LANGUAGE_VERSION) << ")" << endl << flush ;
      primera = false ;
   }

   if ( min_major < major )
      return true;
   if ( min_major == major )
      if ( min_minor <= minor )
         return true;
   return false ;
}


//----------------------------------------------------------------------

void Inicializa_GLEW(  ) // necesario para Linux y resto de SS.OO.
{
#ifndef __APPLE__
   static bool primera = true ;

   if ( ! primera )
      return ;
   primera = false ;

   using namespace std ;
#ifndef GLEW_OK
   Error("no se han incluido los headers de GLEW correctamente, usa '#include <ig-aux.hpp>' para incluir símbolos de OpenGL/GLFW/GLEW") ;
#else
   GLenum codigoError = glewInit();
   if ( codigoError != GLEW_OK ) // comprobar posibles errores
   {
      const std::string errmsg =
         std::string( "Imposible inicializar ’GLEW’, mensaje recibido: ") +
         std::string( (const char *)glewGetErrorString(codigoError) ) ;
      Error(errmsg.c_str()) ;
   }
   else
      cout << "librería GLEW inicializada correctamente." << endl << flush ;
#endif
#else
   // en macOS (símbolo __APPLE__ definido) no es necesario usar 'glew'
#endif
}
// ----------------------------------------------------------------------------
// función que gestiona un error en GLFW, se fija con 'glfwSetErrorCallback'

void ErrorGLFW( int codigo, const char * mensaje )
{
   using namespace std ;
   cout << "Error en la librería GLFW: " << endl
        << "   Código  : " << codigo << endl
        << "   Mensaje : " << mensaje << endl
        << "(programa abortado)" << endl ;
   exit(1);
}

// ---------------------------------------------------------------------

void InformeOpenGL(  )
{
   CError();

   const GLubyte * vendor   = glGetString( GL_VENDOR );
   const GLubyte * renderer = glGetString( GL_RENDERER );
   const GLubyte * version  = glGetString( GL_VERSION );
   const GLubyte * glsl_ver = glGetString( GL_SHADING_LANGUAGE_VERSION );

   GLfloat rango_su[2], rango_ali[2] ;
   glGetFloatv( GL_SMOOTH_LINE_WIDTH_RANGE,  rango_su  );
   glGetFloatv( GL_ALIASED_LINE_WIDTH_RANGE, rango_ali );
   
   CError();

   using namespace std ;
   cout  << "Datos de versión e implementación de OpenGL" << endl
         << "    implementación de  : " << vendor  << endl
         << "    hardware           : " << renderer << endl
         << "    version de OpenGL  : " << version << endl
         << "    version de GLSL    : " << glsl_ver << endl
         << "    rango anchos línea : " << rango_su[0] << " - " << rango_su[1] << " (suave)" << endl 
         << "    rango anchos línea : " << rango_ali[0] << " - " << rango_ali[1] << " (aliased)" << endl 
         << flush ;

   
   
   CError();
}
// ----------------------------------------------------------------------------------
// calcula posicion y tamaño de la ventana en función de la resolucion del escritorio

void TamPosVentanaGLFW( int & tamx, int & tamy, int & posx, int & posy )
{
   // leer el tamaño del escritorio para posicionar y dimensionar la ventana
   const GLFWvidmode *
      modo      = glfwGetVideoMode( glfwGetPrimaryMonitor( ) ); //modo act. del mon. primario.
   const int
      ancho_tot = modo->width,     // ancho total del escritorio en el modo actual
      alto_tot  = modo->height ;    // alto total del escritorio en el modo actual

   tamx  = (alto_tot*4)/5 ;     // ancho de la ventana
   tamy  = tamx ;               // alto de la ventana
   posx  = (ancho_tot-tamx)/2 ; // posicion X de la ventana
   posy  = (alto_tot-tamy)/2;   // posición Y de la ventana
}

// ----------------------------------------------------------------------------
// fijar el icono que se usa para la ventana GLFW, usando imagen UGR
// * En macOS no hace nada (no se puede)
// * Se evita intentarlo en Windows (aborta), y en versiones de GLFW
//   previas a la 3.2 (no está definido 'glfwSetWindowIcon')

void FijarIconoVentanaGLFW( GLFWwindow * glfw_window )
{
   #ifndef WINDOWS
   #if GLFW_VERSION_MAJOR >= 3
   #if GLFW_VERSION_MINOR >= 2

   using namespace std ;
   assert( glfw_window != nullptr );

   unsigned ancho, alto ;
   unsigned char * img = LeerArchivoJPEG( "../recursos/imgs/window-icon.jpg", ancho, alto );
   assert( img != nullptr );
   assert( 0 < ancho );
   assert( 0 < alto );

   static GLFWimage glfw_img  ;
   constexpr unsigned long nc = 4 ;
   //cout << "icono, ancho = " << ancho << ", alto == " << alto << endl ;

   glfw_img.width = ancho ;  
   glfw_img.height = alto ;
   glfw_img.pixels = new unsigned char [nc*glfw_img.width*glfw_img.height] ;

   unsigned char * pwrite = glfw_img.pixels ;

   for( int iy = 0 ; iy < glfw_img.height ; iy++ )
   for( int ix = 0 ; ix < glfw_img.width ; ix++ )
   {
      unsigned char * pread = img + ((3*ancho*iy) + ix) ;
      //const unsigned char vwrite = ( pread[0] != 255 || pread[1] != 255 || pread[2] != 255 ) ? 255 : 0 ;
      for( unsigned i = 0 ; i < nc-1 ; i++ )
         pwrite[i] = pread[i] ;
      pwrite[nc-1] = 255 ;
      pwrite += nc ;
   }
   glfwSetWindowIcon( glfw_window, 1, &glfw_img  );

   delete [] glfw_img.pixels ;
   delete [] img ;

   #endif
   #endif
   #endif
}

constexpr GLsizei long_paso      = 0 ;
constexpr void *  desplazamiento = 0 ;

GLenum CrearVBOAtrib( GLuint ind_atributo,   GLenum  tipo_datos, 
                      GLint  num_vals_tupla, GLsizei num_tuplas, 
                      const GLvoid * datos )
{ 
   // 1. comprobar intgredidad los parámetros:
   assert( datos != nullptr );   
   assert( num_vals_tupla > 0 ); assert( num_tuplas > 0 );
   // assert( ind_atributo < numero_atributos_cauce );
   assert( tipo_datos == GL_FLOAT || tipo_datos == GL_DOUBLE );

   // 2. calcular parámetros no independientes
   const GLsizei 
      num_bytes_valor = (tipo_datos == GL_FLOAT) ? sizeof(float) 
                                                : sizeof(double),
      tamano_en_bytes = num_tuplas * num_vals_tupla * num_bytes_valor;
  
   // 3. crear y activar VBO (vacío por ahora)
   GLenum nombre_vbo = 0;
   glGenBuffers( 1, &nombre_vbo ); assert( 0 < nombre_vbo );
   glBindBuffer( GL_ARRAY_BUFFER, nombre_vbo ); 

   // 4. transfiere datos desde aplicación al VBO en GPU
   glBufferData( GL_ARRAY_BUFFER, tamano_en_bytes, datos, GL_STATIC_DRAW );  
   
   // 5. establece formato y dirección de inicio en el VBO
   glVertexAttribPointer( ind_atributo, num_vals_tupla, tipo_datos, 
                           GL_FALSE, long_paso, desplazamiento );
   
   // 6. habilita la tabla, hacer que no haya ningun VBO activo
   glEnableVertexAttribArray( ind_atributo );
   glBindBuffer( GL_ARRAY_BUFFER, 0 );

   // 7. devolver el nombre o identificador de VBO
   return nombre_vbo ;
}
// ---------------------------------------------------------------------------------
// crea y activa un VBO para una tabla de atributos que contiene tuplas de 3 flotantes 
// devuelve el nombre del VBO

GLenum CrearVBOAtrib( unsigned indice_atrib, const std::vector<Tupla3f> & tabla )
{
   return CrearVBOAtrib( indice_atrib, GL_FLOAT, 3, tabla.size(), tabla.data() );
}
// ---------------------------------------------------------------------------------
// crea y activa un VBO para una tabla de atributos que contiene tuplas de 2 flotantes 
// devuelve el nombre del VBO

GLenum CrearVBOAtrib( unsigned indice_atrib, const std::vector<Tupla2f> & tabla )
{
   return CrearVBOAtrib( indice_atrib, GL_FLOAT, 2, tabla.size(), tabla.data() );
}

// ---------------------------------------------------------------------------------
// Crea y activa un VBO para una tabla de índices
// la tabla tiene datos de tipo 'unsigned int' (GL_UNSIGNED_INT)
// devuelve el nombre del VBO
// queda 'binded' en el target 'GL_ELEMENT_ARRAY_BUFFER'

GLenum CrearVBOInd( GLenum tipo_indices, GLint num_indices, const void * indices )
{

   // 1. comprobar la integridad de los parámetros
   assert( num_indices > 0 ); 
   assert( indices != nullptr );
   assert( tipo_indices == GL_UNSIGNED_BYTE  || 
           tipo_indices == GL_UNSIGNED_SHORT || 
           tipo_indices == GL_UNSIGNED_INT  );

   CError();
   
   // 2. calcular cuantos bytes ocupa cada índice y la tabla completa
   const GLint num_bytes_indice = 
      (tipo_indices == GL_UNSIGNED_BYTE ) ? sizeof(unsigned char)  :
      (tipo_indices == GL_UNSIGNED_SHORT) ? sizeof(unsigned short) :
                                            sizeof(unsigned int)     ;
   const GLsizeiptr tamano_en_bytes = num_bytes_indice * num_indices ; 

   // 3. crear y activar el VBO
   GLenum nombre_vbo = 0;
   glGenBuffers( 1, &nombre_vbo );  assert( 0 < nombre_vbo );
   glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, nombre_vbo ); 

   // 4. copiar los índices desde la aplicación al VBO en la GPU
   glBufferData( GL_ELEMENT_ARRAY_BUFFER, tamano_en_bytes, indices, 
                  GL_STATIC_DRAW ); 

   CError();
   // 5. hecho, devolver el nombre o identificador de VBO
   return nombre_vbo ;
}

// ----------------------------------------------------------------------------
// idem, aceptando exclusivamente datos de tipo 'unsigned int'

GLenum CrearVBOInd( unsigned num_indices, const unsigned * indices )
{
   return CrearVBOInd( GL_UNSIGNED_INT, num_indices, indices );
}
// ----------------------------------------------------------------------------
// idem, aceptando un vector (stl) de unsigned 

GLenum CrearVBOInd( const std::vector<unsigned> & indices )
{
  return CrearVBOInd( GL_UNSIGNED_INT, indices.size(), indices.data() );
}
// ----------------------------------------------------------------------------
// idem, aceptando un vector de tuplas de 3 enteros cada una 

GLenum CrearVBOInd( const std::vector<Tupla3u> & indices )
{
  return CrearVBOInd( GL_UNSIGNED_INT, 3*indices.size(), indices.data() );
}

// -----------------------------------------------------------------------
// Crea y activa un VAO 

GLenum CrearVAO()
{
   CError();    
   GLenum nombre_vao = 0 ;
   glGenVertexArrays( 1, &nombre_vao ); assert( 0 < nombre_vao );
   glBindVertexArray( nombre_vao );
   CError();
   return nombre_vao ;
}

// ---------------------------------------------------------------------------
// crea una tabla de índices para una rejilla con topología cilindrica

void CrearIndicesTopologiaCilindrica( std::vector<Tupla3u> & indices, 
                                      const unsigned na, const unsigned nb )
{
   indices.clear();

   for( unsigned i = 0 ; i < na ; i++ )
   for( unsigned j = 0 ; j < nb ; j++ )
   {        
      const unsigned int
         i00 = (i  )*nb + j,
         i10 = (i+1)*nb + j,
         i01 = (i  )*nb + ((j+1) % nb),
         i11 = (i+1)*nb + ((j+1) % nb);
   
      indices.push_back({ i00, i01, i11 });
      indices.push_back({ i00, i11, i10 });
   }
}

// ----------------------------------------------------------------------------
// dibuja un cilindro, con eje en el eje Z, entre Z=0 y Z=1, y radio unidad.
// (es neutral: no modifica el estado del cauce - únicamente crea el VAO (la primera vez))

void DibujarCilindroZ01( Cauce & cauce )
{
   constexpr unsigned int 
         nz = 5,     // número de 'slices'
         ns = 16 ;   // número de sectores

   // poblar las tablas de coordenadas de posiciones y de índices
   // (únicamente en la 1a llamada a esta función)

   static std::vector<Tupla3f> posiciones ;
   static std::vector<Tupla3u> indices ;
   static GLenum               nombre_vao = 0 ;

   if ( nombre_vao == 0 )
   {
      CrearIndicesTopologiaCilindrica( indices, nz, ns );

      for( unsigned iz = 0 ; iz <= nz ; iz++ )
      for( unsigned is = 0 ; is < ns ; is++ )
      {  
         const float alpha = (2.0f*M_PI*float(is))/float(ns);
         posiciones.push_back( { std::cos(alpha), std::sin(alpha), float(iz)/float(nz) } );
      }
      nombre_vao = CrearVAO(  ); 
      CrearVBOAtrib( ind_atrib_posiciones, posiciones );
      CrearVBOInd( indices );
 }
   else 
      glBindVertexArray( nombre_vao );

   glDrawElements( GL_TRIANGLES, 3*indices.size(), GL_UNSIGNED_INT, 0 );
   glBindVertexArray( 0 );
}

// ----------------------------------------------------------------------------
// dibuja un cono, con eje en el eje Z, entre Z=0 y Z=1, y radio unidad.
// (es neutral: no modifica el estado del cauce - únicamente crea el VAO (la primera vez))

void DibujarConoZ01( Cauce & cauce )
{
   constexpr unsigned int 
         nz = 5,   // número de 'slices'
         ns = 16 ; // número de sectores

   // poblar las tablas de coordenadas de posiciones y de índices
   // (únicamente en la 1a llamada a esta función)

   static std::vector<Tupla3f> posiciones ;
   static std::vector<Tupla3u> indices ;
   static GLenum nombre_vao = 0 ;
   
   if ( nombre_vao == 0 )
   {
      CrearIndicesTopologiaCilindrica( indices, nz, ns );

      for( unsigned iz = 0 ; iz <= nz ; iz++ )
      for( unsigned is = 0 ; is < ns ; is++ )
      {  
         const float alpha = (2.0f*M_PI*float(is))/float(ns);
         const float z     = float(iz)/float(nz) ;
         posiciones.push_back( { (1.0f-z)*std::cos(alpha), (1.0f-z)*std::sin(alpha), z } );
      }
      nombre_vao = CrearVAO( ); 
      CrearVBOAtrib( ind_atrib_posiciones, posiciones );
      CrearVBOInd( indices );
 }
   else 
      glBindVertexArray( nombre_vao );

   glDrawElements( GL_TRIANGLES, 3*indices.size(), GL_UNSIGNED_INT, 0 ); 
   glBindVertexArray( 0 );
}

// ----------------------------------------------------------------------------
// dibuja un cilindro, con eje en el eje Z, entre Z=0 y Z=longitud_z, y radio 'radio'

void DibujarCilindroZ( Cauce & cauce, GLdouble radio, GLdouble longitud_z )
{
   CError();
   cauce.pushMM();
      cauce.compMM( MAT_Escalado( radio, radio, longitud_z ));
      DibujarCilindroZ01( cauce );
   cauce.popMM();
   CError(); 
}

// ----------------------------------------------------------------------------
// dibuja un cono, con eje en el eje Z, entre Z=z0 y Z=z1, 'radio' es el radio en z0, 
// (z0 < z1 )
void DibujarConoZ( Cauce & cauce,  const float radio, const float z0, const float z1 )
{
   CError();
   cauce.pushMM();
      cauce.compMM( MAT_Traslacion({ 0.0, 0.0, z0 }));
      cauce.compMM( MAT_Escalado( radio, radio, z1-z0 ));
      DibujarConoZ01( cauce );
   cauce.popMM();
   CError(); 
}

// ----------------------------------------------------------------------------
// dibuja el eje Z

void DibujarEjeZ( Cauce & cauce )
{
   CError();
   const GLfloat
   	zmed     = 0.93,  // z fin del cilindro
   	rad_fle  = 0.03 ;  // radio del cono

   // dibujar línea del eje (más finas y más alargadas)
   
   static const std::vector<Tupla3f> pos = { {0.0,0.0,-2.0}, {0.0,0.0,5.0} };
   static GLenum nombre_vao = 0 ;

   if ( nombre_vao == 0 ) 
   {
      nombre_vao = CrearVAO( );
      CrearVBOAtrib( ind_atrib_posiciones, pos );
   }
   else 
      glBindVertexArray( nombre_vao );

   glDrawArrays( GL_LINES, 0, pos.size() );
   glBindVertexArray( 0 );
   CError();

   // dibujar cilindro y cono
   DibujarCilindroZ( cauce, rad_fle*0.4, zmed ); 
   DibujarConoZ( cauce, rad_fle, zmed, 1.0 );
      
   CError();
}

//----------------------------------------------------------------------
// dibuja los ejes X,Y y Z, usando cilindros, conos y líneas.

void DibujarEjesSolido( Cauce & cauce )
{
   //log("entra");
   CError();

   // no se usa iluminación ni texturas, se dibuja relleno. 
   cauce.fijarEvalMIL( false );
   cauce.fijarEvalText( false );
   glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

   // dibujar ejes:

   // eje X, color rojo
   cauce.fijarColor( 1.0, 0.2, 0.2 );
   cauce.pushMM();  
      cauce.compMM( MAT_Rotacion( 90.0, { 0.0,1.0,0.0 }) );
      DibujarEjeZ( cauce ) ; 
   cauce.popMM();
   CError();
   
   // eje Y, color verde
   cauce.fijarColor( 0.3, 1.0, 0.3 );
   cauce.pushMM();
      cauce.compMM( MAT_Rotacion( -90.0, { 1.0, 0.0, 0.0 }) );
      DibujarEjeZ( cauce ) ;
   cauce.popMM(); 
   CError();

   // eje Z, color azul
   cauce.fijarColor( 0.1, 0.7, 1.0 );
   DibujarEjeZ( cauce ) ;
   CError();

   // bola en el origen, negra (temporalmente desactivado)
   cauce.fijarColor( 0.0, 0.0, 0.0 );
   //DibujarEsfera( 0.04, 16, 8 );

   CError();
}


// -----------------------------------------------------------------------------
// imprimie en 'cout' una línea con información de la frecuencia con la que se llama
// a la función

void ImprimirFPS()
{
   using namespace std ; 
   using namespace std::chrono ;

   // tipo para duraciones en segundos
   typedef duration<float,ratio<1,1>> DuracionSegs ;

   
   constexpr int  num_cuadros = 20 ;   // numero de frames entre impresiones de los FPS
   static int     count       = 0 ;    // cuenta de frames
   static bool    primera_vez = true ;

   // instante final del cuadro anterior (excepto en la 1a llamada)
   static time_point<steady_clock> fin_cuadro_anterior ;

   // saltar 'num_cuadros' veces la impresión
   if ( count % num_cuadros != 0 )
   {
      count++ ;
      return ;
   }

   // registrar instante actual
   time_point<steady_clock> fin_cuadro_actual = steady_clock::now() ;


   // si no es la primera vez, calcular e imprimir
   if ( ! primera_vez )
   {
      const float segundos_cuadro = (DuracionSegs( fin_cuadro_actual - fin_cuadro_anterior )).count()/float(num_cuadros) ,
                  fps             = 1.0/segundos_cuadro ;

      // guardar flags de formato de 'cout'
      ios estado_anterior( nullptr );
      estado_anterior.copyfmt( cout );

      // imprimir cambiando los flags
      cout << fixed << setprecision( 1 )
           << setw(5) << fps << "FPS "
           << "(" << setw(5) <<  (segundos_cuadro*1000.0) << " ms)."
           << defaultfloat << endl ;

      // restaurar formato de 'cout'
      cout.copyfmt( estado_anterior );
   }
   count ++ ;
   primera_vez = false ;
   fin_cuadro_anterior = fin_cuadro_actual ;
}
// ----------------------------------------------------------------------------
// dibujar una cruz blanca en el centro del viewport, deja el estado de OpenGL fatal

// void DibujarCruz( Cauce & cauce, const float d )
// {
//    glColor3f( 0.0, 0.0, 0.0 );
//    cauce.fijarEvalMIL( false );
//    cauce.fijarEvalText( false );
//    cauce.fijarMatrizProyeccion( MAT_Ident() );
//    cauce.fijarMatrizVista( MAT_Ident() );

//    glDisable( GL_DEPTH_TEST );
//    glBegin( GL_LINES );
//       glVertex3f( -d, 0.0, 0.0 );
//       glVertex3f( +d, 0.0, 0.0 );
//       glVertex3f( 0.0, -d, 0.0 );
//       glVertex3f( 0.0, +d, 0.0 );
//    glEnd();
//    glEnable( GL_DEPTH_TEST );
//    CError();
// }

// ----------------------------------------------------------------------------
//
void DibujarFBO( Cauce & cauce, Framebuffer & fbo )
{
   CError();
   GLuint textId = fbo.leerTextId();

   // ponemos el color a blanco para que al multiplicar por textura salga la textura tal cual.
   cauce.fijarColor( 1.0, 1.0, 1.0 );

   cauce.fijarMatrizProyeccion( MAT_Ident() );
   cauce.fijarMatrizVista( MAT_Ident() );
   cauce.fijarEvalMIL( false );
   cauce.fijarEvalText( true, textId );
   cauce.fijarTipoGCT( 0 );
   CError();

   glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
   glDisable( GL_CULL_FACE );
   glDisable( GL_DEPTH_TEST );
   CError();

   static const std::vector<Tupla3f> posiciones = 
   {  
      { -0.95, +0.60, 0.0 }, { -0.60, +0.60, 0.0 }, 
      { -0.60, +0.95, 0.0 }, { -0.95, +0.95, 0.0 }
   } ;
   static const std::vector<Tupla3u> indices = 
   { 
      { 0, 1, 2 }, { 0, 2, 3 } 
   } ;
   static const std::vector<Tupla2f> coords_text = 
   { 
      { 0.0, 0.0 }, { 1.0, 0.0 }, 
      { 1.0, 1.0 }, { 0.0, 1.0 } 
   } ;

   static GLenum nombre_vao = 0 ;

   if ( nombre_vao == 0 )
   {
      nombre_vao = CrearVAO( );
      CrearVBOAtrib( ind_atrib_posiciones, posiciones );
      CrearVBOAtrib( ind_atrib_coord_text, coords_text ); 
      CrearVBOInd( indices );
   }
   else 
      glBindVertexArray( nombre_vao );
   
   glDrawElements( GL_TRIANGLES, 3*indices.size(), GL_UNSIGNED_INT, 0 );
   glBindVertexArray( 0);
   
   glEnable( GL_DEPTH_TEST );
}


//------
// Reemplazar todas las ocurrencias de 'oldString' por 'newString' dentro de la cadena 'line'
// adaptado de:
// https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
// ( se usa en 'ProcesarNombreArchivo', a continuación)

void FindReplace(std::string& line, const std::string& oldString, const std::string& newString)
{
  const size_t oldSize = oldString.length();

   // do nothing if line is shorter than the string to find
   if( oldSize > line.length() )
      return;

   const size_t newSize = newString.length();
   for( size_t pos = 0; ; pos += newSize )
   {
    // Locate the substring to replace
      pos = line.find( oldString, pos );
      if( pos == std::string::npos )
         return;
      if( oldSize == newSize )
      {
         // if they're same size, use std::string::replace
         line.replace( pos, oldSize, newString );
      }
      else
      {
         // if not same size, replace by erasing and inserting
         line.erase( pos, oldSize );
         line.insert( pos, newString );
      }
   }
}

// -----------------------------------------------------------------------------
// Si el nombre de un archivo tiene la barra invertida ('\') pero no estamos
// en windows, sustituir la barra invertida '\' por la barra normal '/'

// std::string ProcesarNombreArchivo( const std::string & sorg )
// {
// #ifdef WINDOWS
//    return sorg ;
// #else
//    std::string res = sorg ;
//    using namespace std ;
//    FindReplace(res,"\\","/");   // el segundo parámetro es un único caracter (\), escapado con \ para poder escribirlo en C/C++)
//    //cout << "[" << sorg << "] --> [" << res << "]" << endl ;
//    return res ;
// #endif
// }

// -----------------------------------------------------------------------------
// Devuelve el path relativo hasta una carpeta con cierto nombre ('carpeta')
// busca la carpeta en el directorio de trabajo, si no está busca en el padre, y 
// así sucesivamente hasta 'n' veces como mucho
// Es decir, busca: ./<carpeta>, ./../<carpeta>, ../../<carpeta>, ../../../<carpeta> y ../../../../<carpeta>
// (puede requerir adaptaciones para windows, usando \ en lugar de /)
//
// Basado en:
// https://stackoverflow.com/questions/18100097/portable-way-to-check-if-directory-exists-windows-linux-c
// (respuesta de Adam Parson)

std::string PathCarpeta( const std::string & carpeta, unsigned int n )
{
   using namespace std ;
   string prefijo = "" ; 
   
   for( unsigned i = 0 ; i < n ; i++ )
   {
      const string       path   = prefijo + carpeta ;
      const char * const c_str  = path.c_str();
      struct stat        info ;

      if ( stat( c_str, &info ) == 0 )
         if ( S_ISDIR( info.st_mode )  ) // ( info-st_mode & S_IFDIR ) 
            return path ;
      
      if ( i < n-1 )
         prefijo = prefijo + "../" ;
   }

   cout << "No encuentro el path hasta la carpeta '" << carpeta << "' (aborto)" << endl ;
   exit(1);   
}

// -----------------------------------------------------------------------------
// calcula (la primera vez) y devuelve el path hasta la carpeta de materiales 

std::string PathCarpetaMateriales(  )
{
   static bool primera = true ;
   static std::string path ;

   if ( primera )
   {
      path = PathCarpeta( "materiales", 8 );
      primera = false ;
      std::cout << "Carpeta de materiales encontrada en: [" << path << "]" << std::endl ;
      return path ;
   }

   return path ;
}

// -----------------------------------------------------------------------------
// calcula (la primera vez) y devuelve el path hasta la carpeta de archivos del alumno

std::string PathCarpetaArchivosAlumno(  )
{
   static bool        primera = true ;
   static std::string path ;

   if ( primera )
   {
      path = PathCarpeta( "archivos-alumno", 8 );
      primera = false ;
      std::cout << "Carpeta de archivos del alumno encontrada en: [" << path << "]" << std::endl ;
      return path ;
   }

   return path ;
}

// ---------------------------------------------------------------------------
// busca un archivo dado su nombre (nombre_arch) con extensión, sin path alguno.
//
// - en 1er lugar lo busca en la carpeta de materiales, dentro de la subcarpeta especificada 
// - si no está, lo busca en la carpeta de archivos del alumno
//
// devuelve el nombre del archivo con la ruta completa, listo para ser abierto.
// si el archivo no se encuentra en ninguna de ambas carpetas, se invoca 'error' (aborta)

std::string BuscarArchivo( const std::string & nombre_arch, const std::string & subcarpeta )
{
   using namespace std ;

   // buscar en la carpeta de materiales:

   const string nombre_path_mat = PathCarpetaMateriales() + "/" + subcarpeta + "/" + nombre_arch ;
   ifstream     archivo_mat ;

   archivo_mat.open( nombre_path_mat.c_str() ); // intentar abrirlo

   if ( archivo_mat.is_open() ) // si se ha podido abrir, cerrarlo y terminar
   {
      archivo_mat.close();
      return nombre_path_mat ;
   }

   // buscar en la carpeta de archivos del alumno:

   const string nombre_path_alu = PathCarpetaArchivosAlumno() + "/" + nombre_arch ;
   ifstream     archivo_alu ;

   archivo_alu.open( nombre_path_alu.c_str() ); // intentar abrirlo,

   if ( archivo_alu.is_open() ) // si se ha podido abrir, cerrarlo y terminar
   {
      archivo_alu.close();
      return nombre_path_alu ;
   }

   // no se ha encontrado: producir mensaje de error y abortar 

   cout << "No se encuentra el archivo: '" << nombre_arch << "'" << endl 
        << "Programa abortado." << endl ; 

   exit(1);
}
