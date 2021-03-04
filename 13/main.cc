#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> big_add(std::vector<int> &a, std::vector<int> &b) {
    // Pad the smaller vector with 0s as needed.
    while (a.size() < b.size()) {
        a.insert(a.begin(), 0);
    }
    while (b.size() < a.size()) {
        b.insert(b.begin(), 0);
    }

    // Add the numbers digit by digit.
    std::vector<int> result;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int digit_sum = a[i] + b[i] + carry;
        if (digit_sum >= 10) {
            carry = digit_sum / 10;
            digit_sum -= 10;
        }
        else {
            carry = 0;
        }
        result.push_back(digit_sum);
    }

    if (carry > 0) {
        result.push_back(carry);
    }

    // Reverse the result since it is backwards.
    std::reverse(result.begin(), result.end());

    return result;
}

int main() {
    std::vector<int> running_sum;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::vector<int> number;
        for (auto c : line) {
            number.push_back(c - '0');
        }

        running_sum = big_add(running_sum,  number);
    }

    for (auto it = running_sum.cbegin(); it != running_sum.cbegin() + 10; ++it) {
        std::cout << *it;
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}