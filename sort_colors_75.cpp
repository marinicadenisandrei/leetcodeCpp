/* Leetcode - 75. Sort Colors (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sortColors(vector <int> &numsVar);
void printArray(vector <int> array);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 75. Sort Colors (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{2,0,2,1,1,0}, {2,0,1}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        sortColors(nums[test]);
        printArray(nums[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printArray(vector <int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << array[i] << ((i < array.size() - 1) ? ", " : "]"); 
    }

    cout << " | ";
}

void sortColors(vector <int> &numsVar)
{
    bool flag = true;
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 1; i < numsVar.size() - counter; i++)
        {
            if (numsVar[i - 1] > numsVar[i])
            {
                int temp = numsVar[i - 1];
                numsVar[i - 1] = numsVar[i];
                numsVar[i] = temp;
                flag = true;
            }
        }

        counter++;
    }
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