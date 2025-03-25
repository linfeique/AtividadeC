//
// Created by mathe on 20/03/2025.
//

#include "Trigonometria.hpp"

#include <cmath>

Trigonometria::Trigonometria(const double angulo) {
    anguloEmGraus = angulo;
    anguloEmRadianos = angulo * M_PI / 180;
}

void Trigonometria::definirAngulo(const double angulo) {
    anguloEmGraus = angulo;
    anguloEmRadianos = angulo * M_PI / 180;
}

double Trigonometria::seno() const {
    double seno = 0.0;
    for (int n = 0; n < 10; ++n) {
        const int expoente = 2 * n + 1;
        const double termo = (pow(-1, n) * pow(anguloEmRadianos, expoente)) / calcularFatorial(expoente);
        seno += termo;
    }
    return seno;
}

double Trigonometria::cosseno() const {
    double cosseno = 0.0;
    for (int n = 0; n < 10; ++n) {
        const int expoente = 2 * n;
        const double termo = (pow(-1, n) * pow(anguloEmRadianos, expoente)) / calcularFatorial(expoente);
        cosseno += termo;
    }
    return cosseno;
}

double Trigonometria::tangente() const {
    return seno() / cosseno();
}

double Trigonometria::cotangente() const {
    return 1 / tangente();
}

double Trigonometria::secante() const {
    return 1 / cosseno();
}

double Trigonometria::cossecante() const {
    return 1 / seno();
}

Trigonometria Trigonometria::operator+(const Trigonometria &trigonometria) const {
    const double novoSeno = this->seno() * trigonometria.cosseno() + this->cosseno() * trigonometria.seno();
    const double novoCosseno = this->cosseno() * trigonometria.cosseno() - this->seno() * trigonometria.seno();

    return Trigonometria(atan2(novoSeno, novoCosseno) * 180.0 / M_PI);
}

Trigonometria Trigonometria::operator-(const Trigonometria &trigonometria) const {
    const double novoSeno = this->seno() * trigonometria.cosseno() - this->cosseno() * trigonometria.seno();
    const double novoCosseno = this->cosseno() * trigonometria.cosseno() + this->seno() * trigonometria.seno();

    return Trigonometria(atan2(novoSeno, novoCosseno) * 180.0 / M_PI);
}

int Trigonometria::calcularFatorial(const int numero) {
    int fatorial = 1;

    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }

    return fatorial;
}
