#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Joins and prints the contents of a string vector with a separator
void joinStringVector(vector<string> &vString, string sep)
{
    /*
    Loops through the vector and prints each element.
    Adds the separator after each element except the last.
    */
    for (short i = 0; i < vString.size(); ++i)
    {
        cout << vString[i];
        if (i < vString.size() - 1)
            cout << sep;
    }
    cout << endl; // Move to the next line after printing
}

// Removes leading and trailing spaces from a string
string trimString(string s)
{
    size_t firstNonSpace = s.find_first_not_of(' ');
    if (firstNonSpace == string::npos)
        return ""; // Return empty string if all spaces

    size_t lastNonSpace = s.find_last_not_of(' ');
    // Return the substring without leading/trailing spaces
    return s.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}

// Fills a vector with user input strings until "0" is entered
void fillStringVector(vector<string> &vString)
{
    short i = 0; // To keep track of element number
    string s;
    while (true)
    {
        ++i;
        cout << "Enter element [" << i << "] (0 to exit): ";
        getline(cin, s);   // Read user input
        s = trimString(s); // Trim spaces before processing

        if (s == "0") // Exit condition
            break;

        if (!s.empty()) // Only add non-empty strings
            vString.push_back(s);
    }
}

// Reads a full line string from standard input (used for testing or additional utilities)
string readString(string &s)
{
    cout << "Enter a string: (0 to exit): ";
    getline(cin, s);
    return s;
}

int main()
{
    vector<string> vString; // Vector to store user input strings

    fillStringVector(vString);        // Fill the vector with user input
    joinStringVector(vString, " - "); // Display the vector joined with a separator

    return 0;
}