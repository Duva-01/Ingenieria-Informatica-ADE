/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;



public class Civitas {

    static int TAM_JUGADORES = 4;
    static int NUM_CASILLAS = 4;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int valor = 0;
        int[] contador = new int[TAM_JUGADORES];
        
        //Ejercicio 1
        /***************************************************************************************************/
        /*
        for(int i=0; i<TAM_JUGADORES; i++)
            contador[i] = 0;
            
        for(int n=0; n<100; n++){

            valor = Dado.getInstance().quienEmpieza(4);
            contador[valor]++;
 
        }

        for(int i=0; i<TAM_JUGADORES; i++){
            
            System.out.println("Para el jugador: " + i + "ha salido " + contador[i] + " veces.");

            if(contador[i] > (100/TAM_JUGADORES) )
                System.out.println("Cumple a nivel practico con las probabilidades");
            else 
                System.out.println("No cumple a nivel practico con las probabilidades");
            
        }
        */
        //----------------------------------------------------------------------------------------------//
        
        // Ejercicio 2

        /* Asegúrate de que funciona el modo debug del dado activando y desactivando ese modo, y
        realizando varias tiradas en cada modo.*/

        /*
        System.out.println(" Tirada con el debug del dado = false: ");
        
        for(int n=0; n<5; n++){

            System.out.println("Ha salido " + Dado.getInstance().tirar());
        }

        System.out.println(" Tirada con el debug del dado = true: ");
        
        Dado.getInstance().setDebug(true);

        for(int n=0; n<5; n++){

            System.out.println("Ha salido " + Dado.getInstance().tirar());
        }
        */
        
        //Ejercicio 3
        /***************************************************************************************************/
        
        /*
        System.out.println("Ha salido " + Dado.getInstance().tirar());

        System.out.println("El ultimo resultado del dado ha sido: " + Dado.getInstance().getUltimoResultado() );
        */

        //Ejercicio 4
        /***************************************************************************************************/

        /*
        System.out.println(" Ejemplos de enumerados de civitas: ");
        
        System.out.println("Estados de Juego: " + EstadosJuego.DESPUES_AVANZAR);

        System.out.println("Tipo sorpresa: " + TipoSorpresa.PAGAR);

        System.out.println("Tipo casilla: " + TipoCasilla.DESCANSO);

        */

        //Ejercicio 5
        /***************************************************************************************************/
        
        
        System.out.println("Mostramos las casillas del tablero: ");

        Tablero table_rico = new Tablero();
        
        ArrayList<Casilla> propiedades_barrio_1 = new ArrayList<>();
            
            Barrio almanjayar = new Barrio("Almajayar", TipoBarrio.CENTRO, 20, propiedades_barrio_1);
            
        Casilla casilla_1 = new Casilla(TipoCasilla.DESCANSO, "Casa Rico", 3000, 140, 20, almanjayar);
        Casilla casilla_2 = new Casilla(TipoCasilla.SORPRESA, "Etsiit", 203, 1, 34, almanjayar);
        Casilla casilla_3 = new Casilla(TipoCasilla.CALLE, "Recogidas", 7000, 300, 60, almanjayar);

        table_rico.añadeCasilla(casilla_1);
        table_rico.añadeCasilla(casilla_2);
        table_rico.añadeCasilla(casilla_3);

        for(int i=0; i<NUM_CASILLAS; i++){

            System.out.println(table_rico.getCasilla(i).toString());
     
        }

        

         //Ejercicio 6
        /***************************************************************************************************/

        
        int PosMasCaro = 0, PosMasBarato = 0;
        float PrecioMasCaro = 0, PrecioMasBarato = 99999;
        float PrecioMedio = 0;
    


        for(int i=1; i<table_rico.getTodasCasillas().size(); i++){

            PrecioMedio += table_rico.getCasilla(i).getPrecioCompra();

            if(table_rico.getCasilla(i).getPrecioCompra() > PrecioMasCaro){
                PosMasCaro = i;
                PrecioMasCaro = table_rico.getCasilla(i).getPrecioCompra();
            }
                
            
            if(table_rico.getCasilla(i).getPrecioCompra() < PrecioMasBarato){
                PosMasBarato = i;
                PrecioMasBarato = table_rico.getCasilla(i).getPrecioCompra();
            }
               
            
     
        }

        PrecioMedio= PrecioMedio / (NUM_CASILLAS-1);

        System.out.println("Precio Medio: " + PrecioMedio);
        System.out.println("Precio mas caro: " + table_rico.getCasilla(PosMasCaro).getPrecioCompra());
        System.out.println("Precio mas barato: " + table_rico.getCasilla(PosMasBarato).getPrecioCompra());

        
         //Ejercicio 7
        /***************************************************************************************************/

        /*
        Diario.getInstance().ocurreEvento("Davi pide matrimonio a JP");
        Diario.getInstance().ocurreEvento("Rico se tropieza");
        Diario.getInstance().ocurreEvento("Bleble me da una abrazo");
        
        for(int i=0; i<Diario.getInstance().getEventos().size(); i++){

            System.out.println(Diario.getInstance().getEventos().get(i));
     
        }

        //Ejercicio 8
        /***************************************************************************************************/

        int actual = 0;
        int pos = 0;
        for(int i=0; i<5; i++){

            System.out.println("Me encuentro en la posicion: " + actual);

            pos = Dado.getInstance().tirar();
            actual = table_rico.nuevaPosicion(actual,pos);

            System.out.println("Ha salido: " + pos + "  --> Por tanto me encuentro en la posicion " + actual + "\n");
     
        }
    }
    
}
