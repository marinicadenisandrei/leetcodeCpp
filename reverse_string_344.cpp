/* Leetcode - 344. Reverse String (C++ language) - Easy */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

void reverseString(vector<string> &sVar);
void printVector(vector<string> vect);

int main()
{
    yellow();

    cout << "Leetcode - 344. Reverse String (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<string>> s = {{"h","e","l","l","o"},{"H","a","n","n","a","h"}};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        reverseString(s[test]);
        printVector(s[test]);

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<string> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

void reverseString(vector<string> &sVar)
{
    reverse(sVar.begin(), sVar.end());
}

void reset () {
  cout << "\033[1;0m";
}

void green () {
  cout << "\033[1;32m";
}

void yellow () {
  cout << "\033[1;33m";
}

void red () {
  cout << "\033[1;31m";
}