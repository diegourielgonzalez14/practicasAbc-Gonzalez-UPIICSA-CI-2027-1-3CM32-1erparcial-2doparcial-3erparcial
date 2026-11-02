#include <iostream>
using namespace std;

// CLASE PADRE
class Calculadora {
protected:
    long long num1, num2;

public:
    void capturar() {
        cout << "Ingresa el primer numero: ";
        cin >> num1;

        cout << "Ingresa el segundo numero: ";
        cin >> num2;
    }

    virtual void operar() {
        cout << "Operacion general" << endl;
    }
};

// CLASE HIJA: MULTIPLICACION
class Multiplicacion : public Calculadora {
public:
    void operar() {
        long long resultado = 0;
        long long a = num1;
        long long b = num2;

        if (b < 0) {
            a = -a;
            b = -b;
        }

        for (long long i = 0; i < b; i++) {
            resultado += a;
        }

        cout << "Resultado de la multiplicacion: "
             << resultado << endl;
    }
};

// CLASE HIJA: POTENCIA
class Potencia : public Calculadora {
public:
    void operar() {
        if (num2 < 0) {
            cout << "El exponente debe ser no negativo." << endl;
            return;
        }

        long long resultado = 1;

        for (long long i = 0; i < num2; i++) {
            long long temporal = 0;

            for (long long j = 0; j < resultado; j++) {
                temporal += num1;
            }

            resultado = temporal;
        }

        cout << "Resultado de la potencia: "
             << resultado << endl;
    }
};

// CLASE HIJA: DIVISION
class Division : public Calculadora {
public:
    void operar() {
        if (num2 == 0) {
            cout << "Error: no se puede dividir entre cero." << endl;
            return;
        }

        long long a = (num1 < 0) ? -num1 : num1;
        long long b = (num2 < 0) ? -num2 : num2;
        long long cociente = 0;

        while (a >= b) {
            a -= b;
            cociente++;
        }

        if ((num1 < 0 && num2 > 0) ||
            (num1 > 0 && num2 < 0)) {
            cociente = -cociente;
        }

        cout << "Cociente entero: " << cociente << endl;
        cout << "Residuo: " << a << endl;
    }
};

// PROGRAMA PRINCIPAL
int main() {
    int opcion;

    Multiplicacion mult;
    Potencia pot;
    Division div;

    do {
        cout << "\n===== CALCULADORA =====" << endl;
        cout << "1. Multiplicacion" << endl;
        cout << "2. Potencia" << endl;
        cout << "3. Division" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mult.capturar();
                mult.operar();
                break;

            case 2:
                pot.capturar();
                pot.operar();
                break;

            case 3:
                div.capturar();
                div.operar();
                break;

            case 4:
                cout << "Fin del programa." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
