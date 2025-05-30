#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

// Define a tuple as a vector of strings
using Tuple = std::vector<std::string>;
// due to move semantics, we can use std::vector<std::string> directly as a tuple
// value is not copied, but moved when inserted into a set

// Define a relation as a set of tuples
using Relation = std::set<Tuple>;

// Print a relation
void printRelation(const Relation& rel) {
    for (const auto& tuple : rel) {
        for (const auto& val : tuple) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Selection: select tuples where column 'col' == 'value'
Relation selection(const Relation& rel, int col, const std::string& value) {
    Relation result;
    for (const auto& tuple : rel) {
        if (tuple[col] == value)
            result.insert(tuple);
    }
    return result;
}

// Projection: keep only columns in 'cols'
Relation projection(const Relation& rel, const std::vector<int>& cols) {
    Relation result;
    for (const auto& tuple : rel) {
        Tuple projected;
        for (int c : cols)
            projected.push_back(tuple[c]);
        result.insert(projected);
    }
    return result;
}

// Union: combine two relations
Relation unionRel(const Relation& r1, const Relation& r2) {
    Relation result = r1;
    result.insert(r2.begin(), r2.end());
    return result;
}

// Difference: tuples in r1 but not in r2
Relation difference(const Relation& r1, const Relation& r2) {
    Relation result;
    for (const auto& tuple : r1) {
        if (r2.find(tuple) == r2.end())
            result.insert(tuple);
    }
    return result;
}

// Cartesian Product
Relation cartesianProduct(const Relation& r1, const Relation& r2) {
    Relation result;
    for (const auto& t1 : r1) {
        for (const auto& t2 : r2) {
            Tuple combined = t1;
            combined.insert(combined.end(), t2.begin(), t2.end());
            result.insert(combined);
        }
    }
    return result;
}

int main() {
    // Example relations
    Relation students = {
        {"1", "Alice"},
        {"2", "Bob"},
        {"3", "Carol"}
    };

    Relation courses = {
        {"1", "Math"},
        {"2", "Physics"}
    };

    std::cout << "Students:\n";
    printRelation(students);

    std::cout << "\nCourses:\n";
    printRelation(courses);

    std::cout << "\nSelection (students with id=2):\n";
    printRelation(selection(students, 0, "2"));

    std::cout << "\nProjection (student names):\n";
    printRelation(projection(students, {1}));

    std::cout << "\nUnion (students U students):\n";
    printRelation(unionRel(students, students));

    std::cout << "\nDifference (students - selection):\n";
    printRelation(difference(students, selection(students, 0, "2")));

    std::cout << "\nCartesian Product (students x courses):\n";
    printRelation(cartesianProduct(students, courses));

    return 0;
}
/*
Students:
1 Alice 
2 Bob 
3 Carol 

Courses:
1 Math 
2 Physics 

Selection (students with id=2):
2 Bob 

Projection (student names):
Alice 
Bob 
Carol 

Union (students U students):
1 Alice 
2 Bob 
3 Carol 

Difference (students - selection):
1 Alice 
3 Carol 

Cartesian Product (students x courses):
1 Alice 1 Math 
1 Alice 2 Physics 
2 Bob 1 Math 
2 Bob 2 Physics 
3 Carol 1 Math 
3 Carol 2 Physics 
*/