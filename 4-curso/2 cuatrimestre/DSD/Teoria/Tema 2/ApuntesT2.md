<h1>Tema 2</h1>

<h2>Asignador de Recursos</h2>

<h4>Diseñar un asignador de recursos utilizando las primitivas de paso de mensajes utilizando disntintos canales de comunicacion:</h4>

```C
type clase_op = enum (ADQUIRIR, LIBERAR);
port peticion (int, clase_op, int);
char respuesta [1,..n](int);

// Alguna estructuras de datos y variables a utilizar por el Asignador

var unidades: set of int; pendiente: queue of int;
    disponibles: int:= MAX_UNIDADES;
    indice: int; clase: clase_op; unidad; int;

Cliente[i:1..n]::var unidad:int 
    send peticion (i, ADQUIRIR, -1)
    receive respuesta[i](unidad);

    //usar recurso
    send peticion (i, LIBERAR, unidad);
```

<h3>Solucion del ejercicio: </h3>

```c

Asignador::

    while(true){

        // Indice: identificador de cliente(canal)

        //Suponemos que todas las unidades son iguales, por lo que da igual la unidad recibida o a dar

        receive peticion (indice, clase, unidad);// Es un unico puerto por lo que no se pone [i].

        // Hay que ver si nos piden LIBERAR O ADQUIRIR.
        

        if (clase == ADQUIRIR){

            // Comprobamos si hay alguna unidad disponible
            if(disponible > 0){

                unidad = unidades.pop();
                send respuesta[indice](unidad);
                disponibles--;
            }
            else {
                pendientes.push(indice);
            }
        }
        else if (clase == LIBERAR){

            if(!pendientes.empty()){

                // No podemos hacer unidades++ ya que quitamos pero asignamos directamente
                indice = pendientes.pop();
                send respuesta[indice](unidad);
            }
            else {
                unidades.push(unidad);
                disponibles++;
            }
        }

    }
```

<h4>Funciona tanto para paso de mensajes asincronos como sincronos.</h4>

---

<h2>Ejercicio: Servidor de fichero</h2>

* Hasta n ficheros abiertos a la vez por m clientes.
* El acceso a cada fichero se proporciona por un proceso servidor de fichero distinto.
* Paso de mensajes sincrono.

Operaciones: **[ABRIR, LEER, ESCRIBIR Y CERRAR]**

Solucion:

```c

do receive abrir(nombref, indice_cliente)

    // Si todo va bien, se pueden abrir los ficheros... etc.
    // Corchetes para los canales y parentesis parametros
    send respuesta_abrir[indice_cliente](i);

    do 
        [1] fichero_abierto[i]; 
            receive leer[indice_cliente](args) -> // Emitir, leer, read...;
            send respuesta[indice_cliente](resultados);

        [2] fichero_abierto[i]; receive escribir[indice_cliente](args) --> // Emitir en servidor write

        [3] fichero_abierto[i]; receive cerrar   [indice_cliente](args) --> // Close (... m maquina local)
          fichero_abierto[i] = false;

    od

    fichero_abierto[i] = true;


```

<h2>Formato ADA: </h2>

```c

loop 
	
	select when !fichero_abierto[i]
	  accept abrir(nombref, id_cliente);

		indice_cliente := id_cliente;
		fichero_abierto[i] := true;
		respuesta_abrir[índice_cliente](resultado);
		// abir nombref ??

	  end abrir;

	or when fichero_abierto[i] 
	  accept leer[indice_cliente](args);
		
		respuesta[indice_cliente](args);
	
	  end leer;

	or when fichero_abierto[i]
	  accept escribir[indice_cliente](args);
		// send respuesta ok
		
	  end escribir;

	or when fichero_abierto[i]
	  accept cerrar[indice_cliente](args);
		fichero_abierto[i] := false;
		// close nombref ??
	  end cerrar;

end loop;

```