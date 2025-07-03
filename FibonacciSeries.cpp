#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Fibonacci Series - Multiple Implementations

This program demonstrates:
1) Generating Fibonacci numbers into a vector for later use.
2) Printing Fibonacci numbers using an iterative loop.
3) Printing Fibonacci numbers using recursion.

Fibonacci Sequence Rule:
- Each term is the sum of the previous two:
    F(n) = F(n-1) + F(n-2)
- Starts with 0, 1, ...

Examples:
Input: 5 → Output: 0, 1, 1, 2, 3
Input: 8 → Output: 0, 1, 1, 2, 3, 5, 8, 13
*/

// Generates Fibonacci series and stores it in a vector for reuse or analysis
void generateFibonacciVector(short n, vector<int> &v)
{
    if (n == 0)
        return; // If user wants 0 elements, do nothing

    v.push_back(0); // First Fibonacci number
    if (n >= 2)
        v.push_back(1); // Second Fibonacci number

    // From the 3rd element onwards, generate using F(n) = F(n-1) + F(n-2)
    for (int i = 2; i < n; ++i)
    {
        v.push_back(v[i - 1] + v[i - 2]);
    }
}

// Prints all elements of an integer vector with spacing
void printIntVector(const vector<int> &v)
{
    for (const int &num : v)
    {
        cout << num << "   ";
    }
    cout << endl;
}

// Prints Fibonacci numbers directly using a loop (iterative method)
void printFibonacciIterative(short n)
{
    if (n == 0)
        return; // Nothing to print

    int prev2 = 0, prev1 = 1, current = 1;

    cout << prev2 << "   "; // Print first Fibonacci number
    if (n > 1)
        cout << prev1 << "   "; // Print second Fibonacci number

    // Generate and print subsequent Fibonacci numbers
    for (int i = 2; i < n; ++i)
    {
        current = prev1 + prev2; // Calculate next Fibonacci number
        cout << current << "   ";
        prev2 = prev1;   // Move prev2 forward
        prev1 = current; // Move prev1 forward
    }
    cout << endl;
}

// Prints Fibonacci numbers using recursion with default initial previous values
void printFibonacciRecursive(short n, int prev2 = 0, int prev1 = 1)
{
    if (n == 0)
        return; // Base case: stop when n numbers have been printed

    int current = prev2 + prev1;
    cout << prev2 << "   "; // Print the current Fibonacci number

    prev2 = prev1;   // Move prev2 forward
    prev1 = current; // Move prev1 forward

    // Recursive call to print the remaining (n-1) Fibonacci numbers
    printFibonacciRecursive(n - 1, prev1, current);
}

int main()
{
    vector<int> fibonacciVec; // Will store Fibonacci series
    short n;

    cout << "How many numbers do you want in the Fibonacci series? ";
    cin >> n;

    cout << "\nGenerating Fibonacci using vector:\n";
    generateFibonacciVector(n, fibonacciVec);
    printIntVector(fibonacciVec);

    cout << "\nPrinting Fibonacci using iterative loop:\n";
    printFibonacciIterative(n);

    cout << "\nPrinting Fibonacci using recursion:\n";
    printFibonacciRecursive(n);
    cout << endl;

    return 0;
}