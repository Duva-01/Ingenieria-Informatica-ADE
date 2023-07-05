/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author jlric
 */
public class SorpresaConvertirme extends Sorpresa
{
    SorpresaConvertirme(String texto ,  int valor , MazoSorpresa mazo){
 
        super(texto,valor,mazo);
    }
    
    @Override
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos)
    {
        JugadorEspeculador jugador = todos.get(actual).convertir();
        informe(actual, todos);
        todos.set(actual, jugador);
    }
}
