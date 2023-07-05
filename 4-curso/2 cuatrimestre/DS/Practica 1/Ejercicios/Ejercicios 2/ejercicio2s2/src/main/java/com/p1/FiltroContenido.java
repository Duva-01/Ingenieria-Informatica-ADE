package com.p1;

import java.util.ArrayList;

public class FiltroContenido implements Filtro {
    private ArrayList<String> palabrasProhibidas;

    FiltroContenido(){
        palabrasProhibidas = new ArrayList<>();
    }

    FiltroContenido(ArrayList<String> palabras){
        palabrasProhibidas = palabras;
    }

    public void aniadePalabra(String palabra){
        palabrasProhibidas.add(palabra);
    }

    @Override
    public String ejecutar(String texto){
        String texto_filtrado = texto;

        if(!texto.isEmpty())  // Texto no vacío
            for( String palabra : palabrasProhibidas)   // Por cada palabra prohibida
                texto_filtrado = texto.replaceAll(palabra, "***");  // Busca en el texto y si está la sustituye

        return texto_filtrado;
    }
}
