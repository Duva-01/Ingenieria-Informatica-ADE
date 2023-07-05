package vistaTextualCivitas;

import civitas.Casilla;
import civitas.CivitasJuego;
import civitas.Diario;
import civitas.OperacionJuego;
import controladorCivitas.Respuesta;
import civitas.OperacionInmobiliaria;
import civitas.Jugador;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;



public class VistaTextual implements Vista {
  
    
  private static String separador = "=====================";
  
  private Scanner in;
  
  CivitasJuego juegoModel;
  
  public VistaTextual (CivitasJuego juegoModel) {
    in = new Scanner (System.in);
    this.juegoModel=juegoModel;
  }
  
  
           
 public  void pausa() {
    System.out.print ("\nPulsa una tecla");
    in.nextLine();
  }

  int leeEntero (int max, String msg1, String msg2) {
    Boolean ok;
    String cadena;
    int numero = -1;
    do {
      System.out.print (msg1);
      cadena = in.nextLine();
      try {  
        numero = Integer.parseInt(cadena);
        ok = true;
      } catch (NumberFormatException e) { // No se ha introducido un entero
        System.out.println (msg2);
        ok = false;  
      }
      if (ok && (numero < 0 || numero >= max)) {
        System.out.println (msg2);
        ok = false;
      }
    } while (!ok);

    return numero;
  }

  int menu (String titulo, ArrayList<String> lista) {
    String tab = "  ";
    int opcion;
    System.out.println (titulo);
    for (int i = 0; i < lista.size(); i++) {
      System.out.println (tab+i+"-"+lista.get(i));
    }

    opcion = leeEntero(lista.size(),
                          "\n"+tab+"Elige una opción: ",
                          tab+"Valor erróneo");
    return opcion;
  }

  @Override
  public void actualiza() {

    System.out.println (juegoModel.getJugadorActual().toString());

    if(juegoModel.finalDelJuego()){
      ArrayList<Jugador> jugadores = juegoModel._ranking();
      System.out.println ("Juego terminado: Ranking de Jugadores");

      for(int i=0; i<jugadores.size(); i++)
        System.out.println (i+1 + ". " + jugadores.get(i).toString());

    }
    
  }

  public Respuesta comprar(){
      
    int n_casilla = juegoModel.getJugadorActual()._getCasillaActual();
    Casilla casilla = juegoModel.getTablero().getCasilla(n_casilla);
    
    ArrayList<String> estado_inmuebles = casilla.getBarrio().getEstadoInmuebles();
    
    System.out.println ("\n Estado de las propiedades en el barrio: " + casilla.getBarrio().getNombre() + "\n");
    
    for(int n=0; n<estado_inmuebles.size(); n++)
        System.out.println (estado_inmuebles.get(n));
    
    String titulo = "\n ¿Desea comprar la calle?";
    ArrayList<String> opciones = new ArrayList<String>();
    opciones.add("NO");
    opciones.add("SI");

    int opcion = menu(titulo, opciones);
    Respuesta seleccion;

    if(opcion == 1)
      seleccion=Respuesta.SI;
    else seleccion=Respuesta.NO;

    return seleccion;
  }

  public OperacionInmobiliaria elegirOperacion()
  {
    String titulo = "¿Que numero de gestion inmobiliaria ha escogido?";
    ArrayList<String> opciones = new ArrayList<String>();
    opciones.add("CONSTRUIR_CASA ");
    opciones.add("CONSTRUIR_HOTEL ");
    opciones.add("TERMINAR");

    int opcion = menu(titulo, opciones);
    
    return OperacionInmobiliaria.values()[opcion];
  }

  public int elegirPropiedad(){
    
    int indicePropiedad = 0;

    String titulo = "Elige una propiedad: ";
    ArrayList<Casilla> propiedades = juegoModel.getJugadorActual().getPropiedades();

    ArrayList<String> opciones = new ArrayList<>(); 

    for(int i=0; i<propiedades.size(); i++)
      opciones.add(propiedades.get(i).toString());
    
    int opcion = menu(titulo, opciones);

    return opcion;
  }

  public void mostrarSiguienteOperacion(OperacionJuego operacion)
  {
    System.out.println(operacion);
  }

  public void mostrarEventos(){

    while(Diario.getInstance().eventosPendientes()){
      Diario.getInstance().leerEvento();
    }
    
  }
  
  public void mostrarEstado(){
    if(!juegoModel.finalDelJuego())
    {
      String nombre = juegoModel.getJugadorActual().toString();
      int casilla_actual = juegoModel.getJugadorActual()._getCasillaActual();
      System.out.println("Estado actual:");
      System.out.println(nombre);
      System.out.println("Casilla: " + casilla_actual);

      
    }
    else {

      ArrayList<Jugador> jugadores = juegoModel._ranking();
      System.out.println ("Juego terminado: Ranking de Jugadores");

      for(int i=0; i<jugadores.size(); i++)
        System.out.println (i+1 + ". " + jugadores.get(i).toString());
      
      
    }
    
  }
  
  public Respuesta _comprar(){
      
      int njug = juegoModel.getIndiceJugadorActual();
      Jugador jugadorActual = juegoModel.getJugadores().get(njug);
      
      int numCasillas = jugadorActual._getCasillaActual();
      civitas.Tablero tablero = juegoModel.getTablero();
      
      ArrayList<civitas.Casilla> casillas = tablero.getTodasCasillas();
      civitas.Casilla casilla = casillas.get(numCasillas);
      
      civitas.TituloPropiedad titulo = casilla.getTitulo();
      civitas.Barrio barrio = titulo.getBarrio();
      
      ArrayList<String> estados = barrio.getEstadoInmuebles();
      
      
      
      return null;
  }
  
}
