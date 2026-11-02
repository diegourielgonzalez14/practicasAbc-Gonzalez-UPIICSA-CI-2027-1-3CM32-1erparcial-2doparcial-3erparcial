#include <iostream>
#include <cmath>
using namespace std;

// Funcion recursiva para calcular potencias
double potencia(double base, int exponente) {
    if (exponente == 0) {
        return 1;
    }

    return base * potencia(base, exponente - 1);
}

// Funcion recursiva para contar triangulos
unsigned long long triangulosSierpinski(int n) {
    if (n == 0) {
        return 1;
    }

    return 3 * triangulosSierpinski(n - 1);
}

// Funcion recursiva para contar segmentos
unsigned long long segmentosCantor(int n) {
    if (n == 0) {
        return 1;
    }

    return 2 * segmentosCantor(n - 1);
}

int main() {
    int opcion, n;
    double L;

    do {
        cout << "\n===== MENU DE FRACTALES =====" << endl;
        cout << "1. Triangulo de Sierpinski" << endl;
        cout << "2. Polvo de Cantor" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\nTRIANGULO DE SIERPINSKI" << endl;
            cout << "Numero de iteraciones (0 a 39): ";
            cin >> n;

            if (n < 0 || n > 39) {
                cout << "Iteraciones no validas." << endl;
                continue;
            }

            

            unsigned long long cantidad =
                triangulosSierpinski(n);

            double lado = L / potencia(2, n);
            

            cout << "\n--- RESULTADOS ---" << endl;
            cout << "Iteraciones: " << n << endl;
            cout << "Triangulos creados: " << cantidad << endl;
            
        }
        else if (opcion == 2) {
            cout << "\nPOLVO DE CANTOR" << endl;
            cout << "Numero de iteraciones (0 a 60): ";
            cin >> n;

            if (n < 0 || n > 60) {
                cout << "Iteraciones no validas." << endl;
                continue;
            }

           

            unsigned long long cantidad =
                segmentosCantor(n);

            double longitud = L / potencia(3, n);
            double total = L * potencia(2.0 / 3.0, n);

            cout << "\n--- RESULTADOS ---" << endl;
            cout << "Iteraciones: " << n << endl;
            cout << "Segmentos creados: " << cantidad << endl;
           
        }
        else if (opcion == 3) {
            cout << "Programa terminado." << endl;
        }
        else {
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 3);

    return 0;
}

