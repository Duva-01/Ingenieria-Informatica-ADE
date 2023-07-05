package civitas;

import java.util.ArrayList;

public class CasillaSorpresa extends Casilla{
    
    private Sorpresa sorpresa;
    private MazoSorpresa mazo;

    CasillaSorpresa(String nombre, MazoSorpresa mazo){
        
        super(nombre);
        this.mazo = mazo;
        sorpresa = null;
        
    }
    
    @Override
    void recibeJugador(int i_actual, ArrayList<Jugador> todos){

        sorpresa = mazo.siguiente();
        informe(i_actual, todos);
        sorpresa.aplicarAJugador(i_actual, todos);      
    }
    
    
    boolean igualdadEstado (CasillaSorpresa otraCasilla){
        
        if(this == otraCasilla){
            return true;
        }
        else{
             
            if(sorpresa == otraCasilla.sorpresa && mazo == otraCasilla.mazo){
            
                return true;
        }
        
            else return false;
        }
    }

    @Override
    public String toString(){
        
        return super.toString() + " de tipo sorpresa";
    }
}
