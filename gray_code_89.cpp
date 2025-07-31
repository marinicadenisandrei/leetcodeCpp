/* Leetcode - 89. Gray Code (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<int> grayCode(int n);
int bitToDec(string binary);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 89. Gray Code (C++ language) - Medium" << endl;

    vector<int> n {2,1};

    for (int test = 0; test < n.size(); test++)
    {
        vector<int> output = grayCode(n[test]);

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }
    
    cout << " | "; 
}

int bitToDec(string binary)
{   
    int power {0};
    int number {0};

    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            number += pow(2,power);
        }

        power++;
    } 

    return number;
}

vector<int> grayCode(int n)
{
    vector <string> bits {};
    vector <int> decimals {};

    string temp {"00"};
    bits.push_back(temp);

    int shift = ((n <= 1) ? 1 : 0);

    for (int i = n - 1 + shift; i >= 0 + shift; i--)
    {
        temp[i] = '1';
        bits.push_back(temp);
    }

    temp = "00";

    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = '1';
        bits.push_back(temp);
    }

    for (string i : bits)
    {
        int result {bitToDec(i)};
        decimals.push_back(result);
    }

    return decimals;
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