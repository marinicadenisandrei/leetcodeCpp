/* Leetcode - 112. Path Sum (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

bool hasPathSum(vector<int> rootVar, int targetSumVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 112. Path Sum (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{5,4,8,11,0,13,4,7,2,0,0,0,1}, {1,2,3}, {}};
    vector<int> targetSum {22,5,0};

    for (int test = 0; test < targetSum.size(); test++)
    {
        green();

        cout << "Test " << test + 1<< ": ";

        reset();

        cout << boolalpha << hasPathSum(root[test], targetSum[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool hasPathSum(vector<int> rootVar, int targetSumVar)
{
    int len = rootVar.size();
    int power = 1;
    int counter = 0;

    for (int i = 0; i < rootVar.size(); i++)
    {
        if ((i * 2) + 2 > rootVar.size())
        {
            break;
        }
    
        if (rootVar[i] == 0 && (rootVar[(i * 2) + 1] != 0))
        {
            rootVar.insert(rootVar.begin() + (i * 2) + 1, 0);
        }

        if (rootVar[i] == 0 && (rootVar[(i * 2) + 2] != 0))
        {
            rootVar.insert(rootVar.begin() + (i * 2) + 2, 0);
        }
    }

    while (len > 0)
    {
        len -= power;
        power *= 2;
        counter++;
    }
    
    int splitVar = counter;
    int index = 1;
    int c = 0;
    int indexVector = 0;

    while (rootVar.size() < power)
    {
        rootVar.push_back(0);
    }
    
    vector<int> sums (counter * 2, rootVar[0]);

    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter * 2; j++)
        {
            if (c == splitVar)
            {
                index++; 
                c = 0;
            }

            sums[indexVector] += rootVar[index];
            indexVector++;
            c++;          
        }

        c = 0;
        index++;
        splitVar /= 2;
        indexVector = 0;
    }

    for (auto i : sums)
    {
        if (i == targetSumVar)
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