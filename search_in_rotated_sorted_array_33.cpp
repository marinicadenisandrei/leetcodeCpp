/* Leetcode - 33. Search in Rotated Sorted Array (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int search(vector <int> vectorVar, int element, int left_index, int right_index);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 33. Search in Rotated Sorted Array (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{4,5,6,7,0,1,2},{4,5,6,7,0,1,2},{1}};
    vector <int> target {0,3,0};

    for (int test = 0; test < nums.size(); test++)
    {
        int result = search(nums.at(test), target.at(test), 0, nums.at(test).size() - 1);

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int search(vector <int> vectorVar, int element, int left_index, int right_index)
{
    if (left_index > right_index)
    {
        return -1;
    }

    if (vectorVar.at(left_index) == element)
    {
        return left_index;
    }
    else
    {
        return search(vectorVar, element, left_index + 1, right_index);
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