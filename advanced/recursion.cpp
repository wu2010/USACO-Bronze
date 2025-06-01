#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// iterative function to calculate factorial
int factorial2(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Recursive function to calculate nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Iterative function to calculate nth Fibonacci number
int fibonacci2(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    // (a, b) -> (b, a + b)
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Recursive function to compute GCD (Euclidean algorithm)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Iterative function to compute GCD (Euclidean algorithm)
int gcd2(int a, int b) {
    // (a, b) -> (b, a % b)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    if (n == 0) return 0;
    return n % 10 + sumOfDigits(n / 10);
}

// Iterative function to calculate sum of digits
int sumOfDigits2(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Recursive function to calculate power (base^exp)
int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

// Iterative function to calculate power (base^exp)
int power2(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        --exp;
    }
    return result;
}

// Recursive function to reverse a string
void reverseString(const string& s, int idx) {
    if (idx < 0) return;
    cout << s[idx];
    reverseString(s, idx - 1);
}

// Iterative function to reverse a string
void reverseString2(const string& s) {
    for (int i = s.size() - 1; i >= 0; --i) {
        cout << s[i];
    }
}

int main() {

    int num = 7;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    cout << "Fibonacci number at position " << num << " is " << fibonacci(num) << endl;

    num = 12345;
    cout << "Sum of digits of " << num << " is " << sumOfDigits(num) << endl;

    // GCD example
    int a = 98, b = 1001;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    // Power example
    int base, exp;
    base = 2;
    exp = 8;
    cout << base << "^" << exp << " = " << power(base, exp) << endl;

    // Reverse string example
    string s = "Hello, Alicia!";
    cout << "Reversed string: ";
    reverseString(s, s.size() - 1);
    cout << endl;

    return 0;
}
/*
Factorial of 7 is 5040
Fibonacci number at position 7 is 13
Sum of digits of 12345 is 15
GCD of 98 and 1001 is 7
2^8 = 256
Reversed string: !aicilA ,olleH
*/