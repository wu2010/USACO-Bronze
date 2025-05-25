#include <iostream>
#include <string>
#include <stdexcept>

class DemoBitSet {
    // Using unsigned int to store bits
    // This limits the size of the bitset to 32 bits.
    unsigned int bits;
    size_t size;

public:
    // Constructor that initializes the bitset with a given size
    // Throws std::invalid_argument if size is larger than 32 bits
    DemoBitSet(size_t n) : bits(0), size(n) {
        if (n > sizeof(unsigned int) * 8)
            throw std::invalid_argument("Size too large for DemoBitSet");
    }

    void set(size_t pos, bool value = true) {
        if (pos >= size) throw std::out_of_range("Bit position out of range");
        // Set or clear the bit at position pos
        // If value is true, set the bit; if false, clear it
        if (value)
            bits |= (1u << pos);
        else
            bits &= ~(1u << pos);
    }

    // Returns the value of the bit at position pos
    bool test(size_t pos) const {
        if (pos >= size) throw std::out_of_range("Bit position out of range");
        return (bits >> pos) & 1u;
    }

    void reset() { bits = 0; }

    // Flips the bit at position pos
    void flip(size_t pos) {
        if (pos >= size) throw std::out_of_range("Bit position out of range");
        bits ^= (1u << pos);
    }

    // Returns the number of bits set to true
    std::string to_string() const {
        std::string s(size, '0');
        for (size_t i = 0; i < size; ++i)
            if (test(size - i - 1)) s[i] = '1';
        return s;
    }

    // Bitwise operators
    DemoBitSet operator&(const DemoBitSet& other) const {
        if (size != other.size) throw std::invalid_argument("Size mismatch");
        DemoBitSet result(size);
        result.bits = bits & other.bits;
        return result;
    }

    DemoBitSet operator|(const DemoBitSet& other) const {
        if (size != other.size) throw std::invalid_argument("Size mismatch");
        DemoBitSet result(size);
        result.bits = bits | other.bits;
        return result;
    }

    DemoBitSet operator^(const DemoBitSet& other) const {
        if (size != other.size) throw std::invalid_argument("Size mismatch");
        DemoBitSet result(size);
        result.bits = bits ^ other.bits;
        return result;
    }

    // Bitwise NOT operator
    // Returns a new DemoBitSet with all bits flipped
    // Note: This assumes the bits are within the range of size
    DemoBitSet operator~() const {
        DemoBitSet result(size);
        // Create a mask for the size of the bitset 
        // and flip the bits
        result.bits = ~bits & ((1u << size) - 1);
        return result;
    }
};

int main() {
    DemoBitSet b(8);
    b.set(1);
    b.set(3);
    b.set(5);
    std::cout << "Bitset: " << b.to_string() << std::endl;
    b.flip(3);
    std::cout << "After flip(3): " << b.to_string() << std::endl;
    b.reset();
    std::cout << "After reset: " << b.to_string() << std::endl;

    // Demonstrating bitwise operations
    DemoBitSet b2(8);
    b2.set(0);
    b2.set(1);
    b2.set(2);
    std::cout << "Bitset b2: " << b2.to_string() << std::endl;
    DemoBitSet andResult = b & b2;
    DemoBitSet orResult = b | b2;
    DemoBitSet xorResult = b ^ b2;
    std::cout << "b & b2: " << andResult.to_string() << std::endl;
    std::cout << "b | b2: " << orResult.to_string() << std::endl;
    std::cout << "b ^ b2: " << xorResult.to_string() << std::endl;
    DemoBitSet notB = ~b;
    std::cout << "~b: " << notB.to_string() << std::endl;
    DemoBitSet notB2 = ~b2;
    std::cout << "~b2: " << notB2.to_string() << std::endl;

    return 0;
}
/* 
Bitset: 00101010
After flip(3): 00100010
After reset: 00000000
Bitset b2: 00000111
b & b2: 00000000
b | b2: 00000111
b ^ b2: 00000111
~b: 11111111
~b2: 11111000
*/
