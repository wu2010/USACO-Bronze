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
- One's complement (`~`)

Group 10+ lower than equality (`==`) and inequality (`!=`)
- Bitwise AND (`&`), XOR (`^`), OR (`|`)


## Memory Control

- Object creation (`new`) and destruction (`delete`)
- Pointer dereference (`*`) and address-of (`&`)

### Stack vs Heap and Lifespan of Variables

In C++, memory for variables can be allocated on the **stack** or the **heap**:

- **Stack**:  
    - Local variables (declared inside functions) are stored on the stack.
    - Memory is automatically managed—allocated when the variable is declared and deallocated when the variable goes out of scope (e.g., when the function returns).
    - Fast allocation and deallocation, but limited in size.

- **Heap**:  
    - Memory allocated with `new` (or `malloc` in C) comes from the heap.
    - Used for dynamic memory allocation when the size or lifetime of data is not known at compile time.
    - Memory must be manually managed—deallocated with `delete` (or `free` in C) to avoid memory leaks.

**Lifespan of Variables:**
- **Automatic (stack) variables**: Exist only within their scope (e.g., inside a function or block).
- **Dynamic (heap) variables**: Exist until explicitly deallocated, even after the function that created them returns.
- **Static/global variables**: Exist for the entire duration of the program.

**Example:**
```cpp
void foo() {
        int x = 5;           // Stack variable, destroyed when foo() returns
        int* p = new int(10); // Heap variable, persists until delete p;
        // ...
        delete p;            // Free heap memory
}
```

### Why Pointers Are Needed for Array Types

In C++, the name of an array acts as a pointer to its first element. However, arrays themselves are not first-class objects: you cannot assign them directly, pass them by value to functions, or return them from functions. Pointers are needed to work with arrays flexibly, such as:

- **Passing arrays to functions:** When you pass an array to a function, what actually gets passed is a pointer to its first element. This allows the function to access and modify the array elements.
- **Dynamic arrays:** To create arrays whose size is determined at runtime, you must use pointers and dynamic memory allocation (e.g., `new int[n]`).
- **Manipulating array data:** Pointers allow you to iterate, access, and modify array elements efficiently using pointer arithmetic.

**Example: Creating and passing a dynamic array**
```cpp
#include <iostream>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n = 5;
    int* nums = new int[n]; // dynamically allocate array
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    printArray(nums, n); // nums is a pointer to the first element
    delete[] nums; // free dynamically allocated memory
    return 0;
}
```

See more in 
[Arrays](https://learn.microsoft.com/en-us/cpp/cpp/arrays-cpp?view=msvc-170)
and
[Pointers](https://learn.microsoft.com/en-us/cpp/cpp/pointers-cpp?view=msvc-170)


### How the Size of a Dynamically Allocated Array Is Determined

When you create a dynamically allocated array in C++ (e.g., using `new int[n]`), the size of the array is determined at runtime by the value of `n`. This allows you to allocate arrays whose size is not known until the program is running.

**Example:**
```cpp
int n;
std::cin >> n;           // User inputs the desired size
int* arr = new int[n];   // Array of size n is allocated on the heap
```

- The value of `n` can be any integer determined during program execution.
- The memory for the array is allocated on the heap, and you must use `delete[] arr;` to free it when done.
- The size of the array is not stored automatically; if you need to know the size later, you must keep track of it yourself (e.g., by storing `n` in a variable).

**Note:** Accessing elements outside the bounds of the allocated array leads to undefined behavior.


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

### Example: Defining and Using a Class

```cpp
#include <iostream>
#include <string>

class Animal {
private:
    std::string name;
    int age;

public:
    // Default constructor
    Animal() : name(""), age(0) {}

    // Destructor
    ~Animal() {
        // Cleanup code if needed
    }

    // Parameterized constructor
    Animal(const std::string& n, int a) : name(n), age(a) {}

    // Copy constructor
    Animal(const Animal& other) : name(other.name), age(other.age) {}

    // Copy assignment operator
    Animal& operator=(const Animal& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Accessor (getter) functions
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Mutator (setter) functions
    void setName(const std::string& n) { name = n; }
    void setAge(int a) { age = a; }

    // Example member function
    void speak() const {
        std::cout << name << " says hello!" << std::endl;
    }
}
```

### Member Access Operators (`.` and `->`)

In C++, member access operators are used to access members (variables and functions) of classes, structs, and unions.

- The **dot operator** (`.`) is used when you have an object (not a pointer) to access its members.
- The **arrow operator** (`->`) is used when you have a pointer to an object to access its members.

**Examples:**
```cpp
Animal a("Dog", 3);
a.speak();      // Use . to call member function

Animal* p = &a;
p->speak();     // Use -> to call member function via pointer
```

- Use `object.member` when you have an object.
- Use `pointer->member` when you have a pointer to an object.

This distinction is important when working with dynamically allocated objects or when passing objects by pointer to functions.

### Should You Use Class Objects on the Stack?

Yes, in C++ it is generally recommended to use class objects on the **stack** whenever possible. Stack allocation is:

- **Automatic**: Objects are created and destroyed automatically as they enter and leave scope.
- **Efficient**: Stack allocation and deallocation are very fast.
- **Safe**: No risk of memory leaks, since memory is managed automatically.

Use heap allocation (`new`/`delete`) only when:
- The object's lifetime must extend beyond the current scope.
- The size or number of objects is not known at compile time.

**Example (preferred):**
```cpp
Animal a("Dog", 3); // Stack allocation
a.speak();
```

**Example (only if needed):**
```cpp
Animal* p = new Animal("Dog", 3); // Heap allocation
p->speak();
delete p;
```

**Summary:**  
Prefer stack allocation for class objects unless you have a specific reason to use the heap.


### Using `new` and `delete` with Classes

In C++, you can create objects dynamically (on the heap) using the `new` operator, and you must release the memory using `delete` when done. This is useful when the object's lifetime needs to extend beyond the current scope or when the size or number of objects is determined at runtime.

**Example: Creating and deleting a class object dynamically**
```cpp
Animal* a = new Animal("Dog", 3); // dynamically allocate an Animal
a->speak();                       // use the object via pointer
delete a;                         // free memory, calls destructor
```

**For arrays of objects:**
```cpp
int n = 2;
Animal* arr = new Animal[n]; // dynamically allocate array of Animals
arr[0].setName("Cat");
arr[1].setName("Bird");
delete[] arr;                // use delete[] for arrays
```

- Use `new` to allocate, `delete` to deallocate a single object.
- Use `new[]` and `delete[]` for arrays of objects.
- Always ensure `delete` is called to avoid memory leaks.
- The destructor is automatically called when `delete` is used.


## Exception Handling

[Exception](https://learn.microsoft.com/en-us/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-170)

### Example: `out_of_range` and `invalid_argument`

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

int main() {
    try {
        std::vector<int> v = {1, 2, 3};
        // Throws std::out_of_range if index is invalid
        std::cout << v.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range error: " << e.what() << std::endl;
    }

    try {
        // stoi: string to integer
        int n = std::stoi("abc"); // Throws std::invalid_argument
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid argument error: " << e.what() << std::endl;
    }
    return 0;
}
```

## More on Functions

[Functions](https://learn.microsoft.com/en-us/cpp/cpp/functions-cpp?view=msvc-170)

[Lambda expression](https://learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)


## More on Data Types

Collection data types (containers), in various programming languages and database systems, are specialized data structures designed to store and manage groups of related data elements. The core concept is to hold multiple values, usually of the same type, within a single variable or container.

Arrays: Ordered collections of elements of the same data type, accessed by index.
- bit (bool) -> bitset
- char -> string
- floating-point type or integer type -> vector

### Why `vector`, `string`, and `bitset` Are Favored Over Native Arrays (per Stroustrup)

Bjarne Stroustrup, the creator of C++, and the modern C++ community recommend using standard library types like `std::vector`, `std::string`, and `std::bitset` instead of native arrays for most use cases. The reasons include:

- **Safety**: These types provide bounds checking (e.g., `at()` for `vector` and `string`), reducing the risk of buffer overflows and undefined behavior.
- **Automatic Memory Management**: They handle memory allocation and deallocation automatically, preventing memory leaks and dangling pointers.
- **Ease of Use**: They support assignment, copying, resizing, and other operations that are cumbersome or unsafe with raw arrays.
- **Standard Algorithms Compatibility**: They work seamlessly with C++ standard algorithms and iterators.
- **Self-Describing**: Unlike native arrays, these types know their own size and can report it via `.size()`.
- **Performance**: Modern implementations are highly optimized and often as fast as, or faster than, hand-written array code.

**Summary Table:**

| Type         | Use Case                        | Advantages Over Native Arrays                |
|--------------|---------------------------------|----------------------------------------------|
| `std::vector`| Dynamic arrays (resizable)      | Safe, resizable, easy to use                 |
| `std::string`| Text and character sequences    | Safe, convenient, rich functionality         |
| `std::bitset`| Fixed-size bit manipulation     | Type-safe, efficient, easy bit operations    |

**References:**
- [Why you should use vector and string (Stroustrup FAQ)](https://www.stroustrup.com/bs_faq2.html#vector)
- [C++ Core Guidelines: Use vector by default](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#slcon1-use-vector-by-default-unless-you-have-a-reason-not-to)
