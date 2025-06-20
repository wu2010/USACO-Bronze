/* USACO 2022 December Contest, Bronze
Problem 2. Feeding the Cows

Farmer John has N (1≤N≤10^5) cows, the breed of each being either a Guernsey or a 
Holstein. They have lined up horizontally with the cows occupying positions labeled 
from 1…N.

Since all the cows are hungry, FJ decides to plant grassy patches on some of the 
positions 1…N. Guernseys and Holsteins prefer different types of grass, so if Farmer 
John decides to plant grass at some location, he must choose to planting either 
Guernsey-preferred grass or Holstein-preferred grass --- he cannot plant both at the 
same location. Each patch of grass planted can feed an unlimited number of cows of 
the appropriate breed.

Each cow is willing to move a maximum of K (0≤K≤N−1) positions to reach a patch. Find 
the minimum number of patches needed to feed all the cows. Also, print a configuration 
of patches that uses the minimum amount of patches needed to feed the cows. Any 
configuration that satisfies the above conditions will be considered correct.

INPUT FORMAT (input arrives from the terminal / stdin):

Each input contains T test cases, each describing an arrangement of cows. The first 
line of input contains T (1≤T≤10). Each of the T test cases follow.

Each test case starts with a line containing N and K. The next line will contain a 
string of length N, where each character denotes the breed of the ith cow (G meaning 
Guernsey and H meaning Holstein).

OUTPUT FORMAT (print output to the terminal / stdout):

For each of the T test cases, please write two lines of output. For the first line, 
print the minimum number of patches needed to feed the cows. For the second line, 
print a string of length N that describes a configuration that feeds all the cows with 
the minimum number of patches. The ith character, describing the ith position, should 
be a '.' if there is no patch, a 'G' if there is a patch that feeds Guernseys, and a 'H' 
if it feeds Holsteins. Any valid configuration will be accepted.

SAMPLE INPUT:

6
5 0
GHHGG
5 1
GHHGG
5 2
GHHGG
5 3
GHHGG
5 4
GHHGG
2 1
GH

SAMPLE OUTPUT:

5
GHHGG
3
.GH.G
2
..GH.
2
...GH
2
...HG
2
HG

Note that for some test cases, there are multiple acceptable configurations that manage 
to feed all cows while using the minimum number of patches. For example, in the fourth 
test case, another acceptable answer would be:

.GH..

This corresponds to placing a patch feeding Guernseys on the 2nd position and a patch 
feeding Holsteins on the third position. This uses the optimal number of patches and 
ensures that all cows are within 3 positions of a patch they prefer.

SCORING:
- Inputs 2 through 4 have N≤10.
- Inputs 5 through 8 have N≤40.
- Inputs 9 through 12 have N≤10^5.
*/