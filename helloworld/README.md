# C++: an Intro

C++ is a statically typed, compiled, multi-paradigm programming language, with strong emphasis on performance, resource management, and abstraction. Its features include direct memory manipulation, strong type checking, and support for multiple programming paradigms. C++ was designed by Bjarne Stroustrup, who is an ACM Fellow. 


## Minimal Forms

All C++ programs must have a main function. If you try to compile a C++ program without a main function, the compiler raises an error.

This is the minimal C++ program and saved as `main.cpp`. 
```cpp
int main(){}
```

Here is a minimal C++ loop with a null statement that does nothing but iterates from 0 to 4:

```cpp
for (int i = 0; i < 5; ++i) {
    // null statement: nothing happens here
}
```

A null statement in C++ is simply a semicolon (`;`) by itself. You can write the loop as:

```cpp
for (int i = 0; i < 5; ++i);
```

This loop runs five times but performs no action in its body.

## Compiled Language

Compiling is a crucial step in software development because it transforms human-readable source code into efficient machine code that computers can execute. This process enables programs to run faster, use resources more effectively, and catch many errors before the software is ever run. 

A central design idea behind compilers is the separation of concerns into distinct phases: parsing source code, analyzing its structure and meaning (syntax and semantics), optimizing the code, and generating efficient machine instructions. This modular approach allows compilers to transform high-level programming languages into fast, reliable executables.

C++ is a compiled language, which means you need to use a compiler to turn your source code into an executable program. Here are some examples of how to compile your code using `g++`:

```sh
g++ main.cpp -o myprogram
```

This command compiles `main.cpp` and creates an executable named `myprogram`. You can then run your program with:

```sh
./myprogram
```

If you want to see the compilation process in more detail, you can add the `-v` (verbose) flag:

```sh
g++ -v main.cpp -o myprogram
```

If your program uses features from the C++11 standard or later, specify the standard with the `-std` flag:

```sh
g++ -std=c++17 main.cpp -o myprogram
```

If there are errors in your code, the compiler will print error messages to help you debug. Always check the output for any warnings or errors.

## Organizing Code with Header and Multiple Source Files

C++ projects often use header files (`.h`) to declare functions and classes, and source files (`.cpp`) to define them. This helps organize code and makes it easier to manage larger projects. The main function doesn't have a declaration, because it's built into the language, e.g. `int main(int argc, char *argv[]);`.

More in [main function and command-line arguments](https://learn.microsoft.com/en-us/cpp/cpp/main-function-command-line-args?view=msvc-170)

### Example Structure

Suppose you want to separate a function into its own files:

```
project/
├── main.cpp
├── math_utils.h
└── math_utils.cpp
```

### `math_utils.h`

Declare your function in the header file:

```cpp
// math_utils.h
#pragma once

int add(int a, int b);
```

### `math_utils.cpp`

Define the function in the source file:

```cpp
// math_utils.cpp
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}
```

### `main.cpp`

Use the function in your main program:

```cpp
// main.cpp
#include <iostream>
#include "math_utils.h"

int main() {
    std::cout << add(2, 3) << std::endl;
    return 0;
}
```

### Compiling Multiple Files

Compile all `.cpp` files together:

```sh
g++ main.cpp math_utils.cpp -o myprogram
```

This creates an executable `myprogram` that uses code from both source files.


## Typed Language

Type checking is a crucial feature in programming languages like C++. It ensures that operations are performed on compatible data types, helping to catch errors at compile time before the program runs. A strong type system improves program reliability, maintainability, and security by preventing unintended operations, such as assigning a string to an integer variable. The importance of type systems has been recognized in computer science, with Turing Awards given to pioneers like Tony Hoare (1980) for work on formal specification and type safety.

C++ is a strictly typed language, meaning every variable and expression has a specific type that must be declared and cannot be changed implicitly. 

```cpp
int x = 5;      // OK
x = "hello";    // Error: cannot assign a string to an int
```

Strict typing in C++ improves program reliability and makes your code easier to understand and maintain.

### Using `auto` for Type Deduction

Type inference is the ability of a language to automatically deduce the types of expressions without explicit type annotations. Robin Milner received the 1991 Turing Award in part for his work on type inference, specifically the development of the Hindley-Milner type system, which enables powerful type inference in languages like ML and Haskell. 

C++ provides the `auto` keyword to let the compiler automatically deduce the type of a variable from its initializer. This can make your code cleaner and easier to maintain, especially when dealing with complex types.

For example:

```cpp
auto x = 42;        // x is deduced to be int
auto y = 3.14;      // y is deduced to be double
auto name = "Bob";  // name is deduced to be const char*
```

`auto` is especially useful with iterators and template types:

```cpp
std::vector<int> numbers = {1, 2, 3};
for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    // *it is an int
}
```

Remember, `auto` requires an initializer so the compiler can deduce the type. It does not make C++ dynamically typed; the type is still fixed at compile time.

## Program Termination

When a C++ program finishes executing the `main` function, it terminates and returns a value to the operating system. By convention, returning `0` from `main` indicates successful completion, while returning a nonzero value signals an error.

Example:

```cpp
int main() {
    // program logic
    return 0; // signals success
}
```

If you omit the `return` statement in `main`, C++ will automatically return `0` (in C++ standards since C++11).

You can also terminate a program early using the `exit` function from the `<cstdlib>` header:

```cpp
#include <cstdlib>

int main() {
    // some condition
    exit(1); // terminates the program and returns 1
}
```

Use `return` in `main` for normal termination and `exit` for special cases where you need to end the program immediately.
