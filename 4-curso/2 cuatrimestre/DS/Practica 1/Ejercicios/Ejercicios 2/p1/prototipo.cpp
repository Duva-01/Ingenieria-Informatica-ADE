#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <random>
#include "prototipo.h"

using namespace std;

/*Implementaciones clase Barco*/
void Barco::pescar()
{
    int contador = 1;
    for (auto i = 0; i < peces.size(); i++)
    {
        if(peces.at(i)->serPescado())
            cout << contador++ <<"\n";  // Peces de alrededor del barco
    }
}

vector<Pez *> Barco::getPeces()
{
    return peces;
}

void Pez::asignarBarco(Barco *b)
{
    barco = b;
}

bool Pez::serPescado()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0, 1); // Genera nº aleatorio entre 0 y 1 con decimales

    double numero_aleatorio = dist(gen); // Copia nº aleatorio

    if (numero_aleatorio <= barco->getProbabilidad())
    { // Nº aleatorio <= Probabilidad de pesca
        print();
        return true;
    }
    return false;
}

/*Otras implementaciones*/
Barco *SesionPesca::crearBarcoSesion(FactoriaPrototipoPezYBarco *factoria)
{
    Barco *prototipo_barco = factoria->crearBarco(); // Crea barco
    cout << "Sesión pesca " << prototipo_barco->toString() << ": " << endl;

    Pez *prototipo_pez; // Definir prototipo para no sobrecargar en el bucle

    for (int i = 0; i < factoria->getCapacidad(); i++)
    {                                                 // Hasta --> Peces de alrededor
        prototipo_pez = factoria->crearPez();         // Crea pez
        prototipo_pez->asignarBarco(prototipo_barco); // Pez se le asigna barco actual
        prototipo_barco->aniadirPez(prototipo_pez);   // Barco se le asigna pez de la zona
    }

    return prototipo_barco;
}
