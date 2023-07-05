#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:

    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado

      fil = col = 99;

      brujula = cont_coste = grado_arriesgo = esperar_recarga = 0;
      coste_zona_a = coste_zona_b = coste_terreno = cont_adelante = cont_intercalar_algoritmo = 0;

      ultimaAccion = accion = actIDLE;

      bien_situado = false;
      bikini = zapatillas = recarga = fin_recarga = puede_pasar = false;

      cont_bosque = cont_agua = cont_piedra = cont_arena = 0;

      ir_hacia_zonaA = ir_hacia_zonaB = ir_recto = check_mitad_mov = casilla_encontrada = false;
      ir_hacia_zonaA_puerta = ir_hacia_zonaB_puerta = ir_recto_puerta = check_mitad_mov_puerta = hay_puerta = false;

      ir_muro_derecha = ir_muro_izquierda = false;
      /*
      for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
          matrizRecorrida[i][j] = false;
        } 
      }  
      */
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    void PintarMapa(int direccion, Sensores sensores);
    void PintarFinalMapa(Sensores sensores);

    void AlgoritmoBusquedaCoste(Sensores sensores);
    void AlgoritmoPosicionamiento(Sensores sensores);
    void AlgoritmoPuerta(Sensores sensores);
    void AlgoritmoMuros(Sensores sensores);

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
    // Declarar aquí las variables de estado
    int fil, col, brujula, cont_coste, grado_arriesgo, esperar_recarga, cont_adelante, cont_intercalar_algoritmo;
    Action ultimaAccion, accion;

    int coste_zona_a,
			  coste_zona_b,
        coste_terreno;

    int cont_bosque, cont_agua, cont_piedra, cont_arena;
    bool girar_derecha, bien_situado;

    bool ir_hacia_zonaA, ir_hacia_zonaB, ir_recto, check_mitad_mov, casilla_encontrada;
    bool ir_hacia_zonaA_puerta, ir_hacia_zonaB_puerta, ir_recto_puerta, hay_puerta;
    bool ir_muro_derecha, ir_muro_izquierda;
    bool bikini, zapatillas, recarga, fin_recarga, puede_pasar, check_mitad_mov_puerta;

    //bool matrizRecorrida[99][99];

};

#endif
