package civitas;

import GUI.CivitasView;
import java.util.ArrayList;
import GUI.CivitasView;
import GUI.vistaDado;
import java.util.Collections;
import java.util.Comparator;
import javax.swing.*; 

public class CivitasJuego {

    private int indiceJugadorActual;

    private Tablero tablero;
    private MazoSorpresa mazo;
    private GestorEstados gs = new GestorEstados();
    private EstadoJuego estado ;

    private ArrayList<Jugador> jugadores = new ArrayList<>();

    private vistaDado dado;

    public CivitasJuego(ArrayList<String> nombres, boolean debug)
    {
       
        for(int i=0;i<nombres.size();i++)
        {
            Jugador aux = new Jugador(nombres.get(i));
            jugadores.add(aux);
        }
        
        estado = gs.estadoInicial();
        
        vistaDado.createInstance(new JFrame());
                
        dado = vistaDado.getInstance(); 
        dado.setDebug(debug);
        
        indiceJugadorActual = dado.quienEmpieza(nombres.size());
        
        Diario.getInstance().ocurreEvento("Empezamos el juego: ¡Se lanza el dado!.");
        Diario.getInstance().ocurreEvento("El primero en empezar es " + jugadores.get(indiceJugadorActual).getNombre()+".\n");
        
        mazo = new MazoSorpresa(debug);
        
        tablero = new Tablero();
        this.inicializaTablero(mazo);
        
        this.InicializaMazoSorpresas();
    }
    
    public boolean construirCasa(int ip)
    {
       return  jugadores.get(indiceJugadorActual).construirCasa(ip);
    }
    
    public boolean construirHotel(int ip)
    {
        return  jugadores.get(indiceJugadorActual).construirHotel(ip);
    }

    private void contabilizarPasosPorSalida( Jugador JugadorActual)
    {
        if(tablero.computarPasoPorSalida())
            JugadorActual.pasaPorSalida();
        
        
    }

    public boolean finalDelJuego()
    {
        for(int i=0;i<jugadores.size();i++)
        {
            if(jugadores.get(i).enBancarrota())
                return true;
        }
        
        return false;
    }

    public int getIndiceJugadorActual()
    {
            return this.indiceJugadorActual;
    }

    public Jugador getJugadorActual()
    {
       return jugadores.get(indiceJugadorActual);
    }
    public ArrayList<Jugador> getJugadores()
    {
        return jugadores;
    }

    public Tablero getTablero()
    {
         return tablero;
    }
    
    
    private void InicializaMazoSorpresas()
    {
        
        mazo.alMazo(new SorpresaConvertirme ("Convertir jugador", 0, mazo));
        mazo.alMazo(new SorpresaPagarCobrar ("Paga al jugador de tu derecha 500",-500, mazo));
        mazo.alMazo(new SorpresaPagarCobrar ("Paga al jugador de tu izquierda 500",-500, mazo));
        mazo.alMazo(new SorpresaPagarCobrar ("Paga al jugador de en frente 500",-500, mazo));
        mazo.alMazo(new SorpresaPagarCobrar ("Cobra al jugador de tu derecha 500",500, mazo));
        mazo.alMazo(new SorpresaPagarCobrar ("Cobra al jugador de tu izquierda 500",500, mazo));
        mazo.alMazo(new SorpresaPagarCobrar ("Cobra al jugador de en frente 500",500, mazo));
        mazo.alMazo(new SorpresaCasaHotel ("Paga por tu primera casa 500",-500, mazo));
        mazo.alMazo(new SorpresaCasaHotel ("Paga por tu primer hotel 500",-500, mazo));
        mazo.alMazo( new SorpresaCasaHotel ("Cobra por tu primera casa 500",500, mazo));
        mazo.alMazo(new SorpresaCasaHotel ("Cobra por tu primer hotel 500",500, mazo));
    }
    
   
    private void inicializaTablero(MazoSorpresa mazo){   
        
            //Añadimos la casilla de salida la primera
            //tablero.añadeCasilla(new Casilla(TipoCasilla.DESCANSO, "Salida"));

            //Añadimos las 14 calles, las sorpresas y el parking
            tablero.añadeCasilla(new CasillaCalle("Calle jhonny", 1500, 500, 50));
            tablero.añadeCasilla(new CasillaCalle( "Calle Guatemala", 2000, 200, 30));
            tablero.añadeCasilla(new CasillaCalle( "Calle Grumete loco", 3000, 350, 45));
            tablero.añadeCasilla(new CasillaSorpresa("Sorpresa1",mazo) );
            tablero.añadeCasilla(new CasillaCalle( "Calle Capitan Chickens", 4000, 400, 40));
            tablero.añadeCasilla(new CasillaCalle( "Calle gloria de Fenix", 5000, 222, 44));
            tablero.añadeCasilla(new CasillaSorpresa("Sorpresa",mazo) );
            tablero.añadeCasilla(new CasillaCalle( "Calle Cloaca ninja", 3000, 100, 25));
            tablero.añadeCasilla(new CasillaCalle( "Calle lozano melosa", 1000, 100, 10));
            tablero.añadeCasilla(new Casilla("Parking"));
            tablero.añadeCasilla(new CasillaCalle( "Calle Palomil", 4200, 320, 21));
            tablero.añadeCasilla(new CasillaCalle( "Calle rioo bravoo", 3400, 220, 40));  
            tablero.añadeCasilla(new CasillaSorpresa("Sorpresa2",mazo) );
            tablero.añadeCasilla(new CasillaCalle( "Avenida patin piti", 3200, 400, 200));
            tablero.añadeCasilla(new CasillaCalle( "Rotonda los gansos", 5300, 500, 120));
            tablero.añadeCasilla(new CasillaSorpresa("Sorpresa3",mazo) );
            tablero.añadeCasilla(new CasillaCalle( "Calle resurgir del fenix", 2600, 200, 54));
            tablero.añadeCasilla(new CasillaCalle( "Calle rosas", 3500, 320, 33));
            tablero.añadeCasilla(new CasillaCalle( "Calle Sprinter", 2000, 400, 200));
            
            //Añadimos el parking
            
    }

    public void pasarTurno()
    {
        if(indiceJugadorActual == jugadores.size()-1)
            indiceJugadorActual = 0;
        else indiceJugadorActual++;
    }
    
    Comparator<Jugador> comparar=new Comparator<Jugador>(){
        @Override
        public int compare(Jugador uno,Jugador otro){
            
            return uno.compareTo(otro);
        }
    };
     
    private ArrayList<Jugador> ranking(){
        
        
        Collections.sort(jugadores,comparar);
        Collections.sort(jugadores, Collections.reverseOrder());
        
        
        return jugadores;
    }
    
    public ArrayList<Jugador> _ranking()
    {
        return ranking();
    }

    public void siguientePasoCompletado(OperacionJuego operacion)
    {
            estado = gs.siguienteEstado(jugadores.get(indiceJugadorActual), estado, operacion);
    }

    public void avanzaJugador()
    {
        Jugador jugadorActual = this.getJugadorActual();
        
        int posicionActual = jugadorActual.getCasillaActual();
        
        Diario.getInstance().ocurreEvento("\n" + jugadorActual.getNombre() + " lanza el dado.");
        
        int tirada = dado.getInstance().tirar();
        int posicionNueva = tablero.nuevaPosicion(posicionActual, tirada);
        
        Casilla casilla = tablero.getCasilla(posicionNueva);
        
        Diario.getInstance().ocurreEvento("Ha salido el numero: " + tirada);
        Diario.getInstance().ocurreEvento("Ha caido en la casilla: " + casilla.getNombre());
        
        this.contabilizarPasosPorSalida(jugadorActual);

        jugadorActual.moverACasilla(posicionNueva);

        casilla.recibeJugador(indiceJugadorActual,jugadores);
    }

    public OperacionJuego siguientePaso()
    {
        Jugador jugadorActual = this.getJugadorActual();
        OperacionJuego operacion = gs.siguienteOperacion(jugadorActual, estado);
    
        if(operacion == OperacionJuego.PASAR_TURNO)
        {
            this.pasarTurno();
            this.siguientePasoCompletado(operacion);

        }
        else if(operacion == OperacionJuego.AVANZAR)
        {
            this.avanzaJugador();
            this.siguientePasoCompletado(operacion);
        }

        return operacion;
    }

    public boolean comprar()
    {
        boolean res;

        Jugador jugadorActual = this.getJugadorActual();

        int numCasillaActual = jugadorActual.getCasillaActual();

        CasillaCalle casilla = ( (CasillaCalle) tablero.getCasilla(numCasillaActual));

        res = jugadorActual.comprar(casilla);

        return res;
    }

}