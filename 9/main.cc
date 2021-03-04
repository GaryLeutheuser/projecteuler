#include <iostream>

bool is_pythagorean_triple(unsigned a, unsigned b, unsigned c) {
    return (a * a + b * b == c * c);
}

int main() {
    unsigned a = 1;
    unsigned b = 2;
    unsigned c = 3;

    for (unsigned a = 1; a < 1000; ++a) {
        for (unsigned b = a + 1; b < 1000; ++b) {
            unsigned c = 1000 - (a + b);
            if (a + b + c == 1000) {
                if (is_pythagorean_triple(a, b, c)) {
                    std::cout << a * b * c << std::endl;
                    return EXIT_SUCCESS;
                }
            }
        }
    }

    return EXIT_FAILURE;
}