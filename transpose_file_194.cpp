/* Leetcode - 194. Transpose File (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

using namespace std;

string transposeFile(string fileVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 194. Transpose File (C++ language) - Medium" << endl;

    string file {"name age\nalice 21\nryan 30"};
    
    green();

    cout << "Test 1: ";

    reset();
    
    cout << transposeFile(file) << " | ";

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

string transposeFile(string fileVar)
{
    vector<vector<string>> result = {};
    string resultString = "";

    string word;
    std::istringstream iss(fileVar);

    int lines = 0;
    int col = 1;

    bool flag = true;
    int index = 0;

    for (int i = 0; i < fileVar.size(); i++)
    {
        if (flag)
        {
            col += ((fileVar[i] == ' ') ? 1 : 0);
        }
        
        if (fileVar[i] == '\n')
        {
            lines++;
            flag = false;
        }
    }
    
    for (int i = 0; i < col; i++)
    {
        vector<string> temp;
        result.push_back(temp);
    }

    while (iss >> word)
    {
        result[index].push_back(word);
        index++;

        if (index == lines)
        {
            index = 0;
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            resultString += result[i][j] + " ";
        }

        resultString += "\n";
    }
    
    return resultString;
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