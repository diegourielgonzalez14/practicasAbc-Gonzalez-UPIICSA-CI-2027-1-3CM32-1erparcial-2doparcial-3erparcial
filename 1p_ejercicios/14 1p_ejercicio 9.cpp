#include <iostream>
using namespace std;

class Calificaciones {
private:
    double numeros[5];
    double suma;
    double promedio;
    double maximo, minimo;

public:

    void capturar() {
        cout << "Ingresa 5 numeros:" << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> numeros[i];
        }
    }

    void calcularSuma() {
        suma = 0;

        for (int i = 0; i < 5; i++) {
            suma += numeros[i];
        }
    }

    // Metodo para calcular el promedio
    void calcularPromedio() {
        promedio = suma / 5;
    }

    void calcularMaximoMinimo() {
        maximo = numeros[0];
        minimo = numeros[0];

        for (int i = 0; i < 5; i++) {

            if (numeros[i] > maximo) {
                maximo = numeros[i];
            }

            if (numeros[i] < minimo) {
                minimo = numeros[i];
            }
        }
    }

    void mostrarResultados() {
        cout << "\n========== RESULTADOS ==========" << endl;
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Media: " << promedio << endl;
        cout << "Maximo: " << maximo << endl;
        cout << "Minimo: " << minimo << endl;
    }
};

int main() {

    Calificaciones datos;

    datos.capturar();
    datos.calcularSuma();
    datos.calcularPromedio();
    datos.calcularMaximoMinimo();
    datos.mostrarResultados();

    return 0;
}

