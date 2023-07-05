/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;
import java.util.ArrayList;
/**
 *
 * @author Usuario
 */
public class Tablero {
    
    private ArrayList<Casilla> tablero;
    private boolean porSalida;
    
    private ArrayList<Barrio> barrios;
    
    static private Tablero instance = new Tablero();
    
    private boolean correcto(int numCasilla){
        
        if(numCasilla > 0 && numCasilla <= tablero.size())
            return true;
        else return false;
    }
    
    public Tablero(){
        
        tablero = new ArrayList<>();
        porSalida = false;
        
        Barrio barrio = new Barrio();
        Casilla salida = new Casilla(TipoCasilla.DESCANSO, "Salida", 0, 0, 0, barrio);
        
        tablero.add(salida);
    }
    
    boolean computarPasoPorSalida (){
        
        boolean aux = porSalida;
        porSalida = false;
        
        return aux;
    }
    
    void añadeCasilla (Casilla casilla){
        
        tablero.add(casilla);
    }
    
    public Casilla getCasilla (int numCasilla){
        
        if(tablero.get(numCasilla) != null)
            return tablero.get(numCasilla);
        else return null;
    }
    
    public ArrayList<Casilla> getTodasCasillas(){
        return tablero;
    }
    
    int nuevaPosicion (int actual, int tirada){
        
        int nueva_pos;
        
        if((actual+tirada) >= tablero.size()){
            
            porSalida=true;
            nueva_pos = (actual+tirada) % tablero.size();
            return nueva_pos;
        }
        
        else {
            nueva_pos = actual+tirada;
            return nueva_pos;
        }
        
    }
    
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    
    void añadeBarrio(Barrio barrio){
        barrios.add(barrio);
    }
    
    public ArrayList<TituloPropiedad> getInmueblesEnBarrio(Barrio barrio){
        
        for(int i=0; i<Tablero.getInstance().getTodasCasillas().size(); i++){
            
            Casilla unaCasilla = Tablero.getInstance().getCasilla(i);
            TipoCasilla tipo = unaCasilla.getTipo();
            
            if(tipo == TipoCasilla.CALLE){
                
                TituloPropiedad unTitulo = unaCasilla.getTitulo();
                Barrio unBarrio = unaCasilla.getBarrio();
                unBarrio.addPropiedad(unTitulo);
            }
        }
        
        
    }
    
    static public Tablero getInstance() {
        return instance;
    }
    
    static public void setInstance() {
        
        if(instance == null)
            instance = new Tablero();
        
    }
    
}
