#!/bin/bash
for i in $(seq 1 20); 
	do rm Ejercicio5-4; 
	gcc -x assembler-with-cpp -D TEST=$i -no-pie Ejercicio5-4.s -o Ejercicio5-4; 
	echo -n "T#$i "; ./Ejercicio5-4 ; 
done

