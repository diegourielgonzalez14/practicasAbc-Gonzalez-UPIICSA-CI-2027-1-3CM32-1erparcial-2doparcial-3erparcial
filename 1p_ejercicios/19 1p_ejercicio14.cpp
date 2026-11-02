#include <iostream>
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

    // Multiplicacion recursiva por sumas sucesivas
    int multiplicar(int a, int b) {
        if (b == 0) {
            return 0;
        }
        if (b < 0) {
            return -multiplicar(a, -b);
        }
        return a + multiplicar(a, b - 1);
    }

    // Potencia recursiva por multiplicaciones sucesivas
    int potencia(int base, int exponente) {
        if (exponente == 0) {
            return 1;
        }
        if (exponente < 0) {
            cout << "Error: el exponente debe ser cero o positivo.\n";
            return 0;
        }
        return base * potencia(base, exponente - 1);
    }

    // Division entera recursiva por restas sucesivas
    int dividir(int a, int b) {
        if (b == 0) {
            cout << "Error: division por cero.\n";
            return 0;
        }

        int resultado = dividirPositivo(
            (a < 0 ? -a : a),
            (b < 0 ? -b : b)
        );

        if ((a < 0) != (b < 0)) {
            resultado = -resultado;
        }

        return resultado;
    }

private:
    int dividirPositivo(int dividendo, int divisor) {
        if (dividendo < divisor) {
            return 0;
        }
        return 1 + dividirPositivo(dividendo - divisor, divisor);
    }

public:
    // Factorial recursivo: n! = n * (n-1)!
    int factorial(int n) {
        if (n < 0) {
            cout << "Error: el factorial no existe para negativos.\n";
            return 0;
        }
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }

    // Fibonacci recursivo
    int fibonacci(int n) {
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main() {
    int n1, n2, n;

    cout << "--- CALCULADORA RECURSIVA ---\n";
    cout << "Introduce el primer numero: ";
    cin >> n1;
    cout << "Introduce el segundo numero: ";
    cin >> n2;

    CalculadoraNueva calc(n1, n2);

    cout << "\nResultados de la calculadora:\n";
    cout << "Suma: " << calc.sumar() << endl;
    cout << "Resta: " << calc.restar() << endl;
    cout << "Multiplicacion recursiva: "
         << calc.multiplicar(n1, n2) << endl;

    if (n2 >= 0) {
        cout << "Potencia recursiva: "
             << calc.potencia(n1, n2) << endl;
    } else {
        cout << "Potencia: el exponente debe ser cero o positivo.\n";
    }

    cout << "Division entera recursiva: "
         << calc.dividir(n1, n2) << endl;

    cout << "\nIntroduce un numero para factorial y Fibonacci: ";
    cin >> n;

    if (n >= 0 && n <= 12) {
        cout << "Factorial de " << n << ": "
             << calc.factorial(n) << endl;
        cout << "Fibonacci en la posicion " << n << ": "
             << calc.fibonacci(n) << endl;
    } else if (n > 12) {
        cout << "El numero es muy grande para mostrar resultados seguros con int.\n";
    } else {
        cout << "Factorial y Fibonacci requieren un numero no negativo.\n";
    }

    return 0;
}
