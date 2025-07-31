/* Leetcode - 304. Range Sum Query 2D - Immutable (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class NumMatrix
{
private:
    vector<vector<int>> matrix = {};
public:
    NumMatrix(const vector<vector<int>>& mat) 
    {
        matrix.resize(mat.size());
        for (size_t i = 0; i < mat.size(); ++i)
            matrix[i] = mat[i];
    }

    ~NumMatrix() = default;

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = 0;

        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                sum += this->matrix[i][j];
            }
        }
        
        return sum;
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 304. Range Sum Query 2D - Immutable (C++ language) - Medium" << endl;

    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7},{1, 0, 3, 0, 5}};

    green();

    cout << "Test 1: ";

    reset();

    NumMatrix numMatrix = NumMatrix(matrix);
    cout << numMatrix.sumRegion(2,1,4,3) << " " << numMatrix.sumRegion(1,1,2,2) << " " << numMatrix.sumRegion(1,2,2,4) << " | "; 

    green();

    cout << "Passed" << endl;

    reset();

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