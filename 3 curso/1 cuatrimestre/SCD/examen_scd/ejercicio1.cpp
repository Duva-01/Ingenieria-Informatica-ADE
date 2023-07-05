// a) MPI_Receive()
Procesos:
begin
  // Envio de mensaje
  MPI_Send(&valor, 1, MPI_INT, id_proceso_receptor, etiq_proceso, MPI_COMM_WORLD)
  MPI_Recv(&valor, 1, MPI_INT, id_proceso_receptor, etiq_proceso, MPI_COMM_WORLD, &estado)  
  // Cuando el receptor lo recibe el programa termina 
end

ProcesoReceptor:
while i < n
  MPI_Recv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_proceso, MPI_COMM_WORLD, &estado);
  int proceso = valor;
  cout << "Me envia mensaje el proceso: " << proceso;
  MPI_Send(&valor, 1, MPI_INT, proceso, etiq_proceso, MPI_COMM_WORLD); // puedes usar el estado para ver el identificador del proceso
end

// b) MPI_Ireceive()
ProcesoReceptor:
MPI_Request peticion;
while i < n
  MPI_IRecv(&valor, 1, MPI_INT, MPI_ANY_SOURCE, etiq_proceso, MPI_COMM_WORLD, &peticion);
  MPI_Wait(&peticion, &estado); 
  int proceso = valor;
  cout << "Me envia mensaje el proceso: " << proceso;
  MPI_Send(&valor, 1, MPI_INT, proceso, etiq_proceso, MPI_COMM_WORLD); // puedes usar el estado para ver el identificador del proceso
  i++
end

// c) SELECT 
ProcesoReceptor:
MPI_Request peticion;
for indice := 0 to n-1
  when receive(&valor, indice);
  do
    int proceso = valor;
    cout << "Me envia mensaje el proceso: " << proceso;
    MPI_Send(&valor, 1, MPI_INT, proceso, etiq_proceso, MPI_COMM_WORLD); // puedes usar el estado para ver el identificador del proceso
  end
end
