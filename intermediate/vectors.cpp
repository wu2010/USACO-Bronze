/*
    DemoVector<T> - A simplified demonstration of a dynamic array similar to std::vector.

    Key Concepts:
    -------------
    - Dynamic Array: Manages a contiguous memory block for elements of type T.
    - Manual Memory Management: Uses std::allocator<T> for allocation, construction, and destruction.
    - Automatic Growth: Doubles capacity when needed to amortize reallocation cost.
    - Move Semantics: Supports efficient moves with push_back(T&&).
    - Exception Safety: Throws std::out_of_range for invalid access and pop_back on empty vector.
    - Iterator Support: Provides begin()/end() for range-based for loops.
    - Initializer List: Allows construction from an initializer list.

    Member Functions:
    -----------------
    - DemoVector(): Default constructor, creates an empty vector.
    - DemoVector(std::initializer_list<T>): Constructs vector from a list of elements.
    - ~DemoVector(): Destructor, destroys all elements and deallocates memory.
    - void push_back(const T& value): Appends a copy of value to the end.
    - void push_back(T&& value): Appends a moved value to the end.
    - void pop_back(): Removes the last element, throws if empty.
    - void reserve(size_t new_cap): Ensures capacity is at least new_cap. (if needed, allocates new memory, moves existing elements, and cleans up old memory.)
    - void clear(): Destroys all elements, keeps capacity.
    - size_t size() const: Returns the number of elements.
    - size_t capacity() const: Returns the allocated capacity.
    - bool empty() const: Checks if the vector is empty.
    - T& operator[](size_t idx): Accesses element without bounds checking.
    - const T& operator[](size_t idx) const: Const version of operator[].
    - T& at(size_t idx): Accesses element with bounds checking.
    - const T& at(size_t idx) const: Const version of at().
    - T* begin(), T* end(): Iterators for range-based for loops.
    - const T* begin() const, const T* end() const: Const iterators.

    Example Usage:
    --------------
        DemoVector<int> v = {1, 2, 3};
        v.push_back(4);
        for (auto x : v) std::cout << x << " ";

    Notes:
    ------
    - This class is for educational/demo purposes and omits many optimizations and features of std::vector.
    - Not thread-safe.
    - No support for custom allocators beyond std::allocator.
*/

#include <memory>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

template <typename T>
class DemoVector {
    T* data_;
    size_t size_;
    size_t capacity_;

    // Use std::allocator for memory management
    // This allows us to construct, destroy, and allocate memory for T objects.
    std::allocator<T> alloc_;

public:
    DemoVector() : data_(nullptr), size_(0), capacity_(0) {}

    // Constructor that takes an initializer list, e.g. DemoVector<int> v = {1, 2, 3};
    // This allows us to create a DemoVector from a list of elements.
    DemoVector(std::initializer_list<T> ilist)
        : data_(nullptr), size_(0), capacity_(0) {
        reserve(ilist.size());
        for (const auto& elem : ilist) {
            push_back(elem);
        }
    }

    // Reserve memory for at least new_cap elements.
    void reserve(size_t new_cap) {
        if (new_cap <= capacity_) {
            return; // No need to reallocate if we already have enough capacity
        }

        // Reallocate memory to a new capacity, moving existing elements
        // and destroying the old ones.
        T* new_data = alloc_.allocate(new_cap);
        for (size_t i = 0; i < size_; ++i) {
            alloc_.construct(new_data + i, std::move_if_noexcept(data_[i]));
            alloc_.destroy(data_ + i);
        }
        if (data_) alloc_.deallocate(data_, capacity_);
        data_ = new_data;
        capacity_ = new_cap;
    }

    ~DemoVector() {
        clear();
        if (data_) alloc_.deallocate(data_, capacity_);
    }

    void push_back(const T& value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        alloc_.construct(data_ + size_, value);
        ++size_;
    }

    // Move version of push_back
    // This allows efficient insertion of rvalue references.
    void push_back(T&& value) {
        if (size_ == capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        alloc_.construct(data_ + size_, std::move(value));
        ++size_;
    }

    void pop_back() {
        if (size_ == 0) throw std::out_of_range("pop_back on empty vector");
        alloc_.destroy(data_ + --size_);
    }

    void clear() {
        for (size_t i = 0; i < size_; ++i) {
            alloc_.destroy(data_ + i);
        }
        size_ = 0;
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    // Access elements with operator[] without bounds checking
    T& operator[](size_t idx) { return data_[idx]; }
    const T& operator[](size_t idx) const { return data_[idx]; }

    // Access elements with bounds checking
    // Throws std::out_of_range if idx is out of bounds.
    T& at(size_t idx) {
        if (idx >= size_) throw std::out_of_range("vector::at");
        return data_[idx];
    }
    const T& at(size_t idx) const {
        if (idx >= size_) throw std::out_of_range("vector::at");
        return data_[idx];
    }

    // Iterator support for range-based for loops
    T* begin() { return data_; }
    T* end() { return data_ + size_; }
    const T* begin() const { return data_; }
    const T* end() const { return data_ + size_; }

    
    // in C++17, move semantics are used to transfer ownership of resources without copying.
    // This allows us to efficiently move elements in and out of the vector. 
    
};

// Example usage
#include <iostream>
int main() {
    DemoVector<int> v = {1, 2, 3};
    v.push_back(4);
    for (auto x : v) std::cout << x << " ";
    std::cout << std::endl;
}
/*
1 2 3 4 
*/