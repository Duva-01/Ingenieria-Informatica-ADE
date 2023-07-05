/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;
import java.util.ArrayList;
import java.util.*;
/**
 *
 * @author jlric
 */
public class MazoSorpresa {
    
    
    private ArrayList<Sorpresa> sorpresas = new ArrayList<Sorpresa>();
    
    private boolean barajada;
    private int usadas;
    private boolean debug;
    
    private void init ()
    {
        if(!sorpresas.isEmpty() )
            sorpresas.clear();
        
        barajada = false;
        usadas = 0;
        
    }

    MazoSorpresa(boolean d) 
    {
        init();
        debug = d;
        
        if(debug)
            Diario.getInstance().ocurreEvento("Se ha establecido el modo debug del MazoSorpresa.");
    }

    MazoSorpresa()
    {
        init();
        debug = false;
    }
    
    void alMazo (Sorpresa s)
    {
        if(!barajada)
            sorpresas.add(s);
    }
    
    
    Sorpresa siguiente ()
    {
        
        if(!barajada || usadas == sorpresas.size() )
        {
            if(!debug)
            {
                Collections.shuffle(sorpresas);//barajamos el arraylist
                usadas = 0;
                barajada = true;
            }
                
        }
        
        Sorpresa auxiliar = sorpresas.get(usadas);
        usadas++;
        

        return auxiliar;
    }
    
}
