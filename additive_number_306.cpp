/* Leetcode - 306. Additive Number (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isAdditiveNumber(string sVar);

int main()
{   
    yellow();

    cout << "Leetcode - 306. Additive Number (C++ language) - Medium" << endl;

    vector<string> s = {"112358","199100199"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << boolalpha << isAdditiveNumber(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool isAdditiveNumber(string sVar)
{
    int index = 0;
    int last = 0;

    int t1 = sVar[0] - '0';
    int t2 = 0;
    int r = 0;

    bool flag = true;

    for (int i = 0; i < sVar.size() - 2; i++)
    {
        flag = false;

        for (int j = 1; j <= 3; j++)
        {
            string substr = sVar.substr(index + 1, j);
            
            t2 = stoi(substr);
            r = t1 + t2;

            string r_str = to_string(r);
            size_t ind_f = sVar.rfind(r_str);

            if (ind_f == index + 1 + j && ind_f != std::string::npos)
            {
                t1 = t2;
                index = index + j;
                flag = true;
                last = ind_f + j;
                break;
            }
        }

        if (!flag && last != sVar.size())
        {
            return false;
        }
        
    }

    return true;
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