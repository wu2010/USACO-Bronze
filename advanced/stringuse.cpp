#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

int main() {
    // 1. Creating and initializing strings
    std::string s1 = "Hello";
    std::string s2("World");
    std::string s3 = s1 + " " + s2; // Concatenation

    // 2. Accessing characters
    char first = s1[0]; // 'H'
    char last = s1.at(s1.size() - 1); // 'o'

    // 3. Modifying strings
    s1 += "!"; // Append
    s2.insert(0, "Beautiful "); // Insert at position 0
    s3.replace(0, 5, "Hi"); // Replace "Hello" with "Hi"

    // 4. Substrings
    std::string sub = s2.substr(0, 9); // "Beautiful"

    // 5. Searching
    size_t pos = s3.find("World"); // Find substring

    // 6. Comparing
    if (s1 == "Hello!") {
        std::cout << "s1 is Hello!" << std::endl;
    }

    // 7. Iterating
    for (char c : s1) {
        std::cout << c << ' ';
    }
    std::cout << std::endl;

    // 8. Reversing
    std::reverse(s1.begin(), s1.end());
    std::cout << "Reversed s1: " << s1 << std::endl;

    // 9. Converting to C-string
    const char* cstr = s1.c_str();

    // Output examples
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "Substring: " << sub << std::endl;
    std::cout << "Position of 'World' in s3: " << pos << std::endl;
    std::cout << "C-string: " << cstr << std::endl;

    // 10. Formatted output expressions (as string values, not cout)
    // C++ does not have a direct equivalent to Java's String.format(), but you can use std::format (C++20) or stringstream.

    // Using std::format (C++20 and later)
    // #include <format> // Uncomment if your compiler supports <format>
    // std::string formatted = std::format("{} ({})", name, num);
    // std::string pi_str = std::format("{:.2f}", pi);
    // std::string name_width = std::format("{:>10}", name);

    // If std::format is not available, use stringstream as before:
    int num = 42;
    double pi = 3.14159;
    std::string name = "Alice";

    std::ostringstream oss1, oss2, oss3;

    oss1 << name << " (" << num << ")";
    std::string formatted_name = oss1.str();

    oss2 << std::fixed << std::setprecision(2) << pi;
    std::string pi_str = oss2.str();

    oss3 << std::setw(10) << std::right << name;
    std::string name_width = oss3.str();

    std::cout << "Formatted name: " << formatted_name << std::endl;
    std::cout << "Pi (2 decimal places): " << pi_str << std::endl;
    std::cout << "Right-aligned name: " << name_width << std::endl;

    // 11. String to number conversion
    int number = std::stoi("12345"); // Convert string to integer
    double decimal = std::stod("123.45"); // Convert string to double
    std::cout << "Converted number: " << number << std::endl;
    std::cout << "Converted decimal: " << decimal << std::endl;

    // 12. Number to string conversion
    std::string num_str = std::to_string(12345);
    std::string decimal_str = std::to_string(123.45);
    std::cout << "Number to string: " << num_str << std::endl;
    std::cout << "Decimal to string: " << decimal_str << std::endl;

    // split string example
    std::string str = "Hello,World,This,is,a,test";
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ',')) {
        std::cout << "Token: " << token << std::endl;
    }

    // using whitespace as the default delimiter.
    std::string word;
    std::vector<std::string> words;
    // reset the stringstream with the original string
    ss.clear();
    ss.str("Hello World This is a test");
    // Read words separated by whitespace
    while (ss >> word) {
        words.push_back(word);
    }

    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}
/*
s1 is Hello!
H e l l o ! 
Reversed s1: !olleH
s1: !olleH
s2: Beautiful World
s3: Hi World
Substring: Beautiful
Position of 'World' in s3: 3
C-string: !olleH
Formatted name: Alice (42)
Pi (2 decimal places): 3.14
Right-aligned name:      Alice
Converted number: 12345
Converted decimal: 123.45
Number to string: 12345
Decimal to string: 123.450000
Token: Hello
Token: World
Token: This
Token: is
Token: a
Token: test
Hello World This is a test 
*/