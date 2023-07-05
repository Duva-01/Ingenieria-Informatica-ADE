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
    
    private boolean correcto(int numCasilla){
        
        if(numCasilla > 0 && numCasilla <= tablero.size())
            return true;
        else return false;
    }
    
    public Tablero(){
        
        tablero = new ArrayList<>();
        porSalida = false;
        
        Casilla salida = new Casilla("Salida");
        
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
    
}
