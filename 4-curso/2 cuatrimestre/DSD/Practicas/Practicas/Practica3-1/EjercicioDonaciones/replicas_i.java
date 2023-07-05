

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.NotBoundException;
import java.util.List;
import java.util.Map;


public interface replicas_i extends Remote {

    public int getTotalDonaciones() throws RemoteException, NotBoundException;

    public int getCantidadDonadaReplica() throws RemoteException;

    public int registrarCliente(int idCliente) throws RemoteException, NotBoundException;

    public void registrar(int idCliente) throws RemoteException;

    public boolean estaRegistrado(int idCliente) throws RemoteException;

    public int getNumReg() throws RemoteException;

    public void donar(int cantidad, int idCliente) throws RemoteException;

    // Implementacion de operaciones adicionales
    
    public void retirarDonacion(int cantidad, int idCliente) throws RemoteException, NotBoundException;

    public void retirar(int cantidad, int idCliente) throws RemoteException;

    //-----------------------------------

    public int consultarDonacionesCliente(int idCliente) throws RemoteException, NotBoundException ;

    public int consultarDonacionesClienteReplica(int idCliente) throws RemoteException;

    //-----------------------------------

    public List<Integer> consultarMaximoDonador() throws RemoteException, NotBoundException;

    public List<Integer> consultarMaximoDonadorReplica() throws RemoteException;
}