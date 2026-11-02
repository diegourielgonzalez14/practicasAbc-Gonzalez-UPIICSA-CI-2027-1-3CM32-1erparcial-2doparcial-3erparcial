
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAX = 5;

class Pila {
private:
    int datos[MAX];
    int tope;

public:
    // Constructor
    Pila() {
        tope = -1;
    }

    // Insertar elemento (PUSH)
    void insertar() {
        int dato;

        if (tope == MAX - 1) {
            cout << "La pila esta llena. Limite de 5 elementos.\n";
        } else {
            cout << "Ingresa un numero: ";
            cin >> dato;

            tope++;
            datos[tope] = dato;

            cout << "Elemento insertado correctamente.\n";
        }
    }

    // Eliminar elemento (POP)
    void eliminar() {
        if (tope == -1) {
            cout << "La pila esta vacia.\n";
        } else {
            cout << "Elemento eliminado: "
                 << datos[tope] << endl;
            tope--;
        }
    }

    // Mostrar elementos de la pila
    void mostrar() {
        if (tope == -1) {
            cout << "La pila esta vacia.\n";
        } else {
            cout << "\nElementos de la pila:\n";

            for (int i = tope; i >= 0; i--) {
                cout << datos[i] << endl;
            }
        }
    }

    // Consultar elemento superior (PEEK)
    void consultarTope() {
        if (tope == -1) {
            cout << "La pila esta vacia.\n";
        } else {
            cout << "Elemento en el tope: "
                 << datos[tope] << endl;
        }
    }
};

int main() {
    Pila pila;
    int opcion;

    do {
        cout << "\n=== PILA ESTATICA EN POO ===\n";
        cout << "1. Insertar elemento (PUSH)\n";
        cout << "2. Eliminar elemento (POP)\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Consultar tope (PEEK)\n";
        cout << "5. Limpiar pantalla\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pila.insertar();
                break;

            case 2:
                pila.eliminar();
                break;

            case 3:
                pila.mostrar();
                break;

            case 4:
                pila.consultarTope();
                break;

            case 5:
                system("cls");
                break;

            case 6:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 6);

    return 0;
}

