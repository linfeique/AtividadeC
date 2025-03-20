//
// Created by mathe on 20/03/2025.
//

#ifndef TRIGONOMETRIA_H
#define TRIGONOMETRIA_H
#include <ostream>
#include <optional>
using namespace std;

class Trigonometria {
private:
    double anguloEmGraus;
    double anguloEmRadianos;

public:
    // Usando o explicit aqui para evitar conversão de dado implícita
    explicit Trigonometria(double angulo);

    void definirAngulo(double angulo);
    double seno() const;
    double cosseno() const;
    double tangente() const;
    double cotangente() const;
    double secante() const;
    double cossecante() const;

    Trigonometria operator+(const Trigonometria &trigonometria);
    Trigonometria operator-(const Trigonometria &trigonometria);

    friend ostream& operator<<(ostream& os, const Trigonometria& trigonometria);
};
#endif //TRIGONOMETRIA_H
