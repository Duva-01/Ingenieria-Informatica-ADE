#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

void ComportamientoJugador::PintarFinalMapa(Sensores sensores){

	for(int i=0; i<mapaResultado.size(); i++){
		
		for(int j=0; j<mapaResultado.size(); j++){

			if(mapaResultado[i][j] == '?'){

				if((i < 3) or (j < 3) or ((mapaResultado.size()-i) < 3) or ((mapaResultado.size()-j) < 3)){
					mapaResultado[i][j] = 'P';
				}

				else {

					switch(mapaResultado[i-1][j]){

						case 'B':
							cont_bosque++;
						break;

						case 'A':
							cont_agua++;
						break;

						case 'S':
							cont_piedra++;
						break;

						case 'T':
							cont_arena++;
						break;

						default:
							cont_arena++;
					}

					switch(mapaResultado[i+1][j]){

						case 'B':
							cont_bosque++;
						break;

						case 'A':
							cont_agua++;
						break;

						case 'S':
							cont_piedra++;
						break;

						case 'T':
							cont_arena++;
						break;

						default:
							cont_arena++;
					}

					switch(mapaResultado[i][j-1]){

						case 'B':
							cont_bosque++;
						break;

						case 'A':
							cont_agua++;
						break;

						case 'S':
							cont_piedra++;
						break;

						case 'T':
							cont_arena++;
						break;

						default:
							cont_arena++;
					}

					switch(mapaResultado[i][j+1]){

						case 'B':
							cont_bosque++;
						break;

						case 'A':
							cont_agua++;
						break;

						case 'S':
							cont_piedra++;
						break;

						case 'T':
							cont_arena++;
						break;

						default:
							cont_arena++;
					}
					
					if ((cont_arena >= cont_agua) and (cont_arena >= cont_bosque) and (cont_arena >= cont_piedra)){
						mapaResultado[i][j] = 'T';
					}
					else if ((cont_piedra >= cont_agua) and (cont_piedra >= cont_bosque) and (cont_piedra >= cont_arena)){
						mapaResultado[i][j] = 'S';
					}
					else if ((cont_bosque >= cont_agua) and (cont_bosque >= cont_arena) and (cont_bosque >= cont_piedra)){
						mapaResultado[i][j] = 'B';
					}
					else{
						mapaResultado[i][j] = 'A';
					}
				}
				

			}

			cont_bosque = 0;
			cont_agua = 0;
			cont_piedra = 0;
			cont_arena = 0;
		}
	}
					
}

void ComportamientoJugador::PintarMapa(int direccion, Sensores sensores){

	int tam_vision, 
			sensor_fila,
			sensor_columna,
			saltos,
			i;

		switch(direccion){

			case 0:

				tam_vision = 0;
				sensor_fila = 0;
				sensor_columna = 0;
				saltos = 0;
				i = 0;
				
				while(i < 16){

					sensor_columna = saltos;

					for(int j=0; j<tam_vision+1; j++){
						
						mapaResultado[fil+sensor_fila][col+sensor_columna] = sensores.terreno[i];
						sensor_columna++;	
						i++;
					}
					
					tam_vision += 2;
					sensor_fila --;
					saltos--;
				}


			break;
			case 1:

				tam_vision = 0;
				sensor_fila = 0;
				sensor_columna = 0;
				saltos = 0;
				i = 0;

				while(i < 16){

					sensor_fila = saltos;

					for(int j=0; j<tam_vision+1; j++){

						mapaResultado[fil+sensor_fila][col+sensor_columna] = sensores.terreno[i];
						sensor_fila++;	
						i++;
					}
					
					tam_vision += 2;
					sensor_columna++;
					saltos--;
				}

			break;

			case 2:

				tam_vision = 0;
				sensor_fila = 0;
				sensor_columna = 0;
				saltos = 0;

				i = 0;
				
				while(i < 16){

					sensor_columna = saltos;

					for(int j=0; j<tam_vision+1; j++){

						mapaResultado[fil+sensor_fila][col+sensor_columna] = sensores.terreno[i];
						sensor_columna--;	
						i++;
					}
					
					tam_vision += 2;
					sensor_fila ++;
					saltos++;
				}

			break;

			case 3:

				tam_vision = 0;
				sensor_fila = 0;
				sensor_columna = 0;
				saltos = 0;
				i = 0;
				
				while(i < 16){

					sensor_fila = saltos;

					for(int j=0; j<tam_vision+1; j++){

						mapaResultado[fil+sensor_fila][col+sensor_columna] = sensores.terreno[i];
						sensor_fila--;	
						i++;
					}
					
					tam_vision += 2;
					sensor_columna--;
					saltos++;
				}

			break;
		}
}

void ComportamientoJugador::AlgoritmoBusquedaCoste(Sensores sensores){

	if(cont_coste > 15){

		for(int j=0; j<16; j++){

			switch(sensores.terreno[j]){

				case 'T':
					coste_terreno = 2;
				break;

				case 'A':

					if(bikini){
						coste_terreno = 1;
					}
					else{
						coste_terreno = 200;
					}
					
				break;

				case 'B':
					
					if(zapatillas){
						coste_terreno = 1;
					}
					else{
						coste_terreno = 100;
					}

				break;
				
				case 'P':
					coste_terreno = 500;
				break;
				
				default :
					coste_terreno = 1;
			}

			if (j == 1 or j == 4 or j == 5 or j == 9 or j == 10 or j == 11){
				coste_zona_a += coste_terreno;
			}
			else if (j == 3 or j == 7 or j == 8 or j == 13 or j == 14 or j == 15){
				coste_zona_b += coste_terreno;
			}
			
			coste_terreno = 0;
		}

		int diferencia_coste = 0;

		if(coste_zona_a > coste_zona_b){
			diferencia_coste = coste_zona_a - coste_zona_b;
		}
		else {
			diferencia_coste = coste_zona_b - coste_zona_a;
		}

		grado_arriesgo = 1 + rand() % (4 + 1 - 1) ;

		switch(grado_arriesgo){

			case 1:
				grado_arriesgo = 10000;
			break;

			case 2:
				grado_arriesgo = 500;
			break;

			case 3:
				grado_arriesgo = 100;
			break;

			case 4:
				grado_arriesgo = 1;
			break;
		}

		cout << "Diferencia de coste: " << diferencia_coste << endl;

		if(diferencia_coste < grado_arriesgo and sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P' and puede_pasar == true){
			
			accion = actFORWARD;
			cout << "Diferencia de coste pequeña, avanzo" << endl;
			cont_coste = 0;
			 
		}
		else if(coste_zona_a < coste_zona_b){
			accion = actTURN_L;
			cout << "Giro a la izquierda" << endl;
			cont_coste = 0;
		}
		else {
			accion = actTURN_R;
			cout << "Giro a la derecha" << endl;
			cont_coste = 0;
		}
		diferencia_coste = 0;
		coste_zona_a = 0;
		coste_zona_b = 0;
	}
	else{

		if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P' and puede_pasar == true){
			
			accion = actFORWARD;
			cout << "Avanzo de manera predeterminada" << endl;
			cont_coste++;
		}
		
		else {

			if(girar_derecha){
				accion = actTURN_R;
				cout << "Giro a la derecha" << endl;
				cont_coste++;
			}
			else{
				accion = actTURN_L;
				cout << "Giro a la izquierda" << endl;
				cont_coste++;
			}
			
		}

	}
}

void ComportamientoJugador::AlgoritmoPuerta(Sensores sensores){

	if(!ir_hacia_zonaA_puerta and !ir_hacia_zonaB_puerta and !ir_recto_puerta){
		
		if(((sensores.terreno[15] == 'M' or sensores.terreno[15] == 'P') and  (sensores.terreno[9] == 'M' or sensores.terreno[9] == 'P')) and ((sensores.terreno[11] != 'M' or sensores.terreno[11] != 'P') or (sensores.terreno[12] != 'M' or sensores.terreno[12] != 'P') or (sensores.terreno[13] != 'M' or sensores.terreno[13] != 'P') or (sensores.terreno[14] != 'M' or sensores.terreno[14] != 'P') or (sensores.terreno[10] != 'M' or sensores.terreno[10] != 'P'))){
			hay_puerta = true;
		}
		else{
			hay_puerta = false;
		}
		
		if(hay_puerta){


				if (casilla_encontrada == false and (sensores.terreno[11] != 'M' and sensores.terreno[11] != 'P')){
					ir_hacia_zonaA_puerta = true;
					casilla_encontrada = true;
				}
				else if (casilla_encontrada == false and (sensores.terreno[10] != 'M' and sensores.terreno[10] != 'P')){
					ir_hacia_zonaA_puerta = true;
					casilla_encontrada = true;
				}
				else if (casilla_encontrada == false and (sensores.terreno[13] != 'M' and sensores.terreno[13] != 'P')){
					ir_hacia_zonaB_puerta = true;
					casilla_encontrada = true;
				}
				else if (casilla_encontrada == false and (sensores.terreno[14] != 'M' and sensores.terreno[14] != 'P')){
					ir_hacia_zonaB_puerta = true;
					casilla_encontrada = true;
				}
				else if (casilla_encontrada == false and (sensores.terreno[12] != 'M' and sensores.terreno[12] != 'P')){
					ir_recto_puerta = true;
					casilla_encontrada = true;
				}

				casilla_encontrada = false;
			}
		
		
	}

		if(!ir_hacia_zonaA and !ir_hacia_zonaB and !ir_recto){

			cout << "Aplicamos busqueda de coste: " << endl;
			
			
			if(cont_intercalar_algoritmo < 10){
				cont_intercalar_algoritmo++;
				AlgoritmoMuros(sensores);
			}
			else{
				cont_intercalar_algoritmo = 0;
				AlgoritmoBusquedaCoste(sensores);
			}
			
			
		}
		
		if(ir_hacia_zonaA_puerta){

			switch(ultimaAccion){

				case actFORWARD:

					if(check_mitad_mov_puerta == false){
						accion = actTURN_L;
						cout << "Esta en la zona A, giro hacia la izquierda" << endl;
					}
					else{
						accion = actTURN_R;
						cout << "Esta en la zona A, giro hacia la derecha" << endl;
						ir_hacia_zonaA_puerta = false;
						check_mitad_mov_puerta = false;
					}

				break;

				case actTURN_R:

					if(check_mitad_mov_puerta == false){
						accion = actTURN_L;
						cout << "Esta en la zona A, giro hacia la izquierda" << endl;
					}
					else{
						accion = actTURN_R;
						cout << "Esta en la zona A, giro hacia la derecha" << endl;
						ir_hacia_zonaA_puerta = false;
						check_mitad_mov_puerta = false;
					}

				break;

				case actTURN_L:

					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
						accion = actFORWARD;
						cout << "Esta en la zona A, avanzo" << endl;
						check_mitad_mov_puerta = true;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
					

				break;

				default :

					ir_hacia_zonaA_puerta = false;
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
						accion = actFORWARD;
						cout << "Aplico default zona a, Avanzo" << endl;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
			}
		}
		else if(ir_hacia_zonaB_puerta){

			switch(ultimaAccion){

				case actFORWARD:

					if(check_mitad_mov_puerta == false){
						accion = actTURN_R;
						cout << "Esta en la zona B, giro hacia la derecha" << endl;
					}
					else{
						accion = actTURN_L;
						ir_hacia_zonaB_puerta = false;
						check_mitad_mov_puerta = false;
						cout << "Esta en la zona B, giro hacia la izquierda" << endl;
					}

				break;
				
				case actTURN_L: 

					if(check_mitad_mov_puerta == false){
						accion = actTURN_R;
						cout << "Esta en la zona B, giro hacia la derecha" << endl;
					}
					else{
						accion = actTURN_L;
						ir_hacia_zonaB_puerta = false;
						check_mitad_mov_puerta = false;
						cout << "Esta en la zona B, giro hacia la izquierda" << endl;
					}

				break;

				case actTURN_R:

					
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
			
						accion = actFORWARD;
						cout << "Esta en la zona B, avanzo" << endl;
						check_mitad_mov_puerta = true;
						cont_coste++;
					}
					else{
						accion = actIDLE;
					}

				break;

				default :
					
					ir_hacia_zonaB_puerta = false;
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
			
						accion = actFORWARD;
						cout << "Avanzo" << endl;
						cont_coste++;
					}
				
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
							
					}	
				
			}
		}

		else if (ir_recto_puerta){

			if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
			
					accion = actFORWARD;
					cout << "Esta recto Avanzo" << endl;
					cont_coste++;
				}
				
				else {

					if(girar_derecha){
						accion = actTURN_R;
						cout << "Giro a la derecha" << endl;
						cont_coste++;
					}
					else{
						accion = actTURN_L;
						cout << "Giro a la izquierda" << endl;
						cont_coste++;
					}
							
				}
			
			ir_recto_puerta = false;
		}
}

void ComportamientoJugador::AlgoritmoMuros(Sensores sensores){

	if(!ir_muro_derecha and !ir_muro_izquierda){
		
		if(((sensores.terreno[1] == 'M' or sensores.terreno[1] == 'P') and  (sensores.terreno[5] == 'M' or sensores.terreno[5] == 'P')) and ((sensores.terreno[11] != 'M' and sensores.terreno[11] != 'P')) ){
			ir_muro_izquierda = true;
			cout << "Muro izquierda encontrado" << endl;
		}
		else if (((sensores.terreno[3] == 'M' or sensores.terreno[3] == 'P') and  (sensores.terreno[7] == 'M' or sensores.terreno[7] == 'P')) and ((sensores.terreno[13] != 'M' and sensores.terreno[13] != 'P')) ){
			ir_muro_derecha = true;
			cout << "Muro derecha encontrado" << endl;
		}
	}

		if(!ir_muro_derecha and !ir_muro_izquierda){

			cout << "Aplicamos busqueda de coste: " << endl;

			AlgoritmoBusquedaCoste(sensores);
		}
		
		if(ir_muro_derecha){

			switch(ultimaAccion){

				case actFORWARD:

					if(cont_adelante == 3){
						accion = actTURN_R;
						cont_adelante = 0;
					}
					else {

						if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
							accion = actFORWARD;
							cout << "Aplico default zona a, Avanzo" << endl;
							cont_adelante++;
						}
					
						else {
							
							ir_muro_derecha = false;
							if(girar_derecha){
								accion = actTURN_R;
								cout << "Giro a la derecha" << endl;
								cont_coste++;
							}
							else{
								accion = actTURN_L;
								cout << "Giro a la izquierda" << endl;
								cont_coste++;
							}
									
						}
					}
					

				break;

				case actTURN_R:

						ir_muro_derecha = false;
						if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
							accion = actFORWARD;
							cout << "Aplico default zona a, Avanzo" << endl;
	
						}
					
						else {
							
							
							if(girar_derecha){
								accion = actTURN_R;
								cout << "Giro a la derecha" << endl;
								cont_coste++;
							}
							else{
								accion = actTURN_L;
								cout << "Giro a la izquierda" << endl;
								cont_coste++;
							}
									
						}

				break;

				default :

					ir_muro_derecha = false;
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
						accion = actFORWARD;
						cout << "Aplico default zona a, Avanzo" << endl;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
			}
		}
		if(ir_muro_izquierda){

			switch(ultimaAccion){

				case actFORWARD:

					if(cont_adelante == 3){
						accion = actTURN_L;
						cont_adelante = 0;
					}
					else {

						if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
							accion = actFORWARD;
							cout << "Aplico default zona a, Avanzo" << endl;
							cont_adelante++;
						}
					
						else {
							
							ir_muro_izquierda = false;
							if(girar_derecha){
								accion = actTURN_R;
								cout << "Giro a la derecha" << endl;
								cont_coste++;
							}
							else{
								accion = actTURN_L;
								cout << "Giro a la izquierda" << endl;
								cont_coste++;
							}
									
						}
					}
					

				break;

				case actTURN_L:

						ir_muro_izquierda = false;
						if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
							accion = actFORWARD;
							cout << "Aplico default zona a, Avanzo" << endl;
	
						}
					
						else {
							
							
							if(girar_derecha){
								accion = actTURN_R;
								cout << "Giro a la derecha" << endl;
								cont_coste++;
							}
							else{
								accion = actTURN_L;
								cout << "Giro a la izquierda" << endl;
								cont_coste++;
							}
									
						}

				break;

				default :

					ir_muro_izquierda = false;
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
						accion = actFORWARD;
						cout << "Aplico default zona a, Avanzo" << endl;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
			}
		}

}

void ComportamientoJugador::AlgoritmoPosicionamiento(Sensores sensores){


		if(!ir_hacia_zonaA and !ir_hacia_zonaB and !ir_recto){

			for(int j=0; j<16 and (casilla_encontrada == false); j++){

				if((bien_situado == false and sensores.terreno[j] == 'G') or (bikini == false and sensores.terreno[j] == 'K') or (zapatillas == false and sensores.terreno[j] == 'D') or (fin_recarga ==  false and sensores.terreno[j] == 'X')){

					casilla_encontrada = true;
				}

				if ((j == 1 or j == 4 or j == 5 or j == 9 or j == 10 or j == 11) and casilla_encontrada){
					ir_hacia_zonaA = true;
					casilla_encontrada = false;
				}
				else if ((j == 3 or j == 7 or j == 8 or j == 13 or j == 14 or j == 15) and casilla_encontrada){
					ir_hacia_zonaB = true;
					casilla_encontrada = false;
				}
				else if ((j == 2 or j == 6 or j == 12) and casilla_encontrada){
					ir_recto = true;
					casilla_encontrada = false;
				}
			}
		}

		if(!ir_hacia_zonaA and !ir_hacia_zonaB and !ir_recto){
			AlgoritmoPuerta(sensores);
		}
		
		if(ir_hacia_zonaA){

			switch(ultimaAccion){

				case actFORWARD:

					if(check_mitad_mov == false){
						accion = actTURN_L;
						cout << "Esta en la zona A, giro hacia la izquierda" << endl;
					}
					else{
						accion = actTURN_R;
						cout << "Esta en la zona A, giro hacia la derecha" << endl;
						ir_hacia_zonaA = false;
						check_mitad_mov = false;
					}

				break;

				case actTURN_L:

					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
						accion = actFORWARD;
						cout << "Esta en la zona A, avanzo" << endl;
						check_mitad_mov = true;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
					

				break;

				default :

					ir_hacia_zonaA = false;
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
				
						accion = actFORWARD;
						cout << "Aplico default zona A, avanzo" << endl;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
			}
		}
		else if(ir_hacia_zonaB){

			switch(ultimaAccion){

				case actFORWARD:

					if(check_mitad_mov == false){
						accion = actTURN_R;
						cout << "Esta en la zona B, giro hacia la derecha" << endl;
					}
					else{
						accion = actTURN_L;
						ir_hacia_zonaB = false;
						check_mitad_mov = false;
						cout << "Esta en la zona B, giro hacia la izquierda" << endl;
					}

				break;

				case actTURN_R:

					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
			
						accion = actFORWARD;
						cout << "Esta en la zona B, avanzo" << endl;
						check_mitad_mov = true;
						cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
					

				break;

				default :

					ir_hacia_zonaB = false;
					if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
			
					accion = actFORWARD;
					cout << "Aplico default zona B, avanzo" << endl;
					cont_coste++;
					}
					
					else {

						if(girar_derecha){
							accion = actTURN_R;
							cout << "Giro a la derecha" << endl;
							cont_coste++;
						}
						else{
							accion = actTURN_L;
							cout << "Giro a la izquierda" << endl;
							cont_coste++;
						}
								
					}
			}
		}

		else if (ir_recto){

				if(sensores.superficie[2] == '_'  and sensores.terreno[2] != 'M' and sensores.terreno[2] != 'P'){
			
					accion = actFORWARD;
					cout << "Zona recta, avanzo" << endl;
					cont_coste++;
				}
				
				else {

					if(girar_derecha){
						accion = actTURN_R;
						cout << "Giro a la derecha" << endl;
						cont_coste++;
					}
					else{
						accion = actTURN_L;
						cout << "Giro a la izquierda" << endl;
						cont_coste++;
					}
							
				}
			
			ir_recto = false;
		}
}

Action ComportamientoJugador::think(Sensores sensores){

	cout << "Posicion sensor: [" << sensores.posF << "][" <<sensores.posC <<"]." << endl;

	cout << "Sensor Brujula: ";
	switch(sensores.sentido){
		case 0: cout << "--> Norte" << endl; break;
		case 1: cout << "--> Este" << endl; break;
		case 2: cout << "--> Sur " << endl; break;
		case 3: cout << "--> Oeste" << endl; break;
	}
	
	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;
	
	//--------------------------------------------------------------//

	
	if(sensores.terreno[0] == 'K'){
		bikini = true;
	}
	else if(sensores.terreno[0] == 'D'){
		zapatillas = true;
	}
	
	switch(ultimaAccion){

		case actFORWARD:

			switch (brujula){
				case 0: fil--; break;
				case 1: col++; break;
				case 2: fil++; break;
				case 3: col--; break;			
			}

		break;

		case actTURN_R:
			brujula = (brujula+1)%4;
			girar_derecha = (rand()%2 == 0);
			
		break;
		
		case actTURN_L:
			brujula = (brujula+3)%4;
			girar_derecha = (rand()%2 == 0);
		break;
	}

	if(sensores.reset == true){
		bien_situado = false;
		bikini = false;
		zapatillas = false;
		brujula = 0;
	}

	cout << endl << "-----------------------------------------" << endl;
	cout << "Me encuentro en [" << fil << "][" << col << "]" << endl;
	cout << "Brujula: " << brujula << endl;
	cout << "Numero de veces sin evaluar: " << cont_coste << endl;
	
	cout << endl << "-----------------------------------------" << endl;

	if(sensores.terreno[0] == 'G' and !bien_situado){
		fil = sensores.posF;
		col = sensores.posC;
		bien_situado = true;
	}

	if(((sensores.terreno[2] == 'B' and zapatillas) or sensores.terreno[0] == 'B') or ((sensores.terreno[2] == 'A' and bikini) or sensores.terreno[0] == 'A') or (sensores.terreno[0] == 'K') or (sensores.terreno[0] == 'X')){
			puede_pasar = true;
		}
	else{
		puede_pasar = false;
	}

	if(sensores.bateria < 2500){
		fin_recarga = false;
	}

	if((sensores.terreno[2] != 'A' and sensores.terreno[2] != 'B')){
		puede_pasar = true;
	}
		
	if (sensores.terreno[0] == 'X' and fin_recarga == false and sensores.vida > 500){
		
		if(sensores.bateria > 4800){
			fin_recarga = true;
			esperar_recarga = 0;
		}

		accion = actIDLE;
		esperar_recarga++;
	}
	else {

		if(bien_situado == false){

			cout << "Zona A: " << ir_hacia_zonaA << endl;
			cout << "Zona B: " << ir_hacia_zonaB << endl;
			cout << "Seguir Recto: " << ir_recto << endl;

			AlgoritmoPosicionamiento(sensores);
		}
		else{
		
			PintarMapa(brujula, sensores);
		
			if(bikini == false or zapatillas == false or fin_recarga == false){
				AlgoritmoPosicionamiento(sensores);
			}
			else {
				//AlgoritmoBusquedaCoste(sensores);
				AlgoritmoPuerta(sensores);
			}
		}
	}

	if(sensores.vida < 100 or sensores.bateria < 100){
		PintarFinalMapa(sensores);
	}

	ultimaAccion = accion;

	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}