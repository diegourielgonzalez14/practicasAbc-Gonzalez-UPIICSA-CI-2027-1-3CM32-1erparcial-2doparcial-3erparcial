#include <iostream>
#include <algorithm>
using namespace std;

class AnalizadorNumeros {
private:
    static const int TOTAL_NUMEROS = 5;
    double numeros[TOTAL_NUMEROS];
    double suma;

public:
    // Constructor para inicializar los datos
    AnalizadorNumeros() {
        suma = 0;
    }

    // Método para capturar los datos desde el teclado
    void capturarNumeros() {
        cout << "--- ANALIZADOR DE " << TOTAL_NUMEROS << " NUMEROS ---\n";
        for (int i = 0; i < TOTAL_NUMEROS; i++) {
            cout << "Introduce el numero " << (i + 1) << ": ";
            cin >> numeros[i];
            suma += numeros[i];
        }
        // Ordenamos el arreglo de menor a mayor para facilitar max, min y mediana
        sort(numeros, numeros + TOTAL_NUMEROS);
    }

    // Métodos para obtener los cálculos
    double calcularSuma() const {
        return suma;
    }

    double calcularPromedio() const {
        return suma / TOTAL_NUMEROS;
    }

    double obtenerMinimo() const {
        return numeros[0]; // El primero tras ordenar
    }

    double obtenerMaximo() const {
        return numeros[TOTAL_NUMEROS - 1]; // El último tras ordenar
    }

    double obtenerMediana() const {
        return numeros[2]; // El valor central (posición 2) en 5 elementos
    }

    // Método para mostrar todos los resultados ordenados
    void mostrarResultados() const {
        cout << "\n--- RESULTADOS ---\n";
        cout << "Suma: " << calcularSuma() << endl;
        cout << "Promedio (Media aritmetica): " << calcularPromedio() << endl;
        cout << "Mediana: " << obtenerMediana() << endl;
        cout << "Numero maximo: " << obtenerMaximo() << endl;
        cout << "Numero minimo: " << obtenerMinimo() << endl;
    }
};

int main() {
    AnalizadorNumeros analizador;

    analizador.capturarNumeros();
    analizador.mostrarResultados();

    return 0;
}
