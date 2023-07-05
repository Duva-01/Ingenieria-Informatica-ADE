/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1;

/**
 *
 *  @author Raúl Morgado y Elena Ortega, grupo DS-GP6
 */
public class Ejercicio1 {
    
    public static void main(String[] parameters){
        
        long inicio = System.nanoTime();
        FactoriaGrande fGrande = new FactoriaGrande();
        FactoriaPequeña fPequeña = new FactoriaPequeña();
        SesionPesca sesion = new SesionPesca();
        
        Barco bGrande, bPequenio;
        bGrande = sesion.crarBarcoSesion(fGrande, 100);
       
        bPequenio = sesion.crarBarcoSesion(fPequeña, 50);
        
        bGrande.start();
        bPequenio.start();
        long fin = System.nanoTime();
        long x = fin-inicio;
        System.out.println("Tiempo de ejecucion: -----------" +  x);
       
        
        /*
        se crean 2 factorías 
        - new FactoriaGrande
        - new FactoriaPequeña
        
        con las que se crean 2 barcos (uno de cada tipo):
        - FactoriaGrande crea PesqueroGrande --> creaBarco(int N);
        - FactoriaPequeña crea PesqueroPequeño
                creaBarco (int N){
                    Barco b = new BarcoGrande();
                    Para N veces:
                        Pez p = crearPezGrande(); 
                            --> asignarle el barco al pez p.asignarBarco(b);
                            barco.aniadirPez(p);                     
                }
        
        A continuación se llamaría al método pescar en cada instancia de Barco.
        - PesqueroGrande llama a pescar();
        - PesqueroPequeño llama a pescar();
                pescar (){ //lo llama el pesqueroGrande
                    //se crea hebra barco, que hará la funcionalidad:
                        Para N= tamArrayPeces veces:
                            p.serPescado();                     
                }        
            

        */
        
        
    }
    
    
}
