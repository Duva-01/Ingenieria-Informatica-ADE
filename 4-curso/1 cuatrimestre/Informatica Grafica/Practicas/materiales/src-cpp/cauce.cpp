// *********************************************************************
// **
// ** Gestión del cauce gráfico (clase 'Cauce') (implementación)
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


#include "ig-aux.h"
#include "cauce.h" 

// *****************************************************************************
// Cauce programable (OpenGL "moderno", esto es 3.2 o 4.1) (determinar cual de los dos)
// -----------------------------------------------------------------------------

Cauce::Cauce()
{
   using namespace std ;

   // inicializar los nombres de los archivos (gl 3.3 por ahora)
   
#define SHADERS_DIR "../../../materiales/src-shaders/"

   frag_fn = "cauce33-frag.glsl" ;
   vert_fn = "cauce33-vert.glsl" ;

   const std::string frag_fn_full = PathCarpetaMateriales() + "/src-shaders/" + frag_fn ;
   const std::string vert_fn_full = PathCarpetaMateriales() + "/src-shaders/" + vert_fn ;

   // crear y compilar shaders, crear el programa
   id_frag_shader = compilarShader( frag_fn_full, GL_FRAGMENT_SHADER );
   id_vert_shader = compilarShader( vert_fn_full, GL_VERTEX_SHADER );
   id_prog        = glCreateProgram();

	// asociar shaders al programa
	glAttachShader( id_prog, id_frag_shader );
	glAttachShader( id_prog, id_vert_shader );

	// enlazar programa y ver errores
	glLinkProgram( id_prog );
   GLint resultado ;
   glGetProgramiv( id_prog, GL_LINK_STATUS, &resultado );

   // si ha habido errores, abortar
   if ( resultado != GL_TRUE )
   {
      // ver errores al enlazar
      const GLsizei maxt = 1024L*10L ;
      GLsizei       tam ;
      GLchar        buffer[maxt] ;

      glGetProgramInfoLog( id_prog, maxt, &tam, buffer);
      cout << "error al enlazar:" << endl
           << buffer << flush
           << "programa abortado" << endl << std::flush ;
      exit(1);
   }
   CError();

   // obtener las 'locations' de los parámetros uniform

   loc_mat_modelado      = glGetUniformLocation( id_prog, "u_mat_modelado");
   loc_mat_modelado_nor  = glGetUniformLocation( id_prog, "u_mat_modelado_nor");
   loc_mat_vista         = glGetUniformLocation( id_prog, "u_mat_vista");
   loc_mat_proyeccion    = glGetUniformLocation( id_prog, "u_mat_proyeccion");
   loc_eval_mil          = glGetUniformLocation( id_prog, "u_eval_mil" );
   loc_usar_normales_tri = glGetUniformLocation( id_prog, "u_usar_normales_tri" );
   loc_eval_text         = glGetUniformLocation( id_prog, "u_eval_text" );
   loc_tipo_gct          = glGetUniformLocation( id_prog, "u_tipo_gct" );
   loc_coefs_s           = glGetUniformLocation( id_prog, "u_coefs_s" );
   loc_coefs_t           = glGetUniformLocation( id_prog, "u_coefs_t" );
   loc_mil_ka            = glGetUniformLocation( id_prog, "u_mil_ka");
   loc_mil_kd            = glGetUniformLocation( id_prog, "u_mil_kd");
   loc_mil_ks            = glGetUniformLocation( id_prog, "u_mil_ks");
   loc_mil_exp           = glGetUniformLocation( id_prog, "u_mil_exp");
   loc_num_luces         = glGetUniformLocation( id_prog, "u_num_luces");
   loc_pos_dir_luz_ec    = glGetUniformLocation( id_prog, "u_pos_dir_luz_ec");
   loc_color_luz         = glGetUniformLocation( id_prog, "u_color_luz");

   assert( -1 < loc_mat_modelado );
   assert( -1 < loc_mat_modelado_nor );
   assert( -1 < loc_mat_vista );
   assert( -1 < loc_mat_proyeccion );
   assert( -1 < loc_eval_mil );
   assert( -1 < loc_usar_normales_tri );
   assert( -1 < loc_eval_text );
   assert( -1 < loc_tipo_gct );
   assert( -1 < loc_coefs_s );
   assert( -1 < loc_coefs_t );
   assert( -1 < loc_mil_ka );
   assert( -1 < loc_mil_kd );
   assert( -1 < loc_mil_ks );
   assert( -1 < loc_mil_exp );
   assert( -1 < loc_num_luces );
   assert( -1 < loc_pos_dir_luz_ec );
   assert( -1 < loc_color_luz );

   // dar valores iniciales por defecto a los parámetros uniform
 
   glUseProgram( id_prog );
   CError();

   glUniformMatrix4fv( loc_mat_modelado,     1, GL_FALSE, mat_modelado );
   glUniformMatrix4fv( loc_mat_modelado_nor, 1, GL_FALSE, mat_modelado_nor );
   glUniformMatrix4fv( loc_mat_vista,        1, GL_FALSE, mat_vista );
   glUniformMatrix4fv( loc_mat_proyeccion,   1, GL_FALSE, mat_proyeccion );

   glUniform1ui( loc_eval_mil,          eval_mil );
   glUniform1ui( loc_usar_normales_tri, usar_normales_tri );
   glUniform1ui( loc_eval_text,         eval_text  );
   glUniform1i ( loc_tipo_gct,          tipo_gct );

   glUniform4fv( loc_coefs_s, 1, coefs_s );
   glUniform4fv( loc_coefs_t, 1, coefs_t );

   glUniform1f( loc_mil_ka,  0.2 );
   glUniform1f( loc_mil_kd,  0.8 );
   glUniform1f( loc_mil_ks,  0.0 );
   glUniform1f( loc_mil_exp, 0.0 );

   glUniform1i( loc_num_luces, 0 ); // por defecto: 0 fuentes de luz activas
   glUseProgram( 0 );
   CError();

   /// mostrar uniforms:
   // {
   //    GLint i;
   //    GLint count;

   //    GLint size; // size of the variable
   //    GLenum type; // type of the variable (float, vec3 or mat4, etc)

   //    const GLsizei bufSize = 1024; // maximum name length
   //    GLchar name[bufSize]; // variable name in GLSL
   //    GLsizei length; // name length
      
   //    glGetProgramiv(id_prog, GL_ACTIVE_UNIFORMS, &count);

   //    cout << "Active Uniforms count:" <<  count << endl ;

   //    for (i = 0; i < count; i++)
   //    {
   //       glGetActiveUniform( id_prog, (GLuint)i, bufSize, &length, &size, &type, name);

   //       cout << "Uniform " << i << ": type: " << type << ", name: " << name << endl ;
   //    }
   //    CError();
   // }


   using namespace std ;
   cout << "Shaders compilados y objeto 'Cauce' creado con éxito." << endl ;
}
//----------------------------------------------------------------------

void Cauce::activar()
{
   //log("activo cauce ",descripcion());
   CError();
   assert( 0 < id_prog );
   glUseProgram( id_prog );
   CError();
}

// -----------------------------------------------------------------------------
// devuelve el color actual

Tupla4f Cauce::leerColorActual() const
{
   float c[4];
   CError();
   glGetVertexAttribfv( ind_atrib_colores, GL_CURRENT_VERTEX_ATTRIB, c );
   CError();
   return Tupla4f { c[0], c[1], c[2], c[3] };
}

//----------------------------------------------------------------------
// lee un archivo completo como texto  y devuelve una cadena terminada
// en cero con el contenido
// (el resultado está en el heap y debería borrarse con 'delete [] p')

char * Cauce::leerArchivo( const std::string & nombreArchivo )
{
	using namespace std ;

	ifstream file( nombreArchivo.c_str(), ios::in|ios::binary|ios::ate );

	if ( ! file.is_open())
	{  cout << "imposible abrir archivo para lectura (" << nombreArchivo << ") - termino" << endl << flush ;
		exit(0);
	}
	size_t	numBytes	= file.tellg();
	char *	bytes		= new char [numBytes+2];

	file.seekg (0, ios::beg);
	file.read (bytes, numBytes);
	file.close();

	bytes[numBytes]=0 ;
	bytes[numBytes+1]=0 ;

	return bytes ;
}
//----------------------------------------------------------------------
// crea, carga y compila un shader nuevo
// si hay algún error, aborta
// si todo va bien, devuelve el código de opengl del shader

GLuint Cauce::compilarShader( const std::string & nombreArchivo, GLenum tipoShader )
{
   using namespace std ;
   GLuint idShader ; // resultado: identificador de shader

   CError() ;

   // crear shader nuevo, obtener identificador (tipo GLuint)
   idShader = glCreateShader( tipoShader );

   // leer archivo fuente de shader en memoria, asociar fuente al shader, liberar memoria:
   const GLchar * fuente = leerArchivo( nombreArchivo );
   glShaderSource( idShader, 1, & fuente, nullptr );
   delete [] fuente ;
   fuente = nullptr ;

   // compilar y comprobar errores
   glCompileShader( idShader );
   GLint resultado ;
   glGetShaderiv( idShader, GL_COMPILE_STATUS, &resultado );

   // si hay errores, abortar
   if ( resultado != GL_TRUE )
   {
      const GLsizei maxt = 1024L*10L ;
      GLsizei       tam ;
      GLchar        buffer[maxt] ;

      glGetShaderInfoLog( idShader, maxt, &tam, buffer);
      cout << "error al compilar archivo '" << nombreArchivo << "'" << endl
           << buffer << flush
           << "programa abortado" << endl << std::flush ;
      exit(1);
   }
   CError() ;
	return idShader ;
}

// -----------------------------------------------------------------------------
// fijar el color actual (equiv glColor3f en el antiguo cauce fijo)

void Cauce::fijarColor( const float r, const float g, const float b )
{
   color = { r,g,b } ; // registra color en el objeto cauce
   glVertexAttrib3f( ind_atrib_colores, r, g, b  ); // cambia valor atributo
   CError();
}

// -----------------------------------------------------------------------------
// fijar la matriz de vista y resetear las matrices de modelado y vista,
// (vacía la pila de modelado y de normales, igual que el cauce fijo)

void Cauce::fijarMatrizVista( const Matriz4f & nue_mat_vista )
{
   assert( 0 < id_prog );

   mat_vista     = nue_mat_vista ;
   //mat_vista_inv = MAT_Inversa( mat_vista ) ;

   glUseProgram( id_prog );
   glUniformMatrix4fv( loc_mat_vista, 1, GL_FALSE, mat_vista );
   //glUniformMatrix4fv( loc_mat_vista_inv, 1, GL_FALSE, mat_vista_inv );

   pila_mat_modelado.clear();
   pila_mat_modelado_nor.clear();

   mat_modelado     = MAT_Ident();
   mat_modelado_nor = MAT_Ident();

   actualizarMatricesMN();

   CError();
}
// -----------------------------------------------------------------------------

void Cauce::fijarMatrizProyeccion( const Matriz4f & nue_mat_proyeccion )
{
   assert( 0 < id_prog );
   mat_proyeccion = nue_mat_proyeccion ;
   glUseProgram( id_prog );
   glUniformMatrix4fv( loc_mat_proyeccion, 1, GL_FALSE, mat_proyeccion );
   CError();
}
//-----------------------------------------------------------------------------

void Cauce::fijarEvalText( const bool nue_eval_text, const int nue_text_id  )
{
   CError();
   eval_text = nue_eval_text ;

   if ( eval_text )
   {
      assert( -1 < nue_text_id );
      glActiveTexture( GL_TEXTURE0 ) ; // creo que necesario en el cauce prog., probar
      glBindTexture( GL_TEXTURE_2D, nue_text_id );
      glUniform1ui( loc_eval_text, true );
      CError();
   }
   else
   {
      glUniform1i( loc_eval_text, false );
      CError();
   }
   CError();
}
//-----------------------------------------------------------------------------

void Cauce::fijarTipoGCT( const int nue_tipo_gct,
                           const float * coefs_s, const float * coefs_t )
{
   assert( 0 <= nue_tipo_gct && nue_tipo_gct <= 2 );

   tipo_gct = nue_tipo_gct ;

   if ( tipo_gct != 0 )
   {
      assert( coefs_s != nullptr );
      assert( coefs_t != nullptr );
   }

   glUniform1i( loc_tipo_gct, tipo_gct  ? 1 : 0 );

   if ( tipo_gct == 1 || tipo_gct == 2 )
   {
      glUniform4fv( loc_coefs_s, 1, coefs_s );
      glUniform4fv( loc_coefs_t, 1, coefs_t );
   }
   CError();
}


// -----------------------------------------------------------------------------

void Cauce::fijarEvalMIL( const bool nue_eval_mil  )
{
   eval_mil = nue_eval_mil ; // registra valor en el objeto Cauce.
   glUseProgram( id_prog );  // activa el programa 
   glUniform1ui( loc_eval_mil, eval_mil   ); // cambia parámetro del shader
   CError();
}
// -----------------------------------------------------------------------------

//void Cauce::fijarModoSombrPlano( const bool nue_sombr_plano )
void Cauce::fijarUsarNormalesTri ( const bool nue_usar_normales_tri )
{
   usar_normales_tri = nue_usar_normales_tri ;
   glUseProgram( id_prog );
   glUniform1ui( loc_usar_normales_tri, usar_normales_tri );
   CError();
}

// -----------------------------------------------------------------------------

void Cauce::fijarParamsMIL( const float k_amb, const float k_dif,
                            const float k_pse, const float exp_pse )  
{
   assert( -1 < loc_mil_ka );
   assert( -1 < loc_mil_kd );
   assert( -1 < loc_mil_ks );
   assert( -1 < loc_mil_exp );

   glUseProgram( id_prog );
   glUniform1f( loc_mil_ka,   k_amb );
   glUniform1f( loc_mil_kd,   k_dif );
   glUniform1f( loc_mil_ks,   k_pse );
   glUniform1f( loc_mil_exp,  exp_pse );

   CError();
}

// -----------------------------------------------------------------------------

void Cauce::fijarFuentesLuz( const std::vector<Tupla3f> & color,
                                        const std::vector<Tupla4f> & pos_dir_wc  )
{
   const unsigned nl = color.size();
   assert( 0 < nl && nl <= maxNumFuentesLuz() );
   assert( nl == pos_dir_wc.size() );

   assert( 0 < id_prog );
   glUseProgram( id_prog );

   std::vector<Tupla4f> pos_dir_ec ;

   for( unsigned i = 0 ; i < nl ; i++ )
      pos_dir_ec.push_back( mat_vista * pos_dir_wc[i ]);

   glUniform1i( loc_num_luces, nl );
   glUniform3fv( loc_color_luz, nl, (const float *)color.data() );
   glUniform4fv( loc_pos_dir_luz_ec, nl, (const float *)pos_dir_ec.data() );
}
// -----------------------------------------------------------------------------
// inserta copia de la matriz de modelado actual (en el tope de la pila)

void Cauce::pushMM()
{
   //log("entra-sale");
   pila_mat_modelado.push_back( mat_modelado );
   pila_mat_modelado_nor.push_back( mat_modelado_nor );
}

// -----------------------------------------------------------------------------
// extrae tope de la pila y sustituye la matriz de modelado actual

void Cauce::popMM()
{
   //log("entra");
   CError();
   const unsigned n = pila_mat_modelado.size() ;
   assert( 0 < n );
   assert( n == pila_mat_modelado_nor.size() );

   mat_modelado     = pila_mat_modelado[n-1] ;
   mat_modelado_nor = pila_mat_modelado_nor[n-1] ;

   pila_mat_modelado.pop_back();
   pila_mat_modelado_nor.pop_back();


   actualizarMatricesMN();
   //log("sale");
}
// -----------------------------------------------------------------------------
// compone matriz de modelado actual con la matriz dada.

void Cauce::compMM( const Matriz4f & mat_componer )
{
   //log("entra");
   CError();
   const Matriz4f mat_componer_nor = MAT_Transpuesta3x3( MAT_Inversa( mat_componer ) );

   mat_modelado     = mat_modelado * mat_componer ;
   mat_modelado_nor = mat_modelado_nor * mat_componer_nor ;

   CError();
   actualizarMatricesMN();
   CError();
   //log("sale");
}
// -----------------------------------------------------------------------------

void Cauce::actualizarMatricesMN()
{
   //log("entra");
   assert( 0 < id_prog );
   assert( -1 < loc_mat_modelado );
   assert( -1 < loc_mat_modelado_nor );

   CError();
   glUseProgram( id_prog );
   glUniformMatrix4fv( loc_mat_modelado,     1, GL_FALSE, mat_modelado );
   glUniformMatrix4fv( loc_mat_modelado_nor, 1, GL_FALSE, mat_modelado_nor );
   CError();
   //log("sale");
}
// -----------------------------------------------------------------------------
// lee el nombre o descripción del cauce

std::string Cauce::descripcion()
{
   return "programable (OpenGL 'moderno')" ;
}
