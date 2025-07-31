/* Leetcode - 9. Palindrome Number (C++ language) -  Easy*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 9. Palindrome Number (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <int> xTest {121, -121, 10};

    for (int test {0}; test < xTest.size(); test++)
    {
        int x {xTest.at(test)};

        x *= ((x < 0) ? -1 : 1);

        string string_number {to_string(x)};

        reverse(string_number.begin(), string_number.end());
        int reverse_integer {stoi(string_number)};

        bool flag {((x == reverse_integer) ? true : false)};

        cout << boolalpha;

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << flag << " | ";

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