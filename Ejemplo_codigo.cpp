#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm> // Para std::max

using namespace std;

// Función auxiliar para imprimir cualquier vector de doubles
void imprimirVector(const string& titulo, const vector<double>& vec) {
    cout << titulo << ": [ ";
    for (double val : vec) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Nombres de los estudiantes (ahora tenemos 5)
    vector<string> estudiantes = {"Ana", "Carlos", "Luis", "Maria", "Sofia"};

    // Matriz ampliada (5 estudiantes x 3 evaluaciones)
    vector<vector<double>> notas = {
        {4.5, 3.8, 5.0},  // Ana
        {3.0, 3.5, 4.0},  // Carlos
        {5.0, 4.8, 4.9},  // Luis
        {2.5, 3.2, 3.8},  // Maria
        {4.0, 4.2, 4.5}   // Sofia
    };

    // Vector de pesos (30%, 30%, 40%)
    vector<double> pesos = {0.30, 0.30, 0.40};

    size_t num_estudiantes = notas.size();
    size_t num_evaluaciones = pesos.size();

    // --- VECTORES RESULTANTES ---
    vector<double> notas_finales(num_estudiantes, 0.0);
    vector<double> promedio_por_eval(num_evaluaciones, 0.0);
    vector<double> nota_maxima_est(num_estudiantes, 0.0);

    // 1. Calcular notas finales y nota máxima por estudiante
    for (size_t i = 0; i < num_estudiantes; i++) {
        double max_nota = 0.0;
        for (size_t j = 0; j < num_evaluaciones; j++) {
            // Multiplicación matriz * vector
            notas_finales[i] += notas[i][j] * pesos[j];
            
            // Acumular suma por columna (evaluación)
            promedio_por_eval[j] += notas[i][j];

            // Buscar la nota más alta del estudiante
            if (notas[i][j] > max_nota) {
                max_nota = notas[i][j];
            }
        }
        nota_maxima_est[i] = max_nota;
    }

    // 2. Finalizar el cálculo del promedio por evaluación dividiendo entre el total de estudiantes
    for (size_t j = 0; j < num_evaluaciones; j++) {
        promedio_por_eval[j] /= num_estudiantes;
    }

    // --- IMPRIMIR RESULTADOS ---
    cout << fixed << setprecision(2);
    imprimirVector("1. Notas finales ", notas_finales);
    imprimirVector("2. Promedio por evaluacion ", promedio_por_eval);
    imprimirVector("3. Nota maxima por alumno  ", nota_maxima_est);

    cout << "\n Resumen Individual por estudiante" << endl;
    for (size_t i = 0; i < num_estudiantes; i++) {
        cout << estudiantes[i] << " -> Final: " << notas_finales[i] 
             << " | Mejor nota: " << nota_maxima_est[i] << endl;
    }

    return 0;
}
