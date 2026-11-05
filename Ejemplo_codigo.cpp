#include <iostream>
using namespace std;

int main() {
    // 1. TRABAJO CON VECTORES (1D)
    int n;
    cout << "--- TRABAJO CON VECTORES ---" << endl;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n;

    // Se define un tamaño máximo estático para evitar advertencias de compilador
    int vector[100]; 

    // Llenado del vector
    cout << "\nIngrese los " << n << " elementos del vector:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> vector[i];
    }

    // Impresión del vector
    cout << "\nLos elementos del vector son: [ ";
    for (int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}