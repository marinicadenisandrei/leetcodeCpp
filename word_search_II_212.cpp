/* Leetcode - 212. Word Search II (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<string> findWords(vector<vector<string>> boardVar, vector<string> wordsVar);
void printStringVector(vector<string> vectorVar);

int main()
{
    yellow();

    cout << "Leetcode - 212. Word Search II (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<vector<string>>> board {{{"o","a","a","n"},{"e","t","a","e"},{"i","h","k","r"},{"i","f","l","v"}},{{"a","b"},{"c","d"}}};
    vector<vector<string>> words = {{"oath","pea","eat","rain"},{"abcb"}};

    for (int test = 0; test < board.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printStringVector(findWords(board[test], words[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printStringVector(vector<string> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<string> findWords(vector<vector<string>> boardVar, vector<string> wordsVar)
{
    vector<string> result = {};

    for (int j = 0; j < wordsVar.size(); j++)
    {
        int index1 = 0;
        int index2 = 0;

        string temp = "";
        temp += wordsVar[j][0];

        for (int k = 0; k < boardVar.size(); k++)
        {
            for (int l = 0; l < boardVar[k].size(); l++)
            {
                if (boardVar[k][l][0] == wordsVar[j][0])
                {
                    index1 = k;
                    index2 = l;
                }
            }
        }
        
        for (int i = 1; i < wordsVar[j].size(); i++)
        {            
            if (index2 + 1 < boardVar[0].size())
            {
                if (boardVar[index1][index2 + 1][0] == wordsVar[j][i])
                {
                    index2++;
                    temp += wordsVar[j][i];
                    continue;
                }
            }

            if (index2 - 1 >= 0)
            {
                if (boardVar[index1][index2 - 1][0] == wordsVar[j][i])
                {
                    index2--;
                    temp += wordsVar[j][i];
                    continue;
                }
            }

            if (index1 + 1 < boardVar.size())
            {
                if (boardVar[index1 + 1][index2][0] == wordsVar[j][i])
                {
                    index1++;
                    temp += wordsVar[j][i];
                    continue;
                }
            }
            
            break;
        }

        if (temp == wordsVar[j])
        {
            result.push_back(temp);
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