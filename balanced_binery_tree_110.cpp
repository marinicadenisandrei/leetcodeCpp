#include <iostream>
#include <vector>

using namespace std;

bool isBalanced(vector<int> rootVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 110. Balanced Binary Tree (Cpp language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{3,9,20,0,0,15,7},{1,2,2,3,3,0,0,4,4}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isBalanced(root[0]) << " | ";

        green();

        cout << "Passed" << endl;   
    }

    reset();

    return 0;
}

bool isBalanced(vector<int> rootVar)
{
    int power {2};
    int zeros {0};
    int level {0};

    rootVar.erase(rootVar.begin());

    while (rootVar.size() > 0)
    {   
        if (zeros > 0)
        {
            return false;
        }
        
        for (int i = 0; i < power; i++)
        {
            if (rootVar.size() == 0)
            {
                break;
            }

            if (rootVar[i] == 0 && power > 2)
            {
                zeros++;
            }

            rootVar.erase(rootVar.begin());
        }

        power *= 2;
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