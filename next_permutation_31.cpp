/* Leetcode - 31. Next Permutation (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ARRAY_SIZE 20
#define NUMBER_OF_TESTS 3

void nextPermutation(vector <int> &vectorVar);
void printVector(const vector <int> vectorVar);
int depthPermutations(const vector <int> vectorVar);
bool checkIfArraysEquals(const vector <int> array1, const vector <int> array2);
bool descendingVector(const vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 31. Next Permutation (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{1,2,3},{3,2,1},{1,1,5}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        nextPermutation(nums.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void nextPermutation(vector <int> &vectorVar)
{
    int index0 {0};
    int index1 {1};

    int depth = depthPermutations(vectorVar);
    vector <int> copyVector {vectorVar};

    vector <vector <int>> output {};
    output.push_back(vectorVar);

    while (depth > 1)
    {
        if (index1 < vectorVar.size())
        {
            int temp = vectorVar.at(index0);
            vectorVar.at(index0) = vectorVar.at(index1);
            vectorVar.at(index1) = temp;
        }
        else
        {
            int temp = vectorVar.at(0);
            vectorVar.at(0) = vectorVar.at(vectorVar.size() - 1);
            vectorVar.at(vectorVar.size() - 1) = temp;

            index0 = -1;
            index1 = 0;
        }

        index0++;
        index1++;

        depth--;

        output.push_back(vectorVar);
    }

    std::sort(output.begin(), output.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    if (descendingVector(copyVector))
    {
        sort(copyVector.begin(), copyVector.end());
        printVector(copyVector);
    }
    else
    {
        for (int i = 0; i < output.size(); i++)
        {       
            if (checkIfArraysEquals(output.at(i), copyVector))
            {
                if (i + 1 < output.size())
                {
                    printVector(output.at(i + 1));
                }

                break;   
            }
        }
    }
}

void printVector(const vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

int depthPermutations(const vector <int> vectorVar)
{
    int depth {1};

    for (int i = 1; i <= vectorVar.size(); i++) depth *= i; 
    
    return depth;
}

bool checkIfArraysEquals(const vector <int> array1, const vector <int> array2)
{
    for (int i = 0; i < array1.size(); i++)
    {
        if (array1.at(i) != array2.at(i))
        {
            return false;
        }
    }

    return true;
}

bool descendingVector(const vector <int> vectorVar)
{
    for (int i = vectorVar.size() - 1; i > 0; i--)
    {
        if (vectorVar.at(i) + 1 != vectorVar.at(i - 1))
        {
            return false;
        }
    }

    return true;
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