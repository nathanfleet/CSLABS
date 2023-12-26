// "Coffee Shack" driver
// Nathan Fleet
// 10/30/2023

#include <iostream>
#include "Drink.hpp"

using std::cout; using std::cin; using std::endl;

int main() {
    Barista *barista = new JuniorBarista(new SeniorBarista(new Manager));

    for(int i = 0; i < 4; ++i) {
        barista->takeOrder();
    }

    delete barista;
    return 0;
}