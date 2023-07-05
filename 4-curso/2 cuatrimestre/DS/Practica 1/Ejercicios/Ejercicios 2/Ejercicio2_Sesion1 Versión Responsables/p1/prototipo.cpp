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
Barco * SesionPesca::crearBarcoSesion(FactoriaPrototipoPezYBarco *factoria, int capacidad){
    cout << "Sesión pesca barco grande: " << endl;
    cout<<"Debug en sesion" << endl;
    Barco * prototipo_barco = factoria->crearBarco(capacidad); //Crea barco grande


return prototipo_barco;
 }



