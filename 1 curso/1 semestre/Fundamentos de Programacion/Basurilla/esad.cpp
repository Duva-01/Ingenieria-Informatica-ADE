#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

   
    int entrada, num_digitos, entero, aux;
    string entrada_string, resultado;

    bool entero_ok;

  
    cout << "Introduzca un entero de 3 digitos: ";
    cin >> entrada;

   
    entero_ok = (entrada > 0);

    if (entero_ok) {

        entero = entrada;

        // Almaceno el numero de digitos del entero
        entrada_string = to_string(entrada); 
        num_digitos = entrada_string.length();

        if (num_digitos > 1) {

            do {
                aux = entero / pow(10, num_digitos - 1);
                resultado += '|' + to_string(aux);
                entero -= aux * pow(10, num_digitos - 1) ;

                num_digitos--;

            } while (num_digitos > 0);

            resultado += '|';

        } else {
            resultado = '|' + entrada_string + '|';
        }

        cout << resultado;

    } else 
        cout << "El entero no es positivo";



    return 0;
}
