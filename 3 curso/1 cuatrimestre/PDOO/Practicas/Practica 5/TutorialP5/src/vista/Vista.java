/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vista;

import controlador.Controlador;
import modelo.Modelo;


public interface Vista {
    
    public void recibeModelo(Modelo m);
    public void setControlador(Controlador c);
    
}
