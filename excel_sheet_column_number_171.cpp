/* Leetcode - 171. Excel Sheet Column Number (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> excelDB {
    "", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
};

int titleToNumber(string columnTitleVar);

void reset ();
void green ();
void yellow ();
void red ();


int main()
{
    yellow();

    cout << "Leetcode - 171. Excel Sheet Column Number (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> columnTitle {"A","AB","ZY"};

    for (int test = 0; test < columnTitle.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << titleToNumber(columnTitle[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int titleToNumber(string columnTitleVar)
{
    int number = 0;

    for (int i = 0; i < columnTitleVar.size() - 1; i++)
    {
        int temp = 1;

        for (int j = 0; j < excelDB.size(); j++)
        {
            if (excelDB[j][0] == columnTitleVar[i])
            {
                temp = j;
                break;
            }
        }

        number += 26 * temp;
    }

    for (int i = 0; i < excelDB.size(); i++)
    {
        if (excelDB[i][0] == columnTitleVar[columnTitleVar.size() - 1])
        {
            number += i;
            break;
        }
    }
    
    return number;
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