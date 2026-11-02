#include <iostream>
#include <queue> // Librería estándar de C++ para la cola (queue)
using namespace std;

class ColaDinamicaIDE {
private:
    queue<int> cola; // Cola dinámica proporcionada por la librería estándar (STL)

public:
    // Método para insertar un elemento al final (Enqueue)
    void encolar(int valor) {
        cola.push(valor);
        cout << "Elemento " << valor << " agregado a la cola.\n";
    }

    // Método para eliminar y extraer el elemento del frente (Dequeue)
    void desencolar() {
        if (estaVacia()) {
            cout << "Error: La cola esta vacia. No se puede desencolar.\n";
            return;
        }
        cout << "Elemento " << cola.front() << " eliminado de la cola.\n";
        cola.pop();
    }

    // Método para ver el elemento al frente sin eliminarlo (Front)
    void verFrente() const {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }
        cout << "Elemento al frente de la cola: " << cola.front() << "\n";
    }

    // Verificar si la cola está vacía
    bool estaVacia() const {
        return cola.empty();
    }

    // Obtener el tamaño actual de la cola
    void mostrarTamano() const {
        cout << "Tamaño actual de la cola: " << cola.size() << "\n";
    }

    // Mostrar todos los elementos (creando una copia para no vaciar la original)
    void mostrarCola() const {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }
        
        queue<int> temp = cola; // Copia de la cola para iterar
        cout << "Cola (Frente -> Final): [ ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "]\n";
    }
};

int main() {
    ColaDinamicaIDE gestorCola;
    int opcion, valor;

    do {
        cout << "\n=======================================\n";
        cout << "   COLA DINÁMICA (STL queue) - C++    \n";
        cout << "=======================================\n";
        cout << "1. Encolar (push)\n";
        cout << "2. Desencolar (pop)\n";
        cout << "3. Ver frente (front)\n";
        cout << "4. Ver tamaño (size)\n";
        cout << "5. Mostrar cola completa\n";
        cout << "6. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor a encolar: ";
                cin >> valor;
                gestorCola.encolar(valor);
                break;
            case 2:
                gestorCola.desencolar();
                break;
            case 3:
                gestorCola.verFrente();
                break;
            case 4:
                gestorCola.mostrarTamano();
                break;
            case 5:
                gestorCola.mostrarCola();
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}
