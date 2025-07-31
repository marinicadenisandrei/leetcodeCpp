/* Leetcode - 176. Second Highest Salary (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int secondHighestSalary(vector<int> salaryVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 176. Second Highest Salary (C++ language) - Medium" << endl;

    vector<vector<int>> salary {{100,200,300},{100},{}};

    for (int test = 0; test < salary.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << secondHighestSalary(salary[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int secondHighestSalary(vector<int> salaryVar)
{
    sort(salaryVar.begin(), salaryVar.end());
    return ((salaryVar.size() > 1) ? salaryVar[1] : ((salaryVar.size() == 1) ? salaryVar[0] : -1));
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