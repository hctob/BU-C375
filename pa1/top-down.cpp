#include <iostream>
#include <utility>
#include <cmath>
#include <chrono>
#include <cstring>
#include <fstream>
#include <vector>
/*CS375 Programming Assignment #1:
** Task 3: Longest common subsequence problem using
** top-down dynamic programming approach with memoization
*/

const int MAXIMUM_LENGTH = 100;

auto top_down_lcs(std::string x, std::string y, size_t m, size_t n, std::vector<std::vector<int>>& dp) {
    //printf("entering function\n");
    if(n == 0 || m == 0) return 0; //recusive base case
    //printf("after base case\n");
    //cached value - if it exists, do not perform a recusive call
    if(dp.at(m-1).at(n-1) != -1) {
        //printf("cached value");
        return dp[m-1][n-1];
    }
    //otherwise, no previously computed LCS, so should do a recursive call to generate LCS(m, n)
    if(x[m-1] == y[n-1]) {
        //printf("calculating new cached value");
        dp[m-1][n-1] = 1 + top_down_lcs(x, y, m-1, n-1, dp);
        return dp[m-1][n-1];
    }
    else {
        dp[m-1][n-1] = std::max(top_down_lcs(x, y, m-1, n, dp), top_down_lcs(x, y, m, n-1, dp));
        return dp[m-1][n-1];
    }

}

int main(int argc, char** argv) {
        if(argc < 4 || argc > 4) {
            std::cout << "Usage: program3 <filex.txt> <filey.txt> <output1.txt>" << std::endl;
        }
        else {
            std::cout << "Top-down Memoization Approach: " << std::endl;
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
            //int dp[x_sequence.size()][MAXIMUM_LENGTH];
            //memset(dp, -1, sizeof(dp));
            //int** dp = (int**)malloc(sizeof(int) * x_sequence.size() * MAXIMUM_LENGTH);
            std::vector<std::vector<int>> dp;
            //std::cout << "Dp: " << dp.size() << std::endl;
            for(auto i = 0; i < (int)x_sequence.size(); i++) {
                std::vector<int> dp_row(MAXIMUM_LENGTH, -1);
                //printf("Size of dp row: %u\n", dp_row.size());
                dp.push_back(dp_row);
                //std::cout << "dp size: " << dp.size() << std::endl;
            }
            //std::cout << dp[0].size() << std::endl;
            /*for(int i = 0; i < 100; i++) {
                std::cout << dp[0].at(i);
            }*/
            //printf("before");
            auto lcs = top_down_lcs(x_sequence, y_sequence, x_sequence.size(), y_sequence.size(), dp);
            //printf("after");
            //std::cout << "LCS length: " << lcs << std::endl;
            auto end = std::chrono::high_resolution_clock::now();
            std::ofstream output(output_path);
            output << lcs << std::endl;
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            //std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
            output << duration.count() << " ms";
        }
        return 0;
}
