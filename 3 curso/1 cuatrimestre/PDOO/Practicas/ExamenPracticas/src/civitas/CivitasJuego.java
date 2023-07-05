package civitas;

import static civitas.Tablero.getInstance;
import static civitas.Tablero.setInstance;
import java.util.ArrayList;

public class CivitasJuego {

    private int indiceJugadorActual;

    private Tablero tablero;
    private MazoSorpresa mazo;
    private GestorEstados gs = new GestorEstados();
    private EstadoJuego estado ;

    private ArrayList<Jugador> jugadores = new ArrayList<Jugador>();

    private Dado dado = new Dado();
    private OperacionJuego  operacion;

    public CivitasJuego(ArrayList<String> nombres, boolean debug)
    {
       
        for(int i=0;i<nombres.size();i++)
        {
            Jugador aux = new Jugador(nombres.get(i));
            jugadores.add(aux);
        }
        
        estado = gs.estadoInicial();
        
        dado.setDebug(debug);
        
        indiceJugadorActual = dado.quienEmpieza(nombres.size());
        
        System.out.println("Empezamos el juego: ¡Se lanza el dado!.");
        System.out.println("El primero en empezar es " + jugadores.get(indiceJugadorActual).getNombre()+".");
        
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
        mazo.alMazo(new Sorpresa (TipoSorpresa.PAGAR,"Paga al jugador de tu derecha 500",-500));

        
        mazo.alMazo(new Sorpresa (TipoSorpresa.PAGAR,"Paga al jugador de tu izquierda 500",-500));
        
    
        mazo.alMazo(new Sorpresa (TipoSorpresa.PAGAR,"Paga al jugador de en frente 500",-500));
        
      
        mazo.alMazo(new Sorpresa (TipoSorpresa.COBRAR,"Cobra al jugador de tu derecha 500",500));
        
   
        mazo.alMazo(new Sorpresa (TipoSorpresa.COBRAR,"Cobra al jugador de tu izquierda 500",500));
        
    
        mazo.alMazo(new Sorpresa (TipoSorpresa.COBRAR,"Cobra al jugador de en frente 500",500));
        
     
        mazo.alMazo(new Sorpresa (TipoSorpresa.PORCASAHOTEL,"Paga por tu primera casa 500",-500));
        
      
        mazo.alMazo(new Sorpresa (TipoSorpresa.PORCASAHOTEL,"Paga por tu primer hotel 500",-500));
        
  
        mazo.alMazo( new Sorpresa (TipoSorpresa.PORCASAHOTEL,"Cobra por tu primera casa 500",500));
        
    
        mazo.alMazo(new Sorpresa (TipoSorpresa.PORCASAHOTEL,"Cobra por tu primer hotel 500",500));
    }
    
   
    private void inicializaTablero(MazoSorpresa mazo)
    {       
            //Añadimos la casilla de salida la primera
            //tablero.añadeCasilla(new Casilla(TipoCasilla.DESCANSO, "Salida"));

            //Añadimos las 14 calles, las sorpresas y el parking
        
            Tablero.setInstance();
            tablero = Tablero.getInstance();
            
            ArrayList<Casilla> propiedades_barrio_1 = new ArrayList<>();
            ArrayList<Casilla> propiedades_barrio_2 = new ArrayList<>();
            ArrayList<Casilla> propiedades_barrio_3 = new ArrayList<>();
            ArrayList<Casilla> propiedades_barrio_4 = new ArrayList<>();
            ArrayList<Casilla> propiedades_barrio_5 = new ArrayList<>();
            
            Barrio almanjayar = new Barrio("Almajayar", TipoBarrio.CENTRO, 20, propiedades_barrio_1);
            Barrio realejo = new Barrio("Realejo", TipoBarrio.PERIFERIA, 30, propiedades_barrio_2);
            Barrio chana = new Barrio("Chana", TipoBarrio.PERIFERIA, 50, propiedades_barrio_3);
            Barrio suizo = new Barrio("Suizo", TipoBarrio.CENTRO, 10, propiedades_barrio_4);
            Barrio congresos = new Barrio("Congresos", TipoBarrio.CENTRO, 25, propiedades_barrio_5);
            
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle jhonny profundo", 1500, 500, 50, almanjayar));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle flores de guatemala", 2000, 200, 30, almanjayar));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle Grumete loco", 3000, 350, 45, almanjayar));
            
            tablero.añadeCasilla(new Casilla(TipoCasilla.SORPRESA, "Sorpresa1",mazo) );
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle Capitan Chickens", 4000, 400, 40, realejo));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle gloria de Fenix", 5000, 222, 44, realejo));
            tablero.añadeCasilla(new Casilla(TipoCasilla.SORPRESA, "Sorpresa",mazo) );            
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle Cloaca ninja", 3000, 100, 25, realejo));
            
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle lozano melosa", 1000, 100, 10, chana));
            tablero.añadeCasilla(new Casilla(TipoCasilla.DESCANSO, "Parking"));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle salon de palomas", 4200, 320, 21, chana));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle rioo bravoo", 3400, 220, 40, chana));  
            tablero.añadeCasilla(new Casilla(TipoCasilla.SORPRESA, "Sorpresa2",mazo) );
            
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Avenida patin piti", 3200, 400, 200, suizo));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Rotonda los gansos", 5300, 500, 120, suizo));
            tablero.añadeCasilla(new Casilla(TipoCasilla.SORPRESA, "Sorpresa3",mazo) );
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle resurgir del fenix", 2600, 200, 54, suizo));
            
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle rosas", 3500, 320, 33, congresos));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle Sprinter", 2000, 400, 200, congresos));
            tablero.añadeCasilla(new Casilla(TipoCasilla.CALLE, "Calle Santo Tomas de Villanueva", 2000, 400, 200, congresos));
            
            //Añadimos el parking
            
    }

    public void pasarTurno()
    {
        if(indiceJugadorActual == jugadores.size()-1)
            indiceJugadorActual = 0;
        else indiceJugadorActual++;
    }

    private ArrayList<Jugador> ranking()
    {
        ArrayList<Jugador> rank = new ArrayList<Jugador>(jugadores);
        
        int aux=0;//Almacenamos el numero de veces que es mayor que los otros valores
        
        
        for(int i=0;i<jugadores.size();i++)
        {
            for(int j=0;j<jugadores.size();j++)
            {
                if(jugadores.get(i).compareTo(jugadores.get(j)) == 1)
                    aux ++ ;
            }
            
            rank.set(jugadores.size() - (aux+1), jugadores.get(i));
            aux = 0;
        }
        
        return rank;
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
        
        System.out.println("\n" + jugadorActual.getNombre() + " lanza el dado.");
        
        int tirada = dado.getInstance().tirar();
        int posicionNueva = tablero.nuevaPosicion(posicionActual, tirada);
        
        Casilla casilla = tablero.getCasilla(posicionNueva);
        
        System.out.println("Ha salido el numero: " + tirada);
        System.out.println("Ha caido en la casilla: " + casilla.getNombre());
        
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

        Casilla casilla = tablero.getCasilla(numCasillaActual);

        res = jugadorActual.comprar(casilla);

        return res;
    }

}