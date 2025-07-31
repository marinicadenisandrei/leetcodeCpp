/* Leetcode - 190. Reverse Bits (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

uint32_t reverseBits(uint32_t n);


int main()
{
    yellow();

    cout << "Leetcode - 190. Reverse Bits (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<uint32_t> n = {0b00000010100101000001111010011100, 0b11111111111111111111111111111101};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << reverseBits(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    
    for (int i = 0; i < 32; i++)
    {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
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