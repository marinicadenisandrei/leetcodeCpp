/* Leetcode - 47. Permutations II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> permuteUnique(vector <int> vectorVar);
void printMatrix(vector <vector <int>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 47. Permutations II (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{1,1,2}, {1,2,3}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printMatrix(permuteUnique(nums.at(test)));

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

vector <vector <int>> permuteUnique(vector <int> vectorVar)
{
    vector <vector <int>> output {};
    output.push_back(vectorVar);

    int index1 {0};
    int index2 {1};

    int depth {1};

    for (int i = 1; i <= vectorVar.size(); i++)
    {
        depth *= i;
    }

    for (int i = 0; i < depth; i++)    
    {   
        bool flag = true;

        for (auto j : output)
        {
            if (j == vectorVar)
            {
                flag = false;
            }
        }

        if (flag)
        {
            output.push_back(vectorVar);
        }
        
        if (index2 < vectorVar.size())
        {
            int temp {vectorVar.at(index1)};
            vectorVar.at(index1) = vectorVar.at(index2);
            vectorVar.at(index2) = temp;
        }
        else
        {
            int temp {vectorVar.at(0)};
            vectorVar.at(0) = vectorVar.at(vectorVar.size() - 1);
            vectorVar.at(vectorVar.size() - 1) = temp;

            index1 = -1;
            index2 = 0;
        }

        index1++;
        index2++;
    }

    return output;
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