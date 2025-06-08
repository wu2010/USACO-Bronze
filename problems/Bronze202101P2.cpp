/* USACO 2021 January Contest, Bronze
Problem 2. Even More Odd Photos

Farmer John is yet again trying to take a photograph of his N cows (2≤N≤1000).

Each cow has an integer "breed ID" number in the range 1…100. Farmer John has a 
very peculiar idea in mind for his photo: he wants to partition all the cows into 
disjoint groups (in other words, place each cow in exactly one group) and then line 
up the groups so the sum of the breed IDs of the cows in the first group is even, 
the sum of the IDs in the second group is odd, and so on, alternating between even and odd.

What is the maximum possible number of groups Farmer John can form?


INPUT FORMAT (input arrives from the terminal / stdin):

The first line of input contains N. The next line contains N space-separated integers 
giving the breed IDs of the N cows.

OUTPUT FORMAT (print output to the terminal / stdout):

The maximum possible number of groups in Farmer John's photo. It can be shown that 
at least one feasible grouping exists.

SAMPLE INPUT:

7
1 3 5 7 9 11 13

SAMPLE OUTPUT:

3

In this example, one way to form the maximum number of three groups is as follows. Place 
1 and 3 in the first group, 5, 7, and 9 in the second group, and 11 and 13 in the third group.


SAMPLE INPUT:

7
11 2 17 13 1 15 3

SAMPLE OUTPUT:

5

In this example, one way to form the maximum number of five groups is as follows. 
Place 2 in the first group, 11 in the second group, 13 and 1 in the third group, 15 in 
the fourth group, and 17 and 3 in the fifth group.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, odd_count = 0, even_count = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int cow;
        cin >> cow;
        if (cow % 2 == 1) {
            odd_count++;
        }
    }
    even_count = N - odd_count; // Total cows minus odd cows gives even cows

    // the first group is even
    if (odd_count == even_count || even_count == odd_count + 1) {
        // If the difference between odd and even counts is at most 1,
        // we can form groups with all cows.
        cout << N << endl;
        return 0;
    }
    
    // now we have unbalanced odd and even counts. 
    // odd_count cannot be increased but can be decreased
    if (odd_count < even_count) {
        // If there are more even cows, we can merge even groups to balance
        cout << odd_count + (odd_count + 1) << endl;
        return 0;
    }

    // now we have more odd cows than even cows

    /* If there are more odd cows, we can merge odd groups to balance
    while (odd_count > even_count) {
        odd_count -= 2; // Merge two odd cows into one group
        even_count += 1; // This creates one more even group
    }
    // since the first group is even, even_count cannot be too much
    if (odd_count + 2 == even_count) {
        even_count--; // If we have an extra even group, we can remove it
    }
    */

    // odd_count == even_count || even_count == odd_count + 1
    switch ((odd_count - even_count) % 3) {
        case 0:
            // If the difference is a multiple of 3, we can form groups
            cout << N - (odd_count - even_count) / 3 << endl;
            break;
        case 1:
            // If the difference is 1, we can form one less group
            // because we can only merge two odd cows into one group
            cout << N - (odd_count - even_count) / 3 - 2 << endl;
            break;
        case 2:
            // If the difference is 2, we can form one less group
            cout << N - (odd_count - even_count) / 3 - 1 << endl;
            break;
    }
    
    return 0;
}

