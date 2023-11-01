/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica1;

import jade.core.Agent;
import jade.core.behaviours.OneShotBehaviour;

/**
 *
 * @author Usuario
 */
public class AgenteUnaSolaVez extends Agent {
    
    protected void setup() {
        addBehaviour(new OneShotMessageBehaviour());
    }
    
    private class OneShotMessageBehaviour extends OneShotBehaviour {
        public void action() {
            System.out.println("Mensaje de comportamiento de una sola vez de: " + myAgent.getLocalName());
        }
    }
}
