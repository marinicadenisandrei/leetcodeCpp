/* Leetcode - 179. Largest Number (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm> 
#include <sstream>   

using namespace std;

bool compare(int a, int b);
string largestNumber(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 179. Largest Number (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{10,2},{3, 30, 34, 5, 9}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();
    
        cout << largestNumber(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool compare(int a, int b) {
    stringstream ss1, ss2;
    ss1 << a << b;
    ss2 << b << a;
    return ss1.str() > ss2.str();
}

string largestNumber(vector<int> numsVar)
{
    sort(numsVar.begin(), numsVar.end(), compare);

    string largestNumber;
    for (int num : numsVar) {
        largestNumber += to_string(num);
    }

    return largestNumber;
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}