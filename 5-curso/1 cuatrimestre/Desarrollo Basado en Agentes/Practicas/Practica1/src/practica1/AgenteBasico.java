/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica1;

import jade.core.Agent;
import java.util.Iterator;

public class AgenteBasico extends Agent {
    
    @Override
    protected void setup() {
        
        System.out.println("¡Hola! Soy el agente: " + getAID().getName());
        
        System.out.println("My local-name is " + getAID().getName());
        System.out.println("My addresses are: ");
        
        Iterator it = getAID().getAllAddresses();
        
        while(it.hasNext()){
            System.out.println("- " + it.next());
        }
    
        doDelete();
    }
    
    @Override
    public void takeDown(){
        System.out.println("Cerrando agente...");
    }
}