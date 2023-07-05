/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entregajavap4;

/**
 *
 * @author Usuario
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Persona persona = new Persona("Pepe");
        Deportista deportista = new Deportista("Manolo", 10);
        Corredor corredor = new Corredor("Jose", 20);
        Nadador nadador = new Nadador("John", 30);
        
        
        persona.andar();
        deportista.andar();
        corredor.andar();
        nadador.andar();
        
        System.out.println("------------------------------"); 
        
        // Pregunta 2
        
        // Para las clases heredadas si se necesita un constructor 
        // especificandole por parametros, los atributos necesarios para 
        // poder inicializarlos y llamar a super.
        
        // Si no tiene constructor salta un error de compilacion, 
        // requiriendonos unos parametros.
        
        // Los metodos los hereda de la clase del padre, sin embargo, los 
        // elementos son propios, lo que hereda es su constructor.
        
        
        // Pregunta 3
        
        // El caso de deportista puede acceder a los metodos de su propia clase y al metodo de andar de la clase persona,
        // además tiene redefinido el metodo toString.

        // Metodo redefinido
        System.out.println(deportista.toString());
        deportista.competicion_deportiva();
        deportista.andar();

        // No puede acceder al metodo de correr de Corredor, ni al de nadar de Nadador
        // puts corredor.correr
        // puts deportista.nadar


        System.out.println("------------------------------"); 
      // El caso de corredor puede acceder a los metodos de su propia clase y a los metodos de la clase deportista y persona,
      // además tiene redefinido el metodo toString.

        // Metodo redefinido
        System.out.println(corredor.toString());

        corredor.competicion_deportiva();
        corredor.andar();
        corredor.correr();

        // No puede acceder al metodo de nadar de Nadador
        // corredor.nadar()

      System.out.println("------------------------------"); 
      // El caso de nadador puede acceder a los metodos de su propia clase y al metodo de andar de la clase persona,
      // además tiene redefinido el metodo toString.

        // Metodo redefinido
        System.out.println(nadador.toString());

        nadador.competicion_deportiva();
        nadador.andar();
        nadador.nadar();

        // No puede acceder al metodo de correr de Corredor
        // puts corredor.correr

        System.out.println("------------------------------"); 
        
        // Pregunta 3

        // Deportista, tiene dos atributos(nombre, horas_entrenadas), nombre es 
        // heredado de la clase persona y horas_entrenadas, son propios pero 
        // inicializados gracias al super llamado en el constructor, salvo 
        // horas_entrenadas, que es propio de Deportista.
        
        // Corredor, tiene dos atributos(nombre, horas_entrenadas), ambos 
        //heredados de la clase deportista, son propios pero inicializados 
        //gracias al super llamado en el constructor.
        
        // Nadador, tiene dos atributos(nombre, horas_entrenadas), ambos 
        // heredados de la clase deportista., son propios pero inicializados 
        // gracias al super llamado en el constructor.
    }
    
}
