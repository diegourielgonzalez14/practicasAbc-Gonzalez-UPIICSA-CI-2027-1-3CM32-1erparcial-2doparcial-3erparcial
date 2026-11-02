
#include <iostream>
using namespace std;

class OrdenamientoBurbuja {
private:
    int numeros[100];
    int cantidad;

public:
    // Constructor
    OrdenamientoBurbuja(int n) {
        cantidad = n;
    }

    // Metodo para ingresar los numeros
    void ingresarNumeros() {
        cout << "Ingresa " << cantidad
             << " numeros enteros:" << endl;

        for (int i = 0; i < cantidad; i++) {
            cin >> numeros[i];
        }
    }

    // Metodo para mostrar los numeros
    void mostrarNumeros() {
        for (int i = 0; i < cantidad; i++) {
            cout << numeros[i] << " ";
        }
        cout << endl;
    }

    // Metodo de ordenamiento burbuja
    void ordenarBurbuja() {
        int auxiliar;

        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - 1 - i; j++) {

                if (numeros[j] > numeros[j + 1]) {
                    auxiliar = numeros[j];
                    numeros[j] = numeros[j + 1];
                    numeros[j + 1] = auxiliar;
                }
            }
        }
    }
};

int main() {
    int cantidad;

    cout << "=== ORDENAMIENTO BURBUJA CON POO ==="
         << endl;

    cout << "Cuantos numeros deseas ordenar? ";
    cin >> cantidad;

    if (cantidad < 1 || cantidad > 100) {
        cout << "Error: ingresa una cantidad entre 1 y 100."
             << endl;
        return 1;
    }

    // Crear un objeto de la clase
    OrdenamientoBurbuja objeto(cantidad);

    // Utilizar los metodos del objeto
    objeto.ingresarNumeros();

    cout << "\nNumeros originales: ";
    objeto.mostrarNumeros();

    objeto.ordenarBurbuja();

    cout << "Numeros ordenados: ";
    objeto.mostrarNumeros();

    return 0;
}

