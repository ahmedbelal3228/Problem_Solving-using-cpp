#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
    Problem:
    Count how many times a specific character is repeated in a string,
    first case-sensitively, then case-insensitively.

    This problem helps practice:
    - Loops
    - Conditionals
    - Character and string handling
    - Using functions for clean structure
*/

/*
    Counts how many times character 'c' appears in string 's'.

    Input:
        - s: the string to search in
        - c: the character to count
    Output:
        - the count of 'c' in 's'
*/
short countCharInString(string s, char c)
{
    short charCounter = 0; // counts occurrences
    for (short i = 0; i < s.length(); ++i)
    {
        if (s[i] == c)
            ++charCounter;
    }
    return charCounter;
}

/*
    Reads a full line of text from the user.
*/
string readStringFromUser()
{
    cout << "Please enter a string: ";
    string s;
    getline(cin, s);
    return s;
}

/*
    Reads a single character from the user.
*/
char readCharFromUser()
{
    cout << "Please enter a char: ";
    char c;
    cin >> c;
    return c;
}

/*
    Converts all uppercase letters in a string to lowercase.
    Useful for case-insensitive comparison.
*/
string convertStringToLower(string s)
{
    for (short i = 0; i < s.length(); ++i)
    {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }
    return s;
}

/*
    Displays the result with singular/plural formatting.
    For example: "The character [a] is repeated 1 time"
                 "The character [a] is repeated 3 times"
*/
void charCounterResult(char c, short result)
{
    cout << "• The character [" << c << "] is repeated " << result << " "
         << (result == 1 ? "time" : "times") << endl;
}

int main()
{
    // Read user input
    string userInput = readStringFromUser();
    char userChar = readCharFromUser();

    // Count and display case-sensitive count
    short caseSensitiveCount = countCharInString(userInput, userChar);
    charCounterResult(userChar, caseSensitiveCount);

    // For case-insensitive counting:
    // 1) Convert userChar to lowercase for consistent comparison
    // 2) Convert userInput to lowercase
    char lowerChar = tolower(userChar);
    string lowerInput = convertStringToLower(userInput);

    // Count and display case-insensitive count
    short caseInsensitiveCount = countCharInString(lowerInput, lowerChar);
    cout << "• "<<lowerChar << " or " << char(toupper(lowerChar))
         << " is repeated " << caseInsensitiveCount << " "
         << (caseInsensitiveCount == 1 ? "time" : "times") << endl;

    return 0;
}

