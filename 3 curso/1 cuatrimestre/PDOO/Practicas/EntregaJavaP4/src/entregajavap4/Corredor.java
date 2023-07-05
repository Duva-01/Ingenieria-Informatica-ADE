/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entregajavap4;

public class Corredor extends Deportista{
    
    private String nombre;
    private int horas_entrenamiento;

    public Corredor(String nombre, int horas_entrenamiento) {
        super(nombre, horas_entrenamiento);
    }
    
    public void correr(){
        System.out.println("Estoy corriendo");
    }
    
    @Override
    public String toString(){

        return super.toString() + " y soy corredor.";
    }
}
