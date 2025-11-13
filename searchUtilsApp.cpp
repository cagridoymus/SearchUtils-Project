#include <iostream>
#include "searchUtils.h"

int main() {
    int n;
    // Get vector size from user
    std::cout << "Enter the size of the vector: ";
    std::cin >> n;

    // Create a sorted vector from 1 to n
    auto arr = generateSortedVector(n);

    int linComp = 0;
    int binComp = 0;

    // Worst case scenario: search for an element not in the vector (n+1)
    int key = n + 1;

    // Perform linear search
    int linIndex = linearSearch(arr, key, linComp);

    // Perform binary search
    int binIndex = binarySearch(arr, key, binComp);

    // Print the results
    std::cout << "--- Worst Case (Key = " << key << ") ---" << "\n";
    std::cout << "Linear search: vector size = " << n
        << ", comparisons = " << linComp << "\n";
    std::cout << "Binary search: vector size = " << n
        << ", comparisons = " << binComp << "\n";

    return 0;
}