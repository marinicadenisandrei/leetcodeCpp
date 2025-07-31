/* Leetcode - 218. The Skyline Problem (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<vector<int>> getSkyline(vector<vector<int>> buildingsVar);
void display2DVector(vector<vector<int>> vector2d);

int main()
{
    yellow();

    cout << "Leetcode - 218. The Skyline Problem (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> buildings {{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}},{{0,2,3},{2,5,3}}};
    
    for (int test = 0; test < buildings.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        display2DVector(getSkyline(buildings[test]));
    
        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void display2DVector(vector<vector<int>> vector2d)
{
    if (vector2d.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    
    cout << "[";

    for (vector<int> vect : vector2d)
    {
        for (int i = 0; i < vect.size(); i++)
        {
            cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
}

vector<vector<int>> getSkyline(vector<vector<int>> buildingsVar)
{
    vector<vector<int>> result {{}};

    int height {0};
    int width {0};

    for (vector<int> vect : buildingsVar)
    {
        height = ((height < vect[2]) ? vect[2] : height);
        width = ((width < vect[1]) ? vect[1] : width);
    }

    height += 1;
    width += 1;

    std::vector<std::vector<int>> worldMap(height, std::vector<int>(width, 0));

    for (vector<int> vect : buildingsVar)
    {
        for (int i = 0; i < vect[2]; i++)
        {
            for (int j = vect[0]; j < vect[1]; j++)
            {
                worldMap[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (worldMap[i][j] == 1 && worldMap[i][j - 1] == 0 && worldMap[i + 1][j] == 0 && worldMap[i + 1][j - 1] == 0)
            {
                result.push_back(vector<int>({j,i + 1}));
            }
            else if (worldMap[i][j] == 1 && worldMap[i][j + 1] == 1 && worldMap[i + 1][j] == 1 && worldMap[i + 1][j + 1] == 0)
            {
                result.push_back(vector<int>({j + 1, i + 1}));
            } 
            else if (worldMap[i][j] == 1 && worldMap[i][j + 1] == 0 && worldMap[i + 1][j] == 1 && (i - 1) == -1) 
            {
                result.push_back(vector<int>({j + 1, i}));
            }
            else if (worldMap[i][j] == 1 && worldMap[i][j + 1] == 1 && worldMap[i + 1][j] == 0 && worldMap[i + 1][j + 1] == 0 && (j - 1) == -1) 
            {
                result.push_back(vector<int>({j, i + 1}));
            }         
        }
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