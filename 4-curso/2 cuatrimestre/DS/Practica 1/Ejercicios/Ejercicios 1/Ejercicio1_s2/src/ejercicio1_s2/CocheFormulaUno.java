package ejercicio1_s2;


import static java.lang.Float.compare;
import java.util.ArrayList;
import java.util.Random;
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
public class CocheFormulaUno extends Thread implements Comparable<CocheFormulaUno>{
    private int numero;
    private Float UltimoTiempo;
    private TorreDeControl torre;
    private ArrayList<Pieza> piezas;


    public CocheFormulaUno(int numero) {
        this.numero = numero;
        this.UltimoTiempo = 0f;
        this.torre = null;
    }   
    
    @Override
    public void run(){
        if (isAlive()){
            System.out.println("Inicio run, hebra IS ALIVE -- TRUE");
        }else
            System.out.println("Inicio run, hebra IS ALIVE -- FALSE");
        
        try {
            correr();
        } catch (InterruptedException ex) {
            Logger.getLogger(CocheFormulaUno.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public int getNumero() {
        return numero;
    }

    public Float getUltimoTiempo() {
        return UltimoTiempo;
    }
    
    public void setUltimoTiempo(Float tiempo){
        //actuliza ult_tiempo
        UltimoTiempo = UltimoTiempo + tiempo;
    }

    public void correr()throws InterruptedException{
        //actuliza ult_tiempo
        sleep(1000);
        Random random = new Random();
        Float nuevo_tiempo = random.nextFloat();
        setUltimoTiempo(UltimoTiempo + nuevo_tiempo);
    }
    public void setTorre(TorreDeControl torre){
        this.torre = torre;
    }
    
    
    //0 si saldos iguales
    //negativo (-1) si this.saldo  es menor a otro.saldo
    //positivo (1)  si this.saldo  es mayor a otro.saldo
    @Override
    public int compareTo(CocheFormulaUno otro){
        return compare(this.UltimoTiempo, otro.UltimoTiempo); //Ordena de menor a mayor
    }
    
}
