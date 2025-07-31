/* Leetcode - 224. Basic Calculator (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <regex>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int calculate(string sVar);
std::string removeSpaces(const std::string& input);

int main()
{
    yellow();

    cout << "Leetcode - 224. Basic Calculator (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> s = {"1 + 1","2-1 + 2","(1+(4+5+2)-3)+(6+8)"}; 
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << calculate(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

std::string removeSpaces(const std::string& input) {
    std::string result;
    for (char ch : input) {
        if (ch != ' ') { 
            result += ch;
        }
    }
    return result;
}

int calculate(string sVar)
{
    bool flag = true;
    sVar = removeSpaces(sVar);

    while (flag)
    {
        flag = false;

        for (int i = 1; i < sVar.size() - 1; i++)
        {
            if ((sVar[i] == '+' || sVar[i] == '-') && isdigit(sVar[i - 1]) && isdigit(sVar[i + 1]))
            {
                string result = "";
                
                string number1Str = "";
                string number2Str = "";

                int index1 = i - 1;
                int index2 = i + 1;

                while (index1 >= 0 && isdigit(sVar[index1])) 
                {
                    number1Str = sVar[index1] + number1Str;
                    index1--;
                }
                index1++; 

                while (index2 < sVar.size() && isdigit(sVar[index2])) 
                {
                    number2Str += sVar[index2];
                    index2++;
                }

                int number1 = stoi(number1Str);
                int number2 = stoi(number2Str);

                switch (sVar[i])
                {
                case '+':
                    result = to_string(number1 + number2);
                    break;
                default:
                    result = to_string(number1 - number2);
                    break;
                }
                
                sVar = sVar.substr(0, index1) + result + sVar.substr(index2, sVar.size() - index2);
                
                regex singleNumPattern(R"(\((\d+)\))");
                sVar = std::regex_replace(sVar, singleNumPattern, "$1");

                flag = true;
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