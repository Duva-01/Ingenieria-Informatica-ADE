/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1;

/**
 *
 * @author Elena Ortega Contreras, subgrupo A2
 */
public class SesionPesca {
    public Barco crarBarcoSesion(FactoriaAbstractaPezYBarco factoria, int capacidad){
       
        Barco b = factoria.crearBarco(capacidad);
        System.out.println("soy el barco : " + b.getId());
        //b.run();//run hace el metodo pescar
        return b;
    }
}
