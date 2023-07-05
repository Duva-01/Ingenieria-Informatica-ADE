// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

// *********************************************************************
// **
// ** Gestión de una grafo de escena (implementación)
// ** Copyright (C) 2016 Carlos Ureña
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
#include "grafo-escena.h"
#include "malla-ind.h"
#include "malla-revol.h"

using namespace std ;

// *********************************************************************
// Entrada del nodo del Grafo de Escena

// ---------------------------------------------------------------------
// Constructor para entrada de tipo sub-objeto

EntradaNGE::EntradaNGE( Objeto3D * pObjeto )
{
   assert( pObjeto != NULL );
   tipo   = TipoEntNGE::objeto ;
   objeto = pObjeto ;
}
// ---------------------------------------------------------------------
// Constructor para entrada de tipo "matriz de transformación"

EntradaNGE::EntradaNGE( const Matriz4f & pMatriz )
{
   tipo    = TipoEntNGE::transformacion ;
   matriz  = new Matriz4f() ; // matriz en el heap, puntero propietario
   *matriz = pMatriz ;
}

// ---------------------------------------------------------------------
// Constructor para entrada de tipo "matriz de transformación"

EntradaNGE::EntradaNGE( Material * pMaterial )
{
   assert( pMaterial != NULL );
   tipo     = TipoEntNGE::material ;
   material = pMaterial ;
}

// -----------------------------------------------------------------------------
// Destructor de una entrada

EntradaNGE::~EntradaNGE()
{
   /**  no fnciona debido a que se hacen copias (duplicados) de punteros
   if ( tipo == TipoEntNGE::transformacion )
   {
      assert( matriz != NULL );
      delete matriz ;
      matriz = NULL ;
   }
   * **/
}

// *****************************************************************************
// Nodo del grafo de escena: contiene una lista de entradas
// *****************************************************************************

// -----------------------------------------------------------------------------
// Visualiza usando OpenGL

void NodoGrafoEscena::visualizarGL( ContextoVis & cv )
{
   // COMPLETAR: práctica 3: recorrer las entradas y visualizar cada nodo.
   
   // guarda modelview actual
   cv.cauce->pushMM();
   const Tupla4f color_previo = leerFijarColVertsCauce(cv);

   for( unsigned i = 0 ; i < entradas.size() ; i++ ){

      switch( entradas[i].tipo ){ 

         case TipoEntNGE::objeto : // entrada objeto:
            entradas[i].objeto->visualizarGL( cv ); // visualizar objeto
         break ;
         case TipoEntNGE::transformacion : // entrada transf.:
            cv.cauce->compMM( *(entradas[i].matriz)); // componer matriz
         break ;

         case TipoEntNGE::material :

         break;

         case TipoEntNGE::noInicializado :

         break;
      }

   }

   // restaura modelview guardada
   cv.cauce->fijarColor( color_previo );
   cv.cauce->popMM() ;

   // COMPLETAR: práctica 4: en la práctica 4, si 'cv.iluminacion' es 'true',
   // se deben de gestionar los materiales:
   //   1. guardar puntero al material activo al inicio (está en cv.material_act)
   //   2. si una entrada des de tipo material, activarlo y actualizar 'cv.material_act'
   //   3. al finalizar, restaurar el material activo al inicio (si es distinto del actual)
}


// *****************************************************************************
// visualizar pura y simplemente la geometría, sin colores, normales, coord. text. etc...

void NodoGrafoEscena::visualizarGeomGL( ContextoVis & cv )
{
   // comprobar que hay un cauce en 'cv' 
   assert( cv.cauce != nullptr );
  

   // COMPLETAR: práctica 3
   //
   // Este método hace un recorrido de las entradas del nodo, parecido a 'visualizarGL', teniendo 
   // en cuenta estos puntos:
   //
   // - usar push/pop de la matriz de modelado al inicio/fin (al igual que en visualizatGL)
   // - recorrer las entradas, llamando recursivamente a 'visualizarGeomGL' en los nodos u objetos hijos
   // - ignorar el color o identificador del nodo (se supone que el color ya está prefijado antes de la llamada)
   // - ignorar las entradas de tipo material, y la gestión de materiales (se usa sin iluminación)

   // guarda modelview actual
   cv.cauce->pushMM();

   for( unsigned i = 0 ; i < entradas.size() ; i++ ){

      switch( entradas[i].tipo ){ 

         case TipoEntNGE::objeto : // entrada objeto:
            entradas[i].objeto->visualizarGeomGL( cv ); // visualizar objeto
         break ;
         case TipoEntNGE::transformacion : // entrada transf.:
            cv.cauce->compMM( *(entradas[i].matriz)); // componer matriz
         break ;

         case TipoEntNGE::material :

         break;

         case TipoEntNGE::noInicializado :

         break;
      }

   }

   // restaura modelview guardada
   cv.cauce->popMM() ;

}

// -----------------------------------------------------------------------------

NodoGrafoEscena::NodoGrafoEscena()
{

}

// -----------------------------------------------------------------------------
// Añadir una entrada (al final).
// genérica (de cualqiuer tipo de entrada)

unsigned NodoGrafoEscena::agregar( const EntradaNGE & entrada )
{
   // COMPLETAR: práctica 3: agregar la entrada al nodo, devolver índice de la entrada agregada
   // ........
   entradas.push_back(entrada);
   return entradas.size()-1; // sustituir por lo que corresponda ....

}
// -----------------------------------------------------------------------------
// construir una entrada y añadirla (al final)
// objeto (copia solo puntero)

unsigned NodoGrafoEscena::agregar( Objeto3D * pObjeto )
{
   return agregar( EntradaNGE( pObjeto ) );
}
// ---------------------------------------------------------------------
// construir una entrada y añadirla (al final)
// matriz (copia objeto)

unsigned NodoGrafoEscena::agregar( const Matriz4f & pMatriz )
{
   return agregar( EntradaNGE( pMatriz ) );
}
// ---------------------------------------------------------------------
// material (copia solo puntero)
unsigned NodoGrafoEscena::agregar( Material * pMaterial )
{
   return agregar( EntradaNGE( pMaterial ) );
}

// devuelve el puntero a la matriz en la i-ésima entrada
Matriz4f * NodoGrafoEscena::leerPtrMatriz( unsigned indice )
{
   // COMPLETAR: práctica 3: devolver puntero la matriz en ese índice
   //   (debe de dar error y abortar si no hay una matriz en esa entrada)
   // ........(sustituir 'return nullptr' por lo que corresponda)
   assert( indice < entradas.size() );
   assert( entradas[indice].tipo == TipoEntNGE::transformacion );
   assert( entradas[indice].matriz != nullptr );

   return entradas[indice].matriz ;
}
// -----------------------------------------------------------------------------
// si 'centro_calculado' es 'false', recalcula el centro usando los centros
// de los hijos (el punto medio de la caja englobante de los centros de hijos)

void NodoGrafoEscena::calcularCentroOC()
{

   // COMPLETAR: práctica 5: calcular y guardar el centro del nodo
   //    en coordenadas de objeto (hay que hacerlo recursivamente)
   //   (si el centro ya ha sido calculado, no volver a hacerlo)
   // ........

}
// -----------------------------------------------------------------------------
// método para buscar un objeto con un identificador y devolver un puntero al mismo

bool NodoGrafoEscena::buscarObjeto
(
   const int         ident_busc, // identificador a buscar
   const Matriz4f &  mmodelado,  // matriz de modelado
   Objeto3D       ** objeto,     // (salida) puntero al puntero al objeto
   Tupla3f &         centro_wc   // (salida) centro del objeto en coordenadas del mundo
)
{
   assert( 0 < ident_busc );

   // COMPLETAR: práctica 5: buscar un sub-objeto con un identificador
   // Se deben de dar estos pasos:

   // 1. calcula el centro del objeto, (solo la primera vez)
   // ........


   // 2. si el identificador del nodo es el que se busca, ya está (terminar)
   // ........


   // 3. El nodo no es el buscado: buscar recursivamente en los hijos
   //    (si alguna llamada para un sub-árbol lo encuentra, terminar y devolver 'true')
   // ........


   // ni este nodo ni ningún hijo es el buscado: terminar
   return false ;
}

// Ejercicios adicionales Practica 3

ConoUbicado::ConoUbicado(unsigned n, float X, float Y, float Z, float angulo_rotacion, float escalado_X, float escalado_Y, float escalado_Z){

   agregar(MAT_Traslacion({X, Y, Z}));
   agregar(MAT_Rotacion(angulo_rotacion-90, {0.0, 0.0, 1.0}));
   agregar(MAT_Escalado(escalado_X, escalado_Y, escalado_Z));
   agregar(new Cono(3, 15));

}

ConosEstrella::ConosEstrella(unsigned n){

   float X_picos, Y_picos;

   float angulo_incr = 360/n;
   float angulo = 360/n;

   for(int i=0; i<n; i++){

      X_picos = 1.3*cos( angulo*M_PI/180 );
      Y_picos = 1.3*sin( angulo*M_PI/180 );

      std::cout << "Agrego el cono en la posicion: " << X_picos << ", " << Y_picos << " con un angulo de " << angulo << std::endl;
      agregar(new ConoUbicado(n, X_picos, Y_picos, 0.0, angulo, 0.07, 0.15, 0.07));
      angulo += angulo_incr;
   }

}

GrafoEstrellaX::GrafoEstrellaX(unsigned n){

   int indice = agregar(MAT_Rotacion((0.0), {1.0, 0.0, 0.0}));

   agregar(MAT_Rotacion((90.0), {0.0, 1.0, 0.0}));
   agregar(new ConosEstrella(n));

   agregar(MAT_Escalado(2.6, 2.6, 2.6));
   agregar( MAT_Traslacion( {-0.5,-0.5,0.0} ) );

   
   agregar( new EstrellaZ(n) );

   rotacion = leerPtrMatriz(indice);
}

unsigned GrafoEstrellaX::leerNumParametros() const{
    
   return 1;
}

// Redefinimos metodo actualizarEstadoParametro()
void GrafoEstrellaX::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         *rotacion = MAT_Rotacion((360*2.5 * tSec), {1.0, 0.0, 0.0});
      break;
   
   default:
         *rotacion = MAT_Rotacion((360*2.5 * tSec), {1.0, 0.0, 0.0});
      break;
   }

}

// Ejercicio 2 

RejillaUbicada::RejillaUbicada(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z){

   agregar(MAT_Traslacion({X, Y, Z}));
   agregar(MAT_Rotacion(angulo_rotacion, {rot_X, rot_Y, rot_Z}));
   agregar(new RejillaY(10,10));
}

CuboRejilla::CuboRejilla() {
   
   agregar( new RejillaUbicada(-0.5, -0.5, -0.5, 90, 0.0, 0.0, 1.0)); // Eje Z
   agregar( new RejillaUbicada(0.5, -0.5, -0.5, 90, 0.0, 0.0, 1.0)); // Eje Z

   agregar( new RejillaUbicada(-0.5, 0.5, -0.5, 0, 0.0, 1.0, 0.0)); // Eje Y
   agregar( new RejillaUbicada(-0.5, -0.5, -0.5, 0, 0.0, 1.0, 0.0)); // Eje Y

   agregar( new RejillaUbicada(-0.5, 0.5, -0.5, 90, 1.0, 0.0, 0.0)); // Eje X
   agregar( new RejillaUbicada(-0.5, 0.5, 0.5, 90, 1.0, 0.0, 0.0)); // Eje X

}

//----------------------

CuboUbicado::CuboUbicado(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z) {
   
   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));
   
   agregar(MAT_Traslacion({X, Y, Z}));
   agregar(MAT_Rotacion(angulo_rotacion, {rot_X, rot_Y, rot_Z}));
   agregar(MAT_Escalado(escalado_X, escalado_Y, escalado_Z));

   if(X != 0.0){
      eje = 0;
   }
   else if(Y != 0.0) {
      eje = 1;
   }
   else {
      eje = 2;
   }

   agregar(new Cubo(1.0, 1.0, 1.0));

   rotacion = leerPtrMatriz(indice);
   
}


unsigned CuboUbicado::leerNumParametros() const{
    
   return 1;
}

void CuboUbicado::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         switch (eje)
         {
         case 0:
            * rotacion = MAT_Rotacion((100*tSec), {1.0, 0.0, 0.0});
            break;
         
         case 1:
            * rotacion = MAT_Rotacion((100*tSec), {0.0, 1.0, 0.0});
            break;

         case 2:
            * rotacion = MAT_Rotacion((100*tSec), {0.0, 0.0, 1.0});
            break;

         default:
            break;
         }
      break;
   
   default:
      break;
   }

}

//-------------------------------------------

MiniCubosRejilla::MiniCubosRejilla(){

   //int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));

   c1 =  new CuboUbicado(0.0, 0.75, 0.0, 0, 0.0, 0.0, 1.0, 0.1, 0.25, 0.1);
   c2 = new CuboUbicado(0.0, -0.75, 0.0, 0, 0.0, 0.0, 1.0, 0.1, 0.25, 0.1);
   agregar(c1); // Eje Y
   agregar( c2); // Eje Y

   c3 = new CuboUbicado(-0.75, 0.0, 0.0, 90, 0.0, 0.0, 1.0, 0.1, 0.25, 0.1);
   c4 = new CuboUbicado(0.75, 0.0, 0.0, 90, 0.0, 0.0, 1.0, 0.1, 0.25, 0.1);
   agregar( c3); // Eje X
   agregar( c4); // Eje X

   c5 = new CuboUbicado(0.0, 0.0, -0.75, 90, 1.0, 0.0, 0.0, 0.1, 0.25, 0.1);
   c6 =  new CuboUbicado(0.0, 0.0, 0.75, 90, 1.0, 0.0, 0.0, 0.1, 0.25, 0.1);
   agregar(c5 ); // Eje Z
   agregar(c6); // Eje Z
   
}

unsigned MiniCubosRejilla::leerNumParametros() const{
    
   return 1;
}

void MiniCubosRejilla::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         c1->actualizarEstadoParametro(iParam, tSec);
         c2->actualizarEstadoParametro(iParam, tSec);
         c3->actualizarEstadoParametro(iParam, tSec);
         c4->actualizarEstadoParametro(iParam, tSec);
         c5->actualizarEstadoParametro(iParam, tSec);
         c6->actualizarEstadoParametro(iParam, tSec);
      break;
   
   default:
         c1->actualizarEstadoParametro(iParam, tSec);
         c2->actualizarEstadoParametro(iParam, tSec);
         c3->actualizarEstadoParametro(iParam, tSec);
         c4->actualizarEstadoParametro(iParam, tSec);
         c5->actualizarEstadoParametro(iParam, tSec);
         c6->actualizarEstadoParametro(iParam, tSec);
      break;
   }

}

//---------------------



//-----------------------

GrafoCubos::GrafoCubos(){
   
   agregar(new CuboRejilla() );

   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));
   cubillos = new MiniCubosRejilla();
   agregar(cubillos);

   rotacion = leerPtrMatriz(indice);
}

unsigned GrafoCubos::leerNumParametros() const{
    
   return 1;
}

void GrafoCubos::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         cubillos->actualizarEstadoParametro(iParam, tSec);
      break;
   
   default:
         cubillos->actualizarEstadoParametro(iParam, tSec);
      break;
   }

}

// Ejercicios para practicar 

// Examen Sombrilla

Sombrilla::Sombrilla(){

   soporte = new Soporte(5);
   agregar (soporte);
   

}

unsigned Sombrilla::leerNumParametros() const{
    
   return 1;
}

void Sombrilla::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         soporte->actualizarEstadoParametro(iParam, tSec);
      break;
   
   default:
         soporte->actualizarEstadoParametro(iParam, tSec);
      break;
   }

}

Varilla::Varilla(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z){


   agregar(MAT_Traslacion({X, Y, Z}));

   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));
   agregar(MAT_Rotacion(angulo_rotacion, {rot_X, rot_Y, rot_Z}));
   
   agregar(MAT_Escalado(escalado_X, escalado_Y, escalado_Z));

   agregar(MAT_Traslacion({1, 0, 0}));
   agregar(new Cubo(0.5, 0.7, 0.8));

   rotacion = leerPtrMatriz(indice);
}

unsigned Varilla::leerNumParametros() const{
    
   return 1;
}

void Varilla::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
      if(sin(tSec)*90 < 0)
         * rotacion = MAT_Rotacion(sin(tSec)*90, {0.0, 0.0, 1.0});
      break;
   
   default:
         * rotacion = MAT_Rotacion(sin(tSec), {0.0, 0.0, 1.0});
      break;
   }

}

Soporte::Soporte(int n){

   float angulo_incr = 360/n;

   //----------------------------------

   for(int i = 0; i<n; i++){

   }

   agregar(MAT_Rotacion(angulo_incr, {0, 1, 0}));
   v1 = new Varilla(1, 15, 0, 0, 0, 0, 1, 10, 1, 1);
   agregar(v1);

   agregar(MAT_Rotacion(angulo_incr, {0, 1, 0}));
   v2 = new Varilla(1, 15, 0, 0, 0, 0, 1, 10, 1, 1);
   agregar(v2);

   agregar(MAT_Rotacion(angulo_incr, {0, 1, 0}));
   v3 = new Varilla(1, 15, 0, 0, 0, 0, 1, 10, 1, 1);
   agregar(v3);

   agregar(MAT_Rotacion(angulo_incr, {0, 1, 0}));
   v4 = new Varilla(1, 15, 0, 0, 0, 0, 1, 10, 1, 1);
   agregar(v4);

   agregar(MAT_Rotacion(angulo_incr, {0, 1, 0}));
   v5 = new Varilla(1, 15, 0, 0, 0, 0, 1, 10, 1, 1);
   agregar(v5);

   //-------------------------------------

   agregar(MAT_Escalado(1, 15, 1));
   agregar(new Cilindro(30,30, {1,0,0}));

}

unsigned Soporte::leerNumParametros() const{
    
   return 1;
}

void Soporte::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         v1->actualizarEstadoParametro(iParam, tSec);
         v2->actualizarEstadoParametro(iParam, tSec);
         v3->actualizarEstadoParametro(iParam, tSec);
         v4->actualizarEstadoParametro(iParam, tSec);
         v5->actualizarEstadoParametro(iParam, tSec);
      break;
   
   default:
         v1->actualizarEstadoParametro(iParam, tSec);
         v2->actualizarEstadoParametro(iParam, tSec);
         v3->actualizarEstadoParametro(iParam, tSec);
         v4->actualizarEstadoParametro(iParam, tSec);
         v5->actualizarEstadoParametro(iParam, tSec);
      break;
   }

}

//-------------------------------------------

// Examen Donuts

AroUbicado::AroUbicado(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z, float radio_int, float radio_aro, float a, float b, float c){

   if(X == 0){
      eje = 0;
   }
   else if (X == 3){
      eje = 1;
   }
   else {
      eje = 2;
   }
   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));

   agregar(MAT_Traslacion({X, Y, Z}));
   agregar(MAT_Rotacion(angulo_rotacion, {rot_X, rot_Y, rot_Z}));
   agregar(MAT_Escalado(escalado_X, escalado_Y, escalado_Z));

   agregar(MAT_Traslacion({0, -radio_int, 0}));
   agregar(new Aro(30, 30, radio_int, radio_aro, a, b, c));

   rotacion = leerPtrMatriz(indice);
}

unsigned AroUbicado::leerNumParametros() const{
    
   return 1;
}

void AroUbicado::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
      
      switch (eje)
      {
      case 0:
         /* code */
         break;
      case 1:
         * rotacion = MAT_Rotacion(tSec*30, {1.0, 0.0, 0.0});
         break;
      
      case 2:
         * rotacion = MAT_Rotacion(-tSec*30, {1.0, 0.0, 0.0});
         break;
      
      default:
         break;
      }
         
      break;
   
   default:
         * rotacion = MAT_Rotacion(sin(tSec), {0.0, 0.0, 1.0});
      break;
   }

}

MultiplesAros::MultiplesAros(){

   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));

    a1 = new AroUbicado(0,0,0, 90, 1, 0, 0, 1, 1, 1, 6.5, 0.5, 1, 0, 0);
    agregar(a1);
    a2 = new AroUbicado(3.0,0,0, 90, 1, 0, 0, 1, 1, 1, 2.5, 0.5, 0, 1, 0);
    agregar(a2);
    a3 = new AroUbicado(-3.0,0,0, 90, 1, 0, 0, 1, 1, 1, 2.5, 0.5, 0, 0, 1);
    agregar(a3);

    rotacion = leerPtrMatriz(indice);
}

unsigned MultiplesAros::leerNumParametros() const{
    
   return 1;
}

void MultiplesAros::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         * rotacion = MAT_Rotacion(tSec*30, {0.0, 1.0, 0.0});
         a1->actualizarEstadoParametro(iParam, tSec);
         a2->actualizarEstadoParametro(iParam, tSec);
         a3->actualizarEstadoParametro(iParam, tSec);
      break;
   
   default:
         * rotacion = MAT_Rotacion(sin(tSec), {0.0, 0.0, 1.0});
      break;
   }

}

//------------------

// Examen escavadora

ObjetoModificable::ObjetoModificable(Tupla3f traslacion, float angulo_rotacion, Tupla3f rotacion, Tupla3f escalado, Objeto3D & ObjetoModificable){

   agregar(MAT_Traslacion(traslacion));
   agregar(MAT_Rotacion(angulo_rotacion, rotacion));
   agregar(MAT_Escalado(escalado(0), escalado(1), escalado(2)));

   agregar(& ObjetoModificable);
}

//---------------------------

SegundoGanchoExcavadora::SegundoGanchoExcavadora(Tupla3f traslacion, float angulo_rotacion, Tupla3f rotacion, Tupla3f escalado){
   
   
   agregar(MAT_Traslacion(traslacion));
   
   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));
   
   agregar(MAT_Rotacion(angulo_rotacion, rotacion));
   agregar(MAT_Escalado(escalado(0), escalado(1), escalado(2)));

   agregar(MAT_Traslacion({6, 0, 0}));
   agregar(new Cubo({0.3,0.3,0.3}));

   rotacionPrimerGancho = leerPtrMatriz(indice);
}

unsigned SegundoGanchoExcavadora::leerNumParametros() const{
    
   return 1;
}

void SegundoGanchoExcavadora::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         * rotacionPrimerGancho = MAT_Rotacion(sin(tSec)*16, {0.0, 0.0, 1.0});
         
      break;
   
   default:
         * rotacionPrimerGancho = MAT_Rotacion(sin(tSec)*16, {0.0, 0.0, 1.0});
      break;
   }

}

//---------------------------

PrimerGanchoExcavadora::PrimerGanchoExcavadora(Tupla3f traslacion, float angulo_rotacion, Tupla3f rotacion, Tupla3f escalado){
   
   
   agregar(MAT_Traslacion(traslacion));
   
   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));
   agregar(MAT_Rotacion(angulo_rotacion, rotacion));
   agregar(MAT_Escalado(escalado(0), escalado(1), escalado(2)));
   
   agregar(MAT_Traslacion({1, 0, 0}));
   agregar(new Cubo({0,1,0}));

   rotacionPrimerGancho = leerPtrMatriz(indice);
}

unsigned PrimerGanchoExcavadora::leerNumParametros() const{
    
   return 1;
}

void PrimerGanchoExcavadora::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         * rotacionPrimerGancho = MAT_Rotacion(sin(tSec)*20, {0.0, 0.0, 1.0});
         
      break;
   
   default:
         * rotacionPrimerGancho = MAT_Rotacion(sin(tSec)*20, {0.0, 0.0, 1.0});
      break;
   }

}

//---------------------------

GanchoExcavadora::GanchoExcavadora(){
   
   primerGanchoExcavadora = new PrimerGanchoExcavadora({0,6,0}, 0, {1,0,0}, {4,0.2,0.2});
   segundoGancho = new SegundoGanchoExcavadora({-2,6,0}, 0, {1,0,0}, {2,0.2,0.2});

   agregar(primerGanchoExcavadora);
   agregar(segundoGancho);

}

unsigned GanchoExcavadora::leerNumParametros() const{
    
   return 1;
}

void GanchoExcavadora::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         primerGanchoExcavadora->actualizarEstadoParametro(iParam, tSec);
         segundoGancho->actualizarEstadoParametro(iParam, tSec);
         
      break;
   
   default:
         primerGanchoExcavadora->actualizarEstadoParametro(iParam, tSec);
         segundoGancho->actualizarEstadoParametro(iParam, tSec);

      break;
   }

}

//---------------------------

ParteArribaExcavadora::ParteArribaExcavadora(){

   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));

   agregar(new ObjetoModificable({0,6,0}, 0, {1,0,0}, {1,1,1}, * new Cubo({0,0,1})));
   ganchoExcavadora = new GanchoExcavadora();
   agregar(ganchoExcavadora);

   rotacion = leerPtrMatriz(indice);
}

unsigned ParteArribaExcavadora::leerNumParametros() const{
    
   return 1;
}

void ParteArribaExcavadora::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         ganchoExcavadora->actualizarEstadoParametro(iParam, tSec);
         * rotacion = MAT_Rotacion(tSec*30, {0.0, 1.0, 0.0});
         
      break;
   
   default:
         ganchoExcavadora->actualizarEstadoParametro(iParam, tSec);
         * rotacion = MAT_Rotacion(tSec*30, {0.0, 0.0, 1.0});
      break;
   }

}


//---------------------------

Excavadora::Excavadora(){

   int indice = agregar(MAT_Rotacion((0.0), {0.0, 1.0, 0.0}));

   agregar(new ObjetoModificable({2, 0, -0.5}, 90, {1,0,0}, {1,1,1}, * new Cilindro(30, 30, {0,0,0})));
   agregar(new ObjetoModificable({-2, 0, -0.5}, 90, {1,0,0}, {1,1,1}, * new Cilindro(30, 30, {0,0,0})));

   agregar(new ObjetoModificable({0,3,0}, 0, {1,0,0}, {4,2,2}, * new Cubo({1,0,0})));

   parteArriba = new ParteArribaExcavadora();
   agregar(parteArriba);

   traslacion = leerPtrMatriz(indice);
   
}

unsigned Excavadora::leerNumParametros() const{
    
   return 1;
}

void Excavadora::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         * traslacion = MAT_Traslacion({sin(tSec)*5, 0, 0});
         parteArriba->actualizarEstadoParametro(iParam, tSec);
      break;
   
   default:
         * traslacion = MAT_Traslacion({sin(tSec)*5, 0, 0});
         parteArriba->actualizarEstadoParametro(iParam, tSec);
      break;
   }

}

