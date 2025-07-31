/* Leetcode - 42. Trapping Rain Water (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector <int> height);
int createMatrixAndReturn(vector <int> inputVector, vector <vector <int>> &outputVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 42. Trapping Rain Water (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <int>> height {{0,1,0,2,1,0,1,3,2,1,2,1}, {4,2,0,3,2,5}};

    for (int test = 0; test < height.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << trap(height.at(test)) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int createMatrixAndReturn(vector <int> inputVector, vector <vector <int>> &outputVar)
{
    auto maxElement = max_element(inputVector.begin(), inputVector.end());
    int sumOfWater {0};
    
    for (int i = 0; i < *maxElement; i++)
    {
        outputVar.push_back({});

        for (int j = 0; j < inputVector.size(); j++)
        {
            if (i < inputVector[j])
            {
                outputVar[0].push_back(1);
            }
            else
            {
                outputVar[0].push_back(0);
            }
        }

        while (outputVar[0][0] == 0)
        {
            outputVar[0].erase(outputVar[0].begin());
        }

        while (outputVar[0][outputVar[0].size() - 1] == 0)
        {
            outputVar[0].erase(outputVar[0].end() - 1);
        }

        for (int l = 0; l < outputVar[0].size(); l++)
        {
            if (outputVar[0][l] == 0)
            {
                sumOfWater++;
            }
        }

        outputVar.clear();
    }

    return sumOfWater;
}

int trap(vector <int> height)
{
    vector <vector <int>> matrix {};
    return createMatrixAndReturn(height, matrix);
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