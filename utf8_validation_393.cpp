/* Leetcode - 393. UTF-8 Validation (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool validUtf8(vector<int> dataVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    cout << boolalpha;

    yellow();

    cout << "Leetcode - 393. UTF-8 Validation (C++ language) - Medium" << endl;

    vector<vector<int>> data = {{197,130,1},{235,140,4}};
    
    for (int test = 0; test < data.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << validUtf8(data[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}


bool validUtf8(vector<int> dataVar)
{
    int remaining = 0;

    for (int i = 0; i < dataVar.size(); i++)
    {
        bitset<8> binary(dataVar[i]);
        string binaryString = binary.to_string();

        if (remaining == 0)
        {
            if (binaryString[0] == '0')
            {
                remaining = 0;
            }
            else if (binaryString.substr(0, 3) == "110")
            {
                remaining = 1;
            }
            else if (binaryString.substr(0, 4) == "1110")
            {
                remaining = 2;
            }
            else if (binaryString.substr(0, 5) == "11110")
            {
                remaining = 3;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (binaryString.substr(0, 2) == "10")
            {
                remaining -= 1;
            }
            else 
            {
                return false;
            }
        }
    }

    return remaining == 0;
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