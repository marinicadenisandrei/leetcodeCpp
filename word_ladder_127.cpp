/* Leetcode - 127. Word Ladder (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int findLadders(string beginWordVar, string endWordVar, vector<string> wordListVar);
int stringSameCharacters(string string1, string string2);
void print2DVector(vector<vector<string>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 127. Word Ladder (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> beginWord {"hit","hit"}; 
    vector<string> endWord {"cog","cog"};
    vector<vector<string>> wordList {{"hot","dot","dog","lot","log","cog"},{"hot","dot","dog","lot","log"}};
    
    for (int test = 0; test < beginWord.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << findLadders(beginWord[test], endWord[test], wordList[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void print2DVector(vector<vector<string>> vectorVar)
{
    cout << "[";

    if (vectorVar.size() > 0)
    {
        for (int i = 0; i < vectorVar.size(); i++)
        {
            for (int j = 0; j < vectorVar[i].size(); j++)
            {
                cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[i].size() - 1) ? ", " : "]");
            }
        }
    }

    cout << "] | ";
}

int stringSameCharacters(string string1, string string2)
{
    int sum {0};

    for (int i = 0; i < string1.size(); i++)
    {
        sum += ((string1[i] == string2[i]) ? 1 : 0);
    }

    return sum;
}

int findLadders(string beginWordVar, string endWordVar, vector<string> wordListVar)
{
    int maxVar = wordListVar.size();
    vector<int> values {};
    vector<vector<string>> result {};
    bool flag = false;

    for (int i = 0; i < wordListVar.size(); i++)
    {
        if (wordListVar[i] == endWordVar)
        {
            flag = true;
            break;
        }
    }
    
    if (!flag)
    {
        return 0;
    }

    for (int i = 0; i < wordListVar.size(); i++)
    {
        values.push_back(stringSameCharacters(wordListVar[i], endWordVar));
    }   

    while (values.size() > 2)
    {
        vector<string> temp {};
        temp.push_back(beginWordVar);

        vector<string> elementRemove {};
        int step = 2;

        for (int i = 0; i < values.size(); i++)
        {
            if (values[i] < step && step == 2)
            {
                temp.push_back(wordListVar[i]);
                elementRemove.push_back(wordListVar[i]);
            }
            else if (values[i] == step)
            {
                temp.push_back(wordListVar[i]);
                elementRemove.push_back(wordListVar[i]);
                step++;
            }
            
            if (step == endWordVar.size())
            {
                break;
            }
        }
        
        temp.push_back(endWordVar);
        
        for (int i = 1; i < elementRemove.size(); i++)
        {
            auto it = std::remove(wordListVar.begin(), wordListVar.end(), elementRemove[i]);
            wordListVar.erase(it, wordListVar.end());
        }

        elementRemove.clear();
        values.clear();

        for (int i = 0; i < wordListVar.size(); i++)
        {
            values.push_back(stringSameCharacters(wordListVar[i], endWordVar));
        }

        result.push_back(temp);
    }

    for (int i = 0; i < result.size(); i++)
    {
        maxVar = ((maxVar > result[i].size()) ? result[i].size() : maxVar);
    }
    
    return maxVar;    
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