import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.util.AbstractMap;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class cliente implements Runnable {

    private String host;
    private String replica;
    private Scanner scanner;

    public cliente(String host, String replica, Scanner scanner) {
        this.host = host;
        this.replica = replica;
        this.scanner = scanner; 
    }

    public static void main(String args[]) {

        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }

        ArrayList<cliente> v_clientes = new ArrayList<>();
        ArrayList<Thread> v_hebras = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);
        int totalClientes = 0;

        int opcion = -1;

        do {

            System.out.print("-- Sistema Donaciones (RMI -- David Martinez Diaz) -- \n");

            // En primer lugar indica al usuario que nos diga que replica quiere que tenga
            // clientes asociados desde
            // el principio

            System.out.print("--> Indica a que replica quieres asociarle los clientes: ");
            String replica = scanner.nextLine();
            System.out.println("--> Nº Clientes: ");
            int numClientes = Integer.parseInt(scanner.nextLine());

            // Nos creamos un vector con todos los clientes para luego crear las hebras
            // correspondientes

            for (int i = 0; i < numClientes; i++) {
                v_clientes.add(new cliente("localhost", replica, scanner));
            }

            totalClientes += numClientes;

            do {

                // Aqui preguntamos si queremos asociarle clientes a otra replica o no hace
                // falta.

                System.out.println("\n -- ¿Que operacion desea realizar? --");
                System.out.println("1. Deseo conectarme con otra replica.");
                System.out.println("2. Continuar.");

                System.out.println("Introduzca la opcion ==> ");
                opcion = Integer.parseInt(scanner.nextLine());

            } while (opcion != 1 && opcion != 2);

        } while (opcion != 2);

        // Lanzamos los clientes (hebras)
        for (int i = 0; i < totalClientes; i++) {
            v_hebras.add(new Thread(v_clientes.get(i), Integer.toString(i)));
            v_hebras.get(i).start();
        }


    }

    @Override
    public void run() {

        try {

            // Aqui es lo que hara cada cliente de manera automatica

            // -- OPERACIONES QUE REALIZARA CADA CLIENTE -- //

            // 1. El cliente entrara en la replica que tenga asociada
            String id_cliente = Thread.currentThread().getName();
            System.out.println("Cliente [" + id_cliente + "] entra en la Replica [" + replica + "].");

            // 2. Montamos el servicio para acceder a los objetos remotos que haya.
            Registry registry = LocateRegistry.getRegistry(host, 1099);

            // 3. El cliente se va a registrar en el sistema para ello utiliza la Interfaz
            // de Replica-Donaciones
            // que es propio de los clientes con el servidor

            donaciones_i donacion = (donaciones_i) registry.lookup("Replica" + replica + "-Donaciones");
            String replica_Registrada = Integer.toString(donacion.registrarCliente(Integer.parseInt(id_cliente)));
            System.out.println("--> Cliente [" + id_cliente + "] registrado en Replica " + replica_Registrada);

            // 4. Una vez registrado, el cliente donara una cantidad aleatoria entre 0-500
            // en la replica donde este registrada
            int cant_donar = new Random().nextInt(500);
            System.out.println(
                    "Cliente [" + id_cliente + "] dona en la Replica [" + replica_Registrada + "] ==> " + cant_donar);

            // 5. Cambiamos el objeto a la replica donde esta registrado el cliente
            if (this.replica != replica_Registrada) {
                donacion = (donaciones_i) registry.lookup("Replica" + replica_Registrada + "-Donaciones");
            }

            // 6. Donacion
            donacion.donar(cant_donar, Integer.parseInt(id_cliente));

            // 7. Mostrar total de donaciones
            System.out.println("Cliente [" + id_cliente + "]" + " ha solicitado el total de donaciones ==>"
                    + donacion.getTotalDonaciones());

            // Para probar las nuevas operaciones adicionales, vamos a ejecutar solo para la
            // hebra 0

            if (Integer.parseInt(Thread.currentThread().getName()) == 0) {

                Thread.sleep(2000);
                int opcion;

                System.out.println("\n -- Interfaz para el cliente [0] --");

                do {

                    do {

                        // Aqui preguntamos si queremos asociarle clientes a otra replica o no hace
                        // falta.

                        System.out.println("\n -- ¿Que operacion desea realizar? --");
                        System.out.println("1. Realizar una donacion.");
                        System.out.println("2. Retirar una cantidad de donacion.");
                        System.out.println("3. Consultar las donaciones de un cliente.");
                        System.out.println("4. Consultar maximo donador.");
                        System.out.println("5. Consultar Total de Donaciones.");
                        System.out.println("6. Terminar.");

                        System.out.println("Introduzca la opcion ==> ");
                        opcion = Integer.parseInt(scanner.nextLine());
                    } while (opcion < 1 && opcion > 6);

                    switch (opcion) {

                        case 1:

                            int cantidadDonar = 0;
                            do {
                                System.out.println("Cantidad a donar ==> ");
                                cantidadDonar = Integer.parseInt(scanner.nextLine());
                            } while (cantidadDonar < 0);

                            donacion.donar(cantidadDonar, Integer.parseInt(id_cliente));
                            System.out.println(
                                    "Cliente [" + id_cliente + "] dona en la Replica [" + replica_Registrada + "] ==> "
                                            + cantidadDonar);

                            break;

                        case 2:

                            int cantidadRetirar = 0;
                            do {
                                System.out.println("Cantidad a retirar ==> ");
                                cantidadRetirar = Integer.parseInt(scanner.nextLine());
                            } while (cantidadRetirar < 0);

                            donacion.retirarDonacion(cantidadRetirar, Integer.parseInt(id_cliente));

                            System.out.println(
                                    "Cliente [" + id_cliente + "]" + " ha retirado la cantidad de " + cantidadRetirar);
                            System.out.println("Cliente [" + id_cliente + "]"
                                    + " ha solicitado el nuevo total de donaciones ==>"
                                    + donacion.getTotalDonaciones());

                            break;
                        
                        case 3:

                            int idClienteConsulta = 0;

                            do {
                                System.out.println("Introduzca la id ==> ");
                                idClienteConsulta = Integer.parseInt(scanner.nextLine());
                            } while (idClienteConsulta < 0);
                            
                            donaciones_i consultaCliente = (donaciones_i) registry.lookup("Replica0-Donaciones");

                            System.out.println("El cliente " +  idClienteConsulta + " tiene las siguientes donaciones: " + consultaCliente.consultarDonacionesCliente(idClienteConsulta));
                            break;

                        case 4:

                            List<Integer> maxDonador = donacion.consultarMaximoDonador();
                            System.out.println("El maximo donador es el cliente [" +  maxDonador.get(0) + "], sus donaciones: " + maxDonador.get(1));
                            break;
                        
                        case 5:

                            System.out.println("Cliente [0] ha solicitado el total de donaciones ==>"
                                                    + donacion.getTotalDonaciones());
                            break;
                        default:
                            break;
                    }

                } while (opcion != 6);

                scanner.close();
            }

        } catch (Exception e) {
            System.err.println("Error en el Cliente" + Thread.currentThread().getName());
            e.printStackTrace();
        }
    }
}