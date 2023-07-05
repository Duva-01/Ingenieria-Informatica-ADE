package civitas;
import java.util.ArrayList;
import java.lang.Comparable;

import java.lang.Float;

public class Jugador implements Comparable<Jugador> {

    protected static int CasaMax = 4;
    protected static int CasasPorHotel = 4;

    private int casillaActual;
    protected static int HotelesMax = 4;

    private String nombre;
    protected static float PasoPorSalida = 1000.00f;

    private boolean puedeComprar;
    private float saldo;
    private static float SaldoInicial = 7500.00f;

    private ArrayList<Casilla> propiedades;
    

    Jugador(String nombre)
    {
        this.nombre = nombre;
        this.casillaActual = 0;
        this.puedeComprar = false;
        
        this.saldo = SaldoInicial;
        propiedades = new ArrayList<>();

    }

    protected Jugador( Jugador otro)
    {
        
        this.nombre = otro.getNombre();
        this.casillaActual = otro.casillaActual;
        this.puedeComprar = otro.getPuedeComprar();
        
        this.saldo = otro.getSaldo();
        propiedades = otro.getPropiedades();

    }

    int cantidadCasasHoteles(){
        
        int total = 0;
        for(int i = 0; i < propiedades.size(); i++)
            total += propiedades.get(i).getNumCasas() + propiedades.get(i).getNumHoteles();
        
        return total;
    }

    public int compareTo(Jugador otro){

       if (saldo == otro.getSaldo()) {
 
            return 0;
        }
        else if (saldo < otro.getSaldo()) {
 
            return -1;
        }
        else return 1;
    }
   
    boolean comprar( Casilla titulo){

        boolean result = false;

        if(puedeComprar){

            float precio = titulo.getPrecioCompra();

            if(puedoGastar(precio)){

                result=titulo.comprar(this);
                propiedades.add(titulo);
                Diario.getInstance().ocurreEvento("El jugador " + nombre+ " compra la propiedad " + titulo);
                puedeComprar = false;
 
            }

            else{

                Diario.getInstance().ocurreEvento("El jugador" + nombre+ " no tiene saldo para comprar la propiedad "+titulo);
            }

        }

        return result;
    }

    boolean construirCasa(int ip) {

        boolean result = false;
        boolean existe = existeLaPropiedad(ip);

        if(existe){

            Casilla propiedad = propiedades.get(ip); 
            boolean puedoEdificar = puedoEdificarCasa(propiedad);
            float precioEdificar = propiedad.getPrecioEdificar();

  
            if(puedoEdificar){
                result = propiedad.construirCasa(this);
                Diario.getInstance().ocurreEvento("El jugador " + nombre + " contruye casa en la propiedad " + ip);


            }
            
        }
        

        System.out.println(propiedades.get(ip).toString() + " tiene " + propiedades.get(ip).getNumCasas() + " casas y tiene " + propiedades.get(ip).getNumHoteles() + " hoteles. \n");
        return result;

    }

    boolean construirHotel(int ip) {

        boolean result = false;

        if(existeLaPropiedad(ip)){

            Casilla propiedad = propiedades.get(ip);
            boolean puedoEdificarHotel = puedoEdificarHotel(propiedad);

            float precio = propiedad.getPrecioEdificar();
            
            if(puedoEdificarHotel){
                
                result = propiedad.construirHotel(this);
                propiedad.derruirCasas(CasasPorHotel, this);
                Diario.getInstance().ocurreEvento("El jugador "+nombre+ " construye hotel en la propiedad "+ip);
            
            
            }

        }
        
        System.out.println(propiedades.get(ip).toString() + " tiene " + propiedades.get(ip).getNumCasas() + " casas y tiene " + propiedades.get(ip).getNumHoteles() + " hoteles. \n");
        return result;
    }

    boolean enBancarrota(){
        
        if(saldo < 0)
            return true;
        else return false;
    }
    
    private boolean existeLaPropiedad(int ip)
    {
        if(propiedades.get(ip).esEsteElPropietario(this))
           return true;
        else return false;
    }
    
    private int getCasasMax(){
        
        return CasaMax;
    }
    
    int getCasasPorHotel(){
        
        return CasasPorHotel;
    }
    
    int getCasillaActual(){
        
        return casillaActual;
    }
    
    public int _getCasillaActual(){
        
        return casillaActual;
    }
    
    private int getHotelesMax(){
        
        return HotelesMax;
    }
    
    protected String getNombre(){
        
        return nombre;
    }
    
    private float getPremioPasoSalida(){
        
        return PasoPorSalida;
    }
    
    public ArrayList<Casilla> getPropiedades(){
        
        return propiedades;
    }
    
    boolean getPuedeComprar(){
        
        return puedeComprar;
    }
    
    protected float getSaldo(){
        
        return saldo;
    }
    
    boolean modificarSaldo(float cantidad){
        
        saldo += cantidad;
        return true;
    }
    
    boolean moverACasilla(int num_Casilla){
        
        casillaActual = num_Casilla;
        puedeComprar = false;
        Diario.getInstance().ocurreEvento("El jugador " + nombre + " ha caido en la casilla numero: " + num_Casilla);
        return true;
    }
    
    boolean paga(float cantidad) {
        
        return modificarSaldo(cantidad*(-1));
    }
    
    boolean pagaAlquiler(float cantidad){
        
        return paga(cantidad);
    }
    
    boolean pasaPorSalida(){
        
        recibe(PasoPorSalida);
        Diario.getInstance().ocurreEvento("El jugador " + nombre + " ha pasado por la salida.");
        return true;
    }
    
    boolean puedeComprarCasilla()
    {
        puedeComprar = true;
        return puedeComprar;
    }
    
    private boolean puedoEdificarCasa(Casilla propiedad) 
    {
        if(puedoGastar(propiedad.getPrecioEdificar()) && propiedad.getNumCasas() < CasasPorHotel)
            return true;
        else return false;
    }
    
    private boolean puedoEdificarHotel(Casilla propiedad){
        
        if(puedoGastar(propiedad.getPrecioEdificar()) && propiedad.getNumHoteles() < HotelesMax && propiedad.getNumCasas() == CasasPorHotel)
            return true;
        else return false;
    }
    
    private boolean puedoGastar( float precio){
        
        if(getSaldo() >= precio)
            return true;
        else return false;
    }
    
    boolean recibe(float cantidad){
        
        return modificarSaldo(cantidad);
    }
    
    boolean tieneAlgoQueGestionar(){
        
        if(propiedades.size() >= 1)
            return true;
        else return false;
    }
    
    public String toString() 
    {
        return ("Nombre: " +nombre+". Saldo: "+ saldo +". Posicion: "+ casillaActual + ". Num Propiedades: " + propiedades.size());
    }
    
}
