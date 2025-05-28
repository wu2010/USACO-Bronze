#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

// Example 1: Using Comparator (function object)
struct DescendingComparator {
    // Functor is a class that defines operator()
    bool operator()(int a, int b) const {
        return a > b; // Sort in descending order
    }
};

// Using function as comparator
bool compareAscending(int a, int b) {
    return a < b; // Sort in ascending order
}

// Example 2: Using Comparable (operator< in class)
class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}

    // Comparable: define operator<
    bool operator<(const Person& other) const {
        return age < other.age; // Sort by age ascending
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {5, 2, 9, 1};
    // Functor as Comparator example
    sort(nums.begin(), nums.end(), DescendingComparator());
    cout << "Sorted with functor comparator: ";
    for (int n : nums) cout << n << " ";
    cout << endl;
    // Using function as comparator
    sort(nums.begin(), nums.end(), compareAscending);
    cout << "Sorted with function comparator: ";
    for (int n : nums) cout << n << " ";
    cout << endl; 

    // Comparable example
    vector<Person> people = {{"Alice", 30}, {"Bob", 25}, {"Carol", 28}};
    sort(people.begin(), people.end()); // Uses operator<
    cout << "Sorted with comparable: ";
    for (const auto& p : people) cout << p.name << "(" << p.age << ") ";
    cout << endl;

    // difference between comparator and comparable:
    /* - Comparator is a function or function object that defines a custom sorting order.
       - Comparable is a class that implements the operator< to define its own sorting order.
       Comparators can be used with any type, while Comparable is specific to the class that implements it.
       Comparable: Only one natural ordering per class.	
    */

    // what is Strict Weak Ordering?    
    /* 
       Strict weak ordering is a relation that satisfies:
       1. Irreflexivity: For any element x, it is not true that x < x. (i.e., <= or >= is not allowed)
       2. Antisymmetry: If x < y and y < x, then x must be equal to y.
       3. Transitivity: If x < y and y < z, then x < z.
   
       lessthan vs greaterthan
       - `less<T>` is a function object that returns true if the first argument is less than the second.
       - `greater<T>` is a function object that returns true if the first argument is greater than the second.
    */
 
    // Example 3: Using lambda as comparator
    vector<string> words = {"banana", "apple", "cherry"};
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length(); // Sort by length ascending
    });
    cout << "Sorted with lambda comparator: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    // Example 4: Sorting pairs by second element descending
    vector<pair<string, int>> scores = {{"Alice", 90}, {"Bob", 85}, {"Carol", 95}};
    sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Sort by score descending
    });
    cout << "Sorted pairs by score descending: ";
    for (const auto& s : scores) cout << s.first << "(" << s.second << ") ";
    cout << endl;

    // Note: std::complex does not define operator< because there is no natural total order 
    // for complex numbers.
    // However, we can sort complex numbers based on their magnitude or real/imaginary parts.
    vector<complex<double>> cs = { {1, 2}, {3, 1}, {2, 2}, {2, 1} };
    // Sort by magnitude (absolute value) ascending
    sort(cs.begin(), cs.end(), [](const complex<double>& a, const complex<double>& b) {
        return abs(a) < abs(b);
    });
    cout << "Sorted complex numbers by magnitude: ";
    for (const auto& c : cs) cout << "(" << c.real() << "," << c.imag() << ") ";
    cout << endl;

    // Sort complex numbers by real part, then by imaginary part (both ascending)
    sort(cs.begin(), cs.end(), [](const complex<double>& a, const complex<double>& b) {
        if (a.real() != b.real()) return a.real() < b.real();
        return a.imag() < b.imag();
    });
    cout << "Sorted complex numbers by real, then imaginary: ";
    for (const auto& c : cs) cout << "(" << c.real() << "," << c.imag() << ") ";
    cout << endl;

    return 0;
}
/*
Sorted with functor comparator: 9 5 2 1 
Sorted with function comparator: 1 2 5 9 
Sorted with comparable: Bob(25) Carol(28) Alice(30) 
Sorted with lambda comparator: apple banana cherry 
Sorted pairs by score descending: Carol(95) Alice(90) Bob(85) 
Sorted complex numbers by magnitude: (1,2) (2,1) (2,2) (3,1) 
Sorted complex numbers by real, then imaginary: (1,2) (2,1) (2,2) (3,1) 
*/