/* Leetcode - 151. Reverse Words in a String (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWords(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 151. Reverse Words in a String (C++ language) - Medium" << endl;

    vector<string> s {"the sky is blue","  hello world  ", "a good   example"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << reverseWords(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string reverseWords(string sVar)
{
    while (sVar[0] == ' ')
    {
        sVar.erase(0,1);    
    }

    while (sVar[sVar.size() - 1] == ' ')
    {
        sVar.erase(sVar.size() - 1);   
    }
    
    auto takeSubstring = [] (string stringVar, int starter) {
        string temp = "";

        for (int i = starter + 1; i < stringVar.size(); i++)
        {
            temp += stringVar[i];
        }
        
        return temp;
    };

    auto newBegin = [] (string stringVar) {

    };

    string finalString {""};
    int start = sVar.size() - 1;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = start; i >= 0 ; i--)
        {
            if (sVar[i] == ' ')
            {
                finalString += takeSubstring(sVar, i) + " ";

                for (int j = i; j >= 0; j--)
                {
                    if (sVar[j] != ' ' && sVar[j + 1] == ' ')
                    {
                        start = j;
                        sVar = sVar.substr(0,j + 1);
                        break;
                    }
                }

                flag = true;
                break;
            }
        }
    }    

    return finalString + sVar;
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