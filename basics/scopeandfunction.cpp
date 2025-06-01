#include <iostream>
#include <array>
#include <vector>

using namespace std;

// Global variable
int globalVar = 10;

// Function demonstrating local scope
void localScopeExample() {
    int localVar = 20; // Local variable
    cout << "Inside localScopeExample, localVar = " << localVar << endl;
    cout << "Inside localScopeExample, globalVar = " << globalVar << endl;
}

// Function demonstrating parameter scope
void parameterScopeExample(int paramVar) {
    cout << "Inside parameterScopeExample, paramVar = " << paramVar << endl;
}

// Function demonstrating block scope
void blockScopeExample() {
    int x = 5;
    cout << "Outside block, x = " << x << endl;
    {
        int x = 100; // This x shadows the outer x
        cout << "Inside block, x = " << x << endl;
    }
    cout << "After block, x = " << x << endl;
}

int main() {
    cout << "In main, globalVar = " << globalVar << endl;

    // the function-call operator
    localScopeExample();

    parameterScopeExample(42);

    blockScopeExample();

    // Uncommenting the next line will cause a compile error, as localVar is not visible here
    // cout << localVar << endl;

    // C++ uses pass by value. When an argument is passed by value, 
    // a copy of the argument's value is created and passed to the function. 
    // Modifications made to the parameter inside the function do not affect 
    // the original argument. 

    // C++ also supports pass by reference and pass by address (using pointers). 
    // Pass by reference allows a function to modify the original argument, 
    // while pass by address achieves a similar result by passing the memory address 
    // of the argument.

    // the change is local to the function and does not affect the actual 
    // argument's value unless the actual argument was a reference 
    // to an object not of type const.

    // Example: Pass by value
    int a = 5;
    int b = 10;
    auto passByValue = [](int x, int y) {
        x = x + 1;
        y = y + 1;
        cout << "Inside passByValue, x = " << x << ", y = " << y << endl;
    };
    passByValue(a, b);
    cout << "After passByValue, a = " << a << ", b = " << b << endl;

    // Example: Pass by reference
    auto passByReference = [](int& x, int& y) {
        x = x + 1;
        y = y + 1;
        cout << "Inside passByReference, x = " << x << ", y = " << y << endl;
    };
    passByReference(a, b);
    cout << "After passByReference, a = " << a << ", b = " << b << endl;

    // Example: Pass by const reference
    // C++ allows passing by const reference to avoid copying large objects 
    // while ensuring they are not modified.
    auto passByConstReference = [](const int& x) {
        cout << "Inside passByConstReference, x = " << x << endl;
        // x++; // Uncommenting this line will cause a compile error
    };
    passByConstReference(a);
    cout << "After passByConstReference, a = " << a << endl;

    // Example: Pass by pointer
    auto passByPointer = [](int* x) {
        *x = *x + 1;
        cout << "Inside passByPointer, *x = " << *x << endl;
    };
    passByPointer(&a);
    cout << "After passByPointer, a = " << a << endl;

    // Example: Swapping values using pass by reference
    auto swapByReference = [](int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
        cout << "Inside swapByReference, x = " << x << ", y = " << y << endl;
    };
    int c = 7, d = 9;
    cout << "Before swapByReference, c = " << c << ", d = " << d << endl;
    swapByReference(c, d);
    cout << "After swapByReference, c = " << c << ", d = " << d << endl;

    // Example: Modifying an array using pass by reference
    auto modifyArray = [](int (&arr)[3]) {
        for (int i = 0; i < 3; ++i) {
            arr[i] += 10;
        }
        cout << "Inside modifyArray, arr = ";
        for (int i = 0; i < 3; ++i) cout << arr[i] << " ";
        cout << endl;
    };
    int arr[3] = {1, 2, 3};
    cout << "Before modifyArray, arr = ";
    for (int i = 0; i < 3; ++i) cout << arr[i] << " ";
    cout << endl;
    modifyArray(arr);
    cout << "After modifyArray, arr = ";
    for (int i = 0; i < 3; ++i) cout << arr[i] << " ";
    cout << endl;

    // Example: Returning reference from a function
    auto getElementReference = [](int (&arr)[3], int index) -> int& {
        return arr[index];
    };
    getElementReference(arr, 1) = 99;
    cout << "After getElementReference(arr, 1) = 99, arr = ";
    for (int i = 0; i < 3; ++i) cout << arr[i] << " ";
    cout << endl;

    // In C++, when an array is passed as an argument to a function, 
    // it decays to pass by pointer. also it can use passed by reference.
    // This means that the function receives the memory address of 
    // the first element of the array, rather than a copy of the entire array. 
    // Consequently, any modifications made to the array within the function 
    // will affect the original array in the calling scope.

    // Example: Passing array as parameter (decays to pointer)
    auto sumArray = [](int arr[], int size) {
        int sum = 0;
        for (int i = 0; i < size; ++i) sum += arr[i];
        cout << "Inside sumArray, sum = " << sum << endl;
    };
    int nums[4] = {4, 5, 6, 7};
    sumArray(nums, 4);

    // Example: Passing array by reference (size known at compile time)
    auto printArray = [](const int (&arr)[4]) {
        cout << "Inside printArray, arr = ";
        for (int i = 0; i < 4; ++i) cout << arr[i] << " ";
        cout << endl;
    };
    printArray(nums);

    // Example: Passing 2D array as parameter
    auto print2DArray = [](int arr[][2], int rows) {
        cout << "Inside print2DArray:" << endl;
        // Statement scope Names declared in a for, if, while, or switch statement 
        // are visible until the end of the statement block. e.g. i, j
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < 2; ++j) cout << arr[i][j] << " ";
            cout << endl;
        }
    };
    int matrix[2][2] = {{1, 2}, {3, 4}};
    print2DArray(matrix, 2);

    // Example: Using std::array for fixed-size arrays
    // const reference to avoid copying
    auto printStdArray = [](const std::array<int, 3>& arr) {
        cout << "Inside printStdArray, arr = ";
        for (const auto& elem : arr) cout << elem << " ";
        cout << endl;
    };
    std::array<int, 3> stdArr = {1, 2, 3};
    printStdArray(stdArr);

    // Example: Using std::vector for dynamic arrays
    // const reference to avoid copying
    auto printVector = [](const std::vector<int>& vec) {
        cout << "Inside printVector, vec = ";
        for (const auto& elem : vec) cout << elem << " ";
        cout << endl;
    };
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printVector(vec);

    return 0;
}

/* Output:
In main, globalVar = 10
Inside localScopeExample, localVar = 20
Inside localScopeExample, globalVar = 10
Inside parameterScopeExample, paramVar = 42
Outside block, x = 5
Inside block, x = 100
After block, x = 5
Inside passByValue, x = 6, y = 11
After passByValue, a = 5, b = 10
Inside passByReference, x = 6, y = 11
After passByReference, a = 6, b = 11
Inside passByConstReference, x = 6
After passByConstReference, a = 6
Inside passByPointer, *x = 7
After passByPointer, a = 7
Before swapByReference, c = 7, d = 9
Inside swapByReference, x = 9, y = 7
After swapByReference, c = 9, d = 7
Before modifyArray, arr = 1 2 3 
Inside modifyArray, arr = 11 12 13 
After modifyArray, arr = 11 12 13 
After getElementReference(arr, 1) = 99, arr = 11 99 13 
Inside sumArray, sum = 22
Inside printArray, arr = 4 5 6 7 
Inside print2DArray:
1 2 
3 4 
Inside printStdArray, arr = 1 2 3 
Inside printVector, vec = 1 2 3 4 5 
*/