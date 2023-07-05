<h1> Apuntes Tema 3 </h1>


```c

Clientes[i:1..n];

...

send solicitar[i]();
recieve conceder[i]();

// Exclusion mutua

...

// Fin

send liberar[i]();

...
```

```c
Replica[i:1..n];

while true {

    receive token[i]();

    if !empty(solicitor[i]){
        receive solicitor[i]();
        send conceder[i]();
        receive liberar[i]();
    }

    send token[(i%n)+1]();
}
```

---

## Correcion examen Tema 2:

### Pregunta practicas:

* Vamos a suponer que tenemos 2 unidades de recursos:
  * 1 impresora que es rapida
  * 1 impresora que es lenta

* Vamos a tener clientes que van a pedir lo siguiente:
  * Clientes que piden la impresora rapida.
  * Clientes que piden la impresora lenta.
  * Clientes que piden las 2 impresoras

El servidor no sabe en que orden le van a llegar las peticiones, lo primero de todo implementar las operaciones:

* Adquirir Recurso:
  * Adquirir --> Clientes que le dan igual el recurso.
* Liberar Recurso

```c
type RangoI is Positive range 1..N:

    adquirir()

    adquirir_1(){

    }

    adquirir_2(){

    }

    liberar()

```
---
```c

impresora1 = 1;
impresora2 = 1;

disponibles = 2;

do 

    in 

        ((adquirir_1().empty() && adquirir_2().empty()) or contador >= 10) && disponibles > 0
            => accept adquirir() do

                if impresora_1 == libre
                    id == impresora1;
                else 
                    id = impresora2;
                    impresora2 = 0;

                disponibles--;
                contador = 0;
            od

        impresora1 == libre && contador > 10
        ==> accept adquirir_1() do
            impresora1 = 0;
            disponibles--;

            if(!adquirir().empty()){
                contador++;
            }
            

        od

        impresora2 == libre && contador > 10
        ==> accept adquirir_2() do
            impresora2 = 0;
            disponibles--;
            if(!adquirir().empty()){
                contador++;
            }
        od

        (true); accept liberar(int id) do

            if(id==impresora1){
                impresroa1 = 1;
            }else {
                impresora2 = 1;
            }

            disponibles++;

        od

    ni 

od
```

Sustitucion de codigo de arriba:

```c
impresora(RangoI) && contador < 10 =>
    accept adquirir (rangoI)() {

        impresora (RangoI) = 0;
        if (!adquirir.empty()){
            contador++;
        }
    }

```

Seguramente relojes logicos o anillos.

Implementa con estrcuturas guardadas para tal algoritmo, implementando otra cosa.

Tienen sentido las instrucciones guardadas de comunicacion.

Hay que implementar lo que falta del reloj logico.


---

## Implementacion de los algoritmos de Exclusion Mutua

### Algoritmo servidor centralizado

```c
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Algoritmo servidor centralizado

mailbox peticion[]
chan respuesta[], salir[]
cliente_sc :: bool
id_cliente_sc :: int

// cliente

    send peticion[id_servidor](id_cliente);

    receive respuesta[id_servidor]();

    send salir[id_servidor]();

// servidor

do
    !cliente_sc; receive peticion[](id_cliente) =>
        cliente_sc = true;
        id_cliente_sc = id_cliente;
        time.start();

        send respuesta[id_cliente]();
    
    cliente_sc && time < time_max; receive salir[id_cliente_sc]() =>
        cliente_sc = false;
        id_cliente_sc = cipollo;

    time >= time_max =>
        cliente_sc = false;
        id_cliente_sc = cipollo;

od
```

### Algoritmo de relojes logico (Ricart):

```c

{LIBERADO,INTENTANDO,EN_SC} :: estado 
time :: Tiempo
int :: n_proceso
int :: contador_respuestas
Proceso i [1..n];

Servidor::

do 
    estado != EN_SC; receive peticion[i](ptiempo, n_proceso) => 
                if(((estado == INTENTANDO) and (Tiempo <  ptiempo or (ptiempo==Tiempo and n_proceso < this.n_proceso))))
                    peticiones_pendientes.push(n_proceso);
                else
                    send respuesta[n_proceso](); 
                    
    estado == INTENTANDO; recive respuesta[i] =>
        n_respuestas++;

    estado == EN_SC; receive peticion[i](ptiempo, n_proceso) => 
        peticiones_pendientes.push(n_proceso);
od

---

Cliente:: 

estado = LIBERADO

// Obtencion del token
estado = INTENTANDO
Tiempo = getTiempo()

// Hago el multicast
for (int j=0;j<n_procesos;j++)
    send peticion[i](Tiempo,this.n_proceso)

while(contador_respuestas < n-1){}

--------
estado = EN_SC;

<Lo que sea en Seccion Critica>

estado = LIBERADO
contador_respuestas = 0;

for(int i=0; i < peticiones_pendientes.size(); i++){
    send respuesta[peticiones_pendientes[i]]();
}

```

### Algoritmo de E.M con anillos:

```c


Servidor ::

while true 
{
    receive token[i]();
    token=true;
    
    do
    
        (token == true && !cliente_en_sc) && timeout < tiempoMaxEspera; receive peticion_cliente[i](id_cliente) =>
            cliente_en_sc=true; send permiso_sc[id_cliente]();
            
        (token == true && cliente_en_sc); receive soltar_sc[i]() => 
            cliente_en_sc=false;
        
        (token == true) && timeout > tiempoMaxEspera && !cliente_en_sc ; send token[i%n + 1]() => 
            token = false; 

    od
}


----------------------------------------

Cliente::

cliente j [1..m];

while (true){

    send peticion_cliente[id_servidor](j);
    receive permiso_sc[j]();

    //Ejecuto SC
    send soltar_sc[id_Servidor]();

}
```

## Implementacion de los algoritmos de Eleccion

### Algoritmo bully

```c

Clinte-Bully::

iniciarSeleccion(){
    
    for(j = i; j < n_procesos ;j++)
    {
        send eleccion[j]();
        espero_respuesta = true;
        *inicio un tiempoParaRespuestas*
    }
        
}

Servidor-Bully::

while true 
{
    if
        true; receive eleccion[]()=> 
            send respuesta[](); iniciarSeleccion();
            
        espero_respuesta && timeoutRespuesta < tiempoParaRespuestas ;receive respuesta[]()=> 
            *inicio timeoutCoordinador*
            if 
                [] timeoutCoordinador < timeoutParaCoordinador; recive coordinador[i](n_proceso); =>
                    coordinador = n_proceso;

                [] timeoutCoordinador > timeoutParaCoordinador; => iniciarSeleccion();
            fi

        espero_respuesta && timeoutRespuesta > tiempoParaRespuestas; =>
            coordinador=mi_id_proceso;
            while (Para cada proceso con id menor)
                send coordinador[proceso](mi_id_proceso);

        true; receive coordinador[i](id_proceso)=> coordinador = id_proceso;
    fi;
}

```

### Algoritmo anillos de eleccion

```c

Proceso_cliente::

inicia_eleccion()
{
    estado = participante;
    send eleccion[(i%n_procesos) +1](this.n_proceso);
}

Servidor-Anillo::

participante=false;
coordinador=false;
while true {

    if 
        !participante; receive seleccion[i](id_proceso)=>{
            participante=true;
            if(id_proceso < mi_id_proceso){
                send seleccion[mi_id_proceso%n + 1](mi_id_proceso);
            }else{
                send seleccion[mi_id_proceso%n + 1](id_proceso);
            }
        }

        participante; receive seleccion[i](id_proceso){
            if(id_proceso==mi_id_proceso){
                coordinador = mi_id_proceso;
                send coordinador[mi_id_proceso%n + 1](mi_id_proceso);
            } else if(id_proceso > mi_id_proceso){
                send seleccion[mi_id_proceso%n + 1](id_proceso);
            }
        }

        participante; receive coordinador[i](id_proceso)=> 
            if(id_proceso != mi_id_proceso){
                send coordinador[mi_id_proceso%n + 1](id_proceso);
                coordinador = id_proceso;
            } 
                
    fi;
}

```

## Algoritmo de consenso

### Algoritmo de consenso general

```c
ronda = 1

detactar_caida();

mailbox compartir[]


recibidos[] = numero_actual;
enviados[]

for(i = 0; i < ronda ;i++)
{
    for(j = 0;j<n_procesos;j++)
        send compartir[j](recibidos);

    enviados.add(recibidos);
    recibidos.erase();
    
    do
        [] n_recibidos < n_proceso_vivos && time < timeout;recieve compartir[](recividos) =>
            recibidos += recividos;
            recibidos.filtrar_duplicados(enviados); // elimina los comunes entre los dos en recibidos
            n_recibidos++;

        [] time > timeout || n_recibidos == n_proceso_vivos; exit();
    od
    
    ronda += detectar_caida();
}

d = enviados.min();
```

### Algoritmo de generales bizantinos

```c

numeros[]

// general
for(i=0;i<n_procesos;i++)
    if( i != this.n_proceso)
        send numero[i](numero);   

// comandantes

recieve numero[general.n_proceso](numero);

for(i = 0; i < ronda ;i++)
{
    for(i=0;i<n_procesos;i++)
        if( i != this.n_proceso && i != general.n_proceso)
            send numero[i](numero);  

    do
        time < time_max ; recive numero[](numero) =>
            numeros.add(numero);
        
        time > time_max || n_recibidos < n_procesos-2; exit();
    od

    ronda += detectar_caida();
}

decision = numeros.majority();

```