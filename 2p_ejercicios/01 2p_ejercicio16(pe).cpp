
#include <iostream>
using namespace std;

// Funcion para mostrar los numeros
void mostrarNumeros(int numeros[], int n) {
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
}

// Funcion para ordenar usando el metodo burbuja
void ordenarBurbuja(int numeros[], int n) {
    int auxiliar;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {

            if (numeros[j] > numeros[j + 1]) {
                auxiliar = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = auxiliar;
            }

        }
    }
}

int main() {
    int numeros[100];
    int n;

    cout << "ORDENAMIENTO BURBUJA - C++" << endl;
    cout << "Cuantos numeros deseas ordenar? ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Cantidad no valida. Ingresa entre 1 y 100."
             << endl;
        return 1;
    }

    cout << "Ingresa los " << n << " numeros enteros:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    cout << "\nNumeros originales: ";
    mostrarNumeros(numeros, n);

    ordenarBurbuja(numeros, n);

    cout << "Numeros ordenados: ";
    mostrarNumeros(numeros, n);

    return 0;
}

