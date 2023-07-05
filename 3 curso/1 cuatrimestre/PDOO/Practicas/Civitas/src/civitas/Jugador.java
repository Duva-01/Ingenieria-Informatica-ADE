package civitas;
import java.util.ArrayList;
import java.lang.Comparable;

import java.lang.Float;

public class Jugador implements Comparable<Jugador> {

    protected static final int CASASMAX = 4;
    protected static final int CASASPORHOTEL = 4;
    protected static final int HOTELESMAX = 4;
    
    private static final float SALDOINICIAL = 7500.00f;
    protected static final float PASOPORSALIDA = 1000.00f;
    
    private int casillaActual;

    private String nombre;

    protected boolean puedeComprar;
    private float saldo;
    

    protected ArrayList<CasillaCalle> propiedades;
    

    Jugador(String nombre)
    {
        this.nombre = nombre;
        this.casillaActual = 0;
        this.puedeComprar = false;
        
        this.saldo = SALDOINICIAL;
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

    int cantidadCasasHoteles()
    {
        
        int total = 0;
        for(int i = 0; i < propiedades.size(); i++)
            total += propiedades.get(i).getNumCasas() + propiedades.get(i).getNumHoteles();
        
        return total;
    }

    @Override
    public int compareTo(Jugador otro){

       if (saldo == otro.getSaldo()) {
 
            return 0;
        }
        else if (saldo < otro.getSaldo()) {
 
            return -1;
        }
        else return 1;
    }
   
    boolean comprar( CasillaCalle titulo){

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

            CasillaCalle propiedad = propiedades.get(ip); 
            boolean puedoEdificar = puedoEdificarCasa(propiedad);
            float precioEdificar = propiedad.getPrecioEdificar();

  
            if(puedoEdificar){
                result = propiedad.construirCasa(this);
                Diario.getInstance().ocurreEvento("El jugador " + nombre + " contruye casa en la propiedad " + ip);


            }
            
        }
        

        Diario.getInstance().ocurreEvento(propiedades.get(ip).toString() + " tiene " + propiedades.get(ip).getNumCasas() + " casas y tiene " + propiedades.get(ip).getNumHoteles() + " hoteles. \n");
        return result;

    }

    boolean construirHotel(int ip) {

        boolean result = false;

        if(existeLaPropiedad(ip)){

            CasillaCalle propiedad = propiedades.get(ip);
            boolean puedoEdificarHotel = puedoEdificarHotel(propiedad);

            float precio = propiedad.getPrecioEdificar();
            
            if(puedoEdificarHotel){
                
                result = propiedad.construirHotel(this);
                propiedad.derruirCasas(CASASPORHOTEL, this);
                Diario.getInstance().ocurreEvento("El jugador "+nombre+ " construye hotel en la propiedad "+ip);
            
            
            }

        }
        
        Diario.getInstance().ocurreEvento(propiedades.get(ip).toString() + " tiene " + propiedades.get(ip).getNumCasas() + " casas y tiene " + propiedades.get(ip).getNumHoteles() + " hoteles. \n");
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
    
    public int getCasasMax(){
        
        return CASASMAX;
    }
    
    int getCASASPORHOTEL(){
        
        return CASASPORHOTEL;
    }
    
    int getCasillaActual(){
        
        return casillaActual;
    }
    
    public int _getCasillaActual(){
        
        return casillaActual;
    }
    
    public int getHOTELESMAX(){
        
        return HOTELESMAX;
    }
    
    public String getNombre(){
        
        return nombre;
    }
    
    private float getPremioPasoSalida(){
        
        return PASOPORSALIDA;
    }
    
    public ArrayList<CasillaCalle> getPropiedades(){
        
        return propiedades;
    }
    
    boolean getPuedeComprar(){
        
        return puedeComprar;
    }
    
    public float getSaldo(){
        
        return saldo;
    }
    
    float modificarSaldo(float cantidad){
        
        saldo += cantidad;
        Diario.getInstance().ocurreEvento("El jugador " + nombre + " se le modifica el saldo en "+cantidad);
        return cantidad;
    }
    
    boolean moverACasilla(int num_Casilla){
        
        casillaActual = num_Casilla;
        puedeComprar = false;
        Diario.getInstance().ocurreEvento("El jugador " + nombre + " ha caido en la casilla numero: " + num_Casilla);
        return true;
    }
    
    float paga(float cantidad) {
        
        return modificarSaldo(cantidad*(-1));
    }
    
    float pagaAlquiler(float cantidad){
        
        return paga(cantidad);
    }
    
    boolean pasaPorSalida(){
        
        recibe(PASOPORSALIDA);
        
        Diario.getInstance().ocurreEvento("El jugador " + nombre + " ha pasado por la salida.");
        Diario.getInstance().leerEvento();
        
        Diario.getInstance().ocurreEvento("--> El jugador " + nombre + " ha pasado por la salida.");
        return true;
    }
    
    boolean puedeComprarCasilla()
    {
        puedeComprar = true;
        return puedeComprar;
    }
    
    private boolean puedoEdificarCasa(CasillaCalle propiedad) 
    {
        if(puedoGastar(propiedad.getPrecioEdificar()) && propiedad.getNumCasas() < CASASPORHOTEL)
            return true;
        else return false;
    }
    
    private boolean puedoEdificarHotel(CasillaCalle propiedad){
        
        if(puedoGastar(propiedad.getPrecioEdificar()) && propiedad.getNumHoteles() < HOTELESMAX && propiedad.getNumCasas() == CASASPORHOTEL)
            return true;
        else return false;
    }
    
    protected boolean puedoGastar( float precio){
        
        if(getSaldo() >= precio)
            return true;
        else return false;
    }
    
    float recibe(float cantidad){
        
        return modificarSaldo(cantidad);
    }
    
    boolean tieneAlgoQueGestionar(){
        
        if(propiedades.size() >= 1)
            return true;
        else return false;
    }
    
    protected JugadorEspeculador convertir(){
        
        Diario.getInstance().ocurreEvento("El jugador " + nombre + " se ha convertido en especulador.");
        return new JugadorEspeculador(this); 
    }
    
    public boolean esEspeculador(){
        return false;
    }
    
    @Override
    public String toString() 
    {
        return ("Nombre: " +nombre+". Saldo: "+ saldo +". Posicion: "+ casillaActual + ". Num Propiedades: " + propiedades.size());
    }
    
}
