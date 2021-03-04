#include <iostream>
#include <set>
#include <numeric>

int main() {
    constexpr unsigned upper_bound = 1000;

    // Establish a set to hold multiples of 3 or 5.
    std::set<int> multiples;

    // Compute all multiples of 3 and 5 below 1000, adding to the set.
    unsigned index = 1;
    while (index * 3 < upper_bound) {
        multiples.emplace(index * 3);
        ++index;
    }

    // No compelling end condition for doing 3 and 5 simultaneously,
    // so use 2 loops. 1000 is pretty small.
    index = 1;
    while (index * 5 < upper_bound) {
        multiples.emplace(index * 5);
        ++index;
    }

    // Add all numbers in the set.
    unsigned sum = std::accumulate(multiples.cbegin(), multiples.cend(), 0);
    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}