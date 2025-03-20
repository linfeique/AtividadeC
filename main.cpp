#include <iostream>

#include "Trigonometria.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const Trigonometria trigonometria(45);

    std::cout << "O seno do angulo passado é " << trigonometria.seno() << std::endl;
    std::cout << "O cosseno do angulo passado é " << trigonometria.cosseno() << std::endl;
    std::cout << "A tangente do angulo passado é " << trigonometria.tangente() << std::endl;
    std::cout << "A cotangente do angulo passado é " << trigonometria.cotangente() << std::endl;
    std::cout << "A secante do angulo passado é " << trigonometria.secante() << std::endl;
    std::cout << "A cossecante do angulo passado é " << trigonometria.cossecante() << std::endl;

    return 0;
}