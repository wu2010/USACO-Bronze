/*
    String - A demo string class inspired by std::string

    Design Highlights:
    - Manages dynamic character storage with manual memory management.
    - Provides value semantics: copy constructor, copy assignment, and destructor.
    - Maintains size and capacity for efficient appending (push_back, operator+=).
    - Ensures null-terminated storage for C-string compatibility (c_str()).
    - Offers bounds-checked (at) and unchecked (operator[]) element access.
    - Supports comparison operators (==, !=) for string equality.
    - Implements basic modifiers: push_back, pop_back, clear, operator+=.
    - Stream output operator (operator<<) for easy printing.
    - Exception safety: throws std::out_of_range on invalid access.
    - No move semantics (for simplicity in this demo).
    - No allocator support (unlike std::string).
    - Not thread-safe (like std::string).
    - Minimal interface for demonstration and educational purposes.
*/

#include <iostream>
#include <cstring>
#include <stdexcept>

class DemoString {
    char* data_;
    size_t size_;
    size_t capacity_;

    // Ensures that the internal storage has enough capacity for new size
    // If not, it allocates more memory and copies existing data.
    void ensure_capacity(size_t new_cap) {
        if (new_cap > capacity_) {
            size_t new_capacity = new_cap * 2;
            char* new_data = new char[new_capacity + 1];
            if (data_) {
                std::memcpy(new_data, data_, size_);
                delete[] data_;
            }
            data_ = new_data;
            capacity_ = new_capacity;
            data_[size_] = '\0';
        }
    }

public:
    // Constructors
    DemoString() : data_(new char[1]{'\0'}), size_(0), capacity_(0) {}
    DemoString(const char* s) : size_(std::strlen(s)), capacity_(size_) {
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, s, size_ + 1);
    }

    // Copy constructor and assignment operator
    DemoString(const DemoString& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new char[capacity_ + 1];
        std::memcpy(data_, other.data_, size_ + 1);
    }
    DemoString& operator=(const DemoString& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new char[capacity_ + 1];
            std::memcpy(data_, other.data_, size_ + 1);
        }
        return *this;
    }

    ~DemoString() { delete[] data_; }

    // Size and capacity
    size_t size() const { return size_; }
    size_t length() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    // Element access
    char& operator[](size_t idx) { return data_[idx]; }
    const char& operator[](size_t idx) const { return data_[idx]; }
    // Bounds-checked access
    char& at(size_t idx) {
        if (idx >= size_) throw std::out_of_range("String::at");
        return data_[idx];
    }
    const char& at(size_t idx) const {
        if (idx >= size_) throw std::out_of_range("String::at");
        return data_[idx];
    }

    // Modifiers
    void push_back(char c) {
        ensure_capacity(size_ + 1);
        data_[size_++] = c;
        data_[size_] = '\0';
    }

    // Concatenation
    DemoString& operator+=(const DemoString& rhs) {
        ensure_capacity(size_ + rhs.size_);
        std::memcpy(data_ + size_, rhs.data_, rhs.size_ + 1);
        size_ += rhs.size_;
        return *this;
    }

    void pop_back() {
        if (size_ > 0) {
            data_[--size_] = '\0';
        }
    }

    void clear() {
        size_ = 0;
        data_[0] = '\0';
    }

    // C-string access
    const char* c_str() const { return data_; }

    // Comparison
    bool operator==(const DemoString& rhs) const {
        return size_ == rhs.size_ && std::memcmp(data_, rhs.data_, size_) == 0;
    }
    bool operator!=(const DemoString& rhs) const {
        return !(*this == rhs);
    }
};

// Stream output
std::ostream& operator<<(std::ostream& os, const DemoString& s) {
    return os << s.c_str();
}

// Demo usage
int main() {
    DemoString s1("Hello");
    DemoString s2 = s1;
    
    s2.push_back('!');
    s1 += DemoString(" World");

    std::cout << "s1: " << s1 << "\n";
    std::cout << "s2: " << s2 << "\n";
    std::cout << "s1 length: " << s1.length() << "\n";
    std::cout << "s2[5]: " << s2[5] << "\n";
    return 0;
}