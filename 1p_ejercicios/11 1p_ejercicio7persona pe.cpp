
#include <iostream>
#include <string>
using namespace std;

struct Persona {
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
};

int main() {
    Persona persona1;

    cout << "Ingresa el nombre: ";
    cin >> persona1.nombre;

    cout << "Ingresa el apellido paterno: ";
    cin >> persona1.ap;

    cout << "Ingresa el apellido materno: ";
    cin >> persona1.am;

    cout << "Ingresa el genero: ";
    cin >> persona1.genero;

    cout << "Ingresa la edad: ";
    cin >> persona1.edad;

    cout << "\n--- DATOS DE LA PERSONA ---" << endl;
    cout << "Nombre: " << persona1.nombre << endl;
    cout << "Apellido paterno: " << persona1.ap << endl;
    cout << "Apellido materno: " << persona1.am << endl;
    cout << "Genero: " << persona1.genero << endl;
    cout << "Edad: " << persona1.edad << endl;

    return 0;
}

