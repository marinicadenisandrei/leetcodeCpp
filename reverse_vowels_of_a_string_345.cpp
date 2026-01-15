/* Leetcode - 345. Reverse Vowels of a String (C++ language) - Easy */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

string reverseVowels(string sVar);

int main()
{
    yellow();

    cout << "Leetcode - 345. Reverse Vowels of a String (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s = {"IceCreAm","leetcode"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << reverseVowels(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

string reverseVowels(string sVar)
{
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

    vector<char> presentVowels = {};    
    int cursorFindVowels = 0;

    for (int i = 0; i < sVar.size(); i++)
    {
        if (std::find(vowels.begin(), vowels.end(), sVar[i]) != vowels.end())
        {
            presentVowels.push_back(sVar[i]);
        }
    }

    for (int i = sVar.size() - 1; i >= 0; i--)
    {
        if (std::find(vowels.begin(), vowels.end(), sVar[i]) != vowels.end())
        {
            sVar[i] = presentVowels[cursorFindVowels++];
        }  
    }

    return sVar;
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