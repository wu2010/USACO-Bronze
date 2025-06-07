/* USACO 2020 December Contest, Bronze
Problem 3. Stuck in a Rut

Farmer John has recently expanded the size of his farm, so from the perspective of his 
cows it is effectively now infinite in size! The cows think of the grazing area of the 
farm as an infinite 2D grid of square "cells", each filled with delicious grass 
(think of each cell as a square in an infinite chessboard). Each of Farmer John's 
N cows (1≤N≤50) starts out in a different cell; some start facing north, and 
some start facing east.

Every hour, every cow either
- Stops if the grass in her current cell was already eaten by another cow.
- Eats all the grass in her current cell and moves one cell forward according 
to the direction she faces.

Over time, each cow therefore leaves a barren "rut" of empty cells behind her.

If two cows move onto the same grassy cell in the same move, they share the cell 
and continue moving in their respective directions in the next hour.

Please determine the amount of grass eaten by each cow. Some cows never stop, 
and therefore eat an infinite amount of grass.

INPUT FORMAT (input arrives from the terminal / stdin):

The first line of input contains N. Each of the next N lines describes the starting 
location of a cow, in terms of a character that is either N (for north-facing) or 
E (for east-facing) and two nonnegative integers x and y (0≤x≤10^9, 0≤y≤10^9) 
giving the coordinates of a cell. All x-coordinates are distinct from each-other, 
and similarly for the y-coordinates.

To be as clear as possible regarding directions and coordinates, if a cow is in 
cell (x,y) and moves north, she ends up in cell (x,y+1). If she instead had moved east, 
she would end up in cell (x+1,y).

OUTPUT FORMAT (print output to the terminal / stdout):

Print N lines of output. Line i in the output should describe the number of cells 
worth of grass that the ith cow in the input eats. If a cow eats an infinite amount 
of grass, output "Infinity" for that cow.

SAMPLE INPUT:

6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1

SAMPLE OUTPUT:

5
3
Infinity
Infinity
2
5

SCORING:
- In test cases 2-5, all coordinates are at most 100.
- In test cases 6-10, there are no additional constraints.
*/

#include <iostream>
#include <vector>
using namespace std;

class cow {
public:
    int x, y;
    char dir;
    int index; // To keep track of the original index

    // Initially assume infinite grass
    int grass = -1; // -1 means infinity since at least 1 patch of grass is eaten
    int max_x, max_y; // max position based on direction
};

int main() {
    int n;
    cin >> n;
    vector <cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
        cows[i].index = i; // Store the original index
    }

    // pay attention to the main diagonal direction
    // Sort cows by x + y (decending), then by x (ascending)
    sort(cows.begin(), cows.end(), [](const cow& a, const cow& b) {
        if (a.x + a.y > b.x + b.y) return true;
        if (a.x + a.y < b.x + b.y) return false;
        return a.x < b.x;
    });

    // cows[0] is infinity for sure, since it has the highest x + y
    int b = cows[0].x + cows[0].y;
    int next_index = 1; // To keep track of the index where the position may change
    // cows on the same level will not be blocked
    for (int i = 1; i < n; i++) {
        if (cows[i].x + cows[i].y == b) {
            next_index++; // Update the index where the level could be on
        } else {
            // If we find a cow with a smaller x + y, we can stop
            break;
        }
    }
    
    // Process each cow
    for (int i = next_index; i < n; i++) {
        if (cows[i].x + cows[i].y < b) {
            // If the current cow's position is worse, it can be blocked by the previous level
            b = cows[i].x + cows[i].y;
            next_index = i; // Update the index where the level first changes
        }

        // only cows that are from the previous level can block th current cow
        for (int j = 0; j < next_index; j++) {
            // Check if the current cow can be blocked by the previous cows
            if (cows[i].dir == 'N') {
                // The cow can be blocked by the jth cow if 
                // the jth cow is facing East and is to the left of the ith cow
                // or if the jth cow is facing North and is in the same column
                if (cows[j].dir == 'E' && cows[j].x <= cows[i].x 
                        && (cows[j].grass == -1 || cows[j].max_x >= cows[i].x)
                    || cows[j].dir == 'N' && cows[j].x == cows[i].x) {
                    int grass_eaten = cows[j].y - cows[i].y;
                    // only the nearest cow can block the current cow
                    if (cows[i].grass == -1 || cows[i].grass > grass_eaten) {
                        cows[i].grass = grass_eaten;
                        cows[i].max_y = cows[j].y - 1; // Update max_y that ith cow can reach
                   }
                }
            } else if (cows[i].dir == 'E') {
                // The cow can be blocked by the jth cow if
                // the jth cow is facing North and is below the ith cow
                // or if the jth cow is facing East and is in the same row
                if (cows[j].dir == 'N' && cows[j].y <= cows[i].y 
                        && (cows[j].grass == -1 || cows[j].max_y >= cows[i].y
                    || cows[i].dir == 'E' && cows[j].y == cows[i].y)) {
                    int grass_eaten = cows[j].x - cows[i].x;
                    // only the nearest cow can block the current cow
                    if (cows[i].grass == -1 || cows[i].grass > grass_eaten) {
                        cows[i].grass = grass_eaten;
                        cows[i].max_x = cows[j].x - 1; // Update max_x that ith cow can reach
                    }
                }
            }
        }
        // If the cow is still infinite, it means it can move freely
    }

    // Sort cows by index to maintain the original order
    sort(cows.begin(), cows.end(), [](const cow& a, const cow& b) {
        return a.index < b.index;
    });

    // Output the results
    for (const auto& c : cows) {
        if (c.grass == -1) {
            cout << "Infinity" << endl;
        } else {
            cout << c.grass << endl;
        }
    }

}