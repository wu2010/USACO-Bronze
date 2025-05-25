#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Traditional function pointer
bool is_even(int x) {
    return x % 2 == 0;
}

int main() {

    std::vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Using function pointer
    int even_count1 = std::count_if(nums.begin(), nums.end(), is_even);
    std::cout << "Even count (function pointer): " << even_count1 << std::endl;

    // Using lambda instead of function pointer
    int even_count2 = std::count_if(nums.begin(), nums.end(), [](int x) {
        return x % 2 == 0;
    });
    std::cout << "Even count (lambda): " << even_count2 << std::endl;

    // Using std::transform with a lambda
    std::vector<int> doubled(nums.size());
    std::transform(nums.begin(), nums.end(), doubled.begin(), [](int x) {
        return x * 2;
    });
    std::cout << "Doubled: ";
    for (int n : doubled) std::cout << n << " ";
    std::cout << std::endl;

    // Using std::remove_if with a lambda
    auto it = std::remove_if(nums.begin(), nums.end(), [](int x) {
        return 2 < x && x <= 4;
    });
    // Note: std::remove_if does not actually erase elements, it just moves them
    // to the end of the vector. We need to call erase to remove them.
    nums.erase(it, nums.end());
    std::cout << "After remove_if (2<x<=4): ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // Using std::for_each with a lambda
    std::cout << "Squared: ";
    std::for_each(nums.begin(), nums.end(), [](int x) {
        std::cout << x * x << " ";
    });
    std::cout << std::endl;

    // Using std::sort with a lambda (descending order)
    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    std::cout << "Sorted descending: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << std::endl;

    // Using std::find_if with a lambda
    auto found = std::find_if(nums.begin(), nums.end(), [](int x) {
        return x == 6;
    });
    if (found != nums.end()) {
        std::cout << "Found 6 in nums." << std::endl;
    } else {
        std::cout << "6 not found in nums." << std::endl;
    }

    return 0;
}
/*
Even count (function pointer): 3
Even count (lambda): 3
Doubled: 2 4 6 8 10 12 
After remove_if (2<x<=4): 1 2 5 6 
Squared: 1 4 25 36 
Sorted descending: 6 5 2 1 
Found 6 in nums.
*/