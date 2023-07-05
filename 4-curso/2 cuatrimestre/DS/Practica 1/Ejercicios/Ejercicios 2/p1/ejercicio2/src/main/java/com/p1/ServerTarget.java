package com.p1;

import java.util.ArrayList;

public class ServerTarget {
    private ArrayList<String> comentarios;

    ServerTarget(){
        comentarios = new ArrayList<>();
    }

    public void aniadeComentario(String comentario){
        comentarios.add(comentario);
    }
}
