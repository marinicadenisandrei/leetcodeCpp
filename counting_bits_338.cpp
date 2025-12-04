/* Leetcode - 338. Counting Bits (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> countBits(int nVar);
void printVector(vector<int> vect);

int main()
{
    yellow();
    
    cout << "Leetcode - 338. Counting Bits (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {2,5};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        printVector(countBits(n[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
    
}

vector<int> countBits(int nVar)
{
    vector<int> result = {};

    for (int i = 0; i <= nVar; i++)
    {
        std::bitset<32> b(i);
        int ones = b.count();
        result.push_back(ones);
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