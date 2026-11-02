#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// Nuevo tipo de dato
struct Persona {
    string nombre;
    int edad;
};

// Inicializa el arreglo de indices
void inicializarIndices(int indices[], int n) {
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }
}

// Quick Sort indirecto para enteros
void quickSortEnteros(int datos[], int indices[],
                      int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = datos[indices[(inicio + fin) / 2]];

    while (i <= j) {
        while (datos[indices[i]] < pivote) i++;
        while (datos[indices[j]] > pivote) j--;

        if (i <= j) {
            int aux = indices[i];
            indices[i] = indices[j];
            indices[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j)
        quickSortEnteros(datos, indices, inicio, j);

    if (i < fin)
        quickSortEnteros(datos, indices, i, fin);
}

// Quick Sort indirecto para caracteres
void quickSortCaracteres(char datos[], int indices[],
                         int inicio, int fin) {
    int i = inicio, j = fin;
    char pivote = datos[indices[(inicio + fin) / 2]];

    while (i <= j) {
        while (datos[indices[i]] < pivote) i++;
        while (datos[indices[j]] > pivote) j--;

        if (i <= j) {
            int aux = indices[i];
            indices[i] = indices[j];
            indices[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j)
        quickSortCaracteres(datos, indices, inicio, j);

    if (i < fin)
        quickSortCaracteres(datos, indices, i, fin);
}

// Quick Sort indirecto para personas por edad
void quickSortPersonas(Persona datos[], int indices[],
                       int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = datos[indices[(inicio + fin) / 2]].edad;

    while (i <= j) {
        while (datos[indices[i]].edad < pivote) i++;
        while (datos[indices[j]].edad > pivote) j--;

        if (i <= j) {
            int aux = indices[i];
            indices[i] = indices[j];
            indices[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j)
        quickSortPersonas(datos, indices, inicio, j);

    if (i < fin)
        quickSortPersonas(datos, indices, i, fin);
}

int main() {
    int opcion, n;
    int indices[MAX];

    cout << "=== QUICK SORT INDIRECTO - PE ===\n";
    cout << "1. Enteros\n";
    cout << "2. Caracteres\n";
    cout << "3. Personas por edad\n";
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    cout << "Cantidad de elementos (1-100): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Cantidad no valida.\n";
        return 0;
    }

    if (opcion == 1) {
        int datos[MAX];

        for (int i = 0; i < n; i++) {
            cout << "Entero " << i + 1 << ": ";
            cin >> datos[i];
        }

        inicializarIndices(indices, n);
        quickSortEnteros(datos, indices, 0, n - 1);

        cout << "\nDatos originales: ";
        for (int i = 0; i < n; i++)
            cout << datos[i] << " ";

        cout << "\nDatos ordenados indirectamente: ";
        for (int i = 0; i < n; i++)
            cout << datos[indices[i]] << " ";

        cout << "\nIndices ordenados: ";
        for (int i = 0; i < n; i++)
            cout << indices[i] << " ";
    }
    else if (opcion == 2) {
        char datos[MAX];

        for (int i = 0; i < n; i++) {
            cout << "Caracter " << i + 1 << ": ";
            cin >> datos[i];
        }

        inicializarIndices(indices, n);
        quickSortCaracteres(datos, indices, 0, n - 1);

        cout << "\nDatos originales: ";
        for (int i = 0; i < n; i++)
            cout << datos[i] << " ";

        cout << "\nDatos ordenados indirectamente: ";
        for (int i = 0; i < n; i++)
            cout << datos[indices[i]] << " ";

        cout << "\nIndices ordenados: ";
        for (int i = 0; i < n; i++)
            cout << indices[i] << " ";
    }
    else if (opcion == 3) {
        Persona datos[MAX];

        for (int i = 0; i < n; i++) {
            cout << "Nombre: ";
            cin >> datos[i].nombre;
            cout << "Edad: ";
            cin >> datos[i].edad;
        }

        inicializarIndices(indices, n);
        quickSortPersonas(datos, indices, 0, n - 1);

        cout << "\nPersonas originales:\n";
        for (int i = 0; i < n; i++)
            cout << datos[i].nombre << " - "
                 << datos[i].edad << " anios\n";

        cout << "\nPersonas ordenadas por edad:\n";
        for (int i = 0; i < n; i++) {
            int pos = indices[i];
            cout << datos[pos].nombre << " - "
                 << datos[pos].edad << " anios\n";
        }

        cout << "Indices ordenados: ";
        for (int i = 0; i < n; i++)
            cout << indices[i] << " ";
    }
    else {
        cout << "Opcion no valida.\n";
    }

    return 0;
}

