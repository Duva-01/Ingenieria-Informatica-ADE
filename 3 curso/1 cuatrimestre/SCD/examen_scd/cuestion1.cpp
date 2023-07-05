#include <mpi.h>
MPI_Status estado;
MPI_Request peticion_recibir, peticion_enviar;
int valor;
const int etiq_recibir = 1;
int id_vecino, id_propio;

MPI_Comm_rank(MPI_COMM_WORLD, &id_propio);
if (id_propio % 2 == 0) 
  id_vecino = id_propio + 1 % num_procesos;
else 
  id_vecino = id_propio - 1 % num_procesos;

MPI_IRecv(&valor, 1, MPI_INT, id_vecino, etiq_recibir, MPI_COMM_WORLD, &peticion_recibir)
MPI_ISend(&valor, 1, MPI_INT, id_vecino, etiq_recibir, MPI_COMM_WORLD, &peticion_enviar);

if(es_impar){
  MPI_Wait(&peticion_recibir, &estado);
  MPI_Wait(&peticion_enviar, &estado);
}else{
  MPI_Wait(&peticion_enviar, &estado);
  MPI_Wait(&peticion_recibir, &estado);
}
