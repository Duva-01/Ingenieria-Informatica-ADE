
// Algoritmos distribuidos

// EXCLUSION MUTUA

// Exclusion mutua Algoritmo distribuido basado en relojes logicos (Ricart/Agrawala)

//Variables de estado

{LIBERADO,INTENTANDO,EN_SC} :: estado 
time :: Tiempo
int :: n_proceso
int :: contador_respuestas
Proceso i [1..n];
// Codigo de proceso

//----------------------------------------------------------------------------------------------
//Inicializacion
estado = LIBERADO

// Obtencion del token
estado = INTENTANDO

Tiempo = getTiempo()

for (int j=0;j<n_procesos;j++)
    send peticion[i](Tiempo,this.n_proceso)

while(contador_respuestas < n-1)
{}

estado = EN_SC;

< SC >

estado = LIBERADO
contador_respuestas = 0;
for(int i=0; i < peticiones_pendientes.size(); i++){
    send respuesta[peticiones_pendientes[i]]();
}

//----------------------------------------------------------------------------------------------
:: PARTE-SERVIDOR
do 
    estado != EN_SC; receive peticion[i](ptiempo, n_proceso) => 
                if(((estado == INTENTANDO) and (Tiempo <  ptiempo or (ptiempo==Tiempo and n_proceso < this.n_proceso))))
                    peticiones_pendientes.push(n_proceso);
                else
                    send respuesta[n_proceso](); 
                    
    estado == INTENTANDO; receive respuesta[i]()=> contador_respuestas++; 
od

//----------------------------------------------------------------------------------------------


//-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/

//----------------------------------------------------------------------------------------------
// Exclusión mutua con algoritmo basado en anillo:

ClientePropio::

cliente j [1..m];
send peticion_cliente[id_servidor](j);
receive permiso_sc[j]();
//Ejecuto SC
send soltar_sc[id_Servidor]();



//----------------------------------------------------------------------------------------------

Servidor ::

while true 
{
    receive token[i]();
    tengo_token=true;
    
    do
    
        (tengo_token && !cliente_en_sc) && timeout < tiempoMaxEspera; receive peticion_cliente[i](id_cliente) =>
            cliente_en_sc=true; send permiso_sc[id_cliente]();
            
        (tengo_token && cliente_en_sc); receive soltar_sc[i]() => 
            cliente_en_sc=false;
        
        tengo_token && timeout > tiempoMaxEspera && !cliente_en_sc ; send token[i%n + 1]() => 
            tengo_token = false; 

    od
}


//----------------------------------------------------------------------------------------------

//-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/

//----------------------------------------------------------------------------------------------

// ELECCION

// Algoritmo del Valentón

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
        true; receive eleccion[i](n_proceso)=> 
            send respuesta[n_proceso](); iniciarSeleccion();
            
        espero_respuesta && timeoutRespuesta < tiempoParaRespuestas ;receive respuesta[i](n_proceso)=> 
            *inicio timeoutCoordinador*
            if 
                timeoutCoordinador < timeoutParaCoordinador; receive coordinador[i]();
                timeoutCoordinador > timeoutParaCoordinador; => iniciarSeleccion();
            fi

        espero_respuesta && timeoutRespuesta > tiempoParaRespuestas; =>
            coordinador=mi_id_proceso;
            while (Para cada proceso con id menor)
                send coordinador[proceso](mi_id_proceso);

        true; receive coordinador[i](id_proceso)=> coordinador = id_proceso;
    fi;
}

//----------------------------------------------------------------------------------------------

//-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/

//----------------------------------------------------------------------------------------------

// ANILLOS CON ELECCION

// Algoritmo del eleccion basado en anillos

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

//----------------------------------------------------------------------------------------------

//-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/

//----------------------------------------------------------------------------------------------

// ALGORITMOS DE CONSENSO

// ALGORITMO GENERAL DE CONSENSO


int rondas = 1; 
int valor_mandar = rand(); //Podría ser cualquier numero, pero pongo este de ejemplo
vector recibidos;
recibidos.push(valor_mandar);

for(int i=0; i < rondas; i++){
    
    for(int j=0; j < n_procesos_vivos; j++){

        if(j != mi_n_proceso)
            send envio_valores[j](recibidos); //SUPONGO QUE PUEDO ENVIAR VECTORES ENTEROS
    }

    n_recibos=0;
    
    do 
        n_recibos < n_procesos_vivos; receive envio_valores[k](valores)=> {
            recibidos.push(valores);
            n_recibos++;
        }
        timeout > tiempoParaRecibirTodasRespuestas; => rondas+=(n_procesos_vivos - n_recibos); n_procesos_vivos = n_recibos;
    od;
        
}

eleccion = recibidos.min();

//----------------------------------------------------------------------------------------------

//-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/-//-/-///-/-/

//----------------------------------------------------------------------------------------------

// ALGORITMOS DE CONSENSO

// ALGORITMO GENERALES BIZANTINOS


int rondas = 1; 
//Debo recibir este valor del general
receive valorGeneral(valor_mandar);
vector recibidos;
recibidos.push(valor_mandar);

for(int i=0; i < rondas; i++){
    
    for(int j=0; j < n_procesos_vivos; j++){

        if(j != mi_n_proceso)
            send envio_valores[j](valor_mandar); //Ahora mando el valor que me dijo el general
    }

    n_recibos=0;
    
    do 
        n_recibos < n_procesos_vivos; receive envio_valores[k](valor)=> {
            recibidos.push(valor); //Sumo una vez a las veces que me ha llegado un valor. Si me lleva una v y ya tenia una el contador de v = 2.
            n_recibos++;
        }
        timeout > tiempoParaRecibirTodasRespuestas; => rondas+=(n_procesos_vivos - n_recibos); n_procesos_vivos = n_recibos;
    od;
        
}

eleccion = recibidos.maxRepetido(); //Aquí elijo el valor que más se repita.


