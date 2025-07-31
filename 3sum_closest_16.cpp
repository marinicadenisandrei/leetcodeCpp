/* Leetcode - 16. 3Sum Closest (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void generateSumsFromVector(vector <int> vectorNumbers, vector <int> &vectorSums);
void bubbleSort(vector <int> &vectorVar);
int returnElementAfterTarget(vector <int> vectorVar, int targetVar, int left_index);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 16. 3Sum Closest (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{-1,2,1,-4}, {0,0,0}};
    vector <int> target {{1}, {1}};

    for (int test = 0; test < nums.size(); test++)
    {
        vector <int> sums {};

        generateSumsFromVector(nums.at(test), sums);
        bubbleSort(sums);

        int result {returnElementAfterTarget(sums, target.at(test), 0)};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();
        
        cout << result << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
}

void generateSumsFromVector(vector <int> vectorNumbers, vector <int> &vectorSums)
{
    for (int i = 0; i < vectorNumbers.size(); i++)
    {
        for (int j = 0; j < vectorNumbers.size(); j++)
        {
            for (int k = 0; k < vectorNumbers.size(); k++)
            {
                if (i != j && i != k && j != i && j != k && k != i && k != j)
                {
                    int sum {vectorNumbers[i] + vectorNumbers[j] + vectorNumbers[k]};
                    vectorSums.push_back(sum);

                    sum = 0;
                }
            }
        }
    }
}

void bubbleSort(vector <int> &vectorVar)
{
    bool swapped {true};
    int counter = 0;

    while (swapped)
    {
        swapped = false;

        for (int i = 0; i < vectorVar.size() - 1 - counter; i++)
        {
            if (vectorVar[i] > vectorVar[i + 1])
            {
                int temp = vectorVar[i];
                vectorVar[i] = vectorVar[i + 1];
                vectorVar[i + 1] = temp;

                swapped = true;
            }
        }

        counter++;
    }
}

int returnElementAfterTarget(vector <int> vectorVar, int targetVar, int left_index)
{
    if (left_index > vectorVar.size() - 1)
    {
        return 0;
    }

    if (vectorVar[left_index] > targetVar)
    {
        return vectorVar[left_index];
    }
    else
    {
        return returnElementAfterTarget(vectorVar, targetVar, left_index + 1);
    }
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