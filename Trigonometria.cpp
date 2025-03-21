//
// Created by mathe on 20/03/2025.
//

#include "Trigonometria.h"

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
    return sin(anguloEmRadianos);
}

double Trigonometria::cosseno() const {
    return cos(anguloEmRadianos);
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
