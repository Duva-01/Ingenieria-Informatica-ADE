# Ejercicios Tema 2:

## - Ejercicio 52:

Se consideran dos tipos de recursos accesibles por varios procesos concurrentes (denominamos
a los recursos como recursos de tipo 1 y de tipo 2). Existen N1 ejemplares de recursos de tipo
1 y N2 ejemplares de recursos de tipo 2.
Para la gestión de estos ejemplares, queremos diseñar un monitor (con semántica SU) que exporta un procedimiento (pedir_recurso), para pedir un ejemplar de uno de los dos tipos
de recursos. Este procedimiento incluye un parámetro entero (tipo), que valdrá 1 ó 2 indicando el tipo del ejemplar que se desea usar, asimismo, el monitor incorpora otro procedimiento
(liberar_recurso) para indicar que se deja de usar un ejemplar de un recurso previamente
solicitado (este procedimiento también admite un entero que puede valer 1 ó 2, según el tipo
de ejemplar que se quiera liberar). En ningún momento puede haber un ejemplar de un tipo de
recurso en uso por más de un proceso.
En este contexto, responde a estas cuestiones:

(a) Implementa el monitor con los dos procedimientos citados, suponiendo que N1 y N2 son
dos constantes arbitrarias, mayores que cero.

```c++

Monitor Recursos;
CondVar cola[2];

int ejemplares_disponibles[2];

void pedir_recurso(int tipo){

    if(ejemplares_disponibles[tipo-1] == 0){
        cola[tipo-1].wait();
    }
    ejemplares_disponibles[tipo-1]--;
}

void liberar_recurso(int tipo){

    ejemplares_disponibles[tipo-1]++;
    cola[tipo-1].signal();
}

int main(){

    ejemplares_disponibles[0] = N1;
    ejemplares_disponibles[1] = N2;
}
```



(b) El uso de este monitor puede dar lugar a interbloqueo. Esto ocurre cuando más de un
proceso tiene algún punto en su código en el cual necesita usar dos ejemplares de distinto
tipo a la vez. Describe la secuencia de peticiones que da lugar a interbloqueo.

```c++

    proceso 1:

    begin 
        for(int n=0; n<N1; n++){
            pedir_recurso(1);
        }
        pedir_recurso(2);
    end

    proceso 2:

    begin 
        for(int n=0; n<N2; n++){
            pedir_recurso(2);
        }
        pedir_recurso(1);
    end
```



(c) Una posible solución al problema anterior es obligar a que si un proceso necesita dos recursos de distinto tipo a la vez, deba de llamar a pedir_recurso, dando un parámetro
con valor 0, para indicar que necesita los dos ejemplares. En esta solución, cuando un
ejemplar quede libre, se dará prioridad a los posibles procesos esperando usar dos ejemplares, frente a los que esperan usar solo uno de ellos.

```c++

Monitor Recursos;
CondVar cola[2];
CondVar peticion_doble;

int ejemplares_disponibles[2];

void pedir_recurso(int tipo){

    if(tipo == 0){
        if(ejemplares_disponibles[0] == 0 && ejemplares_disponibles[1] == 0){
        peticion_doble.wait();
    }

    }
    if(ejemplares_disponibles[tipo-1] == 0){
        cola[tipo-1].wait();
    }
    ejemplares_disponibles[tipo-1]--;
}

void liberar_recurso(int tipo){

    ejemplares_disponibles[tipo-1]++;

    if(peticion_doble.queue()){
        if(ejemplares_disponibles[0] > 0 && ejemplares_disponibles[1] > 0){

        }
    }
    else {
        cola[tipo-1].signal();

    }
    
}

int main(){

    ejemplares_disponibles[0] = N1;
    ejemplares_disponibles[1] = N2;
}
```

## Ejercicio 53:

53. Escribir una solución al problema de lectores-escritores con monitores:


(a) Con prioridad a los lectores: quiere decir que, si en un momento puede acceder al recurso
tanto un lector como un escritor, se da paso preferentemente al lector.

``` c++
class LecEs 
{
    private:

    int numLectores,   
        numEcritores;

    conVar lectores,
            escritores;
    
    public:

    void inicioEscritura();
    void inicioLectura();
    void finalEscritura();
    void finalLectura();

}

LecEs::LecEs
{
    lectores = newConvar();
    escritores = newConvar();

    numLectores = 0;
    numEscritores = 0;

}

LecEs::inicioEscritura()
{
    if( !(numLectores == 0) || !(numEscritores == 0) )
        escritores.wait();
        
    numEscritores++;

}

/***********************************************************************************************/
LecEs::inicioLectura()
{
    if( !(numEscritores == 0) )
        lectores.wait();
        
    numLectores++;

    lectores.signal();
}
/***********************************************************************************************/
LecEs::finalEscritura()
{
    numEscritores--;

    if( lectores.empty() )
        escritores.signal();
    else
    {
        lectores.signal();
    }

}
/***********************************************************************************************/
LecEs::finalLectura()
{
    numLectores--;

    if( lectores.empty() )
        escritores.signal();
    
}
/***********************************************************************************************/
void funcion_hebra_lectora(MRef <LecEs> monitor){
        while(true)
        {
            monitor->inicioLectura();
            this_thread::sleep_for(chrono::milliseconds(aleatorio<20,200>()));
            monitor->finalLectura();
        }
}
       

/***********************************************************************************************/

void funcion_hebra_escritora(MRef <LecEs> monitor){
        while(true)
        {
            monitor->inicioEscritura();
            this_thread::sleep_for(chrono::milliseconds(aleatorio<20,200>()));
            monitor->finalEscritura();
        }
}

/***********************************************************************************************/

int main()
{

       cout <<  "HoareMonitorSU" << endl ;

   // declarar el número total de hebras 
   const int num_hebras      = 6;

   // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
   MRef<HoareMonitorSU> Lec_Esc = Create<HoareMonitorSU>();

   // crear y lanzar hebras fumadoras
   thread hebra[num_hebras];
   for( unsigned i = 0 ; i < num_hebras-3 ; i++ )
      hebra[i] = thread( funcion_hebra_lectora, Lec_Esc);
    
    for( unsigned i = num_hebras-3 ; i < num_hebras ; i++ )
      hebra[i] = thread( funcion_hebra_escritor, Lec_Esc);
    
   // esperar a que terminen las hebras (no pasa nunca)
   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra[i].join();
    
 
    return 0;
}

```
(b) Con prioridad a los escritores: quiere decir que, si en un momento puede acceder tanto
un lector como un escritor, se da paso preferentemente al escritor.

``` c++
class LecEs 
{
    private:

    int numLectores,   
        numEcritores;

    conVar lectores,
            escritores;
    
    public:

    void inicioEscritura();
    void inicioLectura();
    void finalEscritura();
    void finalLectura();

}

LecEs::LecEs
{
    lectores = newConvar();
    escritores = newConvar();

    numLectores = 0;
    numEscritores = 0;

}

LecEs::inicioEscritura()
{
    if( !(numLectores == 0) || !(numEscritores == 0) )
        escritores.wait();
        
    numEscritores++;

}

/***********************************************************************************************/
LecEs::inicioLectura()
{
    if( !(numEscritores == 0) )
        lectores.wait();
        
    numLectores++;

    if(escritores.empty())
        lectores.signal();
}
/***********************************************************************************************/
LecEs::finalEscritura()
{
    numEscritores--;

    if( !escritores.empty() )
        escritores.signal();
    else
    {
        lectores.signal();
    }

}
/***********************************************************************************************/
LecEs::finalLectura()
{
    numLectores--;

    if( !escritores.empty() )
        escritores.signal();
    
    
}
/***********************************************************************************************/
void funcion_hebra_lectora(MRef <LecEs> monitor){
        while(true)
        {
            monitor->inicioLectura();
            this_thread::sleep_for(chrono::milliseconds(aleatorio<20,200>()));
            monitor->finalLectura();
        }
}
       

/***********************************************************************************************/

void funcion_hebra_escritora(MRef <LecEs> monitor){
        while(true)
        {
            monitor->inicioEscritura();
            this_thread::sleep_for(chrono::milliseconds(aleatorio<20,200>()));
            monitor->finalEscritura();
        }
}

/***********************************************************************************************/

int main()
{

       cout <<  "HoareMonitorSU" << endl ;

   // declarar el número total de hebras 
   const int num_hebras      = 6;

   // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
   MRef<HoareMonitorSU> Lec_Esc = Create<HoareMonitorSU>();

   // crear y lanzar hebras fumadoras
   thread hebra[num_hebras];
   for( unsigned i = 0 ; i < num_hebras-3 ; i++ )
      hebra[i] = thread( funcion_hebra_lectora, Lec_Esc);
    
    for( unsigned i = num_hebras-3 ; i < num_hebras ; i++ )
      hebra[i] = thread( funcion_hebra_escritor, Lec_Esc);
    
   // esperar a que terminen las hebras (no pasa nunca)
   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra[i].join();
    
 
    return 0;
}

```

(c) Con prioridades iguales: en este caso, los procesos acceden al recurso estrictamente en
orden de llegada, lo cual implica, en paricular, que si hay lectores leyendo y un escritor
esperando, los lectores que intenten acceder después del escritor no podrán hacerlo hasta
que no lo haga dicho escritor.

``` c++
const int numHebras = 6;//Suponemos que tenemos 6 hebras ejecutando el programa

class LecEs 
{
    private:

    int numLectores,   
        numEcritores;

    int    hebras[numHebras],
            libres,
            ocupadas;


    conVar colaHebras;
    
    public:

    void inicioEscritura();
    void inicioLectura();
    void finalEscritura();
    void finalLectura();

    numLectores = 0;
}

LecEs::LecEs()
{
    colaHebras = newConvar();

    numLectores = 0;
    numEcritores = 0;
    libres = 0;
    ocupadas = 0;
}

/***********************************************************************************************/
LecEs::inicioEscritura()
{
    hebras[libres] = 1;
    libres = (libres+1)%numHebras;

    if( numEscritrores != 0 || numLectores != 0 )
        colaHebras.wait();

    ocupadas = (ocupadas+1)%numHebras;//Hacemos el ocupadas ++ aqui para prevenir que no avance en la primera hebra que entra

    Escritor = true;

}

/***********************************************************************************************/
LecEs::inicioLectura()
{
    hebras[libres] = 0;
    libres = (libres+1)%numHebras;

    if( numEscritores > 0 )
        colaHebras.wait();

      ocupadas = (ocupadas+1)%numHebras;

    if(hebras[ocupadas] == 0) //la siguiente hebra es una lectora
        colaHebras.signal();
      
    
        
}
/***********************************************************************************************/
LecEs::finalEscritura()
{
    numEscritores--;
    colaHebras.signal();
}
/***********************************************************************************************/
LecEs::finalLectura()
{
    numLectores--;
    colaHebras.signal();
}
/***********************************************************************************************/
void funcion_hebra_lectora(MRef <LecEs> monitor){
        while(true)
        {
            monitor->inicioLectura();
            this_thread::sleep_for(chrono::milliseconds(aleatorio<20,200>()));
            monitor->finalLectura();
        }
}
       

/***********************************************************************************************/

void funcion_hebra_escritora(MRef <LecEs> monitor){
        while(true)
        {
            monitor->inicioEscritura();
            this_thread::sleep_for(chrono::milliseconds(aleatorio<20,200>()));
            monitor->finalEscritura();
        }
}

/***********************************************************************************************/

int main()
{

       cout <<  "HoareMonitorSU" << endl ;

   // declarar el número total de hebras 
   const int num_hebras      = 6;

   // crear monitor  ('monitor' es una referencia al mismo, de tipo MRef<...>)
   MRef<HoareMonitorSU> Lec_Esc = Create<HoareMonitorSU>();

   // crear y lanzar hebras fumadoras
   thread hebra[num_hebras];
   for( unsigned i = 0 ; i < num_hebras-3 ; i++ )
      hebra[i] = thread( funcion_hebra_lectora, Lec_Esc);
    
    for( unsigned i = num_hebras-3 ; i < num_hebras ; i++ )
      hebra[i] = thread( funcion_hebra_escritor, Lec_Esc);
    
   // esperar a que terminen las hebras (no pasa nunca)
   for( unsigned i = 0 ; i < num_hebras ; i++ )
      hebra[i].join();
    
 
    return 0;
}

```



