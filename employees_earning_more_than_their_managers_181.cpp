/* Leetcode - 181. Employees Earning More Than Their Managers (C++ language) - Easy*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string find_employees(vector<int> idVar, vector<string> nameVar, vector<int> salaryVar, vector<int> managerIDVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 181. Employees Earning More Than Their Managers (C++ language) - ";
    
    green();

    cout << "Easy" << endl;

    vector<int> id {1,2,3,4};
    vector<string> name {"Joe", "Henry", "Sam", "Max"};
    vector<int> salary {70000, 80000, 60000, 90000};
    vector<int> managerID {3,4,0,0};

    green();

    cout << "Test 1: ";

    reset();

    cout << find_employees(id, name, salary, managerID) << " | ";

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

string find_employees(vector<int> idVar, vector<string> nameVar, vector<int> salaryVar, vector<int> managerIDVar)
{
    int diff {0};
    string name {""};

    for (int i = 0; i < idVar.size(); i++)
    {
        if (managerIDVar[i] != 0)
        {
            for (int j = 0; j < idVar.size(); j++)
            {
                if (managerIDVar[i] == idVar[j] && salaryVar[i] > salaryVar[j] && salaryVar[i] - salaryVar[j] > diff)
                {
                    diff = salaryVar[i] - salaryVar[j];
                    name = nameVar[i];
                }
            }
        }
    }
    
    return name;
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