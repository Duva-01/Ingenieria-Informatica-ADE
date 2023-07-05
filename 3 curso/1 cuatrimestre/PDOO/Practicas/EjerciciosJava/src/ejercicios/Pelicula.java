/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;

import java.util.ArrayList;

public class Pelicula {
    
    private String titulo;
    private ArrayList<Alquiler> alquileres;
    
    public Pelicula(String titulo){
        this.titulo = titulo;
        alquileres = new ArrayList<>();
    }
    
    public void addAlquiler(Cliente_2 cliente, String fecha){
        
         
        Alquiler aux = new Alquiler(fecha, this, cliente);
        
        alquileres.add(aux);
        cliente.addAlquiler(aux);

    }
    
    public ArrayList<Alquiler> getAlquileres(){
        return alquileres;
    }
    
    public String getTitulo(){
        return titulo;
    }
}
