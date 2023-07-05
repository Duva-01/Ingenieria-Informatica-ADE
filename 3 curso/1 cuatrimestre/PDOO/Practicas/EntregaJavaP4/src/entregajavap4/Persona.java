/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entregajavap4;

public class Persona {
    
    private String nombre;

    public Persona(String nombre) {
        this.nombre = nombre;
    }
    
    public void andar(){
        System.out.println("Soy " + nombre + " y estoy andando.");
    }
    
    @Override
    public String toString(){

        return ("Soy una persona y mi nombre es " + nombre);
    }
}
