/* Leetcode - 115. Distinct Subsequences (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void numDistinct(string sVar, string tVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 115. Distinct Subsequences (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> s {"rabbbit","babgbag"};
    vector<string> t {"rabbit","bag"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        numDistinct(s[test], t[test]);
        cout << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void numDistinct(string sVar, string tVar)
{
    int globalCounter {0};

    for (int i = 0; i < tVar.size() - 1; i++)
    {
        // cout << tVar[i];

        int counter {0};
        vector<int> indexArray {};
        bool flag = true;
        bool leftFlag = true;
        bool rightFlag = true;

        for (int j = 0; j < sVar.size(); j++)
        {
            if (tVar[i] == sVar[j])
            {
                counter++;
                indexArray.push_back(j);
            }
        }
        
        if (i == 0)
        {
            string rest = sVar.substr(indexArray.back() + 1, sVar.size() - 1);
            
            for (int j = i + 1; j < tVar.size(); j++)
            {
                size_t found = rest.find(tVar[j]);

                if (found == string::npos)
                {
                    flag = false;
                    break;
                }
            }
        

            if (flag)
            {
                globalCounter += counter;
            }
        }
        else
        {   
            int left = indexArray[0];
            int right = indexArray.back();

            string leftSubstr = sVar.substr(0, left);
            string rightSubstr = sVar.substr(right + 1, sVar.size() - 1);
            
            for (int j = 0; j < i; j++)
            {
                size_t found = leftSubstr.find(tVar[j]);

                if (found == string::npos)
                {
                    leftFlag = false;
                    break;
                }
            }

            for (int j = i + 1; j < tVar.size(); j++)
            {
                size_t found = rightSubstr.find(tVar[j]);

                if (found == string::npos)
                {
                    rightFlag = false;
                    break;
                }
            }

            if (leftFlag && rightFlag)
            {
                globalCounter += counter;
            }
        }
    }

    cout << globalCounter;
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