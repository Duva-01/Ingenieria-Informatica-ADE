/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package practica2;

import jade.core.Profile;
import jade.core.ProfileImpl;
import jade.core.Runtime;
import jade.wrapper.AgentContainer;
import jade.wrapper.AgentController;
import jade.wrapper.StaleProxyException;
/**
 *
 * @author Usuario
 */
import jade.core.Runtime;
import jade.core.Profile;
import jade.core.ProfileImpl;
import jade.wrapper.*;

public class Main {
    public static void main(String[] args) {
        // Iniciar el runtime de JADE
        Runtime rt = Runtime.instance();
        Profile profile = new ProfileImpl();
        AgentContainer container = rt.createMainContainer(profile);

        try {
            AgentController ac1 = container.createNewAgent("Agente", "practica2.Agente",null);
            
            ac1.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
