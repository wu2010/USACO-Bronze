#include <iostream>
#include <memory>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr; // Points to the first element

    std::cout << "Pointer arithmetic demonstration:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Address: " << (p + i)
                  << ", Value: " << *(p + i) << std::endl;
    }

    // Increment pointer
    p++; // Now points to arr[1]
    std::cout << "\nAfter incrementing pointer:\n";
    std::cout << "Address: " << p << ", Value: " << *p << std::endl;

    // Decrement pointer
    p--; // Back to arr[0]
    std::cout << "After decrementing pointer:\n";
    std::cout << "Address: " << p << ", Value: " << *p << std::endl;

    // Difference between pointers
    int* pEnd = arr + 4; // Points to arr[4]
    std::cout << "\nDifference between pointers (pEnd - arr): "
              << (pEnd - arr) << std::endl; // Should print 4

    // More examples with increment and *
    p = arr; // Reset pointer to start
    std::cout << "\nMix of increment and *:\n";
    std::cout << "Value at *p: " << *p << std::endl;         // 10
    std::cout << "Value at *++p: " << *++p << std::endl;     // 20 (p moves to arr[1], then dereferenced)
    std::cout << "Value at *p++: " << *p++ << std::endl;     // 20 (dereference arr[1], then p moves to arr[2])
    std::cout << "Value at *p: " << *p << std::endl;         // 30

    // Demonstrate -- and *
    std::cout << "Value at *--p: " << *--p << std::endl;     // 20 (p moves to arr[1], then dereferenced)
    std::cout << "Value at *p--: " << *p-- << std::endl;     // 20 (dereference arr[1], then p moves to arr[0])
    std::cout << "Value at *p: " << *p << std::endl;         // 10


    // Demonstrate unique_ptr with auto
    // Using std::unique_ptr to manage dynamic memory
    auto uniqueArr = std::make_unique<int[]>(5);
    uniqueArr[0] = 100;
    uniqueArr[1] = 200;
    uniqueArr[2] = 300;
    uniqueArr[3] = 400;
    uniqueArr[4] = 500;

    std::cout << "\nunique_ptr demonstration:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "uniqueArr[" << i << "] = " << uniqueArr[i] << std::endl;
    }

    // unique_ptr automatically deletes the array when it goes out of scope
    return 0;
}
/*
Pointer arithmetic demonstration:
Address: 0x16fdfeec0, Value: 10
Address: 0x16fdfeec4, Value: 20
Address: 0x16fdfeec8, Value: 30
Address: 0x16fdfeecc, Value: 40
Address: 0x16fdfeed0, Value: 50

After incrementing pointer:
Address: 0x16fdfeec4, Value: 20
After decrementing pointer:
Address: 0x16fdfeec0, Value: 10

Difference between pointers (pEnd - arr): 4

Mix of increment and *:
Value at *p: 10
Value at *++p: 20
Value at *p++: 20
Value at *p: 30
Value at *--p: 20
Value at *p--: 20
Value at *p: 10

unique_ptr demonstration:
uniqueArr[0] = 100
uniqueArr[1] = 200
uniqueArr[2] = 300
uniqueArr[3] = 400
uniqueArr[4] = 500
*/