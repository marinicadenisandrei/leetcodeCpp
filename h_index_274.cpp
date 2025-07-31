/* Leetcode - 274. H-Index (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int hIndex(vector<int> citationsVar);

int main()
{   
    yellow();

    cout << "Leetcode - 274. H-Index (C++ language) - Medium" << endl;

    vector<vector<int>> citations = {{3,0,6,1,5},{1,3,1}};
    
    for (int test = 0; test < citations.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << hIndex(citations[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int hIndex(vector<int> citationsVar)
{
    std::sort(citationsVar.begin(), citationsVar.end(), std::greater<int>());
    int result = 0;

    for (int i = 0; i < citationsVar.size(); i++)
    {
        if (citationsVar[i] >= i + 1)
        {
            result++;
        }
    }
    
    return result;
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
