#include <iostream>
#include <unordered_map>
#include <cmath>

int count_divisors(long number) {
    // Find divisors up to the square root - for each divisor, add 2 to cover the pair.
    int count = 0;
    for (long candidate_divisor = 1; candidate_divisor < std::ceil(std::sqrt(number)); ++candidate_divisor) {
        if (number % candidate_divisor == 0) {
            count += 2;
        }
    }

    return count;
}

int main() {
    int index = 2;
    long triangle_number = 1;
    while (count_divisors(triangle_number) < 500) {
        triangle_number += index++;
    }

    std::cout << triangle_number << std::endl;

    return EXIT_SUCCESS;
}