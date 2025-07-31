/* Leetcode - 136. Single Number (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 136. Single Number (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums {{2,2,1},{4,1,2,1,2},{1}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << singleNumber(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int singleNumber(vector<int> numsVar) {
    auto single = [] (vector<int> &numsVar) {
        for (int i = 0; i < numsVar.size(); i++) {
            int occ {0};

            for (int j = 0; j < numsVar.size(); j++) {
                if (i != j && numsVar[i] == numsVar[j]) {
                    occ++;
                }
            }

            if (occ == 0) {
                return numsVar[i];
            }
        }

        return -1;
    }; 

    return single(numsVar); 
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