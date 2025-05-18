#include <iostream>
#include <fstream>

using namespace std;

// Example 14: Using logical expressions in return statements
int getMax(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a = 5, b = 10, c = 5;

    // Example 1: Equality and Inequality
    cout << "a == c: " << (a == c) << endl; // true (1)
    cout << "a != b: " << (a != b) << endl; // true (1)

    // Example 2: Logical AND
    cout << "(a < b) && (b > c): " << ((a < b) && (b > c)) << endl; // true (1)

    // Example 3: Logical OR
    cout << "(a > b) || (b > c): " << ((a > b) || (b > c)) << endl; // true (1)

    // Example 4: Logical NOT
    cout << "!(a == b): " << (!(a == b)) << endl; // true (1)

    // Example 5: Combining multiple expressions
    bool result = (a < b) && ((b == 10) || (c == 7));
    cout << "Combined logical expression: " << result << endl; // true (1)

    // Example 6: Greater than or equal to
    cout << "b >= a: " << (b >= a) << endl; // true (1)
    cout << "a >= b: " << (a >= b) << endl; // false (0)

    // Example 7: Less than or equal to
    cout << "a <= b: " << (a <= b) << endl; // true (1)
    cout << "b <= c: " << (b <= c) << endl; // false (0)

    // Example 8: Using logical expressions in if statements
    if (a < b && c == 5) {
        cout << "Condition met: a is less than b and c is equal to 5" << endl;
    } else {
        cout << "Condition not met" << endl;
    }

    // Example 9: Using logical expressions in switch statements
    int choice = 2;
    switch (choice) {
        case 1:
            cout << "Choice is 1" << endl;
            break;
        case 2:
            cout << "Choice is 2" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    // Example 10: Using logical expressions in while loops
    int count = 0;
    while (count < 4) {
        cout << "Count: " << count << endl;
        count++;
    }

    // Example 11: Using logical expressions in for loops
    for (int i = 0; i < 4; i++) {
        cout << "i: " << i << endl;
    }

    // Example 12: Using logical expressions in ternary operator
    int max = (a > b) ? a : b;
    cout << "Max of a and b: " << max << endl; // 10

    // Example 13: Using logical expressions in function arguments
    cout << "Max of 5 and 10: " << getMax(5, 10) << endl; // 10

    // Example 15: Using logical expressions in lambda functions
    auto isEven = [](int num) { return num % 2 == 0; };
    cout << "Is 4 even? " << isEven(4) << endl; // true (1)

    // Example 18: Using logical expressions in file I/O
    ofstream file("output.txt");
    if (file.is_open()) {
        file << "Writing to file" << endl;
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}