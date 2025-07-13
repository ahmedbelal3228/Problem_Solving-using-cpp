#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*
1. make a string contains all the punctuation
2. loop through the string
3. for Schar : string
    for char : punctuation
    if char == char = replace(Schar with char punctuation)


what function will i use :
    - replace(start,  end , wordToReplace  , wordToReplaceWith)
*/

bool isPunct(char c)
{
    string punctuationChars = R"(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)";
    for (char i : punctuationChars)
    {
        if (c == i)
            return true;
    }
    return false;
}

string replacePunctuation(string s, string punctuationChars, char replacementChar = ' ')
{

    for (short i = 0; i < s.length(); ++i)
    {
        if (isPunct(s[i]))
        {
            if ((0 < i && i < s.length() - 1) && (s[i + 1] == ' ' || s[i - 1] == ' '))
                s.erase(i, 1);
            else
                s[i] = replacementChar;
        }
    }

    return s;
}

// Reads a full line string from standard input and trims it automatically
string readString(string message = "Please enter a string: ")
{
    cout << message;
    string s;
    getline(cin, s);
    return s; // Automatically remove leading/trailing spaces
}

int main()
{

    string s = readString();

    string punctuationChars = R"(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)";

    string clearedString = replacePunctuation(s, punctuationChars);
    cout << clearedString << endl;

    return 0;
}