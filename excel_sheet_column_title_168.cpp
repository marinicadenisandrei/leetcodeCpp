/* Leetcode - 168. Excel Sheet Column Title (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convertToTitle(int columnNumberVar);

void reset ();
void green ();
void yellow ();
void red ();

const vector<string> excel = {
    "", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
};

int main()
{
    yellow();

    cout << "Leetcode - 168. Excel Sheet Column Title (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> columnNumber = {1,28,701};

    for (int test = 0; test < columnNumber.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << convertToTitle(columnNumber[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string convertToTitle(int columnNumberVar)
{
    string result = "";

    if (columnNumberVar <= 26)
    {
        result += excel[columnNumberVar];
        return result;
    }
    
    vector <int> acumulation = {};
    int excelSize = excel.size() - 1;
    int index = 0;

    for (int i = 0; i < 10; i++)
    {
        acumulation.push_back(0);
    }

    while (columnNumberVar > excelSize)
    {
        columnNumberVar -= excelSize;
        acumulation[index]++;

        if (acumulation[index] == excelSize)
        {
            index++;
        }
    }

    for (int i = 0; i < 1; i++)
    {
        result += excel[acumulation[i]];
    }

    result += excel[columnNumberVar];
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