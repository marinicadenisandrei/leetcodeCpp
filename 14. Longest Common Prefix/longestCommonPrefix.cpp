/* Leetcode - 14. Longest Common Prefix (C language) */

#include <iostream>
using namespace std;

#define NUMBER_OF_TESTS 2

int main()
{
    cout << "Leetcode - 14. Longest Common Prefix (C language)" << endl;

    string strs[10][20] {{"flower", "flow", "flight"}, {"dog", "racecar", "car"}};
    int sizeTest[] = {3,3};
    int flag {true};
    int index {0};
    int sizeStrs {0};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        sizeStrs = sizeTest[test];

        while (flag)
        {
            for (int i = 0; i < sizeStrs-1; i++)
            {
                flag = (strs[test][i][index] != strs[test][i+1][index]) ? false : flag;
                
                if (flag == false)
                {
                    break;
                }
            }

            if (flag == false)
            {
                break;
            }
            
            index++;
        }

        cout << "Test " << test+1 << ": \"";

        for (int i = 0; i < index; i++)
        {
            cout << strs[test][0][i];
        }

        cout << "\"  | Passed" << endl;
        index = 0;
        flag = true;
    }

    return 0;
}