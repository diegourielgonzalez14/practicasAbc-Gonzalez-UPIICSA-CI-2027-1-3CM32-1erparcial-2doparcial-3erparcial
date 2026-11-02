
#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    double precio;
    int anio;
    string marca;

public:
    void capturar() {
        cout << "\n--- DATOS DEL AUTO ---" << endl;

        cout << "Ingresa la marca: ";
        cin >> marca;

        cout << "Ingresa el precio: ";
        cin >> precio;

        cout << "Ingresa el anio: ";
        cin >> anio;
    }

    void mostrar() {
        cout << "\n--- DATOS DEL AUTO ---" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Anio: " << anio << endl;
    }
};

class Persona {
private:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
    Auto coche;

public:
    void capturar() {
        cout << "\n--- DATOS DE LA PERSONA ---" << endl;

        cout << "Ingresa el nombre: ";
        cin >> nombre;

        cout << "Ingresa el apellido paterno: ";
        cin >> ap;

        cout << "Ingresa el apellido materno: ";
        cin >> am;

        cout << "Ingresa el genero: ";
        cin >> genero;

        cout << "Ingresa la edad: ";
        cin >> edad;

        coche.capturar();
    }

    void mostrar() {
        cout << "\n================================" << endl;
        cout << "       DATOS DE LA PERSONA" << endl;
        cout << "================================" << endl;

        cout << "Nombre: " << nombre << endl;
        cout << "Apellido paterno: " << ap << endl;
        cout << "Apellido materno: " << am << endl;
        cout << "Genero: " << genero << endl;
        cout << "Edad: " << edad << endl;

        coche.mostrar();
    }
};

int main() {
    const int MAX = 5;
    Persona personas[MAX];
    Persona *ptr = personas;
    int cantidad;

    cout << "CUANTAS PERSONAS DESEAS REGISTRAR? (1-5): ";
    cin >> cantidad;

    if (cantidad < 1 || cantidad > MAX) {
        cout << "Cantidad no valida." << endl;
        return 1;
    }

    // Capturar los datos mediante el puntero
    for (int i = 0; i < cantidad; i++) {
        cout << "\n********************************" << endl;
        cout << "REGISTRO NUMERO " << i + 1 << endl;
        cout << "********************************" << endl;

        (ptr + i)->capturar();
    }

    // Mostrar la lista mediante el puntero
    cout << "\n\n========================================" << endl;
    cout << "     LISTA DE PERSONAS Y SUS COCHES" << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nRegistro " << i + 1 << endl;
        (ptr + i)->mostrar();
    }

    return 0;
}

