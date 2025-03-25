//
// Created by mathe on 22/03/2025.
//

#ifndef VETORES_HPP
#define VETORES_HPP

class Vetor {
private:
    double* elementos;
    int tamanho;

public:
    explicit Vetor(int n);
    Vetor(const Vetor& outro);

    void carregarDeArquivo(const char* nomeArquivo) const;
    double norma() const;
    Vetor operator+(const Vetor& outro) const;
    Vetor operator-(const Vetor& outro) const;
    double operator*(const Vetor& outro) const;
    Vetor operator^(const Vetor& outro) const;
    double distancia(const Vetor& outro) const;

    static bool saoLinearmenteIndependentes(const Vetor* vetores, int quantidade);
    static bool saoLinearmenteDependentes(const Vetor* vetores, int quantidade);

    int getTamanho() const;
    double getElemento(int i) const;
};

#endif //VETORES_HPP
