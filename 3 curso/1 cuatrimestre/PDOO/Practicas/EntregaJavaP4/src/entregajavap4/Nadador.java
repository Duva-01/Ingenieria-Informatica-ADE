/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entregajavap4;

public class Nadador extends Deportista{
    
    private String nombre;
    private int horas_entrenamiento;

    public Nadador(String nombre, int horas_entrenamiento) {
        super(nombre, horas_entrenamiento);
    }
    
    public void nadar(){
        System.out.println("Estoy nadando");
    }
    
    @Override
    public String toString(){

        return super.toString() + " y soy nadador.";
    }
}
