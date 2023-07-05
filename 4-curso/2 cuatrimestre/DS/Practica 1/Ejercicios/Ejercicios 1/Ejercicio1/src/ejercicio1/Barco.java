/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1;

import java.util.ArrayList;

/**
 *
 *  @author Raúl Morgado y Elena Ortega, grupo DS-GP6
 */
public class Barco extends Thread{
    private Float probabilidad;
    private ArrayList<Pez> peces;  

    public Barco() {
        peces = new ArrayList();  
    }

    public Float getProbabilidad() {
        return probabilidad;
    }

    public void setProbabilidad(Float probabilidad) {
        this.probabilidad = probabilidad;
    }
    
    @Override
    public void run(){ //este método realiza todo el trabajo de la clase
        pescar();
    }
    
    
    /*
    Queremos que la funcionalidad principal del barco vaya aquí implementada. 
    Se crea la hebra y se ejecuta un bucle que pase por todos los peces 
    y ejecute el método serPescado
    */
    public void pescar(){
        //bucle que recorre la lista de todos los peces que haya,
        // cada pez ejecuta el serPescaqdo y si es pescado se añade al array
        // de peces de este barco, llamando a aniadirPEz
         
        //creamos hebra barco que hará run de esto:
        for ( Pez p : peces){
            p.start();//se ejecuta el serPescado de pez   
        }    
    }
    
    public void aniadirPez(Pez pez){
        //si se complica, metemos aquí el return de SerPescado
        peces.add(pez);
    }
    
}

class PesqueroGrande extends Barco{
    
    public PesqueroGrande() {
        super();
        setProbabilidad(0.6f);
    }

}

class PesqueroPequeño extends Barco{
    
    public PesqueroPequeño() {
        super();
        setProbabilidad(0.9f);
    }
}
