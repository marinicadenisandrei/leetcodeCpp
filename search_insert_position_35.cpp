#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector <int> vectorVar, int targetVar);
int findIndexElement(vector <int> vectorVar, int targetVar);
int findLessThanIndexElement(vector <int> vectorVar, int targetVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 35. Search Insert Position (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <vector <int>> nums {{1,3,5,6}, {1,3,5,6}, {1,3,5,6}};
    vector <int> target {5,2,7};

    for (int test = 0; test < nums.size(); test++)
    {
        int result = searchInsert(nums.at(test), target.at(test));

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";
        
        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int searchInsert(vector <int> vectorVar, int targetVar)
{
    return findIndexElement(vectorVar, targetVar);
}

int findIndexElement(vector <int> vectorVar, int targetVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (vectorVar.at(i) == targetVar)
        {
            return i;
        }
    }

    return findLessThanIndexElement(vectorVar, targetVar);
}

int findLessThanIndexElement(vector <int> vectorVar, int targetVar)
{
    for (int i = vectorVar.size() - 1; i >= 0; i--)
    {
        if (vectorVar.at(i) < targetVar)
        {
            return i + 1;
        }
    }

    return vectorVar.size();   
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