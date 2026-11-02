#include <iostream>
#include <cstdlib>
using namespace std;

class CalculadoraBase {
protected:
    int num1, num2;

public:
    CalculadoraBase(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

    int sumar() {
        return num1 + num2;
    }
};

class CalculadoraNueva : public CalculadoraBase {
public:
    CalculadoraNueva(int n1, int n2)
        : CalculadoraBase(n1, n2) {}

    int restar() {
        return num1 - num2;
    }

    // Multiplicacion por sumas sucesivas
    int multiplicar(int a, int b) {
        int resultado = 0;

        for (int i = 0; i < abs(b); i++) {
            resultado += abs(a);
        }

        if ((a < 0) != (b < 0)) {
            resultado = -resultado;
        }

        return resultado;
    }

    // Potencia por multiplicaciones sucesivas
    int potencia(int base, int exponente) {
        int resultado = 1;

        for (int i = 0; i < exponente; i++) {
            resultado *= base;
        }

        return resultado;
    }

    // Division entera por restas sucesivas
    int dividir(int a, int b) {
        if (b == 0) {
            cout << "Error: division por cero.\n";
            return 0;
        }

        int dividendo = abs(a);
        int divisor = abs(b);
        int resultado = 0;

        while (dividendo >= divisor) {
            dividendo -= divisor;
            resultado++;
        }

        if ((a < 0) != (b < 0)) {
            resultado = -resultado;
        }

        return resultado;
    }
};

int main() {
    int n1, n2;

    cout << "--- CALCULADORA NUEVA ---\n";
    cout << "Introduce el primer numero: ";
    cin >> n1;
    cout << "Introduce el segundo numero: ";
    cin >> n2;

    CalculadoraNueva calc(n1, n2);

    cout << "\nResultados:\n";
    cout << "Suma: " << calc.sumar() << endl;
    cout << "Resta: " << calc.restar() << endl;
    cout << "Multiplicacion por sumas sucesivas: "
         << calc.multiplicar(n1, n2) << endl;

    if (n2 >= 0) {
        cout << "Potencia (primer numero elevado al segundo): "
             << calc.potencia(n1, n2) << endl;
    } else {
        cout << "Potencia: el exponente debe ser cero o positivo.\n";
    }

    cout << "Division entera por restas sucesivas: "
         << calc.dividir(n1, n2) << endl;

    return 0;
}
