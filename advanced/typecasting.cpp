#include <iostream>
using namespace std;

int main() {
    int a = 5;
    double b = 2.5;

    // Type promotion: int promoted to double in arithmetic
    double result = a + b;
    cout << "a + b = " << result << " (int promoted to double)" << endl;

    // Explicit casting: double to int (truncates decimal)
    int c = (int)b;
    cout << "Casting double b to int: " << c << endl;

    // Implicit casting: assigning int to double
    double d = a;
    cout << "Assigning int a to double d: " << d << endl;

    // C++ style casting
    int e = static_cast<int>(b);
    cout << "static_cast<double b to int>: " << e << endl;

    // Char to int and int to char
    char ch = 'A';
    int ch_int = ch;
    cout << "Char ch ('A') to int: " << ch_int << endl;

    int num = 66;
    char num_char = static_cast<char>(num);
    cout << "Int num (66) to char: " << num_char << endl;

    // Famous example: integer division vs. floating-point division
    int x = 7, y = 2;
    cout << "Integer division x / y: " << x / y << endl; // Outputs 3
    cout << "Floating-point division (double)x / y: " << (double)x / y << endl; // Outputs 3.5

    // Example: narrowing conversion (possible data loss)
    double large = 1e10;
    int narrowed = large;
    cout << "Narrowing conversion from double to int: " << narrowed << endl;

    // Example: unsigned and signed conversion
    int neg = -1;
    unsigned int u = static_cast<unsigned int>(neg);
    cout << "Casting -1 to unsigned int: " << u << ", which is 0xFFFFFFFF" << endl;
    // Explanation: The negative value is interpreted as a large positive value in unsigned representation.
    // This is because unsigned integers cannot represent negative values, so the bit pattern is preserved.
    // the reserve example:
    unsigned int reserve = 0xFFFFFFFF; // All bits set to 1
    int reserve_signed = static_cast<int>(reserve);
    cout << "Casting 0xFFFFFFFF to signed int: " << reserve_signed << endl;
    // Explanation: The bit pattern of 0xFFFFFFFF is interpreted as -1 in signed representation.

    return 0;
}
/*
a + b = 7.5 (int promoted to double)
Casting double b to int: 2
Assigning int a to double d: 5
static_cast<double b to int>: 2
Char ch ('A') to int: 65
Int num (66) to char: B
Integer division x / y: 3
Floating-point division (double)x / y: 3.5
Narrowing conversion from double to int: 4434
Casting -1 to unsigned int: 4294967295, which is 0xFFFFFFFF
Casting 0xFFFFFFFF to signed int: -1
*/