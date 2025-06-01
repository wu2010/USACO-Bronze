#include <iostream>
#include <bitset>
using namespace std;

int main() {
    // why unsigned int?
    // Bitwise operations are often used with unsigned integers to avoid issues with sign extension.
    // For example, when shifting bits, signed integers can lead to 
    // undefined behavior if the sign bit is shifted out.
    // This code demonstrates various bitwise operations in C++ using unsigned integers.

    // Bitwise operations on unsigned integers
    // are well-defined and predictable, making them suitable for low-level programming tasks.
    unsigned int a = 42;      // 00101010 in binary
    unsigned int b = 15;      // 00001111 in binary

    cout << "a      = " << bitset<8>(a) << " (" << a << ")\n";
    cout << "b      = " << bitset<8>(b) << " (" << b << ")\n";

    // Bitwise AND
    cout << "a & b  = " << bitset<8>(a & b) << " (" << (a & b) << ")\n";

    // Bitwise OR
    cout << "a | b  = " << bitset<8>(a | b) << " (" << (a | b) << ")\n";

    // Bitwise XOR
    cout << "a ^ b  = " << bitset<8>(a ^ b) << " (" << (a ^ b) << ")\n";

    // Bitwise NOT (or complement)
    // Note: ~a will produce a signed integer if a is signed, so we mask it with 0xFF to get the last 8 bits
    cout << "~a     = " << bitset<8>(~a) << " (" << (~a & 0xFF) << ")\n";


    // Left shift. This is equivalent to multiplying by 2^n
    cout << "a << 2 = " << bitset<8>(a << 2) << " (" << (a << 2) << ")\n";

    // Right shift. This is equivalent to dividing by 2^n (for unsigned integers)
    cout << "a >> 2 = " << bitset<8>(a >> 2) << " (" << (a >> 2) << ")\n";


    // Swap a and b using bitwise XOR
    a = a ^ b;
    b = a ^ b; // Now b is the original value of a because (x ^ y) ^ y = x
    a = a ^ b; // Now a is the original value of b because (x ^ y) ^ x = y
    cout << "After swap:\n";
    cout << "a      = " << bitset<8>(a) << " (" << a << ")\n";
    cout << "b      = " << bitset<8>(b) << " (" << b << ")\n";


    // Turn off the rightmost set bit
    unsigned int z = 44; // 00101100
    unsigned int result = z & (z - 1);
    // Example: 16 is 00010000 in binary, and 16 - 1 is 00001111. The AND operation results in 0.
    cout << "After turning off rightmost set bit of " << bitset<8>(z) << ": " << bitset<8>(result) << "\n";

    // Check if a number is a power of two
    unsigned int num = 16;
    bool isPowerOfTwo = (num != 0) && ((num & (num - 1)) == 0); 
    // Explanation: num & (num - 1) clears the rightmost set bit of num. 
    //     If the result is 0, then num is a power of two.
    cout << num << (isPowerOfTwo ? " is" : " is not") << " a power of two\n";

    // Count the number of set bits (Hamming weight)
    // This is often done using Brian Kernighan's algorithm
    // Brian Kernighan popularized the "Hello, World!" program
    unsigned int x = 29; // 00011101
    int count = 0;
    for (unsigned int y = x; y; y &= (y - 1)) {
        // y &= (y - 1) clears the rightmost set bit of y
        count++;
    }
    cout << "Number of set bits in " << x << " = " << count << "\n";


    // Check if a number is even or odd using bitwise AND
    unsigned int evenOddNum = 7;
    cout << evenOddNum << " is " << ((evenOddNum & 1) ? "odd" : "even") << "\n";
    // Check if a number is divisible by 4 using bitwise AND
    unsigned int divisibleBy4Num = 12;
    cout << divisibleBy4Num << " is " << ((divisibleBy4Num & 3) ? 
        "not divisible by 4" : "divisible by 4") << "\n";
    // Check if a number is divisible by 8 using bitwise AND
    unsigned int divisibleBy8Num = 24;
    cout << divisibleBy8Num << " is " << ((divisibleBy8Num & 7) ? 
        "not divisible by 8" : "divisible by 8") << "\n";


    // Isolate the rightmost set bit
    unsigned int m = 52; // 00110100
    unsigned int rightmostSetBit = m & -m; 
    // why this works: -m is the two's complement of m, which flips all bits and adds 1
    cout << "Rightmost set bit of " << bitset<8>(m) << ": " << bitset<8>(rightmostSetBit) << "\n";


    // Reverse bits in a byte
    unsigned int n = 13; // 00001101
    unsigned int reversed = 0;
    for (int i = 0; i < 8; ++i) {
        reversed <<= 1; // Shift reversed left to make space for the next bit
        reversed |= (n >> i) & 1; // Get the i-th bit of n and add it to reversed
    }
    cout << "Reversed bits of " << bitset<8>(n) << ": " << bitset<8>(reversed) << "\n";

    // Find the position of the highest set bit (0-based)
    unsigned int p = 72; // 01001000
    int pos = -1;
    for (int i = 0; i < 8; ++i) {
        // Check each bit from least significant to most significant
        // If the bit is set, update pos to the current index
        if ((p >> i) & 1) pos = i;
    }
    cout << "Highest set bit position in " << bitset<8>(p) << ": " << pos << "\n";


    return 0;
}
/*
a      = 00101010 (42)
b      = 00001111 (15)
a & b  = 00001010 (10)
a | b  = 00101111 (47)
a ^ b  = 00100101 (37)
~a     = 11010101 (213)
a << 2 = 10101000 (168)
a >> 2 = 00001010 (10)
After swap:
a      = 00001111 (15)
b      = 00101010 (42)
After turning off rightmost set bit of 00101100: 00101000
16 is a power of two
Number of set bits in 29 = 4
7 is odd
12 is divisible by 4
24 is divisible by 8
Rightmost set bit of 00110100: 00000100
Reversed bits of 00001101: 10110000
Highest set bit position in 01001000: 6
*/