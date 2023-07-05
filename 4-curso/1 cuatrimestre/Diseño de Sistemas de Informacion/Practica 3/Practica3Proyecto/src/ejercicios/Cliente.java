/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;
import java.util.ArrayList;


public class Cliente {
    
    private ArrayList<Reserva> reservas;
    private String dni;
    private String nombre;
    
    public Cliente(String dni, String nombre){
        this.dni = dni;
        this.nombre = nombre;
        reservas = new ArrayList<>();
    }
    
    public String getNombre(){
        return nombre;
    }
    
    public void addReserva(Reserva reserva){
        reservas.add(reserva);
    }
    
    public ArrayList<Reserva> getReservas(){
        return reservas;
    }
    
}
