#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <optional>
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Reads a full line string from standard input
string readString(string message = "Please enter a string: ")
{

    cout << message;
    string s;
    getline(cin, s);
    return s;
}

string sToLower(string s)
{
    for (char &c : s)
    {
        if (isupper(c))
            tolower(c);
    }

    return s;
}

// take the confirmation from the user with yes/no
bool isSure(string message = "Are you sure? (y/n) : ")
{

    cout << message << endl;
    string answer;
    getline(cin, answer);
    string lowerAnswer = sToLower(answer);
    if (!lowerAnswer.empty() && lowerAnswer[0] == 'y')
        return true;

    else
        return false;
}

// reading an integer from the user with input validation
short readNum(string message = "Please enter a number: ")
{
    while (true)
    {

        cout << message;
        short n;
        cin >> n;

        if (!cin.fail() && n >= 0)
            return n;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
}

/*
 * This function splits the input string `s` into substrings separated by the specified `delimiter`.
 * Each non-empty substring is added to the vector `vWords`.
 */
void splitString(string s, vector<string> &vWords, string delimiter)
{

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

// Represents a bank client with basic account and contact information
struct sClient
{
    string accountNumber;
    string pinCode;
    string fullName;
    string phone;
    double accountBalance;
};

void addClientsToFile(string fileName, string delim, vector<sClient> &vClients);

short displayMainMenuAndGetChoice()
{
    cout << "\n========== Client Data Converter ==========\n";
    cout << "1. Convert line-based input to structured client records\n";
    return readNum("Select an option (0 to exit) : ");
}

// ------------------------------------------------------ DISPLAYING CLIENTS ------------------------------------------------------
// *****************************************************************************************************************

// Prints all fields of a single client in a formatted layout
void displayClientCard(const sClient client)
{
    cout << "---------------------------------------------\n";
    cout << "Account Number : " << client.accountNumber << "\n";
    cout << "Pin Code       : " << client.pinCode << "\n";
    cout << "Full Name      : " << client.fullName << "\n";
    cout << "Phone          : " << client.phone << "\n";
    // Set output format: fixed point, 3 decimal places
    cout << fixed << setprecision(3);
    cout << "Balance        : " << client.accountBalance << "\n";
    cout << "---------------------------------------------\n";
}

void displayClientRecord(const sClient client, int n)
{
    cout << "| " << setw(5) << left << n;
    cout << "| " << setw(15) << left << client.accountNumber;
    cout << "| " << setw(10) << left << client.pinCode;
    cout << "| " << setw(40) << left << client.fullName;
    cout << "| " << setw(12) << left << client.phone;
    cout << fixed << setprecision(2);
    cout << "| " << setw(12) << left << client.accountBalance;
}

void printHorizontalTableBorder()
{
    cout << "\n_______________________________________________________";
    cout << "__________________________________________________\n\n";
}

void printTableHeader()
{
    printHorizontalTableBorder();
    cout << "| " << left << setw(5) << "Num";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    printHorizontalTableBorder();
}

// Iterates through a list of clients and prints each one using displayClientCard
void displayClientsStructFromVector(vector<sClient> &vClients)
{

    int n = 1;
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).\n";

    printTableHeader();

    // print clients inside the table
    for (sClient &client : vClients)
    {

        displayClientRecord(client, n);
        if (n < vClients.size())
            cout << endl;
        n++;
    }
    printHorizontalTableBorder();
}
// *****************************************************************************************************************

// Converts a vector of strings (representing client fields) into a structured sClient
sClient parseClientRecord(const vector<string> &vClient)
{
    // Assumes the vector contains exactly 5 elements in the correct order
    sClient client;
    client.accountNumber = vClient[0];
    client.pinCode = vClient[1];
    client.fullName = vClient[2];
    client.phone = vClient[3];
    client.accountBalance = stod(vClient[4]); // Convert string to double
    return client;
}

// Prompts the user to enter client data as delimited strings,
// then parses and stores them as structured client records
void convertLineToRecord(short numOfClients, vector<sClient> &vClients)
{
    string delim = readString("Enter the field delimiter used in client records: ");
    for (short n = 1; n <= numOfClients; ++n)
    {
        string line = readString("Enter full client record line [" + to_string(n) + "]: ");
        vector<string> vClientString;
        splitString(line, vClientString, delim);
        sClient client = parseClientRecord(vClientString);
        vClients.push_back(client);
    }

    // Display parsed records for verification
    displayClientsStructFromVector(vClients);
}
// ********************************************************************************************

int main()
{

    vector<sClient> vClients;
    const string fileName = "Clients.txt";
    const string delim = "#||#";

    while (true)
    {
        short userChoice = displayMainMenuAndGetChoice();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice == 1)
        {
            short numOfClients = readNum("Enter the number of clients: ");
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            convertLineToRecord(numOfClients, vClients);
        }

        else if (userChoice == 0)
        {
            cout << "Exiting program...\n";
            break;
        }

        else
            cout << "Ivalid Choice !\n ";

        cout << "\nPress Enter to return to the main menu...";
        cin.get(); // Pause}
        clearScreen();
    }
    return 0;
}