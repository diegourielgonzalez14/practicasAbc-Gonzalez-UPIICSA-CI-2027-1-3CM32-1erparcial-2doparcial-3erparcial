#include <iostream>
#include <list>
using namespace std;

class Lista {
private:
    list<int> datos;

public:
    // Insertar al inicio
    void insertarInicio(int valor) {
        datos.push_front(valor);
        cout << "Elemento insertado al inicio.\n";
    }

    // Insertar al final
    void insertarFinal(int valor) {
        datos.push_back(valor);
        cout << "Elemento insertado al final.\n";
    }

    // Eliminar la primera aparicion de un valor
    void eliminar(int valor) {
        for (list<int>::iterator it = datos.begin();
             it != datos.end(); ++it) {

            if (*it == valor) {
                datos.erase(it);
                cout << "Elemento eliminado.\n";
                return;
            }
        }

        cout << "Elemento no encontrado.\n";
    }

    // Buscar un elemento
    void buscar(int valor) {
        int posicion = 1;

        for (list<int>::iterator it = datos.begin();
             it != datos.end(); ++it) {

            if (*it == valor) {
                cout << "Elemento encontrado en la posicion "
                     << posicion << ".\n";
                return;
            }

            posicion++;
        }

        cout << "Elemento no encontrado.\n";
    }

    // Mostrar todos los elementos
    void mostrar() {
        if (datos.empty()) {
            cout << "La lista esta vacia.\n";
            return;
        }

        cout << "\nElementos de la lista:\n";

        for (list<int>::iterator it = datos.begin();
             it != datos.end(); ++it) {
            cout << *it << " -> ";
        }

        cout << "FIN\n";
    }

    // Consultar si la lista esta vacia
    void estaVacia() {
        if (datos.empty())
            cout << "La lista esta vacia.\n";
        else
            cout << "La lista contiene elementos.\n";
    }

    // Mostrar la cantidad de elementos
    void cantidad() {
        cout << "Cantidad de elementos: "
             << datos.size() << endl;
    }
};

int main() {
    Lista lista;
    int opcion, valor;

    do {
        cout << "\n=== LISTA DINAMICA CON STL ===\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Eliminar elemento\n";
        cout << "4. Buscar elemento\n";
        cout << "5. Mostrar lista\n";
        cout << "6. Verificar si esta vacia\n";
        cout << "7. Consultar cantidad de elementos\n";
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
                cout << "Numero que deseas eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                break;

            case 4:
                cout << "Numero que deseas buscar: ";
                cin >> valor;
                lista.buscar(valor);
                break;

            case 5:
                lista.mostrar();
                break;

            case 6:
                lista.estaVacia();
                break;

            case 7:
                lista.cantidad();
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

