#include <iostream>
#include <vector>

int main() {
    // Array example
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout << "Array elements: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Adding elements to an array (not possible in C++, arrays have fixed size)
    // arr[5] = 6; // This would be an error

    // Removing elements from an array (not possible in C++, arrays have fixed size)

    // Accessing elements
    std::cout << "First element: " << arr[0] << std::endl;
    std::cout << "Last element: " << arr[4] << std::endl;
    std::cout << "Size of array: " << sizeof(arr) / sizeof(arr[0]) << std::endl;
    std::cout << "Max size of array: " << sizeof(arr) / sizeof(arr[0]) << std::endl;
    std::cout << "Is array empty? " << (sizeof(arr) / sizeof(arr[0]) == 0 ? "Yes" : "No") << std::endl;

    std::cout << "Accessing elements using index: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        std::cout << arr[i] << " "; // Indexing
    }
    std::cout << std::endl;

    std::cout << "Accessing elements using std::for_each: ";
    std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), [](int val) {
        std::cout << val << " "; // Using lambda function
    });
    std::cout << std::endl;

    // Resizing an array (not possible in C++, arrays have fixed size). Need a new array 
    int newSize = 10;
    int* newArr = new int[newSize]; // Dynamically allocate a new array
    std::copy(arr, arr + sizeof(arr) / sizeof(arr[0]), newArr); // Copy old array to new array
    std::cout << "After resizing: ";
    for (int i = 0; i < newSize; ++i) {
        std::cout << newArr[i] << " "; 
    }
    std::cout << std::endl;

    // Clearing an array (fill with 0)
    std::fill(arr, arr + sizeof(arr) / sizeof(arr[0]), 0); // Fill with 0
    std::cout << "After clearing: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;

    // Accessing elements using pointer arithmetic
    std::cout << "Accessing elements using pointer arithmetic: ";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        std::cout << *(arr + i) << " "; // Pointer arithmetic
    }
    std::cout << std::endl;


    // Vector example
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Adding elements to a vector
    vec.push_back(60);
    std::cout << "After push_back(60): ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Removing elements from a vector
    vec.pop_back();
    std::cout << "After pop_back(): ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Accessing elements
    std::cout << "First element: " << vec[0] << std::endl;
    std::cout << "Last element: " << vec[vec.size() - 1] << std::endl;
    std::cout << "Size of vector: " << vec.size() << std::endl;
    std::cout << "Capacity of vector: " << vec.capacity() << std::endl;
    std::cout << "Max size of vector: " << vec.max_size() << std::endl;
    std::cout << "Is vector empty? " << (vec.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Front element: " << vec.front() << std::endl;
    std::cout << "Back element: " << vec.back() << std::endl;

    std::cout << "Iterating using range-based for loop: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // auto: type inferred by compiler 

    std::cout << "Iterating using iterator: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating using reverse iterator: ";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating using index: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating using std::for_each: ";
    std::for_each(vec.begin(), vec.end(), [](int val) {
        std::cout << val << " ";
    });
    std::cout << std::endl;


    // Resizing a vector
    vec.resize(10, 0); // Resize to 10 elements, fill with 0
    std::cout << "After resize(10, 0): ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clearing a vector    
    vec.clear();
    std::cout << "After clear(): ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "Size after clear: " << vec.size() << std::endl;
    std::cout << "Capacity after clear: " << vec.capacity() << std::endl;
    std::cout << "Max size after clear: " << vec.max_size() << std::endl;
    std::cout << "Is vector empty after clear? " << (vec.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Front element after clear: " << (vec.empty() ? "N/A" : std::to_string(vec.front())) << std::endl;
    std::cout << "Back element after clear: " << (vec.empty() ? "N/A" : std::to_string(vec.back())) << std::endl;


    return 0;
}