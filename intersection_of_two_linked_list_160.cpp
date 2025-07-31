/* Leetcode - 160. Intersection of Two Linked Lists (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

bool getIntersectionNode(int intersectValVar, vector<int> listAVar, vector<int> listBVar, int skipAVar, int skipBVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 160. Intersection of Two Linked Lists (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> intersectVal = {8,2,0}; 
    vector<vector<int>> listA = {{4,1,8,4,5},{1,9,1,2,4},{2,6,4}}; 
    vector<vector<int>> listB = {{5,6,1,8,4,5},{3,2,4},{1,5}};
    vector<int> skipA = {2,3,3};
    vector<int> skipB = {3,1,2};

    for (int test = 0; test < intersectVal.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        if (getIntersectionNode(intersectVal[test], listA[test], listB[test], skipA[test], skipB[test]))
        {
            cout << "Itersection at " << intersectVal[test] << " | ";
        }
        else
        {
            cout << "No intersection | ";
        }

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool getIntersectionNode(int intersectValVar, vector<int> listAVar, vector<int> listBVar, int skipAVar, int skipBVar)
{
    int index1 = skipAVar;
    int index2 = skipBVar;

    if (index1 >= listAVar.size() || index2 >= listBVar.size()) {
        return false;
    }

    while (index1 < listAVar.size()) {
        if (listAVar[index1] != listBVar[index2]) {
            return false;
        }
    
        index1++;
        index2++;
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