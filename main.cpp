#include <iostream>

#include "Trigonometria.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    const Trigonometria trigonometria(45);

    std::cout << "O seno do angulo passado é " << trigonometria.seno() << std::endl;

    return 0;
}