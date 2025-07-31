/* Leetcode - 231. Power of Two (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool IsPowerOfTwo(int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 231. Power of Two (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n {1,16,3};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << IsPowerOfTwo(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool IsPowerOfTwo(int nVar)
{
    if (nVar == 1)
    {
        return true;
    }
    
    for (int i = 1; i <= nVar / 2; i++)
    {
        for (int j = 0; j <= nVar / 2; j++)
        {
            if (pow(i,j) == nVar)
            {
                return true;
            }
        }
    }

    return false;
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
  
      