
#include <iostream>
using namespace std;

const int MAX = 5;

int cola[MAX];
int frente = 0;
int cantidad = 0;

void insertar() {
    if (cantidad == MAX) {
        cout << "\nLa cola esta llena.\n";
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

    int finalCola = (frente + cantidad) % MAX;
    cola[finalCola] = dato;
    cantidad++;

    cout << "\nElemento insertado correctamente.\n";
}

void borrar() {
    if (cantidad == 0) {
        cout << "\nLa cola esta vacia.\n";
        return;
    }

    cout << "\nElemento borrado: " << cola[frente] << endl;

    frente = (frente + 1) % MAX;
    cantidad--;
}

void mostrar() {
    if (cantidad == 0) {
        cout << "\nLa cola esta vacia.\n";
        return;
    }

    cout << "\nElementos de la cola:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << cola[(frente + i) % MAX] << " ";
    }

    cout << endl;
}

int main() {
    int opcion = 0;

    do {
        cout << "\n===== MENU DE COLA =====\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Borrar elemento\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Salir\n";
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
                borrar();
                break;

            case 3:
                mostrar();
                break;

            case 4:
                cout << "\nPrograma terminado.\n";
                break;

            default:
                cout << "\nOpcion no valida. Elige del 1 al 4.\n";
        }

    } while (opcion != 4);

    return 0;
}

