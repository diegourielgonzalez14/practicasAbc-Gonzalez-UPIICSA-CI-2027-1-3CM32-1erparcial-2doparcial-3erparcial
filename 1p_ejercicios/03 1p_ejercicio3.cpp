
#include <iostream>
using namespace std;

class Calculadora {
private:
    double num1, num2, resultado;
    int opcion;

public:

    void mostrarMenu() {
        cout << "=========================" << endl;
        cout << "       CALCULADORA       " << endl;
        cout << "=========================" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Salir" << endl;
        cout << "=========================" << endl;
    }

    void operar() {
        mostrarMenu();

        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingresa el primer numero: ";
            cin >> num1;

            cout << "Ingresa el segundo numero: ";
            cin >> num2;
        }

        switch (opcion) {

            case 1:
                resultado = num1 + num2;
                cout << "Resultado: " << resultado << endl;
                break;

            case 2:
                resultado = num1 - num2;
                cout << "Resultado: " << resultado << endl;
                break;

            case 3:
                resultado = num1 * num2;
                cout << "Resultado: " << resultado << endl;
                break;

            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    cout << "Resultado: " << resultado << endl;
                } else {
                    cout << "Error: no se puede dividir entre cero." << endl;
                }
                break;

            case 5:
                cout << "Saliendo de la calculadora..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    }
};


int main() {


    Calculadora miCalculadora;

    miCalculadora.operar();

    return 0;
}

