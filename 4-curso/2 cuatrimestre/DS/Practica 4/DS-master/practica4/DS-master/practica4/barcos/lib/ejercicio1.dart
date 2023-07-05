import 'dart:math';

abstract class Barco {
    double _probabilidad=0.0;
    List<Pez> peces=[];
    Mar ? _mar;
    
    Barco( double _probabilidad, Mar m)
    {
      this._probabilidad = _probabilidad;
      this._mar = m;
    }
    
    void setProbabilidad(double prob){
        this._probabilidad = prob;
    }

    double getProbabilidad(){return this._probabilidad;}
    
    int pescar(){
      bool hay_mas = true;
      Pez ?pez_aux;
      int indice = 0;
      int cont = 0;
      while(hay_mas)
      {
        pez_aux = _mar?.getPeces().elementAt(indice);

        if(pez_aux!=null){
            if(!pez_aux.serPescado(this))
              indice++;
            else
              cont++;
            
            if(indice == _mar?.getPeces().length)
              hay_mas=false;
              
        }

      }

      return cont;
    }

    void aniadirPez(Pez p){
        peces.add(p);
    }
    
}

class BarcoGrande extends Barco
{
    BarcoGrande(double _probabilidad, Mar mar) : super(_probabilidad,mar);
    @override
    void aniadirPez(Pez p){
        super.aniadirPez(p);
        print("Soy un barco Grande y he pescado!\n");
    }
}

class BarcoPequenio extends Barco
{
    BarcoPequenio(double _probabilidad, Mar mar) : super(_probabilidad,mar);

    @override
    void aniadirPez(Pez p){
        super.aniadirPez(p);
        print("Soy un barco Pequenio y he pescado!\n");
    }
}

abstract class Pez {
    Mar ? _mar;
    Barco ? _barco;
    Pez(Mar m){
        this._mar = m;
    }
    void aniadirBarco(Barco b){this._barco = b;}
    bool serPescado(Barco b);
}

class PezGrande extends Pez{

  PezGrande(Mar m) : super(m);

    @override
    bool serPescado(Barco b){
        bool sePuede = false;
        if(b.runtimeType.toString() == "BarcoGrande"){
            Random rnd;
            int min = 0;
            int max = 100;
            rnd = new Random();
            int r = min + rnd.nextInt(max - min);
            double res = r/100;
            //Compruebo probabilidad
            if(res<b.getProbabilidad()){
                sePuede=true;
                b.aniadirPez(this);
                super.aniadirBarco(b);
                
                // eliminamos el pex del array del mar
                this._mar?.eliminarPez(this);
                print("Soy un Pez Grande y he sido pescado\n");
            }
        }
        return sePuede;
    }
}

class PezPequenio extends Pez{

  PezPequenio(Mar m) : super(m);

    @override
    bool serPescado(Barco b){
        bool sePuede = false;
        if(b.runtimeType.toString() == "BarcoPequenio"){
            Random rnd;
            int min = 0;
            int max = 100;
            rnd = new Random();
            int r = min + rnd.nextInt(max - min);
            double res = r/100;
            //Compruebo probabilidad
            if(res<b.getProbabilidad()){
                sePuede=true;
                b.aniadirPez(this);
                super.aniadirBarco(b);
                
                // eliminamos el pex del array del mar
                this._mar?.eliminarPez(this);
                print("Soy un Pez Pequenio y he sido pescado\n");
            }
        }
        return sePuede;
    }
}

class Mar
{
  List<Pez> _peces=[];
  List<Barco> _barcos=[];

  String ? nombre;

  List<Barco> getBarcos() => _barcos;

  List<Pez> getPeces() => _peces;
    //En este constructor no hemos metido por parametros ni barcos ni peces, para eso tenemos aniadir peces
  Mar(String nombre)
  {
    this.nombre = nombre;
  }
  
  void aniadirPez(Pez pescado) => _peces.add(pescado);
  
  void aniadirPeces(List<Pez> peces) => _peces = _peces + peces;

  void aniadirBarco(Barco barco) => _barcos.add(barco); 

  void aniadirBarcos(List<Barco> barcos) => _barcos = _barcos + barcos;

  void eliminarPez(Pez p) => _peces.remove(p);
}

abstract class FactoriaAbstracta {
    Barco crearBarco(double probabilidad, Mar m);
    Pez crearPez(Mar m);

    //crearMar no llega nada
    Mar crearMar(String nombre){
        return Mar(nombre);
    }
}

class FactoriaAbstractaPequenia extends FactoriaAbstracta
{
  //FactoriaAbstractaPequenia();
  
  BarcoPequenio crearBarco(double probabilidad, Mar mar )
  {
    return BarcoPequenio(probabilidad,mar);
  }

  PezPequenio crearPez(Mar mar)
  {
    return PezPequenio(mar);
  }

}

class FactoriaAbstractaGrande extends FactoriaAbstracta{
    BarcoGrande crearBarco(double probabilidad, Mar m){
        return BarcoGrande(probabilidad, m);
    }

    PezGrande crearPez(Mar m){
        return PezGrande(m);
    }
}

Mar mar = Mar("Mar Mediterraneao");
FactoriaAbstractaGrande fG = FactoriaAbstractaGrande();
FactoriaAbstractaPequenia fP = FactoriaAbstractaPequenia();

