/* Leetcode - 8. String to Integer (atoi) (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 8. String to Integer (atoi) (C++ language) - Medium" << endl;

    vector <string> s {"42", "   -42", "4193 with words"};
    
    for (int test = 0; test < s.size(); test++)
    {
        int integer {stoi(s.at(test))};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << integer << " | ";

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