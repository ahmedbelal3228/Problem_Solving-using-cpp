#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// * Counts the number of words in the input string separated by the given delimiter.
int countWordsInString(string s, string delimiter)
{

    /*
     * The function works by repeatedly finding the delimiter, extracting the substring before it,
     * counting it if it's not empty, and then removing that part from the string.
     * Finally, it checks for any remaining substring after the last delimiter and counts it too.
     */

    short pos = 0;      // Position of the delimiter in the string
    string tempWord;    // Temporary string to hold the current word
    int wordsCount = 0; // Counter for words found

    // Loop until no delimiter is found in the string
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        // Extract substring from start up to the delimiter position
        tempWord = s.substr(0, pos);

        // Count the substring as a word only if it is not empty
        if (tempWord != "")
            wordsCount++;

        // Remove the processed word and delimiter from the string
        s.erase(0, pos + delimiter.length());
    }

    // After the loop, check if any remaining substring exists and count it as a word
    if (s != "")
        wordsCount++;

    return wordsCount; // Return the total number of words counted
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

int main()
{
    string s = readString();
    int Words = countWordsInString(s, " ");
    cout << "The number of Words in your string is : " << Words << endl;
    return 0;
}