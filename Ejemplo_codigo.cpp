#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    // Matriz (3 estudiantes x 3 evaluaciones) usando vector de vectores
    vector<vector<double>> notas = {
        {4.5, 3.8, 5.0},  // Estudiante 1
        {3.0, 3.5, 4.0},  // Estudiante 2
        {5.0, 4.8, 4.9}   // Estudiante 3
    };

    // Vector de pesos (30%, 30%, 40%)
    vector<double> pesos = {0.30, 0.30, 0.40};

    // Vector resultante inicializado con el tamaño de los estudiantes en 0.0
    vector<double> notas_finales(notas.size(), 0.0);

    // Multiplicación de matriz por vector
    for (size_t i = 0; i < notas.size(); i++) {
        for (size_t j = 0; j < pesos.size(); j++) {
            notas_finales[i] += notas[i][j] * pesos[j];
        }
    }

    // Imprimir el vector resultante con 2 decimales
    cout << fixed << setprecision(2);
    cout << "Vector de notas finales: [ ";
    for (double nota : notas_finales) {
        cout << nota << " ";
    }
    cout << "]" << endl;

    return 0;
}
