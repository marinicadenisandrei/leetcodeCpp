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

    cout << "Leetcode - 7. Reverse Integer (C++ language) - Medium" << endl;

    vector <int> xTest {123, -123, 120};

    for (int test = 0; test < xTest.size(); test++)
    {
        int x {xTest[test]};

        bool negative_flag {false};
        negative_flag = ((x < 0) ? true : false);

        string x_string {to_string(x)};
        reverse(x_string.begin(), x_string.end());

        x = stoi(x_string);
        x *= ((negative_flag == true) ? -1 : 1);

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << x << " | ";

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
