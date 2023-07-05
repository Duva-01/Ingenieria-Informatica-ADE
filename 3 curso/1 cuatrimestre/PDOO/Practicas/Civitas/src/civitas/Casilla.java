package civitas;

import java.util.ArrayList;


public class Casilla {
    
    private String nombre;
    
    protected Casilla(String nombre){

        this.nombre = nombre;
    }

    
    //--------------------------------------------------------------//

    //Consultores
    
    public String getNombre(){
        return nombre;
    }
   
    //--------------------------------------------------------------//

    void informe(int i_actual, ArrayList<Jugador> todos){
        
        Diario.getInstance().ocurreEvento("El jugador " + todos.get(i_actual).getNombre() + " ha caido en la casilla: " + this.toString());
    }
    
    void recibeJugador(int i_actual, ArrayList<Jugador> todos){

        informe(i_actual, todos);
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
            
            if(nombre.equals(otraCasilla.getNombre())){
            
                return true;
        }
        
            else return false;
        }
    }
    
    
    public String toString(){

        return "Casilla: " + nombre;
    }

    
}
