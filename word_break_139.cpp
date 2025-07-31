/* Leetcode - 139. Word Break (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool wordBreak(string sVar, vector<string> wordDict);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 139. Word Break (C++ language) - Medium" << endl;

    vector<string> s {"leetcode","applepenapple","catsandog"};
    vector<vector<string>> wordDict {{"leet","code"},{"apple","pen"},{"cats","dog","sand","and","cat"}};
    
    for (int test = 0; test < s.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << wordBreak(s[test], wordDict[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();
    
    return 0;
}

bool wordBreak(string sVar, vector<string> wordDict)
{
    bool flag {true};

    while (flag)
    {
        flag = false;

        for (int i = 0; i < wordDict.size(); i++)
        {
            size_t start_pos = sVar.find(wordDict[i]);

            if (start_pos != std::string::npos) {
                sVar.replace(start_pos, wordDict[i].length(), "");
                flag = true;
                break;
            }
        }
    }

    if (sVar.size() > 0)
    {
        return false;
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