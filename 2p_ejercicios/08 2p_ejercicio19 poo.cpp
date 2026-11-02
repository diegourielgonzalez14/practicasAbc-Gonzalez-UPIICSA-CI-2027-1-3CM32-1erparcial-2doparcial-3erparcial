
#include <iostream>
using namespace std;

class OrdenamientoIndirecto {
private:
    int datos[100];
    int indices[100];
    int cantidad;

public:
    // Constructor
    OrdenamientoIndirecto(int n) {
        cantidad = n;
    }

    // Ingresar datos
    void ingresarDatos() {
        cout << "Ingresa " << cantidad
             << " numeros enteros:" << endl;

        for (int i = 0; i < cantidad; i++) {
            cin >> datos[i];
            indices[i] = i;
        }
    }

    // Ordenamiento burbuja indirecto
    void ordenarBurbuja() {
        int auxiliar;

        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - 1 - i; j++) {

                if (datos[indices[j]] >
                    datos[indices[j + 1]]) {

                    auxiliar = indices[j];
                    indices[j] = indices[j + 1];
                    indices[j + 1] = auxiliar;
                }
            }
        }
    }

    // Mostrar datos originales
    void mostrarOriginales() {
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }

    // Mostrar datos ordenados indirectamente
    void mostrarOrdenados() {
        for (int i = 0; i < cantidad; i++) {
            cout << datos[indices[i]] << " ";
        }
        cout << endl;
    }

    // Mostrar indices ordenados
    void mostrarIndices() {
        for (int i = 0; i < cantidad; i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;

    cout << "ORDENAMIENTO INDIRECTO CON POO" << endl;
    cout << "Cuantos numeros deseas ordenar? ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Cantidad no valida." << endl;
        return 1;
    }

    // Crear objeto
    OrdenamientoIndirecto objeto(n);

    objeto.ingresarDatos();

    cout << "\nDatos originales: ";
    objeto.mostrarOriginales();

    objeto.ordenarBurbuja();

    cout << "Datos ordenados indirectamente: ";
    objeto.mostrarOrdenados();

    cout << "Indices ordenados: ";
    objeto.mostrarIndices();

    return 0;
}

