

import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;
import java.util.List;
import java.util.Map;

public class donaciones extends UnicastRemoteObject implements donaciones_i {
    
    replicas replica;

    public donaciones(replicas replica) throws RemoteException {
        this.replica = replica;
    }

    public int getTotalDonaciones() throws RemoteException, NotBoundException{
        return replica.getTotalDonaciones();
    }

    public int registrarCliente(int idCliente) throws RemoteException, NotBoundException{
        return replica.registrarCliente(idCliente);
    }

    public void donar(int cantidad, int idCliente) throws RemoteException {
        replica.donar(cantidad, idCliente);
    }

    // Implementacion de operaciones adicionales

    public void retirarDonacion(int cantidad, int idCliente) throws RemoteException, NotBoundException{
        replica.retirarDonacion(cantidad, idCliente);
    }

    public int consultarDonacionesCliente(int idCliente) throws RemoteException, NotBoundException {
        return replica.consultarDonacionesCliente(idCliente);
    }

    public List<Integer> consultarMaximoDonador() throws RemoteException, NotBoundException{
        return replica.consultarMaximoDonador();
    }
}