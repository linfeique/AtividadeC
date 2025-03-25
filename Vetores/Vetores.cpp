//
// Created by mathe on 22/03/2025.
//

#include "Vetores.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

Vetor::Vetor(const int n) {
    tamanho = n;
    elementos = new double[tamanho];
    for (int i = 0; i < tamanho; i++) {
        elementos[i] = 0.0;
    }
}

Vetor::Vetor(const Vetor& outro) {
    tamanho = outro.tamanho;
    elementos = new double[tamanho];
    for (int i = 0; i < tamanho; i++) {
        elementos[i] = outro.elementos[i];
    }
}

void Vetor::carregarDeArquivo(const char* nomeArquivo) const {
    ifstream arquivo(nomeArquivo);
    double valor;
    int i = 0;
    while (arquivo >> valor && i < tamanho) {
        elementos[i] = valor;
        i++;
    }
    arquivo.close();
}

double Vetor::norma() const {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += elementos[i] * elementos[i];
    }
    return sqrt(soma);
}

Vetor Vetor::operator+(const Vetor& outro) const {
    Vetor resultado(tamanho);
    for (int i = 0; i < tamanho; i++) {
        resultado.elementos[i] = elementos[i] + outro.elementos[i];
    }
    return resultado;
}

Vetor Vetor::operator-(const Vetor& outro) const {
    Vetor resultado(tamanho);
    for (int i = 0; i < tamanho; i++) {
        resultado.elementos[i] = elementos[i] - outro.elementos[i];
    }
    return resultado;
}

double Vetor::operator*(const Vetor& outro) const {
    double produto = 0.0;
    for (int i = 0; i < tamanho; i++) {
        produto += elementos[i] * outro.elementos[i];
    }
    return produto;
}

Vetor Vetor::operator^(const Vetor& outro) const {
    Vetor resultado(tamanho + outro.tamanho);
    for (int i = 0; i < tamanho; i++) {
        resultado.elementos[i] = elementos[i];
    }
    for (int i = 0; i < outro.tamanho; i++) {
        resultado.elementos[i + tamanho] = outro.elementos[i];
    }
    return resultado;
}

double Vetor::distancia(const Vetor& outro) const {
    double soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        const double diferenca = elementos[i] - outro.elementos[i];
        soma += diferenca * diferenca;
    }
    return sqrt(soma);
}

static double calcularDeterminante(double** matriz, const int n) {
    if (n == 1) return matriz[0][0];
    if (n == 2) return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

    double det = 0.0;
    for (int p = 0; p < n; p++) {
        auto** submatriz = new double*[n - 1];
        for (int i = 0; i < n - 1; i++)
            submatriz[i] = new double[n - 1];

        for (int i = 1; i < n; i++) {
            int col_sub = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                submatriz[i - 1][col_sub] = matriz[i][j];
                col_sub++;
            }
        }

        const double cofator = (p % 2 == 0 ? 1 : -1) * matriz[0][p];
        det += cofator * calcularDeterminante(submatriz, n - 1);

        for (int i = 0; i < n - 1; i++)
            delete[] submatriz[i];
        delete[] submatriz;
    }
    return det;
}

bool Vetor::saoLinearmenteIndependentes(const Vetor* vetores, int quantidade) {
    auto** matriz = new double*[quantidade];
    for (int i = 0; i < quantidade; i++) {
        matriz[i] = new double[quantidade];
        for (int j = 0; j < quantidade; j++) {
            matriz[i][j] = vetores[i].getElemento(j);
        }
    }

    const double det = calcularDeterminante(matriz, quantidade);

    for (int i = 0; i < quantidade; i++)
        delete[] matriz[i];
    delete[] matriz;

    return det != 0.0;
}

bool Vetor::saoLinearmenteDependentes(const Vetor* vetores, int quantidade) {
    return !saoLinearmenteIndependentes(vetores, quantidade);
}

int Vetor::getTamanho() const { return tamanho; }
double Vetor::getElemento(const int i) const { return elementos[i]; }