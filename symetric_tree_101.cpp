/* Leetcode - 101. Symmetric Tree (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

bool isSymetric(vector<int> rootVar);
bool symetricVectors(vector<int> vec1, vector<int> vec2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 101. Symmetric Tree (C++ language) - ";
    
    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{1,2,2,3,4,4,3},{1,2,2,0,3,0,3}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isSymetric(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool symetricVectors(vector<int> vec1, vector<int> vec2)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec2[vec2.size() - 1 - i])
        {
            return false;
        }
    }
    
    return true;
}

bool isSymetric(vector<int> rootVar)
{
    int power = 2;
    rootVar.erase(rootVar.begin());

    while (!rootVar.empty())
    {
        vector<int> left {};
        vector<int> right {};

        for (int i = 0; i < power / 2; i++)
        {
            left.push_back(rootVar[i]);
        }
        
        for (int i = power / 2; i < power; i++)
        {
            right.push_back(rootVar[i]);
        }

        if (!symetricVectors(left, right))
        {
            return false;
        }
        
        
        rootVar.erase(rootVar.begin(), rootVar.begin() + power);
        power *= 2;
        
        left.clear();
        right.clear();
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