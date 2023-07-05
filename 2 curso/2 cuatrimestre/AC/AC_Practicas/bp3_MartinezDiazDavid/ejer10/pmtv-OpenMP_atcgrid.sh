#!/bin/bash

export OMP_NUM_THREADS=12

declare -a planificacion=("static" "dynamic" "guided")

for i in "${planificacion[@]}"
do
	for (( j = 0; j < 3; ++j )); do
		if [ $j -eq 0 ]; then
			echo "PLANIFICACION: $i | CHUNK: DEFAULT"
			export OMP_SCHEDULE=$i
		elif [ $j -eq 1 ]; then
			echo "PLANIFICACION: $i | CHUNK: 1"
			export OMP_SCHEDULE="$i,1"
		elif [ $j -eq 2 ]; then
			echo "PLANIFICACION: $i | CHUNK: 64"
			export OMP_SCHEDULE="$i,64"
		fi
		srun ./pmtv-OpenMP 15400
		echo -e "\n"
	done
done

