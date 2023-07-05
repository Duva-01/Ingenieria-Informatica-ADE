/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;
import java.util.ArrayList;

public class Empleado {
    
    private String nombre;
    private ArrayList<Hotel> trabajos;
    
    // Supongo que puede tener un max de 2 actividades al ser 2 hoteles como max tambien.
    private ArrayList<Actividad> actividades;
    
    public Empleado(){
        
        this.nombre = "";
        trabajos = new ArrayList<>();
        actividades = new ArrayList<>();
    }
    
    public Empleado(String nombre){
        
        this.nombre = nombre;
        trabajos = new ArrayList<>();
        actividades = new ArrayList<>();
    }
    
    public String getNombre(){
        
        return nombre;
    }
    
    public boolean addTrabajo(Hotel hotel){
        
        if(trabajos.size() < 2){
            
            trabajos.add(hotel);
            return true;
        }
        else return false;
    }
    
    public ArrayList<Actividad> getActividades(){
        
        return actividades;
    }
}
