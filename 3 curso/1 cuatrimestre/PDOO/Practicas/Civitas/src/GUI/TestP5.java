package GUI;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import GUI.CivitasView;
import GUI.CapturaNombres;
import java.util.ArrayList;

import civitas.CivitasJuego;
import controladorCivitas.Controlador;
import vistaTextualCivitas.VistaTextual;

/**
 *
 * @author Usuario
 */
public class TestP5 {
    
    public static void main(String[] args)
    {
        
        CivitasView vista = new CivitasView();
        CapturaNombres captura = new CapturaNombres(vista, true);
        
        ArrayList<String> jugadores = new ArrayList<String>();
        jugadores = captura.getNombres();
        
        CivitasJuego juego = new CivitasJuego(jugadores, true);
        Controlador controlador = new Controlador(juego, vista);
        
        vista.setCivitasJuego(juego);
        
        controlador.juega();
        
        
    }
    
}
