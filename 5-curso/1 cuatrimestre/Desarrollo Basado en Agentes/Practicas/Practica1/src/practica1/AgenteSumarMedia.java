package practica1;

import jade.core.Agent;
import jade.core.behaviours.Behaviour;
import java.util.Scanner;

public class AgenteSumarMedia extends Agent {
    
    private int numeros;
    private double sumatoria = 0;
    private int contador = 0;
    private Scanner scanner = new Scanner(System.in);
    
    @Override
    protected void setup() {
        addBehaviour(new SolicitarNumeroDeEntradas());
    }
    
    private class SolicitarNumeroDeEntradas extends Behaviour {
        
        @Override
        public void action() {
            System.out.println("Introduce el número de elementos numéricos a leer:");
            numeros = scanner.nextInt();
            myAgent.addBehaviour(new LeerYSumarEntradas());
        }
        
        @Override
        public boolean done() {
            return true;
        }
    }
    
    private class LeerYSumarEntradas extends Behaviour {
        
        @Override
        public void action() {
            System.out.println("Introduce el número " + (contador + 1) + ":");
            sumatoria += scanner.nextDouble();
            contador++;
            if(contador == numeros) {
                myAgent.addBehaviour(new CalcularYMostrarMedia());
            }
        }
        
        @Override
        public boolean done() {
            return contador == numeros;
        }
    }
    
    private class CalcularYMostrarMedia extends Behaviour {
        
        @Override
        public void action() {
            double media = sumatoria / numeros;
            System.out.println("La media de los números introducidos es: " + media);
        }
        
        @Override
        public boolean done() {
            return true;
        }
    }
}
