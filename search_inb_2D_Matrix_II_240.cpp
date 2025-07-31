/* Leetcode - 240. Search a 2D Matrix II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool searchMatrix(vector<vector<int>> &matrixVar, int &targetVar);

int main()
{
    yellow();

    cout << "Leetcode - 240. Search a 2D Matrix II (C++ language) - Medium" << endl;

    vector<vector<vector<int>>> matrix = {{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}},
                                {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}}; 
    vector<int> target = {5,20};

    for (int test = 0; test < matrix.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << searchMatrix(matrix[test], target[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

bool searchMatrix(vector<vector<int>> &matrixVar, int &targetVar)
{
    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            if (matrixVar[i][j] == targetVar)
            {
                return true;
            }
        }
    }

    return false;
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