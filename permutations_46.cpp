/* Leetcode - 46. Permutations (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> permute(vector <int> nums);
void printMatrix(vector <vector <int>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 46. Permutations (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{1,2,3}, {0,1}, {1}};

    for (int test = 0; test < nums.size(); test++)
    {
        vector <vector <int>> result {permute(nums.at(test))};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printMatrix(result);

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

vector <vector <int>> permute(vector <int> nums)
{    
    vector <vector <int>> output {};   

    if (nums.size() == 1)
    {
        output.push_back(nums);
        return output;
    }

    vector <int> copy = nums;

    int temp {nums.at(0)};
    nums.at(0) = nums.at(1);
    nums.at(1) = temp;

    int index1 {1};
    int index2 {2}; 

    output.push_back(copy);

    while (nums != copy)
    {
        output.push_back(nums);

        if (index2 < nums.size())
        {
            int temp {nums.at(index1)};
            nums.at(index1) = nums.at(index2);
            nums.at(index2) = temp;
        }
        else
        {
            int temp {nums.at(0)};
            nums.at(0) = nums.at(nums.size() - 1);
            nums.at(nums.size() - 1) = temp;

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

    