
package ejercicios;

public class David {
    
    private static String MARTINEZ = "Martinez";
    
    private String diaz;

    public David(String apellido_2) {
        
        diaz = apellido_2;
    }
    
    
    // En java no hace falta crear ninguno metodo extra
    
    public void Mostrar(){
        
        System.out.println("La variable de clase es: " + MARTINEZ);
        System.out.println("El atributo de instancia es: " + diaz);
    }
    
    
}
