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
public abstract class Sorpresa {
    
    protected String texto;
    protected int valor;
    protected MazoSorpresa mazo;

    Sorpresa(String texto ,  int valor ,MazoSorpresa mazo )
    {
        this.texto = texto;
        this.valor = valor;
        this.mazo = mazo;
    }

    public abstract void  aplicarAJugador(int actual, ArrayList<Jugador> todos);
    
    protected void informe(int actual , ArrayList<Jugador> todos){

        Diario.getInstance().ocurreEvento("El jugador " + todos.get(actual).getNombre() + " se le esta aplicando una sorpresa: " + texto);
        
    }
    
    @Override
    public String toString()
    {
        return texto;
    }


}
