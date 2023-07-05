/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;


public class Alquiler {
    
    private String fecha;
    private Pelicula pelicula;
    private Cliente_2 cliente;
    
    public Alquiler(String fecha, Pelicula pelicula, Cliente_2 cliente){
        
        this.fecha = fecha;
        this.pelicula = pelicula;
        this.cliente = cliente;
    }
    
    public String getFecha(){
        return fecha;
    }
    
    public Pelicula getPelicula(){
        return pelicula;
    }
    
    public Cliente_2 getCliente(){
        return cliente;
    }
}
