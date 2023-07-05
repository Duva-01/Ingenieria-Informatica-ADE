/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;


public class Director {
    
    private String nombre;
    private long telefono;

    public Director(String nombre, long telefono) {
        
        this.nombre = nombre;
        this.telefono = telefono;
    }
    
    
    public String getNombre(){
        return nombre;
    }
    
}
