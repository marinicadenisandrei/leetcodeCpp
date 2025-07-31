/* Leetcode - 180. Consecutive Numbers (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> consecutiveNumbers(vector<int> numVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 180. Consecutive Numbers (C++ language) - Medium" << endl;

    vector<vector<int>> num {{1,1,1,2,1,2,2}};

    for (int test = 0; test < num.size(); test++)
    {
        green();

        cout << "Test " << test + ": ";

        reset();

        printVector(consecutiveNumbers(num[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> consecutiveNumbers(vector<int> numVar)
{
    int counter = 0;
    vector<int> result {};

    for (int i = 0; i < numVar.size() - 1; i++)
    {
        if (numVar[i] == numVar[i + 1])
        {
            counter++;
        }
        else
        {
            if (counter >= 2)
            {
                result.push_back(numVar[i]);
            }

            counter = 0;
        }   
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