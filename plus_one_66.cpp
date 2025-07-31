/* Leetcode - 66. Plus One (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

vector <int> plusOne(vector <int> digitsVar);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    cout << "Leetcode - 66. Plus One (C++ language) - ";
    
    green();
    
    cout << "Easy" << endl;
    
    vector <vector <int>> digits {{1,2,3}, {4,3,2,1}, {9}};
    
    for (int test = 0; test < digits.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";
        
        reset();
        
        digits[test] = plusOne(digits[test]);
        printVector(digits[test]);   
        
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
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector <int> plusOne(vector <int> digitsVar)
{
    vector <int> newVect {0};
    
    int mulNumber {1};
    int formatNumber  {0};
    
    for (int i = 0; i < digitsVar.size() - 1; i++)
    {
        mulNumber *= 10;
    }
    
    for (int i = 0; i < digitsVar.size(); i++)
    {
        formatNumber += mulNumber * digitsVar[i];
        mulNumber /= 10;
    }
    
    formatNumber += 1;
    
    if (formatNumber % 10 == 0)
    {
        digitsVar.push_back(0);
    }
    
    for (int i = digitsVar.size() - 1; i >= 0 ; i--)
    {
        digitsVar[i] = formatNumber % 10;
        formatNumber /= 10;
    }
    
    return digitsVar;
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
