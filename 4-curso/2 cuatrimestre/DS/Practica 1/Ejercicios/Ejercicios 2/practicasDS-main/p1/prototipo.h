#include <vector>
#include <string> //No debería incluir(std)
#include <iostream>

using namespace std;

enum TipoBarco { B_GRANDE, B_PEQUENIO };
enum TipoPez { P_GRANDE, P_PEQUENIO };

class Barco;
class Pez;

class Barco {
    private:
        // Es el vector que almacena los peces que puede llegar a pescar el barco,
        // sin que todos ellos tengan que ser obligatoriamente pescados
        vector<Pez *> peces;

    protected:
        string nombre;
        float probabilidad;
        
    public:
        Barco() {};
        
        // Comprueba para cada pez de cada barco si ha sido pesaco o no mediante la llamada "serPescado" de la clase Pez
        void pescar();
        void aniadirPez(Pez *pez){ peces.push_back(pez);}
        float getProbabilidad(){return probabilidad;}
        vector<Pez *> getPeces();

        virtual Barco *clone() const = 0;
        string toString(){
            return "barco "+nombre;
        }

        // Destructor de punteros del vector
        ~Barco(){
            for(auto i: peces)
               delete i;
            peces.clear();
        }
};
 
class PesqueroGrande : public Barco{
    public:
        PesqueroGrande() {
            nombre = "grande";
            probabilidad=0.6;
        }

        // Clona el objeto
        PesqueroGrande *clone() const override {
            return new PesqueroGrande(*this);
        }
};

class PesqueroRedes : public Barco{
    public:
        PesqueroRedes() {
            nombre = "pequeño";
            probabilidad=0.9;
        }

        PesqueroRedes *clone() const override {
            return new PesqueroRedes(*this);
        }
};



class Pez {
    private:
        Barco *barco;

    protected:
        string nombre;

    public:
        Pez() {};

        // Comprueba con la probabilidad que tiene el barco que puede pescarlo si es pescado o no
        void serPescado();
        // Le asigna al pez en el que está el barco que lo pesca
        void asignarBarco(Barco *b);

        virtual void print(){ 
            cout << "He sido pescado por un " << barco->toString() << " y soy un pez " << this->nombre << endl;
        }

        virtual Pez *clone() const = 0;

        ~Pez(){
            delete barco;
        }
};

class PezGrande : public Pez {
    public:
        PezGrande() {nombre="pez grande";}
        
        PezGrande *clone() const override{
            return new PezGrande(*this);
        }
};

class PezPequenio : public Pez{
    public:
        PezPequenio() {nombre="pez pequenio";}

        PezPequenio *clone() const override{
            return new PezPequenio(*this);
        }
};

class FactoriaPrototipoPezYBarco {
    private:
        vector <Pez *> _pezPrototipo ;
        vector <Barco *> _barcoPrototipo;

        int capacidad;

    public:
        FactoriaPrototipoPezYBarco( int new_capacidad ) {
            capacidad = new_capacidad;      // Es la cantidad de peces que puede llegar a tener el barco

            _pezPrototipo.resize(2);
            _barcoPrototipo.resize(2);

            _pezPrototipo[TipoPez::P_GRANDE] = new PezGrande();
            _pezPrototipo[TipoPez::P_PEQUENIO] = new PezPequenio();

            _barcoPrototipo[TipoBarco::B_GRANDE] = new PesqueroGrande();
            _barcoPrototipo[TipoBarco::B_PEQUENIO] = new PesqueroRedes();


        };

        int getCapacidad() { return capacidad; }
        
        // Devuelve el nuevo objeto clonado
        Pez *crearPez( TipoPez tipo ) {
            return _pezPrototipo[tipo]->clone();
        };
        Barco *crearBarco( TipoBarco tipo ){
            return _barcoPrototipo[tipo]->clone();
        };

        ~FactoriaPrototipoPezYBarco(){
            delete _pezPrototipo[TipoPez::P_GRANDE];      
            delete _pezPrototipo[TipoPez::P_PEQUENIO];

            delete _barcoPrototipo[TipoBarco::B_GRANDE];
            delete _barcoPrototipo[TipoBarco::B_PEQUENIO];
        }
};




class SesionPesca {
    
    public:
    SesionPesca() {};

    //Errata FactoriaAbstractaPezYBarco no existe
    void crearBarcoSesion(FactoriaPrototipoPezYBarco *factoria);
};
