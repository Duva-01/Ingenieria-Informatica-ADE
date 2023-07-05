/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;
import java.util.Random;

public class Dado {
    
    
    static final private Dado instance = new Dado();
    
    private Random random;
    private int ultimoResultado;
    private boolean debug;
    
    Dado(){
        
        random = new Random();
        ultimoResultado = 0;
        debug = false; 
    }
    
    static Dado getInstance(){
        return instance;
    }
    
    public int tirar()
    {
        if(!debug)
            ultimoResultado = random.nextInt(5) + 1;
        else
            ultimoResultado = 1;
        return ultimoResultado;
    }
    
    public int quienEmpieza (int n){
        
        return random.nextInt(n);
    }

    public void setDebug (boolean d){

        debug = d;
        
        if(debug)
            Diario.getInstance().ocurreEvento("Se ha establecido el modo debug del dado.");
    
    }
    
    int getUltimoResultado()
    {
        return ultimoResultado;
    }
}
