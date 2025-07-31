/* Leetcode - 77. Combinations (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> combine(int nVar, int kVar);
bool duplicatesInArray(vector <int> vectorVar);
void printVector(vector <vector <int>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 77. Combinations (C++ language) - Medium" << endl;

    vector <int> n {4,1};
    vector <int> k {2,1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector <vector <int>> output = combine(n[test], k[test]);
        printVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(vector <vector <int>> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        for (int j = 0; j < vectorVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[i].size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

bool duplicatesInArray(vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        for (int j = i + 1; j < vectorVar.size(); j++)
        {
            if (vectorVar[i] == vectorVar[j])
            {
                return true;
            }
        }
    }

    return false;
}

vector <vector <int>> combine(int nVar, int kVar)
{
    vector <int> combVector {};

    for (int i = 1; i <= nVar; i++)
    {
        combVector.push_back(i);
    }

    vector <vector <int>> acumulation {};

    if (nVar == 1)
    {
        acumulation.push_back(combVector);
        return acumulation;   
    }

    for (int i = 0; i < combVector.size(); i++)
    {
        for (int j = 0; j < combVector.size(); j++)
        {
            if (i < j)
            {
                acumulation.push_back({});

                acumulation[acumulation.size() - 1].push_back(combVector[i]);
                acumulation[acumulation.size() - 1].push_back(combVector[j]); 
            }
        }
    }
    
    kVar -= 2;

    for (int l = 0; l < kVar; l++)
    {
        vector <vector <int>> tempAcumulation {};

        for (int k = 0; k < combVector.size(); k++)
        {
            for (int i = 0; i < acumulation.size(); i++)
            {
                tempAcumulation.push_back({});
                tempAcumulation[tempAcumulation.size() - 1].push_back(combVector[k]);

                for (int j = 0; j < acumulation[i].size(); j++)
                {
                    tempAcumulation[tempAcumulation.size() - 1].push_back(acumulation[i][j]);
                }
            }
        }

        acumulation.clear();

        for (int i = 0; i < tempAcumulation.size(); i++)
        {
            acumulation.push_back({});

            for (int j = 0; j < tempAcumulation[i].size(); j++)
            {
                acumulation[acumulation.size() - 1].push_back(tempAcumulation[i][j]);
            }
        }

        tempAcumulation.clear();
    }

    return acumulation;
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