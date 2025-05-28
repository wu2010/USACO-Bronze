#include <iostream>

// 1. Selection (if-else)
// Prove: {x >= 0} if (x > 5) y = x; else y = 5; {y >= 5}
void selection_example(int x) {
    int y;
    if (x > 5) {
        y = x;
    } else {
        y = 5;
    }
    std::cout << "[Selection] y = " << y << std::endl;
    // Postcondition: y >= 5
    // Hoare logic:
    // {x >= 0} if (x > 5) y = x; else y = 5; {y >= 5}
}

// 2. Iteration (while)
// Prove: {x >= 0} while (x > 0) x = x - 1; {x == 0}
void iteration_example(int x) {
    // Loop invariant: x >= 0
    while (x > 0) {
        x = x - 1;
    }
    std::cout << "[Iteration] x = " << x << std::endl;
    // Postcondition: x == 0
    // Hoare logic:
    // {x >= 0} while (x > 0) x = x - 1; {x == 0}
}

// 3. Recursive function
// Prove: {n >= 0} factorial(n) returns n! {result > 0}
int factorial(int n) {
    // Precondition: n >= 0
    if (n == 0) return 1;
    return n * factorial(n - 1);
    // Postcondition: result > 0
    // Hoare logic:
    // {n >= 0} factorial(n) {result > 0}
}

// 4. Sequence (composition)
// Prove: {x >= 0} y = x + 1; z = y * 2; {z >= 2}
void sequence_example(int x) {
    int y = x + 1;
    int z = y * 2;
    std::cout << "[Sequence] z = " << z << std::endl;
    // Postcondition: z >= 2
    // Hoare logic:
    // {x >= 0} y = x + 1; z = y * 2; {z >= 2}
}

// 5. Nested selection and iteration
// Prove: {x >= 0} if (x % 2 == 0) while (x > 0) x = x - 2; {x == 0 or x == positive odd}
void nested_example(int x) {
    if (x % 2 == 0) {
        while (x > 0) {
            x = x - 2;
        }
    }
    std::cout << "[Nested] x = " << x << std::endl;
    // Postcondition: x == 0 or x == positive odd
    // Hoare logic:
    // {x >= 0} if (x % 2 == 0) while (x > 0) x = x - 2; {x == 0 or x == positive odd}
}

// 6. Multiple assignment
// Prove: {a >= 0, b >= 0} a = a + b; b = a - b; a = a - b; {a == old_b, b == old_a}
void swap_example(int a, int b) {
    int old_a = a, old_b = b;
    a = a + b;
    b = a - b;
    a = a - b;
    std::cout << "[Swap] a = " << a << ", b = " << b << std::endl;
    // Postcondition: a == old_b, b == old_a
    // Hoare logic:
    // {a >= 0, b >= 0} a = a + b; b = a - b; a = a - b; {a == old_b, b == old_a}
}

// 7. Short-circuit logic
// Prove: {a >= 0, b >= 0} if (a > 0 && b > 0) c = 1; else c = 0; {c == 1 => a > 0 && b > 0}
void short_circuit_example(int a, int b) {
    int c;
    if (a > 0 && b > 0) {
        c = 1;
    } else {
        c = 0;
    }
    std::cout << "[Short-circuit] c = " << c << std::endl;
    // Postcondition: c == 1 => a > 0 && b > 0
    // Hoare logic:
    // {a >= 0, b >= 0} if (a > 0 && b > 0) c = 1; else c = 0; {c == 1 => a > 0 && b > 0}
}

int main() {

    // Hoare logic examples

    selection_example(7);   // y = 7
    selection_example(3);   // y = 5

    iteration_example(4);   // x = 0

    int n = 5;
    int result = factorial(n);
    std::cout << "[Recursion] factorial(" << n << ") = " << result << std::endl;

    sequence_example(0);    // z = 2
    sequence_example(3);    // z = 8

    nested_example(6);      // x = 0
    nested_example(5);      // x = 5

    swap_example(2, 5);     // a = 5, b = 2
    swap_example(10, 20);   // a = 20, b = 10

    short_circuit_example(1, 2); // c = 1
    short_circuit_example(0, 2); // c = 0


    std::cout << "\n[Extra Loop Invariant Example]" << std::endl;

    // Example: Sum of first n natural numbers using a loop
    // Prove: {n >= 0} sum = 0; i = 1; while (i <= n) { sum = sum + i; i = i + 1; } {sum == n*(n+1)/2}
    int sum = 0;
    int i = 1;
    // Loop invariant: sum == (i-1)*i/2 && 1 <= i <= n+1
    while (i <= n) {
        sum = sum + i;
        i = i + 1;
    }
    std::cout << "Sum of first " << n << " natural numbers = " << sum << std::endl;

    // Example: Find minimum in an array
    // Prove: {size > 0} min = arr[0]; for (int j = 1; j < size; ++j) if (arr[j] < min) min = arr[j]; {min == minimum of arr}
    // Loop invariant: min == minimum of arr[0..j-1]
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    for (int j = 1; j < size; ++j) {
        if (arr[j] < min) min = arr[j];
    }
    std::cout << "Minimum in array = " << min << std::endl;

    return 0;
}

/*
Hoare Logic demonstration:
1. Selection: {x >= 0} if (x > 5) y = x; else y = 5; {y >= 5}
2. Iteration: {x >= 0} while (x > 0) x = x - 1; {x == 0}
3. Recursion: {n >= 0} factorial(n) {result > 0}
4. Sequence: {x >= 0} y = x + 1; z = y * 2; {z >= 2}
5. Nested: {x >= 0} if (x % 2 == 0) while (x > 0) x = x - 2; {x == 0 or x == 1}
6. Swap: {a >= 0, b >= 0} a = a + b; b = a - b; a = a - b; {a == old_b, b == old_a}
7. Short-circuit: {a >= 0, b >= 0} if (a > 0 && b > 0) c = 1; else c = 0; {c == 1 => a > 0 && b > 0}
*/