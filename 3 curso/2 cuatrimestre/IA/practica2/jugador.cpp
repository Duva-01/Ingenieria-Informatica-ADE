#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>

// Este es el método principal que se piden en la practica.
// Tiene como entrada la información de los sensores y devuelve la acción a realizar.
// Para ver los distintos sensores mirar fichero "comportamiento.hpp"


void ComportamientoJugador::PintarMapa(estado actual, Sensores sensores){
	
	int direccion = actual.orientacion;

	int fil = actual.fila;
	int col = actual.columna;

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

				mapaResultado[fil][col] = sensores.terreno[0];

				mapaResultado[fil - 1][col] = sensores.terreno[1];
				mapaResultado[fil - 1][col + 1] = sensores.terreno[2];
				mapaResultado[fil][col + 1] = sensores.terreno[3];

				mapaResultado[fil - 2][col] = sensores.terreno[4];
				mapaResultado[fil - 2][col + 1] = sensores.terreno[5];
				mapaResultado[fil - 2][col + 2] = sensores.terreno[6];
				mapaResultado[fil - 1][col + 2] = sensores.terreno[7];
				mapaResultado[fil][col + 2] = sensores.terreno[8];

				mapaResultado[fil - 3][col] = sensores.terreno[9];
				mapaResultado[fil - 3][col + 1] = sensores.terreno[10];
				mapaResultado[fil - 3][col + 2] = sensores.terreno[11];
				mapaResultado[fil - 3][col + 3] = sensores.terreno[12];
				mapaResultado[fil - 2][col + 3] = sensores.terreno[13];
				mapaResultado[fil - 1][col + 3] = sensores.terreno[14];
				mapaResultado[fil][col + 3] = sensores.terreno[15];

			break;

			case 2:

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

			case 3:

				mapaResultado[fil][col] = sensores.terreno[0];

				mapaResultado[fil][col + 1] = sensores.terreno[1];
				mapaResultado[fil + 1][col + 1] = sensores.terreno[2];
				mapaResultado[fil + 1][col] = sensores.terreno[3];

				mapaResultado[fil][col + 2] = sensores.terreno[4];
				mapaResultado[fil + 1][col + 2] = sensores.terreno[5];
				mapaResultado[fil + 2][col + 2] = sensores.terreno[6];
				mapaResultado[fil + 2][col + 1] = sensores.terreno[7];
				mapaResultado[fil + 2][col] = sensores.terreno[8];

				mapaResultado[fil][col + 3] = sensores.terreno[9];
				mapaResultado[fil + 1][col + 3] = sensores.terreno[10];
				mapaResultado[fil + 2][col + 3] = sensores.terreno[11];
				mapaResultado[fil + 3][col + 3] = sensores.terreno[12];
				mapaResultado[fil + 3][col + 2] = sensores.terreno[13];
				mapaResultado[fil + 3][col + 1] = sensores.terreno[14];
				mapaResultado[fil + 3][col] = sensores.terreno[15];

			break;

			case 4:

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

			case 5:

				mapaResultado[fil][col] = sensores.terreno[0];

				mapaResultado[fil + 1][col] = sensores.terreno[1];
				mapaResultado[fil + 1][col - 1] = sensores.terreno[2];
				mapaResultado[fil][col - 1] = sensores.terreno[3];

				mapaResultado[fil + 2][col] = sensores.terreno[4];
				mapaResultado[fil + 2][col - 1] = sensores.terreno[5];
				mapaResultado[fil + 2][col - 2] = sensores.terreno[6];
				mapaResultado[fil + 1][col - 2] = sensores.terreno[7];
				mapaResultado[fil][col - 2] = sensores.terreno[8];

				mapaResultado[fil + 3][col] = sensores.terreno[9];
				mapaResultado[fil + 3][col - 1] = sensores.terreno[10];
				mapaResultado[fil + 3][col - 2] = sensores.terreno[11];
				mapaResultado[fil + 3][col - 3] = sensores.terreno[12];
				mapaResultado[fil + 2][col - 3] = sensores.terreno[13];
				mapaResultado[fil + 1][col - 3] = sensores.terreno[14];
				mapaResultado[fil][col - 3] = sensores.terreno[15];

			break;

			case 6:

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

			case 7:

				mapaResultado[fil][col] = sensores.terreno[0];

				mapaResultado[fil][col - 1] = sensores.terreno[1];
				mapaResultado[fil - 1][col - 1] = sensores.terreno[2];
				mapaResultado[fil - 1][col] = sensores.terreno[3];

				mapaResultado[fil][col - 2] = sensores.terreno[4];
				mapaResultado[fil - 1][col - 2] = sensores.terreno[5];
				mapaResultado[fil - 2][col - 2] = sensores.terreno[6];
				mapaResultado[fil - 2][col - 1] = sensores.terreno[7];
				mapaResultado[fil - 2][col] = sensores.terreno[8];

				mapaResultado[fil][col - 3] = sensores.terreno[9];
				mapaResultado[fil - 1][col - 3] = sensores.terreno[10];
				mapaResultado[fil - 2][col - 3] = sensores.terreno[11];
				mapaResultado[fil - 3][col - 3] = sensores.terreno[12];
				mapaResultado[fil - 3][col - 2] = sensores.terreno[13];
				mapaResultado[fil - 3][col - 1] = sensores.terreno[14];
				mapaResultado[fil - 3][col] = sensores.terreno[15];

			break;
		}
}

bool ComportamientoJugador::descubiertoCasillaEspecial(){

	bool encontrado = false;
	estado casillaEspecial;

	for(int f = 0; f < mapaResultado.size() and encontrado == false; f++){

		for(int c = 0; c < mapaResultado.size() and encontrado == false; c++){

			if(mapaResultado[f][c] == 'X'){
				
				encontrado = true;
				fila_especial = f;
				columna_especial = c;
			}
			
		}
	}
	
	return encontrado;
}

void ComportamientoJugador::modificarPosicionamiento(Action ultimaAccion){

	switch(ultimaAccion){

		case actTURN_R:
			nivel_4_orientacion = (nivel_4_orientacion + 2) % 8;
		break;
			
		case actSEMITURN_R:
			nivel_4_orientacion = (nivel_4_orientacion + 1) % 8;
		break;

		case actTURN_L:
			nivel_4_orientacion = (nivel_4_orientacion + 6) % 8;
		break;
			
		case actSEMITURN_L:
			nivel_4_orientacion = (nivel_4_orientacion + 7) % 8;
		break;

		case actFORWARD:

			switch (nivel_4_orientacion){

				case 0:
					nivel_4_fila--;
					break;
				case 1:
					nivel_4_fila--;
					nivel_4_columna++;
					break;
				case 2:
					nivel_4_columna++;
					break;
				case 3:
					nivel_4_fila++;
					nivel_4_columna++;
					break;
				case 4:
					nivel_4_fila++;
					break;
				case 5:
					nivel_4_fila++;
					nivel_4_columna--;
					break;
				case 6:
					nivel_4_columna--;
					break;
				case 7:
					nivel_4_fila--;
					nivel_4_columna--;
					break;
			}

		break;

	}
}

Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;
	list<estado> objetivo_casilla_especial;

	estado destino_aux;
	list<estado> tres_objetivos;

	int contador;

	if(sensores.nivel != 4){

		actual.fila = sensores.posF;
		actual.columna = sensores.posC;
		actual.orientacion = sensores.sentido;
	}

	cout << "Fila: " << actual.fila << endl;
	cout << "Col : " << actual.columna << endl;
	cout << "Ori : " << actual.orientacion << endl;

	if(sensores.nivel == 4){
		
		if(nuevos_objetivos == true){

			objetivos_vector.clear();

			for(int i=0; i<sensores.num_destinos; i++){

				estado aux;

				aux.fila = sensores.destino[2 * i];
				aux.columna = sensores.destino[2 * i + 1];

				objetivos_vector.push_back(aux);
				objetivos.push_back(aux);

				cout << "Tamaño del vector: " << objetivos_vector.size() << endl;
				cout << "Añadimos el destino " << i << " f: " << objetivos_vector.at(i).fila << " c: " << objetivos_vector.at(i).columna << endl; 
			}

			nuevos_objetivos = false;
		}

	}
	
	if(sensores.terreno[0] == 'K'){
		tieneBikini = true;
		tieneDeportivas = false;
	}

	if(sensores.terreno[0] == 'D'){
		tieneBikini = false;
		tieneDeportivas = true;
	}

	if(sensores.nivel == 3){

		comprobarVestimenta(actual);
		if(sensores.reset == true){
			actual.bikini = false;
			actual.deportivas = false;
			actual.orientacion = 0;
		}

		PintarMapa(actual, sensores);

		if(plan.size() == 0 || (plan.size() > 0 and plan.front() == actFORWARD and ((sensores.superficie[2] != '_') || sensores.terreno[2] == 'P' || sensores.terreno[2] == 'M' || (sensores.terreno[2] == 'A' and tieneBikini == false) || (sensores.terreno[2] == 'B' and tieneDeportivas == false)) and (sensores.terreno[0] != 'A' || sensores.terreno[0] != 'B' ||  sensores.terreno[0] != 'K' || sensores.terreno[0] != 'D') )){
				hay_plan = false;
		}

		if(sensores.bateria < 500){
			fin_recarga = false;
			
		}

		if(casillaEncontrada == false){

			casillaEncontrada = descubiertoCasillaEspecial();

			if(casillaEncontrada == true){

				casillaEspecial.fila = fila_especial;
				casillaEspecial.columna = columna_especial;

				objetivo_casilla_especial.clear();
				objetivo_casilla_especial.push_back(casillaEspecial);

				cout << "Casilla especial en la posicion [" << casillaEspecial.fila << "][" << casillaEspecial.columna << "]." << endl;
			
			}
		}

		if(casillaEncontrada == true and fin_recarga == false ){
			
			cout << "Buscando casilla recarga" << endl;

			if(sensores.bateria >= 3000 or sensores.vida < 200){
				fin_recarga = true;
				hay_plan = false;
				plan.clear();
			}

			if(sensores.terreno[0] == 'X' and fin_recarga == false ){
				accion = actIDLE;
			}
			else{

				if(hay_plan == false){

					plan.clear();
					hay_plan = pathFinding_A_Estrella(actual, casillaEspecial, plan);
				}

				if (hay_plan == true and plan.size() > 0){
					accion = plan.front();
					plan.pop_front();
				}
			}
			

			return accion;
		}

		else {

			cout << "Buscando casilla aleatoria" << endl;

			while(hay_plan == false){
				
				bool encontrado = false;
				objetivos.clear();
				plan.clear();

				estado aux;

				for(; fila_busqueda<mapaResultado.size()-3 and !encontrado; fila_busqueda++){

					if(mapaResultado.size() - 3 <= columna_busqueda){
						columna_busqueda = 3;
					}

					for(; columna_busqueda<mapaResultado.size()-3 and !encontrado; columna_busqueda++){

						if(mapaResultado[fila_busqueda][columna_busqueda] == '?'){

							aux.fila = fila_busqueda;
							aux.columna = columna_busqueda;
							encontrado = true;
						}
					}

				}

				if(mapaResultado.size() - 3 <= fila_busqueda){
						fila_busqueda = 3;
				}

				if(!encontrado){
					
					fila_aux += 2;
					if(mapaResultado.size() - 3 <= fila_aux or fila_aux < 3){
						fila_aux = 3;
						columna_aux += 5;
					}
					if(mapaResultado.size() - 3 <= columna_aux or columna_aux < 3){
						columna_aux = 3;
					}

					aux.fila = fila_aux;
					aux.columna = columna_aux;
				}
				

				if(mapaResultado[aux.fila][aux.columna] != 'M' and mapaResultado[aux.fila][aux.columna] != 'P'){

					objetivos.push_back(aux);
					hay_plan = pathFinding(sensores.nivel, actual, objetivos, plan, sensores);

				}
				
			}
			
			if (hay_plan == true and plan.size() > 0){
				accion = plan.front();
				plan.pop_front();
			}

			return accion;


		}
		
	}
	
	else if (sensores.nivel == 4){
		
		
		if(sensores.bateria < 500){
			fin_recarga = false;
			
		}

		if(sensores.colision == true){
			fin_recarga = true;
			hay_plan = false;
		}

		if(casillaEncontrada == false){

			casillaEncontrada = descubiertoCasillaEspecial();

			if(casillaEncontrada == true){

				casillaEspecial.fila = fila_especial;
				casillaEspecial.columna = columna_especial;

				objetivo_casilla_especial.clear();
				objetivo_casilla_especial.push_back(casillaEspecial);

				cout << "Casilla especial en la posicion [" << casillaEspecial.fila << "][" << casillaEspecial.columna << "]." << endl;
			
			}
		}

		if(casillaEncontrada == true and fin_recarga == false ){
			
			cout << "Buscando casilla recarga" << endl;

			actual.fila = nivel_4_fila;
			actual.columna = nivel_4_columna;
			actual.orientacion = nivel_4_orientacion;
			
			if(sensores.bateria >= 3000 or sensores.vida < 200){
				fin_recarga = true;
				hay_plan = false;
				plan.clear();
			}

			if(sensores.terreno[0] == 'X' and fin_recarga == false and sensores.colision == false and mapaResultado[nivel_4_fila][nivel_4_columna] == 'X'){
				accion = actIDLE;
				ultimaAccion = accion;
				return accion;
			}
		}

		if(plan.size() == 0 || (plan.size() > 0 and plan.front() == actFORWARD and ((sensores.superficie[2] != '_') || sensores.terreno[2] == 'P' || sensores.terreno[2] == 'M' || (sensores.terreno[2] == 'A' and tieneBikini == false) || (sensores.terreno[2] == 'B' and tieneDeportivas == false)) and (sensores.terreno[0] != 'A' || sensores.terreno[0] != 'B' ||  sensores.terreno[0] != 'K' || sensores.terreno[0] != 'D') )){
				hay_plan = false;
				plan.clear();
		}
		
		if(plan.size() == 0){
			nuevos_objetivos = true;
			cout << "Creando nuevos objetivos" << endl;
		}

		if(plan.front() == actFORWARD and (sensores.superficie[2] != '_')){
			hay_plan = false;
			accion = actIDLE;
			ultimaAccion = accion;
			return accion;
		}

		if(ultimaAccion == actWHEREIS){

			actual.fila = sensores.posF;
			actual.columna = sensores.posC;
			actual.orientacion = sensores.sentido;

			nivel_4_columna = sensores.posC;
			nivel_4_fila = sensores.posF;
			nivel_4_orientacion = sensores.sentido;

			while(hay_plan == false){
				
				plan.clear();
				tres_objetivos.clear();

				cout << endl << "----------------------------" << endl;

				for(int i=0; i<3; i++){

					cout << "Añadimos el destino " << i << " f: " << objetivos_vector.at(i).fila << " c: " << objetivos_vector.at(i).columna << endl;
					tres_objetivos.push_front(objetivos_vector.at(i));
					i++;
				}
				
				cout << endl << "----------------------------" << endl;

				if(casillaEncontrada == true and fin_recarga == false){
					plan.clear();
					hay_plan = pathFinding_A_Estrella(actual, casillaEspecial, plan);
				}
				else {
					hay_plan = pathFinding_A_Estrella_4(actual, objetivos_vector, plan, sensores);
				}

			}
			
		}

		if (hay_plan == true and plan.size() > 0){

			modificarPosicionamiento(ultimaAccion);

			actual.fila = nivel_4_fila;
			actual.columna = nivel_4_columna;
			actual.orientacion = nivel_4_orientacion;

			accion = plan.front();
			plan.pop_front();

			PintarMapa(actual, sensores);
		}

		if(hay_plan == false and nuevos_objetivos){
			
			cout << "Hago whereis" << endl,
			accion = actWHEREIS;
		}

		ultimaAccion = accion;
		return accion;
	}
	else {

		// Capturo los destinos
		cout << "sensores.num_destinos : " << sensores.num_destinos << endl;
		objetivos.clear();

		for (int i = 0; i < sensores.num_destinos; i++)
		{
			estado aux;
			aux.fila = sensores.destino[2 * i];
			aux.columna = sensores.destino[2 * i + 1];
			objetivos.push_back(aux);
		}

		if(hay_plan == false){
			hay_plan = pathFinding(sensores.nivel, actual, objetivos, plan, sensores);
		}
		else if (hay_plan == true and plan.size() > 0){
			accion = plan.front();
			plan.pop_front();
		}

		return accion;
	
	}

	
}

// Llama al algoritmo de busqueda que se usara en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding(int level, const estado &origen, const list<estado> &destino, list<Action> &plan, Sensores sensores)
{
	estado un_objetivo_aux;
	switch (level){

		case 0:

			cout << "Demo\n";

			
			un_objetivo_aux = objetivos.front();
			cout << "fila: " << un_objetivo_aux.fila << " col:" << un_objetivo_aux.columna << endl;

			return pathFinding_Profundidad(origen, un_objetivo_aux, plan);

			break;

		case 1:

			cout << "Optimo numero de acciones\n";

			un_objetivo_aux = objetivos.front();
			cout << "fila: " << un_objetivo_aux.fila << " col:" << un_objetivo_aux.columna << endl;

			return pathFinding_Anchura(origen, un_objetivo_aux, plan);

			break;

		case 2:

			cout << "Optimo en coste\n";

			un_objetivo_aux = objetivos.front();
			cout << "fila: " << un_objetivo_aux.fila << " col:" << un_objetivo_aux.columna << endl;

			return pathFinding_A_Estrella(origen, un_objetivo_aux, plan);
			break;

		case 3:

			// Incluir aqui la llamada al algoritmo de busqueda para el Reto 1

			un_objetivo_aux = objetivos.front();

			cout << "fila: " << un_objetivo_aux.fila << " col:" << un_objetivo_aux.columna << endl;

			return pathFinding_A_Estrella(origen, un_objetivo_aux, plan);
			
			break;
		case 4:
		
			cout << "Reto 2: Maximizar objetivos\n";
			vector<estado> vector_aux;

			for(auto it=destino.begin(); it != destino.end(); ++it){

				vector_aux.push_back(*it);
				cout << "fila: " << (*it).fila << " col:" << (*it).columna << endl;
			}
			
			return pathFinding_A_Estrella_4(origen, vector_aux,plan, sensores);
			break;
	}

	return false;
}

//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el codigo en caracter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla)
{
	if (casilla == 'P' or casilla == 'M')
		return true;
	else
		return false;
}

// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st)
{
	int fil = st.fila, col = st.columna;

	// calculo cual es la casilla de delante del agente
	switch (st.orientacion)
	{
	case 0:
		fil--;
		break;
	case 1:
		fil--;
		col++;
		break;
	case 2:
		col++;
		break;
	case 3:
		fil++;
		col++;
		break;
	case 4:
		fil++;
		break;
	case 5:
		fil++;
		col--;
		break;
	case 6:
		col--;
		break;
	case 7:
		fil--;
		col--;
		break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil < 0 or fil >= mapaResultado.size())
		return true;
	if (col < 0 or col >= mapaResultado[0].size())
		return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col]))
	{
		// No hay obstaculo, actualizo el parametro st poniendo la casilla de delante.
		st.fila = fil;
		st.columna = col;
		return false;
	}
	else
	{
		return true;
	}
}

struct ComparaEstados
{
	bool operator()(const estado &a, const estado &n) const
	{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
			(a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion))
			return true;
		else
			return false;
	}
};

// Implementación de la busqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.

//------------------ Nivel 0 -------------------//

bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan)
{
	// Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado, ComparaEstados> Cerrados; // Lista de Cerrados
	stack<nodo> Abiertos;				  // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();

	Abiertos.push(current);

	while (!Abiertos.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha 90 grados
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 2) % 8;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			Abiertos.push(hijoTurnR);
		}

		// Generar descendiente de girar a la derecha 45 grados
		nodo hijoSEMITurnR = current;
		hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion + 1) % 8;
		if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end())
		{
			hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
			Abiertos.push(hijoSEMITurnR);
		}

		// Generar descendiente de girar a la izquierda 90 grados
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 6) % 8;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de girar a la izquierda 45 grados
		nodo hijoSEMITurnL = current;
		hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion + 7) % 8;
		if (Cerrados.find(hijoSEMITurnL.st) == Cerrados.end())
		{
			hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
			Abiertos.push(hijoSEMITurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (Cerrados.find(hijoForward.st) == Cerrados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				Abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty())
		{
			current = Abiertos.top();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

//------------------ Nivel 1 -------------------//

bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan)
{
	// Borro la lista
	cout << "Calculando plan\n";

	plan.clear();
	set<estado, ComparaEstados> Cerrados; // Lista de Cerrados
	queue<nodo> Abiertos;				  // Lista de Abiertos

	nodo current;
	current.st = origen;
	current.secuencia.empty();

	Abiertos.push(current);

	while (!Abiertos.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		Abiertos.pop();
		Cerrados.insert(current.st);

		// Generar descendiente de girar a la derecha 90 grados
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 2) % 8;
		if (Cerrados.find(hijoTurnR.st) == Cerrados.end())
		{
			hijoTurnR.secuencia.push_back(actTURN_R);
			Abiertos.push(hijoTurnR);
		}

		// Generar descendiente de girar a la derecha 45 grados
		nodo hijoSEMITurnR = current;
		hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion + 1) % 8;
		if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end())
		{
			hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
			Abiertos.push(hijoSEMITurnR);
		}

		// Generar descendiente de girar a la izquierda 90 grados
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 6) % 8;
		if (Cerrados.find(hijoTurnL.st) == Cerrados.end())
		{
			hijoTurnL.secuencia.push_back(actTURN_L);
			Abiertos.push(hijoTurnL);
		}

		// Generar descendiente de girar a la izquierda 45 grados
		nodo hijoSEMITurnL = current;
		hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion + 7) % 8;
		if (Cerrados.find(hijoSEMITurnL.st) == Cerrados.end())
		{
			hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
			Abiertos.push(hijoSEMITurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st))
		{
			if (Cerrados.find(hijoForward.st) == Cerrados.end())
			{
				hijoForward.secuencia.push_back(actFORWARD);
				Abiertos.push(hijoForward);
				if(hijoForward.st.fila == destino.fila && hijoForward.st.columna == destino.columna){
					current=hijoForward;
					break;
				}
			}
		}

		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty())
		{
			current = Abiertos.front();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

//------------------ Nivel 2 -------------------//

struct ComparaEstadosNivel2{

	bool operator()(const estado &a, const estado &n) const{

		if ((a.fila > n.fila) || (a.fila == n.fila and a.columna > n.columna) || (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion) || 
		(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini > n.bikini) || 
		(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.deportivas > n.deportivas ))
			return true;
		else
			return false;
	}

};

void ComportamientoJugador::comprobarVestimenta(estado & estado){
	
	if(mapaResultado[estado.fila][estado.columna] == 'K' and estado.bikini == false){

		// Como solo se puede coger uno, tendriamos que dejar las zapatillas
		estado.bikini = true;
		estado.deportivas = false;
	}
	else if(mapaResultado[estado.fila][estado.columna] == 'D' and estado.deportivas == false){

		// Como solo se puede coger uno, tendriamos que dejar las zapatillas
		estado.bikini = false;
		estado.deportivas = true;
	}
}

int ComportamientoJugador::costeCasilla(nodo & nodo1, const Action & accion){

	int coste = 0;

	if(accion == actIDLE){
		
		return 0;
	}
	else{

		switch (mapaResultado[nodo1.st.fila][nodo1.st.columna])
		{

		case 'A':
			
			if(nodo1.st.bikini == true){
				
				if(accion == actTURN_L || accion == actSEMITURN_L || accion == actSEMITURN_R || accion == actTURN_R){
					coste = 5;
				}
				else{
					coste = 10;
				}
				
			}
			else {

				if(accion == actTURN_L || accion == actSEMITURN_L || accion == actSEMITURN_R || accion == actTURN_R){

					coste = 500;
				}
				else{

					coste = 200;
				}
			}


			break;

		case 'B':
			
			if(nodo1.st.deportivas == true){
				
				if(accion == actTURN_L || accion == actSEMITURN_L || accion == actSEMITURN_R || accion == actTURN_R){
					coste = 1;
				}
				else{
					coste = 15;
				}
				
			}
			else {

				if(accion == actTURN_L || accion == actSEMITURN_L || accion == actSEMITURN_R || accion == actTURN_R){

					coste = 3;
				}
				else{

					coste = 100;
				}
			}

			break;
		
		case 'T':

			coste = 2;

			break;

		default:

			coste = 1;

			break;
		}

		return coste;
	}
}

int ComportamientoJugador::Chebychev(nodo & nodo1, const estado & objetivo){

	int diferencia_filas = abs(objetivo.fila - nodo1.st.fila);
	int diferencia_columnas = abs(objetivo.columna - nodo1.st.columna);

	int distancia_chebychev = max(diferencia_columnas, diferencia_filas);

	return distancia_chebychev;
}

struct compararValorF{

	bool operator()(const nodo & nodo1, const nodo & nodo2) const {
		return nodo1.st.valor_F > nodo2.st.valor_F;
	}
};

bool ComportamientoJugador::pathFinding_A_Estrella(const estado &origen, const estado &destino, list<Action> &plan)
{
	// Borro la lista
	cout << "Calculando plan\n";
	cout << "Destino f: " << destino.fila << " c: " << destino.columna;
	cout << "Origen f: " << origen.fila << " c: " << origen.columna;
	plan.clear();
	set<estado, ComparaEstadosNivel2> Cerrados; // Lista de Cerrados
	priority_queue<nodo, vector<nodo>, compararValorF> Abiertos;	// Lista de Abiertos

	nodo current;
	current.st = origen;

	current.secuencia.empty();
	current.st.bikini = false;
	current.st.deportivas = false;

	current.st.valor_G = costeCasilla(current, actIDLE);
	current.st.valor_F = current.st.valor_G + Chebychev(current, destino);

	Abiertos.push(current);

	while (!Abiertos.empty() and (current.st.fila != destino.fila or current.st.columna != destino.columna))
	{

		// Elegimos el nodo de abiertos
		Abiertos.pop();

		if(Cerrados.find(current.st) == Cerrados.end()){

			Cerrados.insert(current.st);
			comprobarVestimenta(current.st);

			// Generar descendiente de girar a la derecha 90 grados
			nodo hijoTurnR = current;
			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 2) % 8;

			hijoTurnR.st.valor_G += costeCasilla(hijoTurnR, actTURN_R);
			hijoTurnR.st.valor_F = hijoTurnR.st.valor_G + Chebychev(hijoTurnR, destino);

			if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
				hijoTurnR.secuencia.push_back(actTURN_R);
				Abiertos.push(hijoTurnR);
			}

			// Generar descendiente de girar a la derecha 45 grados
			nodo hijoSEMITurnR = current;
			hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion + 1) % 8;

			hijoSEMITurnR.st.valor_G += costeCasilla(hijoSEMITurnR, actSEMITURN_R);
			hijoSEMITurnR.st.valor_F = hijoSEMITurnR.st.valor_G + Chebychev(hijoSEMITurnR, destino);

			if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end())
			{
				hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
				Abiertos.push(hijoSEMITurnR);
			}

			// Generar descendiente de girar a la izquierda 90 grados
			nodo hijoTurnL = current;
			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 6) % 8;
			
			hijoTurnL.st.valor_G += costeCasilla(hijoTurnL, actTURN_L);
			hijoTurnL.st.valor_F = hijoTurnL.st.valor_G + Chebychev(hijoTurnL, destino);

			if (Cerrados.find(hijoTurnL.st) == Cerrados.end())
			{
				hijoTurnL.secuencia.push_back(actTURN_L);
				Abiertos.push(hijoTurnL);
			}

			// Generar descendiente de girar a la izquierda 45 grados
			nodo hijoSEMITurnL = current;
			hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion + 7) % 8;
			
			hijoSEMITurnL.st.valor_G += costeCasilla(hijoSEMITurnL, actSEMITURN_L);
			hijoSEMITurnL.st.valor_F = hijoSEMITurnL.st.valor_G + Chebychev(hijoSEMITurnL, destino);

			if (Cerrados.find(hijoSEMITurnL.st) == Cerrados.end())
			{
				hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
				Abiertos.push(hijoSEMITurnL);
			}

			// Generar descendiente de avanzar
			nodo hijoForward = current;
			hijoForward.st.valor_G += costeCasilla(hijoForward, actFORWARD);
			hijoForward.st.valor_F = hijoForward.st.valor_G + Chebychev(hijoForward, destino);

			if (!HayObstaculoDelante(hijoForward.st))
			{			

				if (Cerrados.find(hijoForward.st) == Cerrados.end())
				{
					hijoForward.secuencia.push_back(actFORWARD);
					Abiertos.push(hijoForward);
				}
			}

		}
		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty())
		{
			current = Abiertos.top();
			
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}

//------------------ Nivel 4 -------------------//

struct ComparaEstadosNivel4{

	bool operator()(const estado &a, const estado &n) const{

		if ((a.fila > n.fila) || (a.fila == n.fila and a.columna > n.columna) || (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion) || (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and
		a.bikini > n.bikini) || (a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.deportivas > n.deportivas ) || 
		(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.deportivas == n.deportivas and a.objetivos.at(0) > n.objetivos.at(0)) || 
		(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.deportivas == n.deportivas and a.objetivos.at(0) == n.objetivos.at(0) and a.objetivos.at(1) > n.objetivos.at(1)) || 
		(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.deportivas == n.deportivas and a.objetivos.at(0) == n.objetivos.at(0) and a.objetivos.at(1) == n.objetivos.at(1) and a.objetivos.at(2) > n.objetivos.at(2)))
			return true;
		else
			return false;
	}

};

void ComportamientoJugador::esObjetivo(estado & estado_nodo){

	bool esObjetivo = false;
	int i = 0;
	
	estado objetivo;
	
	for(auto it=objetivos_vector.begin(); it != objetivos_vector.end() && esObjetivo == false; ++it){

		objetivo = *it;
		if(estado_nodo.fila == objetivo.fila and estado_nodo.columna == objetivo.columna){
			esObjetivo = true;
			estado_nodo.objetivos[i] = true;
		}
		++i;
	}
}

int ComportamientoJugador::ChebychevMultipleObjetivos(nodo & nodo1, const vector<estado> &objetivos, const vector<bool> & objetivos_visitados){

	int aux = 1000000;

	auto it = objetivos.begin();

	for(int i=0; i<3; i++){

		if(objetivos_visitados.at(i) && aux > Chebychev(nodo1, *it)){
			aux = Chebychev(nodo1, *it);
		}
		it++;
	}
	
	return aux;
}

bool EsObstaculo4(unsigned char casilla, Sensores sensores)
{
	if (casilla == 'P' or casilla == 'M' or sensores.superficie[2] != '_')
		return true;
	else
		return false;
}

bool ComportamientoJugador::HayObstaculoDelante4(estado &st, Sensores sensores)
{
	int fil = st.fila, col = st.columna;

	// calculo cual es la casilla de delante del agente
	switch (st.orientacion)
	{
	case 0:
		fil--;
		break;
	case 1:
		fil--;
		col++;
		break;
	case 2:
		col++;
		break;
	case 3:
		fil++;
		col++;
		break;
	case 4:
		fil++;
		break;
	case 5:
		fil++;
		col--;
		break;
	case 6:
		col--;
		break;
	case 7:
		fil--;
		col--;
		break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil < 0 or fil >= mapaResultado.size())
		return true;
	if (col < 0 or col >= mapaResultado[0].size())
		return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo4(mapaResultado[fil][col], sensores))
	{
		// No hay obstaculo, actualizo el parametro st poniendo la casilla de delante.
		st.fila = fil;
		st.columna = col;
		return false;
	}
	else
	{
		return true;
	}
}

bool ComportamientoJugador::pathFinding_A_Estrella_4(const estado &origen, const vector<estado> &destino, list<Action> &plan, Sensores sensores)
{
	// Borro la lista
	cout << "Calculando plan\n";

	auto aux = destino.begin(); 

	for(int i=0; i<destino.size(); i++){

		cout << "Destino " << i << " f: " << destino[i].fila << " c: " << destino[i].columna << endl;
	}

	plan.clear();
	set<estado, ComparaEstadosNivel4> Cerrados; // Lista de Cerrados
	priority_queue<nodo, vector<nodo>, compararValorF> Abiertos;	// Lista de Abiertos

	nodo current;
	current.st = origen;

	current.secuencia.empty();
	current.st.bikini = false;
	current.st.deportivas = false;
	current.st.objetivos = {false, false, false};

	esObjetivo(current.st);

	current.st.valor_G = costeCasilla(current, actIDLE);
	current.st.valor_F = current.st.valor_G + ChebychevMultipleObjetivos(current, destino, current.st.objetivos);

	Abiertos.push(current);

	while (!Abiertos.empty() and current.st.finObjetivos() == false)
	{

		// Elegimos el nodo de abiertos
		Abiertos.pop();

		if(Cerrados.find(current.st) == Cerrados.end()){

			Cerrados.insert(current.st);
			comprobarVestimenta(current.st);

			// Generar descendiente de girar a la derecha 90 grados
			nodo hijoTurnR = current;
			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion + 2) % 8;

			hijoTurnR.st.valor_G += costeCasilla(hijoTurnR, actTURN_R);
			hijoTurnR.st.valor_F = hijoTurnR.st.valor_G + ChebychevMultipleObjetivos(hijoTurnR, destino, hijoTurnR.st.objetivos);

			if (Cerrados.find(hijoTurnR.st) == Cerrados.end()){
				hijoTurnR.secuencia.push_back(actTURN_R);
				Abiertos.push(hijoTurnR);
			}

			// Generar descendiente de girar a la derecha 45 grados
			nodo hijoSEMITurnR = current;
			hijoSEMITurnR.st.orientacion = (hijoSEMITurnR.st.orientacion + 1) % 8;

			hijoSEMITurnR.st.valor_G += costeCasilla(hijoSEMITurnR, actSEMITURN_R);
			hijoSEMITurnR.st.valor_F = hijoSEMITurnR.st.valor_G + ChebychevMultipleObjetivos(hijoSEMITurnR, destino, hijoSEMITurnR.st.objetivos);

			if (Cerrados.find(hijoSEMITurnR.st) == Cerrados.end())
			{
				hijoSEMITurnR.secuencia.push_back(actSEMITURN_R);
				Abiertos.push(hijoSEMITurnR);
			}

			// Generar descendiente de girar a la izquierda 90 grados
			nodo hijoTurnL = current;
			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion + 6) % 8;
			
			hijoTurnL.st.valor_G += costeCasilla(hijoTurnL, actTURN_L);
			hijoTurnL.st.valor_F = hijoTurnL.st.valor_G + ChebychevMultipleObjetivos(hijoTurnL, destino, hijoTurnL.st.objetivos);

			if (Cerrados.find(hijoTurnL.st) == Cerrados.end())
			{
				hijoTurnL.secuencia.push_back(actTURN_L);
				Abiertos.push(hijoTurnL);
			}

			// Generar descendiente de girar a la izquierda 45 grados
			nodo hijoSEMITurnL = current;
			hijoSEMITurnL.st.orientacion = (hijoSEMITurnL.st.orientacion + 7) % 8;
			
			hijoSEMITurnL.st.valor_G += costeCasilla(hijoSEMITurnL, actSEMITURN_L);
			hijoSEMITurnL.st.valor_F = hijoSEMITurnL.st.valor_G +  ChebychevMultipleObjetivos(hijoSEMITurnL, destino, hijoSEMITurnL.st.objetivos);

			if (Cerrados.find(hijoSEMITurnL.st) == Cerrados.end())
			{
				hijoSEMITurnL.secuencia.push_back(actSEMITURN_L);
				Abiertos.push(hijoSEMITurnL);
			}

			// Generar descendiente de avanzar
			nodo hijoForward = current;
			hijoForward.st.valor_G += costeCasilla(hijoForward, actFORWARD);
			hijoForward.st.valor_F = hijoForward.st.valor_G + ChebychevMultipleObjetivos(hijoForward, destino, hijoForward.st.objetivos);

			if (!HayObstaculoDelante4(hijoForward.st, sensores))
			{			

				if (Cerrados.find(hijoForward.st) == Cerrados.end())
				{
					hijoForward.secuencia.push_back(actFORWARD);
					Abiertos.push(hijoForward);
				}
			}

		}
		// Tomo el siguiente valor de la Abiertos
		if (!Abiertos.empty())
		{
			current = Abiertos.top();
			
		}

		esObjetivo(current.st);
	}

	cout << "Terminada la busqueda\n";

	if (current.st.finObjetivos() == true)
	{
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else
	{
		cout << "No encontrado plan\n";
	}

	return false;
}


// Sacar por la consola la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan)
{
	auto it = plan.begin();
	while (it != plan.end())
	{
		if (*it == actFORWARD)
		{
			cout << "A ";
		}
		else if (*it == actTURN_R)
		{
			cout << "D ";
		}
		else if (*it == actSEMITURN_R)
		{
			cout << "d ";
		}
		else if (*it == actTURN_L)
		{
			cout << "I ";
		}
		else if (*it == actSEMITURN_L)
		{
			cout << "i ";
		}
		else
		{
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}

// Funcion auxiliar para poner a 0 todas las casillas de una matriz
void AnularMatriz(vector<vector<unsigned char>> &m)
{
	for (int i = 0; i < m[0].size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			m[i][j] = 0;
		}
	}
}

// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan)
{
	AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it != plan.end())
	{
		if (*it == actFORWARD)
		{
			switch (cst.orientacion)
			{
			case 0:
				cst.fila--;
				break;
			case 1:
				cst.fila--;
				cst.columna++;
				break;
			case 2:
				cst.columna++;
				break;
			case 3:
				cst.fila++;
				cst.columna++;
				break;
			case 4:
				cst.fila++;
				break;
			case 5:
				cst.fila++;
				cst.columna--;
				break;
			case 6:
				cst.columna--;
				break;
			case 7:
				cst.fila--;
				cst.columna--;
				break;
			}
			mapaConPlan[cst.fila][cst.columna] = 1;
		}
		else if (*it == actTURN_R)
		{
			cst.orientacion = (cst.orientacion + 2) % 8;
		}
		else if (*it == actSEMITURN_R)
		{
			cst.orientacion = (cst.orientacion + 1) % 8;
		}
		else if (*it == actTURN_L)
		{
			cst.orientacion = (cst.orientacion + 6) % 8;
		}
		else if (*it == actSEMITURN_L)
		{
			cst.orientacion = (cst.orientacion + 7) % 8;
		}
		it++;
	}
}

int ComportamientoJugador::interact(Action accion, int valor)
{
	return false;
}