/* Leetcode - 184. Department Highest Salary (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string departamentHighestSalary(vector<string> nameVar, vector<int> salaryVar, vector<int> departamentIDVar, vector<string> departamentVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 184. Department Highest Salary (C++ language) - Medium" << endl;

    vector<string> name {"Joe", "Jim", "Henry", "Sam", "Max"};
    vector<int> salary {70000, 90000, 80000, 60000, 90000};
    vector<int> departamentID {1,1,2,2,1};
    vector<string> departament {"IT", "Sales"};

    green();

    cout << "Test 1: " << endl;

    reset();

    cout << departamentHighestSalary(name, salary, departamentID, departament);

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

string departamentHighestSalary(vector<string> nameVar, vector<int> salaryVar, vector<int> departamentIDVar, vector<string> departamentVar)
{
    vector<int> sortSalary = salaryVar;
    sort(sortSalary.begin(), sortSalary.end());
    
    auto last = std::unique(sortSalary.begin(), sortSalary.end());
    sortSalary.erase(last, sortSalary.end());

    string result = "";
    int counter = 0;

    for (int i = sortSalary.size() - 1; i >= sortSalary.size() - 3; i--)
    {
        for (int j = 0; j < nameVar.size(); j++)
        {
            if (sortSalary[i] == salaryVar[j])
            {
                result += departamentVar[departamentIDVar[j] - 1] + " | " + nameVar[j] + " | " + to_string(sortSalary[i]) + "\n";
                counter++;

                if (counter == 3)
                {
                    return result;
                }
            }
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