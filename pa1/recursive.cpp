#include <iostream>
#include <utility>
#include <cmath>
#include <chrono>
#include <fstream>
/*CS375 Programming Assignment #1:
** Task 2: Longest common subsequence problem calculated
** recursively wihthout memoization
*/

auto recursive_lcs(std::string x, std::string y, size_t i, size_t j) {
    if(i == 0 || j == 0) {
        return 0;
    }
    if(x[i-1] == y[j-1]) {
        return 1 + recursive_lcs(x, y, i-1, j-1);
    }
    else {
        return std::max(recursive_lcs(x, y, i-1, j), recursive_lcs(x, y, i, j-1));
    }
}

int main(int argc, char** argv) {
        if(argc < 4 || argc > 4) {
            std::cout << "Usage: program2 <filex.txt> <filey.txt> <output1.txt>" << std::endl;
        }
        else {
            std::cout << "Recursive LCS Approach: " << std::endl;
            auto x_path = argv[1];
            auto y_path = argv[2];
            auto output_path = argv[3];

            std::ifstream x(x_path);
            std::ifstream y(y_path);

            //TODO: do work
            std::string x_sequence;
            std::getline(x, x_sequence);
            std::string y_sequence;
            std::getline(y, y_sequence);

            std::cout << "X: <" << x_sequence << ">\n";
            std::cout << "Y: <" << y_sequence << ">\n";
            auto start = std::chrono::high_resolution_clock::now();
            auto lcs = recursive_lcs(x_sequence, y_sequence, x_sequence.size(), y_sequence.size());
            //std::cout << "LCS length: " << lcs << std::endl;
            auto end = std::chrono::high_resolution_clock::now();
            std::ofstream output(output_path);
            output << lcs << std::endl;
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            //std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
            output << duration.count();
        }
        return 0;
}
