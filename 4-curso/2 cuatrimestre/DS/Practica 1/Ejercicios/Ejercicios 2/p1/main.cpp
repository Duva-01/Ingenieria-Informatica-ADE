#include "prototipo.h"

int main() {
    SesionPesca sesion;

    //Crear pez y barco pequeño
    Pez* pez = new PezPequenio(); //Cliente encargado de crear los prototipos que quiera
    Barco* barco = new PesqueroRedes();

    FactoriaPrototipoPezYBarco *prototipo_factoria_PB = new FactoriaPrototipoPezYBarco(10,pez,barco); //Prototipo factoria

    Barco* resultado = sesion.crearBarcoSesion(prototipo_factoria_PB); //Cliente crea sesión

    resultado->pescar();

    delete resultado; //Se encarga de borrar el barco
    delete prototipo_factoria_PB; //Se encarga de borrar la factoria

    //Crear pez y barco grande
    pez= new PezGrande(); //Cliente encargado de crear los prototipos que quiera
    barco = new PesqueroGrande();

    prototipo_factoria_PB = new FactoriaPrototipoPezYBarco(10,pez,barco);

    resultado = sesion.crearBarcoSesion(prototipo_factoria_PB); //Cliente crea sesión

    resultado->pescar();

    delete resultado; //Se encarga de borrar el barco
    delete prototipo_factoria_PB; //Se encarga de borrar la factoria
}
