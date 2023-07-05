/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejerciciosjavap4;

/**
 *
 * @author Usuario
 */

public class CasillaCalle extends Casilla{
    
        private int numCasas;
        
        CasillaCalle(String nombre) {
            
            super(nombre);
            numCasas = 0;
        }
        
        // Ejercicio 1
        // No es necesario ningun metodo, porque es una subclase de Casilla por 
        // lo que puede llamar a su metodo RecibeJugador por la herencia
        
        
        // Ejercicio 2
        //@Override
        /*
        boolean recibeJugador(){
            
            System.out.println("Y ademas soy una casilla calle");
            return true;
            
        }
        */
        
        // Ejercicio 3
        
        // Devuelve el de su clase
        // Reutilizando codigo del padre
        @Override
        boolean recibeJugador(){
            
            boolean check = super.recibeJugador();
            if(check){
                
                System.out.println("Y ademas soy una casilla calle");
                return true;
            }
            else return false;
        }
        
        void construirCasa(){
            
            numCasas++;
            System.out.println("El numero de casas es: " + numCasas);
        }
}