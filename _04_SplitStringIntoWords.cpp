#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../MyLib/MyArrLib.h"
using namespace std;

/*
 * Splits the input string into words separated by spaces.
 * Appends words to the provided vector.
 */
void splitStringToWords_1(string s, vector<string> &vWords)
{
    string tempWord = "";
    s += " ";
    for (short i = 0; i < s.length(); ++i)
    {
        if (s[i] != ' ')
            tempWord += s[i];
        if (s[i] == ' ' && tempWord != "")
        {
            vWords.push_back(tempWord);
            tempWord = "";
        }
    }
}

/*
 * Splits the input string into words separated by spaces.
 * Handles the last word without trailing space.
 */
void splitStringToWords_2(string s, vector<string> &vWords)
{
    string tempWord = "";

    for (short i = 0; i < s.length(); ++i)
    {
        if (s[i] != ' ')
            tempWord += s[i];
        else if (tempWord != "")
        {
            vWords.push_back(tempWord);
            tempWord = "";
        }
    }
    // After the loop, tempWord may hold the last word if the string doesn't end with a space.
    // Check if tempWord is not empty, then add it to the vector to include the final word.
    if (tempWord != "")
        vWords.push_back(tempWord);
}

/*
 * This function splits the input string `s` into substrings separated by the specified `delimiter`.
 * Each non-empty substring is added to the vector `vWords`.
 */
void splitStringToWords_3(string s, vector<string> &vWords, string delimiter)
{
    /*
     * Steps:
     * 1. Search for the delimiter in the string.
     * 2. Extract the part before the delimiter as a word.
     * 3. Add the word to the vector if it's not empty.
     * 4. Remove the extracted word and delimiter from the string.
     * 5. Repeat until no more delimiters are found.
     * 6. Add any leftover substring as the last word.
     */

    short pos = 0;   // Position of the delimiter in the string
    string tempWord; // Temporary string to hold the current word

    // Loop as long as the delimiter is found in the string
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        // Extract the substring from the start up to the delimiter position
        tempWord = s.substr(0, pos);

        // Add the substring to the vector only if it is not empty
        if (tempWord != "")
            vWords.push_back(tempWord);

        // Remove the extracted word and the delimiter from the original string
        s.erase(0, pos + delimiter.length());
    }

    // After the loop ends, add any remaining part of the string as the last word if not empty
    if (s != "")
        vWords.push_back(s);
}

/*
 * Reads a full line string from standard input.
 */
string readString()
{
    cout << "Please enter a string: ";

    string s;
    getline(cin, s);
    return s;
}

/*
 * Prints the contents of the string vector with index and spacing.
 */
void printStringVector(vector<string> &v)
{
    vector<string>::iterator first = v.begin();
    vector<string>::iterator last = v.end();
    int i = 1;
    for (auto it = first; it != last; ++it)
    {
        cout << i << "- " << *it;
        ++i;
        if (next(it) != v.end())
            cout << "   ";
    }
    cout << endl;
}

int main()
{
    vector<string> vWords;
    string s = readString();
    // splitStringToWords_1(s, vWords);
    // splitStringToWords_2(s, vWords);
    splitStringToWords_3(s, vWords, " ");
    printStringVector(vWords);
    cout << "Number Of Words: " << vWords.size() << endl;

    return 0;
}