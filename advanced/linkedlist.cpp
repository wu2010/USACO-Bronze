#include <iostream>

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {

private:
    Node* head; // Pointer to the head of the list
    int list_size; // Size of the list

public:
    // Constructor
    LinkedList() : head(nullptr), list_size(0) {}

    // Insert at the end
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = newNode;
        }
        ++list_size;
    }

    // Insert at the beginning
    void addFirst(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        ++list_size;
    }

    // Insert at a specific index
    void insert(int index, int val) {
        if (index < 0 || index > list_size) return;
        if (index == 0) {
            addFirst(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* curr = head;
        for (int i = 0; i < index - 1; ++i) curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
        ++list_size;
    }

    // Remove first occurrence of value
    bool remove(int val) {
        Node* curr = head;
        Node* prev = nullptr;
        while (curr) {
            if (curr->data == val) {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                delete curr;
                --list_size;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    // Remove at index
    bool removeAt(int index) {
        if (index < 0 || index >= list_size) return false;
        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = curr;
            curr = curr->next;
        }
        if (prev) prev->next = curr->next;
        else head = curr->next;
        delete curr;
        --list_size;
        return true;
    }

    // Get value at index
    int get(int index) const {
        if (index < 0 || index >= list_size) throw std::out_of_range("Index out of range");
        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        return curr->data;
    }

    // Set value at index
    void set(int index, int val) {
        if (index < 0 || index >= list_size) throw std::out_of_range("Index out of range");
        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        curr->data = val;
    }

    // Check if list contains value
    bool contains(int val) const {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    // Get index of value, -1 if not found
    int indexOf(int val) const {
        Node* curr = head;
        int idx = 0;
        while (curr) {
            if (curr->data == val) return idx;
            curr = curr->next;
            ++idx;
        }
        return -1;
    }

    // Get size of list
    int size() const {
        return list_size;
    }

    // Check if list is empty
    bool isEmpty() const {
        return list_size == 0;
    }

    // Print the list
    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

};

int main() {

    // Example usage of LinkedList
    LinkedList list;
    list.append(10);
    list.append(20);
    list.addFirst(5);
    list.insert(1, 15); // 5 15 10 20
    list.print();

    std::cout << "Contains 10? " << list.contains(10) << std::endl;
    std::cout << "Index of 20: " << list.indexOf(20) << std::endl;
    std::cout << "Element at 2: " << list.get(2) << std::endl;

    list.set(2, 100);
    list.print();

    list.remove(15);
    list.print();

    list.removeAt(0);
    list.print();

    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Is empty? " << list.isEmpty() << std::endl;

    return 0;
}