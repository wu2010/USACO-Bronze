
## Python Grammar

Here is a simple BNF (Backus-Naur Form) description for a subset of Python:

```
<program> ::= <statement_list>
<statement_list> ::= <statement> | <statement> <statement_list>
<statement> ::= <assignment> | <if_statement> | <while_statement> | <function_def>
<assignment> ::= <identifier> "=" <expression>
<if_statement> ::= "if" <expression> ":" <statement_list> ["else" ":" <statement_list>]
<while_statement> ::= "while" <expression> ":" <statement_list>
<function_def> ::= "def" <identifier> "(" [<parameters>] ")" ":" <statement_list>
<parameters> ::= <identifier> | <identifier> "," <parameters>
<expression> ::= <identifier> | <number> | <expression> <operator> <expression>
<operator> ::= "+" | "-" | "*" | "/" | "==" | "!=" | "<" | ">" | "<=" | ">="
<identifier> ::= /* a valid Python identifier */
<number> ::= /* a numeric literal */
```

This BNF covers basic constructs like assignments, conditionals, loops, and function definitions.


## Why C++ BNF Includes Declarations but Python's Focuses on Statements

C++ is a statically typed language, so variables and functions must be declared with their types before use. Its BNF includes explicit rules for declarations (e.g., variable and function declarations).

Python is dynamically typed and does not require explicit type declarations. Variables are created by assignment, and functions are defined with `def`. Therefore, Python's BNF focuses on statements and expressions rather than declarations.

This difference reflects the languages' type systems and design philosophies.


## Minimal Python Code Example

Here is the smallest valid Python program:

```python
pass
```

The `pass` statement does nothing and is used as a placeholder.


## Entry Point in Python

Unlike some languages, Python does not require a special `main` function as the entry point. However, a common convention is to use the following pattern:

```python
def main():
    # Your program logic here
    print("Hello, world!")

if __name__ == "__main__":
    main()
```

The `if __name__ == "__main__":` block ensures that `main()` is only called when the script is run directly, not when imported as a module.


## Running Code from Multiple Files

To organize code across multiple files in Python, you can use modules and the `import` statement. For example, suppose you have two files:

**utils.py**
```python
def greet(name):
    print(f"Hello, {name}!")
```

**main.py**
```python
from utils import greet

def main():
    greet("Alice")

if __name__ == "__main__":
    main()
```

Run the program by executing `main.py`:
```sh
python main.py
```

This approach allows you to reuse code and keep your project organized.


## Heap vs Stack in Python (Compared to Java and C++)

In **Java**, memory management distinguishes clearly between stack and heap:
- **Stack**: Stores local variables and function call information. Each thread has its own stack.
- **Heap**: Stores objects and arrays. Objects are allocated on the heap and managed by the garbage collector.

In **Python**:
- **Stack**: Used for function call frames (local variables, execution context). Each thread has its own call stack.
- **Heap**: All objects (including integers, lists, functions, etc.) are allocated on the heap. Variable names are references to heap objects.
- Python's memory management and garbage collection are handled automatically (using reference counting and a cyclic garbage collector).

In **C++**:
- **Stack**: Stores local variables, function call information, and objects with automatic storage duration. Fast allocation and deallocation.
- **Heap**: Used for dynamic memory allocation (via `new`/`delete` or `malloc`/`free`). The programmer is responsible for managing heap memory.
- No built-in garbage collector; memory leaks can occur if heap memory is not properly released.

**Key Differences:**
- In Java, primitive types (like `int`, `double`) can be stored on the stack, but in Python, all values are objects on the heap.
- In C++, both primitives and objects can be stack-allocated or heap-allocated, depending on how they are declared. C++ requires explicit memory management for heap allocations.
- Python abstracts away most memory management details, so programmers rarely need to think about stack vs heap.

**Summary Table:**

| Aspect         | Java                          | Python                         | C++                                 |
|----------------|------------------------------|--------------------------------|-------------------------------------|
| Stack          | Primitives, call frames      | Call frames only               | Primitives, objects, call frames    |
| Heap           | Objects, arrays              | All objects                    | Objects, arrays (via `new`/`malloc`)|
| Memory Control | Explicit types, some control | Fully automatic, dynamic types | Manual (heap), explicit types       |
| GC             | Yes                          | Yes                            | No (manual deallocation)            |


## Abstract Data Types (ADT) in Python

An **Abstract Data Type (ADT)** defines a data structure by its behavior (operations and properties), not by its implementation. In Python, ADTs are typically implemented using classes, which encapsulate data and provide methods for interacting with it.

### Built-in ADTs

Python provides several built-in ADTs, such as:
- **List** (`list`): dynamic arrays
- **Dictionary** (`dict`): key-value mappings
- **Set** (`set`): unordered collections of unique elements
- **Tuple** (`tuple`): immutable sequences

These types have well-defined interfaces and behaviors, abstracting away implementation details.

### Custom ADTs

You can define your own ADTs using classes:

```python
class Stack:
    def __init__(self):
        self._items = []

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self._items.pop()

    def is_empty(self):
        return not self._items
```

Here, `Stack` is an ADT: users interact with it via `push`, `pop`, and `is_empty` without needing to know how the data is stored internally.

### Duck Typing

Python uses **duck typing**: if an object implements the required methods, it can be used as that ADT, regardless of its actual class. This makes ADT usage flexible and idiomatic in Python.



## Programming Paradigm of Python

Python is a **multi-paradigm programming language**. It supports several programming paradigms, including:

- **Imperative programming**: Writing code as a sequence of statements that change program state.
- **Object-oriented programming (OOP)**: Organizing code using classes and objects, supporting encapsulation, inheritance, and polymorphism.
- **Functional programming**: Treating functions as first-class objects, supporting higher-order functions, map/filter/reduce, and lambda expressions.
- **Procedural programming**: Structuring code into procedures (functions) for modularity and reuse.

This flexibility allows developers to choose the most suitable paradigm or combine them as needed for a given problem.

### Examples

#### Imperative Programming

```python
x = 10
y = 20
z = x + y
print(z)
```

#### Object-Oriented Programming

```python
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(f"{self.name} makes a sound.")

dog = Animal("Dog")
dog.speak()
```

#### Functional Programming

```python
numbers = [1, 2, 3, 4]
squared = list(map(lambda x: x ** 2, numbers))
print(squared)
```

#### Procedural Programming

```python
def greet(name):
    print(f"Hello, {name}!")

greet("Alice")
```


## Calling C++ Libraries from Python to Accelerate Speed

To leverage C++ code for performance-critical parts of your Python program, you can build your C++ code as a shared library and call it from Python. Common approaches include:

### 1. Using `ctypes`

- Compile your C++ code as a shared library (`.so` on Linux/macOS, `.dll` on Windows).
- Use Python's built-in `ctypes` module to load and call functions.

**Calling Multiple C++ Functions**

You can expose multiple C++ functions to Python using the same approach. For example, with `ctypes`:

C++ code (`mylib.cpp`):
```cpp
extern "C" int add(int a, int b) {
    return a + b;
}

extern "C" int multiply(int a, int b) {
    return a * b;
}
```
Compile:
```sh
g++ -shared -fPIC -o libmylib.so mylib.cpp
```

Python code:
```python
import ctypes

mylib = ctypes.CDLL('./libmylib.so')
add = mylib.add
add.argtypes = [ctypes.c_int, ctypes.c_int]
add.restype = ctypes.c_int

multiply = mylib.multiply
multiply.argtypes = [ctypes.c_int, ctypes.c_int]
multiply.restype = ctypes.c_int

print(add(2, 3))        # Output: 5
print(multiply(2, 3))   # Output: 6
```

### 2. Using `cffi`

- Write C declarations and use the `cffi` package to interface with your library.

### 3. Using `pybind11` (Recommended for Modern C++)

- Write C++ code with `pybind11` bindings.
- Build a Python extension module.

**Example:**

With `pybind11`, you can define and expose multiple functions in the module:

C++ code (`example.cpp`):
```cpp
#include <pybind11/pybind11.h>
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
PYBIND11_MODULE(example, m) {
    m.def("add", &add, "Add two numbers");
    m.def("multiply", &multiply, "Multiply two numbers");
}
```

Python code:
```python
import example
print(example.add(2, 3))        # Output: 5
print(example.multiply(2, 3))   # Output: 6
```

You can expose as many functions as needed using these methods.


### 4. Using `Cython`

- Write Python-like code that calls C/C++ functions.
- Compile with Cython to generate a Python extension.


**Example: Using Cython**

Suppose you have a C function you want to call from Python.

1. **Write a Cython file (`mymath.pyx`):**
    ```cython
    cpdef int add(int a, int b):
        return a + b
    ```

2. **Create a `setup.py` to build the extension:**
    ```python
    from setuptools import setup
    from Cython.Build import cythonize

    setup(
        ext_modules=cythonize("mymath.pyx")
    )
    ```

3. **Build the extension:**
    ```sh
    python setup.py build_ext --inplace
    ```

4. **Use it in Python:**
    ```python
    import mymath
    print(mymath.add(2, 3))  # Output: 5
    ```

Cython makes it easy to write fast code that integrates seamlessly with Python.


---

**Summary:**  
- Use `ctypes` or `cffi` for simple C interfaces.
- Use `pybind11` or `Cython` for more complex C++ integration.
- This allows you to accelerate Python code by offloading performance-critical parts to C++.
