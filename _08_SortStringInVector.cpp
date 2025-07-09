#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

// Reads a full line string from standard input.
string readString(string &s)
{
    cout << "Enter a string: (0 to exit): ";
    getline(cin, s);
    return s;
}

// Sorts the vector of strings in ascending alphabetical order
void sortString(vector<string> &v)
{
    sort(v.begin(), v.end());
}

// Reads strings from user until "0" is entered; stores them in the vector
void fillVector(vector<string> &v)
{
    string s;
    while (true)
    {
        s = readString(s);

        if (s == "0")
            break;
        else if (!s.empty())
            v.push_back(s);
    }
}

// Prints all strings separated by three spaces, no trailing spaces after last
void printStringVector(const vector<string> &v, string sep = " - ")
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it;
        if (next(it) != v.end())
            cout << sep;
    }
    cout << endl;
}

int main()
{
    vector<string> v;

    fillVector(v);        // Read input strings
    sortString(v);        // Sort alphabetically
    printStringVector(v); // Print sorted list

    return 0;
}