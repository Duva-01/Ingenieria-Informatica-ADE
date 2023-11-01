package practica2;

import jade.core.Agent;
import java.awt.Point;
import java.util.List;
import jade.core.behaviours.*;
import java.util.ArrayList;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.util.Random;

public class Agente extends Agent {
    
    private Mapa mapa;
    private Point posicionActual;
    public Point objetivo;
    private MapaVisual visual;
    
    protected void setup() {
        // Inicializar el mapa.
        mapa = new Mapa("practica2/mapa.txt");

        // Ubicar al agente y al objetivo en posiciones aleatorias que estén libres.
        setPositionRandomly();
        setObjetivoRandomly();

        visual = new MapaVisual(mapa, this);
        visual.doIteration = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                startMovement();
                visual.setAgentePosicion((int) posicionActual.getX(), (int) posicionActual.getY());
                visual.repaint(); // Repinta solo después de un movimiento
            }
        };

        visual.setVisible(true);
    }
    
    public void startMovement() {
        addBehaviour(new ComportamientoMoverse());
    }

    private void setPositionRandomly() {
        Random rand = new Random();
        int x, y;

        do {
            x = rand.nextInt(mapa.getFilas());
            y = rand.nextInt(mapa.getColumnas());
        } while (!mapa.isFree(x, y));

        posicionActual = new Point(x, y);
    }

    private void setObjetivoRandomly() {
        Random rand = new Random();
        int x, y;

        do {
            x = rand.nextInt(mapa.getFilas());
            y = rand.nextInt(mapa.getColumnas());
        } while (!mapa.isFree(x, y) || (x == posicionActual.x && y == posicionActual.y));

        objetivo = new Point(x, y);
        mapa.setObjetivo(x, y); // Marcar el objetivo en el mapa.
    }

    private void moverAgente() {
        List<Point> moves = getPossibleMoves(posicionActual);
        Point bestMove = getBestMove(moves);

        if (bestMove != null) {
            posicionActual = bestMove;
        }
    }
    
    private class ComportamientoMoverse extends OneShotBehaviour {
    
        public void action() {
            moverAgente();
        }
    }

    // Devuelve los posibles movimientos desde una posición dada.
    private List<Point> getPossibleMoves(Point point) {
        List<Point> moves = new ArrayList<>();
        int x = (int) point.getX();
        int y = (int) point.getY();

        if (x > 0 && mapa.isFree(x-1, y)) moves.add(new Point(x-1, y));
        if (x < mapa.getFilas() - 1 && mapa.isFree(x+1, y)) moves.add(new Point(x+1, y));
        if (y > 0 && mapa.isFree(x, y-1)) moves.add(new Point(x, y-1));
        if (y < mapa.getColumnas() - 1 && mapa.isFree(x, y+1)) moves.add(new Point(x, y+1));

        return moves;
    }

    // Devuelve la dirección que acerca más al objetivo desde una lista de movimientos posibles.
    private Point getBestMove(List<Point> moves) {
        Point bestMove = null;
        double bestDistance = Double.MAX_VALUE;

        for (Point move : moves) {
            double distance = move.distance(objetivo);
            if (distance < bestDistance) {
                bestDistance = distance;
                bestMove = move;
            }
        }

        return bestMove;
    }
}
