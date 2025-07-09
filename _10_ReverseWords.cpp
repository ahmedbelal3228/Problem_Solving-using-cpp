#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/*

-- PROCESS --  :
1. TAKE THE STRING INPUT FROM THE USER

2. PASS THE USER'S STRING TO A FUNCTION TO SEPARATE IT TO WORDS AND THEN ADD THESE WORDS TO A NEW VECTOR
    - while (true)-> find the position of the first space,
    - make a substring from 0 to this position (first word)
    - store this substring into a temp variable
    - push-back this variable to the vector
    - then erase the string from 0 to (position of the first space + delimiter.length()) (the del could be ex: -- or ## )
    - and continue until there are no spaces in the string (only the last word remaining without spaces)
    - return what left in the string

3. PRINT THIS WORDS VECTOR FROM LAST TO FIRST
    - for i = vector.size() to i = 0 -> print vector[i]

*/

// *Reads a full line string from standard input.
string readString()
{
    cout << "Please enter a string: ";

    string s;
    getline(cin, s);
    return s;
}

// Splits a string into words by the given delimiter, returns a vector of words.
vector<string> splitIntoWords(string s, string del = " ")
{
    vector<string> vWords;

    int pos;
    string tempWord;

    while ((pos = s.find_first_of(del)) != std::string::npos)
    {

        tempWord = s.substr(0, pos);

        if (tempWord != "")
            vWords.push_back(tempWord);

        s.erase(0, pos + del.length());
    }

    if (s != "")
        vWords.push_back(s);

    return vWords;
}

// Prints the elements of a vector of strings in reverse order with the given delimiter.
void printVector(vector<string> &vWords, string del = " ")
{

    if (vWords.empty())
    {
        cout << "No words to display." << endl;
        return;
    }

    for (short i = vWords.size() - 1; i >= 0; --i)
    {
        cout << vWords[i];

        if (i > 0)
            cout << del;
    }
    cout << endl;
}

int main()
{

    vector<string> vWords = splitIntoWords(readString());
    printVector(vWords);

    return 0;
}