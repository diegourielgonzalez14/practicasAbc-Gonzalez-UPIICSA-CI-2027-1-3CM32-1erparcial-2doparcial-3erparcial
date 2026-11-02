
#include <iostream>
using namespace std;

const int MAX = 100;

// Funcion para ingresar los numeros
void ingresarDatos(int datos[], int n) {
    cout << "Ingresa " << n << " numeros enteros:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }
}

// Funcion para inicializar los indices
void inicializarIndices(int indices[], int n) {
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }
}

// Ordenamiento burbuja indirecto
void ordenarIndirecto(int datos[], int indices[], int n) {
    int auxiliar;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {

            if (datos[indices[j]] > datos[indices[j + 1]]) {
                auxiliar = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = auxiliar;
            }
        }
    }
}

// Funcion para mostrar los datos originales
void mostrarOriginales(int datos[], int n) {
    for (int i = 0; i < n; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

// Mostrar los datos utilizando los indices ordenados
void mostrarOrdenados(int datos[], int indices[], int n) {
    for (int i = 0; i < n; i++) {
        cout << datos[indices[i]] << " ";
    }
    cout << endl;
}

int main() {
    int datos[MAX];
    int indices[MAX];
    int n;

    cout << "ORDENAMIENTO INDIRECTO POR BURBUJA" << endl;
    cout << "Cuantos numeros deseas ordenar? ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Cantidad no valida." << endl;
        return 1;
    }

    ingresarDatos(datos, n);
    inicializarIndices(indices, n);

    cout << "\nDatos originales: ";
    mostrarOriginales(datos, n);

    ordenarIndirecto(datos, indices, n);

    cout << "Datos ordenados indirectamente: ";
    mostrarOrdenados(datos, indices, n);

    cout << "\nIndices ordenados: ";
    for (int i = 0; i < n; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}

