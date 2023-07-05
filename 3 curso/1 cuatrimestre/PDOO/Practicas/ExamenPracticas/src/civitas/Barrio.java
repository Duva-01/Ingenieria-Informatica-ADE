/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

public class Barrio {
    
    private TipoBarrio tipo;
    private String nombre;
    private float porcentajePlusvalia;
    private ArrayList<Casilla> propiedades;
    
    public Barrio(){
        
        this.tipo = TipoBarrio.CENTRO;
        this.nombre = "";
        this.porcentajePlusvalia = 0;
        this.propiedades = new ArrayList<>();
    }
    public Barrio(String nombre, TipoBarrio tipo, float porcentajePlusvalia, ArrayList<Casilla> propiedades){
        
        this.tipo = tipo;
        this.nombre = nombre;
        this.porcentajePlusvalia = porcentajePlusvalia;
        this.propiedades = propiedades;
    }
    
    public void addPropiedad(Casilla propiedad){
        
        propiedades.add(propiedad);
    }    
            
    public ArrayList<String> getEstadoInmuebles(){
        
        ArrayList<TituloPropiedad> propiedadesEnBarrio = Tablero.getInstance().getInmueblesEnBarrio(this);
        
        for(int n=0; n<propiedadesEnBarrio.size(); n++){
            
            propiedadesEnBarrio.get(n);
            
        }
    }
    
    public String getNombre(){
        return nombre;
    }
    
    public TipoBarrio getTipo(){
        return tipo;
    }
    
    public float getPorcentaje(){
        return porcentajePlusvalia;
    }
    
    public ArrayList<TituloPropiedad> getTitulos(){
        
        ArrayList<TituloPropiedad> titulos = new ArrayList<>();
        for(int n=0; n<propiedades.size(); n++)
            titulos.add(propiedades.get(n).getTitulo());
        
        return titulos;
    }
    
    public ArrayList<Casilla> getPropiedades(){
        return propiedades;
    }
}
