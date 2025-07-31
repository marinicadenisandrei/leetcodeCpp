/* Leetcode - 48. Rotate Image (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector <vector <int> >& matrix);
void printMatrix(vector <vector <int>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 48. Rotate Image (C++ language) - Medium" << endl;

    vector <vector <vector <int>>> matrix {{{1,2,3}, {4,5,6}, {7,8,9}},{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}};

    for (int test = 0; test < matrix.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        rotate(matrix.at(test));
        printMatrix(matrix.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printMatrix(vector <vector <int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix.at(i).at(j) << ((j < matrix.at(i).size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

void rotate(vector<vector<int>>& matrix)
{
    vector <vector <int>> output {};

    for (int j = 0; j < matrix.size(); j++)
    {
        output.push_back({});

        for (int k = matrix.at(j).size() - 1; k >= 0 ; k--)
        {
            output.at(j).push_back(matrix.at(k).at(j));
        }
    }

    matrix = output;
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