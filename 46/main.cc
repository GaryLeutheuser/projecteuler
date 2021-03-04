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

bool has_property(int number) {
    // Subtract 2 * square s.t. result is not greater than the number..
    for (int i = 1; i*i*2 <= number; ++i) {
        int difference = number - i*i*2;
        if (is_prime(difference)) {
            return true;
        }
    }

    return false;
}

int main() {
    int i = 9;
    while (true) {
        if (is_prime(i)) {
            i += 2;
            continue;
        }
        else if (!has_property(i)) {
            break;
        }
        else {
            i += 2;
        }
    }

    std::cout << i << std::endl;

    return EXIT_SUCCESS;
}