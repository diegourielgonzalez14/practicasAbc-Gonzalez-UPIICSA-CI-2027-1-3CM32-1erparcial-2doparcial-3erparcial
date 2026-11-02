#include <iostream>
#include <vector>
#include <limits>

// Nuevo tipo de dato (Estructura personalizada en PE)
struct Registro {
    int clave;
    float valor;
};

// ---------------------------------------------------------
// 1. MERGE SORT INDIRECTO PARA ENTEROS
// ---------------------------------------------------------
void mergeIndirectoEnteros(const std::vector<int>& datos, std::vector<int>& indices, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = indices[izq + i];
    for (int j = 0; j < n2; j++) R[j] = indices[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        // Comparación indirecta sobre el vector de datos usando los índices
        if (datos[L[i]] <= datos[R[j]]) {
            indices[k++] = L[i++];
        } else {
            indices[k++] = R[j++];
        }
    }
    while (i < n1) indices[k++] = L[i++];
    while (j < n2) indices[k++] = R[j++];
}

void mergeSortIndirectoEnteros(const std::vector<int>& datos, std::vector<int>& indices, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSortIndirectoEnteros(datos, indices, izq, medio);
        mergeSortIndirectoEnteros(datos, indices, medio + 1, der);
        mergeIndirectoEnteros(datos, indices, izq, medio, der);
    }
}

// ---------------------------------------------------------
// 2. MERGE SORT INDIRECTO PARA CARACTERES
// ---------------------------------------------------------
void mergeIndirectoCaracteres(const std::vector<char>& datos, std::vector<int>& indices, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = indices[izq + i];
    for (int j = 0; j < n2; j++) R[j] = indices[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        // Comparación indirecta sobre el vector de caracteres
        if (datos[L[i]] <= datos[R[j]]) {
            indices[k++] = L[i++];
        } else {
            indices[k++] = R[j++];
        }
    }
    while (i < n1) indices[k++] = L[i++];
    while (j < n2) indices[k++] = R[j++];
}

void mergeSortIndirectoCaracteres(const std::vector<char>& datos, std::vector<int>& indices, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSortIndirectoCaracteres(datos, indices, izq, medio);
        mergeSortIndirectoCaracteres(datos, indices, medio + 1, der);
        mergeIndirectoCaracteres(datos, indices, izq, medio, der);
    }
}

// ---------------------------------------------------------
// 3. MERGE SORT INDIRECTO PARA NUEVO TIPO DE DATO (Registro)
// ---------------------------------------------------------
void mergeIndirectoRegistros(const std::vector<Registro>& datos, std::vector<int>& indices, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = indices[izq + i];
    for (int j = 0; j < n2; j++) R[j] = indices[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        // Comparación indirecta por la clave del Registro
        if (datos[L[i]].clave <= datos[R[j]].clave) {
            indices[k++] = L[i++];
        } else {
            indices[k++] = R[j++];
        }
    }
    while (i < n1) indices[k++] = L[i++];
    while (j < n2) indices[k++] = R[j++];
}

void mergeSortIndirectoRegistros(const std::vector<Registro>& datos, std::vector<int>& indices, int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSortIndirectoRegistros(datos, indices, izq, medio);
        mergeSortIndirectoRegistros(datos, indices, medio + 1, der);
        mergeIndirectoRegistros(datos, indices, izq, medio, der);
    }
}

// ---------------------------------------------------------
// MENÚ INTERACTIVO PRINCIPAL (PE)
// ---------------------------------------------------------
int main() {
    int opcion = 0;
    do {
        std::cout << "\n===================================================\n";
        std::cout << "   MERGE SORT INDIRECTO (PE) - DIVERSOS TIPOS DE DATO\n";
        std::cout << "===================================================\n";
        std::cout << "1. Ordenamiento indirecto de Enteros\n";
        std::cout << "2. Ordenamiento indirecto de Caracteres\n";
        std::cout << "3. Ordenamiento indirecto de Nuevo Tipo de Dato (Registro)\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) break;

        if (opcion == 1) {
            int n;
            std::cout << "Cantidad de enteros: ";
            std::cin >> n;
            if (n <= 0) continue;

            std::vector<int> datos(n);
            std::vector<int> indices(n);

            for (int i = 0; i < n; i++) {
                std::cout << "Entero [" << i << "]: ";
                std::cin >> datos[i];
                indices[i] = i; // Arreglo auxiliar de índices original
            }

            mergeSortIndirectoEnteros(datos, indices, 0, n - 1);

            std::cout << "\n--- DATOS ORIGINALES (SIN MOVER) ---\n[ ";
            for (int i = 0; i < n; i++) std::cout << datos[i] << " ";
            std::cout << "]\n";

            std::cout << "--- ÍNDICES ORDENADOS ---\n[ ";
            for (int i = 0; i < n; i++) std::cout << indices[i] << " ";
            std::cout << "]\n";

            std::cout << "--- DATOS ACCEDIDOS DE FORMA INDIRECTA (ORDENADOS) ---\n[ ";
            for (int i = 0; i < n; i++) std::cout << datos[indices[i]] << " ";
            std::cout << "]\n";
        }
        else if (opcion == 2) {
            int n;
            std::cout << "Cantidad de caracteres: ";
            std::cin >> n;
            if (n <= 0) continue;

            std::vector<char> datos(n);
            std::vector<int> indices(n);

            for (int i = 0; i < n; i++) {
                std::cout << "Caracter [" << i << "]: ";
                std::cin >> datos[i];
                indices[i] = i;
            }

            mergeSortIndirectoCaracteres(datos, indices, 0, n - 1);

            std::cout << "\n--- DATOS ORIGINALES (SIN MOVER) ---\n[ ";
            for (int i = 0; i < n; i++) std::cout << datos[i] << " ";
            std::cout << "]\n";

            std::cout << "--- ÍNDICES ORDENADOS ---\n[ ";
            for (int i = 0; i < n; i++) std::cout << indices[i] << " ";
            std::cout << "]\n";

            std::cout << "--- DATOS ACCEDIDOS DE FORMA INDIRECTA (ORDENADOS) ---\n[ ";
            for (int i = 0; i < n; i++) std::cout << datos[indices[i]] << " ";
            std::cout << "]\n";
        }
        else if (opcion == 3) {
            int n;
            std::cout << "Cantidad de registros: ";
            std::cin >> n;
            if (n <= 0) continue;

            std::vector<Registro> datos(n);
            std::vector<int> indices(n);

            for (int i = 0; i < n; i++) {
                std::cout << "\nRegistro " << i << ":\n";
                std::cout << "  Clave (entero): ";
                std::cin >> datos[i].clave;
                std::cout << "  Valor (float): ";
                std::cin >> datos[i].valor;
                indices[i] = i;
            }

            mergeSortIndirectoRegistros(datos, indices, 0, n - 1);

            std::cout << "\n--- REGISTROS ACCEDIDOS INDIRECTAMENTE (ORDENADOS POR CLAVE) ---\n";
            for (int i = 0; i < n; i++) {
                int idx = indices[i];
                std::cout << "Posición ordenada " << i << " -> Índice original " << idx 
                          << " | Clave: " << datos[idx].clave << " | Valor: " << datos[idx].valor << "\n";
            }
        }
        else if (opcion == 4) {
            std::cout << "Saliendo...\n";
        }
        else {
            std::cout << "Opción no válida.\n";
        }

    } while (opcion != 4);

    return 0;
}
