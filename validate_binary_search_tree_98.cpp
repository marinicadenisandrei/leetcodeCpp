/* Leetcode - 98. Validate Binary Search Tree (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

bool isValidBST(vector <int> rootVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    cout << "Leetcode - 98. Validate Binary Search Tree (C++ language) - Medium" << endl;

    vector<vector<int>> root {{2,1,3},{5,1,4,0,0,3,6}};
    cout << boolalpha;
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << isValidBST(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

bool isValidBST(vector <int> rootVar)
{
    for (int i = 0; i < rootVar.size(); i++)
    {
        if ((i * 2) + 1 >= rootVar.size())
        {
            break;
        }

        if (rootVar[i] < rootVar[(i * 2) + 1] || rootVar[(i * 2) + 1] > rootVar[(i * 2) + 2] || rootVar[(i * 2) + 2] < rootVar[i])
        {
            if (rootVar[i] == 0 || rootVar[(i * 2) + 1] == 0 || rootVar[(i * 2) + 2] == 0)
            {
                if (rootVar[i] == 0 && (rootVar[(i * 2) + 1] > rootVar[(i * 2) + 2]))
                {
                    return false;
                    break;
                }
                
            }
            else
            {
                return false;
                break;
            }
            
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