#include <iostream>
using namespace std;

int main() {
    // For loop: print numbers 0 to 5
    for (int i = 0; i <= 3; ++i) {
        cout << "For loop: " << i << endl;
    }

    // While loop: print numbers 0 to 5
    int j = 0;
    while (j <= 3) {
        cout << "While loop: " << j << endl;
        ++j;
    }

    // Do-while loop: print numbers 0 to 5
    int k = 0;
    do {
        cout << "Do-while loop: " << k << endl;
        ++k;
    } while (k <= 3);

    // Nested loop: print multiplication table for 1 to 3
    for (int a = 1; a <= 3; ++a) {
        for (int b = 1; b <= 3; ++b) {
            cout << "Multiplication: " << a << " * " << b << " = " << a * b << endl;
        }
    }

    // Break statement: early stop to exit loop when i is 3
    for (int i = 1; i <= 5; ++i) {
        if (i == 3) {
            cout << "Breaking loop at i = " << i << endl;
            break;
        }
        cout << "Looping: " << i << endl;
    }
    cout << "Exited loop after breaking." << endl;

    // Continue statement: skip even numbers
    for (int i = 1; i <= 5; ++i) {
        if (i % 2 == 0) {
            cout << "Skipping even number: " << i << endl;
            continue;
        }
        cout << "Looping: " << i << endl;
    }
    cout << "Exited loop after skipping even numbers." << endl;

    // Infinite loop with manual break
    int count = 0;
    while (true) {
        cout << "Infinite loop iteration: " << count << endl;
        ++count;
        if (count >= 3) {
            cout << "Breaking infinite loop at count = " << count << endl;
            break;
        }
    }

    // Range-based for loop (C++11 and later)
    int arr[] = {10, 20, 30, 40, 50};
    for (int num : arr) {
        cout << "Range-based for loop: " << num << endl;
    }

    // Loop with multiple variables
    for (int x = 1, y = 5; x <= 5 && y >= 1; ++x, --y) {
        cout << "Multiple variables: x = " << x << ", y = " << y << endl;
    }

    return 0;
}