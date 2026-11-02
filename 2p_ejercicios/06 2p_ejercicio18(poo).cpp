#include <iostream>
#include <string>
using namespace std;

// Clase que representa un nuevo tipo de dato
class Persona {
public:
    string nombre;
    int edad;

    Persona() {
        nombre = "";
        edad = 0;
    }

    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrar() {
        cout << nombre << " - " << edad << " anios" << endl;
    }
};

// Clase encargada del ordenamiento
class Ordenador {
public:

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

    // Quick Sort para objetos Persona
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
};

int main() {
    Ordenador ordenador;
    int opcion, n;

    cout << "=== QUICK SORT EN POO ===" << endl;
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
            cout << "Ingresa el entero " << i + 1 << ": ";
            cin >> v[i];
        }

        ordenador.quickSort(v, 0, n - 1);

        cout << "Enteros ordenados: ";
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
    else if (opcion == 2) {
        char v[100];

        for (int i = 0; i < n; i++) {
            cout << "Ingresa el caracter " << i + 1 << ": ";
            cin >> v[i];
        }

        ordenador.quickSort(v, 0, n - 1);

        cout << "Caracteres ordenados: ";
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    }
    else if (opcion == 3) {
        Persona v[100];

        for (int i = 0; i < n; i++) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            v[i] = Persona(nombre, edad);
        }

        ordenador.quickSort(v, 0, n - 1);

        cout << "\nPersonas ordenadas por edad:\n";
        for (int i = 0; i < n; i++)
            v[i].mostrar();
    }
    else {
        cout << "Opcion no valida." << endl;
    }

    return 0;
}

