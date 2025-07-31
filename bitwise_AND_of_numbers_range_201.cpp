/* Leetcode - 201. Bitwise AND of Numbers Range (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int rangeBitwiseAnd(int leftVar, int rightVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 201. Bitwise AND of Numbers Range (C++ language) - Medium" << endl;

    vector<int> left {5,0,1};
    vector<int> right {7,0,2147483647};

    for (int test = 0; test < left.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();
 
        cout << rangeBitwiseAnd(left[test], right[test]) << " | ";

        green();

        cout << "Passed" << endl;   
    }

    reset();

    return 0;
}

int rangeBitwiseAnd(int left, int right) {
    int shift = 0;

    while (left < right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    return left << shift;
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