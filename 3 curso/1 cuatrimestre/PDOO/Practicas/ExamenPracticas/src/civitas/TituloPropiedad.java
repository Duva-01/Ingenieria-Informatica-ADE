package civitas;


public class TituloPropiedad {
    
    private Barrio barrio;
    private Jugador propietario;
    
    public TituloPropiedad(Barrio barrio) {
        this.barrio = barrio;
        propietario = null;
    }
    
    public Barrio getBarrio(){
        return barrio;
    }
    
    public boolean tienePropietario(){
        
        if(propietario!=null)
            return true;
        else return false;
    }
}
