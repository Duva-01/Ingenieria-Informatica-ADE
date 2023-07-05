package civitas;

import java.util.ArrayList;

public class CasillaCalle extends Casilla {
    
    private float precioCompra, precioEdificar, precioBaseAlquiler;
    private int numCasas, numHoteles;

    private static final float FACTORALQUILERCALLE = 1.0f, FACTORALQUILERCASA = 1.0f, FACTORALQUILERHOTEL = 4.0f;
    private Jugador propietario;

    CasillaCalle(String n, float precio_Compra, float precio_Edificar, float precio_Base_alquiler){
        
        super(n);
        
        propietario = null;
        precioCompra = precio_Compra;
        precioEdificar = precio_Edificar;
        precioBaseAlquiler = precio_Base_alquiler;
        numCasas = 0;
        numHoteles = 0;
    }


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

    public int cantidadCasasHoteles(){
        
        return (numCasas + numHoteles);
    }

    public float getPrecioCompra(){
        return precioCompra;
    }
    
    public float getPrecioEdificar(){
        return precioEdificar;
    }
    
    public int getNumCasas(){
        return numCasas;
    }
    
    public int getNumHoteles(){
        return numHoteles;
    }
    
    float getPrecioAlquilerCompleto(){
        
        return (precioBaseAlquiler *(FACTORALQUILERCASA + numCasas+ numHoteles*FACTORALQUILERHOTEL));
    }
    @Override
    void recibeJugador(int i_actual, ArrayList<Jugador> todos){

        informe(i_actual, todos);
        Jugador aux = todos.get(i_actual);

        
        if(!this.tienePropietario()){
            aux.puedeComprarCasilla();
        }
        else{
            tramitarAlquiler(aux);
        }

    }

    public boolean tienePropietario(){
        
        if(propietario != null)
            return true;
        else return false;
    }
    
    public void tramitarAlquiler(Jugador jugador){
        
        if(!esEsteElPropietario(jugador) && this.tienePropietario()){
            
            float precio = this.getPrecioAlquilerCompleto();
            System.out.println("El propietario de la propiedad es: " + this.propietario.getNombre() + " y " + jugador.getNombre() + " tiene que pagar: " + precio + " a no ser que sea especulador.");
            
            
            float nuevo_precio = jugador.paga(precio);
            this.propietario.modificarSaldo(nuevo_precio*(-1));
           
        }
    }

    boolean igualdadEstado (CasillaCalle otraCasilla){

        if(this == otraCasilla){
            return true;
        }
        else{
            
            
            if(this.getNombre().equals(otraCasilla.getNombre()) && precioCompra == otraCasilla.getPrecioCompra() 
           && precioEdificar == otraCasilla.getPrecioEdificar() && this.getPrecioAlquilerCompleto() == otraCasilla.getPrecioAlquilerCompleto()
           && numCasas == otraCasilla.getNumCasas() && numHoteles == getNumHoteles()){
            
                return true;
        }
        
            else return false;
        }
    }
    
    public void actualizaPropietarioPorConversion(Jugador nuevo)
    {
        this.propietario = nuevo;
    }

    @Override
    public String toString(){

        if (propietario == null)
            return super.toString() + (". Precios: Compra: " + precioCompra + ", Edificar: " + precioEdificar + ", Alquiler base: " + precioBaseAlquiler + ", Alquiler Completo: " + getPrecioAlquilerCompleto() +", Casas: " + numCasas + ", Hoteles: " + numHoteles );
        else return  super.toString() + (" con el propietario " + propietario.getNombre());

    }
}
