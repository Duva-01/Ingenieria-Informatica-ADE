package com.p1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import java.util.ArrayList;

public class UsuarioCliente extends JFrame implements ActionListener  {
    
    private JTextField input;
    private JButton send;
    private JTextArea output;

    private GestorFiltros gestor;


    UsuarioCliente() {
        //Crear objeto gestor
        gestor = new GestorFiltros();
        ini();
    }

    UsuarioCliente(ServerTarget servidor) {
        //Crear objeto gestor
        gestor = new GestorFiltros(servidor);
        ini();
    }


    private void ini() {
        // Inicializaciones de componentes
        input = new JTextField(20);
        send = new JButton("Enviar");
        output = new JTextArea(10,20);

        // Componente editable
        output.setEditable(false);
        
        
        // Crear panel y añadir elementos
        JPanel panel = new JPanel();

        panel.setLayout((new BorderLayout()));
        panel.add(input,BorderLayout.NORTH);
        panel.add(send,BorderLayout.CENTER);
        panel.add(output,BorderLayout.SOUTH);
        
        this.setTitle("Introduce comentario");
        this.setContentPane(panel);
        this.pack();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);


        // Añadir envento al botón
        send.addActionListener(this);
    }


    public String ejecucion(String texto){//
        // Crear objetos
        String texto_test = texto;

        // Crear gestor
        GestorFiltros gestor = new GestorFiltros(new ServerTarget());


        // Conjunto de palabras prohibidas que borraremos
        ArrayList<String> prohibidas = new ArrayList<>();
        prohibidas.add("Duis");

        // Crear filtros
        FiltroContenido filtrado = new FiltroContenido(prohibidas);
        FiltroHora filtrado_date = new FiltroHora();

        // Añadir filtros
        gestor.aniadirFiltro(filtrado);
        gestor.aniadirFiltro(filtrado_date);


        // Devuelve la cadena modificada con los filtros
        return gestor.aniadeComentario(texto_test);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
         //Obtener la entrada
         String texto_input = input.getText();

         //Ejecución de programa
         String texto_resultado = ejecucion(texto_input);
         
         //Mostrar resultado
         output.setText(texto_resultado);
    }


    public String comentar(String comentario) {
        return gestor.aniadeComentario(comentario);
    }

    public GestorFiltros getGestor() {
        return gestor;
    }


    public static void main(String[] args) {
        // Crear la interfaz
        UsuarioCliente usuarioInterfaz = new UsuarioCliente();
        usuarioInterfaz.setVisible(true);
    }
}