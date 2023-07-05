#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct estado {

  int fila;
  int columna;
  int orientacion;

  bool bikini;
  bool deportivas;

  int valor_F;
  int valor_G;

  vector<bool> objetivos;
  
  inline bool finObjetivos() const{
    
    bool recorridoCompletado = true;

    for(int i=0; i<objetivos.size() && recorridoCompletado; i++)
      recorridoCompletado = recorridoCompletado && objetivos[i];

    return recorridoCompletado;

  }

};

struct nodo{
	estado st;
	list<Action> secuencia;

  bool operator<(const nodo & nodo2) const {
		return (st.valor_F >= nodo2.st.valor_F);
	}
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado

      casillaEncontrada =  tieneBikini = tieneDeportivas = false;
      fin_recarga =  true;
      fila_especial = columna_especial = 0;
      fila_aux = columna_aux = 3;
      hay_plan = false;

      fila_busqueda = columna_busqueda = 3;
      contador = 0;

      int nivel_4_fila = nivel_4_columna = nivel_4_orientacion = 0;

      contador_objetivos = 0;
      contador_vector = 0;
      ultimaAccion = actIDLE;

      nuevos_objetivos = true;

    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      hay_plan = false;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    estado actual, casillaEspecial;
    list<estado> objetivos;
    list<Action> plan;
    Action ultimaAccion;
    
    list<estado>::iterator it;
    vector<estado> objetivos_vector;
    
    int fila_especial, columna_especial;
    bool hay_plan, fin_recarga, casillaEncontrada, tieneBikini, tieneDeportivas;

    int fila_aux, columna_aux;
    int fila_busqueda, columna_busqueda;
    int contador, contador_objetivos;

    int nivel_4_fila, nivel_4_columna, nivel_4_orientacion;
    int contador_vector = 0;

    bool nuevos_objetivos;

    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const list<estado> &destino, list<Action> &plan, Sensores sensores);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan);

    int Chebychev(nodo & nodo1, const estado & objetivo);
    int costeCasilla(nodo & nodo1, const Action & accion);
    void comprobarVestimenta(estado & estado);
    bool pathFinding_A_Estrella(const estado &origen, const estado &destino, list<Action> &plan);

    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);

    void PintarMapa(estado actual, Sensores sensores);
    bool descubiertoCasillaEspecial();

    int ChebychevMultipleObjetivos(nodo & nodo1, const vector<estado> &objetivos, const vector<bool> & objetivos_visitados);
    bool HayObstaculoDelante4(estado &st, Sensores sensores);
    bool pathFinding_A_Estrella_4 (const estado &origen, const vector<estado> &destino, list<Action> &plan, Sensores sensores);
    void modificarPosicionamiento(Action ultimaAccion);
    
    void esObjetivo(estado & st);

};

#endif
