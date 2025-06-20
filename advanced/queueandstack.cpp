#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <list>

int main() {
    /* explain stack and queue
        Stack is a LIFO (Last In First Out) data structure, where the last element 
            added is the first one to be removed.
        Queue is a FIFO (First In First Out) data structure, where the first element 
            added is the first one to be removed.
        Both can be implemented using different underlying containers like 
            std::vector, std::deque, or std::list.
    */

    // Stack and Queue examples using C++ Standard Library
    // Stack using std::vector (default)
    std::stack<int> stack_vec;
    stack_vec.push(1);
    stack_vec.push(2);
    stack_vec.push(3);
    std::cout << "Stack (vector): ";
    while (!stack_vec.empty()) {
        std::cout << stack_vec.top() << " ";
        stack_vec.pop();
    }
    std::cout << std::endl;

    // Stack using std::deque
    std::stack<int, std::deque<int>> stack_deque;
    stack_deque.push(4);
    stack_deque.push(5);
    stack_deque.push(6);
    std::cout << "Stack (deque): ";
    while (!stack_deque.empty()) {
        std::cout << stack_deque.top() << " ";
        stack_deque.pop();
    }
    std::cout << std::endl;

    // Queue using std::deque (default)
    std::queue<int> queue_deque;
    queue_deque.push(7);
    queue_deque.push(8);
    queue_deque.push(9);
    std::cout << "Queue (deque): ";
    while (!queue_deque.empty()) {
        std::cout << queue_deque.front() << " ";
        queue_deque.pop();
    }
    std::cout << std::endl;

    // Queue using std::list
    std::queue<int, std::list<int>> queue_list;
    queue_list.push(10);
    queue_list.push(11);
    queue_list.push(12);
    std::cout << "Queue (list): ";
    while (!queue_list.empty()) {
        std::cout << queue_list.front() << " ";
        queue_list.pop();
    }
    std::cout << std::endl;

    /* differences between list and deque
        std::list is a doubly linked list, which allows for efficient insertions and
            deletions at both ends, but it does not provide random access like std::deque
        std::deque is a double-ended queue that allows for efficient insertions and deletions
            at both ends and provides random access to elements, making it more versatile 
            for many use cases.

        why deque can support both random access and efficient insertions/deletions?
            std::deque is implemented as a sequence of fixed-size arrays, which allows 
            it to provide constant time access to elements by index (like an array) 
            while also allowing for efficient insertions and deletions at both ends 
            (like a linked list). This makes it suitable for scenarios where both 
            random access and efficient modifications are needed.    
    */

    // working with std::deque (random access and efficient insertions/deletions)
    std::deque<int> deque_example = {13, 14, 15, 16, 17};
    std::cout << "Deque example: ";
    for (const auto& elem : deque_example) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Demonstrating random access
    std::cout << "Element at index 2: " << deque_example[2] << std::endl;
    std::cout << "Element at index 0: " << deque_example.at(0) << std::endl;
    std::cout << "Element at index 4: " << deque_example.back() << std::endl;

    // Demonstrating efficient insertions and deletions
    deque_example.push_front(12);
    deque_example.push_back(18);
    std::cout << "After push_front(12) and push_back(18): ";
    for (const auto& elem : deque_example) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    deque_example.pop_front();
    deque_example.pop_back();
    std::cout << "After pop_front() and pop_back(): ";
    for (const auto& elem : deque_example) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;


    return 0;
}
/*
Stack (vector): 3 2 1 
Stack (deque): 6 5 4 
Queue (deque): 7 8 9 
Queue (list): 10 11 12 
Deque example: 13 14 15 16 17 
Element at index 2: 15
Element at index 0: 13
Element at index 4: 17
After push_front(12) and push_back(18): 12 13 14 15 16 17 18 
After pop_front() and pop_back(): 13 14 15 16 17 
*/