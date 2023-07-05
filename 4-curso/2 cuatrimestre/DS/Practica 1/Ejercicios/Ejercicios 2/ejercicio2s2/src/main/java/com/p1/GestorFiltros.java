package com.p1;

public class GestorFiltros{
    private ServerTarget target;
    private CadenaFiltros cadena;

    GestorFiltros() {
        cadena = new CadenaFiltros();
    }

    GestorFiltros(CadenaFiltros cad) {
        cadena = cad;
    }

    GestorFiltros(ServerTarget servidor) {
        target = servidor;
        cadena = new CadenaFiltros();
    }

    public String aniadeComentario(String comentario) {
        // Añade la cadena original al "diccionario" de cadenas
        target.aniadeComentario(comentario);
        
        // Procesamiento de la cadena
        return cadena.ejecutar(comentario);
    }

    public void aniadirFiltro(Filtro filtro) {
        cadena.aniadirFiltro(filtro);
    }



}