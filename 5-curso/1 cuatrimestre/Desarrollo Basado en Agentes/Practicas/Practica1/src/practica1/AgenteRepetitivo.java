/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica1;

import jade.core.Agent;
import jade.core.behaviours.TickerBehaviour;

/**
 *
 * @author Usuario
 */
public class AgenteRepetitivo extends Agent{
    
    protected void setup() {
        addBehaviour(new RepeatedMessageBehaviour(this, 2000));  
    }
    
    private class RepeatedMessageBehaviour extends TickerBehaviour {
        
        public RepeatedMessageBehaviour(Agent a, long period) {
            super(a, period);
        }
        
        protected void onTick() {
            System.out.println("Mensaje repetitivo de: " + myAgent.getLocalName());
        }
    }
}
