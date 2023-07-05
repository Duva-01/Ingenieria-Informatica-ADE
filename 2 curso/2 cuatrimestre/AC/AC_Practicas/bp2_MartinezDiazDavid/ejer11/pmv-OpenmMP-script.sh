#!/bin/bash

echo "Secuencial"
./pmv-secuencial 8000
./pmv-secuencial 24000

echo "Paralelo"

for ((N=0; N<=16; N++)); do

	echo " $N threads "
	export OMP_NUM_THREADS=$N
	./pmv-OpenMP-a 8000
	./pmv-OpenMP-a 24000 
done 

echo " 32 threads "
export OMP_NUM_THREADS=32
./pmv-OpenMP-a 8000
./pmv-OpenMP-a 24000 
