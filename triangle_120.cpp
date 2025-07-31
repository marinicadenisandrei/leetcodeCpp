/* Leetcode - 120. Triangle (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>> triangleVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 120. Triangle (C++ language) - Medium" << endl;

    vector<vector<vector<int>>> triangle {{{2},{3,4},{6,5,7},{4,1,8,3}}, {{-10}}};

    for (int test = 0; test < triangle.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minimumTotal(triangle[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int minimumTotal(vector<vector<int>> triangleVar)
{
    if (triangleVar.size() == 1 && triangleVar.back().size() == 1)
    {
        return triangleVar[0][0];
    }

    vector<vector<int>> output;
    output.push_back({triangleVar[0][0] + triangleVar[1][0], triangleVar[0][0] + triangleVar[1][1]});
    
    for (int i = 2; i < triangleVar.size(); i++)
    {
        vector<int> temp;

        for (int j = 0; j < output.back().size(); j++)
        {
            if (j > triangleVar[i].size() - 2)
            {
                break;
            }
        
            temp.push_back(output.back()[j] + triangleVar[i][j]);
            temp.push_back(output.back()[j] + triangleVar[i][j + 1]);
        }
        
        output.push_back(temp);
        temp.clear();
    }
    
    auto min_element = std::min_element(output.back().begin(), output.back().end());
    int minVar = *min_element;

    return minVar;
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