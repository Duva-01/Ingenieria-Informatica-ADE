/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica2;

import javax.swing.*;
import java.awt.*;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.Timer;


public class MapaVisual extends JFrame {
    
    private Mapa mapa;
    private int agenteX, agenteY;
    private final int CELL_SIZE = 20; // Define el tamaño de cada celda en el canvas

    private JButton btnIterar;
    private JButton btnAuto;
    private Timer autoTimer;
    public ActionListener doIteration;
    
    private Agente agente;
    
    private JLabel lblTitulo;
    private JLabel lblPosicionActual;
    private JLabel lblPosicionObjetivo;
    private JLabel lblNumeroIteracion;
    private int iteraciones = 0;

    private MapaPanel mapaPanel;
    
    public MapaVisual(Mapa mapa, Agente agente) {
        this.mapa = mapa;
        this.agente = agente;
        this.agenteX = 0;
        this.agenteY = 0;
        this.setTitle("Visualización del Mapa");
        this.setPreferredSize(new Dimension(800, 600)); // Establece el tamaño preferido para el JFrame

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
    JPanel btnPanel = new JPanel();

        btnIterar = new JButton("Iterar");
        btnAuto = new JButton("Auto");

        btnIterar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                agente.startMovement();
                doIteration();
            }
        });

        btnAuto.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                agente.startMovement();
                if (autoTimer == null) {
                    autoTimer = new Timer(500, new ActionListener() { // Ejecuta cada 500 milisegundos
                        @Override
                        public void actionPerformed(ActionEvent e) {
                            doIteration();
                        }
                    });
                    autoTimer.start();
                    btnAuto.setText("Detener");
                } else {
                    autoTimer.stop();
                    autoTimer = null;
                    btnAuto.setText("Auto");
                }
            }
        });

        btnPanel.add(btnIterar);
        btnPanel.add(btnAuto);
        this.add(btnPanel, BorderLayout.SOUTH);
        
        // Título dentro de la ventana
    lblTitulo = new JLabel("Practica 2 - DBA", SwingConstants.CENTER);
    lblTitulo.setFont(new Font("Serif", Font.BOLD, 20));
    this.add(lblTitulo, BorderLayout.NORTH);
    
        // Panel Informativo
    JPanel panelInfo = new JPanel();
    panelInfo.setLayout(new GridLayout(6, 1));

    // Estilo para el panel informativo
    panelInfo.setBorder(BorderFactory.createTitledBorder("Información del Agente"));
    panelInfo.setBackground(Color.LIGHT_GRAY);

    lblPosicionActual = new JLabel("Posición Actual: (0,0)");
    lblPosicionObjetivo = new JLabel("Posición Objetivo: (" + agente.objetivo.x + "," + agente.objetivo.y + ")");
    lblNumeroIteracion = new JLabel("Iteración: " + iteraciones);

    panelInfo.add(lblPosicionActual);
    panelInfo.add(lblPosicionObjetivo);
    panelInfo.add(lblNumeroIteracion);

    this.add(panelInfo, BorderLayout.EAST);
    
    
        // Después de definir el panel de información, pero antes de pack();
        mapaPanel = new MapaPanel(mapa, agenteX, agenteY); // Inicializamos el panel del mapa con las posiciones iniciales
        this.add(mapaPanel, BorderLayout.CENTER);

        this.pack();

    }
    
    public void doIteration() {
    if(doIteration != null) {
        doIteration.actionPerformed(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, "doIteration"));
        }
    }

    
    public void setAgentePosicion(int x, int y) {
        mapaPanel.setAgentePosicion(x, y); // Llamamos al método del MapaPanel
        lblPosicionActual.setText("Posición Actual: (" + x + "," + y + ")");
        iteraciones++;
        lblNumeroIteracion.setText("Iteración: " + iteraciones);
    }

}
