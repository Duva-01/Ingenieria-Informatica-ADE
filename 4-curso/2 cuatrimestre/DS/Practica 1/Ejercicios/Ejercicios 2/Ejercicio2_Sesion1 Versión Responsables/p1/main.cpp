#include "prototipo.h"

int main() {
    SesionPesca sesion;

    FactoriaPrototipoPezYBarco *prototipo_factoria_PB = new FactoriaPrototipoPezYBarco(new  PezPequenio(), new PesqueroRedes()); //Prototipo factoria
    delete(prototipo_factoria_PB);
    Barco * b1_peq = sesion.crearBarcoSesion( prototipo_factoria_PB,10); //Cliente crea sesiónS
    b1_peq->pescar();
    prototipo_factoria_PB = new FactoriaPrototipoPezYBarco(new  PezGrande(), new PesqueroGrande()); 
    Barco * b2_gr = sesion.crearBarcoSesion( prototipo_factoria_PB,10);
    
    delete prototipo_factoria_PB;
}
