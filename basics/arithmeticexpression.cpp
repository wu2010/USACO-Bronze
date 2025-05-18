#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Arithmetic expressions
    int x = 5 + 3; // Addition
    int y = 10 - 4; // Subtraction
    int z = 6 * 7; // Multiplication
    int w = 20 / 4; // Integer division
    int r = 17 % 3; // Modulus (remainder)

    cout << "5 + 3 = " << x << endl;
    cout << "10 - 4 = " << y << endl;
    cout << "6 * 7 = " << z << endl;
    cout << "20 / 4 = " << w << endl;
    cout << "17 % 3 = " << r << endl;

    int a = 7, b = 2;

    // Integer division
    int int_div = a / b;
    cout << "Integer division (7 / 2): " << int_div << endl; // Outputs 3

    // Rational (floating-point) division
    double float_div = static_cast<double>(a) / b;
    cout << "Floating-point division (7 / 2): " << float_div << endl; // Outputs 3.5

    // Another way: using double literals
    double float_div2 = 7.0 / 2.0;
    cout << "Floating-point division (7.0 / 2.0): " << float_div2 << endl; // Outputs 3.5

    // Increment and Decrement
    int increment = 5;
    increment++; // Increment by 1
    cout << "Incremented value: " << increment << endl; // Outputs 6
    increment--; // Decrement by 1
    cout << "Decremented value: " << increment << endl; // Outputs 5
    increment += 2; // Increment by 2
    cout << "Incremented by 2: " << increment << endl; // Outputs 7
    increment -= 3; // Decrement by 3
    cout << "Decremented by 3: " << increment << endl; // Outputs 4

    // Compound assignment operators
    int compound = 10;
    compound += 5; // compound = compound + 5
    cout << "Compound addition: " << compound << endl; // Outputs 15

    // exponentiation
    // C++ does not have a built-in exponentiation operator, but you can use a loop or the pow function from <cmath>
    int base = 2;
    int exponent = 3;
    int power = 1;
    for (int i = 0; i < exponent; ++i) {
        power *= base; // power = power * base
    }
    cout << "2^3 = " << power << endl; // Outputs 8
    
    // Using the pow function from cmath
    double pow_result = pow(2, 3);
    cout << "Using pow function: 2^3 = " << pow_result << endl; // Outputs 8.0
    // Note: The pow function returns a double, so the result is 8.0 instead of 8.
    // The pow function can also be used for non-integer exponents
    double non_integer_pow = pow(2, 2.5);
    cout << "2^2.5 = " << non_integer_pow << endl; // Outputs 5.65685
    // Note: The result is a double, so it may not be an exact integer.
    // The pow function can also be used for negative bases and exponents
    double negative_base_pow = pow(-2, 3);
    cout << "-2^3 = " << negative_base_pow << endl; // Outputs -8.0
    // Note: The result is negative because the exponent is odd.

    // The pow function can also be used for complex numbers
    // but that requires including the <complex> header and using complex numbers.
    // Example: Using pow with complex numbers
    complex<double> complex_base(2, 3); // 2 + 3i
    complex<double> complex_pow = pow(complex_base, 2); // (2 + 3i)^2
    cout << "(2 + 3i)^2 = " << complex_pow << endl; // Outputs -5 + 12i
    // Note: The result is a complex number, so it has both real and imaginary parts.


    return 0;
}
