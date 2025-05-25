## Operators

[The following table shows](https://learn.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=msvc-170) the precedence and associativity of C++ operators (from highest to lowest precedence). Operators with the same precedence number have equal precedence unless another relationship is explicitly forced by parentheses. 

High precedence operators include: 

Group 1 precedence, no associativity	
- Scope resolution	(`::`)

Group 2 precedence, left to right associativity
- Function call (`()`)
- Array subscripting (`[]`)
- Member access (`.` and `->`)

Group 3 precedence, right to left associativity	
- Object creation (`new`) and destruction (`delete`)
- Pointer dereference (`*`) and address-of (`&`)

- Bitwise AND (`&`), XOR (`^`), OR (`|`)


## Memory Control

[Arrays](https://learn.microsoft.com/en-us/cpp/cpp/arrays-cpp?view=msvc-170)

scope vs lifespan

[Pointers](https://learn.microsoft.com/en-us/cpp/cpp/pointers-cpp?view=msvc-170)

Most built-in types have implementation-defined sizes. The following table lists the amount of storage required for built-in types in Microsoft C++. In particular, long is 4 bytes even on 64-bit operating systems. 
- `bool`, `char`: 1 byte. range -128 to 127 or 0 to 255
- `short`: 2 bytes. range -32768 to 32767 or 0 to 65535 (= 2^16-1)
- `float`, `int`, `long`: 4 bytes
- `double`, `long long`: 8 bytes

The smallest positive number x, such that x + 1.0 is not equal to 1.0.
- `float`: 1.192092896e-07F
- `double`: 2.2204460492503131e-016


## Object Oriented Programming

[Classes](https://learn.microsoft.com/en-us/cpp/cpp/classes-and-structs-cpp?view=msvc-170)

An "abstract class type," often shortened to "abstract type" or "AST," refers to a class in object-oriented programming that cannot be directly instantiated (created as an object). 


## Exception Handling

[Exception](https://learn.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170)


## More on Functions

[Functions](https://learn.microsoft.com/en-us/cpp/cpp/functions-cpp?view=msvc-170)

[Lambda expression](https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)


## More on Data Types

Collection data types (containers), in various programming languages and database systems, are specialized data structures designed to store and manage groups of related data elements. The core concept is to hold multiple values, usually of the same type, within a single variable or container.

Arrays: Ordered collections of elements of the same data type, accessed by index.
- bit (bool) -> bitset
- char -> string
- floating-point type or integer type -> vector
