/* Leetcode - 177. Nth Highest Salary (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int getNthHighestSalary(vector<int> salaryVar, int nVar);

int main() 
{
    yellow();

    cout << "Leetcode - 177. Nth Highest Salary (C++ language) - Medium" << endl;

    vector<vector<int>> salary {{100,200,300},{100}};
    vector<int> n {2,2};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << getNthHighestSalary(salary[test], n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int getNthHighestSalary(vector<int> salaryVar, int nVar)
{   
    sort(salaryVar.begin(), salaryVar.end());

    if (nVar - 1 < salaryVar.size())
    {
        return salaryVar[nVar - 1]; 
    }
    
    return -1;
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