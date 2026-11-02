#include <iostream>
using namespace std;

class ListaEstatica {
private:
    static const int CAPACIDAD = 10; // Tamaño máximo fijo del arreglo
    int datos[CAPACIDAD];
    int tamano; // Cantidad actual de elementos

public:
    // Constructor
    ListaEstatica() {
        tamano = 0;
    }

    // Verificar si la lista está llena
    bool estaLlena() const {
        return tamano == CAPACIDAD;
    }

    // Verificar si la lista está vacía
    bool estaVacia() const {
        return tamano == 0;
    }

    // Insertar un elemento al final de la lista
    void insertar(int valor) {
        if (estaLlena()) {
            cout << "Error: La lista esta llena. No se puede insertar " << valor << ".
";
            return;
        }
        datos[tamano] = valor;
        tamano++;
        cout << "Elemento " << valor << " insertado correctamente.
";
    }

    // Insertar en una posición específica (0-indexed)
    void insertarEn(int pos, int valor) {
        if (estaLlena()) {
            cout << "Error: La lista esta llena.
";
            return;
        }
        if (pos < 0 || pos > tamano) {
            cout << "Error: Posicion invalida.
";
            return;
        }
        for (int i = tamano; i > pos; i--) {
            datos[i] = datos[i - 1];
        }
        datos[pos] = valor;
        tamano++;
        cout << "Elemento " << valor << " insertado en la posicion " << pos << ".
";
    }

    // Eliminar por valor
    void eliminar(int valor) {
        if (estaVacia()) {
            cout << "Error: La lista esta vacia.
";
            return;
        }
        int pos = -1;
        for (int i = 0; i < tamano; i++) {
            if (datos[i] == valor) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << "Error: El elemento " << valor << " no se encuentra en la lista.
";
            return;
        }
        for (int i = pos; i < tamano - 1; i++) {
            datos[i] = datos[i + 1];
        }
        tamano--;
        cout << "Elemento " << valor << " eliminado de la lista.
";
    }

    // Buscar la posición de un elemento
    int buscar(int valor) const {
        for (int i = 0; i < tamano; i++) {
            if (datos[i] == valor) {
                return i;
            }
        }
        return -1;
    }

    // Imprimir el contenido de la lista
    void mostrar() const {
        if (estaVacia()) {
            cout << "La lista esta vacia.
";
            return;
        }
        cout << "Lista [" << tamano << "/" << CAPACIDAD << "]: [ ";
        for (int i = 0; i < tamano; i++) {
            cout << datos[i] << " ";
        }
        cout << "]
";
    }
};

int main() {
    ListaEstatica lista;
    int opcion, valor, pos;

    do {
        cout << "
=======================================
";
        cout << "  LISTA ESTATICA (CON ARREGLO) - POO  
";
        cout << "=======================================
";
        cout << "1. Insertar al final
";
        cout << "2. Insertar en posicion específica
";
        cout << "3. Eliminar por valor
";
        cout << "4. Buscar elemento
";
        cout << "5. Mostrar lista
";
        cout << "6. Salir
";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor a insertar: ";
                cin >> valor;
                lista.insertar(valor);
                break;
            case 2:
                cout << "Ingresa la posicion (0 a " << 10 << "): ";
                cin >> pos;
                cout << "Ingresa el valor a insertar: ";
                cin >> valor;
                lista.insertarEn(pos, valor);
                break;
            case 3:
                cout << "Ingresa el valor a eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                break;
            case 4:
                cout << "Ingresa el valor a buscar: ";
                cin >> valor;
                pos = lista.buscar(valor);
                if (pos != -1) {
                    cout << "El elemento " << valor << " se encuentra en el indice " << pos << ".
";
                } else {
                    cout << "El elemento " << valor << " no esta en la lista.
";
                }
                break;
            case 5:
                lista.mostrar();
                break;
            case 6:
                cout << "Saliendo del programa...
";
                break;
            default:
                cout << "Opcion invalida. Intenta de nuevo.
";
        }
    } while (opcion != 6);

    return 0;
}
