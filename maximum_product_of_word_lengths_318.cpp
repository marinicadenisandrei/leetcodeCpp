/* Leetcode - 318. Maximum Product of Word Lengths (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int maxProduct(vector<string> wordsVar);
bool compareSameCharsInTwoStrings(string str1, string str2);

int main()
{
    yellow();

    cout << "Leetcode - 318. Maximum Product of Word Lengths (C++ language) - Medium" << endl;

    vector<vector<string>> words = {{"abcw","baz","foo","bar","xtfn","abcdef"},
                                   {"a","ab","abc","d","cd","bcd","abcd"},
                                   {"a","aa","aaa","aaaa"}};
    
    for (int test = 0; test < words.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxProduct(words[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool compareSameCharsInTwoStrings(string str1, string str2)
{
    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                return false;
            }
        }
    }

    return true;
}

int maxProduct(vector<string> wordsVar)
{
    int result = 0;
    
    for (int i = 0; i < wordsVar.size(); i++)
    {
        for (int j = 0; j < wordsVar.size(); j++)
        {    
            if (i != j && compareSameCharsInTwoStrings(wordsVar[i], wordsVar[j]))
            {
                int tempResult = wordsVar[i].size() * wordsVar[j].size();
                result = ((result < tempResult) ? tempResult : result);
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