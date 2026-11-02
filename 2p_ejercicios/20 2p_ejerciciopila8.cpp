
#include <iostream>
using namespace std;

const int MAX = 5;

int pila[MAX];
int tope = -1;

void insertar() {
    if (tope == MAX - 1) {
        cout << "\nLa pila esta llena.\n";
        return;
    }

    int dato;
    cout << "Ingresa un numero: ";

    if (!(cin >> dato)) {
        cout << "\nError: ingresa un numero entero.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    tope++;
    pila[tope] = dato;

    cout << "\nElemento insertado correctamente.\n";
}

void eliminar() {
    if (tope == -1) {
        cout << "\nLa pila esta vacia.\n";
        return;
    }

    cout << "\nElemento eliminado: " << pila[tope] << endl;
    tope--;
}

void mostrar() {
    if (tope == -1) {
        cout << "\nLa pila esta vacia.\n";
        return;
    }

    cout << "\nElementos de la pila (de arriba hacia abajo):\n";

    for (int i = tope; i >= 0; i--) {
        cout << pila[i] << endl;
    }
}

void consultar() {
    if (tope == -1) {
        cout << "\nLa pila esta vacia.\n";
        return;
    }

    cout << "\nElemento superior: " << pila[tope] << endl;
}

int main() {
    int opcion = 0;

    do {
        cout << "\n===== MENU DE PILA =====\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Consultar elemento superior\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";

        if (!(cin >> opcion)) {
            cout << "\nError: ingresa una opcion numerica.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                insertar();
                break;

            case 2:
                eliminar();
                break;

            case 3:
                mostrar();
                break;

            case 4:
                consultar();
                break;

            case 5:
                cout << "\nPrograma terminado.\n";
                break;

            default:
                cout << "\nOpcion no valida. Elige del 1 al 5.\n";
        }

    } while (opcion != 5);

    return 0;
}

