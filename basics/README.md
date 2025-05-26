# Understanding C++ Grammar, Procedural Programming, and Scoping Rules

A **language grammar** formally defines the syntax rules for constructing valid programs in a programming language. It specifies how symbols, keywords, and structures (like expressions, statements, and functions) can be combined, enabling both humans and computers to understand and process code. Grammars are typically described using notations such as Backus-Naur Form (BNF).

A grammar is often **recursively defined**, meaning some rules are specified in terms of themselves. For example, a rule for a list of statements might allow a statement followed by another list of statements, enabling the grammar to describe sequences of arbitrary length. This recursive structure is essential for expressing the nested and repetitive patterns found in programming languages.


## Relationship to Procedural Programming

The C++ grammar outlined below closely aligns with the principles of procedural programming. Procedural programming is a programming paradigm based on the concept of procedure calls, where programs are organized as sequences of instructions grouped into functions (procedures).

- **Functions as Procedures**: The grammar includes rules for defining functions (`<function-definition>`), which are the primary building blocks in procedural programming. Each function encapsulates a specific task or procedure.
- **Statements and Control Flow**: Constructs like `<statement>`, `<selection-statement>`, and `<iteration-statement>` represent the step-by-step instructions and control flow mechanisms (such as `if`, `else`, `for`, and `while` loops) that are central to procedural code.
- **Variable Declarations and Scope**: The grammar supports variable declarations and scoping rules, allowing data to be managed locally within procedures or globally, as is typical in procedural languages.
- **Top-Down Structure**: Programs are structured as a sequence of declarations and statements, executed in a defined order, which is characteristic of procedural programming.

In summary, the grammar provides the syntactic foundation for writing procedural C++ programs, where computation is organized into procedures (functions), and control flows through statements and expressions in a linear or structured manner.

### Elements of C++ Grammar

From a language parser's perspective, a C++ program is typically structured as follows:

1. **Preprocessing Directives**: Lines starting with `#` (e.g., `#include`, `#define`) are handled before actual parsing.
2. **Declarations and Definitions**: These include variable declarations, function prototypes, and type definitions.
3. **Function Definitions**: The main function (`int main()`) and any other user-defined or library functions.
4. **Statements and Expressions**: The body of functions contains statements (e.g., loops, conditionals) and expressions.
5. **Scopes and Namespaces**: Code is organized into scopes (curly braces `{}`) and may use namespaces for name resolution.

The parser processes the code according to the C++ grammar, building an abstract syntax tree (AST) that represents the program's structure for further compilation stages.

### C++ Grammar Highlights

Below is a simplified excerpt of C++ grammar using [Backus-Naur Form (BNF)](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form):

```bnf
<program> ::= <declaration-seq>
<declaration-seq> ::= <declaration> | <declaration-seq> <declaration>
<declaration> ::= <function-definition> | <variable-declaration> | ...
<function-definition> ::= <type-specifier> <identifier> "(" <parameter-list> ")" <compound-statement>
<compound-statement> ::= "{" <statement-seq> "}"
<statement-seq> ::= <statement> | <statement-seq> <statement>
<statement> ::= <variable-declaration> | <expression-statement> | <selection-statement> | <iteration-statement> | ...
```

This grammar guides the parser in recognizing valid C++ constructs and their hierarchical relationships.


## Illustrations 

### Example: Variable Declaration in C++

A variable declaration introduces a new variable and specifies its type. For example:

```cpp
int x;        // declares an integer variable named x
double pi;    // declares a double-precision floating-point variable named pi
char letter;  // declares a character variable named letter
```

You can also initialize variables at the time of declaration:

```cpp
int y = 10;
double radius = 3.14;
char grade = 'A';
```

In the BNF grammar above, `<variable-declaration>` represents such statements.

### Example: Expression Statement in C++

An expression statement consists of an expression followed by a semicolon. It is commonly used for assignments, function calls, increment/decrement operations, and more. For example:

```cpp
x = 5;           // assignment expression
y++;             // increment expression
std::cout << x;  // function call (output)
```

In the BNF grammar, `<expression-statement>` represents these types of statements.


### Example: A Simple C++ Program

Using the BNF grammar above, here's how the elements combine to form a complete C++ program:

```cpp
#include <iostream>  // Preprocessing directive

int main() {         // Function definition
    int x = 5;       // Variable declaration and initialization
    double y = 2.5;  // Variable declaration and initialization
    x = x + 1;       // Expression statement (assignment)
    std::cout << x << " " << y << std::endl; // Expression statement (function call)
    return 0;        // Expression statement (return)
}
```

**Breakdown according to the BNF:**

- `<program>`: The entire file.
- `<declaration-seq>`: Includes the preprocessing directive and the `main` function definition.
- `<function-definition>`: The `main` function.
- `<compound-statement>`: The body of `main`, enclosed in `{}`.
- `<statement-seq>`: The sequence of statements inside `main`.
- `<statement>`: Each line inside the function body (variable declarations, assignments, function calls, return).

This example demonstrates how C++ grammar rules are used to structure a valid program.

### Example: C++ Program with an Extra Function and Selection Statement

Here's a more complex C++ program that includes an additional function, a compound statement, and a selection statement (`if-else`):

```cpp
#include <iostream>

int square(int n) {           // Function definition
    int result = n * n;       // Variable declaration and initialization
    return result;            // Return statement
}

int main() {
    int value = 7;
    int sq = square(value);   // Function call

    // Selection statement (if-else)
    if (sq > 40) {
        std::cout << "Square is large: " << sq << std::endl;
    } else {
        std::cout << "Square is small: " << sq << std::endl;
    }

    return 0;
}
```

**Breakdown according to the BNF:**

- `<function-definition>`: Both `square` and `main` functions.
- `<compound-statement>`: The bodies of both functions, enclosed in `{}`.
- `<statement-seq>`: The sequence of statements inside each function.
- `<statement>`: Variable declarations, assignments, function calls, selection statement, and return statements.
- `<selection-statement>`: The `if-else` block inside `main`.

This example illustrates how functions, compound statements, and selection statements are represented in C++ grammar.

### Note: Selection Statements and Compound Statements

In C++ grammar, a `<selection-statement>` (such as `if`, `if-else`, or `switch`) can contain either a single statement or a compound statement (a block enclosed in `{}`) as its body. This allows you to execute multiple statements conditionally by grouping them within curly braces. For example:

```cpp
if (condition)
    statement;  // single statement

if (condition) {
    statement1;
    statement2;
} // compound statement
```

In the BNF, this is typically represented as:

```bnf
<selection-statement> ::= "if" "(" <expression> ")" <statement> [ "else" <statement> ]
```

Here, `<statement>` can be a simple statement or a `<compound-statement>`, enabling flexible control flow structures.

## Scoping Rules in C++

Scoping rules determine the visibility and lifetime of variables and other identifiers in a C++ program. A *scope* is a region of the program where a name (such as a variable or function) is valid and accessible. The development of scoping rules in programming languages is closely tied to the evolution of language design and compiler theory. **Niklaus Wirth** (Turing Award 1984) explicitly designed languages such as Pascal, Modula, and Oberon with block structure and lexical scoping, making scope rules clear and central to language semantics.

### Types of Scopes

1. **Block Scope**: Names declared inside a pair of curly braces `{}` are only accessible within that block. For example, variables declared inside a function or an `if` statement are not accessible outside of it.
2. **Function Scope**: Labels (used with `goto`) have function scope, meaning they are visible throughout the function in which they are declared.
3. **File Scope (Global Scope)**: Names declared outside of all functions and classes are accessible from their point of declaration to the end of the file, unless shadowed by a local declaration.
4. **Class Scope**: Members declared inside a class are accessible within the class and according to access specifiers (`public`, `protected`, `private`).

### Example: Block Scope

```cpp
int main() {
    int x = 10; // x is visible throughout main
    if (x > 5) {
        int y = 20; // y is only visible inside this block
        x = y;
    }
    // y is not accessible here
    return 0;
}
```

In this example, `y` is only accessible within the `if` block, while `x` is accessible throughout the `main` function.

### Shadowing

A variable declared in an inner scope can *shadow* a variable with the same name in an outer scope. The inner declaration temporarily hides the outer one within its scope.

```cpp
int x = 5;
void foo() {
    int x = 10; // shadows the global x within foo
    // use x = 10 here
}
// use x = 5 outside foo
```

Understanding scoping rules is essential for writing correct and maintainable C++ programs, as it helps prevent naming conflicts and unintended side effects.

