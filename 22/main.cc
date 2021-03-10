#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // Get unchanged input.
    constexpr int BUFFER_SIZE = 65536;
    char input[BUFFER_SIZE] = "";
    std::ifstream ifs;
    ifs.open("input.txt");
    ifs.getline(input, BUFFER_SIZE);

    // Tokenize on comma.
    char *pch = strtok(input, ",");
    std::vector<std::string> names;
    while (pch != nullptr) {
        // Note - moving the terminator and starting
        // at the second character is simply a means
        // to avoid the quote characters.
        pch[std::strlen(pch) - 1] = '\0';
        names.push_back(std::string(&pch[1]));

        pch = std::strtok(nullptr, ",");
    }

    // Sort the names.
    std::sort(names.begin(), names.end());

    // Score the names.
    int score_sum = 0;
    int i = 1;
    
    for (auto it = names.cbegin(); it != names.cend(); ++it) {
        int name_score = 0;
        for (auto c : *it) {
            name_score += c - 'A' + 1;
        }
        name_score *= i++;
        score_sum += name_score;
    }

    std::cout << score_sum << std::endl;

    return EXIT_SUCCESS;
}