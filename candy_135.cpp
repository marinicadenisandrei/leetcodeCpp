/* Leetcode - 135. Candy (Cpp language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int> ratingsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 135. Candy (Cpp language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> ratings {{1,0,2},{1,2,2}};
    
    for (int test = 0; test < ratings.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << candy(ratings[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int candy(vector<int> ratingsVar)
{
    vector<int> candy (ratingsVar.size(),1);
    int sum {0};

    for (int i = 0; i < ratingsVar.size(); i++)
    {
        if (i == 0)
        {
            if (ratingsVar[i] > ratingsVar[i + 1])
            {
                candy[i]++;
            }
        }
        else if (i == ratingsVar.size() - 1)
        {
            if (ratingsVar[i] > ratingsVar[i - 1])
            {
                candy[i]++;
            }
        }
        else if (ratingsVar[i] > ratingsVar[i - 1] || ratingsVar[i] > ratingsVar[i + 1])
        {
            candy[i]++;
        }
    }

    for (int i = 0; i < candy.size(); i++)
    {
        sum += candy[i];   
    }

    return sum;
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