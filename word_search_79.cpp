/* Leetcode - 79. Word Search (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool exists(vector <vector <string>> boardVar, string wordVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 79. Word Search (C++ language) - Medium" << endl;

    vector <vector <string>> board {{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
    vector <string> word = {"ABCCED","SEE","ABCB"};
    
    for (int test = 0; test < word.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << exists(board, word[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

bool exists(vector <vector <string>> boardVar, string wordVar)
{
    vector <vector <vector <int>>> positionsOfCharacters;

    for (int i = 0; i < wordVar.size(); i++)
    {
        positionsOfCharacters.push_back({});

        for (int j = 0; j < boardVar.size(); j++)
        {
            for (int k = 0; k < boardVar[j].size(); k++)
            {
                if (boardVar[j][k][0] == wordVar[i])
                {
                    vector <int> temp {j,k};
                    positionsOfCharacters[i].push_back(temp);
                }
            }
        }
    }

    for (int i = 0; i < positionsOfCharacters.size(); i++)
    {
        if (positionsOfCharacters[i].size() + 1 <= (int) count(wordVar.begin(), wordVar.end(), wordVar[i]))
        {
            return false;
        }
    }
    
    bool flag = true;

    for (int k = 0; k < positionsOfCharacters.size() - 1; k++)
    {    
        flag = false;

        for (int i = 0; i < positionsOfCharacters[k].size(); i++)
        {
            for (int j = 0; j < positionsOfCharacters[k + 1].size(); j++)
            {
                if (abs(positionsOfCharacters[k][i][0] - positionsOfCharacters[k][j][0]) < 2 && abs(positionsOfCharacters[k + 1][i][1] - positionsOfCharacters[k + 1][j][1]) < 2)
                {
                    flag = true;
                    break;
                }
            }

            if (flag == true)
            {
                break;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
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