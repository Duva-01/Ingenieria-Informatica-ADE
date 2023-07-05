import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.NotBoundException;
import java.util.List;
import java.util.Map;

public interface donaciones_i extends Remote {

    public int getTotalDonaciones() throws RemoteException, NotBoundException;

    public int registrarCliente(int idCliente) throws RemoteException, NotBoundException;

    public void donar(int cantidad, int idCliente) throws RemoteException;

    // Implementacion de operaciones adicionales

    public void retirarDonacion(int cantidad, int idCliente) throws RemoteException, NotBoundException;

    public int consultarDonacionesCliente(int idCliente) throws RemoteException, NotBoundException;

    public List<Integer> consultarMaximoDonador() throws RemoteException, NotBoundException;

}