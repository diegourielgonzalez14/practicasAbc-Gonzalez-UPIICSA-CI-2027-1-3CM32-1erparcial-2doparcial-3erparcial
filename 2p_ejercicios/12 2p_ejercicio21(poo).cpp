#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// Clase que representa el nuevo tipo de dato
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
        cout << nombre << " - " << edad << " anios\n";
    }
};

// Clase que realiza el ordenamiento indirecto
class Ordenador {
private:
    int indices[MAX];

public:
    void inicializarIndices(int n) {
        for (int i = 0; i < n; i++)
            indices[i] = i;
    }

    // Ordenamiento indirecto de enteros
    void quickSort(int datos[], int inicio, int fin) {
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

        if (inicio < j) quickSort(datos, inicio, j);
        if (i < fin) quickSort(datos, i, fin);
    }

    // Ordenamiento indirecto de caracteres
    void quickSort(char datos[], int inicio, int fin) {
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

        if (inicio < j) quickSort(datos, inicio, j);
        if (i < fin) quickSort(datos, i, fin);
    }

    // Ordenamiento indirecto de personas por edad
    void quickSort(Persona datos[], int inicio, int fin) {
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

        if (inicio < j) quickSort(datos, inicio, j);
        if (i < fin) quickSort(datos, i, fin);
    }

    // Consultar un indice ordenado
    int obtenerIndice(int posicion) {
        return indices[posicion];
    }
};

int main() {
    Ordenador ordenador;
    int opcion, n;

    cout << "=== QUICK SORT INDIRECTO - POO ===\n";
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

    ordenador.inicializarIndices(n);

    if (opcion == 1) {
        int datos[MAX];

        for (int i = 0; i < n; i++) {
            cout << "Entero " << i + 1 << ": ";
            cin >> datos[i];
        }

        ordenador.quickSort(datos, 0, n - 1);

        cout << "\nDatos originales: ";
        for (int i = 0; i < n; i++)
            cout << datos[i] << " ";

        cout << "\nDatos ordenados: ";
        for (int i = 0; i < n; i++)
            cout << datos[ordenador.obtenerIndice(i)] << " ";

        cout << "\nIndices ordenados: ";
        for (int i = 0; i < n; i++)
            cout << ordenador.obtenerIndice(i) << " ";
    }
    else if (opcion == 2) {
        char datos[MAX];

        for (int i = 0; i < n; i++) {
            cout << "Caracter " << i + 1 << ": ";
            cin >> datos[i];
        }

        ordenador.quickSort(datos, 0, n - 1);

        cout << "\nDatos originales: ";
        for (int i = 0; i < n; i++)
            cout << datos[i] << " ";

        cout << "\nDatos ordenados: ";
        for (int i = 0; i < n; i++)
            cout << datos[ordenador.obtenerIndice(i)] << " ";

        cout << "\nIndices ordenados: ";
        for (int i = 0; i < n; i++)
            cout << ordenador.obtenerIndice(i) << " ";
    }
    else if (opcion == 3) {
        Persona datos[MAX];

        for (int i = 0; i < n; i++) {
            string nombre;
            int edad;

            cout << "Nombre: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            datos[i] = Persona(nombre, edad);
        }

        ordenador.quickSort(datos, 0, n - 1);

        cout << "\nPersonas originales:\n";
        for (int i = 0; i < n; i++)
            datos[i].mostrar();

        cout << "\nPersonas ordenadas por edad:\n";
        for (int i = 0; i < n; i++) {
            int pos = ordenador.obtenerIndice(i);
            datos[pos].mostrar();
        }

        cout << "Indices ordenados: ";
        for (int i = 0; i < n; i++)
            cout << ordenador.obtenerIndice(i) << " ";
    }
    else {
        cout << "Opcion no valida.\n";
    }

    return 0;
}

