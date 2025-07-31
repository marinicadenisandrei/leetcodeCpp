/* Leetcode - 182. Duplicate Emails (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> duplicateEmails(vector<string> emailVar);
bool stringInArray(string stringVar, vector<string> vectorVar);
void printVector(vector<string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 182. Duplicate Emails (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> email {"a@b.com","c@b.com","a@b.com"};

    green();

    cout << "Test 1: ";

    reset();

    printVector(duplicateEmails(email));

    green();

    cout << "Passed";

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

vector<string> duplicateEmails(vector<string> emailVar)
{
    vector<string> result = {};

    for (int i = 0; i < emailVar.size(); i++)
    {
        for (int j = 0; j < emailVar.size(); j++)
        {
            if (i != j && emailVar[i] == emailVar[j] && !stringInArray(emailVar[i], result))
            {
                result.push_back(emailVar[i]);
                break;
            }
        }
    }
    
    return result;
}

bool stringInArray(string stringVar, vector<string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (vectorVar[i] == stringVar)
        {
            return true;
        }
    }
    
    return false;
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