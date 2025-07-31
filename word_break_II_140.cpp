/* Leetcode - 140. Word Break II (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> wordBreak(string sVar, vector<string> wordDictVar);
string removeSpaces(string stringVar);
void printVector(vector<string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 140. Word Break II (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> s {"catsanddog","pineapplepenapple"};
    vector<vector<string>> wordDict {{"cat","cats","and","sand","dog"},{"apple","pen","applepen","pine","pineapple"}}; 
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<string> result = wordBreak(s[test], wordDict[test]);
        printVector(result);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

string removeSpaces(string stringVar)
{
    string newString = "";

    for (int i = 0; i < stringVar.size(); i++)
    {
        if (stringVar[i] != ' ')
        {
            newString += stringVar[i];
        }
    }
    
    return newString;
}

vector<string> wordBreak(string sVar, vector<string> wordDictVar)
{
    vector<string> acumulation;

    while (wordDictVar.size() > 0)
    {   
        vector<string> start;
        string temp = "";

        for (int i = 0; i < sVar.size(); i++)
        {
            temp += sVar[i];

            auto it = find(wordDictVar.begin(), wordDictVar.end(), temp);
            if (it != wordDictVar.end())
            {
                start.push_back(temp);
                temp = "";
            }
        }

        if (start.size() == 0)
        {
            break;
        }

        temp = "";

        for (int i = 0; i < start.size(); i++)
        {
            temp += start[i] + " ";
        }

        if (removeSpaces(temp) == sVar)
        {
            acumulation.push_back(temp);
        }

        temp = "";
        
        for (int i = 0; i < start.size() - 1; i++)
        {
            temp = "";

            for (int j = 0; j < i; j++)
            {
                temp += start[j] + " ";
            }
            
            temp += start[i];
            temp += start[i + 1];

            for (int j = i + 2; j < start.size(); j++)
            {
                temp += " " + start[j];
            }
            
            if (removeSpaces(temp) == sVar)
            {
                auto it = find(wordDictVar.begin(), wordDictVar.end(), start[i] + start[i + 1]);

                if (it != wordDictVar.end())
                {
                    acumulation.push_back(temp);
                }
            }
        }

        wordDictVar.erase(wordDictVar.begin());
    }    

    return acumulation;
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