#include <iostream>
using namespace std;

class Calculadora {
public:
    // Método que recibe los parámetros y retorna la suma
    int sumar(int a, int b) {
        return a + b;
    }
};

int main() {
    int num1, num2;

    cout << "Ingresa el primer numero: ";
    cin >> num1;

    cout << "Ingresa el segundo numero: ";
    cin >> num2;

    // Creamos una instancia (objeto) de la clase Calculadora
    Calculadora calc;

    // Llamamos al método del objeto pasando los parámetros
    int resultado = calc.sumar(num1, num2);

    cout << "La suma es: " << resultado << endl;

    return 0;
}
