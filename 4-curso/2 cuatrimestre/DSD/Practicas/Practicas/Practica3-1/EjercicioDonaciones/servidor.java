import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class servidor {
    public static void main(String[] args) {

        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {

            System.out.println("LLego a meterme");
            // Nos creamos el registro objetos remotos en el puerto por defecto
            Registry registry = LocateRegistry.createRegistry(1099);

            // Recibimos por parametro cuantas replicas del servidor voy a crearme
            int tamReplicas = Integer.parseInt(args[0]);

            for (int i = 0 ; i < tamReplicas ; i++) {

                // Nos cremos el objeto remoto "Replica", los cuales tendra su 
                // identificador y el numero total de replicas para su correcta comunicacion entre ellas

                replicas replica = new replicas("localhost", i, tamReplicas);   
                Naming.rebind("Replica" + i, replica);
                
                // Nos creamos los objetos remotos para las donaciones, 
                // las cuales serviran entre el cliente y el servidor

                donaciones donacion = new donaciones(replica); 
                Naming.rebind("Replica" + i + "-Donaciones", donacion);

                System.out.println("==> Replica " + i + " construida...");
            }

            // Finalizamos la creacion de replicas
            System.out.println("-- Finalizacion de las replicas creadas -- \n");

        } catch (Exception e) {
            System.err.println("Replica exception:");
            e.printStackTrace();
        }
    }
}