/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package controladorCivitas;
import civitas.CivitasJuego;
import civitas.OperacionInmobiliaria;
import vistaTextualCivitas.VistaTextual;

/**
 *
 * @author dmartinez01
 */
public class Controlador {
    
    private CivitasJuego juego;
    private VistaTextual vista;
    
    public Controlador(CivitasJuego juego, VistaTextual vista)
    {
        this.juego = juego;
        this.vista =vista;
    
    }
    
    public void juega()
    {
        boolean fin_juego = juego.finalDelJuego();
        while(!fin_juego)
        {
            vista.mostrarEstado();
            vista.pausa();
            
            civitas.OperacionJuego siguiente = juego.siguientePaso();
            vista.mostrarSiguienteOperacion( siguiente);
            
            if( siguiente != civitas.OperacionJuego.PASAR_TURNO )
                vista.mostrarEventos();
            
            fin_juego = juego.finalDelJuego();
            
            if(!fin_juego)
            {
                switch (siguiente)
                {
                    case COMPRAR:
                        
                        if(vista.comprar() == Respuesta.SI)
                            juego.comprar();
                        
                        juego.siguientePasoCompletado(siguiente);
                        
                    break;
                    case GESTIONAR:
                        
                        civitas.OperacionInmobiliaria operacion = vista.elegirOperacion() ;
                        if(operacion != civitas.OperacionInmobiliaria.TERMINAR)
                        {   
                            int propiedad = vista.elegirPropiedad();
                            
                            civitas.GestionInmobiliaria gestion = new civitas.GestionInmobiliaria(operacion,propiedad); 
                            
                            if(operacion == civitas.OperacionInmobiliaria.CONSTRUIR_CASA)
                            {
                                juego.construirCasa(propiedad);
                            }
                            else
                            {
                                juego.construirHotel(propiedad);
                            }
                            
                        }
                        else
                        {
                            juego.siguientePasoCompletado(siguiente);
                        }
                        
                        
                    break;    
                
                }
                
                
            }
            
            
        }
        
        vista.mostrarEstado();
    }
    
    
}
