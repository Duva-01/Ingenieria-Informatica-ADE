package ejercicio1_s2;

import java.util.ArrayList;
import java.util.Collections;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
public class Clasificacion implements Observer{
    
    private TorreDeControl torre;
    private VentanaPrincipal ventana;
    
    public Clasificacion(TorreDeControl torre, VentanaPrincipal ventana) {
        this.torre = torre;
        this.ventana = ventana;
    }

    /*
    @Override
    public void update() {
        System.out.println("---------- CLASIFICACIÓN ----------");
        ArrayList<CocheFormulaUno> lista_ordenada = new ArrayList<>(torre.getCoches());
        Collections.sort(lista_ordenada);
        for (CocheFormulaUno c : lista_ordenada){
            System.out.println("Coche " + c.getNumero()+", tiempo: " + c.getUltimoTiempo());
        }
    }
*/
    
    //cambiado
    //añadido para llamar a la ventana
    @Override
    public void update() {
        ventana.updateClasificacion(torre);
    }
    
}
