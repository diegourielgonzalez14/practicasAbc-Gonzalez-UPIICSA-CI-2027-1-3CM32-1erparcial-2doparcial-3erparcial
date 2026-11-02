
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Cuantos numeros deseas ingresar? ";
    cin >> n;

    if (n <= 0) {
        cout << "Debes ingresar una cantidad mayor que cero." << endl;
        return 1;
    }

    double numeros[n];
    double *ptr = numeros;

    // Ingresar numeros usando el puntero
    cout << "\nIngresa los numeros:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    // Inicializar variables
    double suma = 0;
    double maximo = *ptr;
    double minimo = *ptr;

    // Operaciones usando el puntero
    for (int i = 0; i < n; i++) {
        suma += *(ptr + i);

        if (*(ptr + i) > maximo) {
            maximo = *(ptr + i);
        }

        if (*(ptr + i) < minimo) {
            minimo = *(ptr + i);
        }
    }

    double promedio = suma / n;

    // Ordenar los numeros para calcular la mediana
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                double aux = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = aux;
            }
        }
    }

    double mediana;

    if (n % 2 == 0) {
        mediana = (*(ptr + n / 2 - 1) +
                   *(ptr + n / 2)) / 2.0;
    } else {
        mediana = *(ptr + n / 2);
    }

    // Mostrar resultados
    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    return 0;
}

