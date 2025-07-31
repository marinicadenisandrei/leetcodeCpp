/* Leetcode - 279. Perfect Squares (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int numSquares(int nVar);
bool perfectSquare(int n);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 279. Perfect Squares (C++ language) - Medium" << endl;
    
    vector<int> n = {12,13};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << numSquares(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

#include <cmath>

bool perfectSquare(int n)
{
    if (n < 0) return false; 
    
    int sqrt_n = static_cast<int>(sqrt(n));
    return sqrt_n * sqrt_n == n;
}

int numSquares(int nVar)
{
    int squareCut = 0;
    int result = 0;
    int counter = 0;

    for (int i = 2; i < nVar / 2; i++)
    {
        if (perfectSquare(i))
        {
            squareCut = i;
            break;
        }
    } 

    if (perfectSquare(nVar - squareCut))
    {
        return 2;
    }
    
    while (result < nVar)
    {
        if (result + squareCut > nVar)
        {
             for (int i = squareCut + 1; i < nVar; i++)
            {
                if (perfectSquare(i))
                {
                    squareCut = i;
                    break;
                }
            }   
        }
        
        result += squareCut;
        counter++;
    }

    return counter;
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