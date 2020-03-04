#include <iostream>
#include <utility>
#include <cmath>
#include <chrono>
#include <fstream>
/*CS375 Programming Assignment #1:
** Task 2: Longest common subsequence problem calculated
** recursively wihthout memoization
*/

auto recursive_lcs(std::string x, std::string y, size_t m, size_t n) {
    if(m == 0 || n == 0) {
        return 0;
    }
    if(x[m-1] == y[n-1]) {
        return 1 + recursive_lcs(x, y, m-1, n-1);
    }
    else {
        return std::max(recursive_lcs(x, y, m-1, n), recursive_lcs(x, y, m, n-1));
    }
}

int main(int argc, char** argv) {
        if(argc < 4 || argc > 4) {
            std::cout << "Usage: program1 <filex.txt> <filey.txt> <output1.txt>" << std::endl;
        }
        else {
            std::cout << "Top-down dynamic programming (with memoization)." << std::endl;
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
            std::ofstream output(output_path);
            //output <<
            if(x_sequence.size() > 10 || y_sequence.size() > 10) {
                //std::cout << "Error: Sequences must be of length 10 or less." << std::endl;
                //exit(1);
                //std::cout << "Greater case: " << std::endl;
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
                auto start = std::chrono::high_resolution_clock::now();
                auto lcs = recursive_lcs(x_sequence, y_sequence, x_sequence.size(), y_sequence.size());
                //std::cout << "LCS length: " << lcs << std::endl;
                output << lcs << std::endl;
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                //std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
                output << duration.count();
            }
            else {
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
                for(size_t i = 0; i < x_sequence.size(); i++) {
                    //TODO: print n*m matrix of LCS lengths
                }
            }
        }
        return 0;
}
