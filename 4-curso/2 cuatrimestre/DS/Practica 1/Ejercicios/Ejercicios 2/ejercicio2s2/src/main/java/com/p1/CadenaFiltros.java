package com.p1;

import java.util.ArrayList;

public class CadenaFiltros {
    private ArrayList<Filtro> filtros;

    CadenaFiltros(){
        filtros = new ArrayList<>();
    }

    CadenaFiltros(ArrayList<Filtro> f){
        filtros = f;
    }

     public String ejecutar(String texto){
        // Recorre cada filtro aplicándolo a la cadena
        for(Filtro filtro : filtros)
            // Se aplica cada filtro a la cadena y ésta reemplaza la original
            texto = filtro.ejecutar(texto);

        // Devuelve la cadena procesada
        return texto;
    }

    public void aniadirFiltro(Filtro filtro){
        filtros.add(filtro);
    }
}
