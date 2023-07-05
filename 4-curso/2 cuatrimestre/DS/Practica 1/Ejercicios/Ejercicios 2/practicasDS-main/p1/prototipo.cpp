#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <random>
#include "prototipo.h"

using namespace std;

/*Implementaciones clase Barco*/
void Barco::pescar(){
    for(auto i=0; i<peces.size(); i++){
        peces.at(i)->serPescado(); //Peces de alrededor del barco
    }
}
        

vector<Pez *> Barco::getPeces(){
    return peces;
}


void Pez::asignarBarco(Barco *b) {
    barco = b;
}

void Pez::serPescado() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double>dist(0,1); //Genera nº aleatorio entre 0 y 1 con decimales

    double numero_aleatorio = dist(gen); //Copia nº aleatorio

    if(numero_aleatorio <= barco->getProbabilidad()){ //Nº aleatorio <= Probabilidad de pesca
        print(); 
    }

}


/*Otras implementaciones*/
void SesionPesca::crearBarcoSesion(FactoriaPrototipoPezYBarco *factoria){
    cout << "Sesión pesca barco grande: " << endl;

    Barco* prototipo_barco = factoria->crearBarco(TipoBarco::B_GRANDE); //Crea barco grande
    
    Pez* prototipo_pez;//Definir prototipo para no sobrecargar en el bucle


    for( int i=0; i<factoria->getCapacidad(); i++ ) { // Hasta --> Peces de alrededor
        prototipo_pez = factoria->crearPez(TipoPez::P_GRANDE); //Crea pez
        prototipo_pez->asignarBarco(prototipo_barco);//Pez se le asigna barco actual
        prototipo_barco->aniadirPez(prototipo_pez);//Barco se le asigna pez de la zona
    }

    prototipo_barco->pescar(); //Pesca

    delete prototipo_barco; //Eliminamos el barco especifico

    
    cout << "\nSesión pesca barco pequeño: " << endl; 

    prototipo_barco = factoria->crearBarco(TipoBarco::B_PEQUENIO);
    
    for( int i=0; i<factoria->getCapacidad(); i++ ) {
        prototipo_pez = factoria->crearPez(TipoPez::P_PEQUENIO);
        prototipo_pez->asignarBarco(prototipo_barco);
        prototipo_barco->aniadirPez(prototipo_pez);
    }

    prototipo_barco->pescar();

    delete prototipo_barco;
 }



