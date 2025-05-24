#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Declaration examples
    int a;                  // declares an integer variable
    double b;               // declares a double variable
    char c;                 // declares a character variable
    string s;               // declares a string variable
    vector<int> v;          // declares a vector of integers

    // You can also declare multiple variables of the same type
    int x, y, z;

    // Declaration with initialization
    int n = 10;
    double pi = 3.14159;
    char grade = 'A';
    string name = "Alice";
    vector<int> nums = {1, 2, 3, 4, 5};

    // More initialization examples
    int m(20);                  // direct initialization
    double e{2.71828};          // brace initialization (C++11)
    char symbol('!');           // direct initialization
    string city{"London"};      // brace initialization
    vector<int> primes{2, 3, 5, 7, 11}; // brace initialization for vector

    // Initializing arrays
    int arr1[3] = {1, 2, 3};
    double arr2[] = {0.1, 0.2, 0.3, 0.4};
    char arr3[] = {'a', 'b', 'c', '\0'}; // null-terminated string
    // Note: arr3 is a C-style string, not a std::string

    // Initializing with expressions
    int sum = n + m;
    double area = pi * 2 * 2;

    // Output the values (excluding uninitialized variables)
    cout << "v size: " << v.size() << endl;
    cout << "n: " << n << endl;
    cout << "pi: " << pi << endl;
    cout << "grade: " << grade << endl;
    cout << "name: " << name << endl;

    cout << "nums: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    cout << "m: " << m << endl;
    cout << "e: " << e << endl;
    cout << "symbol: " << symbol << endl;
    cout << "city: " << city << endl;

    cout << "primes: ";
    for (int p : primes) cout << p << " ";
    cout << endl;
    cout << "arr1: ";
    for (int i = 0; i < 3; ++i) cout << arr1[i] << " ";
    cout << endl;
    cout << "arr2: ";
    for (double d : arr2) cout << d << " ";
    cout << endl;

    cout << "arr3: " << arr3 << endl;
    // Note: arr3 is printed as a string due to null-termination
    cout << "sum: " << sum << endl;
    cout << "area: " << area << endl;

    // C++ requires constant expressions — expressions that evaluate to 
    // a constant — for declarations of: Array bounds, Selectors in case statements
    // Example: Using a constant expression for array size
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};
    cout << "Array of size " << SIZE << ": " << endl;

    // A reference acts as another name for an existing variable and must be 
    // initialized to an existing variable at declaration. References are often 
    // used to avoid copying data or to allow functions to modify arguments.
    int& ref = y; // ref is a reference to y
    ref = 20;     // changes y to 20
    cout << ref << " (y is now " << y << ")" << endl;

    return 0;
}