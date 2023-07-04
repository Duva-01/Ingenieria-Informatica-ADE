// gcc -Og bomba.c -o bomba -no-pie -fno-guess-branch-probability

#include <stdio.h>	// para printf(), fgets(), scanf()
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()
#include <sys/time.h>	// para gettimeofday(), struct timeval

#define SIZE 100
#define TLIM 60

char password[]= {'c'+5,'h'+5,'i'+5,'c'+5,'k'+5,'e'+5,'n'+5,'s'+5,'\n'+5};	// contrasena
int  passcode = 2544; // pin

void boom(void){

	printf(	"\n"
		"***************\n"
		"*** BOMBA EXPLOTADA!!!!!! ***\n"
		"***************\n"
		" ___________________    . , ; .\n"
		"(___________________|~~~~~X.;' .\n"
		"\n");
	exit(-1);
}

void defused(void){

	printf(	"\n"
		"---- NOS SALVAMOS!!!! ----\n"
		"	    __ \n"     
		"	   / _|\n"   
		" ___  __ _| |_ ___\n" 
		"/ __|/ _` |  _/ _ \ \n"
		"\__ \ (_| | ||  __/\n"
		"|___/\__,_|_| \___|\n"
		"\n");
	exit(0);
}

int main(){

	char pw[SIZE];
	int  pc, n;

	struct timeval tv1,tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1,NULL);


	printf(	"\n"
		"Corre que se acaba el tiempo!!! (60 segs) \n"
		"  ________\n"
 		" /  12    \\ \n"
		"|    |     | \n"
		"|9   |    3| \n"
		"|     \\    | \n"
		"|       \\  | \n"
		" \\___6___ / \n"
		"\n");

//------------------------------------------------------------------

	// Pedimos la contraseña y la pasamos a codificarla.

	do	printf("\nIntroduce la contrasena: ");
	while (	fgets(pw, SIZE, stdin) == NULL );

	for(int i=0;i<SIZE;i++){
        	pw[i]=pw[i]+5;
	}

//------------------------------------------------------------------

	// Comparamos las contraseñas, si es incorrecta, explota.

	if    (	strncmp(pw,password,sizeof(password)) )
	    boom();

	// Comparamos los tiempos, si se pasa, explota.

	gettimeofday(&tv2,NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM )
	    boom();

//------------------------------------------------------------------

	// Pedimos el pin y pasamos a codificarlo.

	do  {	printf("\nIntroduce el pin: ");
	 if ((n=scanf("%i",&pc))==0)
		scanf("%*s")    ==1;         }
	while (	n!=1 );


//------------------------------------------------------------------

	// Comparamos los pines, si es incorrecta, explota.

	if    (	(pc) != (passcode) )
	    boom();

	// Comparamos los tiempos, si se pasa, explota.

	gettimeofday(&tv1,NULL);
	if    ( tv1.tv_sec - tv2.tv_sec > TLIM )
	    boom();

	defused();
}
