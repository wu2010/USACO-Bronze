#include <iostream>

// Function demonstrating stack allocation (local variable)
void stackFunction() {
    int localStackVar = 100;
    std::cout << "[stackFunction] Stack variable value: " << localStackVar << std::endl;
    std::cout << "[stackFunction] Stack variable address: " << &localStackVar << std::endl;

    int stackArr[3] = {1, 2, 3};
    std::cout << "[stackFunction] Stack array: ";
    for (int i = 0; i < 3; ++i) std::cout << stackArr[i] << " ";
    std::cout << std::endl;
    std::cout << "[stackFunction] Stack array address: " << stackArr << std::endl;
}

// Function demonstrating heap allocation (dynamic memory)
void heapFunction() {
    int* localHeapVar = new int(200);
    std::cout << "[heapFunction] Heap variable value: " << *localHeapVar << std::endl;
    std::cout << "[heapFunction] Heap variable address: " << localHeapVar << std::endl;

    int* heapArr = new int[3]{4, 5, 6};
    std::cout << "[heapFunction] Heap array: ";
    for (int i = 0; i < 3; ++i) std::cout << heapArr[i] << " ";
    std::cout << std::endl;
    std::cout << "[heapFunction] Heap array address: " << heapArr << std::endl;

    delete localHeapVar;
    delete[] heapArr;
}

int main() {
    std::cout << "=== Stack Allocation Demo ===" << std::endl;
    stackFunction();

    std::cout << "\n=== Heap Allocation Demo ===" << std::endl;
    heapFunction();

    std::cout << "\n=== Example: Returning Stack Variable Address (Dangerous!) ===" << std::endl;
    int* dangerousPtr = nullptr;
    {
        int localVar = 42;
        dangerousPtr = &localVar;
        std::cout << "[Example] Address inside scope: " << dangerousPtr << ", value: " << *dangerousPtr << std::endl;
    }
    // Now localVar is out of scope, dangerousPtr is dangling!
    std::cout << "[Example] Address after scope: " << dangerousPtr << ", value: " << *dangerousPtr << " (undefined behavior!)" << std::endl;

    std::cout << "\n=== Example: Returning Heap Variable Address (Safe) ===" << std::endl;
    int* safePtr = nullptr;
    {
        safePtr = new int(99);
        std::cout << "[Example] Heap address inside scope: " << safePtr << ", value: " << *safePtr << std::endl;
    }
    // safePtr is still valid, memory lives until we delete it
    std::cout << "[Example] Heap address after scope: " << safePtr << ", value: " << *safePtr << std::endl;
    delete safePtr;

    std::cout << "\n=== Java Comparison ===" << std::endl;
    std::cout << "In Java, all objects are allocated on the heap using 'new',\n"
              << "and local variables (primitive types and references) are stored on the stack.\n"
              << "Java has automatic garbage collection, so you don't need to manually free memory.\n"
              << "Example in Java:\n"
              << "int x = 10; // stack (primitive)\n"
              << "Integer y = new Integer(20); // heap (object)\n";

    return 0;
}
/*
=== Stack Allocation Demo ===
[stackFunction] Stack variable value: 100
[stackFunction] Stack variable address: 0x16fdfeeac
[stackFunction] Stack array: 1 2 3 
[stackFunction] Stack array address: 0x16fdfeeb8

=== Heap Allocation Demo ===
[heapFunction] Heap variable value: 200
[heapFunction] Heap variable address: 0x123004080
[heapFunction] Heap array: 4 5 6 
[heapFunction] Heap array address: 0x123004090

=== Example: Returning Stack Variable Address (Dangerous!) ===
[Example] Address inside scope: 0x16fdfeef4, value: 42
[Example] Address after scope: 0x16fdfeef4, value: 42 (undefined behavior!)

=== Example: Returning Heap Variable Address (Safe) ===
[Example] Heap address inside scope: 0x123004090, value: 99
[Example] Heap address after scope: 0x123004090, value: 99

=== Java Comparison ===
In Java, all objects are allocated on the heap using 'new',
and local variables (primitive types and references) are stored on the stack.
Java has automatic garbage collection, so you don't need to manually free memory.
Example in Java:
int x = 10; // stack (primitive)
Integer y = new Integer(20); // heap (object)
*/