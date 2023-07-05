// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

#include "ig-aux.h"
#include "malla-ind.h"   // declaración de 'ContextoVis'
#include "lector-ply.h"
#include "modelo-jer.h"



C::C(const float velocidad){

   int indice = agregar(MAT_Rotacion((45.0 + velocidad), {1.0, 0.0, 0.0}));
   agregar( MAT_Traslacion( {0.1,1.0,0.0} ) );// Tra[0.1, 0.1]
   agregar( MAT_Escalado( 0.4,0.8,1.0 ) ); // Esc[0.4, 0.8]

   agregar( new MallaPiramideL() ); 

   rotacion = leerPtrMatriz(indice);
   

}
// Redefinimos metodo leerNumParametros()

unsigned C::leerNumParametros() const{
    
   return 1;
}

// Redefinimos metodo actualizarEstadoParametro()
void C::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         *rotacion = MAT_Rotacion((45.0 + tSec), {1.0, 0.0, 0.0});
      break;
   
   default:
         *rotacion = MAT_Rotacion((45.0 + tSec), {1.0, 0.0, 0.0});
      break;
   }

}

// --------------------------------------------

// Proyecto Helicoptero
CuboProyectoUbicado::CuboProyectoUbicado(float X, float Y, float Z, float angulo_rotacion, float rot_X, float rot_Y, float rot_Z, float escalado_X, float escalado_Y, float escalado_Z, float a, float b, float c){

   agregar(MAT_Traslacion({X, Y, Z}));
   agregar(MAT_Rotacion(angulo_rotacion, {rot_X, rot_Y, rot_Z}));
   agregar(MAT_Escalado(escalado_X, escalado_Y, escalado_Z));

   agregar(new Cubo(a, b, c));
}

//----------------------------------------

HeliceHelicopteroLateral::HeliceHelicopteroLateral(){

   agregar(MAT_Traslacion({-3.0,0.0,-0.6}));

   int indice = agregar(MAT_Rotacion((0.0), {1.0, 0.0, 0.0}));

   //agregar( new CuboProyectoUbicado(-3.0, 0.0, -0.6, 0, 1.0, 0.0, 0.0, 0.05, 0.4, 0.05, 0.35, 0.35, 0.35) ); 
   agregar( new CuboProyectoUbicado(0.0, 0.0, 0.0, 0, 1.0, 0.0, 0.0, 0.05, 0.4, 0.05, 0.35, 0.35, 0.35) ); 

   rotacionHeliceLateral = leerPtrMatriz(indice);

}

unsigned HeliceHelicopteroLateral::leerNumParametros() const{
    
   return 1;
}

// Redefinimos metodo actualizarEstadoParametro()
void HeliceHelicopteroLateral::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         *rotacionHeliceLateral = MAT_Rotacion((360*2.5 * tSec), {0.0, 0.0, 1.0});
      break;
   
   }

}

//---------------------------------------

HeliceHelicopteroArriba::HeliceHelicopteroArriba(){

   int indice = agregar(MAT_Rotacion((0.0), {1.0, 0.0, 0.0}));

   agregar( new CuboProyectoUbicado(0.0, 0.7, 0.0, 0, 1.0, 0.0, 0.0, 1.5, 0.1, 0.1, 0.35, 0.35, 0.35) ); 

   rotacionHeliceArriba = leerPtrMatriz(indice);
}

unsigned HeliceHelicopteroArriba::leerNumParametros() const{
    
   return 1;
}

// Redefinimos metodo actualizarEstadoParametro()
void HeliceHelicopteroArriba::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         *rotacionHeliceArriba = MAT_Rotacion((360*2.5 * tSec), {0.0, 1.0, 0.0});
      break;
   
   }

}

//------------------------------------------

TroncoHelicoptero::TroncoHelicoptero(){

   agregar( new CuboProyectoUbicado(0.0, 0.0, 0.0, 0, 1.0, 0.0, 0.0, 1.0, 0.5, 0.5, 1.0, 0.1, 0.1) ); // Tronco Principal

   agregar( new CuboProyectoUbicado(0.5, 0.0, 0.0, 0, 1.0, 0.0, 0.0, 0.25, 0.35, 0.60, 0.0, 0.0, 0.80) ); // Ventanas
   agregar( new CuboProyectoUbicado(0.90, 0.0, 0.0, 0, 1.0, 0.0, 0.0, 0.20, 0.35, 0.40, 0.0, 0.0, 0.80) ); // Ventanas
   
   agregar( new CuboProyectoUbicado(0.0, 0.5, 0.0, 0, 1.0, 0.0, 0.0, 0.1, 0.2, 0.1, 0.35, 0.35, 0.35) ); // Pivote arriba
}

//------------------------------------

ParteAbajoHelicoptero::ParteAbajoHelicoptero(){

   agregar( new CuboProyectoUbicado(0.0, -0.5, 0.25, 0, 1.0, 0.0, 0.0, 0.1, 0.2, 0.1, 0.35, 0.35, 0.35) ); // Pivote abajo
   agregar( new CuboProyectoUbicado(0.0, -0.5, -0.25, 0, 1.0, 0.0, 0.0, 0.1, 0.2, 0.1, 0.35, 0.35, 0.35) ); // Pivote abajo

   agregar( new CuboProyectoUbicado(0.0, -0.75, 0.25, 0, 1.0, 0.0, 0.0, 0.85, 0.1, 0.2, 0.35, 0.35, 0.35) ); // Aletas
   agregar( new CuboProyectoUbicado(0.0, -0.75, -0.25, 0, 1.0, 0.0, 0.0, 0.85, 0.1, 0.2, 0.35, 0.35, 0.35) );  // Aletas

}

//---------------------------------------

ColaHelicoptero::ColaHelicoptero(){

   agregar( new CuboProyectoUbicado(-2.0, 0.0, 0.0, 0, 1.0, 0.0, 0.0, 1.0, 0.25, 0.25, 1.0, 0.1, 0.1) ); 
   agregar( new CuboProyectoUbicado(-3.0, 0.0, 0.0, 0, 1.0, 0.0, 0.0, 0.4, 0.4, 0.4, 1.0, 0.1, 0.1) ); 

   agregar( new CuboProyectoUbicado(-3.0, 0.0, -0.2, 0, 1.0, 0.0, 0.0, 0.1, 0.1, 0.4, 0.35, 0.35, 0.35) ); 
}

//-----------------------------------------

Escenario::Escenario(){

   agregar( new CuboProyectoUbicado(0.0, -3.0, 0.0, 0, 1.0, 0.0, 0.0, 20.0, 1.0, 20.0, 0.1, 1.0, 0.1) ); 

   // Arboles
   agregar( new CuboProyectoUbicado(5.0, -1.0, 7.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(5.0, 0.0, 7.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) ); 

   agregar( new CuboProyectoUbicado(-10.0, -1.0, 7.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(-10.0, 0.0, 7.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) );

   agregar( new CuboProyectoUbicado(-14.0, -1.0, -7.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(-14.0, 0.0, -7.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) );

   agregar( new CuboProyectoUbicado(17.0, -1.0, 12.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(17.0, 0.0, 12.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) );

   agregar( new CuboProyectoUbicado(17.0, -1.0, -12.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(17.0, 0.0, -12.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) );

   agregar( new CuboProyectoUbicado(9.0, -1.0, -4.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(9.0, 0.0, -4.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) );

   agregar( new CuboProyectoUbicado(-9.0, -1.0, -2.0, 0, 1.0, 0.0, 0.0, 0.5, 1.0, 0.5, 1.0, 0.3, 0.4) ); 
   agregar( new CuboProyectoUbicado(-9.0, 0.0, -2.0, 0, 1.0, 0.0, 0.0, 0.75, 0.5, 0.75, 0.1, 0.5, 0.1) );
}

//------------------------------------------

FuegoProyecto::FuegoProyecto(){

   agregar(new CuboProyectoUbicado(0.0, -2.0, 0.0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.7, 0.0, 0.0));

   int indice = agregar(MAT_Traslacion({1, 1, 1}));

   agregar(new CuboProyectoUbicado(0.0, -1.2, 0.0, 0, 1.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.8, 0.0, 0.0));
   agregar(new CuboProyectoUbicado(0.6, -0.7, 0.6, 0, 1.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.6, 0.0, 0.0));
   agregar(new CuboProyectoUbicado(0.6, -0.4, -0.6, 0, 1.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.6, 0.0, 0.0));
   agregar(new CuboProyectoUbicado(-0.6, -0.2, 0.6, 0, 1.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.6, 0.0, 0.0));
   agregar(new CuboProyectoUbicado(-0.6, -1.0, -0.6, 0, 1.0, 0.0, 0.0, 0.2, 0.2, 0.2, 0.4, 0.0, 0.0));

   traslacionFuego = leerPtrMatriz(indice);
}

unsigned FuegoProyecto::leerNumParametros() const{
    
   return 1;
}

// Redefinimos metodo actualizarEstadoParametro()
void FuegoProyecto::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:
         *traslacionFuego = MAT_Traslacion({0,sin(tSec),0});  
         
      break;
   
   }

}

//------------------------------------------

Helicoptero::Helicoptero(){

   agregar (new Escenario() );

   fuego = new FuegoProyecto();
   agregar(fuego);

   int indice = agregar(MAT_Rotacion((0), {1.0, 0.0, 0.0}));
   int indice_2 = agregar(MAT_Traslacion({0,0,0}));
   
   agregar(MAT_Traslacion({0, 2, 3}));    
   agregar( new TroncoHelicoptero() ); 
   agregar( new ParteAbajoHelicoptero() );
   agregar( new ColaHelicoptero() );

   helice_arriba = new HeliceHelicopteroArriba();
   helice_lateral = new HeliceHelicopteroLateral();

   agregar(helice_lateral);
   agregar( helice_arriba );

   rotacion = leerPtrMatriz(indice);
   traslacion = leerPtrMatriz(indice_2);

}

// Redefinimos metodo leerNumParametros()

unsigned Helicoptero::leerNumParametros() const{
    
   return 1;
}

// Redefinimos metodo actualizarEstadoParametro()
void Helicoptero::actualizarEstadoParametro( const unsigned iParam, const float tSec )
{
   assert(iParam < leerNumParametros());
   
   switch (iParam)
   {
   case 0:

         helice_arriba->actualizarEstadoParametro(iParam, tSec);
         helice_lateral->actualizarEstadoParametro(iParam, tSec);

         fuego->actualizarEstadoParametro(iParam, tSec);

         *rotacion = MAT_Rotacion((20 * tSec), {0.0, 1.0, 0.0});
         *traslacion = MAT_Traslacion({0,sin(tSec),0});    

      break;
   
   }

}