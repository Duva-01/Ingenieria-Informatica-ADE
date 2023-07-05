package ejercicio1_s2;


import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
class TorreDeControl extends Observable{
    private ArrayList<CocheFormulaUno> coches; 
    
    TorreDeControl(){
        super();
        this.coches = null;
    }
  
    TorreDeControl(ArrayList<CocheFormulaUno> coches){
        super();
        this.coches = coches;
    }
    
    TorreDeControl(ArrayList<CocheFormulaUno> coches, ArrayList<Observer> observadores){
        super(observadores);
        this.coches = coches;
    }
    
    public ArrayList<CocheFormulaUno> getCoches(){
        return coches;
    }
    
    public void setTiempo(CocheFormulaUno coche) throws InterruptedException{
        
        coche.run(); 
        
        isChanged = true;
        //coche.sleep(1000);
        Notify();
    }
    
    public void setTiempo(CocheFormulaUno coche, Float tiempo){
        coche.setUltimoTiempo(tiempo);
        isChanged = true;
    }
        
}
