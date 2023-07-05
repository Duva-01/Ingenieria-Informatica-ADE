/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;


public class Actividad {
    
    
    private TipoActividad actividad;
    private String horario;
    private Empleado empleado;
    
    public Actividad(){
        
        actividad = TipoActividad.BASKET;
        horario = "";
        empleado = new Empleado();
    }
    
    public Actividad(TipoActividad actividad, String horario, Empleado empleado){
        
        this.actividad = actividad;
        this.horario = horario;
        this.empleado = empleado;
    }
    
    public Empleado getEmpleado(){
        return empleado;
    }
    
    public String getHorario(){
        return horario;
    }
    
    public TipoActividad getTipo(){
        return actividad;
    }
}
