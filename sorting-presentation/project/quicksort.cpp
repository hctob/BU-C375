#include <iostream>
#include <chrono>
#include <random>
#include <bits/stdc++.h>
#include <functional>

namespace QS {

    int partition(int* arr, size_t start, size_t end) {
        int pivot = arr[end];
        size_t i = start - 1;

        //from the start index to the end index of the partition
        for(size_t j = start; j <= end - 1; j++) {
            if(arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[end]);
        return i + 1;
    }
    void quicksort(int* arr, size_t start, size_t end) {
        if(start < end) {
            //get pivot point for quicksort based on relative start and end points
            int p = partition(arr, start, end);
            //std::cout << "P = " << p << std::endl;
            //perform quicksort on the left partition
            quicksort(arr, start, p - 1);
            //perform quicksort on the right partition
            quicksort(arr, p + 1, end - 1);
        }
    }
}
