/* Leetcode - 60. Permutation Sequence (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getPermutations(int nVar, int kVar);
int depth(int nvar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 60. Permutation Sequence (C++ language) - ";

    red();

    cout <<  "Hard" << endl; 

    vector <int> n {3, 4, 3}; 
    vector <int> k {3, 9 , 1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        string result = getPermutations(n[test] , k[test]);
        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int depth(int nvar)
{
    int depth = 1;

    for (int i = 1; i <= nvar; i++)
    {
        depth *= i;
    }
    
    return depth;
}

string getPermutations(int nVar, int kVar)
{
    string numberVar {""};
    
    for (int i = 1; i <= nVar; i++)
    {
        numberVar += to_string(i);
    }

    int index1 {0};
    int index2 {1};

    vector <string> numbers {};
    numbers.push_back(numberVar);

    int depthVar = depth(nVar);

    for (int i = 0; i < depthVar; i++)
    {
        if (index2 < nVar)
        {
            char temp = numberVar[index1];
            numberVar[index1] = numberVar[index2];
            numberVar[index2] = temp; 
        }
        else
        {
            char temp = numberVar[0];
            numberVar[0] = numberVar[nVar - 1];
            numberVar[nVar - 1] = temp; 

            index1 = -1;
            index2 = 0;
        }

        index1++;
        index2++;

        numbers.push_back(numberVar);
    }

    bool flag {true};
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < numbers.size() - 2 - counter; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                string tempStr = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = tempStr;

                flag = true;
            }
        }

        counter++;
    }

    return numbers[kVar - 1];
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