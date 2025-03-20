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
    // estarei fazendo o uso das Séries de Taylor para realizar o calculo do seno

    double seno = 0.0;
    double termo = anguloEmGraus;

    for (int i = 1; i <= 10; i++ ) {
        seno += termo;
        termo *= -(anguloEmGraus * anguloEmGraus / (2 * i * (2 * i + 1)));
    }

    return seno;
}

