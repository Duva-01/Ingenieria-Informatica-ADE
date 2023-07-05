/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ejercicio1;

/**
 *
 * @author Raúl Morgado y Elena Ortega, grupo DS-GP6
 */
public abstract class FactoriaAbstractaPezYBarco {
    public abstract Pez crearPez();
    
    public abstract Barco crearBarco(int capacidad);
    
}

class FactoriaGrande extends FactoriaAbstractaPezYBarco{
    @Override
    public PezGrande crearPez(){
        return new PezGrande(); //implementar
    }
    
    @Override
    public PesqueroGrande crearBarco(int capacidad){        
        PesqueroGrande b = new PesqueroGrande();
        for (int i = 0; i< capacidad; i++){
            Pez p = crearPez();
            p.asignarBarco(b);
            b.aniadirPez(p);
        }       
        return b;       
    }  
}

class FactoriaPequeña extends FactoriaAbstractaPezYBarco{
    @Override
    public PezPequeño crearPez(){
        return new PezPequeño(); //implementar
    }
    
    @Override
    public PesqueroPequeño crearBarco(int capacidad){
        PesqueroPequeño b = new PesqueroPequeño();
        for (int i = 0; i< capacidad; i++){
            Pez p = crearPez();
            p.asignarBarco(b);
            b.aniadirPez(p);
        }       
        return b;    
    }  
}
