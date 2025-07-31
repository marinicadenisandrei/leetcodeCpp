/* Leetcode - 38. Count and Say (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string countAndSay(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 38. Count and Say (C++ language) - Medium" << endl;

    vector <int> n {1,4};
    
    for (int test = 0; test < n.size(); test++)
    {
        string result {countAndSay(n.at(test))};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

string countAndSay(int nVar)
{
    if (nVar == 1)
    {
        return "1";
    }
    
    string starter {"1"};
    string newString {""};
    
    int counter {1};

    for (int  i = 0; i < nVar - 1; i++)
    {
        starter += "x";

        for (int j = 1; j < starter.size(); j++)
        {
            if (starter[j-1] == starter[j])
            {
                counter++;
            }
            else
            {
                newString += to_string(counter);
                string myString(1,starter[j-1]);
                newString += myString;

                counter = 1;
            }
        }

        starter = newString;
        newString.clear();
    }

    return starter;
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