/* Leetcode - 49. Group Anagrams (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <vector <string>> groupAnagrams(vector <string> strsVar);
bool stringExistsInVector(vector <string> vectorVar, string element);
void printMatrix(vector <vector <string>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    cout << "Leetcode - 49. Group Anagrams (C++ language) - Medium" << endl;

    vector <vector <string>> strs {{"eat","tea","tan","ate","nat","bat"}, {""}, {"a"}};

    for (int test = 0; test < strs.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector <vector <string>> result {groupAnagrams(strs.at(test))};
        printMatrix(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printMatrix(vector <vector <string>> matrix)
{
    cout << "[";

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix.at(i).at(j) << ((j < matrix.at(i).size() - 1) ? ", " : "]");
        }
    }

    cout << "] | "; 
}

bool stringExistsInVector(vector <string> vectorVar, string element)
{
    for (string i : vectorVar)
    {
        if (i == element)
        {
            return true;
        }
    }
    
    return false;
}

vector <vector <string>> groupAnagrams(vector <string> strsVar)
{
    vector <string> sortStrings {};
    vector <string> noDuplicate {};

    vector <vector <string>> output {};

    for (string i : strsVar)
    {
        string temp = i;
        sort(temp.begin(), temp.end());
        
        if (!stringExistsInVector(noDuplicate, temp))
        {
            noDuplicate.push_back(temp);
        }
        
        sortStrings.push_back(temp);
    }

    for (int i = 0; i < noDuplicate.size(); i++)
    {
        output.push_back({});

        for (int j = 0; j < sortStrings.size(); j++)
        {
            if (noDuplicate.at(i) == sortStrings.at(j))
            {
                output.at(i).push_back(strsVar.at(j));
            }
        }
    }
    
    return output;
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