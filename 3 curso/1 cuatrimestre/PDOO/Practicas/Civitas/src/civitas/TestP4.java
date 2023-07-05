/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;
/**
 *
 * @author Usuario
 */
public class TestP4 {
    
    private static void pruebaConversiónJugador () {
      int i;  // Un contador para los bucles
        
//      # Nos preparamos un par de nombres para tener dos jugadores
      
      ArrayList<String> nombres = new ArrayList<>();
      nombres.add ("Vilma");
      nombres.add ("Pedro");
      
      CivitasJuego juego = new CivitasJuego (nombres, true); 
      Diario diario = Diario.getInstance();
      
      diario.ocurreEvento(juego.getJugadores().get(0).toString());
      diario.ocurreEvento(juego.getJugadores().get(1).toString());
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      diario.ocurreEvento("Turno de " + juego.getJugadorActual().getNombre());
      
      juego.getJugadorActual().moverACasilla(1);
      juego.getJugadorActual().puedeComprarCasilla();
      diario.ocurreEvento(juego.getTablero().getCasilla(1).toString());
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      juego.getJugadorActual().comprar((CasillaCalle) juego.getTablero().getCasilla(1));
      
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      diario.ocurreEvento(juego.getJugadores().get(0).toString());
      diario.ocurreEvento(juego.getJugadores().get(1).toString());
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      SorpresaConvertirme sorpresa = new SorpresaConvertirme ("Convertir Jugador a especulador", 0, null);
      sorpresa.aplicarAJugador(juego.getIndiceJugadorActual(), juego.getJugadores());

      diario.ocurreEvento(juego.getJugadorActual().toString());
      diario.ocurreEvento(juego.getTablero().getCasilla(1).toString());
      
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      juego.getJugadorActual().moverACasilla(2);
      juego.getJugadorActual().puedeComprarCasilla();
      diario.ocurreEvento(juego.getTablero().getCasilla(2).toString());
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      juego.getJugadorActual().comprar((CasillaCalle) juego.getTablero().getCasilla(1));
      
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      diario.ocurreEvento(juego.getJugadores().get(0).toString());
      diario.ocurreEvento(juego.getJugadores().get(1).toString());
   
      diario.ocurreEvento("\n ------------------------------ \n");
      
      juego.getJugadorActual().convertir();
      
      diario.ocurreEvento("\n ------------------------------ \n");
      
      while (diario.eventosPendientes()) {
        System.out.println (diario.leerEvento());
      }

    }

    public static void main (String[] args) {
      pruebaConversiónJugador();
    }
}
