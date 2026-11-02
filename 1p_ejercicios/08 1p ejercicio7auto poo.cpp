
#include <iostream>
using namespace std;

class Auto {
private:
    double precio;
    int anio;

public:
    void capturar() {
        cout << "Ingresa el precio del auto: ";
        cin >> precio;

        cout << "Ingresa el anio del auto: ";
        cin >> anio;
    }

    void mostrar() {
        cout << "\n=== DATOS DEL AUTO ===" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Anio: " << anio << endl;
    }
};

int main() {
    Auto auto1;

    auto1.capturar();
    auto1.mostrar();

    return 0;
}

