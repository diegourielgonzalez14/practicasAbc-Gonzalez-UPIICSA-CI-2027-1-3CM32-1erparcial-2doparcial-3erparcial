
#include <iostream>
using namespace std;

// Funcion con 0 parametros
void calcular() {
    double a, b;

    cout << "Ingresa el primer numero: ";
    cin >> a;

    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "Suma: " << a + b << endl;
    cout << "Resta: " << a - b << endl;
    cout << "Multiplicacion: " << a * b << endl;

    if (b != 0) {
        cout << "Division: " << a / b << endl;
    } else {
        cout << "No se puede dividir entre cero." << endl;
    }
}

// Funcion con 2 parametros
double calcular(double a, double b) {
    return a + b;
}

// Funcion con 3 parametros
double calcular(double a, double b, double c) {
    return a + b + c;
}

int main() {
    int opcion;
    double a, b, c;

    cout << "===== CALCULADORA CON SOBRECARGA =====" << endl;
    cout << "1. Operaciones con 0 parametros" << endl;
    cout << "2. Sumar 2 numeros" << endl;
    cout << "3. Sumar 3 numeros" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            calcular();
            break;

        case 2:
            cout << "Ingresa dos numeros: ";
            cin >> a >> b;
            cout << "Resultado de la suma: "
                 << calcular(a, b) << endl;
            break;

        case 3:
            cout << "Ingresa tres numeros: ";
            cin >> a >> b >> c;
            cout << "Resultado de la suma: "
                 << calcular(a, b, c) << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
    }

    return 0;
}

