let indiceActual = 0;
const imagenes = document.getElementsByClassName("carrusel-imagen");
const botonAnterior = document.getElementById("boton-anterior");
const botonSiguiente = document.getElementById("boton-siguiente");

function mostrarImagen(indice) {
  for (let i = 0; i < imagenes.length; i++) {
    imagenes[i].classList.remove("active");
  }
  imagenes[indice].classList.add("active");
}

function imagenAnterior() {
  indiceActual--;
  if (indiceActual < 0) {
    indiceActual = imagenes.length - 1;
  }
  mostrarImagen(indiceActual);
}

function imagenSiguiente() {
  indiceActual++;
  if (indiceActual >= imagenes.length) {
    indiceActual = 0;
  }
  mostrarImagen(indiceActual);
}

botonAnterior.addEventListener("click", imagenAnterior);
botonSiguiente.addEventListener("click", imagenSiguiente);

// Muestra la primera imagen al cargar la página
mostrarImagen(indiceActual);
