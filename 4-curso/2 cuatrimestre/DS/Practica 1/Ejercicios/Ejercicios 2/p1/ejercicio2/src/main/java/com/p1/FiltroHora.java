package com.p1;

import java.util.Date;

public class FiltroHora implements Filtro{
    private Date fecha;

    FiltroHora(){
        fecha = new Date();
    }

    @Override
    public String ejecutar(String texto){
        String texto_resultado = texto + " " + fecha.toString(); //Objeto fecha creado
        return texto_resultado;
    }
}