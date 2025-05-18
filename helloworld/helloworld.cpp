#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    cout << "This is Alicia!" << endl;
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
// This is a simple C++ program that prints a message to the console.
