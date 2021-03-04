#include <iostream>

// Checks if number is divisible by all numbers in the range
// [start, end].
bool divisible_by_range(unsigned number, unsigned start, unsigned end) {
    for (unsigned divisor = end; divisor >= start; --divisor) {
        if (number % divisor !=0 ) {
            return false;
        }
    }

    return true;
}

int main() {
    unsigned i = 20;
    while (!divisible_by_range(i, 1, 20)) {
        ++i;
    }

    std::cout << i << std::endl;

    return EXIT_SUCCESS;
}