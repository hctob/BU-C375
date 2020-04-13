#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include "quicksort.cpp"

//Insertion, merge, quick, and randomized quicksort

namespace Driver {
    int* generate_rand_array(size_t size) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, size / 2);
        auto gen_rand = std::bind(distribution, generator);
        //std::vector<int> qs_array(end);
        int* new_array = new int[size];
        for(size_t i = 0; i < size; i++) {
            new_array[i] = gen_rand();
        }
        /*std::cout << "Array of size " << size << " before sort: ";
        for (auto i = 0; i < (int)size; i++) {
            std::cout << new_array[i] << " ";
        }*/
        std::cout << std::endl;
        return new_array;
    }

    template <typename ResultType, typename ...ArgumentTypes>
    auto do_action(ResultType&& f, ArgumentTypes&&... args) {
        auto func = std::move(f);

        auto start = std::chrono::steady_clock::now(); //save the current time as the 'start' timestamp
        func(args...);
        auto end = std::chrono::steady_clock::now(); //save the current time as the 'end' timestamp

        std::chrono::duration<double> diff = (end - start); //save the difference between the end and start as 'diff'

        return diff.count(); //return diff (the approximate number of seconds to execute the algorithm with the specified args)
    }

    void go(std::string type) {
        for(size_t i = 1; i < 8; i++) {
            size_t bound = std::pow(10, i);
            auto arr = generate_rand_array(bound);

            //first argument of do-action is the sort you want to test the performance of
            //next arguments are the arguments of the sort function
            if(type == "quicksort") {
                    auto arr = generate_rand_array(bound);
                    auto ret = Driver::do_action(QS::quicksort, arr, 0, bound);
                    std::cout << "Time to " << type << " array of " << bound << " elements: " << ret << " seconds";
                    free(arr);
            }
        }
    }
}


int main(int argc, char** argv) {
    /*For each sorting function, call Driver::do("name of sort");*/

    //Insertion sort

    //Merge sort

    //Quicksort
    Driver::go("quicksort");

    //Randomized quicksort



    return 0;
}
