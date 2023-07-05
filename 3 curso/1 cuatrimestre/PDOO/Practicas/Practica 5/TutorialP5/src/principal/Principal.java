/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal;

import controlador.Controlador;
import modelo.Modelo;
import vista.Vista;
import vista.VistaPrincipal;


public class Principal {
    
    public static void main(String[] args) {
        Vista v=new VistaPrincipal();
        Modelo m=new Modelo();
        Controlador c=new Controlador(m,v);
        
        
    }
}
