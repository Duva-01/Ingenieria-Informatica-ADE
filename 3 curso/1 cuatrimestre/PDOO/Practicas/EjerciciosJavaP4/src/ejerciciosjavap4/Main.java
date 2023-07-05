/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejerciciosjavap4;

/**
 *
 * @author dmartinez01
 */

import java.util.ArrayList;

public class Main {

    
    public static void main(String[] args) {
        
        
        // Sesion 1
        
        /*
        Casilla casilla = new Casilla("Pato");
        CasillaCalle calle_casilla = new CasillaCalle("Pato");
        
        casilla.recibeJugador();
        calle_casilla.recibeJugador();
        
        calle_casilla.construirCasa();
        
        ArrayList<Casilla> tablero = new ArrayList<>();
        
        tablero.add(casilla);
        tablero.add(calle_casilla);
        
        // No me deja llamar al metodo de construirCasa porque es un metodo de 
        //CasillaCalle y el objeto es de tipo Casilla
        
        //tablero.get(0).construirCasa();;
       
        // De primeras tampoco puedes construir una casa en un objeto de CasillaCalle
        //tablero.get(1).construirCasa();
        
        // Podemos hacerlo creandonos una instancia de dicha subclase, es decir
        // realizar un downcasting
        
        ((CasillaCalle) tablero.get(1)).construirCasa();
        */

        
        CasillaCalle casilla1 = new CasillaCalle("Recogidas");
        Casilla casilla2 = casilla1;
        
        // Ambos objetos llaman al metodo de CasillaCalle, es decir, al del hijo
        
        casilla1.recibeJugador();
        casilla2.recibeJugador();
        
        // No puedo llamar al metodo construirCasa en casilla2 porque es un objeto de
        // tipo Casilla
        
        casilla1.construirCasa();
        //casilla2.construirCasa();
        
        // Hay que realizar un downcasting para poder llamar al metodo y 
        // se incrementa casilla2 (casilla1 realmente)
        
        ((CasillaCalle) casilla2).construirCasa();
        
    }
    
}
