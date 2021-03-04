#include <iostream>

int main() {
    std::string input;
    while(std::cin) {
        std::string line;
        std::cin >> line;
        input += line;
    }

    unsigned long max_product = 0;
    for (decltype(input.size()) i = 0; i < input.size() - 13; ++i) {
        unsigned long product = 1;
        for (unsigned j = 0; j < 13; ++j) {
            product *= input[i + j] - '0';
        }
        max_product = std::max(max_product, product);
    }

    std::cout << max_product << std::endl;

    return EXIT_SUCCESS;
}