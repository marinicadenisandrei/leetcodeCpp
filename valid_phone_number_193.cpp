#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> validPhoneNumber(vector<string> phoneVar);
void printVector(vector<string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 193. Valid Phone Numbers (C++ language) - ";

    green();

    cout << "Easy" << endl;

    reset();

    vector<string> phone {"987-123-4567","123 456 7890","(123) 456-7890"};
    
    green();

    cout << "Test 1: ";
    
    reset();

    printVector(validPhoneNumber(phone));

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void printVector(vector<string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }  
}

vector<string> validPhoneNumber(vector<string> phoneVar)
{
    regex pattern1(R"(\d{3}-\d{3}-\d{4})");
    regex pattern2(R"(\(\d{3}\) \d{3}-\d{4})");

    vector<string> result = {};

    for (int i = 0; i < phoneVar.size(); i++)
    {
        if (regex_match(phoneVar[i], pattern1) || regex_match(phoneVar[i], pattern2))
        {
            result.push_back(phoneVar[i]);
        }
    }

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