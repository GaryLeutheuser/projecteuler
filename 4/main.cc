#include <iostream>
#include <string>
#include <stack>

bool is_palindrome(unsigned number) {
    std::string number_string = std::to_string(number);
    return (std::equal(number_string.begin(), number_string.begin() + number_string.size()/2, number_string.rbegin()));
}

int main() {
    // Compute all possible products of 2 three digit numbers.
    unsigned max_palindrome = 0;
    for (unsigned a = 100; a <= 999; ++a) {
        for (unsigned b = a; b <= 999; ++b) {
            unsigned product = a * b;
            if (is_palindrome(product)) {
                max_palindrome = std::max(max_palindrome, product);
            }
        }
    }

    std::cout << max_palindrome << std::endl;

    return EXIT_SUCCESS;
}