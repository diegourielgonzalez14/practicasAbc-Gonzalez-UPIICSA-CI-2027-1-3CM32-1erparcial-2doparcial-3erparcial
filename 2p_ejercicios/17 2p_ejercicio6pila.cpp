
#include <iostream>
#include <stdlib.h>
using namespace std;

// Clase que representa cada nodo de la pila
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = NULL;
    }
};

// Clase que maneja la pila dinamica
class Pila {
private:
    Nodo* tope;

public:
    // Constructor
    Pila() {
        tope = NULL;
    }

    // Destructor: libera la memoria de todos los nodos
    ~Pila() {
        while (tope != NULL) {
            Nodo* auxiliar = tope;
            tope = tope->siguiente;
            delete auxiliar;
        }
    }

    // Insertar elemento (PUSH)
    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);

        nuevo->siguiente = tope;
        tope = nuevo;

        cout << "Elemento insertado correctamente.\n";
    }

    // Eliminar elemento (POP)
    void eliminar() {
        if (tope == NULL) {
            cout << "La pila esta vacia.\n";
        } else {
            Nodo* auxiliar = tope;

            cout << "Elemento eliminado: "
                 << tope->dato << endl;

            tope = tope->siguiente;
            delete auxiliar;
        }
    }

    // Mostrar elementos de la pila
    void mostrar() {
        if (tope == NULL) {
            cout << "La pila esta vacia.\n";
        } else {
            Nodo* actual = tope;

            cout << "\nElementos de la pila:\n";

            while (actual != NULL) {
                cout << actual->dato << endl;
                actual = actual->siguiente;
            }
        }
    }

    // Consultar el elemento superior (PEEK)
    void consultarTope() {
        if (tope == NULL) {
            cout << "La pila esta vacia.\n";
        } else {
            cout << "Elemento en el tope: "
                 << tope->dato << endl;
        }
    }

    // Verificar si la pila esta vacia
    bool estaVacia() {
        return tope == NULL;
    }
};

int main() {
    Pila pila;
    int opcion, valor;

    do {
        cout << "\n=== PILA DINAMICA EN POO ===\n";
        cout << "1. Insertar elemento (PUSH)\n";
        cout << "2. Eliminar elemento (POP)\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Consultar tope (PEEK)\n";
        cout << "5. Verificar si esta vacia\n";
        cout << "6. Limpiar pantalla\n";
        cout << "7. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa un numero: ";
                cin >> valor;
                pila.insertar(valor);
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
                if (pila.estaVacia())
                    cout << "La pila esta vacia.\n";
                else
                    cout << "La pila contiene elementos.\n";
                break;

            case 6:
                system("cls");
                break;

            case 7:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 7);

    return 0;
}

