/* Leetcode - 386. Lexicographical Numbers (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> lexicalOrder(int nVar);
void printVector(const vector<int>& vec);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 386. Lexicographical Numbers (C++ language) - Medium" << endl;

    vector<int> n = {13,2};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();
        
        printVector(lexicalOrder(n[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

vector<int> lexicalOrder(int nVar)
{
    vector<string> resultString = {};
    vector<int> result = {};
    
    for (int i = 1; i <= nVar; i++)
    {
        resultString.push_back(to_string(i));
    }

    int c = 0;
    bool flag = true;
    
    while (flag)
    {
        flag = false;

        for (int i = 0; i < resultString.size() - 1 - c; i++)
        {
            if (resultString[i] > resultString[i + 1])
            {
                string temp = resultString[i];
                resultString[i] = resultString[i + 1];
                resultString[i + 1] = temp;

                flag = true;
            }
        }

        c++;
    }

    for (int i = 0; i < resultString.size(); i++)
    {
        result.push_back(stoi(resultString[i]));
    }

    return result;
}

void printVector(const vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << ((i == 0) ? "[" : ", ") << vec[i] << ((i == vec.size() - 1) ? "] | " : "");
    }
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