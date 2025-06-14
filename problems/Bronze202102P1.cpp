/* USACO 2021 February Contest, Bronze
Problem 1. Year of the Cow

Farmer John's cows are excited to learn that Chinese New Year was recently celebrated, ushering 
in the year of the Ox, always a bovine favorite.

As we know, the zodiac animals for Chinese calendar years follow a 12-year cycle: Ox, Tiger, 
Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat, and then Ox again.

Bessie the cow is proud to say she was born in a year of the Ox, many years ago. Her friend 
Elsie wants to know how many years apart from Bessie she was born, and hopes you can help her 
deduce this by looking at relationships between the birth years of several cows on the farm.

INPUT FORMAT (input arrives from the terminal / stdin):

The first line of input contains an integer N (1≤N≤100). Each of the next N lines contains an 
8-word phrase specifying the relationship between the birth years of two cows. It is of the form

"Mildred born in previous Dragon year from Bessie",

or

"Mildred born in next Dragon year from Bessie"

The last word is the name of a cow on the farm, which is either "Bessie" or a cow that has 
already been mentioned in a previous line of input.

The first word is the name of a cow on the farm who is not "Bessie" and who has not yet been 
mentioned in the input. All cow names have at most 10 characters that are in the range a..z 
or A..Z.

The 5th word is one of the 12 zodiac animals above.

The 4th word is either "previous" or "next". For example, if the phrase is "Mildred born in 
previous Dragon year from Bessie", then Mildred's year of birth was the Dragon year closest 
to and strictly before (not equal to) Bessie's birth year.

OUTPUT FORMAT (print output to the terminal / stdout):

Please output the number of years by which Bessie and Elsie's birth years differ. It is 
guaranteed that this number can be determined by the input given.

SAMPLE INPUT:

4
Mildred born in previous Dragon year from Bessie
Gretta born in previous Monkey year from Mildred
Elsie born in next Ox year from Gretta
Paulina born in next Dog year from Bessie

SAMPLE OUTPUT:

12

In the input above,

    Elsie was born 12 years before Bessie.
    Mildred was born 9 years before Bessie.
    Gretta was born 17 years before Bessie.
    Paulina was born 9 years after Bessie.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> zodiac_years = {
    {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
    {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7},
    {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}
};

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> birth_years;
    birth_years["Bessie"] = 0; // Bessie's year is the reference point

    string skip;

    for (int i = 0; i < N; ++i) {
        string cow1, cow2, direction, zodiac;
        cin >> cow1 >> skip >> skip >> direction >> zodiac >> skip >> skip >> cow2;

        // Ensure cow2 was mentioned before cow1
        if (birth_years.count(cow2) == 0) {
            cerr << "Error: " << cow2 << " must be defined before " << cow1 << endl;
            return 1; // Exit if cow2 is not defined
        }

        // Calculate the year difference based on the zodiac and direction
        // the difference between cow2 and Bessie can be used to infer cow2's year
        int zodiac_cow2 = birth_years[cow2] % 12; // because Bessie is year 0
        // we assume cow1 is born after cow2
        int year_difference = (zodiac_years[zodiac] - zodiac_cow2 + 12) % 12;

        // Adjust year difference based on actual direction
        if (direction == "previous") {
            year_difference -= 12; // Go to previous zodiac cycle
        } else if (year_difference == 0) {
            year_difference = 12; // If same zodiac, go to next cycle
        }

        // Update cow1's birth year based on cow2's birth year and the calculated difference
        birth_years[cow1] = birth_years[cow2] + year_difference;
    }

    cout << abs(birth_years["Elsie"] - birth_years["Bessie"]) << endl;

    return 0;
}