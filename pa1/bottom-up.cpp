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

auto bottom_up_lcs(std::vector<std::vector<int>>& lenLCS, std::string x, std::string y, size_t m, size_t n) {
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
    lenLCS = dp;
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
                auto big_start = std::chrono::high_resolution_clock::now();
                std::vector<std::vector<int>> dp;
                //std::cout << "Dp: " << dp.size() << std::endl;
                for(auto i = 0; i < (int)x_sequence.size(); i++) {
                    std::vector<int> dp_row(y_sequence.size(), -1);
                    //printf("Size of dp row: %u\n", dp_row.size());
                    dp.push_back(dp_row);
                    //std::cout << "dp size: " << dp.size() << std::endl;
                }
                //std::cout << "Made dp matrix" << std::endl;
                auto longest = bottom_up_lcs(dp, x_sequence, y_sequence, x_sequence.size(), y_sequence.size());
                //std::cout << "Made dp matrix" << std::endl;
                for(size_t i = 0; i <= x_sequence.size(); i++) {
                    output << "lenLCS[" << i << "]: ";
                    for(size_t j = 0; j <= y_sequence.size(); j++) {
                        output << dp[i][j] << " ";
                    }
                    output << std::endl;

                }
                auto big_end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(big_end - big_start);
                output << longest << std::endl << duration.count() << " ms";
            }
            else {
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
                auto start = std::chrono::high_resolution_clock::now();
                std::vector<std::vector<int>> dp;
                //std::cout << "Dp: " << dp.size() << std::endl;
                for(auto i = 0; i < (int)x_sequence.size(); i++) {
                    std::vector<int> dp_row(y_sequence.size(), -1);
                    //printf("Size of dp row: %u\n", dp_row.size());
                    dp.push_back(dp_row);
                    //std::cout << "dp size: " << dp.size() << std::endl;
                }
                auto lcs = bottom_up_lcs(dp, x_sequence, y_sequence, x_sequence.size(), y_sequence.size());
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::ofstream output(output_path);
                //std::cout << "LCS: " << lcs << std::endl;
                output << lcs << std::endl << duration.count() << " ms";
                //output << duration.count();
            }
        }
        return 0;
}
