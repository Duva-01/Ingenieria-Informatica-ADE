/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

// Si es necesario, se le cambia la visibilidad a los métodos que vayan a ser llamados desde aquí

public class Pruebas {

//#     PRUEBA:
//#     Se quiere probar que un jugador no puede tener 5 casas a la vez, 
//#     pero que sí puede construir un hotel cuando tiene 4 casas y que no puede construir un 
//#     hotel si no tiene exactamente 4 casas
//#     Ya que estamos, se quiere probar que el otro jugador,
//#     cuando caiga en la casilla del primer jugador, con edificaciones, 
//#     paga el alquiler correctamente
//#    
//#     REQUISITOS:
//#     Es necesario que en la casilla 1 haya una calle y que el juego esté en modo debug
    
    private static void pruebaHotelAlquiler () {
      int i;  // Un contador para los bucles
        
//      # Nos preparamos un par de nombres para tener dos jugadores
      
      ArrayList<String> nombres = new ArrayList<>();
      nombres.add ("Vilma");
      nombres.add ("Pedro");
      
//      # Instanciamos un juego y obtenemos el diario
      // En mi versión puedo poner el modo debug al instanciar el juego (el boolean del segundo parámetro)
      CivitasJuego juego = new CivitasJuego (nombres, true); 
      Diario diario = Diario.getInstance();
      
//      # Se implementa la prueba usando métodos de CivitasJuego y de Diario. Se le envían los mensajes a dichas variables.
      
//      # Durante el transcurso de la prueba se pueden escribir cosas en el diario
      diario.ocurreEvento("Turno de " + juego.getJugadorActual().getNombre());
      
//      # EMPEZAMOS A JUGAR.

//      # Avanzamos al primer jugador 
//      # Recordar que avanzar un jugador es que tire el dado (saldrá 1 al estar en modo debug)
//      # llegue a esa casilla, y le ocurra todo lo que pueda ocurrirle de manera automática
//      # Eso es lo que hace el método  avanza_jugador
      juego.avanzaJugador();
      
//      # Lo que requiere intervención del usuario hay que programarlo
//      # Hay que comprar la propiedad e intentar construir 5 casas
      juego.comprar();
      for (i=0; i<5; i++) {
        juego.construirCasa(0); //# Como solo tiene una propiedad, su índice es el cero
      }
      juego.construirHotel(0);
      juego.construirHotel(0);
//      # Si el juego está bien, este jugador solo tendrá 1 hotel, ya que la 5a casa no debe haberse
//      # edificado y el segundo hotel tampoco
      
//      # Cuanto más completa sea la información que metemos en el diario y la que muestran los métodos toString,
//      # más información tenemos en el momento de las pruebas para comprobar el correcto funcionamiento del software
      
//      # Aunque siempre podemos ver el estado de los objetos que queremos comprobar
      System.out.println (juego.getJugadorActual().toString());
      
//      # Una vez el primer jugador ha completado su turno con todas las operaciones que queríamos probar
//      # pasamos de turno
      juego.pasarTurno();
      
//      # Para el siguiente jugador, se pide simplemente que juegue, es decir, que avance
//      # Se anota su turno en el diario
//      # Se muestra su estado, para ver si ha pagado el alquiler. Debería haberlo hecho ya que 
//      # ha caído en la casilla de su oponente, y el pago del alquiler es algo que ocurre automáticamente
//      # al no requerir intervención expresa del usuario
      diario.ocurreEvento("Turno de " + juego.getJugadorActual().getNombre());
      juego.avanzaJugador();
      System.out.println (juego.getJugadorActual().toString());
      
//      # Acabamos comprobando el estado del primer jugador
      juego.pasarTurno();
      System.out.println (juego.getJugadorActual().toString());
            
//      # Por último, mostramos todo lo que se ha ido añadiendo al diario,
//      # Aunque esta operación puede hacerse en cualquier momento para leer el diario después de
//      # haber hecho alguna operación importante
      while (diario.eventosPendientes()) {
        System.out.println (diario.leerEvento());
      }

    }

    public static void main (String[] args) {
      pruebaHotelAlquiler();
    }
}
