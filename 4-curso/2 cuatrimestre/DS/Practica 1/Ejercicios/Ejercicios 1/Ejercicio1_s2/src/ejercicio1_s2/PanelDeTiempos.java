package ejercicio1_s2;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
public class PanelDeTiempos implements Observer{
    
    private TorreDeControl torre;
    private VentanaPrincipal ventana;
    
    public PanelDeTiempos(TorreDeControl torre, VentanaPrincipal ventana) {
        this.torre = torre;
        this.ventana = ventana;
    }
    
    /*
    @Override
    public void update() {
        System.out.println("---------- PANEL TIEMPOS ----------");
        
        for (CocheFormulaUno c : torre.getCoches()){
            System.out.println("Coche " + c.getNumero()+", tiempo: " + c.getUltimoTiempo());
        }
    }
    */
    
    //cambiado
    @Override
    public void update() {
        ventana.updatePanelTiempo(torre);
    }
    
}

