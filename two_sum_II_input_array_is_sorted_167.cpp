/* Leetcode - 167. Two Sum II - Input Array Is Sorted (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> numbersVar, int targetVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 167. Two Sum II - Input Array Is Sorted (C++ language) - Medium" << endl;

    vector<vector<int>> numbers {{2,7,11,15},{2,3,4},{-1,0}};
    vector<int> target {9,6,-1};

    for (int test = 0; test < target.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(twoSum(numbers[test], target[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> twoSum(vector<int> numbersVar, int targetVar)
{
    auto l = [] (vector<int> numbersVar, int targetVar) {
        for (int i = 0; i < numbersVar.size(); i++)
        {
            for (int j = 0; j < numbersVar.size(); j++)
            {
                int result = numbersVar[i] + numbersVar[j];

                if (i != j && result == targetVar)
                {
                    return vector<int> {i + 1, j + 1};
                }
            }
        }

        return vector<int> {};
    };    

    return l(numbersVar, targetVar);
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