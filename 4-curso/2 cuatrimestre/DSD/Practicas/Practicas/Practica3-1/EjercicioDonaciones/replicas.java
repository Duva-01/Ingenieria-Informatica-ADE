
import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.AbstractMap;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class replicas extends UnicastRemoteObject implements replicas_i {

    // Variables

    private replicas_i replica;
    private Registry registry;

    private int id; // Identificador de esta réplica
    private int numReplicas; // Número total de réplicas

    private Map<Integer, Integer> clientesRegistrados = new HashMap<Integer, Integer>();
    private int cantidad_donada = 0;

    // Contructor

    public replicas(String host, int id, int numReplicas) throws RemoteException {

        registry = LocateRegistry.getRegistry(host, 1099);
        this.id = id;
        this.numReplicas = numReplicas;
    }

    // ---------------------------------------------------//

    public int getTotalDonaciones() throws RemoteException, NotBoundException {

        int total = 0;

        // Consigo la cantidad donada por esta replica
        total = cantidad_donada;

        // Hago lo mismo con las demas replicas
        for (int i = 0; i < this.numReplicas; i++) {

            if (i != id) {
                replica = (replicas_i) registry.lookup("Replica" + i);
                total += replica.getCantidadDonadaReplica();
            }
        }

        return total;
    }

    public int getCantidadDonadaReplica() throws RemoteException {
        return cantidad_donada;
    }

    public synchronized int registrarCliente(int idCliente) throws RemoteException, NotBoundException {

        int id_replicaReg = id;
        boolean registrado = false;

        int numReg;
        int minReg = clientesRegistrados.size();

        System.out
                .println("==> El numero MINIMO de registrados esta en la Replica " + id_replicaReg + " es: " + minReg);

        // Comprobamos en cada replica si ya esta registrado dicho cliente
        // y obtenemos la replica con menos registros

        for (int i = 0; i < numReplicas && !registrado; i++) {

            if (i != id) {

                replica = (replicas_i) registry.lookup("Replica" + i);
                registrado = replica.estaRegistrado(idCliente);
                numReg = replica.getNumReg();

                System.out.println("El numero de registrados en Replica " + i + " es: " + numReg);

                if (numReg < minReg) {
                    id_replicaReg = i;
                    minReg = numReg;
                }
            }
        }

        // Si no esta registrado continuamos

        System.out.println("hola");

        if (registrado == false) {

            // Obtenemos la replica con menos registros
            replica = (replicas_i) registry.lookup("Replica" + id_replicaReg);

            // Registramos al cliente en la replica con menor numero de registros
            replica.registrar(idCliente);
        }

        return id_replicaReg;
    }

    public void registrar(int idCliente) throws RemoteException {
        clientesRegistrados.put(idCliente, 0);
    }

    public boolean estaRegistrado(int idCliente) throws RemoteException {
        return clientesRegistrados.containsKey(idCliente);
    }

    public int getNumReg() throws RemoteException {
        return clientesRegistrados.size();
    }

    public synchronized void donar(int cantidad, int idCliente) throws RemoteException {

        // En primer lugar comprobamos que el cliente se encuentra registrado en el
        // sistema
        if (clientesRegistrados.containsKey(idCliente)) {

            clientesRegistrados.put(idCliente, cantidad);
            cantidad_donada += cantidad;
        } else {

            throw new RemoteException("El cliente con ID " + idCliente + " no se encuentra registrado.");
        }
    }

    //-------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------


    // Implementacion de operaciones adicionales

    public synchronized void retirarDonacion(int cantidad, int idCliente) throws RemoteException, NotBoundException {

        int id_replicaReg = id;
        boolean registrado = false;

        for (int i = 0; i < numReplicas && !registrado; i++) {

            replica = (replicas_i) registry.lookup("Replica" + i);
            registrado = replica.estaRegistrado(idCliente);

            if (registrado == true) {
                id_replicaReg = i;
            }
        }

        if (registrado == true) {

            replica = (replicas_i) registry.lookup("Replica" + id_replicaReg);

            replica.retirar(cantidad, idCliente);

        } else {

            throw new RemoteException("El cliente con ID " + idCliente + " no se encuentra registrado.");
        }
    }

    public void retirar(int cantidad, int idCliente) throws RemoteException {

        // Obtener las donaciones del clientes
        int donacionesCliente = clientesRegistrados.get(idCliente);

        // Restar la cantidad de la donación
        int donacionesClienteNuevo = donacionesCliente - cantidad;

        // Verificar si el valor no es negativo
        if (donacionesClienteNuevo >= 0) {

            clientesRegistrados.put(idCliente, donacionesClienteNuevo);
            cantidad_donada -= cantidad;
        } else {

            throw new RemoteException(
                    "La cantidad de la donación a retirar es mayor a las donaciones que ha realizado.");
        }
    }

    //-------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------

    public synchronized int consultarDonacionesCliente(int idCliente) throws RemoteException, NotBoundException {

        int id_replicaReg = id;
        boolean registrado = false;

        int donaciones = 0;

        for (int i = 0; i < numReplicas && !registrado; i++) {

            replica = (replicas_i) registry.lookup("Replica" + i);
            registrado = replica.estaRegistrado(idCliente);

            if (registrado == true) {
                id_replicaReg = i;
            }
        }

        if (registrado == true) {

  
            replica = (replicas_i) registry.lookup("Replica" + id_replicaReg);

            
            donaciones = replica.consultarDonacionesClienteReplica(idCliente);
            
        } else {

            throw new RemoteException("El cliente con ID " + idCliente + " no se encuentra registrado.");
        }

        return donaciones;
    }

    public int consultarDonacionesClienteReplica(int idCliente) throws RemoteException{

        return clientesRegistrados.get(idCliente);
    }
    

    //-------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------


    public synchronized List<Integer> consultarMaximoDonador() throws RemoteException, NotBoundException {

        List<Integer> maxDonador = consultarMaximoDonadorReplica();
    
        List<Integer> donador = Arrays.asList(0, 0);
    
        for (int i = 0; i < numReplicas; i++) {
    
            if (i != id) {
    
                replica = (replicas_i) registry.lookup("Replica" + i);
    
                donador = replica.consultarMaximoDonadorReplica();
    
                if (donador.get(1) > maxDonador.get(1)) {
                    maxDonador = donador;
                }
            }
        }
    
        return maxDonador;
    }
    
    public List<Integer> consultarMaximoDonadorReplica() throws RemoteException {
    
        List<Integer> maxDonador = Arrays.asList(0, 0);
    
        if (clientesRegistrados.isEmpty() == false){
    
            for (Map.Entry<Integer, Integer> donador : clientesRegistrados.entrySet()) {
                if (donador.getValue() > maxDonador.get(1)) {
                    maxDonador = Arrays.asList(donador.getKey(), donador.getValue());
                }
            }
        }
    
        return maxDonador;
    }
    
}
