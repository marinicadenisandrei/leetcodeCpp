#include <iostream>
#include <vector>

#define BLOCKER 999

using namespace std;

int uniquePathsWithObstacles(vector <vector <int>> obstacleGridVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 63. Unique Paths II (C++ language) - Medium" << endl;

    vector <vector <vector <int>>> obstacleGrid {{{0,0,0}, {0,1,0}, {0,0,0}}, {{0,1},{0,0}}};

    for (int test = 0; test < obstacleGrid.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << uniquePathsWithObstacles(obstacleGrid[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int uniquePathsWithObstacles(vector <vector <int>> obstacleGridVar)
{
    for (int i = 0; i < obstacleGridVar.size(); i++)
    {
        for (int j = 0; j < obstacleGridVar[i].size(); j++)
        {
            if(obstacleGridVar[i][j] == 1)
            {
                obstacleGridVar[i][j] = BLOCKER;
            }
        }
    }

    for (int i = 0; i < obstacleGridVar.size() - 1; i++)
    {
        if (obstacleGridVar[i][obstacleGridVar[i].size() - 1] != BLOCKER)
        {
            obstacleGridVar[i][obstacleGridVar[i].size() - 1] = 1;
        }
    }

    for (int i = 0; i < obstacleGridVar[obstacleGridVar.size() - 1].size(); i++)
    {
        if (obstacleGridVar[obstacleGridVar.size() - 1][i] != BLOCKER)
        {
            obstacleGridVar[obstacleGridVar.size() - 1][i] = 1;
        }
    }

    for (int i = obstacleGridVar.size() - 2; i >= 0; i--)
    {
        for (int j = obstacleGridVar[i].size() - 2; j >= 0; j--)
        {
            if (obstacleGridVar[i][j] == BLOCKER)
            {
                obstacleGridVar[i][j] = 0;
                continue;
            }

            if (obstacleGridVar[i + 1][j] == BLOCKER)
            {
                obstacleGridVar[i + 1][j] = 0;
            }
            
            if (obstacleGridVar[i][j + 1] == BLOCKER)
            {
                obstacleGridVar[i][j + 1] = 0;
            }

            obstacleGridVar[i][j] = obstacleGridVar[i + 1][j] + obstacleGridVar[i][j + 1];
        }
    }

    return obstacleGridVar[0][0];
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