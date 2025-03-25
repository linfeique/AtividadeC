#include <iostream>

#include "Trigonometria/Trigonometria.hpp"

void testesTrigonometria() {
    const Trigonometria trigonometria(45);

    std::cout << "O seno do angulo passado é " << trigonometria.seno() << std::endl;
    std::cout << "O cosseno do angulo passado é " << trigonometria.cosseno() << std::endl;
    std::cout << "A tangente do angulo passado é " << trigonometria.tangente() << std::endl;
    std::cout << "A cotangente do angulo passado é " << trigonometria.cotangente() << std::endl;
    std::cout << "A secante do angulo passado é " << trigonometria.secante() << std::endl;
    std::cout << "A cossecante do angulo passado é " << trigonometria.cossecante() << std::endl;

    const Trigonometria trigonometria2(90);

    const Trigonometria somaDeAngulos = trigonometria + trigonometria2;
    const Trigonometria diferencaDeAngulos = trigonometria - trigonometria2;

    std::cout << "O seno da soma de 45 e 90 graus é " << somaDeAngulos.seno() << std::endl;
    std::cout << "O seno da diferença de 45 e 90 graus é " << diferencaDeAngulos.seno() << std::endl;

    std::cout << "O cosseno da soma de 45 e 90 graus é " << somaDeAngulos.cosseno() << std::endl;
    std::cout << "O cosseno da diferença de 45 e 90 graus é " << diferencaDeAngulos.cosseno() << std::endl;
}

int main() {
    testesTrigonometria();

    return 0;
}