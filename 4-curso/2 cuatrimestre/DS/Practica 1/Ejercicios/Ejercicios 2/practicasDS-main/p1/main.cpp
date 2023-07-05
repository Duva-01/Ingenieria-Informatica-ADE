#include "prototipo.h"

int main() {
    SesionPesca sesion;

    FactoriaPrototipoPezYBarco *prototipo_factoria_PB = new FactoriaPrototipoPezYBarco(10); //Prototipo factoria

    sesion.crearBarcoSesion(prototipo_factoria_PB); //Cliente crea sesión

    
    delete prototipo_factoria_PB;
}
