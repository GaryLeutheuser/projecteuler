#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

using std::cin;

int main() {
    std::vector<std::vector<int>> matrix;

    std::string line;
    while (std::getline(cin, line)) {
        // Push back new vector for new line.
        matrix.push_back(std::vector<int>());

        // Read in numbers for this line.
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            matrix[matrix.size() - 1].push_back(number);
        }
    }
    
    int max_product = 0;
    
    // Check segments going to the right.
    for (auto rowit = matrix.cbegin(); rowit != matrix.cend(); ++rowit) {
        for (auto it = (*rowit).cbegin(); it + 4 != (*rowit).cend(); ++it) {
            int product = std::accumulate(it, it+4, 1, std::multiplies<int>());
            max_product = std::max(max_product, product);
        }
    }

    // Check segments going down.
    for (decltype(matrix.size()) i = 0; i + 4 < matrix.size(); ++i) {
        for (decltype(matrix[i].size()) j = 0; j < matrix[i].size(); ++j) {
            int product = matrix[i][j] * matrix[i+1][j] * matrix[i+2][j] * matrix[i+3][j];
            max_product = std::max(max_product, product);
        }
    }

    // Check diagonal down and right.
    for (decltype(matrix.size()) i = 0; i + 4 < matrix.size(); ++i) {
        for (decltype(matrix[i].size()) j = 0; j + 4 < matrix[i].size(); ++j) {
            int product = matrix[i][j] * matrix[i+1][j+1] * matrix[i+2][j+2] * matrix[i+3][j+3];
            max_product = std::max(max_product, product);
        }
    }

    // Check diagonal up and right.
     for (decltype(matrix.size()) i = 3; i < matrix.size(); ++i) {
        for (decltype(matrix[i].size()) j = 0; j + 4 < matrix[i].size(); ++j) {
            int product = matrix[i][j] * matrix[i-1][j+1] * matrix[i-2][j+2] * matrix[i-3][j+3];
            max_product = std::max(max_product, product);
        }
    }

    std::cout << max_product << std::endl;

    return EXIT_SUCCESS;
}