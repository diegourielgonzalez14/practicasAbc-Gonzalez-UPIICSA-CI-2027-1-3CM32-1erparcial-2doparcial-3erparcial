#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX = 5;

class Auto {
public:
    string marca;
    string modelo;
    int anio;

    void capturar() {
        cout << "Marca del auto: ";
        cin >> marca;

        cout << "Modelo del auto: ";
        cin >> modelo;

        cout << "Anio del auto: ";
        cin >> anio;
    }

    void mostrar() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio: " << anio << endl;
    }
};

class Persona {
public:
    string nombre;
    int edad;
    Auto autoPersona;

    Persona* siguiente;

    Persona() {
        siguiente = NULL;
    }

    void capturar() {
        cout << "Nombre de la persona: ";
        cin >> nombre;

        cout << "Edad: ";
        cin >> edad;

        cout << "\nDatos del auto:\n";
        autoPersona.capturar();
    }

    void mostrar() {
        cout << "\n----------------------\n";
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;

        cout << "\nDatos del auto:\n";
        autoPersona.mostrar();
    }
};

int main() {
    Persona personas[MAX];

    cout << "CAPTURA DE PERSONAS Y AUTOS\n";

    for (int i = 0; i < MAX; i++) {
        cout << "\nPersona " << i + 1 << endl;
        personas[i].capturar();
    }

    for (int i = 0; i < MAX - 1; i++) {
        personas[i].siguiente = &personas[i + 1];
    }

    personas[MAX - 1].siguiente = NULL;

    cout << "\nLISTA DE PERSONAS Y SUS AUTOS\n";

    Persona* actual = &personas[0];

    while (actual != NULL) {
        actual->mostrar();
        actual = actual->siguiente;
    }

    cout << "\nPrograma terminado.";
    cout << "\nPresiona ENTER para salir...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
