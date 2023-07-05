/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

/**
 *
 * @author jlric
 */
public class JugadorEspeculador extends Jugador
{
    private static final int FACTORESPECULADOR = 2;
    
    protected JugadorEspeculador(String nombre)
    {
        super(nombre);
    }
            
    protected JugadorEspeculador(Jugador otro)
    {
        super(otro);
        actualizaPropiedadesPorConversion(this);
        
    }
    
    @Override  
    public int getHOTELESMAX(){
        
        return HOTELESMAX*FACTORESPECULADOR;
    }
    
    @Override    
    public int getCasasMax(){
        
        return CASASMAX*FACTORESPECULADOR;
    }
    
    @Override
    float paga(float cantidad) {
        
        return modificarSaldo((cantidad/FACTORESPECULADOR)*(-1));
    }
    
    public void actualizaPropiedadesPorConversion(Jugador jugador)
    {
        for(int i=0;i<propiedades.size();i++)
            propiedades.get(i).actualizaPropietarioPorConversion(jugador);
    }
    
    @Override    
    boolean comprar( CasillaCalle titulo){

        boolean result = false;

        if(getPuedeComprar()){

            float precio = titulo.getPrecioCompra();

            if(super.puedoGastar(precio)){

                result=titulo.comprar(this);
                propiedades.add(titulo);
                Diario.getInstance().ocurreEvento("El jugador " + getNombre()+ ", jugador especulador compra la propiedad " + titulo);
                super.puedeComprar = false;
 
            }

            else{

                Diario.getInstance().ocurreEvento("El jugador" + getNombre()+ ", jugador especulador no tiene saldo para comprar la propiedad "+titulo);
            }

        }

        return result;
    }
    
    @Override
    protected JugadorEspeculador convertir()
    {
        
        Diario.getInstance().ocurreEvento("El jugador " + getNombre() + " ya es un especulador.");
        return null;
        
        
    }
    
    @Override
    public boolean esEspeculador(){
        return true;
    }
    
    @Override
    public String toString() 
    {
        return (super.toString() + " Es un jugador especulador.");
    }
}
