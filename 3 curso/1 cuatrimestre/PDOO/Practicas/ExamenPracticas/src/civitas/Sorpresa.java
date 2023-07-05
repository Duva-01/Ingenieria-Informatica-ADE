/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author Usuario
 */
public class Sorpresa {
    
    private String texto;
    private int valor;
    private TipoSorpresa tipo;
    private MazoSorpresa mazo;

    Sorpresa( TipoSorpresa  tipo ,  String texto ,  int valor )
    {
        this.texto = texto;
        this.valor = valor;
        this.tipo = tipo;
        mazo = new MazoSorpresa();
    }

    void aplicarAJugador(int actual, ArrayList<Jugador> todos){

        if(tipo == TipoSorpresa.COBRAR || tipo == TipoSorpresa.PAGAR){
            
            System.out.println("El jugador ha caido en una casilla sorpresa del tipo: " + tipo);
            aplicarAJugador_pagarCobrar(actual, todos);
        }
        else{
            
            System.out.println("El jugador ha caido en una casilla sorpresa del tipo: " + tipo);
            aplicarAJugador_porCasaHotel(actual, todos);
        }
    }

    private void aplicarAJugador_pagarCobrar(int actual, ArrayList<Jugador> todos){
        
        this.informe(actual, todos);
        todos.get(actual).modificarSaldo(valor);
    }

    private void aplicarAJugador_porCasaHotel(int actual , ArrayList<Jugador> todos ){

        this.informe(actual, todos);
        todos.get(actual).modificarSaldo(valor*todos.get(actual).cantidadCasasHoteles());
    }

    private void informe(int actual , ArrayList<Jugador> todos){

        Diario.getInstance().ocurreEvento("El jugador " + todos.get(actual).getNombre() + " se le esta aplicando una sorpresa: " + texto);
    }
    
    public String toString()
    {
        return texto;
    }


}
