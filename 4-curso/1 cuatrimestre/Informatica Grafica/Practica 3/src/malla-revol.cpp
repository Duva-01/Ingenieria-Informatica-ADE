// Nombre: David Apellidos: Martinez Diaz Titulación: GIADE.
// email: dmartinez01@correo.ugr.es DNI o pasaporte: 44669141J

// *********************************************************************
// **
// ** Informática Gráfica, curso 2019-20
// ** Implementación de la clase 'MallaRevol'
// **
// *********************************************************************

#include "ig-aux.h"
#include "lector-ply.h"
#include "malla-revol.h"

using namespace std ;

// *****************************************************************************




// Método que crea las tablas de vértices, triángulos, normales y cc.de.tt.
// a partir de un perfil y el número de copias que queremos de dicho perfil.
void MallaRevol::inicializar
(
   const std::vector<Tupla3f> & perfil,     // tabla de vértices del perfil original
   const unsigned               num_copias  // número de copias del perfil
)
{
   // COMPLETAR: Práctica 2: completar: creación de la malla....
   Tupla3f q;
   float x,y;

   vertices.clear();

   for(int i=0; i <= num_copias-1; i++){

      for(int j=0; j <= perfil.size()-1; j++){

         q = {perfil.at(j)(0)*cos(i*2*M_PI/(num_copias-1)), perfil.at(j)(1), perfil.at(j)(0)*sin(i*2*M_PI/(num_copias-1))};
         vertices.push_back(q);
      }
   }

   // Añadimmos los triangulos

   triangulos.clear();

   float k;

   for(int i = 0; i <= num_copias - 2; i++){

      for(int j=0; j <= perfil.size() - 2; j++){

         k = i*perfil.size() + j;
         triangulos.push_back({k, k+perfil.size(), k+perfil.size()+1});
         triangulos.push_back({k, k+perfil.size()+1, k+1});

      }
   }
}

// -----------------------------------------------------------------------------
// constructor, a partir de un archivo PLY

MallaRevolPLY::MallaRevolPLY
(
   const std::string & nombre_arch,
   const unsigned      nperfiles
)
{
   ponerNombre( std::string("malla por revolución del perfil en '"+ nombre_arch + "'" ));
   // COMPLETAR: práctica 2: crear la malla de revolución
   // Leer los vértice del perfil desde un PLY, después llamar a 'inicializar'
   // ...........................

   std::vector<tup_mat::Tupla3f> aux;
   LeerVerticesPLY(nombre_arch, aux);
   inicializar(aux, nperfiles);

}

//------------------------

Cilindro::Cilindro(const int num_vert_per, const unsigned nperfiles, Tupla3f colores ){

   std::vector<Tupla3f> perfil;

   perfil.push_back({0.0, 0.0, 0.0});
   
   for(int i=0; i<num_vert_per; i++){
      perfil.push_back({1.0, (i*(1.0/(num_vert_per-1))), 0.0});
   }
   perfil.push_back({0.0, 1, 0.0});
   
   inicializar(perfil, nperfiles);

   for(int i=0; i<vertices.size(); i++){
      col_ver.push_back(colores);
   }
}

//--------------------------

Cono::Cono(const int num_vert_per, const unsigned nperfiles ){

   std::vector<Tupla3f> perfil;

   perfil.push_back({0.0, 1, 0.0});

   for(int i=0; i<num_vert_per; i++){
      perfil.push_back({1-((i+1)/num_vert_per),(i/num_vert_per), 0.0});
   }

   perfil.push_back({0.0, 0.0, 0.0});
   inicializar(perfil, nperfiles);

   
}

//-----------------------------

Esfera::Esfera(const int num_vert_per, const unsigned nperfiles ){

   std::vector<Tupla3f> perfil;
   float x,y;

   for(int angulo=-90; angulo<=90; angulo+=180/num_vert_per){

      x = cos( angulo*M_PI/180.0 );
      y = sin( angulo*M_PI/180.0 );
      perfil.push_back({x, y, 0.0});
   }

   inicializar(perfil, nperfiles);
}


SemiEsfera::SemiEsfera(const int num_vert_per, const unsigned nperfiles, Tupla3f colores ){

   std::vector<Tupla3f> perfil;
   float x,y;

   for(int angulo=-90; angulo<=0; angulo+=180/num_vert_per){

      x = cos( angulo*M_PI/180.0 );
      y = sin( angulo*M_PI/180.0 );

      perfil.push_back({x, y, 0.0});

   }

   perfil.push_back({0, 0, 0.0});

   inicializar(perfil, nperfiles);

   for(int i=0; i<vertices.size(); i++){
      col_ver.push_back(colores);
   }
}

//------------------------------


Aro::Aro(const int num_vert_per, const unsigned nperfiles, float radio_int, float radio_aro, float a, float b, float c){

   float X_picos, Y_picos;
   float angulo_incr = 360.0/(nperfiles);
   float angulo = 360.0/(nperfiles);

   std::vector<Tupla3f> perfil;

   for(int i=0; i<=nperfiles; i++){

      X_picos = radio_int + radio_aro*cos( angulo*M_PI/180 );
      Y_picos = radio_int + radio_aro*sin( angulo*M_PI/180 );

      std::cout << "Agrego el punto en la posicion: " << X_picos << ", " << Y_picos << " con un angulo de " << angulo << std::endl;

      perfil.push_back({X_picos, Y_picos, 0.0});
   
      angulo += angulo_incr;
   }

   inicializar(perfil, nperfiles);

   for(int i=0; i<vertices.size(); i++){
      col_ver.push_back({a,b,c});
   }
}
