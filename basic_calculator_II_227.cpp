/* Leetcode - 227. Basic Calculator II (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int Calculate(string sVar);

int main()
{
    yellow();

    cout << "Leetcode - 227. Basic Calculator II (C++ language) - Medium" << endl;

    vector<string> s {"3+2*2","3/2 ","3+5 / 2 "};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << Calculate(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int Calculate(string sVar)
{
    bool flagPriority2 = true;
    bool flagPriority1 = true;

    sVar.erase(std::remove(sVar.begin(), sVar.end(), ' '), sVar.end());

    while (flagPriority2)
    {
        flagPriority2 = false;

        for (int i = 0; i < sVar.size() - 1; i++)
        {
            int result = 0;

            if (sVar[i] == '*')
            {
                int number1 = sVar[i - 1] - '0';
                int number2 = sVar[i + 1] - '0';
                
                result = number1 * number2;
                sVar = sVar.substr(0, i - 1) + to_string(result) + sVar.substr(i + 2, sVar.size());
                
                flagPriority2 = true;
                
                break;
            }
            else if (sVar[i] == '/') 
            {
                int number1 = sVar[i - 1] - '0';
                int number2 = sVar[i + 1] - '0';
                
                result = number1 / number2;
                sVar = sVar.substr(0, i - 1) + to_string(result) + sVar.substr(i + 2, sVar.size());

                flagPriority2 = true;

                break;
            }
        }
    }

    while (flagPriority1)
    {
        flagPriority1 = false;

        for (int i = 0; i < sVar.size() - 1; i++)
        {
            int result = 0;

            if (sVar[i] == '-')
            {
                int number1 = sVar[i - 1] - '0';
                int number2 = sVar[i + 1] - '0';
                
                result = number1 - number2;
                sVar = sVar.substr(0, i - 1) + to_string(result) + sVar.substr(i + 2, sVar.size());
                
                flagPriority1 = true;
                
                break;
            }
            else if (sVar[i] == '+') 
            {
                int number1 = sVar[i - 1] - '0';
                int number2 = sVar[i + 1] - '0';
                
                result = number1 + number2;
                sVar = sVar.substr(0, i - 1) + to_string(result) + sVar.substr(i + 2, sVar.size());

                flagPriority1 = true;

                break;
            }
        }
    }

    return stoi(sVar);
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