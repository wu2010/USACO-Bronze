# USACO-Bronze

https://usaco.org/

Bronze, for students who have recently learned to program, but who have no training in algorithms beyond basic concepts like **sorting and binary search**.

Each contest has typically 3 or 4 problems to which you will submit solution programs in C, C++, Java, or Python. C++ is the only language supported at IOI, this is the clear answer once you reach higher levels.

Contest are typically 4..5 contiguous hours in length. You can take the contest during any block of time you want within the larger contest window. When you start the contest, your personal timer starts counting down

When you submit a program, it will be run against a number of judging test cases and for each one, you will receive feedback, shown in a colored box: green for correct, and red for incorrect. Incorrect submissions are further differentiated by the type of problem: X (incorrect answer), T (time limit exceeded), ! (run-time error or memory limit exceeded), E (empty output file), or M (missing output file). If your program fails to compile, you will be shown the error messages from the compiler. 

## Programming Paradigms and Folder Structure

C++ supports several major programming paradigms:

- **Procedural Programming:** Writing code as a sequence of instructions and procedures (functions). This is the foundation for most beginner-level C++ code. The procedural paradigm was formalized and popularized by languages like C, and its theoretical foundations were influenced by the work of Turing Award laureates such as Donald Knuth (for algorithms and structured programming) and John Backus (for the development of FORTRAN and BNF notation).
- **Object-Oriented Programming (OOP):** Organizing code using classes and objects, encapsulation, inheritance, and polymorphism. The object-oriented paradigm was formalized and popularized by languages like Simula and Smalltalk, with key theoretical foundations influenced by Turing Award laureates such as Ole-Johan Dahl and Kristen Nygaard (for Simula, the first object-oriented language), Alan Kay (for contributions to Smalltalk and OOP concepts), and Barbara Liskov (for her work on data abstraction and the Liskov Substitution Principle, foundational to OOP design).
- **Generic Programming:** Writing algorithms and data structures in a way that works with any data type, primarily using templates. The theoretical foundations of generic programming were influenced by Turing Award laureate John Backus, who developed Backus-Naur Form (BNF). While BNF itself is a notation for formally describing the syntax of programming languages, its introduction enabled language designers to define more abstract and general language constructs, paving the way for features like templates and generic programming. The practical development of generic programming in C++ was led by Alexander Stepanov, whose work on the Standard Template Library (STL) made these concepts widely accessible to programmers.
- **Functional Programming:** Using functions as first-class objects, lambda expressions, and features like `std::function`, though C++ is not purely functional. Functional programming is rooted in the mathematical concept of functions and the lambda calculus, formalized by Alonzo Church. Lambda calculus underpins function abstraction and application, influencing many languages. Turing Award laureates who shaped functional programming include John McCarthy (LISP), Robin Milner (ML and type inference), and Peter Landin (lambda calculus in programming). Their work established key ideas—higher-order functions, immutability, and pure computation—now present in modern languages, including C++.

This repository is organized to help you learn C++ through these paradigms, starting from procedural basics and advancing to OOP and generic programming.

- **helloworld/**  
    Contains a minimal C++ program and null statements. How to compile a strict typed C++ program. 

    ```bash
    # Compile with C++17 standard 
    g++ -std=c++17 -O2 -lm -o myprogram myprogram.cpp

    # Run the compiled executable
    ./myprogram
    ```

- **basics/**  
    Introduces the syntactic foundation for writing procedural C++ programs using Backus-Naur Form (BNF). Includes fundamental programming exercises and examples, covering topics like declarations, expressions (arithmetic, relational, logical), statements (conditionals, loops), and basic data structures for iteration.

    ```cpp
    // Procedural Programming Example
    #include <iostream>
    void greet() {
        std::cout << "Hello, world!" << std::endl;
    }
    int main() {
        greet();
        return 0;
    }
    ```

- **intermediate/**  
    Covers abstract class types, object-oriented programming (OOP) concepts, and the use of sequence containers in C++. Includes examples like `bitset`, `string`, and `vector` for managing collections of data. Memory management concepts are also discussed, together with pointers. 

    ```cpp
    // OOP Example
    #include <iostream>
    class Animal {
    public:
        void speak() { std::cout << "Meow!" << std::endl; }
    };
    int main() {
        Animal cat;
        cat.speak();
        return 0;
    }
    ```

- **advanced/**  
    Introduces generic programming in C++ where algorithms are written in terms of types to-be-specified-later. It allows writing code that works with various data types without having to rewrite the code for each type. Algorithm design for sorting linear data types.

    ```cpp
    // Generic Programming Example
    #include <iostream>
    template<typename T>
    T add(T a, T b) { return a + b; }
    int main() {
        std::cout << add(2, 3) << std::endl;       // int
        std::cout << add(2.5, 3.1) << std::endl;   // double
        return 0;
    }
    ```

    ```cpp
    // Functional Programming Example
    #include <iostream>
    #include <algorithm>
    int main() {
        int arr[] = {1, 2, 3};
        std::for_each(arr, arr + 3, [](int x) { std::cout << x * x << " "; });
        std::cout << std::endl;
        return 0;
    }
    ```

## UNIX and language settings

Since this is a UNIX environment, lines in all input/output files are terminated with a single newline "\n", rather than a carriage return plus newline "\r\n"

Note that as of the December 2020 contest, input and output switched from file-based to terminal-based, using standard input and standard output (e.g., cin and cout in C++). The input and output spec of a problem will specify which mode is being used. For C++ users, you may want to add "ios_base::sync_with_stdio(false); cin.tie(0);" to the top of your main method if you are using cin/cout.

For C/C++ programmers: Programs are compiled with gcc/g++ 7.5.0 using the "-O2" optimization flag and "-lm" to access the math library, and "-std=c++11" or "-std=c++17" to enable support for C++11 or C++17. Ints are 32 bits in size; use a "long long" if you need a 64-bit integer. To read or write a long long variable with C-style I/O (e.g., scanf, printf), use the "%lld" format string.

The development of UNIX, which forms the foundation for Linux and many modern operating systems, was recognized by the Turing Award: **Dennis Ritchie and Ken Thompson** received the 1983 Turing Award for their development of generic operating systems theory and specifically for the implementation of the UNIX operating system. Their work on UNIX introduced key concepts such as hierarchical file systems, process control, and portability, which have influenced nearly all modern operating systems, including Linux. Linux itself, created by Linus Torvalds, is heavily inspired by UNIX principles.


### Basic Linux Commands for C++

Here are some simple Linux commands useful for C++ programming:

- **Show the current directory:**
    ```bash
    pwd
    ```

- **List files in the current directory:**
    ```bash
    ls -l
    ```

- **Change directory:**
    ```bash
    cd foldername
    cd ../at_parent_level
    ```

- **Print the contents of a file to the screen:**
    ```bash
    more myprogram.cpp
    ```

- **Run the compiled program:**
    ```bash
    ./myprogram
    ```

If you try to run a program in the current directory with just its name (e.g., myprogram), the shell may not find it unless `.` is in your PATH. That's why you often use `./myprogram` to run executables in the current directory.

- **Check if a file is executable:**
    ```bash
    ls -l myprogram
    ```
If you see an `x` in the permissions (e.g., `-rwxr-xr-x`), the file is executable. If not, add execute permission with:
    ```
    chmod +x myprogram
    ```

### Quitting a Running Program

To quit a running program in the terminal, you can usually press `Ctrl+C`. This sends an interrupt signal (SIGINT) to the program, causing it to terminate.

If you are running a text editor like `vim`:
- In `vim`, press `Esc`, then type `:q` and press `Enter` to quit (use `:q!` to force quit without saving).

If a program does not respond to `Ctrl+C`, you can find its process ID (PID) using `ps` or `top`, and then use `kill PID` to terminate it.
