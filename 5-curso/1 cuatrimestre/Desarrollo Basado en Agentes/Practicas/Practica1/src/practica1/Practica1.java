/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package practica1;

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
public class Practica1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Runtime rt = Runtime.instance();
        
        // Creo mi perfil y lo configuro
        Profile p = new ProfileImpl();
        p.setParameter(Profile.MAIN_HOST, "localhost");
        p.setParameter(Profile.CONTAINER_NAME, "ContenedorPrincipal");
        AgentContainer cc = rt.createMainContainer(p);
        
        try {
            
            // Creo y ejecuto los agentes
            
            // Crear y lanzar el tercer agente: AgenteBasico
            AgentController ac1 = cc.createNewAgent("AgenteBasico", "practica1.AgenteBasico",null);
            ac1.start();
            
            
            // Crear y lanzar el tercer agente: AgenteRepetitivo
            AgentController ac2 = cc.createNewAgent("AgenteRepetitivo","practica1.AgenteRepetitivo",null);
            //ac2.start();
            //ac2.kill();
            
            // Crear y lanzar el tercer agente: AgenteUnaSolaVez
            AgentController ac3 = cc.createNewAgent("AgenteUnaSolaVez","practica1.AgenteUnaSolaVez",null);
            //ac3.start();
            //ac3.kill();
            
            // Crear y lanzar el cuarto agente: AgenteSumarMedia
            AgentController ac4 = cc.createNewAgent("AgenteSumarMedia","practica1.AgenteSumarMedia",null);
            //ac4.start();
            //ac4.kill();

        } catch (StaleProxyException e) {
            e.printStackTrace();
        }
    }
    
}
