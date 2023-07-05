/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1_s2;

import java.util.ArrayList;

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
public class Ejercicio1_s2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        VentanaPrincipal ventana = new VentanaPrincipal();
                
        ArrayList<CocheFormulaUno> cochesCarrera = new ArrayList<>();
        
        //creamos 10 coches para la carrera
        for (int i= 0; i< 10; i++){
            cochesCarrera.add(new CocheFormulaUno(i));
        }
        
        TorreDeControl torre = new TorreDeControl(cochesCarrera);
        torre.attach(new PanelDeTiempos(torre,ventana));
        torre.attach(new Clasificacion(torre,ventana));
        
        ventana.setTorre(torre);
        
        //cREAMOS HEBRAS Y DAN UNA VUELTA
        for (CocheFormulaUno c : torre.getCoches()){
            c.start();
        }
        
        torre.Notify();
        
        
        
        
        
        
    }
    
}
