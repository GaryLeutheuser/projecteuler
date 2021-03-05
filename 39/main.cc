#include <iostream>

int number_of_solutions(int perimeter) {
    int count = 0;
    for (int a = 1; a < perimeter; ++a) {
        for (int b = a; (b + a) < perimeter; ++b) {
            int c = perimeter - a - b;
            if (a * a + b * b == c * c) {
                ++count;
            }
        }
    }

    return count;
}

int main() {
    int max_perimeter = 0;
    int max_count = 0;
    for (int perimeter = 1; perimeter <= 1000; ++perimeter) {
        int count = number_of_solutions(perimeter);
        if (count > max_count) {
            max_count = count;
            max_perimeter = perimeter;
        }
    }

    std::cout << max_perimeter << std::endl;

    return EXIT_SUCCESS;
}