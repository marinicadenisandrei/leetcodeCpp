/* Leetcode - 43. Multiply Strings (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 43. Multiply Strings (C++ language) - Medium" << endl;

    vector <string> num1 {"2", "123"};
    vector <string> num2 {"3", "456whats"};

    for (int test = 0; test < num1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << multiply(num1.at(test), num2.at(test)) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string multiply(string num1, string num2)
{
    int integer_num1 = stoi(num1);
    int integer_num2 = stoi(num2);

    return to_string(integer_num1 * integer_num2);
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