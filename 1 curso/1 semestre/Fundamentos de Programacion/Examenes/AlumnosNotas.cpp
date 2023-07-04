#include <iostream>
#include <string>

using namespace std;

int main() {

    const int MAX_ALUMNOS = 50;
    const int MAX_NOTAS = 50;

    double registro[MAX_ALUMNOS][MAX_NOTAS];

    int identidad;
    double nota;

    int alumnos = 0;
    int notas = 0;

    cout << "REGISTRO DE NOTAS" << endl << endl;

    cout << "Numero Identificativo: ";
    cin >> identidad;

    while (identidad != 0 && alumnos < MAX_ALUMNOS) {

        registro[alumnos][0] = identidad;

        cout << "Notas (separadas por espacios): ";
        cin >> nota;

        notas++;

        // Entrada de las notas. Se almacenan a partir de la columna [1]

        while (nota != -1 && notas < MAX_NOTAS - 1) {

            registro[alumnos][notas] = nota;

            cin >> nota;

            notas++;
        }

        // Almaceno en la ultima posicion el -1 para determinar el final

        if (nota == -1)
            registro[alumnos][notas] = nota;

        alumnos++;
        notas = 0;

        cout << "Numero Identificativo: ";
        cin >> identidad;

    }

    // Mayor media

    double mayor_media = 0;
    int alumno_mayor_media;

    for (int i = 0; i < alumnos; i++){

        double media = 0;
        int num_notas = 0;

        for (int u = 1; registro[i][u] != -1; u++) {

            media += registro[i][u];
            num_notas++;
        }

        media /= num_notas;

        if (media > mayor_media) {
            mayor_media = media;
            alumno_mayor_media = registro[i][0];
        }
    }

    cout << "El alumno con mayor media es: "
          << alumno_mayor_media
          << " (" << mayor_media << ")"
          << endl;

    return 0;
}
