/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejerciciosjavap4;

/**
 *
 * @author Usuario
 */
public class Casilla {
    
    private String nombre;

    public Casilla(String nombre) {
        this.nombre = nombre;
    }
    
    boolean recibeJugador(){
        System.out.println("Ha recibido un jugador.");
        return true;
    }
    
    void setNombre(String aux){
        nombre = aux;
    }
    
    //--------------------------------------------------------------
    
    
}

