/* USACO 2023 January Contest, Bronze
Problem 1. Leaders

Farmer John has N cows (2≤N≤10^5). Each cow has a breed that is either Guernsey or Holstein. 
As is often the case, the cows are standing in a line, numbered 1…N in this order.

Over the course of the day, each cow writes down a list of cows. Specifically, cow i's list 
contains the range of cows starting with herself (cow i) up to and including cow E_i (i≤E_i≤N).

FJ has recently discovered that each breed of cow has exactly one distinct leader. FJ does 
not know who the leaders are, but he knows that each leader must have a list that includes 
all the cows of their breed, or the other breed's leader (or both).

Help FJ count the number of pairs of cows that could be leaders. It is guaranteed that there 
is at least one possible pair.

INPUT FORMAT (input arrives from the terminal / stdin):

The first line contains N.

The second line contains a string of length N, with the ith character denoting the breed of 
the ith cow (G meaning Guernsey and H meaning Holstein). It is guaranteed that there is at 
least one Guernsey and one Holstein.

The third line contains E_1…E_N.

OUTPUT FORMAT (print output to the terminal / stdout):

Output the number of possible pairs of leaders.

SAMPLE INPUT:

4
GHHG
2 4 3 4

SAMPLE OUTPUT:

1

The only valid leader pair is (1,2). Cow 1's list contains the other breed's leader (cow 2). 
Cow 2's list contains all cows of her breed (Holstein).

No other pairs are valid. For example, (2,4) is invalid since cow 4's list does not contain 
the other breed's leader, and it also does not contain all cows of her breed.

SAMPLE INPUT:

3
GGH
2 3 3

SAMPLE OUTPUT:

2

There are two valid leader pairs, (1,3) and (2,3).

SCORING
- Inputs 3-5: N≤100
- Inputs 6-10: N≤3000
- Inputs 11-17: No additional constraints.
*/