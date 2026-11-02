
#include <iostream>
#include <stdlib.h>
using namespace std;

// Clase que representa cada nodo de la lista
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

// Clase que maneja la lista dinamica
class Lista {
private:
    Nodo* inicio;

public:
    // Constructor de la lista
    Lista() {
        inicio = NULL;
    }

    // Destructor: libera la memoria de los nodos
    ~Lista() {
        while (inicio != NULL) {
            Nodo* auxiliar = inicio;
            inicio = inicio->siguiente;
            delete auxiliar;
        }
    }

    // Insertar un elemento al inicio
    void insertarInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);

        nuevo->siguiente = inicio;
        inicio = nuevo;

        cout << "Elemento insertado al inicio.\n";
    }

    // Insertar un elemento al final
    void insertarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);

        if (inicio == NULL) {
            inicio = nuevo;
        } else {
            Nodo* actual = inicio;

            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        cout << "Elemento insertado al final.\n";
    }

    // Eliminar un elemento por su valor
    void eliminar(int valor) {
        if (inicio == NULL) {
            cout << "La lista esta vacia.\n";
            return;
        }

        // Si el elemento esta al inicio
        if (inicio->dato == valor) {
            Nodo* auxiliar = inicio;
            inicio = inicio->siguiente;
            delete auxiliar;

            cout << "Elemento eliminado.\n";
            return;
        }

        // Buscar el elemento
        Nodo* actual = inicio;

        while (actual->siguiente != NULL &&
               actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente == NULL) {
            cout << "Elemento no encontrado.\n";
        } else {
            Nodo* auxiliar = actual->siguiente;
            actual->siguiente = auxiliar->siguiente;
            delete auxiliar;

            cout << "Elemento eliminado.\n";
        }
    }

    // Buscar un elemento
    void buscar(int valor) {
        Nodo* actual = inicio;
        int posicion = 1;

        while (actual != NULL) {
            if (actual->dato == valor) {
                cout << "Elemento encontrado en la posicion "
                     << posicion << ".\n";
                return;
            }

            actual = actual->siguiente;
            posicion++;
        }

        cout << "Elemento no encontrado.\n";
    }

    // Mostrar todos los elementos
    void mostrar() {
        if (inicio == NULL) {
            cout << "La lista esta vacia.\n";
            return;
        }

        Nodo* actual = inicio;

        cout << "\nElementos de la lista:\n";

        while (actual != NULL) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }

        cout << "NULL\n";
    }

    // Consultar si la lista esta vacia
    bool estaVacia() {
        return inicio == NULL;
    }
};

int main() {
    Lista lista;
    int opcion, valor;

    do {
        cout << "\n=== LISTA DINAMICA EN POO ===\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Eliminar elemento\n";
        cout << "4. Buscar elemento\n";
        cout << "5. Mostrar lista\n";
        cout << "6. Verificar si esta vacia\n";
        cout << "7. Limpiar pantalla\n";
        cout << "8. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa un numero: ";
                cin >> valor;
                lista.insertarInicio(valor);
                break;

            case 2:
                cout << "Ingresa un numero: ";
                cin >> valor;
                lista.insertarFinal(valor);
                break;

            case 3:
                cout << "Ingresa el numero que deseas eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                break;

            case 4:
                cout << "Ingresa el numero que deseas buscar: ";
                cin >> valor;
                lista.buscar(valor);
                break;

            case 5:
                lista.mostrar();
                break;

            case 6:
                if (lista.estaVacia())
                    cout << "La lista esta vacia.\n";
                else
                    cout << "La lista contiene elementos.\n";
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

