#include <iostream>
#include <vector>
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
    for (unsigned divisor = 3; divisor < std::ceil(std::sqrt(number)) + 1; divisor += 2) {
        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<unsigned> primes;
    unsigned i = 2;
    while (primes.size() != 10001) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
        ++i;
    }

    std::cout << primes[primes.size() - 1] << std::endl;

    return EXIT_SUCCESS;
}