
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;

public:
    void capturar() {
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
    }

    void mostrar() {
        cout << "\n=== DATOS DE LA PERSONA ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido paterno: " << ap << endl;
        cout << "Apellido materno: " << am << endl;
        cout << "Genero: " << genero << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {
    Persona persona1;

    persona1.capturar();
    persona1.mostrar();

    return 0;
}

