/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;


public class Casilla {
    
    // Variables
    
    private Jugador propietario;
    private Sorpresa sorpresa;
    
    private TipoCasilla tipo;
    private String nombre;
    private float precioCompra, precioEdificar, precioBaseAlquiler;
    private int numCasas, numHoteles;
    
    private static float FACTORALQUILERCALLE = 1.0f, FACTORALQUILERCASA = 1.0f, FACTORALQUILERHOTEL = 4.0f;
  
    private MazoSorpresa mazo;
    private TituloPropiedad titulo;
    
    private Barrio barrio;
    
    // Constructores
    private void init(){
        
        propietario = new Jugador("");
        sorpresa = new Sorpresa(TipoSorpresa.COBRAR, "", 0);

        tipo = TipoCasilla.DESCANSO;
        nombre = "";

        precioCompra = 0;
        precioEdificar = 0;
        precioBaseAlquiler = 0;

        numCasas = 0;
        numHoteles = 0;

        mazo = new MazoSorpresa();

    }

    Casilla(TipoCasilla t, String n, float precio_Compra, float precio_Edificar, float precio_Base_alquiler, Barrio barrio){
        
        tipo = t;
        nombre = n;
        precioCompra = precio_Compra;
        precioEdificar = precio_Edificar;
        precioBaseAlquiler = precio_Base_alquiler;
        numCasas = 0;
        numHoteles = 0;
        this.barrio = barrio;
        
        this.barrio.addPropiedad(this);
    }
    
    Casilla(TipoCasilla t, String nombre, MazoSorpresa mazo){
        
        tipo = t;
        this.nombre = nombre;
        this.mazo = mazo;
        precioCompra = 0;
        precioEdificar = 0;
        precioBaseAlquiler = 0;
        numCasas = 0;
        numHoteles = 0;
        barrio = null;
    }
    
    Casilla(TipoCasilla t, String nombre){
        
        tipo = t;
        this.nombre = nombre;
        precioCompra = 0;
        precioEdificar = 0;
        precioBaseAlquiler = 0;
        numCasas = 0;
        numHoteles = 0;
        barrio = null;
    }

    
    //--------------------------------------------------------------//
    
    // Acciones del jugador
    
    boolean comprar(Jugador jugador){
        
        propietario = jugador;
        jugador.paga(getPrecioCompra());
        return true;
    }
    
    boolean construirCasa(Jugador jugador){
        jugador.paga(precioEdificar);
        numCasas++;
        return true;
    }
    
    boolean construirHotel(Jugador jugador){
        
        propietario.paga(precioEdificar);
        numHoteles++;
        return true;
    }
    
    boolean derruirCasas(int numero, Jugador jugador){
        
        if(this.esEsteElPropietario(jugador) && numCasas >= numero){
            numCasas = numCasas - numero;
            return true;
        }
        else return false;

    }
    
    public boolean esEsteElPropietario(Jugador jugador){
        
        if(jugador == propietario)
            return true;
        else return false;
    }
    
    //--------------------------------------------------------------//

    //Consultores
    
    public int cantidadCasasHoteles(){
        
        return (numCasas + numHoteles);
    }
    String getNombre(){
        return nombre;
    }
    
    float getPrecioCompra(){
        return precioCompra;
    }
    
    float getPrecioEdificar(){
        return precioEdificar;
    }
    
    int getNumCasas(){
        return numCasas;
    }
    
    int getNumHoteles(){
        return numHoteles;
    }
    
    float getPrecioAlquilerCompleto(){
        
        return (precioBaseAlquiler *(FACTORALQUILERCASA + numCasas+ numHoteles*FACTORALQUILERHOTEL));
    }
    

    //--------------------------------------------------------------//

    void informe(int i_actual, ArrayList<Jugador> todos){
        
        Diario.getInstance().ocurreEvento("El jugador " + todos.get(i_actual).getNombre() + " ha caido en la casilla: " + this.toString());
    }
    
    void recibeJugador(int i_actual, ArrayList<Jugador> todos){
        
        Jugador aux = todos.get(i_actual);

        switch (tipo) {
            case CALLE:
                
                recibeJugador_calle(i_actual, todos);
                break;

            case SORPRESA:
                
                recibeJugador_sorpresa(i_actual, todos);
                break;
            
            case DESCANSO:
                
                informe(i_actual, todos);
                break;
        
            default:
                break;
        }
    }
    
    private void recibeJugador_calle(int i_actual, ArrayList<Jugador> todos){
        
        informe(i_actual, todos);
        Jugador aux = todos.get(i_actual);

        if(!tienePropietario() && aux.puedeComprarCasilla()){
            
        }
        else {
            
            
            tramitarAlquiler(aux);
        }
    }
    
    private void recibeJugador_sorpresa(int i_actual, ArrayList<Jugador> todos){
        
        sorpresa = mazo.siguiente();
        informe(i_actual, todos);
        sorpresa.aplicarAJugador(i_actual, todos);      
    }
    
    public boolean tienePropietario(){
        
        if(propietario != null)
            return true;
        else return false;
    }
    
    public void tramitarAlquiler(Jugador jugador){
        
        if(!esEsteElPropietario(jugador) && this.tienePropietario()){
            
            float precio = this.getPrecioAlquilerCompleto();
            System.out.println("El propietario de la propiedad es: " + this.propietario.getNombre() + " y " + jugador.getNombre() + " tiene que pagar: " + precio);
            jugador.modificarSaldo(precio*-1);
            this.propietario.modificarSaldo(precio);
           
        }
    }
    
    public boolean igualdadIdentidad (Casilla otraCasilla){
        
        if(this == otraCasilla)
            return true;
        else return false;
    }
    
    boolean igualdadEstado (Casilla otraCasilla){
        
        if(this == otraCasilla){
            return true;
        }
        else{
            
            
            if(nombre.equals(otraCasilla.getNombre()) && precioCompra == otraCasilla.getPrecioCompra() 
           && precioEdificar == otraCasilla.getPrecioEdificar() && this.getPrecioAlquilerCompleto() == otraCasilla.getPrecioAlquilerCompleto()
           && numCasas == otraCasilla.getNumCasas() && numHoteles == getNumHoteles()){
            
                return true;
        }
        
            else return false;
        }
    }
    
    @Override
    public String toString(){
        
        if(this.tipo == TipoCasilla.CALLE){
            
            if (propietario == null)
                return (tipo + " " + nombre + ". Barrio: " + this.barrio.getNombre() + ". Precios: Compra: " + precioCompra + ", Edificar: " + precioEdificar + ", Alquiler base: " + precioBaseAlquiler + ", Alquiler Completo: " + getPrecioAlquilerCompleto() +", Casas: " + numCasas + ", Hoteles: " + numHoteles );
            
            else return  (("La casilla : ")+this.nombre + " en el barrio " + this.barrio.getNombre() + (" con el propietario " + propietario.getNombre()));
        }
        
        if (this.tipo == TipoCasilla.SORPRESA){
            return ("Casilla de tipo sorpresa");
        }
        else return ("Casilla de tipo descanso");
        
    }

    public Barrio getBarrio(){
        return barrio;
    }
    
    public TituloPropiedad getTitulo(){
        return titulo;
    }
    
    public TipoCasilla getTipo(){
        return tipo;
    }
}

    

