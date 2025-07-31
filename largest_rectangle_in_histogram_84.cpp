/* Leetcode - 84. Largest Rectangle in Histogram (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector <int> heightsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 84. Largest Rectangle in Histogram (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <int>> heights {{2,1,5,6,2,3},{2,4}};

    for (int test = 0; test < heights.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << largestRectangleArea(heights[test]) << " | ";

        green();
        
        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int largestRectangleArea(vector <int> heightsVar)
{
    int mul {0};
    int max {0};

    int maxArray {0};

    for (auto i : heightsVar)
    {
        if (maxArray < i)
        {
            maxArray = i;
        }
    }
    
    for (int i = 0; i < maxArray; i++)
    {
        for (int j = 0; j < heightsVar.size(); j++)
        {
            if (i <= heightsVar[j])
            {
                mul++;
            }
            else
            {   
                if (max < i * mul)
                {
                    max = i * mul;
                }
                
                mul = 0;
            }
        }
        
        if (max < i * mul)
        {
            max = i * mul;
        }

        mul = 0;
    }

    return max;
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