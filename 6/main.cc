#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<unsigned> numbers(100);
    std::iota(numbers.begin(), numbers.end(), 1);

    // Apply transform to square each element, then sum.
    decltype(numbers) squared_numbers;
    std::transform(numbers.cbegin(),
                    numbers.cend(),
                    std::back_inserter(squared_numbers),
                    [](unsigned n){return n * n;});
    unsigned sum_of_squares = std::accumulate(squared_numbers.cbegin(), squared_numbers.cend(), 0);

    // Sum the elements, then square.
    unsigned sum = std::accumulate(numbers.cbegin(), numbers.cend(), 0);
    unsigned square_of_sum = sum * sum;

    std::cout << square_of_sum - sum_of_squares << std::endl;

    return EXIT_SUCCESS;
}