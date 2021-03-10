#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int score_name(std::string name) {
    int score = 0;
    for (auto c : name) {
        score += c - 'A' + 1;
    }

    return score;
}

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
    std::vector<int> scores(names.size());

    // Compute scores.
    std::transform(names.cbegin(), names.cend(), scores.begin(), score_name);
    
    std::cout << "Raw scores computed.\n";

    // Multiply scores by index.
    int i = 1;
    std::for_each(scores.begin(), scores.end(), [&i](int &score){score *= i++;});
    
    // Sum the scores.
    int score_sum = std::accumulate(scores.cbegin(), scores.cend(), 0);

    std::cout << score_sum << std::endl;

    return EXIT_SUCCESS;
}