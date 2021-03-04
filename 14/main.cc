#include <iostream>
#include <unordered_map>

std::unordered_map<long, int> chain_lengths;

long next_collatz(long number) {
    if (number % 2 == 0) {
        return number/2;
    }
    else {
        return 3 * number + 1;
    }
}

// int compute_collatz_length(long number) {
//     if (number == 1) {
//         return 1;
//     }
//     else {
//         return 1 + compute_collatz_length(next_collatz(number));
//     }
// }

// int compute_collatz_length(long number, int running_count = 0) {
//     if (number == 1) {
//         return running_count + 1;
//     }
//     else {
//         return compute_collatz_length(next_collatz(number), running_count + 1);    
//     }
// }

int compute_collatz_length(long number) {
    int count = 1;
    while (number != 1) {
        if (number < chain_lengths.size()) {
            if (chain_lengths.find(number) != chain_lengths.end()) {
                return count + chain_lengths[number];
            }
        }
        else {
            number = next_collatz(number);
            count += 1;
        }
    }

    return count;
}

int main() {
    int maximum_length_seed = 0;
    int maximum_length = 0;
    for (int i = 1; i < 1000000; ++i) {
        int current_length = compute_collatz_length(i);
        chain_lengths[i] = current_length;
        if (current_length > maximum_length) {
            maximum_length = current_length;
            maximum_length_seed = i;
        }
    }

    std::cout << maximum_length_seed << "\n";

    return EXIT_SUCCESS;
}