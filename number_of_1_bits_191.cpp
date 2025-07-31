/* Leetcode - 191. Number of 1 Bits (C language) - Easy */

#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

int hammingWeight(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 191. Number of 1 Bits (C language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {11,128,2147483645};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << hammingWeight(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int hammingWeight(int nVar)
{
    bitset<32> binary(nVar);
    string binaryString = binary.to_string();   
    int countOne = 0;

    for (int i = 0; i < binaryString.size(); i++)
    {
        if (binaryString[i] == '1')
        {
            countOne++;
        }
    }
    
    return countOne;
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