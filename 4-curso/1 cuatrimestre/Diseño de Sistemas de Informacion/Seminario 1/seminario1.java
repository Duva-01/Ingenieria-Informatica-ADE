/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package seminario1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Scanner;
import java.sql.*;

/**
 *
 * @author Miguel
 */
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
//PRIMERO HEMOS AÑADIDO EL ARCHIVO DLE DRIVER .JAR A LA LIBRERIA DEL PROYECTO
class Seminario1 {

    /*
    Funcion para establecer conexion con la BD y obtener el último codigo de
    pedido que insertamos ya que lo hacemos secuencialmente. 
    Si quisiésemos que lo crease el cliente simplemente bastaría con hacer una
    consulta y si existe la tupla con el cpedido que inserta el cliente se le
    comunica que no es válido.
     */
    static int obtenerNumPedido(Statement stmt) {
        int Cpedido = 0;
        try {
            String sql = "select MAX(cpedido) from pedido";
            ResultSet rs = stmt.executeQuery(sql);
            if (rs.next()) {
                Cpedido = rs.getInt("MAX(cpedido)");
                Cpedido++;
            }
        } catch (Exception e) {

        }
        return Cpedido;
    }

    /*
    Función para comprobar que una cadena sea entera y que no salte una excepción
    que acabe con la ejecución de nuestro programa
     */
    static boolean esEntero(String cadena) {
        try {
            Integer.parseInt(cadena);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    /*
    Función para visualizar el contenido de las tablas de la base de datos
     */
    static void mostrarContenidoTablas(Statement stmt) {
        try {

            String sql;
            sql = "select * from Stock";
            ResultSet rs = stmt.executeQuery(sql);
            System.out.println("Tabla Stock\n");
            while (rs.next()) {
                System.out.println("Cproducto " + rs.getInt("Cproducto") + " Cantidad " + rs.getInt("Cantidad") + "\n");
            }

            sql = "select * from Pedido";
            rs = stmt.executeQuery(sql);
            System.out.println("Tabla Pedido\n");
            while (rs.next()) {
                System.out.println("Cpedido " + rs.getInt("Cpedido") + " Ccliente " + rs.getInt("Ccliente") + " Fecha " + rs.getDate("Fechapedido").toString() + "\n");
            }

            sql = "select * from DetallePedido";
            rs = stmt.executeQuery(sql);
            System.out.println("Tabla DetallePedido\n");
            while (rs.next()) {
                System.out.println("Cproducto " + rs.getInt("Cproducto") + " Cpedido " + rs.getInt("Cpedido") + " Cantidad " + rs.getInt("Cantidad") + "\n");
            }

        } catch (Exception e) {
            System.out.println("\n No se ha podido leer la base de datos\n");
        }
    }

    public static void main(String args[]) {
        try {
            //step1 Cargamos la clase del driver  
            Class.forName("oracle.jdbc.driver.OracleDriver");

            //step2 Creamos el objeto conexión. Le indicamos qué driver: tipo de base de datos:tipo de conexión
            //: A qué servidor: qué puerto/nombre de la base de datos, usuario, contraseña
            Connection con = DriverManager.getConnection(
                    "jdbc:oracle:thin:@//oracle0.ugr.es:1521/practbd.oracle0.ugr.es", "x9112789", "x9112789");

            // Desactivamos el autoCommit tal y como se dijo en clase
            // para que no se apliquen los cambios permanentemente a no ser 
            //que hagamos un commit manualmente
            con.setAutoCommit(false);
            //step3 Creamos el objeto Statement, a través de él iremos ejecutando
            // las órdenes SQL
            Statement stmt = con.createStatement();
            int codigoPedido = 0;
            String sql;
            Scanner scan = new Scanner(System.in);
            boolean tablasCreadas = false;
            boolean terminar = false;

            /*
            Bucle principal del programa, en él tenemos las 4 opciones indicadas en la
            realización de las prácticas.
             */
            while (!terminar) {
                System.out.println("\n Bienvenido al SI del grupo DisMarket, elija que opción realizar:\n");
                System.out.println("1. Borrado y creacion de las tablas e insercion de 10 tuplas\n");
                System.out.println("2. Dar de alta un nuevo pedido\n");
                System.out.println("3. Mostrar el contenido de las tablas de la base de datos\n");
                System.out.println("4. Salir del programa y cerrar la conexión a la Base de datos\n");
                String rep = scan.nextLine();

                //Comprobación por si el usuario no introdujese números
                if (esEntero(rep)) {
                    int num = Integer.parseInt(rep);
                    //Por si no introdujese un número válido
                    if ((num > 4) || (num <= 0)) {
                        System.out.println("OPCION NO VALIDA, POR FAVOR INSERTE UN NUMERO DEL 1 AL 4\n");
                    } else if (num == 4) {
                        //La opción 4 pone a true la condición del bucle y termina la ejecución de la aplicación
                        terminar = true;
                        System.out.println("Saliendo del sistema\n");
                    } else if (num == 1) {
                        //Borrado de las tablas. Si no estaban creadas se crea una excepción que manejamos mediante
                        // el uso de try catch para que no finalice la ejecución de nuestra aplicación
                        try {
                            sql = "drop table DetallePedido";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla DetallePedido");
                        }
                        try {
                            sql = "drop table Stock";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Stock");
                        }
                        try {
                            sql = "drop table Pedido";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Pedido");
                        }

                        // Creación de las tablas
                        try {
                            sql = "CREATE TABLE Stock "
                                    + "(Cproducto INT PRIMARY KEY, "
                                    + "Cantidad number CONSTRAINT stock_mayor_0"
                                    + "    CHECK (Cantidad>=0)) ";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla Stock");
                            sql = "delete from Stock";
                            stmt.executeUpdate(sql);
                        }

                        try {
                            sql = "create table Pedido( "
                                    + " Cpedido int primary key, "
                                    + "Ccliente int, "
                                    + "Fechapedido DATE) ";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla Pedido");
                            sql = "delete from Pedido";
                            stmt.executeUpdate(sql);
                        }

                        try {
                            sql = "create table DetallePedido( "
                                    + "Cpedido references Pedido(Cpedido),"
                                    + "Cproducto references Stock(Cproducto),"
                                    + "Cantidad int CONSTRAINT stock_pedido_mayor_0 CHECK (Cantidad>0),"
                                    + "primary key (Cpedido, Cproducto))";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla DetallePedido");
                            sql = "delete from DetallePedido";
                            stmt.executeUpdate(sql);
                        }

                        //Inserción de tuplas. Podríamos haber hecho todo mediante la inclusión de las
                        // órdenes SQL a un Lote (batch) teniendo el mismo resultado.
                        sql = "INSERT INTO Stock VALUES ( 0000 ,0)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0001 ,1)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0010 ,2)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0011 ,3)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0100 ,4)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0101 ,5)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0110 ,6)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 0111 ,7)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 1000 ,8)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 1001 ,9)";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO Stock VALUES ( 1010 ,10)";
                        stmt.executeQuery(sql);
                        tablasCreadas = true;

                        // Hacemos commit para actualizar la base de datos
                        con.commit();
                        mostrarContenidoTablas(stmt);
                    } else if (num == 2) {
                        // Opción 2, el usuario ha elegido realizar un nuevo pedido
                        Scanner scan2 = new Scanner(System.in);
                        boolean codigoClienteCorrecto = true;
                        boolean codigoProductoExiste = true;
                        boolean codigoEntero = false;
                        String codCliente = "";
                        //Bucle para que el usuario indique un código de cliente válido
                        while (!codigoEntero) {
                            System.out.println("\nPor favor indique su codigo de cliente (debe ser un numero): \n");
                            codCliente = scan2.nextLine();
                            if (esEntero(codCliente)) {
                                if (Integer.parseInt(codCliente) > 0) {
                                    codigoEntero = true;
                                }
                            }
                        }

                        // Vamos a suponer que el sistema crea el codigo de pedido y la fecha a traves de SYSDATE
                        // ya que sería lo más realista.
                        //Empleamos el método anterioremente visto. En un principio actualizábamos el entero codigoPedido
                        // pero nos dimos cuenta que si volviamos a iniciar la aplicación el codigo de pedido se iba a repetir
                        // y habría saltado una excepción en la ejecución del programa. Se supone que el inicio de una transacción
                        //bloquea la tabla.
                        //Respecto a la fecha simplemente deberíamos de haber implementado un método que comprobase que compro
                        //base que el usuario introdujo una fecha con el sistema dd/mm/aaaa, algo que no atañe a la asignatura y se
                        //ría de fácil implementación.
                        //Con el bucle nos aseguramos que el código funciona correctamente incluso en casos de concurrencia en la base de datos
                        boolean insertadoCorrecto = false;
                        while (!insertadoCorrecto) {
                            try {
                                codigoPedido = obtenerNumPedido(stmt);
                                String datosPedido = "insert into Pedido values (" + Integer.toString(codigoPedido) + "," + codCliente + ", SYSDATE)";
                                stmt.executeQuery(datosPedido);
                                insertadoCorrecto = true;
                            } catch (Exception e) {
                                System.out.println("Reintentando inserción de pedido, un momento...\n");
                            }
                        }

                        boolean terminarSubmenu = false;
                        boolean datosProductoInsertados = false;
                        Savepoint antesDeProducto = null;
                        while (!terminarSubmenu) {
                            System.out.println("1. Aniadir detalle de producto\n");
                            System.out.println("2. Eliminar detalles de producto\n");
                            System.out.println("3. Cancelar pedido\n");
                            System.out.println("4. Finalizar pedido\n");
                            Scanner scan3 = new Scanner(System.in);
                            String opSubmenu = scan3.nextLine();

                            while (!esEntero(opSubmenu)) {
                                System.out.println("Por favor, introduzca un numero del 1 al 4\n");
                                scan3 = new Scanner(System.in);
                                opSubmenu = scan3.nextLine();
                            }
                            int opcion = Integer.parseInt(opSubmenu);
                            if (opcion == 1) {
                                if (datosProductoInsertados) {
                                    System.out.println("\n -- ERROR, YA HAY UNOS DATOS INSERTADOS. SI QUIERE VOLVER A INSERTAR ANTES DEBE DE ELIMINAR DATOS PRODUCTO (OPCION 2)\n");
                                } else {
                                    boolean errores = false;
                                    antesDeProducto = con.setSavepoint();
                                    System.out.println("\nPor favor indique su codigo de producto (debe ser un numero): \n");
                                    String codProducto;
                                    Scanner scan4 = new Scanner(System.in);
                                    codProducto = scan4.nextLine();
                                    try {
                                        sql = "select * from Stock where Cproducto=" + codProducto;
                                        ResultSet rs = stmt.executeQuery(sql);
                                        if (!rs.next()) {
                                            errores = true;
                                        }
                                    } catch (Exception e) {
                                        errores = true;
                                    }

                                    if (errores) {
                                        System.out.println("\nError en la introducción del codigo de producto, no se va a insertar. Reintente de nuevo\n");
                                    }

                                    if (!errores) {
                                        boolean CantidadEnteroPositivo = false;
                                        String cantidad = "";
                                        while (!CantidadEnteroPositivo) {
                                            System.out.println("\nPor favor indique cantidad (numero positivo): \n");
                                            Scanner scan5 = new Scanner(System.in);
                                            cantidad = scan5.nextLine();
                                            if (esEntero(cantidad) && Integer.parseInt(cantidad) > 0) {
                                                CantidadEnteroPositivo = true;
                                            }
                                        }
                                        try {
                                            sql = "update Stock set Cantidad = Cantidad  - " + cantidad + " where Cproducto = " + codProducto;
                                            stmt.executeQuery(sql);
                                            sql = "insert into DetallePedido values (" + Integer.toString(codigoPedido) + ", " + codProducto + ", " + cantidad + ") ";
                                            stmt.executeQuery(sql);
                                        } catch (Exception e) {
                                            System.out.println("No hay suficiente cantidad del producto, no vamos a insertar la tupla. Intentelo de nuevo\n");
                                            errores = true;
                                        }

                                        if (!errores) {
                                            datosProductoInsertados = true;

                                            System.out.println("Se ha insertado correctamente los datos del producto, puede realizar el pedido\n");
                                        }
                                    }
                                }
                            } else if (opcion == 2 && antesDeProducto != null) {
                                datosProductoInsertados = false;
                                con.rollback(antesDeProducto);
                                mostrarContenidoTablas(stmt);
                            } else if (opcion == 3) {
                                //Este es un rollback a secas porque queremos terminar la transacción actual
                                // Si lo hiciésemos hasta un savepoint no terminaría dicha transacción
                                con.rollback();
                                terminarSubmenu = true;
                            } else if (opcion == 4 && datosProductoInsertados) {
                                con.commit();
                                terminarSubmenu = true;
                            } else if (opcion == 4 && !datosProductoInsertados) {
                                System.out.println("Introduzca los datos del producto correctamente o cancele el pedido\n");
                            } else if (opcion == 5) {
                                mostrarContenidoTablas(stmt);
                            }
                        }
                        mostrarContenidoTablas(stmt);
                        con.commit();
                    } else if (num == 3) {
                        mostrarContenidoTablas(stmt);
                        con.commit();
                    }
                } else {
                    System.out.println("Inserte un numero por favor\n");
                }
            }

//step5 close the connection object  
            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }

    }
}