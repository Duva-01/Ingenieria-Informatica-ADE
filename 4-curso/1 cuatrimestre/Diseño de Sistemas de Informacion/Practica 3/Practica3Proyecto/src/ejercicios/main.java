/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package practica3Coco.pkg3;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Savepoint;
import java.sql.Statement;
import java.util.Scanner;

/**
 *
 * @author Miguel
 */
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
//PRIMERO HEMOS AÑADIDO EL ARCHIVO DLE DRIVER .JAR A LA LIBRERIA DEL PROYECTO
class Practica3Coco {

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

    static boolean esFloat(String cadena) {
        try {
            Float.parseFloat(cadena);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    static String formatear(String cadena) {
        boolean decimales = false;
        boolean terminar = false;
        int n_dec = 0;
        for (int i = 0; i < cadena.length() & !terminar; i++) {
            if (decimales) {
                if (n_dec == 1) {
                    cadena = cadena.substring(0, i);
                    terminar = true;
                } else {
                    n_dec++;
                }

            }
            if (cadena.charAt(i) == '.') {
                decimales = true;
            }
        }
        return cadena;
    }

    static boolean esUnica(Statement stmt, String NSegSoc) {
        String sql = "select * from Empleado where NSegSoc = '" + NSegSoc + "'";
        boolean esUnica = true;
        try {
            ResultSet rs = stmt.executeQuery(sql);
            if (rs.next()) {
                esUnica = false;
            }
        } catch (Exception e) {

        }
        return esUnica;
    }

    /*
    Función para visualizar el contenido de las tablas de la base de datos
     */
     static void mostrarContenidoTablasMarketplace(Statement stmt) {
        // Mostrar tablas
        ResultSet rs;
        try {
            String sql;
            sql = "select * from ProductoAlmacena";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla ProductoAlmacena:\n");
            while( rs.next()){
                System.out.println("Nombre: " + rs.getString("nombre")+ " Referencia: " + rs.getString("referencia") + " Stock: " + rs.getString("stock") +" IdentificadorAlmacen: " + rs.getString("IdentificadorAlmacen") +"\n");
            }
            sql = "select * from Proveedor";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla Proveedor:\n");
            while( rs.next()){
                System.out.println("Nombre: " + rs.getString("nombre")+ " CIF: " + rs.getString("cif") +  " direccion: " + rs.getString("direccion") +"\n");
            }
            sql = "select * from suministra";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla suministra:\n");
            while( rs.next()){
                System.out.println("CIF: " + rs.getString("cif")+ "Referencia: " + rs.getString("Referencia") + "\n");
            }
            

        } catch (Exception e) {
            System.out.println("\n No se ha podido leer la base de datos\n");
        }
    }
    
    static void mostrarContenidoTablas(Statement stmt) {
        try {

            String sql;
            sql = "select * from Empleado";
            ResultSet rs = stmt.executeQuery(sql);
            System.out.println("Tabla Empleado\n");
            while (rs.next()) {
                System.out.println("Nombre " + rs.getString("Nombre") + " Apellidos " + rs.getString("Apellidos") + " Telefono " + rs.getString("Telefono") + " DNI " + rs.getString("DNI") + " Cuenta Bancaria: " + rs.getString("CuentaBancaria") + " Direccion: " + rs.getString("Direccion") + " Num. Seg Social: " + rs.getString("NSegSoc") + " Puesto: " + rs.getString("Puesto") + " Turno: " + rs.getString("Turno") + " Sueldo: " + rs.getFloat("Sueldo") + "\n");
            }
            sql = "select * from MetodoDeTransporte";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla MetodoDeTransporte\n");
            while( rs.next()){
                System.out.println("Matricula: " + rs.getString("matricula")+ "\nTipo: " + rs.getString("Tipo") + "\nMarca: " + rs.getString("Marca") + "\nAsignado: " + rs.getInt("Asignado") + "\nsubcontratacion: " + rs.getInt("Asignado") + "\n");
            }
            sql = "select * from Ruta";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla Ruta\n");
            while( rs.next()){
                System.out.println("Codigo de ruta: " + rs.getString("Cod_Ruta")+ "\nOrigen: " + rs.getString("origen") + "\nDestino: " + rs.getString("destino") + "\nKilometraje: " + rs.getInt("kilometraje") + "\n");
            }
            sql = "select * from Asigna";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla Asigna\n");
            while( rs.next()){
                System.out.println("Matricula: " + rs.getString("matricula")+ "\nCodigo de Pedido: " + rs.getString("Cod_pedido") + "\n");
            }
            sql = "select * from AsignaR";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla AsignaR\n");
            while( rs.next()){
                System.out.println("Matricula: " + rs.getString("matricula")+ "\nCodigo de Ruta: " + rs.getString("Cod_Ruta") + "\n");
            }
            
            mostrarContenidoTablasMarketplace(stmt);
            


        } catch (Exception e) {
            System.out.println("\n No se ha podido leer la base de datos\n");
        }
    }
   
    static void mostrarContenidoTablas4(Statement stmt) {
        try {

            String sql;
            sql = "select * from MetodoDeTransporte";
            ResultSet rs =stmt.executeQuery(sql);
            System.out.println("Tabla MetodoDeTransporte\n");
            while( rs.next()){
                System.out.println("Matricula: " + rs.getString("matricula")+ "\nTipo: " + rs.getString("Tipo") + "\nMarca: " + rs.getString("Marca") + "\nAsignado: " + rs.getInt("Asignado") + "\nsubcontratacion: " + rs.getInt("Asignado") + "\n");
            }
            sql = "select * from Ruta";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla Ruta\n");
            while( rs.next()){
                System.out.println("Codigo de ruta: " + rs.getString("Cod_Ruta")+ "\nOrigen: " + rs.getString("origen") + "\nDestino: " + rs.getString("destino") + "\nKilometraje: " + rs.getInt("kilometraje") + "\n");
            }
            sql = "select * from Asigna";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla Asigna\n");
            while( rs.next()){
                System.out.println("Matricula: " + rs.getString("matricula")+ "\nCodigo de Pedido: " + rs.getString("Cod_pedido") + "\n");
            }
            sql = "select * from AsignaR";
            rs =stmt.executeQuery(sql);
            System.out.println("Tabla AsignaR\n");
            while( rs.next()){
                System.out.println("Matricula: " + rs.getString("matricula")+ "\nCodigo de Ruta: " + rs.getString("Cod_Ruta") + "\n");
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
                System.out.println("\n Bienvenido al SI del grupo DisMarket, elija que opcion realizar:\n");
                System.out.println("0. Borrado y creacion de las tablas e insercion de tuplas\n");
                System.out.println("1. Acceso al subsistema de Gestion de Clientes\n");
                System.out.println("2. Acceso al subsistema de Gestion de Empleados\n");
                System.out.println("3. Acceso al subsistema de Gestion de Marketplace\n");
                System.out.println("4. Acceso al subsistema de Gestion de Logi­stica\n");
                System.out.println("5. Acceso al subsistema de Gestion de Almacenes\n");
                System.out.println("6. Mostrar el contenido de las tablas de la base de datos\n");
                System.out.println("7. Salir del programa y cerrar la conexion a la Base de datos\n");
                String rep = scan.nextLine();

                //Comprobación por si el usuario no introdujese números
                if (esEntero(rep)) {
                    int num = Integer.parseInt(rep);
                    //Por si no introdujese un número válido
                    if ((num > 7) || (num < 0)) {
                        System.out.println("OPCION NO VALIDA, POR FAVOR INSERTE UN NUMERO DEL 1 AL 4\n");
                    } else if (num == 7) {
                        //La opción 7 pone a true la condición del bucle y termina la ejecución de la aplicación
                        terminar = true;
                        System.out.println("Saliendo del sistema\n");
                    } else if (num == 6) {
                        mostrarContenidoTablas(stmt);
                    } else if (num == 0) {
                        //Borrado de las tablas. Si no estaban creadas se crea una excepción que manejamos mediante
                        // el uso de try catch para que no finalice la ejecución de nuestra aplicación
                        //Tabla de Miguel
                        try {
                            sql = "drop table Empleado";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Empleado");
                        }                        
                        //Tabla de Maria
                        try {
                            sql = "drop table suministra";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla suministra");
                        }
                        //Tabla de Maria
                        try {
                            sql = "drop table Proveedor";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Proveedor");
                        }
                        
                        // tabla de FJ
                        try {
                            sql = "drop table Asigna";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Asigna");
                        }
                        
                        //INSERTAR AQUI DROP PEDIDOCONFORMA
                                
                        
                        
                        
                        //Tabla Maria
                        try {
                            sql = "drop table ProductoAlmacena";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla ProductoAlmacena");
                        }
                        
                        //INSERTAR AQUI DROP ALMACEN
                        try {
                            sql = "drop table Almacen";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Almacen");
                        }
                        
                        

                        // tabla de FJ
                        try {
                            sql = "drop table AsignaR";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla AsignaR");
                        }

                        // tabla de FJ
                        try {
                            sql = "drop table MetodoDeTransporte";
                            stmt.executeUpdate(sql);

                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla MetodoDeTransporte");
                        }
                        
                        // tabla de FJ
                        try {
                            sql = "drop table Ruta";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("No estaba creada la tabla Ruta");
                        }   
                        
                        
                        //INSERTAR AQUI DROP CLIENTE
                        


                        // Creación de las tablas
                        try {
                            sql = "create table Empleado("
                                    + "    Nombre varchar(20) NOT NULL,"
                                    + "    Apellidos varchar(40) NOT NULL,"
                                    + "    Telefono varchar(20) NOT NULL,"
                                    + "    DNI varchar(9) primary key,"
                                    + "    CuentaBancaria varchar(20) NOT NULL,"
                                    + "    Direccion varchar(60) NOT NULL,"
                                    + "    NSegSoc varchar(20) unique not null,"
                                    + "    Puesto varchar(20) NOT NULL,"
                                    + "    Turno varchar(20) NOT NULL,"
                                    + "    Sueldo float(2) NOT NULL check(Sueldo>=0)"
                                    + ") ";
                            stmt.executeUpdate(sql);
                            
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla Empleado");
                            sql = "delete from Empleado";
                            stmt.executeUpdate(sql);
                        }
                        
                        //INSERTAR AQUI CREATE TABLE CLIENTE
                        
                        
                        //INSERTAR AQUI CREATE TABLE ALMACEN
                        try {
                            
                            String sqlAlmacen = "create table Almacen(\n"
                                    + "    Identificador varchar(20) primary key,"
                                    + "    Nombre varchar(20),"
                                    + "    Direccion varchar(40),"
                                    + "    Tamanio int"
                                    + ") ";

                            stmt.executeUpdate(sqlAlmacen);
                        } catch (SQLException e) {
                            System.out.println(e);
                            System.out.println("Ya estaba creada la tabla Almacen");
                            String aux = "delete from productoAlmacena";
                            try{
                                stmt.executeUpdate(aux);
                            }catch(SQLException exception){
                                
                            }
                            String eliminarTablaAlmacen = "delete from Almacen";
                            stmt.executeUpdate(eliminarTablaAlmacen);
                        }
                        
                        //Tabla de Maria
                        try {
                            sql = "create table ProductoAlmacena(\n"
                                    + "    Nombre varchar(20),"
                                    + "    Referencia varchar(20) primary key,"
                                    + "    Stock int default 0,"
                                    + "    IdentificadorAlmacen varchar(10),"
                                    + "    foreign key (IdentificadorAlmacen) references Almacen(Identificador))"; 
      
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla ProductoAlmacena");
                            System.out.println(e);
                            
                            sql = "delete from ProductoAlmacena";
                            stmt.executeUpdate(sql);
                        } 
                        
                        
                        //INSERTAR AQUI CREATE TABLE PEDIDOCONFORMA
                        
                        
                        // Tabla de FJ
                        try {
                            sql = "CREATE TABLE Ruta( "
                                    + "Cod_Ruta varchar2(9), "
                                    + "origen varchar2(20) NOT NULL,"
                                    + "destino varchar2(20) NOT NULL,"
                                    + "kilometraje int NOT NULL,"
                                    + "primary key(Cod_Ruta) )";
                            stmt.executeUpdate(sql);
                            
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla Ruta");
                            sql = "delete from Ruta";
                            stmt.executeUpdate(sql);
                        }

                        //tabla de FJ
                        try {
                            sql = "CREATE TABLE MetodoDeTransporte( "
                                    + "matricula varchar2(7), "
                                    + "Tipo varchar2(20),"
                                    + "Marca varchar2(10),"
                                    + "Asignado int ,"
                                    + "subcontratacion int ,"
                                    + "primary key(matricula) )";
                            stmt.executeUpdate(sql);
                            
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla MetodoDeTransporte");
                            sql = "delete from MetodoDeTransporte";
                            stmt.executeUpdate(sql);
                        }
                        
                        // tabla de FJ
                        try {
                            sql = "CREATE TABLE AsignaR( "
                                    + "matricula varchar2(7), "
                                    + "Cod_Ruta varchar2(9),"
                                    + "primary key(matricula),"
                                    + "foreign key(Cod_Ruta) references Ruta(Cod_Ruta),"
                                    + "foreign key(matricula) references MetodoDeTransporte(matricula) )";
                                   
                            stmt.executeUpdate(sql);
                            
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla AsignaR");
                            sql = "delete from AsignaR";
                            stmt.executeUpdate(sql);
                        }


                        // tabla de FJ
                        try {
                            sql = "CREATE TABLE Asigna( "
                                    + "matricula varchar2(7), "
                                    + "Cod_pedido varchar2(9),"
                                    + "primary key(matricula),"
                                    //+ "foreign key(Cod_pedido) references PedidoConforma(Cod_pedido),"
                                    + "foreign key(matricula) references MetodoDeTransporte(matricula) )";
                                   
                            stmt.executeUpdate(sql);
                            
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla Asigna");
                            sql = "delete from Asigna";
                            stmt.executeUpdate(sql);
                        }
                        
                        //Tabla de Maria
                        try {
                            sql = "create table Proveedor(\n"
                                    + "    Nombre varchar(20),"
                                    + "    cif varchar(20),"
                                    + "    direccion varchar(60),"
                                    + "    primary key( cif))";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla Proveedor");
                            sql = "delete * from Proveedor";
                            stmt.executeUpdate(sql);
                        }
                        
                        //Tabla de Maria
                        try {
                            sql = "create table suministra(\n"
                                    + "    cif REFERENCES Proveedor(cif),"
                                    + "    referencia REFERENCES ProductoAlmacena (referencia),"
                                    + "    PRIMARY KEY (referencia)"
                                    + ") ";
                            stmt.executeUpdate(sql);
                        } catch (SQLException e) {
                            System.out.println("Ya estaba creada la tabla suministra");
                            sql = "delete * from suministra";
                            stmt.executeUpdate(sql);
                        }
                        

                        
                        //Inserción de tuplas. Podríamos haber hecho todo mediante la inclusión de las
                        // órdenes SQL a un Lote (batch) teniendo el mismo resultado.
                        
                        //Datos empleado
                        sql = "insert into Empleado values ('Pedro', 'García', '111111111', '00000001X', '0','C/ Santa Amalia', '1', 'Reponedor', 'Mañanas', 1200.00)";
                        stmt.executeQuery(sql);
                        sql = "insert into Empleado values ('Paco', 'Pérez', '222222222', '00000002X', '1','C/ Santa Clotilde', '2', 'Directivo', 'Tardes', 1800.00)";
                        stmt.executeQuery(sql);
                        sql = "insert into Empleado values ('Manolo', 'Jiménez', '333333333', '00000003X', '2','C/ San Pedro', '3', 'Reponedor', 'Tardes', 2000.00)";
                        stmt.executeQuery(sql);
                        sql = "insert into Empleado values ('Manoli', 'Jiménez', '444444444', '00000004X', '3','C/ Santo Tomás', '4', 'Reponedor', 'Mañanas', 1200.00)";
                        stmt.executeQuery(sql);
                        sql = "insert into Empleado values ('Andrea', 'Alcántara', '612121212', '00000005X', '4','C/ Santa María', '5', 'Directiva', 'Tardes', 3000.00)";
                        stmt.executeQuery(sql);
                        
                        
                        //INSERTAR AQUI DATOS CLIENTE
                        
                        
                        
                        System.out.println("LLego aqui");
                        //INSERTAR AQUI DATOS ALMACEN
                        String insercion_tuplas_almacen_sql = "insert into Almacen values ('000000000J', 'Almacen1', 'C/ Camino Ronda NÂº 6', 1100)";
                        stmt.executeQuery(insercion_tuplas_almacen_sql);

                        insercion_tuplas_almacen_sql = "insert into Almacen values ('000000000M', 'Almacen2', 'C/ Recogidas NÂº 22', 1400)";
                        stmt.executeQuery(insercion_tuplas_almacen_sql);

                        insercion_tuplas_almacen_sql = "insert into Almacen values ('000000000T', 'Almacen3', 'C/ Doctor Oloriz NÂº 39', 990)";
                        stmt.executeQuery(insercion_tuplas_almacen_sql);

                        insercion_tuplas_almacen_sql = "insert into Almacen values ('000000000S', 'Almacen4', 'C/ Padre Marcelino NÂº 2', 1800)";
                        stmt.executeQuery(insercion_tuplas_almacen_sql);

                        insercion_tuplas_almacen_sql = "insert into Almacen values ('000000000P', 'Almacen5', 'C/ San Agustin NÂº 44', 3300)";
                        stmt.executeQuery(insercion_tuplas_almacen_sql);
                        
                        
                        
                        //Datos ProductoAlmacena
                        sql = "insert into ProductoAlmacena values ('Fidget Spinner', '000001X', 0, '000000000J')";
                        stmt.executeQuery(sql);
                        sql = "insert into ProductoAlmacena values ('Peonza', '000002B', 0, '000000000M')";
                        stmt.executeQuery(sql);
                        sql = "insert into ProductoAlmacena values ('BleyBlade', '000012Z', 0, '000000000T')";
                        stmt.executeQuery(sql);
                        sql = "insert into ProductoAlmacena values ('Domino', '000011L', 0, '000000000J')";
                        stmt.executeQuery(sql);
                        sql = "insert into ProductoAlmacena values ('Parchis', '000031W', 0, '000000000P')";
                        stmt.executeQuery(sql);           
                        
                        //INSERTAR AQUI DATOS PEDIDOCONFORMA
                        
                        
                        
                        
                        //Datos Ruta
                        sql = "insert into Ruta values ('111111111','A','B',100)";
                        stmt.executeQuery(sql);
                        sql = "insert into Ruta values ('222222222','B','C',150)";
                        stmt.executeQuery(sql);
                        sql = "insert into Ruta values ('333333333','C','D',200)";
                        stmt.executeQuery(sql);
                        sql = "insert into Ruta values ('444444444','D','E',250)";
                        stmt.executeQuery(sql);
                        sql = "insert into Ruta values ('555555555','E','A',300)";
                        stmt.executeQuery(sql);
                        
                        //Datos MetodoDeTransporte
                        sql = "insert into MetodoDeTransporte values ('1111abc','furgoneta','Toyota',0,0)";
                        stmt.executeQuery(sql);
                        sql = "insert into MetodoDeTransporte values ('2222abc','coche','seat',0,0)";
                        stmt.executeQuery(sql);
                        sql = "insert into MetodoDeTransporte values ('3333abc','moto','peugeot',0,0)";
                        stmt.executeQuery(sql);
                        sql = "insert into MetodoDeTransporte values ('4444abc','furgoneta','Toyota',0,0)";
                        stmt.executeQuery(sql);
                        sql = "insert into MetodoDeTransporte values ('5555abc','coche','nissan',0,0)";
                        stmt.executeQuery(sql);
                        
                        //DatosAsignaR
                        sql = "insert into AsignaR values ('1111abc','111111111')";
                        stmt.executeQuery(sql);
                        sql = "insert into AsignaR values ('2222abc','222222222')";
                        stmt.executeQuery(sql);
                        sql = "insert into AsignaR values ('3333abc','333333333')";
                        stmt.executeQuery(sql);
                        sql = "insert into AsignaR values ('4444abc','444444444')";
                        stmt.executeQuery(sql);
                        sql = "insert into AsignaR values ('5555abc','555555555')";
                        stmt.executeQuery(sql);
                               
                        //Datos Asigna
                        sql = "insert into Asigna values ('1111abc','000001X')";
                        stmt.executeQuery(sql);
                        sql = "insert into Asigna values ('2222abc','000002B')";
                        stmt.executeQuery(sql);
                        sql = "insert into Asigna values ('3333abc','000012Z')";
                        stmt.executeQuery(sql);
                        sql = "insert into Asigna values ('4444abc','000011L')";
                        stmt.executeQuery(sql);
                        sql = "insert into Asigna values ('5555abc','000031W')";
                        stmt.executeQuery(sql);
                        
                        //Datos Proveedor
                        sql = "insert into Proveedor values ('Cristal Mesina', 'B67657189',  'C/Azabache 3,Granada')";
                        stmt.executeQuery(sql);
                        sql = "insert into Proveedor values ('Mesas Cristalinas', 'B13829940','C/Suspiro s/n, Padul')";
                        stmt.executeQuery(sql);
                        sql = "insert into Proveedor values ('Lesla S.A.','S07948674','Gran Via 1, Granada')";
                        stmt.executeQuery(sql);
                        sql = "insert into Proveedor values ('GRUNDASA','B07633001','C/Ancha 13, Guadix')";
                        stmt.executeQuery(sql);
                        sql = "insert into Proveedor values ('NavideÃ±a SL','B86910650','Avd Dilar 4, Granada')";
                        stmt.executeQuery(sql);
                        
                        
                        //Datos suministra
                        sql = "INSERT INTO suministra VALUES('B67657189','000001X')";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO suministra VALUES('B13829940','000002B')";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO suministra VALUES('S07948674','000012Z')";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO suministra VALUES('B07633001','000011L')";
                        stmt.executeQuery(sql);
                        sql = "INSERT INTO suministra VALUES('B86910650','000031W')";
                        stmt.executeQuery(sql);

                        
                        tablasCreadas = true;

                        // Hacemos commit para actualizar la base de datos
                        con.commit();
                        mostrarContenidoTablas(stmt);
                    } else if (num == 2) {
                        // Opción 2, el usuario ha elegido el Subsistema de Gestión de Empleados
                        boolean terminarSubmenu = false;
                        boolean datosProductoInsertados = false;

                        while (!terminarSubmenu) {
                            System.out.println("1. Contratar empleado\n");
                            System.out.println("2. Despedir empleado\n");
                            System.out.println("3. Modificar datos empleado\n");
                            System.out.println("4. Consultar empleado\n");
                            System.out.println("5. Modificar puesto de trabajo de empleado\n");
                            System.out.println("6. Salir del submenu\n");

                            Scanner scan3 = new Scanner(System.in);
                            String opSubmenu = scan3.nextLine();

                            while (!esEntero(opSubmenu)) {
                                System.out.println("Por favor, introduzca un numero del 1 al 5\n");
                                scan3 = new Scanner(System.in);
                                opSubmenu = scan3.nextLine();
                            }
                            int opcion = Integer.parseInt(opSubmenu);
                            if (opcion == 1) {
                                boolean errores = false;
                                System.out.println("\nPor favor indique el NOMBRE del empleado: \n");
                                String nombreEmpleado;
                                Scanner scan4 = new Scanner(System.in);
                                nombreEmpleado = scan4.nextLine();
                                while (nombreEmpleado.length() > 20) {
                                    System.out.println("\nNombre no válido, intentelo de nuevo\n");
                                    Scanner scanNombre = new Scanner(System.in);
                                    nombreEmpleado = scanNombre.nextLine();
                                }
                                System.out.println("\nPor favor indique los APELLIDOS del empleado: \n");
                                String apellidoEmpleado;
                                Scanner scanEmpleado = new Scanner(System.in);
                                apellidoEmpleado = scanEmpleado.nextLine();
                                while (nombreEmpleado.length() > 40) {
                                    System.out.println("\nApellidos no válido, intentelo de nuevo\n");
                                    Scanner scanAp = new Scanner(System.in);
                                    apellidoEmpleado = scanAp.nextLine();
                                }

                                System.out.println("\nPor favor indique el TELÉFONO del empleado: \n");
                                String Telefono;
                                Scanner scanTelefono = new Scanner(System.in);
                                Telefono = scanTelefono.nextLine();
                                while (Telefono.length() > 20 || !esEntero(Telefono)) {
                                    System.out.println("\nTelefono no válido, intentelo de nuevo\n");
                                    Scanner scanTel = new Scanner(System.in);
                                    Telefono = scanTel.nextLine();
                                }

                                System.out.println("\nPor favor indique el DNI del empleado: \n");
                                String DNI;
                                Scanner scanDNI = new Scanner(System.in);
                                DNI = scanDNI.nextLine();
                                while (DNI.length() > 20) {
                                    System.out.println("\nDNI no válido, intentelo de nuevo\n");
                                    Scanner scanDNIEmp = new Scanner(System.in);
                                    DNI = scanDNIEmp.nextLine();
                                }

                                System.out.println("\nPor favor indique la CUENTA BANCARIA del empleado: \n");
                                String cuentaBancaria;
                                Scanner scanBanc = new Scanner(System.in);
                                cuentaBancaria = scanBanc.nextLine();
                                while (cuentaBancaria.length() > 20 || !esEntero(cuentaBancaria)) {
                                    System.out.println("\nCuenta bancaria no válida, intentelo de nuevo\n");
                                    scanBanc = new Scanner(System.in);
                                    cuentaBancaria = scanBanc.nextLine();
                                }
                                System.out.println("\nPor favor indique la DIRECCIÓN del empleado: \n");
                                String Direccion;
                                Scanner scanDireccion = new Scanner(System.in);
                                Direccion = scanDireccion.nextLine();
                                while (Direccion.length() > 20) {
                                    System.out.println("\nDirección no válido, intentelo de nuevo\n");
                                    scanDireccion = new Scanner(System.in);
                                    Direccion = scanDireccion.nextLine();
                                }
                                System.out.println("\nPor favor indique el NÚMERO SEGURIDAD SOCIAL del empleado: \n");
                                String nSegSoc;
                                Scanner scanNSegSoc = new Scanner(System.in);
                                nSegSoc = scanNSegSoc.nextLine();
                                while (nSegSoc.length() > 20 && !esEntero(nSegSoc) || !esUnica(stmt, nSegSoc)) {
                                    System.out.println("\nNúmero de seguridad social no válido o ya existente, intentelo de nuevo\n");
                                    scanNSegSoc = new Scanner(System.in);
                                    nSegSoc = scanNSegSoc.nextLine();
                                }
                                if (esUnica(stmt, nSegSoc)) {
                                    System.out.println("\nEs Unica\n");
                                }
                                System.out.println("\nPor favor indique el PUESTO del empleado: \n");
                                String Puesto;
                                Scanner scanPuesto = new Scanner(System.in);
                                Puesto = scanPuesto.nextLine();
                                while (Puesto.length() > 20) {
                                    System.out.println("\nPuesto no válido, intentelo de nuevo\n");
                                    scanPuesto = new Scanner(System.in);
                                    Puesto = scanPuesto.nextLine();
                                }
                                System.out.println("\nPor favor indique el TURNO del empleado: \n");
                                String Turno;
                                Scanner scanTurno = new Scanner(System.in);
                                Turno = scanTurno.nextLine();
                                while (Turno.length() > 20) {
                                    System.out.println("\nTurno no válido, intentelo de nuevo\n");
                                    scanTurno = new Scanner(System.in);
                                    Turno = scanTurno.nextLine();
                                }
                                System.out.println("\nPor favor indique el SUELDO del empleado: \n");
                                String Sueldo;
                                Scanner scanSueldo = new Scanner(System.in);
                                Sueldo = scanSueldo.nextLine();
                                while (!esFloat(Sueldo)) {
                                    System.out.println("\nSueldo no válido, intentelo de nuevo\n");
                                    scanSueldo = new Scanner(System.in);
                                    Sueldo = scanSueldo.nextLine();
                                }
                                //Sueldo = formatear(Sueldo);

                                sql = "insert into Empleado (Nombre, Apellidos, Telefono, Dni, CuentaBancaria, Direccion, NSEGSOC, Puesto, Turno, Sueldo) ";
                                sql += "values ('";
                                sql += nombreEmpleado;
                                sql += "','";
                                sql += apellidoEmpleado;
                                sql += "','";
                                sql += Telefono;
                                sql += "','";
                                sql += DNI;
                                sql += "','";
                                sql += cuentaBancaria;
                                sql += "','";
                                sql += Direccion;
                                sql += "','";
                                sql += nSegSoc;
                                sql += "','";
                                sql += Puesto;
                                sql += "','";
                                sql += Turno;
                                sql += "',";
                                sql += Sueldo + ")";
                                try {
                                    stmt.executeQuery(sql);
                                } catch (Exception e) {
                                    System.out.println(e);
                                }

                                con.commit();

                            } else if (opcion == 2) {
                                System.out.println("\nPor favor indique el DNI del empleado a despedir: \n");
                                String DNI;
                                Scanner scanDNI = new Scanner(System.in);
                                DNI = scanDNI.nextLine();
                                while (DNI.length() > 20) {
                                    System.out.println("\nDNI no válido, intentelo de nuevo\n");
                                    Scanner scanDNIEmp = new Scanner(System.in);
                                    DNI = scanDNIEmp.nextLine();
                                }

                                sql = "select * from Empleado where DNI='" + DNI + "'";

                                try {
                                    stmt.executeQuery(sql);
                                    ResultSet rs = stmt.executeQuery(sql);
                                    if (rs.next()) {
                                        System.out.println("\nBorrando el empleado:" + rs.getString("Nombre") + " " + rs.getString("Apellidos") + " \n");
                                        sql = "delete from Empleado where DNI='" + DNI + "'";
                                        stmt.executeQuery(sql);
                                    } else {
                                        System.out.println("\nNo existe el empleado\n");
                                    }
                                } catch (Exception e) {
                                    System.out.println("\nERROR: El empleado no existe o hay problemas en la conexión\n");
                                }
                                con.commit();
                            } else if (opcion == 3) {
                                System.out.println("\nPor favor indique su DNI: \n");
                                String DNI;
                                Scanner scanDNI = new Scanner(System.in);
                                DNI = scanDNI.nextLine();
                                while (DNI.length() > 20) {
                                    System.out.println("\nDNI no válido, intentelo de nuevo\n");
                                    Scanner scanDNIEmp = new Scanner(System.in);
                                    DNI = scanDNIEmp.nextLine();
                                }
                                System.out.println("\nPor favor indique su CUENTA BANCARIA: \n");
                                String cuentaBancaria;
                                Scanner scanBanc = new Scanner(System.in);
                                cuentaBancaria = scanBanc.nextLine();
                                while (cuentaBancaria.length() > 20 || !esEntero(cuentaBancaria)) {
                                    System.out.println("\nCuenta bancaria no válida, intentelo de nuevo\n");
                                    scanBanc = new Scanner(System.in);
                                    cuentaBancaria = scanBanc.nextLine();
                                }
                                System.out.println("\nPor favor indique su DIRECCIÓN: \n");
                                String Direccion;
                                Scanner scanDireccion = new Scanner(System.in);
                                Direccion = scanDireccion.nextLine();
                                while (Direccion.length() > 20) {
                                    System.out.println("\nDirección no válido, intentelo de nuevo\n");
                                    scanDireccion = new Scanner(System.in);
                                    Direccion = scanDireccion.nextLine();
                                }

                                sql = "select * from Empleado where DNI='" + DNI + "'";
                                try {

                                    ResultSet rs = stmt.executeQuery(sql);
                                    if (rs.next()) {
                                        sql = "update Empleado SET CuentaBancaria = '" + cuentaBancaria + "', Direccion = '" + Direccion + "' where DNI = '" + DNI + "'";
                                        stmt.executeQuery(sql);
                                    } else {
                                        System.out.println("\nNo existe el empleado\n");
                                    }
                                } catch (Exception e) {

                                }
                                con.commit();
                            } else if (opcion == 4) {
                                System.out.println("\nPor favor indique el DNI del empleado a consultar: \n");
                                String DNI;
                                Scanner scanDNI = new Scanner(System.in);
                                DNI = scanDNI.nextLine();
                                while (DNI.length() > 20) {
                                    System.out.println("\nDNI no válido, intentelo de nuevo\n");
                                    Scanner scanDNIEmp = new Scanner(System.in);
                                    DNI = scanDNIEmp.nextLine();
                                }
                                sql = "select * from Empleado where DNI='" + DNI + "'";

                                try {
                                    ResultSet rs = stmt.executeQuery(sql);
                                    if (rs.next()) {
                                        System.out.println("Nombre " + rs.getString("Nombre") + " Apellidos " + rs.getString("Apellidos") + " Telefono " + rs.getString("Telefono") + " DNI " + rs.getString("DNI") + " Cuenta Bancaria: " + rs.getString("CuentaBancaria") + " Direccion: " + rs.getString("Direccion") + " Num. Seg Social: " + rs.getString("NSegSoc") + " Puesto: " + rs.getString("Puesto") + " Turno: " + rs.getString("Turno") + " Sueldo: " + rs.getFloat("Sueldo") + "\n");
                                    } else {
                                        System.out.println("\nNo existe el empleado\n");
                                    }
                                } catch (Exception e) {
                                    System.out.println("\nERROR: Hay problemas en la conexión\n");
                                }
                            } else if (opcion == 5) {
                                System.out.println("\nPor favor el DNI del empleado: \n");
                                String DNI;
                                Scanner scanDNI = new Scanner(System.in);
                                DNI = scanDNI.nextLine();
                                while (DNI.length() > 20) {
                                    System.out.println("\nDNI no válido, intentelo de nuevo\n");
                                    Scanner scanDNIEmp = new Scanner(System.in);
                                    DNI = scanDNIEmp.nextLine();
                                }
                                System.out.println("\nPor favor indique el PUESTO del empleado: \n");
                                String Puesto;
                                Scanner scanPuesto = new Scanner(System.in);
                                Puesto = scanPuesto.nextLine();
                                while (Puesto.length() > 20) {
                                    System.out.println("\nPuesto no válido, intentelo de nuevo\n");
                                    scanPuesto = new Scanner(System.in);
                                    Puesto = scanPuesto.nextLine();
                                }
                                System.out.println("\nPor favor indique el TURNO del empleado: \n");
                                String Turno;
                                Scanner scanTurno = new Scanner(System.in);
                                Turno = scanTurno.nextLine();
                                while (Turno.length() > 20) {
                                    System.out.println("\nTurno no válido, intentelo de nuevo\n");
                                    scanTurno = new Scanner(System.in);
                                    Turno = scanTurno.nextLine();
                                }
                                System.out.println("\nPor favor indique el SUELDO del empleado: \n");
                                String Sueldo;
                                Scanner scanSueldo = new Scanner(System.in);
                                Sueldo = scanSueldo.nextLine();
                                while (!esFloat(Sueldo)) {
                                    System.out.println("\nSueldo no válido, intentelo de nuevo\n");
                                    scanSueldo = new Scanner(System.in);
                                    Sueldo = scanSueldo.nextLine();
                                }
                                //Sueldo = formatear(Sueldo);

                                sql = "update Empleado SET Puesto = '" + Puesto + "', Turno = '" + Turno + "', Sueldo = " + Sueldo + " where DNI = '" + DNI + "'";

                                try {
                                    stmt.executeQuery(sql);
                                } catch (Exception e) {
                                    System.out.println(e);
                                }
                                con.commit();
                            } else if (opcion == 6) {
                                terminarSubmenu = true;
                            }
                        }

                    }else if(num==3){
                        boolean terminarsub=false;
                        while (!terminarsub){
                            System.out.println("\n Subsistema de gestion de Marketplace:\n");
                            System.out.println("1. Añadir producto\n");
                            System.out.println("2. Consultar disponibilidad producto\n");
                            System.out.println("3. Añadir proveedor\n");
                            System.out.println("4. Eliminar proveedor\n");
                            System.out.println("5. Modificar producto\n");
                            System.out.println("6. Mostrar tablas\n");
                            System.out.println("7. Volver al menu principal\n");

                            rep = scan.nextLine();

                            //Comprobación por si el usuario no introdujese números
                            if (esEntero(rep)) {
                                int num2 = Integer.parseInt(rep);
                                //Por si no introdujese un numero valido
                                if ((num2 > 7) || (num2 <= 0)) {
                                    System.out.println("OPCION NO VALIDA, POR FAVOR INSERTE UN NUMERO DEL 1 AL 7\n");
                                } else if (num2 == 7) {
                                    //La opcion 7 pone a true la condicion del bucle y termina la ejecucion de la aplicacion
                                    terminarsub = true;
                                    System.out.println("Saliendo del subsistema. Volviendo al menu principal\n");
                                } else if (num2 == 1) {
                                    //Añadir producto.                       
                                    Savepoint antesDeProducto = null;
                                    boolean errores = false;
                                    antesDeProducto = con.setSavepoint();
                                    System.out.println("\nPor favor indique la referencia del producto (menos de 20 caracteres): \n");
                                    String codProducto;
                                    Scanner scanProd1 = new Scanner(System.in);
                                    codProducto = scanProd1.nextLine();
                                    System.out.println("\nPor favor indique el identificador del almacen (menos de 10 caracteres): \n");
                                    String codAlmacen;
                                    Scanner scanProd2 = new Scanner(System.in);
                                    codAlmacen = scanProd2.nextLine();
                                    try {
                                        sql = "select * from Almacen where Identificador='" + codAlmacen+"'";
                                        ResultSet rs = stmt.executeQuery(sql);
                                        if (!rs.next()) {
                                            errores = true;
                                        }
                                    } catch (Exception e) {
                                        errores = true;
                                    }
                                    boolean mostrado=false;

                                    if (errores) {
                                        System.out.println("\nError en la introduccion del codigo de almacen, no se va a insertar. Reintente de nuevo\n");
                                        mostrado=true;
                                    }
                                    System.out.println("\nPor favor indique el nombre del producto: \n");
                                    String nombre;
                                    Scanner scanProd3 = new Scanner(System.in);
                                    nombre = scanProd3.nextLine();

                                    System.out.println("\nPor favor indique el cif del proveedor (menos de 20 caracteres, null en caso de que no tenga): \n");
                                    String codprov;
                                    Scanner scanProd4 = new Scanner(System.in);
                                    codprov = scanProd4.nextLine();
                                    boolean prov_null=false;
                                    if(codprov!="null"){
                                        try {
                                            sql = "select * from Proveedor where cif=" + codprov+"'";
                                            ResultSet rs = stmt.executeQuery(sql);
                                            if (!rs.next()) {
                                                errores = true;
                                            }
                                        } catch (Exception e) {
                                            errores = true;
                                        }
                                    }
                                    else{
                                        prov_null=true;
                                    }
                                    if (errores && !mostrado) {
                                        System.out.println("\nError en la introduccion del cif del proveedor, no se va a insertar. Reintente de nuevo\n");
                                        mostrado=true;
                                    }


                                    if (!errores) {  
                                        if(prov_null){
                                            try {
                                                sql = "insert into ProductoAlmacena values ('"+nombre+"', '"+codProducto+"', 0, '"+codAlmacen+"')";
                                                stmt.executeQuery(sql);
                                            } catch (Exception e) {
                                                System.out.println("Ya existe el producto, no se va a insertar\n");
                                                errores = true;
                                            }
                                        }
                                        else{
                                            try {
                                                sql = "insert into ProductoAlmacena values ('"+nombre+"', '"+codProducto+"', 0, '"+codAlmacen+"')";
                                                stmt.executeQuery(sql);

                                                sql= "INSERT INTO suministra VALUES('"+codprov+"','"+codProducto+"')";
                                                stmt.executeQuery(sql); 
                                            } catch (Exception e) {
                                                System.out.println("Ya existe el producto, no se va a insertar\n");
                                                errores = true;
                                            }
                                        }
                                        if (!errores) {
                                            System.out.println("Se ha insertado correctamente los datos del producto, puede realizar el pedido\n");
                                        }
                                    }

                                    mostrarContenidoTablasMarketplace(stmt);

                                    // Hacemos commit para actualizar la base de datos
                                    con.commit();
                                    mostrarContenidoTablasMarketplace(stmt);
                                } else if (num2 == 2) {
                                    // Opcion 2, consultar en que almacen se encuentra un producto
                                    System.out.println("\nPor favor indique la referencia del producto (menos de 20 caracteres): \n");
                                    String codProducto;
                                    Scanner scanProd1 = new Scanner(System.in);
                                    codProducto = scanProd1.nextLine();
                                    boolean codigoProductoExiste = true;
                                    
                                    try {
                                        sql="SELECT COUNT(*) FROM ProductoAlmacena WHERE Referencia = '"+codProducto+"'";
                                        ResultSet rs = stmt.executeQuery(sql);
                                        if (rs.next()) {
                                            sql="SELECT identificadorAlmacen FROM ProductoAlmacena WHERE Referencia = '"+codProducto+"'";
                                            rs=stmt.executeQuery(sql);
                                            System.out.println("Referencia: " + rs.getString("referencia") +" IdentificadorAlmacen: " + rs.getString("IdentificadorAlmacen") +"\n");
                                        
                                        } else {
                                            System.out.println("\nNo existe el producto\n");
                                        }
                                    } catch (Exception e) {
                                        codigoProductoExiste=false;
                                    }                               
                                    


                                } else if (num2 == 3) {
                                    //Añadir proveedor.                        
                                    Savepoint antesDeProveedor = null;
                                    boolean errores = false;
                                    antesDeProveedor = con.setSavepoint();
                                    System.out.println("\nPor favor indique el cif del proveedor (menos de 20 caracteres): \n");
                                    String cifProv;
                                    Scanner scanProd1 = new Scanner(System.in);
                                    cifProv = scanProd1.nextLine();
                                    
                                    System.out.println("\nPor favor indique el nombre del proveedor: \n");
                                    String nombre;
                                    Scanner scanProd3 = new Scanner(System.in);
                                    nombre = scanProd3.nextLine();

                                    System.out.println("\nPor favor indique la direcciÃ³n del proveedor (menos de 60 caracteres): \n");
                                    String dirProv;
                                    Scanner scanProd4 = new Scanner(System.in);
                                    dirProv = scanProd4.nextLine();
                                    try {
                                        sql = "insert into Proveedor values ('"+nombre+"', '"+cifProv+"', '"+dirProv+"')";
                                        stmt.executeQuery(sql);
                                    } catch (Exception e) {
                                        System.out.println("Ya existe el producto, no se va a insertar\n");
                                        errores = true;
                                        }

                                    if (!errores) {
                                        System.out.println("Se ha insertado correctamente los datos del producto, puede realizar el pedido\n");
                                    }                               

                                    mostrarContenidoTablasMarketplace(stmt);

                                    // Hacemos commit para actualizar la base de datos
                                    con.commit();
                                    mostrarContenidoTablasMarketplace(stmt);
                                } else if (num2 == 4) {
                                    //Eliminar proveedor.               
                                    System.out.println("\nPor favor indique el CIF del proveedor que desea aliminar: \n");
                                    String cif;
                                    Scanner scancif = new Scanner(System.in);
                                    cif = scancif.nextLine();
                                    while (cif.length() > 20) {
                                        System.out.println("\nCIF no vÃ¡lido, intentelo de nuevo\n");
                                        Scanner scanCIF2 = new Scanner(System.in);
                                        cif = scanCIF2.nextLine();
                                    }

                                    sql = "select * from Proveedor where cif='" + cif + "'";

                                    try {
                                        stmt.executeQuery(sql);
                                        ResultSet rs = stmt.executeQuery(sql);
                                        if (rs.next()) {
                                            System.out.println("\nBorrando el proveedor:" + rs.getString("Nombre") + " " + rs.getString("cif") + rs.getString("direccion") +" \n");
                                            sql = "delete from Proveedor where cif='" + cif + "'";
                                            stmt.executeQuery(sql);
                                        } else {
                                            System.out.println("\nNo existe el proveedor\n");
                                        }
                                    } catch (Exception e) {
                                        System.out.println(e);
                                    }                 

                                    mostrarContenidoTablasMarketplace(stmt);

                                    // Hacemos commit para actualizar la base de datos
                                    con.commit();
                                    mostrarContenidoTablasMarketplace(stmt);
                                }else if (num2 == 5) {
                                    //Modificar producto.                       
                                    Savepoint antesDeModificar = null;
                                    boolean errores = false;
                                    antesDeModificar = con.setSavepoint();
                                    System.out.println("\nPor favor indique la referencia del producto (menos de 20 caracteres): \n");
                                    String codProducto;
                                    Scanner scanProd1 = new Scanner(System.in);
                                    codProducto = scanProd1.nextLine();
                                    try {
                                        sql = "select * from ProductoAlmacena where referencia='" + codProducto+"'";
                                        ResultSet rs = stmt.executeQuery(sql);
                                        if (!rs.next()) {
                                            errores = true;
                                        }
                                    } catch (Exception e) {
                                        errores = true;
                                    }
                                    boolean mostrado1=false;

                                    if (errores) {
                                        System.out.println("\nError en la introduccion de la referencia del producto, no se va a modificar. Reintente de nuevo\n");
                                        mostrado1=true;
                                    }
                                    System.out.println("\nPor favor indique el identificador del nuevo almacen (menos de 10 caracteres, null si no quiere modificarlo): \n");
                                    String codAlmacen;
                                    Scanner scanProd2 = new Scanner(System.in);
                                    codAlmacen = scanProd2.nextLine();
                                    boolean almacen_null=false;                                    
                                    boolean mostrado2=false;
                                    if(codAlmacen!="null"){
                                        try {
                                            sql = "select * from Almacen where identificador='" + codAlmacen+"'";
                                            ResultSet rs = stmt.executeQuery(sql);
                                            if (!rs.next()) {
                                                errores = true;
                                            }
                                        } catch (Exception e) {
                                            errores = true;
                                        }

                                        if (errores) {
                                            System.out.println("\nError en la introduccion del codigo del almacen, no se va a modificar. Reintente de nuevo\n");
                                            mostrado2=true;
                                        }
                                    }else{
                                        almacen_null=true;
                                    }
                                    
                                    boolean mostrado=false;

                                    System.out.println("\nPor favor indique el nuevo nombre del producto (null si no desea modificarlo): \n");
                                    String nombre;
                                    Scanner scanProd3 = new Scanner(System.in);
                                    nombre = scanProd3.nextLine();
                                    boolean nom_null=false;
                                    if(nombre=="null")
                                        nom_null=true;

                                    System.out.println("\nPor favor indique el cif del proveedor (menos de 20 caracteres, null en caso de que no quiera modificarlo): \n");
                                    String codprov;
                                    Scanner scanProd4 = new Scanner(System.in);
                                    codprov = scanProd4.nextLine();
                                    boolean prov_null=false;
                                    if(codAlmacen!="null"){
                                        try {
                                            sql = "select * from Proveedor where cif='" + codprov+"'";
                                            ResultSet rs = stmt.executeQuery(sql);
                                            if (!rs.next()) {
                                                errores = true;
                                            }
                                        } catch (Exception e) {
                                            errores = true;
                                        }
                                    }
                                    else{
                                        prov_null=true;
                                    }
                                    if (errores && !mostrado1 && !mostrado2) {
                                        System.out.println("\nError en la introduccion del cif del proveedor, no se va a modificar. Reintente de nuevo\n");
                                        mostrado=true;
                                    }


                                    if (!errores) { 
                                        boolean error_prov=false;
                                        boolean error_nom=false;
                                        boolean error_alm=false;
                                        if(!prov_null){
                                            try {
                                                sql = "UPDATE suministra SET proveedor='"+codprov+"' WHERE referencia='"+codProducto+"'";
                                                stmt.executeQuery(sql);
                                            } catch (Exception e) {
                                                System.out.println("No se puede modificar el proveedor\n");
                                                error_prov = true;
                                            }
                                            if(!error_prov)
                                                System.out.println("Se ha modificado el proveedor\n");
                                        }
                                        if(!nom_null){
                                            try {
                                                sql = "UPDATE productoalmacena SET nombre='"+nombre+"' WHERE referencia='"+codProducto+"'";
                                                stmt.executeQuery(sql);
                                            } catch (Exception e) {
                                                System.out.println("No se puede modificar el nombre\n");
                                                error_nom = true;
                                            }
                                            if(!error_nom)
                                                System.out.println("Se ha modificado el nombre\n");
                                        }
                                        if(!almacen_null){
                                            try {
                                                sql = "UPDATE productoalmacena SET IdentificaroAlmacen='"+codAlmacen+"' WHERE referencia='"+codProducto+"'";
                                                stmt.executeQuery(sql);
                                            } catch (Exception e) {
                                                System.out.println("No se puede modificar el almacen\n");
                                                error_alm = true;
                                            }                                            
                                            if(!error_alm)
                                                System.out.println("Se ha modificado el almacen\n");
                                        }
                                        if(error_alm || error_nom || error_prov)
                                            errores=true;
                                        if (!errores) {
                                            System.out.println("Se han modificado correctamente los datos del producto\n");
                                        }
                                    }

                                    mostrarContenidoTablasMarketplace(stmt);

                                    // Hacemos commit para actualizar la base de datos
                                    con.commit();
                                    mostrarContenidoTablasMarketplace(stmt);
                                }else if (num2 == 6) {
                                    // Mostrar tablas
                                    mostrarContenidoTablasMarketplace(stmt);           
                                }
                                
                            } else {
                                System.out.println("Inserte un numero por favor\n");
                            }
                        }
                    }                    
                    else if (num == 4) {
                        boolean salir=false;
                        while(!salir){
                        System.out.println("\n SUBSISTEMA 4 -> GESTION DE LOGISTICA:\n");
                        System.out.println("1. Aniadir metodo de transporte\n");
                        System.out.println("2. Asignar pedido a transporte\n");
                        System.out.println("3. Eliminar metodo de transporte\n");
                        System.out.println("4. Asignar ruta\n");
                        System.out.println("5. Consultar estado de pedido\n");
                        System.out.println("6. Mostrar transportres\n");
                        System.out.println("7. Salir del subsistema \n");
                        Scanner scan4 = new Scanner(System.in);
                        rep = scan4.nextLine();
                
                        // vamos a comprobar que lo introducido es un numero
                        if(!esEntero(rep)){
                            System.out.println("Inserte un numero por favor\n");
                        }else{
                            int num_op = Integer.parseInt(rep);
                            if ((num_op > 6) || (num_op <= 0)) {
                                System.out.println("OPCION NO VALIDA, POR FAVOR INSERTE UN NUMERO DEL 1 AL 6\n");
                            } else if ( num_op == 7 ) {
                                //La opción 4 pone a true la condición del bucle y termina la ejecución de la aplicación
                                salir = true;
                                System.out.println("Saliendo del subsistema\n");
                            
                            
                            } else if( num_op ==1 ){
                                
                                // 1. Aniadir metodo de transporte
                                String tipo, marca, matricula, aux;
                                int subcontratacion=0, asignado=0;
                                System.out.println("--------------------------------------- ");
                                System.out.println("1. Aniadir metodo de transporte ");
                                System.out.println("--------------------------------------- ");
                                System.out.println("Tipo (Coche, moto, furgoneta, etc.): ");
                                tipo = scan.nextLine();
                                System.out.println("Marca: ");
                                marca = scan.nextLine();
                                System.out.println("Matricula: ");
                                matricula = scan.nextLine();
                                do{
                                System.out.println("Subcontratacion (0 si es vehículo propio,1 si es subcontratado): ");
                                subcontratacion = Integer.parseInt(scan.nextLine());
                                }while(subcontratacion > 1 || subcontratacion < 0);
                                /*System.out.println("Asignado: ");
                                tipo = scan.nextLine();*/
                                sql = "INSERT INTO MetodoDeTransporte VALUES ( '"+matricula+"','"+tipo+"','"+marca+"',"+subcontratacion+","+asignado+")";
                                System.out.println(sql);
                                stmt.executeQuery(sql);
                                
                                con.commit();
                                
                            } else if ( num_op == 2 ){
                                //2. Asignar pedido a transporte
                                String cod_pedido, matricula;
                                System.out.println("--------------------------------------- ");
                                System.out.println("2. Asignar pedido a transporte ");
                                System.out.println("--------------------------------------- ");
                                
                                System.out.println("Codigo del pedido: ");
                                cod_pedido = scan.nextLine();
                                System.out.println("Matricula del transporte: ");
                                matricula = scan.nextLine();
                                
                                sql = "INSERT INTO Asigna VALUES ( '"+matricula+"','"+cod_pedido+"')";
                                System.out.println(sql);
                                stmt.executeQuery(sql);
                                
                                con.commit();
                                //¿¿ no se le asigna el metodo del transporte al pedido??
                                
                            } else if ( num_op == 3 ) {
                                //3. Eliminar metodo de transporte
                                String matricula;
                                System.out.println("--------------------------------------- ");
                                System.out.println("3. Eliminar metodo de transporte ");
                                System.out.println("--------------------------------------- ");
                                
                                System.out.println("Matricula del transporte: ");
                                matricula = scan.nextLine();
                                
                                sql = "DELETE FROM MetodoDeTransporte where matricula = '"+matricula+"'";
                                System.out.println(sql);
                                stmt.executeQuery(sql);
                            
                                con.commit();
                                
                            } else if ( num_op == 4 ){
                                //4. Asignar ruta
                                String cod_ruta, matricula;
                                System.out.println("--------------------------------------- ");
                                System.out.println("4. Asignar ruta ");
                                System.out.println("--------------------------------------- ");
                                
                                System.out.println("Codigo de la ruta: ");
                                cod_ruta = scan.nextLine();
                                System.out.println("Matricula del transporte: ");
                                matricula = scan.nextLine();
                                
                                sql = "INSERT INTO AsignaR VALUES ( '"+matricula+"','"+cod_ruta+"')";
                                System.out.println(sql);
                                stmt.executeQuery(sql);
                                sql = "UPDATE MetodoDeTransporte set Asignado=1 where matricula = '"+matricula+"'";
                                System.out.println(sql);
                                stmt.executeQuery(sql);
                                
                                con.commit();
                                
                            } else if ( num_op == 5 ){
                                //5. Consultar estado de pedido
                                
                                String cod_pedido="", matricula="ninguno", cod_ruta="ninguna";
                                System.out.println("--------------------------------------- ");
                                System.out.println("5. Consultar estado de pedido ");
                                System.out.println("--------------------------------------- ");
                                
                                System.out.println("Codigo del pedido: ");
                                cod_pedido = scan.nextLine();
                                
                                System.out.println("Estado de pedido: ");
                                System.out.println("\t - Codigo del pedido: "+cod_pedido);
                                
                                // trabajamos la matricula
                                System.out.println("\t - Caracteristicas del vehículo donde esta asignado: "+stmt.executeQuery("select * from MetodoDeTransporte where matricula= (SELECT matricula FROM Asigna where cod_pedido = '"+cod_pedido+"')"));
                                                            
                                // trabajamos la ruta 
                                sql = "SELECT * from Ruta R where R.Cod_Ruta = (SELECT cod_ruta from AsignaR A where A.matricula = (SELECT matricula FROM Asigna where cod_pedido = "+cod_pedido+"))";
                                System.out.println("\t - Caracteristica de la ruta del vehiculo: "+stmt.executeQuery(sql));
                                
                                
                            } else if( num_op == 6 ){
                                // mostras los transportes
                                mostrarContenidoTablas4(stmt);
                            } 
                        }
                    }
                }
                else if (num == 5){
                                

                        boolean terminarAlmacen = false;

                            while (!terminarAlmacen) {
                                System.out.println("\n Bienvenido al subsistema de Almacen, elija que opcion realizar:\n");
                                System.out.println("1. Aniadir Almacen\n");
                                System.out.println("2. Eliminar Almacen\n");
                                System.out.println("3. Aniadir stock de un producto\n");
                                System.out.println("4. Disminuir stock de un producto\n");
                                System.out.println("5. Consultar stock de un producto\n");
                                System.out.println("6. Consultar productos de un Almacen\n");
                                System.out.println("7. Mostrar tablas del subsistema\n");
                                System.out.println("8. Salir del subsistema\n");
                                String repAlmacen = scan.nextLine();

                                int idAlmacen = 0;
                                

                                //Comprobacion por si el usuario no introdujese numeros
                                if (esEntero(repAlmacen)) {

                                    int numAlmacen = Integer.parseInt(repAlmacen);

                                    if ((numAlmacen > 8) || (numAlmacen <= 0)) {
                                        System.out.println("OPCION NO VALIDA, POR FAVOR INSERTE UN NUMERO DEL 1 AL 8\n");
                                    }
                                    else {

                                        // Salir del subsistema
                                        if(numAlmacen == 8){

                                            terminarAlmacen = true;
                                            System.out.println("Saliendo del sistema\n");
                                        }

                                        // Aniadir un almacen
                                        else if (numAlmacen == 1){


                                            Scanner scanAlmacen = new Scanner(System.in);
                                            boolean idInsertado = false;
                                            String idAlmacen_aniadir = "";

                                            while (!idInsertado) {
                                                System.out.println("\nPor favor indique el id de Almacen: \n");
                                                idAlmacen_aniadir = scanAlmacen.nextLine();
                                                if (idAlmacen_aniadir.length() > 0) {
                                                    idInsertado = true;
                                                }
                                            }
                                            //--------------------------------------------

                                            boolean nombreInsertado = false;
                                            String nombreAlmacen = "";

                                            while (!nombreInsertado) {
                                                System.out.println("\nPor favor indique el nombre de Almacen: \n");
                                                nombreAlmacen = scanAlmacen.nextLine();
                                                if (nombreAlmacen.length() > 0) {
                                                    nombreInsertado = true;
                                                }
                                            }
                                            //-----------------------------------------------

                                            boolean direccionInsertado = false;
                                            String direccionAlmacen = "";

                                            while (!direccionInsertado) {
                                                System.out.println("\nPor favor indique la direccion del Almacen: \n");
                                                direccionAlmacen = scanAlmacen.nextLine();
                                                if (nombreAlmacen.length() > 0) {
                                                    direccionInsertado = true;
                                                }
                                            }
                                            //------------------------------------------------

                                            boolean tamanioInsertado = false;
                                            String tamanioAlmacen = "";

                                            while (!tamanioInsertado) {
                                                System.out.println("\nPor favor indique el tamanio del Almacen: \n");
                                                tamanioAlmacen = scanAlmacen.nextLine();
                                                    if (esEntero(tamanioAlmacen)) {
                                                        if (Integer.parseInt(tamanioAlmacen) > 0) {
                                                            tamanioInsertado = true;
                                                        }
                                                    }
                                            }

                                            //------------------------------------------------


                                                try {
                                                    
                                                    String datosAlmacen = "insert into Almacen values ('" + idAlmacen_aniadir + "','" + nombreAlmacen + "','" + direccionAlmacen + "'," + tamanioAlmacen +")";
                                                    stmt.executeQuery(datosAlmacen);
                                                    
                                                } catch (Exception e) {
                                                    System.out.println("No se ha podido aniadir el Almacen...\n");
                                                }
                                                con.commit();
                                        }

                                        // Eliminar Almacen

                                        else if (numAlmacen == 2){

                                            boolean idAlmacen_insertado_eliminar = false;
                                            String idAlmacen_eliminar;
                                            Scanner scanAlmacenEliminar = new Scanner(System.in);
                                            String sentencia_almacen_eliminar;

                                            System.out.println("\nPor favor escriba el identificador del Almacen que quiere eliminar: \n");
                                                idAlmacen_eliminar = scanAlmacenEliminar.nextLine();

                                                    try{

                                                        sentencia_almacen_eliminar = "delete from Almacen where identificador='"+idAlmacen_eliminar+"'";
                                                        stmt.executeQuery(sentencia_almacen_eliminar);
                                                    }
                                                    catch (Exception e) {
                                                        System.out.println("No se ha podido eliminar dicho Almacen.\n");
                                                    }
                                                    con.commit();
                                        }

                                        // Aniadir Stock a un Producto

                                        else if (numAlmacen == 3){

                                            Scanner scanAlmacenAniadirStock = new Scanner(System.in);
                                            boolean idProductoInsertado_aniadir = false;
                                            String idProducto_aniadir_stock = "";

                                            while (!idProductoInsertado_aniadir) {
                                                System.out.println("\nPor favor indique el id del Producto: \n");
                                                idProducto_aniadir_stock = scanAlmacenAniadirStock.nextLine();
                                                if (idProducto_aniadir_stock.length() > 0) {
                                                    idProductoInsertado_aniadir = true;
                                                }
                                            }

                                            //----------------------------------

                                            boolean aniadir_cantidad = false;
                                            String cantidad = "";

                                            while (!aniadir_cantidad) {
                                                System.out.println("\nPor favor indique la cantidad a aniadir: \n");
                                                cantidad = scanAlmacenAniadirStock.nextLine();
                                                if (esEntero(cantidad) && Integer.parseInt(cantidad) > 0) {
                                                    aniadir_cantidad = true;
                                                }
                                            }

                                            //---------------------------------


                                            try {
                                                System.out.println("update ProductoAlmacena set Stock=Stock+" + cantidad + " where Referencia='" + idProducto_aniadir_stock + "'" + "\n");
                                                String datosAniadirStock = "update ProductoAlmacena set Stock=Stock+" + cantidad + " where Referencia='" + idProducto_aniadir_stock + "'";
                                                stmt.executeQuery(datosAniadirStock);
                                            } catch (Exception e) {
                                                System.out.println("No se ha podido aniadir stock al producto...\n");
                                            }
                                            con.commit();
                                        }

                                        // Disminuir stock de un producto

                                        else if (numAlmacen == 4){

                                            Scanner scanAlmacenDisminuirStock = new Scanner(System.in);
                                            boolean idProductoInsertado_disminuir = false;
                                            String idProducto_disminuir_stock = "";

                                            while (!idProductoInsertado_disminuir) {
                                                System.out.println("\nPor favor indique el id del Producto: \n");
                                                idProducto_disminuir_stock = scanAlmacenDisminuirStock.nextLine();
                                                if (idProducto_disminuir_stock.length() > 0) {
                                                    idProductoInsertado_disminuir = true;
                                                }
                                            }

                                            //----------------------------------

                                            boolean disminuir_cantidad = false;
                                            String cantidad_disminuir = "";

                                            while (!disminuir_cantidad) {
                                                System.out.println("\nPor favor indique la cantidad a disminuir: \n");
                                                cantidad_disminuir = scanAlmacenDisminuirStock.nextLine();
                                                if (esEntero(cantidad_disminuir) && Integer.parseInt(cantidad_disminuir) > 0) {
                                                    disminuir_cantidad = true;
                                                }
                                            }

                                            //---------------------------------


                                            try {

                                                String datosDisminuirStock = "update ProductoAlmacena set Stock=Stock-" + cantidad_disminuir + " where Referencia='" + idProducto_disminuir_stock + "'";
                                                stmt.executeQuery(datosDisminuirStock);
                                            } catch (Exception e) {
                                                System.out.println("No se ha podido disminuir stock al producto...\n");
                                            }
                                            con.commit();
                                        }

                                        // Consultar stock de un producto

                                        else if (numAlmacen == 5){

                                            Scanner scanAlmacenConsultarStock = new Scanner(System.in);
                                            boolean idProductoInsertado_consultar = false;
                                            String idProducto_consultar_stock = "";

                                            while (!idProductoInsertado_consultar) {
                                                System.out.println("\nPor favor indique el id del Producto: \n");
                                                idProducto_consultar_stock = scanAlmacenConsultarStock.nextLine();
                                                if (idProducto_consultar_stock.length() > 0) {
                                                    idProductoInsertado_consultar = true;
                                                }
                                            }

                                            try {

                                                String datosConsultarStock = "select Stock from ProductoAlmacena where Referencia='" + idProducto_consultar_stock + "'";
                                                ResultSet rs = stmt.executeQuery(datosConsultarStock);

                                                System.out.println("Stock del producto: " + idProducto_consultar_stock + "\n");
                                                while (rs.next()) {
                                                    System.out.println("Stock: " + rs.getInt("Stock") + "\n");
                                                }
                                            } catch (Exception e) {
                                                System.out.println("No se ha podido consultar el stock del producto...\n");
                                            }



                                        }

                                        // Consultar listado de productos de un Almacen

                                        else if (numAlmacen == 6){

                                            Scanner scanAlmacenListaProductos = new Scanner(System.in);
                                            boolean idAlmacenInsertado_listaProductos = false;
                                            String idAlmacen_listado_productos = "";

                                            while (!idAlmacenInsertado_listaProductos) {
                                                System.out.println("\nPor favor indique el id del Almacen: \n");
                                                idAlmacen_listado_productos = scanAlmacenListaProductos.nextLine();
                                                if (idAlmacen_listado_productos.length() > 0) {
                                                    idAlmacenInsertado_listaProductos = true;
                                                }
                                            }

                                            try {

                                                String datosListadoProductos = "select * from ProductoAlmacena where IdentificadorAlmacen='"+idAlmacen_listado_productos + "'";
                                                ResultSet rs = stmt.executeQuery(datosListadoProductos);

                                                System.out.println("Listado de Productos: \n");
                                                while (rs.next()) {
                                                    System.out.println("Nombre " + rs.getString("Nombre") + " Referencia " + rs.getString("Referencia") + " Stock " + rs.getInt("Stock") + " IdentificadorAlmacen " + rs.getString("IdentificadorAlmacen") +"\n");
                                                }

                                            } catch (Exception e) {
                                                System.out.println("No se ha podido consultar el listado de productos...\n");
                                            }

                                        }

                                        // Mostrar tablas del subsistema

                                        else if (numAlmacen == 7){

                                            String datosAlmacen = "select * from Almacen";
                                            ResultSet rs = stmt.executeQuery(datosAlmacen);

                                            System.out.println("Tabla Almacen: \n");
                                            while (rs.next()) {
                                                System.out.println("Identificador " + rs.getString("Identificador") + " Nombre " + rs.getString("Nombre") + " Direccion " + rs.getString("Direccion") + " Tamanio " + rs.getInt("Tamanio") +"\n");
                                            }

                                            //-------------------------------------------.
                                            String datosProductoAlmacena = "select * from ProductoAlmacena";
                                            ResultSet rs_1 = stmt.executeQuery(datosProductoAlmacena);

                                            System.out.println("Tabla ProductoAlmacena: \n");
                                            while (rs_1.next()) {
                                                System.out.println("Nombre " + rs_1.getString("Nombre") + " Referencia " + rs_1.getString("Referencia") + " Stock " + rs_1.getInt("Stock") + " IdentificadorAlmacen " + rs_1.getString("IdentificadorAlmacen") +"\n");
                                            }
                                        }
                                    }


                               }

                       }
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