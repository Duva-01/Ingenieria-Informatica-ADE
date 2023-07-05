/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicios;

public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        /*
        System.out.println("Comprobacion para parcela: \n");

        Parcela p=new Parcela("Suizo", 2000, 300, 60);
        
        p.construirCasa();
        p.construirCasa();
        p.construirCasa();
        
        p.construirHotel();
        
        
        System.out.println("Numero de casas construidas: " + p.getNumCasas() + "\n");
        System.out.println("Numero de hoteles construidos: " + p.getNumHoteles() + "\n");
        System.out.println("Precio Alquiler Total: " + p.getPrecioAlquilerCompleto() + "\n");
        
        //---------------------------------------------------------------------------//
        //---------------------------------------------------------------------------//
        
        System.out.println("2 referencias a parcelas que creas que son iguales en identidad: \n");
        
        Parcela parcela_1 = new Parcela("Recogidas", 1000, 100, 20);
        
        Parcela parcela_2 = parcela_1;
        
        if(parcela_1.igualdadEstado(parcela_2)){
            System.out.println("Son iguales en identidad\n");   
        }
        else System.out.println("No son iguales en identidad\n");
        
        //---------------------------------------------------------------------------//
        //---------------------------------------------------------------------------//

        System.out.println("2 referencias a parcelas que creas que son iguales en estado pero distintas en cuanto a su identidad: \n");
        
        Parcela parcela_3 = new Parcela("Ronda", 4000, 600, 70);
        Parcela parcela_4 = new Parcela("Ronda", 4000, 600, 70);
        
        if(parcela_3.igualdadEstado(parcela_4) && parcela_3.igualdadIdentidad(parcela_4)){
            System.out.println("Son iguales en estado e identidad \n");   
        }
        else if (parcela_3.igualdadEstado(parcela_4) && !(parcela_3.igualdadIdentidad(parcela_4))){
            System.out.println("Son iguales en estado pero no en identidad \n"); 
        }
        else if (!(parcela_3.igualdadEstado(parcela_4)) && parcela_3.igualdadIdentidad(parcela_4)){
            System.out.println("Son iguales en identidad pero no en estado \n"); 
        }
        else System.out.println("No son iguales \n");
        
        //---------------------------------------------------------------------------//
        //---------------------------------------------------------------------------//
        
        System.out.println("2 referencias a parcelas que creas que son distintas en estado e identidad:\n");

        Parcela parcela_5 = new Parcela("Pepe", 3500, 250, 10);
        Parcela parcela_6 = new Parcela("David", 7000, 340, 35);
        
        if(parcela_5.igualdadEstado(parcela_6) && parcela_5.igualdadIdentidad(parcela_6)){
            System.out.println("Son iguales en estado e identidad\n");   
        }
        else if (parcela_5.igualdadEstado(parcela_6) && !(parcela_5.igualdadIdentidad(parcela_6))){
            System.out.println("Son iguales en estado pero no en identidad\n"); 
        }
        else if (!(parcela_5.igualdadEstado(parcela_6)) && parcela_5.igualdadIdentidad(parcela_6)){
            System.out.println("Son iguales en identidad pero no en estado\n"); 
        }
        else System.out.println("No son iguales\n");
        
        //Main de la prueba de evaluacion
        
        David hola = new David("Diaz");
        
        hola.Mostrar();
        
        //---------------------------------------------------------------------------//
        //---------------------------------------------------------------------------//
        */
        Hotel hotel_1 = new Hotel("Nazari", "Granada", 3);
        
        Hotel hotel_2 = new Hotel("Barcelo", "Malaga", 4);
        
        System.out.println("El numero de hoteles es: " + hotel_1.getNUM_HOTELES());

        Director Garban = new Director("Garban", 633892323);
        
        hotel_1.setDirector(Garban);
        
        System.out.println("El director es: " + hotel_1.getDirector().getNombre());
        System.out.println("--------------------------------------");
        
        Cliente Rafillao = new Cliente("445577844", "Rafael");
        
        hotel_2.addReserva(Rafillao, "01/10/2021", "07/10/2021");
        
        
        for(int n=0; n<hotel_2.getReservas().size(); n++){
            
            System.out.println("Reserva " + n);
            
            System.out.println("Nombre del cliente: " + hotel_2.getReservas().get(n).getCliente().getNombre());
            System.out.println("Fecha de entrada: " + hotel_2.getReservas().get(n).getFechaEntrada());
            
            Cliente aux = hotel_2.getReservas().get(n).getCliente();
            
            for(int i=0; i<aux.getReservas().size(); i++){
                
                System.out.println("--------------------------------------");
                System.out.println(aux.getNombre() + " reserva: " + i);
                System.out.println("Fecha de entrada: " + aux.getReservas().get(i).getFechaEntrada());
                System.out.println("--------------------------------------");
            
            }
        }
        
        
        //------------------------------------------//
        
        Pelicula shrek = new Pelicula("Shrek");
        
        Cliente_2 David = new Cliente_2("44669141", "David");
        
        shrek.addAlquiler(David, "8/10/2021");
        
        System.out.println("Para la pelicula: " + shrek.getTitulo());
        System.out.println("Fecha: " + shrek.getAlquileres().get(0).getFecha());
        
        //--------------------------------------------//
        
        Empleado rico = new Empleado("Rico");
        hotel_1.addEmpleado(rico);
        
        System.out.println("El hotel 1 tienes " + hotel_1.getEmpleados().size() + " empleados");
        
        hotel_1.addHabitacion(234, 5);
        hotel_1.addHabitacion(455, 7);
        
        System.out.println("La habitacion para 7 huespedes es: " + hotel_1.buscarHabitacionCapacidad(7));
    }
    
}
