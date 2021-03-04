#include <iostream>
#include <cmath>

bool is_prime(unsigned number) {
    if (number <= 1) {
        return false;
    }

    if (number == 2) {
        return true;
    }

    // Try dividing by 2.
    if (number % 2 == 0) {
        return false;
    }

    // Try dividing by odd numbers up to the square root of the number.
    for (unsigned divisor = 3; divisor < std::ceil(std::sqrt(number)); divisor += 2) {
        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}

unsigned largest_prime_factor(unsigned number) {
    return 0;
}

int main() {
    constexpr unsigned long input_number = 600851475143; 

    // Because we want the largest prime factor, starting from the largest
    // possible candidate and working backward, stopping at the first valid
    // factor is the best way to proceed.
    for (unsigned n = std::ceil(std::sqrt(input_number)); n > 1; --n) {
        if (input_number % n == 0 && is_prime(n)) {
            std::cout << n << std::endl;
            break;
        }
    }

    return EXIT_SUCCESS;
}