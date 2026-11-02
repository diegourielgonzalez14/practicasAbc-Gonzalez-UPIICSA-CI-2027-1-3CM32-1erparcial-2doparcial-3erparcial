#include <iostream>
#include <string>
using namespace std;

// Nuevo tipo de dato
struct Persona {
    string nombre;
    int edad;
};

// Quick Sort para enteros
void quickSort(int v[], int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = v[(inicio + fin) / 2];

    while (i <= j) {
        while (v[i] < pivote) i++;
        while (v[j] > pivote) j--;

        if (i <= j) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j) quickSort(v, inicio, j);
    if (i < fin) quickSort(v, i, fin);
}

// Quick Sort para caracteres
void quickSort(char v[], int inicio, int fin) {
    int i = inicio, j = fin;
    char pivote = v[(inicio + fin) / 2];

    while (i <= j) {
        while (v[i] < pivote) i++;
        while (v[j] > pivote) j--;

        if (i <= j) {
            char aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j) quickSort(v, inicio, j);
    if (i < fin) quickSort(v, i, fin);
}

// Quick Sort para el nuevo tipo Persona
void quickSort(Persona v[], int inicio, int fin) {
    int i = inicio, j = fin;
    int pivote = v[(inicio + fin) / 2].edad;

    while (i <= j) {
        while (v[i].edad < pivote) i++;
        while (v[j].edad > pivote) j--;

        if (i <= j) {
            Persona aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    if (inicio < j) quickSort(v, inicio, j);
    if (i < fin) quickSort(v, i, fin);
}

int main() {
    int opcion, n;

    cout << "=== QUICK SORT EN PE ===" << endl;
    cout << "1. Ordenar enteros" << endl;
    cout << "2. Ordenar caracteres" << endl;
    cout << "3. Ordenar personas por edad" << endl;
    cout << "Elige una opcion: ";
    cin >> opcion;

    cout << "Cantidad de elementos (1 a 100): ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Cantidad no valida." << endl;
        return 0;
    }

    if (opcion == 1) {
        int v[100];

        for (int i = 0; i < n; i++) {
            cout << "Entero " << i + 1 << ": ";
            cin >> v[i];
        }

        quickSort(v, 0, n - 1);

        cout << "Enteros ordenados: ";
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
    else if (opcion == 2) {
        char v[100];

        for (int i = 0; i < n; i++) {
            cout << "Caracter " << i + 1 << ": ";
            cin >> v[i];
        }

        quickSort(v, 0, n - 1);

        cout << "Caracteres ordenados: ";
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
    else if (opcion == 3) {
        Persona v[100];

        for (int i = 0; i < n; i++) {
            cout << "Nombre de la persona " << i + 1 << ": ";
            cin >> v[i].nombre;
            cout << "Edad: ";
            cin >> v[i].edad;
        }

        quickSort(v, 0, n - 1);

        cout << "\nPersonas ordenadas por edad:\n";
        for (int i = 0; i < n; i++)
            cout << v[i].nombre << " - "
                 << v[i].edad << " anios" << endl;
    }
    else {
        cout << "Opcion no valida." << endl;
    }

    return 0;
}

