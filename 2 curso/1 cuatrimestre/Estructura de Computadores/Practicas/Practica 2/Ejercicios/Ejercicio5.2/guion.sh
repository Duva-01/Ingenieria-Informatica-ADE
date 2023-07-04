#!/bin/bash

for i in $(seq 1 9); do 
rm Ejercicio5-2; 
gcc -x assembler-with-cpp -D TEST=$i -no-pie Ejercicio5-2.s -o Ejercicio5-2; echo -n "T#$i "; 
./Ejercicio5-2; 

done;

