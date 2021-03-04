#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Compute Fibonacci terms with values under a given amount.
void fibonacci(unsigned upper_bound, std::vector<unsigned> &output) {
    // Initialize with first two terms.
    output.push_back(0);
    output.push_back(1);

    // Compute the rest of the terms one at a time.
    unsigned next_term = 1;
    decltype(output.size()) index = 2;
    while (next_term < upper_bound) {
        output.push_back(next_term);
        next_term = output[index] + output[index-1];
        ++index;
    }
}

int main() {
    // Compute Fibonacci numbers below four million.
    std::vector<unsigned> fib_terms;
    fibonacci(4000000, fib_terms);

    // Remove odd values.
    fib_terms.erase(std::remove_if(fib_terms.begin(),
                                    fib_terms.end(),
                                    [](unsigned n){return n % 2 != 0;}),  
                    fib_terms.end());

    // Sum the even terms.
    unsigned sum = std::accumulate(fib_terms.cbegin(), fib_terms.cend(), 0);
    std::cout << sum << std::endl;

    return EXIT_SUCCESS;
}