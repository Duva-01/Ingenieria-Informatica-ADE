/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1;

import java.util.Random;

/**
 *
 * @author Raúl Morgado y Elena Ortega, grupo DS-GP6
 */
public abstract class Pez extends Thread{ 
        // start() --> solo se llama 1 vez, arranque explícito de un hilo llamar run 
        // sleep(retardo en ms)
        // isAlive() --> true si no se ha parado con stop() ni ha terminado run()
    
    private Barco barcoAsignado;
    
    
    @Override
    public void run(){ //este método realiza todo el trabajo de la clase
        serPescado();
    }
    
    public Barco getBarcoAsignado() {
        return barcoAsignado;
    }
    
    public void asignarBarco(Barco b){
        this.barcoAsignado= b;
    }
   
    public boolean serPescado(){
        Random random = new Random();
        Float x = random.nextFloat();
        
        if (x < getBarcoAsignado().getProbabilidad()){
            //Consideramos que si es menor, es pescado
            return true;
        }else{
            return false;
        }
    }
    
}

class PezGrande extends Pez{
    @Override
    public boolean serPescado(){
        if (super.serPescado()){
            System.out.println("Soy un pez grande y he sido pescado --------- " + this.getId() );
            return true;
        }else{
            System.out.println("Soy un pez grande y NO he sido pescado----------- " + this.getId());
            return false;
        }
    }
}

class PezPequeño extends Pez{
    @Override
    public boolean serPescado(){
        if (super.serPescado()){
            System.out.println("Soy un pez pequeño y he sido pescado------------------- " + this.getId());
            return true;
        }else{
            System.out.println("Soy un pez pequeño y NO he sido pescado------------- " + this.getId());
            return false;
        }
    }
}