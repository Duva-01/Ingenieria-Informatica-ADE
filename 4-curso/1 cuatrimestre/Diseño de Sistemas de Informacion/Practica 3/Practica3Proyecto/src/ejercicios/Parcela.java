/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;

public class Parcela {
    
    private String nombre;
    private float precioCompra, precioEdificar, precioBaseAlquiler;
    private int numCasas, numHoteles;
    
    private static float FACTORALQUILERCALLE = 1.0f, 
            FACTORALQUILERCASA = 1.0f, 
            FACTORALQUILERHOTEL = 4.0f;
    
    public Parcela(String n, float precio_Compra, float precio_Edificar, float precio_Base_alquiler){
        
        nombre = n;
        precioCompra = precio_Compra;
        precioEdificar = precio_Edificar;
        precioBaseAlquiler = precio_Base_alquiler;
        numCasas = 0;
        numHoteles = 0;
    }
    
    /*
    Justificacion: A la hora de construir un constructor por defecto,
    debemos darle valores a los diferentes atributos que tiene la clase.
    
    Al nombre de esta le devolvemos una cadena vacia de texto, y a los demas valores, al
    ser numericos, los inicializamos a 0, donde posteriormente ya se podran modificar, teniendo un 
    objeto de la clase Parcela vacio.
    
    */
    public Parcela(){
        
        nombre = "";
        precioCompra = 0;
        precioEdificar = 0;
        precioBaseAlquiler = 0;
        numCasas = 0;
        numHoteles = 0;
    }
    public String getNombre(){
        return nombre;
    }
    
    public float getPrecioCompra(){
        return precioCompra;
    }
    
    public float getPrecioEdificar(){
        return precioEdificar;
    }
    
    public int getNumCasas(){
        return numCasas;
    }
    
    public int getNumHoteles(){
        return numHoteles;
    }
    
    public float getPrecioAlquilerCompleto(){
        
        return (precioBaseAlquiler *(FACTORALQUILERCASA + numCasas+ numHoteles*FACTORALQUILERHOTEL));
    }
    
    public boolean construirCasa(){
        numCasas += 1;
        return true;
    }
    
    public boolean construirHotel(){
        numHoteles += 1;
        return true;
    }
    
    public boolean igualdadIdentidad (Parcela otraParcela){
        
        if(this == otraParcela)
            return true;
        else return false;
    }
    
    boolean igualdadEstado (Parcela otraParcela){
        
        if(this == otraParcela){
            return true;
        }
        else{
            
            
            if(nombre.equals(otraParcela.getNombre()) && precioCompra == otraParcela.getPrecioCompra() 
           && precioEdificar == otraParcela.getPrecioEdificar() && this.getPrecioAlquilerCompleto() == otraParcela.getPrecioAlquilerCompleto()
           && numCasas == otraParcela.getNumCasas() && numHoteles == getNumHoteles()){
            
                return true;
        }
        
            else return false;
        }
    }
}

    
