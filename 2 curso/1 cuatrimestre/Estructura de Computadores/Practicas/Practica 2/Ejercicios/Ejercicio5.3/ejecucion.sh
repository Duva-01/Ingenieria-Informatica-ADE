#!/bin/bash
for i in $(seq 1 11); do rm suma_con_signo; gcc -x assembler-with-cpp -D TEST=$i -no-pie suma_con_signo.s -o suma_con_signo; echo -n "T#$i "; ./suma_con_signo ; done

