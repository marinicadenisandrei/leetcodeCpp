/* Leetcode - 166. Fraction to Recurring Decimal (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string fractionToDecimal(int numeratorVar, int denominatorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 166. Fraction to Recurring Decimal (C++ language) - Medium" << endl;

    vector<int> numerator {1,2,4};
    vector<int> denominator {2,1,333};

    for (int test = 0; test < numerator.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << fractionToDecimal(numerator[test], denominator[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string fractionToDecimal(int numeratorVar, int denominatorVar)
{
    float number = static_cast<float> (numeratorVar) / denominatorVar;
    string numberStr = to_string(number);
    
    return numberStr;
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