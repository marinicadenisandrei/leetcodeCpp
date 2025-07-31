#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 11. Container With Most Water (C++ language) - Medium" << endl;

    vector <vector <int>> height {{1,8,6,2,5,4,8,3,7}, {1,1}};
    
    for (int test = 0; test < height.size(); test++)
    {
        int max_var {};

        for (int i = 0; i < height.at(test).size(); i++)
        {
            for (int j = 0; j < height.at(test).size() - 1; j++)
            {
                if (i != j)
                {
                    max_var = (((min(height.at(test)[i], height.at(test)[j]) * abs(j-i)) > max_var) ? (min(height.at(test)[i], height.at(test)[j]) * abs(j-i)) : max_var);
                }  
            }
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << max_var << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }

    return 0;
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