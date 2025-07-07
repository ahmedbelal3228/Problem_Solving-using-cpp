#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
    Problem: String Statistics Analyzer

    Description:
    - Reads a user-input string.
    - Counts and displays:
        * Total string length
        * Number of uppercase letters
        * Number of lowercase letters

    Purpose:
    - Practice Strings , using structs, character checking with isupper/islower, and clean function design.

*/

struct sStringStats
{
    size_t length;      // Total length of the string
    int capCount = 0;   // Count of uppercase letters
    int lowerCount = 0; // Count of lowercase letters
};

// Returns statistics (length, uppercase count, lowercase count) for the given string
sStringStats getStringStats(const string &s)
{
    sStringStats stringStats = {s.length(), 0, 0};

    for (int i = 0; i < s.length(); ++i)
    {
        if (islower(s[i]))
            ++stringStats.lowerCount;
        else if (isupper(s[i]))
            ++stringStats.capCount;
    }

    return stringStats;
}

string readString()
{
    cout << "Please enter a string: ";

    string s;
    getline(cin, s);
    return s;
}

void printStringStats(sStringStats stringStats)
{
    int totalLettersCount = stringStats.capCount + stringStats.lowerCount;

    cout << "String length: " << stringStats.length << endl;
    cout << "Total letters count: " << totalLettersCount << endl;
    cout << "Capital letters count: " << stringStats.capCount << endl;
    cout << "Lowercase letters count: " << stringStats.lowerCount << endl;
}

int main()
{
    string s = readString();
    sStringStats stringStats = getStringStats(s);
    printStringStats(stringStats);
    return 0;
}
