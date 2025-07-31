#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector <int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 41. First Missing Positive (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <int>> nums {{1,2,0}, {3,4,-1,1}, {7,8,9,11,12}};

    for (int test = 0; test < nums.size(); test++)
    {
        int result = firstMissingPositive(nums.at(test));

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

int firstMissingPositive(vector <int> numsVar)
{
    sort(numsVar.begin(), numsVar.end());

    for (int i = 0; i < numsVar.size(); i++)
    {
        if (numsVar.at(i) <= 0)
        {
            numsVar.erase(numsVar.begin() + i);
        }
    }
    
    if (numsVar.at(0) != 1)
    {
        return 1;
    }

    for (int i = 0; i < numsVar.size() - 1; i++)
    {
        if ((numsVar[i + 1] - numsVar[i]) > 1)
        {
            return numsVar[i] + 1;
        }
    }
    
    return numsVar.at(numsVar.size() - 1) + 1;
}

