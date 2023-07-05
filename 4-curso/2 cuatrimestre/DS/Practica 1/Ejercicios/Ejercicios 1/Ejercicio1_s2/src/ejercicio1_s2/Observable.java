package ejercicio1_s2;

import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
public abstract class Observable{
    
    private ArrayList<Observer> observadores;
    boolean isChanged; //informa de si ha habido cambios en los tiempos
    
    public Observable() {
        this.observadores = new ArrayList<>();
        this.isChanged = true;
    }
    
    public Observable(ArrayList<Observer> observadores) {
        this.observadores = observadores;
        this.isChanged = true;
    }
    
    public void attach(Observer observer){
        observadores.add(observer);
    }
    
    public void dettach(Observer observer){
        observadores.remove(observer);
    }
    
    public void Notify(){
        System.out.println("holaaa");
        
        if (isChanged){
            for (Observer o : observadores){
                o.update();
            }
            isChanged = false;
        }
        
    }
    
    public void setChanged(){
        isChanged = true;
    }

    public ArrayList<Observer> getObservadores() {
        return observadores;
    }

    public void setObservadores(ArrayList<Observer> observadores) {
        this.observadores = observadores;
    }
    
    
}
