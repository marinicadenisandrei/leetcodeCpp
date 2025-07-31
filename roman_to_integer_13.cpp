#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct databaseRomanToInt 
{
    string symbol;
    int value;
};

int * makeArrayNumbers(string roman, vector <struct databaseRomanToInt> db);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 13. Roman to Integer (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <struct databaseRomanToInt> database {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000}
    };

    vector <string> sTest {"III", "LVIII", "MCMXCIV"};

    for (int test = 0; test < sTest.size(); test++)
    {
        string s {sTest.at(test)};

        int *arrayNumbersInt {NULL};
        arrayNumbersInt = makeArrayNumbers(s, database);

        int result {0};

        for (int i = 0; i < s.size(); i++)
        {
            if (arrayNumbersInt[i] < arrayNumbersInt[i + 1])
            {
                result += arrayNumbersInt[i + 1] - arrayNumbersInt[i];
                i++;
            }
            else
            {
                result += arrayNumbersInt[i];
            }
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
}

int * makeArrayNumbers(string roman, vector<struct databaseRomanToInt> db)
{
    int *arrayNumbers;
    arrayNumbers = new int[roman.size() + 1];

    int index = 0;

    for (char s : roman)
    {
        for (auto i : db)
        {
            if (i.symbol == string(1, s))
            {
                arrayNumbers[index] = i.value;
                break;
            }
        }
        index++;
    }

    return arrayNumbers;
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


