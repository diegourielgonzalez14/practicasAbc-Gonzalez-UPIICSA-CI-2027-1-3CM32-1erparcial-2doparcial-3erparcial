
#include <iostream>
using namespace std;

class Auto {
public:
    double precio;
    int anio;
};

class Persona {
public:
    char nombre[30];
    char ap[30];
    char am[30];
    char genero[15];
    int edad;
};

int main() {
    cout << "=== TAMANO DE TIPOS BASICOS ===" << endl;

    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;

    cout << "\n=== TAMANO DE TIPOS CREADOS (POO) ===" << endl;

    cout << "Auto: " << sizeof(Auto) << " bytes" << endl;
    cout << "Persona: " << sizeof(Persona) << " bytes" << endl;

    return 0;
}

