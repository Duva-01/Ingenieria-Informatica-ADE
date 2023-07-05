// const no hace referencia a que no se pueda modificar el elemento, si
// no que no se peuda cambiar el objeto al que apunta

// Para ello utilizariamos la variable let


const botonComentario = document.getElementById('botonComentario');
botonComentario.addEventListener('click', activarContenedor);

function activarContenedor() {
    
    // Consigo el elemento 
    var seccionComentario = document.getElementById("seccionComentario");

    // Si esta en oculto, lo muestro y si no al reves
    if (seccionComentario.style.display === "none") {
        seccionComentario.style.display = "grid";
    } else {
        seccionComentario.style.display = "none";
    }
  }

//----------------------------------------------//

const comentariosEnviados = document.getElementById("comentariosEnviados");
const botonEnviarFormulario = document.getElementById('botonEnviar');
botonEnviarFormulario.addEventListener('click', enviarComentario);

function enviarComentario() {

    // Expresion regular para comprobar que es un email valido
    var validRegex = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;

    // Cogemos la informacion de cada uno de los campos del formulario 

    var nombreFormulario = document.getElementById('nombreFormulario').value;
    var emailFormulario = document.getElementById('emailFormulario').value;
    var textoComentario = document.getElementById('textoComentario').value;
    

    if(nombreFormulario != "" && emailFormulario.match(validRegex) && textoComentario != ""){
        
        // Crear el elemento div con la clase "comentario"
        var nuevoComentario = document.createElement('div');
        nuevoComentario.classList.add('comentario');

        // Crear el elemento h3 y agregar el texto al elemento

        var fechaHora = new Date();

        // Obtener la fecha actual
        var fecha = fechaHora.toLocaleDateString();

        // Obtener la hora actual
        var hora = fechaHora.toLocaleTimeString();

        var h3 = document.createElement('h3');
        var h3Texto = document.createTextNode(nombreFormulario + " " + fecha + " " + hora);
        h3.appendChild(h3Texto);

        // Crear el elemento p y agregar el texto al elemento
        var p = document.createElement('p');
        var pTexto = document.createTextNode(textoComentario);
        p.appendChild(pTexto);

        // Agregar los elementos h3 y p al elemento div
        nuevoComentario.appendChild(h3);
        nuevoComentario.appendChild(p);

        // Agregar el elemento div a nuestra seccion de comentarios
        comentariosEnviados.appendChild(nuevoComentario);

        
    }
    else {
        alert("algo mal");
    }

}

const textoComentario = document.getElementById('textoComentario');

// Definimos las palabras prohibidas en un array
const palabrasProhibidas = ['cabra', 'camion', 'puta']; 

textoComentario.addEventListener('input', cambiarPalabrasProhibidas);

function cambiarPalabrasProhibidas() {

    const textoOriginal = textoComentario.value;
    let textoModificado = textoOriginal;

    // Para cada palabra de las prohibidas, creamos una expresion regular:
    // Los parametros "gi" indican que queremos buscar todas las coincidencias.

    palabrasProhibidas.forEach(palabra => {
        const regex = new RegExp(palabra, 'gi');
        textoModificado = textoModificado.replace(regex, '*'.repeat(palabra.length));
    });

    // Cambiamos el texto modificado

    textoComentario.value = textoModificado;
}


