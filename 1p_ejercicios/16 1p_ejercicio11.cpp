#include <iostream>
using namespace std;

class Matriz3x3 {
private:
    static const int N = 3;
    int A[N][N];
    int B[N][N];
    int constante;

public:
    // Método para capturar las matrices A, B y la constante desde el teclado
    void capturarDatos() {
        cout << "Ingresa los elementos de la matriz A (3x3):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }

        cout << "Ingresa los elementos de la matriz B (3x3):\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> B[i][j];
            }
        }

        cout << "Ingresa la constante: ";
        cin >> constante;
    }

    // Método para multiplicar la Matriz A por la constante
    void multiplicarConstante() const {
        cout << "\nMatriz A * constante:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << A[i][j] * constante << "\t";
            }
            cout << endl;
        }
    }

    // Método para multiplicar la Matriz A por la Matriz B
    void multiplicarMatrices() const {
        int C[N][N] = {0};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "\nMatriz A * B:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Matriz3x3 matriz;

    matriz.capturarDatos();
    matriz.multiplicarConstante();
    matriz.multiplicarMatrices();

    return 0;
}
