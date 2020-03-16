#include <iostream>
#include <utility>
#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
/*CS375 Programming Assignment #1:
** Task 1: Longest common subsequence problem using
** bottom-up dynamic programming approach
*/

auto bottom_up_lcs(std::string x, std::string y, size_t m, size_t n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    /*int** dp = (int**)malloc(sizeof(int*) * m * n * sizeof(int));*/
    for(size_t i = 1; i <= m; i++) {
        //printf("i = %d", (int)i);
        for(size_t j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char** argv) {
        if(argc < 4 || argc > 4) {
            std::cout << "Usage: program1 <filex.txt> <filey.txt> <output1.txt>" << std::endl;
        }
        else {
            std::cout << "Bottom-up dynamic programming (with no memoization)." << std::endl;
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

            if(x_sequence.size() <= 10 || y_sequence.size() <= 10) {
                //std::cout << "Error: Sequences must be of length 10 or less." << std::endl;
                //exit(1);
                //std::cout << "Greater case: " << std::endl;
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
                std::ofstream output(output_path);
                //auto start = std::chrono::high_resolution_clock::now();
                auto longest = INT_MIN;
                auto big_start = std::chrono::high_resolution_clock::now();
                for(size_t i = 0; i <= x_sequence.size(); i++) {
                    for(size_t j = 0; j <= y_sequence.size(); j++) {
                        auto start = std::chrono::high_resolution_clock::now();
                        auto lcs = bottom_up_lcs(x_sequence, y_sequence, i, j);
                        longest = std::max(longest, lcs);
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                        output << "lcs[" << i << "][" << j << "]: " << lcs << ", duration = " << duration.count() << std::endl;
                    }

                }
                auto big_end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(big_end - big_start);
                output << longest << std::endl << duration.count();
            }
            else {
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
                auto start = std::chrono::high_resolution_clock::now();
                auto lcs = bottom_up_lcs(x_sequence, y_sequence, x_sequence.size(), y_sequence.size());
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::ofstream output(output_path);
                //std::cout << "LCS: " << lcs << std::endl;
                output << lcs << std::endl << duration.count();
                //output << duration.count();
            }
        }
        return 0;
}
