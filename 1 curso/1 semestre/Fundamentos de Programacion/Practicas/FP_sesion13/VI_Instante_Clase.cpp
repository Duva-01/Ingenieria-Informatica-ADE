/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
//
// DAVID MARTINEZ DIAZ
//
/*  
	Sobre la clase SecuenciaEnteros, defina lo que sea necesario para calcular 
	el número de secuencias ascendientes del vector.
	Por ejemplo, en el vector {2,4,1,1,7,2,1} encontramos 4 secuencias 
	ascencentes, que son: {2,4}, {1,1,7}, {2}, {1}.
	
	
		
		Entrada: - Secuenciasclass Instante {
	
	private:
		
		int horas;
		int minutos;
		int segundos;
	
	public:
		
	
	
/***************************************************************************/
 	
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// La clase "Instante" representa un instante de tiempo dentro de un día. 

const int SEGS_MIN  = 60;   // Segundos en un minuto
const int MINS_HORA = 60;	// Minutos en una hora
const int HORAS_DIA = 24;	// Horas en un dia				
const int SEGS_HORA = MINS_HORA * SEGS_MIN; // Segundos en una hora
const int SEGS_DIA  = SEGS_HORA * HORAS_DIA; // Segundos en un dia

	
class Instante
{

private:

	// PRE: 0 <= hora < 24
	int hora;	
	
	// PRE: 0 <= minuto < 60
	int minuto;	

	// PRE: 0 <= segundo < 60
	int segundo;	

public:
	
	/***********************************************************************/
	// Constructor con argumentos: la hora, el minuto y el segundo
	// PRE: 0 <= la_hora < 24
	// PRE: 0 <= el_minuto < 60
	// PRE: 0 <= el_segundo < 60	
	
	Instante (int la_hora, int el_minuto, int el_segundo) 
	{
		hora = la_hora;
		minuto = el_minuto;
		segundo = el_segundo;
		
	}

	/***********************************************************************/
	// Constructor con un argumento: el número de segundos (desde las 0:0:0)
	// PRE: 0 <= segundos < SEGS_DIA
	
	Instante (int num_segundos) 
	{	
		segundo = num_segundos%SEGS_MIN;
		
		int minutos_tmp = num_segundos/SEGS_MIN;
		
		hora = minutos_tmp/MINS_HORA;
		minuto = minutos_tmp%MINS_HORA;
	}

	/***********************************************************************/
	// Devuelve la hora registrada
	int GetHora ()
	{
		return (hora);
	}

	/***********************************************************************/
	// Devuelve los minutos registrados
	int GetMinuto ()
	{
		return (minuto);
	}

	/***********************************************************************/
	// Devuelve los segundos registrados
	int GetSegundo ()
	{
		return (segundo);
	}

	/***********************************************************************/
	// Devuelve las horas que hay en el instante
	double CuantasHorasHay ()
	{
		return (hora + ((1.0*minuto)/MINS_HORA) + ((1.0*segundo)/SEGS_HORA));
	}

	/***********************************************************************/
	// Devuelve los minutos que hay en el instante
	double  CuantosMinutosHay ()
	{
		return (((1.0*hora)*MINS_HORA) + minuto + ((1.0*segundo)/SEGS_MIN));
	}

	/***********************************************************************/
	// Devuelve los segundos que hay en el instante
	double  CuantosSegundosHay ()
	{
		return (((1.0*hora)*SEGS_HORA) + ((1.0*minuto)*SEGS_MIN) + segundo);
	}
	
	/***********************************************************************/
	// Calcula los segundos transcurridos desde el instante (0,0,0)
	int SegundosTranscurridos ()
	{
		return ((hora*SEGS_HORA)+(minuto*SEGS_MIN)+segundo);
	}
	

	/***********************************************************************/
	// Calcula los minutos transcurridos desde el instante (0,0,0)
	int MinutosTranscurridos ()
	{		
		return (SegundosTranscurridos()/SEGS_MIN);
	}
	
	/***********************************************************************/
	// Construye un string con la representación textual de un "Instante"
	string ToString ()
	{
		return ("(" + to_string(hora) + " h: " + to_string(minuto) 
		            + " m : " +  to_string(segundo) + " s)");
	}
	
	/***********************************************************************/
	
	bool EsAnterior (Instante otro) {
		
		bool es_anterior = false;
		int segundos = CuantosSegundosHay();
		
		if ( segundos < otro.CuantosSegundosHay()) {
			es_anterior = true;
		}
		
		return es_anterior;
	}
	
	Instante Avanza (Instante otro)	{
		
		hora = hora + otro.hora;
		minuto = minuto + otro.minuto;
		segundo = segundo + otro.segundo;
		
		while (segundo >= 60) {segundo = segundo - 60; minuto ++;}
		while (minuto >= 60) {minuto = minuto - 60; hora ++;}
		
		return (hora, minuto, segundo);
	}
	
	Instante Retrocede (Instante otro)	{
		
		int rest_hora = 0, rest_minuto = 0;
		
		if (minuto - otro.minuto < 0) {rest_hora = 1;}
		if (segundo - otro.segundo < 0){rest_minuto = 1;}
		
		hora = abs (hora - otro.hora);
		minuto = abs (minuto - otro.minuto);
		segundo = abs (segundo - otro.segundo);
		
		hora = hora - rest_hora;
		minuto = minuto - rest_minuto;
		
		while (segundo >= 60) {segundo = segundo - 60; minuto ++;}
		while (minuto >= 60) {minuto = minuto - 60; hora ++;}
		
		return (hora, minuto, segundo);
	}
	
	Instante Salto (int n_segundos)	{
		
		segundo = segundo + n_segundos;
		
		while (segundo >= 60) {segundo = segundo - 60; minuto ++;}
		while (minuto >= 60) {minuto = minuto - 60; hora ++;}
		
		
		return (hora, minuto, segundo);
	}
	
	Instante Diferencia (Instante otro)	{
		
		int sec_1 = CuantosSegundosHay();
		int sec_2 = otro.CuantosSegundosHay();
		
		segundo = 0;
		minuto = 0;
		hora = 0;
		
		
		segundo = abs (sec_1 - sec_2);
		
		while (segundo >= 60) {segundo = segundo - 60; minuto ++;}
		while (minuto >= 60) {minuto = minuto - 60; hora ++;}
	
		return (hora, minuto, segundo);
	}
	
};

/////////////////////////////////////////////////////////////////////////////

string EliminaUltimosSeparadores (string cadena)
{
   	while (cadena.length()>0 && isspace(cadena.back()))
		cadena.pop_back();
        
	return (cadena);
}



string EliminaPrimerosSeparadores (string cadena)
{	
	// Buscar el primer carácter no espacio
	int pos = 0;
	while (pos <cadena.length() && isspace(cadena.at(pos))) pos++;

	string local; 
	
	// Copiar todos los que quedan
	while (pos <cadena.length()) {
		local.push_back(cadena.at(pos));
		pos++;
	}
		
	return (local);
}



string EliminaSeparadoresInicialesyFinales (string cadena)
{	
	return (EliminaUltimosSeparadores(EliminaPrimerosSeparadores(cadena))); 
}


bool EsEntero (string cadena) 
{
	bool es_entero = true;

	cadena = EliminaSeparadoresInicialesyFinales (cadena);

	int long_cadena = cadena.length();
			
	if (long_cadena == 0) es_entero = false;
	else {	
	
		// Si el primer carácter es '+' ó '-', perfecto. En ese caso 
		// se pasa al siguiente carácter (posición 1).
		 		
		int pos;
		if (cadena.at(0)=='-'|| cadena.at(0) == '+') pos=1;
		else pos=0;
		
		// Todos los caracteres desde la posición "pos" deben ser dígitos
		
		while ((pos < long_cadena) && es_entero) {
			if (!isdigit(cadena.at(pos))) es_entero = false;
			else pos++;
		}	
	}
	
	return (es_entero);
}



int LeeEntero (string titulo)
{
	string cadena;

	do {
		cout << titulo;
		getline (cin, cadena);
						
	} while (!EsEntero(cadena));
			
	int numero = stoi(cadena);
 	
	return (numero);	
}



int LeeEnteroEnRango (string titulo, int menor, int mayor)
{
	int numero;

	do {
		numero = LeeEntero (titulo);		
	} while ((numero<menor) || (numero>mayor));
	
	return numero;
}

/***************************************************************************/
/***************************************************************************/




int main()
{
	cout.setf (ios::showpoint);
	cout.setf (ios::fixed);	

	// Leer dos instantes
		
	int hora, minuto, segundo;
	
	cout << "Introduzca hora inicial" << endl;
	hora    = LeeEnteroEnRango ("Hora: ", 0, 23);
	minuto  = LeeEnteroEnRango ("Minuto: ", 0, 59);
	segundo = LeeEnteroEnRango ("Segundo: ", 0, 59);
	
	Instante instante_inicial (hora, minuto, segundo);
         	
	cout << endl;   	
	cout << "Introduzca hora final" << endl;
	hora    = LeeEnteroEnRango ("Hora: ", 0, 23);
	minuto  = LeeEnteroEnRango ("Minuto: ", 0, 59);
	segundo = LeeEnteroEnRango ("Segundo: ", 0, 59);
	
	Instante instante_final (hora, minuto, segundo);
       
       
    // Mostrar instantes 
    
	cout << endl;    
	cout << "----------------------------------------------";
    cout << endl; 
    cout << "Instante inicial = " << instante_inicial.ToString() << endl; 
    cout << "Instante final   = " << instante_final.ToString() << endl;
    cout << endl;
	cout << "----------------------------------------------";
    cout << endl;	
    
	
	// Cálculos sobre innstantes
	
	//----------------------------------------------------------------//
	
	cout << endl;    
	cout << "----------------------------------------------";
    cout << endl;
    
	cout << endl;
	cout << "- Metodo 'Es Anterior booleano:'";
	cout << endl << endl;;
	
	if (instante_inicial.EsAnterior(instante_final) == 1) {cout << "--> Verdadero";}
	else {cout << "--> Falso";}
	
	int opcion;
	
	cout << endl << endl;
	cout << "Elija una opcion:" << endl << endl;
	cout << "1.- Metodo 'Avanza Instante': ";
	cout << endl;
	cout << "2.- Metodo 'Retrocede Instante': ";
	cout << endl;
	cout << "3.- Metodo 'Salto'";
	cout << endl ;
	cout << "4.- Metodo 'Diferencia'";
	cout << endl ;
	
	do {
		
		cout << endl << "--> "; cin >> opcion;
	}while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
	
	
	if (opcion == 1) {
	
	instante_inicial.Avanza(instante_final);
	
	cout << endl;
	cout << "--> Instante resultante = " << instante_inicial.ToString() << endl;
	cout << endl;
	
	}
	
	if (opcion == 2) {
		
	instante_inicial.Retrocede(instante_final);
	
	cout << endl;
	cout << "--> Instante resultante = " << instante_inicial.ToString() << endl; 
	cout << endl;
	
	}
	
	
	if (opcion == 3) {
	
	int n_segs;
	
	cout << "Introduzca el numero de segundos a saltar: "; 
	cin >> n_segs;
	
	instante_inicial.Salto(n_segs);
	
	cout << endl;
	cout << "--> Instante resultante = " << instante_inicial.ToString() << endl; 
	cout << endl;
	
	}
	
	if (opcion == 4) {
		
	instante_inicial.Diferencia(instante_final);
	
	cout << endl;
	cout << "--> Instante resultante = " << instante_inicial.ToString() << endl; 
	cout << endl;
	
	}
	
	return (0);
}
