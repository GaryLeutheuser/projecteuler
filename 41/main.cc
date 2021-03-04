#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

bool is_prime(long number) {
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
    std::vector<int> number{1};
    long max = 0;

    for (int i = 2; i < 10; ++i) {
        do {
            // Convert to a number.
            long value = 0;
            long multiplier = 1;
            for (int i = number.size() - 1; i >= 0; --i) {
                value += number[i] * multiplier;
                multiplier *= 10;
            }
                
            if (is_prime(value)) {
                max = std::max(max, value);
            }
        }
        while (std::next_permutation(number.begin(), number.end()));

        // Add the next digit.
        number.push_back(i);
    }

    std::cout << max << std::endl;

    return EXIT_SUCCESS;
}