/* Leetcode - 131. Palindrome Partitioning (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> partition(string sVar);
bool isPalindrome(string a);
void print2DVector(vector<vector<string>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 131. Palindrome Partitioning (C++ language) - Medium" << endl;
    vector<string> s {"aab", "a"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<vector<string>> output = partition(s[test]);
        print2DVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void print2DVector(vector<vector<string>> vectorVar)
{
    cout << "[";
    for (int i = 0; i < vectorVar.size(); i++)
    {
        for (int j = 0; j < vectorVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[i].size() - 1) ? ", " : "]");
        }
    } 
    
    cout << "] | ";
}

bool isPalindrome(string a)
{
    for (int i = 0; i < a.size() / 2; i++)
    {
        if (a[i] != a[a.size() - 1 - i])
        {
            return false;
        }
    }

    return true;
}

vector<vector<string>> partition(string sVar)
{
    int stop {1};
    vector<vector<string>> result {};
    vector<string> temp {};

    for (int i = 0; i < sVar.size(); i++) temp.push_back(string {sVar[i]});     
    result.push_back(temp);
    temp.clear();

    while (stop < sVar.size())
    {
        string tempStr = "";

        for (int i = 0; i <= stop; i++)
        {
            tempStr += sVar[i];
        }

        if (isPalindrome(tempStr))
        {
            temp.push_back(tempStr);
        }

        for (int i = stop + 1; i < sVar.size(); i++)
        {
            temp.push_back(string {sVar[i]});  
        }

        stop++;
        result.push_back(temp);
        temp.clear();
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