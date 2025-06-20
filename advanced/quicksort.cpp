// Quick Sort is exceptionally well-suited for arrays, and this is where it truly shines. 
// Its time complexity is O(n log n) on average, making it efficient for large datasets.
// However, in the worst case, it can degrade to O(n^2), especially if the pivot selection is poor.
// STD::sort in C++ uses a hybrid approach, often combining Quick Sort with other algorithms 
// like Heap Sort or Insertion Sort for better performance.
// It is comparison-based and can be implemented using recursion or iteration.

#include <iostream>
#include <vector>
#include <algorithm>

// Partition function for quicksort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // choose the last element as pivot
    // invariant: all elements before index i are less than pivot
    // and all elements after >= i (before j) are greater than or equal to pivot
    // j is the index where the next element to be compared with the pivot
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    // Place the pivot in the correct position
    // i is the index where the pivot will be placed
    std::swap(arr[i], arr[high]);
    return i;
}

// Recursive quicksort
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Original array: ";
    for (int n : arr) std::cout << n << " ";
    std::cout << std::endl;

    // begin and end are inclusive indices
    quicksort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int n : arr) std::cout << n << " ";
    std::cout << std::endl;

    // For comparison, using std::sort
    std::vector<int> arr2 = {10, 7, 8, 9, 1, 5};
    std::sort(arr2.begin(), arr2.end());
    std::cout << "Sorted array using std::sort: ";
    for (int n : arr2) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
/*
Original array: 10 7 8 9 1 5 
Sorted array: 1 5 7 8 9 10 
Sorted array using std::sort: 1 5 7 8 9 10 
*/