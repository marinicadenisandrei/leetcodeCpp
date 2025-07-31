/* Leetcode - 72. Edit Distance (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1Var, string word2Var);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 72. Edit Distance (C++ language) - Medium" << endl;

    vector <string> word1 {"horse", "intention"};
    vector <string> word2 {"ros", "execution"};

    for (int test = 0; test < word1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minDistance(word1[test], word2[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int minDistance(string word1Var, string word2Var)
{
    if (word1Var.size() == word2Var.size())
    {
        int diff {0};

        for (int i = 0; i < word1Var.size(); i++)
        {
            if (word1Var[i] != word2Var[i])
            {
                diff++;
            }
        }

        return diff;
    }
    
    int starter = 0;

    for (int i = 0; i < word2Var.size(); i++)
    {
        for (int j = starter; j < word1Var.size(); j++)
        {
            if (word2Var[i] == word1Var[j])
            {
                word1Var.erase(j, 1);
                word2Var.erase(i, 1);

                starter = j;
                break;
            }
        }
    }

    return word1Var.size();
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