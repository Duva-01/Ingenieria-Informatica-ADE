/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;
import java.util.ArrayList;

public class Hotel {
    
    private static int NUM_HOTELES = 0;
    private String nombre;
    private String ciudad;
    private int estrellas;
    private ArrayList<Empleado> empleados;
    private ArrayList<Habitacion> habitaciones;    
    private Director director;
    
    private ArrayList<Reserva> reservas;
    private ArrayList<Actividad> actividades;
    
    public Hotel(String nombre, String ciudad, int estrellas) {
        
        NUM_HOTELES++;
        this.nombre = nombre;
        this.ciudad = ciudad;
        this.estrellas = estrellas;
        
        reservas = new ArrayList<>();
        empleados = new ArrayList<>();
        habitaciones = new ArrayList<>();
        actividades = new ArrayList<>();
    }
    
    public static int getNUM_HOTELES(){
        return NUM_HOTELES;
    }
    
    public void setDirector(Director director){
        this.director = director;
    }
    
    public Director getDirector(){
        return director;
    }
    
    public void addReserva(Cliente cliente, String fchaEntrada, String fechSalida){
        
        Reserva aux = new Reserva(fchaEntrada, fechSalida, cliente, this);
        reservas.add(aux);
        cliente.addReserva(aux);
    
    }   
    
    public ArrayList<Reserva> getReservas(){  
       return reservas;
    }
    
    public ArrayList<Empleado> getEmpleados(){
        
        return empleados;
    }
    
    public boolean addEmpleado(Empleado empleado){
        
        if(empleado.addTrabajo(this)){
            
            empleados.add(empleado);
            return true;
        }
        else return false;
    }
    
    public void addHabitacion(int numero, int capacidad){
        
        Habitacion aux = new Habitacion(numero, capacidad);
        habitaciones.add(aux);
        
    }
    
    public int buscarHabitacionCapacidad(int capacidad){
        
        int num = 0;
        boolean check = true;
        
        while(check){
            
            if(habitaciones.get(num).getCapacidad() == capacidad){
                num = habitaciones.get(num).getNumero();
                check = false;
            }
                
            else num++;
        }
        
        return num;
    }
    
    public ArrayList<Actividad> getActividades(){
        
        return actividades;
    }
}
