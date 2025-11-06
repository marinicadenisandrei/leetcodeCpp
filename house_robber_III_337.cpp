/* Leetcode - 337. House Robber III (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int rob(vector<int> rootVar);

int main()
{
    yellow();
    
    cout << "Leetcode - 337. House Robber III (C++ language) - Medium" << endl;

    vector<vector<int>> root = {{3,2,3,0,3,0,1},{3,4,5,1,3,0,1}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << rob(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int rob(vector<int> rootVar)
{
    vector<int> candidates = {};
    candidates.push_back(rootVar[0]);

    int result = 0;

    int start = 1;
    int end = 2;
    int level = 2;
    
    while (end < rootVar.size())
    {
        int max_l = 0;
        int max_r = 0;
        vector<int> temp = {};

        for (int i = start; i <= end; i++)
        {
            temp.push_back(rootVar[i]);
        }

        for (int i = 0; i < level / 2; i++)
        {
            if (max_l < temp[i] )
            {
                max_l = temp[i];
            }
        }

        for (int i = level / 2; i < temp.size(); i++)
        {
            if (max_r < temp[i] )
            {
                max_r = temp[i];
            }
        }
        
        candidates.push_back(max_l + max_r);

        start = end + 1;
        end = start * 2;
        level *= 2;
    }

    for (int i = 0; i < 2; i++)
    {
        int tempResult = 0;

        for (int j = i; j < candidates.size(); j += 2)
        {
            tempResult += candidates[j];
        }

        result = ((result < tempResult) ? tempResult : result);
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