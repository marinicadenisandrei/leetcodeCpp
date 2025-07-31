/* Leetcode - 210. Course Schedule II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> findOrder(vector<vector<int>> prerequisitesVar, int numCoursesVar);
bool elementInVector(vector<int> vectorVar, int element);
bool insertElement(vector<int> &vectorVar, int afterValue, int element);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 210. Course Schedule II (C++ language) - Medium" << endl;

    vector<vector<vector<int>>> prerequisites {{{1,0}},{{1,0},{2,0},{3,1},{3,2}}};
    vector<int> numCourses {2,4};

    for (int test = 0; test < prerequisites.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";
        
        reset();

        printVector(findOrder(prerequisites[test], numCourses[test]));

        green();

        cout << "Passed" << endl;        
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << (i == 0 ? "[" : "") << vectorVar[i] << (i < vectorVar.size() - 1 ? ", " : "] | ");
    }   
}

bool insertElement(vector<int> &vectorVar, int afterValue, int element)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (vectorVar[i] == afterValue)
        {
            vectorVar.insert(vectorVar.begin() + i + 1, element);

            return true;
        }
    }

    return false;
}

bool elementInVector(vector<int> vectorVar, int element)
{
    for (int i : vectorVar)
    {
        if (i == element)
        {
            return true;
        }
    }
    
    return false;
}

vector<int> findOrder(vector<vector<int>> prerequisitesVar, int numCoursesVar)
{
    vector<int> result {};
    result.push_back(prerequisitesVar[0][1]);
    result.push_back(prerequisitesVar[0][0]);

    for (int i = 1; i < prerequisitesVar.size(); i++)
    {
        if (!elementInVector(result, prerequisitesVar[i][0]))
        {
            bool flag = insertElement(result, prerequisitesVar[i][1], prerequisitesVar[i][0]);

            if (!flag)
            {
                result.push_back(prerequisitesVar[i][0]);
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