/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Se quiere construir un programa que lea el número total de escaños a 
	distribuir, el número de partidos que han participado en las elecciones y 
	los votos obtenidos por cada uno de ellos. El programa mostrará cuántos 
	escaños obtuvo cada partido.	
		
		Entrada: - Escaños.
				 - Votos.
				 - Partidos.
						 
		Salida:  - Escaños -- Partido.
				 		
	
*/
/***************************************************************************/

#include <iostream>			// Incluye las opciones de E/S.

using namespace std;

int main () {				// Programa Principal

	
	// Variables

	int const MAX_PARTIDOS = 10;
	int escanios, n = 0, j = 0;
	long votos_partido, ganar_escanio, mayor_votos = 0;
	

	
	struct Partidos {
	
        char sigla;;
        long votos;
        int escanios;

    };
    
	Partidos partido[MAX_PARTIDOS];
	
/***************************************************************************/	
	
	// Entrada de Datos
	
	cout << endl;
	cout << "- Introduzca el numero de escanios: "; cin >> escanios;
	cout << endl;

	cout << endl;
	cout << "- Para parar de crear partidos ponga '*'. -";
	cout << endl;

	do {
		
		
		cout << endl;
		cout << "- Introduzca la sigla de su partido: "; cin >> partido[n].sigla;
		cout << endl;
	
		if (partido[n].sigla != '*') {
		
		cout << endl;
		cout << "- Introduzca el numero de votos: "; cin >> partido[n].votos;
		cout << endl;
		
		n++;
		
		}
		
	}while (MAX_PARTIDOS >= n && partido[n].sigla != '*');

/***************************************************************************/
	
	// Limpieza
	
	do {

		partido[j].escanios = 0;
		j++;
			
	}while (j != n);
	
/***************************************************************************/
	
	// Calculo
	
	for (int i = 0; i < escanios; i++) {

        for (int u = 0; u < n; u++){

            votos_partido = partido[u].votos / (partido[u].escanios + 1);

            if (votos_partido > mayor_votos) {

                mayor_votos = votos_partido;
                ganar_escanio = u;
				
            }
        }

        partido[ganar_escanio].escanios ++;
        mayor_votos = 0;

    }
    
/***************************************************************************/
	
	// Salida de Datos
	
	j = 0;
	
	do {
		
		cout << "El partido "<< partido[j].sigla << " tiene " 
		 	<< partido[j].escanios << " escanios.";
		
		cout << endl;
		j++;
			
	}while (j != n);

return 0;

}
