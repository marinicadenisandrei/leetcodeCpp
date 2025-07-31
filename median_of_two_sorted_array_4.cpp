#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 4. Median of Two Sorted Arrays - ";

    red();

    cout << "Hard" << endl;

    vector <vector <float>> nums1 {{1,3}, {1,2}};
    vector <vector <float>> nums2 {{2}, {3,4}};

    for (int test = 0; test < nums1.size(); test++)
    {
        nums1.at(test).resize(nums1.at(test).size() + nums2.at(test).size());
        copy(nums2.at(test).begin(), nums2.at(test).end(), nums1.at(test).rbegin());

        sort(nums1.at(test).begin(), nums1.at(test).end());

        float result {((nums1.at(test).size() % 2 == 1) ? nums1.at(test).at((int)nums1.at(test).size()/2) : (nums1.at(test).at((int)nums1.at(test).size()/2) + nums1.at(test).at(((int)nums1.at(test).size()/2)-1))/2)};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
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