/* Leetcode - 363. Max Sum of Rectangle No Larger Than K (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int maxSumSubmatrix(vector<vector<int>> matrixVar, int kVar);
int regionSumIn2DVector(vector<vector<int>> vect, int i_start, int i_end, int j_start, int j_end);

int main()
{
    yellow();

    cout << "Leetcode - 363. Max Sum of Rectangle No Larger Than K (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> matrix = {{{1,0,1},{0,-2,3}},{{2,2,-1}}};
    vector<int> k = {2,3};

    for (int test = 0; test < k.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxSumSubmatrix(matrix[test], k[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int regionSumIn2DVector(vector<vector<int>> vect, int i_start, int i_end, int j_start, int j_end)
{
    int sum = 0;

    for (int i = i_start; i <= i_end; i++)
    {
        for (int j = j_start; j <= j_end; j++)
        {
            sum += vect[i][j];
        }
    }

    return sum;
}

int maxSumSubmatrix(vector<vector<int>> matrixVar, int kVar)
{
    int sum = 0;

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            int temp_sum = matrixVar[i][j];
            sum = ((sum < temp_sum & temp_sum <= kVar) ? temp_sum : sum);

            int temp_i = i;
            int temp_j = j;
            bool flag = true;
            
            while (flag)
            {
                flag = false;
                if (temp_i < matrixVar.size() - 1)
                {
                    temp_i++;
                    flag = true;
                }
                
                if (temp_j < matrixVar[i].size() - 1)
                {
                    temp_j++;
                    flag = true;
                }
                
                temp_sum += regionSumIn2DVector(matrixVar, i, temp_i, j, temp_j);
                sum = ((sum < temp_sum & temp_sum <= kVar) ? temp_sum : sum);
            }

            temp_sum = 0;
        }   
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