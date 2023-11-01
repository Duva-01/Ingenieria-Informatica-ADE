/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package practica2;

/**
 *
 * @author Usuario
 */
import java.awt.Point;
import java.io.*;

public class Mapa {
    private int[][] data;
    private int filas;
    private int columnas;

    public Mapa(String fichero) {
        try {
            
            InputStream is = this.getClass().getClassLoader().getResourceAsStream(fichero);
            if (is == null) {
                throw new FileNotFoundException("No se pudo encontrar el archivo: " + fichero);
            }
            BufferedReader reader = new BufferedReader(new InputStreamReader(is));
            
            filas = Integer.parseInt(reader.readLine().trim());
            columnas = Integer.parseInt(reader.readLine().trim());
            
            data = new int[filas][columnas];
            for(int i = 0; i < filas; i++) {
                String[] line = reader.readLine().split("\t");
                for(int j = 0; j < columnas; j++) {
                    data[i][j] = Integer.parseInt(line[j]);
                }
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean isObstacle(int x, int y) {
        return data[x][y] == -1;
    }

    public boolean isFree(int x, int y) {
        return data[x][y] == 0;
    }
    
    public boolean isObjetivo(int x, int y) {
        return data[x][y] == 2;
    }

    public int getFilas() {
        return filas;
    }

    public int getColumnas() {
        return columnas;
    }
    
    public void setObjetivo(int x, int y) {
        data[x][y] = 2;
    }
    
    public void printMapa(int x, int y) {
    // Imprimir el borde superior
    System.out.print("+");
    for (int j = 0; j < columnas; j++) {
        System.out.print("-");
    }
    System.out.println("+");

    for (int i = 0; i < filas; i++) {
        System.out.print("|"); // Borde izquierdo
        for (int j = 0; j < columnas; j++) {
            if (i == x && j == y) {
                System.out.print("A");
            } else if (data[i][j] == -1) {
                System.out.print("x");
            } else if (i == 99 && j == 99) { // Coordenadas del objetivo (Ajustar según sea necesario)
                System.out.print("G");
            } else {
                System.out.print("o");
            }
        }
        System.out.print("|"); // Borde derecho
        System.out.println();
    }

    // Imprimir el borde inferior
    System.out.print("+");
    for (int j = 0; j < columnas; j++) {
        System.out.print("-");
    }
    System.out.println("+");
}


}

