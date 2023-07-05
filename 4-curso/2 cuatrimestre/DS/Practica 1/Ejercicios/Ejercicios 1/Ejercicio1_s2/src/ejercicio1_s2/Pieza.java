/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1_s2;

import java.util.ArrayList;

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
public abstract class Pieza {
    
    private Float peso;
    
    public Pieza() {
        this.peso = 0f; 
    }
    
    public Pieza(Float peso) {
        this.peso = peso;
    }
    
    public void aniadirPieza(Pieza pieza){};
    
    public void quitarPieza(Pieza pieza){};
    
    public Pieza getPieza(int indice){
        return null;
    }
    
    public Float getPesoTotal(){
        return peso;
    }
    
}

class PiezaSimple extends Pieza{

    @Override
    public Float getPesoTotal(){
        return super.getPesoTotal();
    }
}

class PiezaCompuesta extends Pieza{
    
    private ArrayList<Pieza> piezas;
    
    public PiezaCompuesta() {
        super(); 
        piezas = new ArrayList<>();
    }

    public PiezaCompuesta(Float peso) {
        super(peso); 
        piezas = new ArrayList<>();
    }
    
    @Override
    public void aniadirPieza(Pieza pieza){
        piezas.add(pieza);
    }
    
    @Override
    public void quitarPieza(Pieza pieza){
        piezas.remove(pieza);
    }
    
    @Override
    public Pieza getPieza(int indice){
        return piezas.get(indice);
    }
    
    @Override
    public Float getPesoTotal(){
        Float total = 0f;
        for (Pieza p : piezas){
            total += p.getPesoTotal();
        }
        return total;
    }
}
