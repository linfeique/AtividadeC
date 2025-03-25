//
// Created by mathe on 20/03/2025.
//

#ifndef TRIGONOMETRIA_H
#define TRIGONOMETRIA_H
#include <ostream>
using namespace std;

class Trigonometria {
private:
    double anguloEmGraus;
    double anguloEmRadianos;

    static int calcularFatorial(int numero);
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

    Trigonometria operator+(const Trigonometria &trigonometria) const;
    Trigonometria operator-(const Trigonometria &trigonometria) const;

    friend ostream& operator<<(ostream& os, const Trigonometria& trigonometria);
};
#endif //TRIGONOMETRIA_H
