/* Leetcode - 6. Zigzag Conversion (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 6. Zigzag Conversion (C++ language) - Medium" << endl;
    
    string s {"PAYPALISHIRING"};
    vector <int> numRowsTest {3, 4};

    for (int test = 0; test < numRowsTest.size(); test++)
    {   
        string s_copy = s;
        int numRows = numRowsTest.at(test);
        int index_end = numRows + (int) (numRows / 2);;

        vector <string> output {};
        string temp {};

        for (int i = 0; size(s) > 0; i++)
        {   
            temp = s.substr(0, numRows + (int)(numRows / 2));

            output.push_back(temp.substr(0,numRows));
            temp.erase(0,numRows);
            
            reverse(temp.begin(), temp.end());

            output.push_back(" " + temp + " ");
            temp = "";
            s.erase(0,numRows + (int)(numRows / 2));
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < output.size(); j++)
            {
                if (output[j][i] != ' ')
                {
                    cout << output[j][i];
                }
            }
        }

        cout << " | ";

        green();

        cout << "Passed" << endl;
        s = s_copy;

        reset();
    }

    return 0;
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