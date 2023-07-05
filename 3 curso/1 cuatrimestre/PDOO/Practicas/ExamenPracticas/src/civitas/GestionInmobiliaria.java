package civitas;

public class GestionInmobiliaria {
    
    private int propiedad;
    private OperacionInmobiliaria operacion;

    public GestionInmobiliaria (OperacionInmobiliaria gest, int ip){

        propiedad = ip;
        operacion = gest;
    }

    public OperacionInmobiliaria getOperacion(){

        return operacion;
    }

    public int getPropiedad(){

        return propiedad;
    }


}
