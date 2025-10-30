/* Leetcode - 336. Palindrome Pairs (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<vector<int>> palindromePairs(vector<string> wordsVar);
bool isPalindrome(string str);
void print2DIntVector(vector<vector<int>> vect);

int main()
{
    yellow();

    cout << "Leetcode - 336. Palindrome Pairs (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<string>> words = {{"abcd","dcba","lls","s","sssll"},{"bat","tab","cat"},{"a",""}};

    for (int test = 0; test < words.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        print2DIntVector(palindromePairs(words[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void print2DIntVector(vector<vector<int>> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << "[" << vect[i][0] << ", " << vect[i][1] << "]" << ((i < vect.size() - 1) ? ", " : "] | ");
    }
    
}

bool isPalindrome(string str)
{
    for (int i = 0; i < str.size() / 2; i++)
    {
        if (str[i] != str[str.size() - 1 - i])
        {
            return false;
        }
    }
    
    return true;
}

vector<vector<int>> palindromePairs(vector<string> wordsVar)
{
    vector<vector<int>> result = {};

    for (int i = 0; i < wordsVar.size(); i++)
    {
        for (int j = 0; j < wordsVar.size(); j++)
        {
            if (i != j)
            {
                string temp = wordsVar[i] + wordsVar[j];
                
                if (isPalindrome(temp))
                {
                    vector<int> indexVector = {i, j};
                    result.push_back(indexVector);
                }
            }
        }
    }

    return result;
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