int valor = ProducirBloque();
MPI_Request peticion;
while (i < n) {
  if(i != id_propio){
    MPI_Isend(&valor, 1, MPI_INT, i, etiq, MPI_COMM_WORLD, &peticion)
    for (indice := 0 to n - 1){
      when MPI_Recv(bloque, indice)
      do
        ConsumirBloque(bloque);
      end
    }
    
  }
}
