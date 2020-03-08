#include <iostream>
#include <utility>
#include <cmath>
#include <fstream>
/*CS375 Programming Assignment #1:
** Task 1: Longest common subsequence problem using
** bottom-up dynamic programming approach
*/



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

            if(x_sequence.size() > 10 || y_sequence.size() > 10) {
                //std::cout << "Error: Sequences must be of length 10 or less." << std::endl;
                //exit(1);
                std::cout << "Greater case: " << std::endl;
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
            }
            else {
                std::cout << "X: <" << x_sequence << ">\n";
                std::cout << "Y: <" << y_sequence << ">\n";
            }
            std::ofstream output(output_path);
        }
        return 0;
}
