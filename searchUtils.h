#ifndef SEARCH_UTILS_H
#define SEARCH_UTILS_H

#include <vector>
#include <numeric> // For std::iota

// --- Linear search ---
// Returns the index of key in arr, or -1 if not found.
// comparisons will contain the number of element comparisons made.
int linearSearch(const std::vector<int>& arr, int key, int& comparisons) {
    comparisons = 0; // Reset comparison counter
    for (int i = 0; i < arr.size(); ++i) {
        comparisons++; // Count each element check as a comparison
        if (arr[i] == key) {
            return i; // Element found
        }
    }
    return -1; // Element not found
}

// --- Iterative binary search ---
// Returns the index of key in arr, or -1 if not found.
// comparisons will contain the number of element comparisons made.
// arr must be sorted in non-decreasing order.
int binarySearch(const std::vector<int>& arr, int key, int& comparisons) {
    comparisons = 0; // Reset comparison counter
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        comparisons++; // Count each loop iteration (mid-element check) as a comparison
        int mid = low + (high - low) / 2; // To prevent overflow

        if (arr[mid] == key) {
            return mid; // Element found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

// --- Generate sorted vector ---
// Returns a vector of n integers sorted in non-decreasing order.
// The numbers are consecutive starting from 1.
std::vector<int> generateSortedVector(int n) {
    std::vector<int> arr(n);
    // Fill the vector with 1, 2, 3, ..., n
    std::iota(arr.begin(), arr.end(), 1); 
    return arr;
}

#endif // SEARCH_UTILS_H