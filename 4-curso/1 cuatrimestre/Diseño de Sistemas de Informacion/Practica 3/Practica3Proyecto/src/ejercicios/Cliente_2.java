/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;
import java.util.ArrayList;

public class Cliente_2 {
    
    
    private String dni;
    private String nombre;
    private ArrayList<Alquiler> alquileres;
    
    public Cliente_2(String dni, String nombre){
        
        this.dni = dni;
        this.nombre = nombre;
        alquileres = new ArrayList<>();
    }
    
    public void addAlquiler(Alquiler alquiler){
        
        alquileres.add(alquiler);
    }
}
