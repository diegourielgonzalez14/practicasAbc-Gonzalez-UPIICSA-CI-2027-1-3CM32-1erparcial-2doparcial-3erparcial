#include <iostream>
#include <stdlib.h>
using namespace std;

// Clase que representa cada nodo de la cola
class Nodo {
public:
    int dato;
    Nodo* siguiente;

    // Constructor del nodo
    Nodo(int valor) {
        dato = valor;
        siguiente = NULL;
    }
};

// Clase que maneja la cola dinamica
class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    // Constructor de la cola
    Cola() {
        frente = NULL;
        final = NULL;
    }

    // Destructor: libera la memoria de los nodos
    ~Cola() {
        while (frente != NULL) {
            Nodo* auxiliar = frente;
            frente = frente->siguiente;
            delete auxiliar;
        }
        final = NULL;
    }

    // Insertar elemento (ENQUEUE)
    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);

        if (frente == NULL) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }

        cout << "Elemento insertado correctamente.\n";
    }

    // Eliminar elemento (DEQUEUE)
    void eliminar() {
        if (frente == NULL) {
            cout << "La cola esta vacia.\n";
        } else {
            Nodo* auxiliar = frente;

            cout << "Elemento eliminado: "
                 << frente->dato << endl;

            frente = frente->siguiente;

            if (frente == NULL) {
                final = NULL;
            }

            delete auxiliar;
        }
    }

    // Mostrar elementos de la cola
    void mostrar() {
        if (frente == NULL) {
            cout << "La cola esta vacia.\n";
        } else {
            Nodo* actual = frente;

            cout << "\nElementos de la cola:\n";

            while (actual != NULL) {
                cout << actual->dato << endl;
                actual = actual->siguiente;
            }
        }
    }

    // Consultar el primer elemento
    void consultarFrente() {
        if (frente == NULL) {
            cout << "La cola esta vacia.\n";
        } else {
            cout << "Elemento al frente: "
                 << frente->dato << endl;
        }
    }

    // Consultar el ultimo elemento
    void consultarFinal() {
        if (final == NULL) {
            cout << "La cola esta vacia.\n";
        } else {
            cout << "Elemento al final: "
                 << final->dato << endl;
        }
    }

    // Verificar si la cola esta vacia
    bool estaVacia() {
        return frente == NULL;
    }
};

int main() {
    Cola cola;
    int opcion, valor;

    do {
        cout << "\n=== COLA DINAMICA EN POO ===\n";
        cout << "1. Insertar elemento (ENQUEUE)\n";
        cout << "2. Eliminar elemento (DEQUEUE)\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Consultar frente\n";
        cout << "5. Consultar final\n";
        cout << "6. Verificar si esta vacia\n";
        cout << "7. Limpiar pantalla\n";
        cout << "8. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa un numero: ";
                cin >> valor;
                cola.insertar(valor);
                break;

            case 2:
                cola.eliminar();
                break;

            case 3:
                cola.mostrar();
                break;

            case 4:
                cola.consultarFrente();
                break;

            case 5:
                cola.consultarFinal();
                break;

            case 6:
                if (cola.estaVacia())
                    cout << "La cola esta vacia.\n";
                else
                    cout << "La cola contiene elementos.\n";
                break;

            case 7:
                system("cls");
                break;

            case 8:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Opcion no valida.\n";
        }

    } while (opcion != 8);

    return 0;
}

