/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

public class SorpresaPagarCobrar extends Sorpresa{
    
    SorpresaPagarCobrar(String texto ,  int valor , MazoSorpresa mazo){
 
        super(texto,valor,mazo);
    }
    
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos){

        
        Diario.getInstance().ocurreEvento("\n El jugador ha caido en una casilla sorpresa del tipo: PagarCobrar");
        Diario.getInstance().ocurreEvento("--> " + toString() + "\n");
        informe(actual, todos);
        
        if(valor < 0)
            todos.get(actual).paga(valor);
        else
            todos.get(actual).modificarSaldo(valor);
        
           
        }
    }

