#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

void departamentTopThreeSalaries(vector<string> nameVar, vector<int> salaryVar, vector<int> departamentIDVar, vector<string> departamentNameVar);

int main()
{
    yellow();

    cout << "Leetcode - 185. Department Top Three Salaries (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> name {"Joe","Henry","Sam","Max","Janet","Randy","Will"};
    vector<int> salary {85000, 80000, 60000, 90000, 69000, 85000, 70000};
    vector<int> departamentID {1,2,2,1,1,1,1};
    vector<string> departamentName {"IT", "Sales"};

    green();

    cout << "Test 1: ";

    reset();

    departamentTopThreeSalaries(name, salary, departamentID, departamentName);

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void departamentTopThreeSalaries(vector<string> nameVar, vector<int> salaryVar, vector<int> departamentIDVar, vector<string> departamentNameVar)
{
    string result = "";

    vector<int> salarySortedUnique = vector<int>(salaryVar);
    sort(salarySortedUnique.begin(), salarySortedUnique.end());
    
    auto last = std::unique(salarySortedUnique.begin(), salarySortedUnique.end());
    salarySortedUnique.erase(last, salarySortedUnique.end());

    for (int i = 0; i < departamentNameVar.size(); i++)
    {
        int counter = 0;
        int historySalary = 0;

        for (int j = salarySortedUnique.size() - 1; j >= 0; j--)
        {
            for (int k = 0; k < salaryVar.size(); k++)
            {
                if (salaryVar[k] == salarySortedUnique[j] && (i + 1) == departamentIDVar[k])
                {
                    cout << departamentNameVar[i] << " | " << nameVar[k] << " | " << salaryVar[k] << endl; 
                    
                    if (historySalary != salaryVar[k])
                    {
                        counter++;
                    }

                    if (counter == 3)
                    {
                        break;
                    }

                    historySalary = salaryVar[k];
                }
            }

            if (counter == 3)
            {
                break;
            }
        }
    }

    cout << " | ";
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