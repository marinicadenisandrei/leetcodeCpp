/* Leetcode - 174. Dungeon Game (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

int calculateMinimumHP(vector<vector<int>> dungeonVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 174. Dungeon Game (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> dungeon {{{-2,-3,3},{-5,-10,1},{10,30,-5}},{{0}}};
    
    for (int test = 0; test < dungeon.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << calculateMinimumHP(dungeon[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int calculateMinimumHP(vector<vector<int>> dungeonVar)
{
    int f = 1;

    for (int j = dungeonVar[dungeonVar.size() - 1].size() - 1; j >= 0; j--)
    {
        dungeonVar[dungeonVar.size() - 1][j] = max(1, f - dungeonVar[dungeonVar.size() - 1][j]);
        f = dungeonVar[dungeonVar.size() - 1][j];
    }

    for (int i = dungeonVar.size() - 2; i >= 0; i--)
    {
        dungeonVar[i][dungeonVar[i].size() - 1] = max(1, dungeonVar[i + 1][dungeonVar[i].size() - 1] - dungeonVar[i][dungeonVar[i].size() - 1]);
        f = dungeonVar[i][dungeonVar[i].size() - 1];
    }
    
    for (int i = dungeonVar.size() - 2; i >= 0; i--)
    {
        for (int j = dungeonVar[i].size() - 2; j >= 0; j--)
        {
            dungeonVar[i][j] = max(min(dungeonVar[i][j + 1], dungeonVar[i + 1][j]), min(dungeonVar[i][j + 1], dungeonVar[i + 1][j]) - dungeonVar[i][j]);
            f = dungeonVar[i][j];
        }
    }

    return dungeonVar[0][0];
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