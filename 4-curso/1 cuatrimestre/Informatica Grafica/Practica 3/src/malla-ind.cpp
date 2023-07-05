// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

// *********************************************************************
// **
// ** Informática Gráfica, curso 2020-21
// ** Declaraciones de la clase Objeto3D.hpp
// **
// *********************************************************************

#include "ig-aux.h"
#include "malla-ind.h"   // declaración de 'ContextoVis'
#include "lector-ply.h"

// *****************************************************************************
// funciones auxiliares

// *****************************************************************************
// métodos de la clase MallaInd.

MallaInd::MallaInd()
{
   // nombre por defecto
   ponerNombre("malla indexada, anónima");
}
// -----------------------------------------------------------------------------

MallaInd::MallaInd( const std::string & nombreIni )
{
   // 'identificador' puesto a 0 por defecto, 'centro_oc' puesto a (0,0,0)
   ponerNombre(nombreIni) ;
}

//-----------------------------------------------------------------------------
// calcula la tabla de normales de triángulos una sola vez, si no estaba calculada

void MallaInd::calcularNormalesTriangulos()
{

   // si ya está creada la tabla de normales de triángulos, no es necesario volver a crearla
   const unsigned nt = triangulos.size() ;
   assert( 1 <= nt );
   if ( 0 < nor_tri.size() )
   {
      assert( nt == nor_tri.size() );
      return ;
   }

   // COMPLETAR: Práctica 4: creación de la tabla de normales de triángulos
   // ....

}


// -----------------------------------------------------------------------------
// calcula las dos tablas de normales

void MallaInd::calcularNormales()
{
   // COMPLETAR: en la práctica 4: calculo de las normales de la malla
   // se debe invocar en primer lugar 'calcularNormalesTriangulos'
   // .......


}



// --------------------------------------------------------------------------------------------

void MallaInd::visualizarGL( ContextoVis & cv )
{


   using namespace std ;
   assert( cv.cauce != nullptr );
   CError();

   if ( triangulos.size() == 0 || vertices.size() == 0 )
   {  cout << "advertencia: intentando dibujar malla vacía '" << leerNombre() << "'" << endl << flush ;
      return ;
   }

   // guardar el color previamente fijado y fijar el color del objeto actual
   const Tupla4f color_previo = leerFijarColVertsCauce( cv );

   // COMPLETAR: práctica 1: si el nombre del VAO es 0, crear el VAO con sus VBOs:
   //   * en primer lugar se crea y activa el VAO , con 'CrearVAO'.
   //   * después se añade el VBO con la tabla de coordenadas de posición, 'CrearVBOAtrib'.
   //   * se añade el VBO con la tabla de índices (la tabla de triángulos), con 'CrearVBOInd'.
   //   * finalmente se añaden al VAO los VBOs con tablas de atributos (opcionaes) que haya, con 'CrearVBOAtrib'.
   // si el VAO ya está creado, (nombre_vao > 0), activarlo, con 'glBindVertexArray'
   //
   //  hay que tener en cuenta que el nombre del VAO y los nombres de losVBOs deben quedar en las correspondientes 
   //  variables de instancia. Estos nombres son los devueltos por las 
   //  funciones 'CrearVAO', 'CrearVBOAtrib' y 'CrearVBOInd'.
   //

   // COMPLETAR: práctica 1: visualizar con 'glDrawElements' y desactivar VAO.
    
   if( nombre_vao == 0){

      nombre_vao = CrearVAO();

      if (vertices.size() >0) {
         nombre_vbo_pos = CrearVBOAtrib( ind_atrib_posiciones, vertices);
      }
      

      if (triangulos.size() >0) {
         nombre_vbo_tri = CrearVBOInd( triangulos );
      }
      if (col_ver.size() >0){
         nombre_vbo_col = CrearVBOAtrib( ind_atrib_colores, col_ver );
      } 
      if (nor_ver.size() >0){
         nombre_vbo_nor = CrearVBOAtrib( ind_atrib_normales, nor_ver );
      } 
      if (cc_tt_ver.size()>0){
         nombre_vbo_cct = CrearVBOAtrib( ind_atrib_coord_text, cc_tt_ver);
      } 
      
      
   }
   else{
      glBindVertexArray( nombre_vao );  // VAO ya creado, simplemente se activa
   }
        
   assert( glGetError() == GL_NO_ERROR );

   // Si es una secuencia indexada
   glDrawElements( GL_TRIANGLES, triangulos.size()*3, GL_UNSIGNED_INT, 0 );

   glBindVertexArray( 0 );

   // restaurar el color previamente fijado
   cv.cauce->fijarColor( color_previo );
}


// -----------------------------------------------------------------------------
// visualizar pura y simplemente la geometría, sin colores, normales, coord. text. etc...
// (se supone que el estado de OpenGL está fijado antes de esta llamada de alguna forma adecuada)

void MallaInd::visualizarGeomGL( ContextoVis & cv )
{

   // COMPLETAR: práctica 1: visualizar con 'glDrawElements' y desactivar VAO.
    
   if( nombre_vao_geo == 0){

      nombre_vao_geo = CrearVAO();
      
      glBindBuffer(GL_ARRAY_BUFFER, nombre_vbo_pos);
      

      glVertexAttribPointer(ind_atrib_posiciones, 3, GL_FLOAT, GL_FALSE, 0, 0);

      glEnableVertexAttribArray(ind_atrib_posiciones);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, nombre_vbo_tri);
      
      CError();
   }
   else{
      glBindVertexArray( nombre_vao_geo );  // VAO ya creado, simplemente se activa
   }
        
   assert( glGetError() == GL_NO_ERROR );

   glDrawElements( GL_TRIANGLES, triangulos.size()*3, GL_UNSIGNED_INT, 0 );

   glBindVertexArray( 0 ); // Desactivamos el VAO



}


// ****************************************************************************
// Clase 'MallaPLY'

MallaPLY::MallaPLY( const std::string & nombre_arch )
{
   ponerNombre( std::string("malla leída del archivo '") + nombre_arch + "'" );

   // COMPLETAR: práctica 2: leer archivo PLY e inicializar la malla
   // ..........................

   LeerPLY(nombre_arch, vertices, triangulos);
   // COMPLETAR: práctica 4: invocar  a 'calcularNormales' para el cálculo de normales
   // .................

}

// ****************************************************************************
// Clase 'Cubo

Cubo::Cubo(float a, float b, float c)
:  MallaInd( "cubo 8 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         {2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;

   ponerColor({a,b,c});
}


Tetraedro::Tetraedro()
:  MallaInd( "Tetraedro 4 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 1
         { -1.0, -1.0, +1.0 }, // 2
         { -1.0, +1.0, -1.0 }, // 3
      } ;



   triangulos =
      {  {0,1,3}, {0,1,2}, {0,2,3}, {1,2,3}
      
      } ;

      ponerColor({0.0,0.0,0.0});

}

// ****************************************************************************
// Clase 'CuboTejado'

CuboTejado::CuboTejado()
:  MallaInd( "cubo 8 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
         { +0.0, +2.0, +0.0 }, // 8
      } ;

   for( Tupla3f & v : vertices )
      v = 2.0f*v +Tupla3f({0.0,2.0,0.0});



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         //{2,3,7}, {2,7,6}, // Y+ (+2)   // quito cara superior
         {2,3,8}, {3,7,8}, {7,6,8}, {6,2,8}, // añado tejado 

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;

}
// -----------------------------------------------------------------------------------------------

CuboColores::CuboColores()
:  MallaInd( "cubo 8 vértices" )
{

   vertices =
      {  { -1.0, -1.0, -1.0 }, // 0
         { -1.0, -1.0, +1.0 }, // 1
         { -1.0, +1.0, -1.0 }, // 2
         { -1.0, +1.0, +1.0 }, // 3
         { +1.0, -1.0, -1.0 }, // 4
         { +1.0, -1.0, +1.0 }, // 5
         { +1.0, +1.0, -1.0 }, // 6
         { +1.0, +1.0, +1.0 }, // 7
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X-
         {4,7,5}, {4,6,7}, // X+ (+4)

         {0,5,1}, {0,4,5}, // Y-
         {2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3}  // Z+ (+1)
      } ;
   
   col_ver =
      {  { 0.0, 0.0, 0.0 }, // 0
         { 0.0, 0.0, 1.0 }, // 1
         { 0.0, 1.0, 0.0 }, // 2
         { 0.0, 1.0, 1.0 }, // 3
         { 1.0, 0.0, 0.0 }, // 4
         { 1.0, 0.0, 1.0 }, // 5
         { 1.0, 1.0, 0.0 }, // 6
         { 1.0, 1.0, 1.0 }, // 7
      } ;
}

// Ejercicio Adicional 1 

EstrellaZ::EstrellaZ(unsigned n)
:  MallaInd( "Estrella Z" )
{

   // Vertice central   
   vertices.push_back({0.5, 0.5, 0});
   col_ver.push_back({1.0, 1.0, 1.0});

   // Vertice picos
   float X_picos;
   float Y_picos;

   // Vertice aristas
   float x_aristas;
   float y_aristas;

   // Angulos
   float angulo_incr = 360/n;
   float angulo = 360/n;

   float angulo_base = (360/n)/2;

   for(int i=0; i<n; i++){

      X_picos = 0.5 + 0.5*cos( angulo*3.14/180 );
      Y_picos = 0.5 + 0.5*sin( angulo*3.14/180 );

      vertices.push_back({X_picos, Y_picos, 0.0});
      col_ver.push_back({X_picos, Y_picos, 0.0});

      x_aristas = 0.5 + 0.25*cos( angulo_base*3.14/180 );
      y_aristas = 0.5 + 0.25*sin( angulo_base*3.14/180 );

      vertices.push_back({x_aristas, y_aristas, 0.0});
      col_ver.push_back({x_aristas, y_aristas, 0.0});

      angulo += angulo_incr;
      angulo_base += angulo_incr;

      //std::cout << "Pico "<< i << ": (X="<< X <<", Y="<< Y <<")." << std::endl;

   }

   // Creamos las uniones
   
   unsigned int aux_1 = 1;
   unsigned int aux_2 = 2;

   for(int i=0; i<2*n; i++){

         triangulos.push_back({0, aux_1, aux_2});

         if(i%2==0){
            aux_2+=2;
         }

         else {
            aux_1+=2;
         }

         if(aux_2 > 2*n){
            aux_2 = 2;
         }
      }

      
   
}


// Ejercicio Adicional 2

CuboX::CuboX()
:  MallaInd( "Cubo X" )
{

   vertices =
      {  { 0.0, 0.0, 0 }, // 0
         { 0.0, 0.0, +0.5 }, // 1

         { 0.0, +0.5, 0 }, // 2
         { 0.0, +0.5, +0.5 }, // 3

         { +1.0, 0.0, 0 }, // 4
         { +1.0, 0.0, +0.5 }, // 5

         { +1.0, +0.5, 0 }, // 6
         { +1.0, +0.5, +0.5 }, // 7

         { 0.5, +1.0, 0}, // 8
         { 0.5, +1.0, +0.5}, // 9
      } ;



   triangulos =
      {  {0,1,3}, {0,3,2}, // X- Laterales
         {4,7,5}, {4,6,7}, // X+ (+4)

         //{0,5,1}, {0,4,5}, // Y-
         //{2,3,7}, {2,7,6}, // Y+ (+2)

         {0,6,4}, {0,2,6}, // Z-
         {1,5,7}, {1,7,3},  // Z+ (+1)

         {2,3,8}, {2,6,8}, {3,8,9},
         {3,7,9}, {6,7,9}, {6,8,9}
         
         

      } ;

   col_ver =
      {  { -1.0, -1.0, -0.5 }, // 0
         { -1.0, -1.0, +0.5 }, // 1

         { -1.0, +1.0, -0.5 }, // 2
         { -1.0, +1.0, +0.5 }, // 3

         { +1.0, -1.0, -0.5 }, // 4
         { +1.0, -1.0, +0.5 }, // 5

         { +1.0, +1.0, -0.5 }, // 6
         { +1.0, +1.0, +0.5 }, // 7

         { 0.0, +2.0, -0.5}, // 8
         { 0.0, +2.0, +0.5}, // 9
      } ;

}

// Ejercicio adicional 3

MallaTriangulo::MallaTriangulo()
:  MallaInd( "Malla triangulo" )
{

   vertices =
      {  
         { -0.5, 0.0, 0.0}, // 0
         { +0.5, 0.0, 0.0 }, // 1
         { 0.0, sqrt(2.0), 0.0 }, // 2
      } ;

   triangulos =
      {  {0,1,2}
      
      } ;

}

MallaCuadrado::MallaCuadrado()
:  MallaInd( "Malla cuadrado" )
{

   vertices =
      {  
         { -1.0, 0.0, 0.0}, // 0
         { 1.0, 0.0, 0.0}, // 1
         { -1.0, 2.0, 0.0 }, // 2
         { 1.0, 2.0, 0.0 }, // 3
      } ;

   triangulos =
      {  {0,1,2}, {1,2,3}

      } ;

}

MallaPiramideL::MallaPiramideL()
:  MallaInd( "Malla piramide" )
{

   vertices =
      {  
         { 0.0, 0.0, 0.0}, // 0
         { 0.0, 0.0, -1.0}, // 1
         { 1.0, 0.0, -1.0}, // 2
         { 1.0, 0.0, 1.0 }, // 3
         { -1.0, 0.0, 1.0 }, // 4
         { -1.0, 0.0, 0.0}, // 5
         { 0.0, 2.0, 0.0} // 6
      } ;

   triangulos =
      {  {0,1,2}, {0,4,5}, {0,2,3}, {0,3,4},
         {6,0,1}, {6,1,2}, {6,2,3}, {6,3,4},
         {6,4,5}, {6,5,0}

      } ;

}

//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------

// Practica 2 - Adicionales -


PiramideEstrellaZ::PiramideEstrellaZ(unsigned n)
:  MallaInd( "Piramide Estrella Z" )
{

   // Vertice central   
   

   vertices.push_back({0.5, 0.5, 0});
   col_ver.push_back({1.0, 1.0, 1.0});

   // Vertice picos
   float X_picos;
   float Y_picos;

   // Vertice aristas
   float x_aristas;
   float y_aristas;

   // Angulos
   float angulo_incr = 360/n;
   float angulo = 360/n;

   float angulo_base = (360/n)/2;

   for(int i=0; i<n; i++){

      X_picos = 0.5 + 0.5*cos( angulo*3.14/180 );
      Y_picos = 0.5 + 0.5*sin( angulo*3.14/180 );

      vertices.push_back({X_picos, Y_picos, 0.0});
      col_ver.push_back({X_picos, Y_picos, 0.0});

      x_aristas = 0.5 + 0.25*cos( angulo_base*3.14/180 );
      y_aristas = 0.5 + 0.25*sin( angulo_base*3.14/180 );

      vertices.push_back({x_aristas, y_aristas, 0.0});
      col_ver.push_back({x_aristas, y_aristas, 0.0});

      angulo += angulo_incr;
      angulo_base += angulo_incr;

      //std::cout << "Pico "<< i << ": (X="<< X <<", Y="<< Y <<")." << std::endl;

   }

   // Creamos las uniones
   
   unsigned int aux_1 = 1;
   unsigned int aux_2 = 2;

   vertices.push_back({0.5, 0.5, 0.5});
   col_ver.push_back({1.0, 1.0, 1.0});

   for(int i=0; i<2*n+2; i++){

         triangulos.push_back({0, aux_1, aux_2});

         if(i<2*n+1){
            triangulos.push_back({vertices.size()-1, aux_1, aux_2});
         }
         

         if(i%2==0){
            aux_2+=2;
         }

         else {
            aux_1+=2;
         }

         if(aux_2 > 2*n){
            aux_2 = 2;
         }
      }
   
}

//----------------------------- Adicional 2 -------------------//

RejillaY::RejillaY(unsigned n, unsigned m)
:  MallaInd( "Rejilla Y" )
{

   float x_incr = 1.0/(n-1);
   float z_incr = 1.0/(m-1);

   for(float i=0; i<=1; i+=x_incr){

      for(float j=0; j<=1; j+=z_incr){
         
         std::cout << "Inserto el punto " << i << ","<<j << std::endl;
         vertices.push_back({i,0,j});
         col_ver.push_back({i,0,j});
      }
   }

   int aux = 0;

   for(unsigned i = 0; i<n-1; i++){

      for(unsigned j=0; j<m-1; j++){
         triangulos.push_back({aux,aux+m,aux+1});
         triangulos.push_back({aux+1,aux+1+m,aux+m});
         aux++;
      }
      aux++;
   }

}

//----------------------------- Adicional 3 -------------------//

MallaTorre::MallaTorre(unsigned n)
:  MallaInd( "Malla Torre " )
{

   vertices.clear();
   std::cout << std::endl << "Creacion de Torre: " << std::endl;

   int contador = 0;
   for(int i=0; i<n; i+=2){

      std::cout<<"La altura es: " << i*1 << std::endl;

      vertices.push_back({0.5, i*1, 0.5});
      vertices.push_back({0.5, i*1, -0.5});
      vertices.push_back({-0.5, i*1, -0.5});
      vertices.push_back({-0.5, i*1, 0.5});
      

      vertices.push_back({0.5, (i*1)+1, 0.5});
      vertices.push_back({0.5, (i*1)+1, -0.5});
      vertices.push_back({-0.5, (i*1)+1, -0.5});
      vertices.push_back({-0.5, (i*1)+1, 0.5});
      
      
      std::cout << "Inserto el punto (" << 0.5 << ","<<(i*1)+1 << "," << -0.5 << ")" << std::endl;
      std::cout << "Inserto el punto (" << 0.5 << ","<<(i*1) << "," << -0.5 << ")" << std::endl;
      contador++;
   }
   
   int numero = 0;

   for(int i=0; i<n; i++){
      
      triangulos.push_back({numero,numero+3, numero+4});
      std::cout << "Meto el triangulo ("<<numero<<","<<numero+3<<","<<numero+4<<")."<< std::endl;
      for(int j=0; j<3; j++){
         
         std::cout << "Meto el triangulo ("<<numero<<","<<numero+1<<","<<numero+5<<")."<< std::endl;
         std::cout << "Meto el triangulo ("<<numero<<","<<numero+4<<","<<numero+5<<")."<< std::endl;

         triangulos.push_back({numero,numero+1, numero+5});
         triangulos.push_back({numero,numero+4, numero+5});

         numero++;
      }
      
      std::cout << "El numero que falta es: " << numero << std::endl;
      std::cout << "Meto el triangulo ("<<numero<<","<<numero+1<<","<<numero+4<<")."<< std::endl;

      triangulos.push_back({numero,numero+1, numero+4});
      numero++;

      std::cout << "Termino piso " << i << std::endl;
      
   }
}