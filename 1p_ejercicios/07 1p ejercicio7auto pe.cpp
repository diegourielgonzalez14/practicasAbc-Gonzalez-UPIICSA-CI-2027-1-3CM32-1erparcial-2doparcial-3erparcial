
#include <iostream>
using namespace std;

struct Auto {
    float precio;
    int anio;
};

int main() {
    Auto auto1;

    cout << "Ingresa el precio del auto: ";
    cin >> auto1.precio;

    cout << "Ingresa el anio del auto: ";
    cin >> auto1.anio;

    cout << "\n--- DATOS DEL AUTO ---" << endl;
    cout << "Precio: $" << auto1.precio << endl;
    cout << "Anio: " << auto1.anio << endl;

    return 0;
}


