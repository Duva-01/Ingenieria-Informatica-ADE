/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entregajavap4;


public class Deportista extends Persona {
    
    private String nombre;
    private int horas_entrenamiento;
    
    public Deportista(String nombre, int horas_entrenamiento) {
        
        super(nombre);
        this.horas_entrenamiento = horas_entrenamiento;
        
    }
    
    public void competicion_deportiva(){
        System.out.println("He ido a una competicion deportiva y he entrenado " + horas_entrenamiento + " horas.");
    }
    
    @Override
    public String toString(){

        return super.toString() + " y soy deportista.";
    }
}
