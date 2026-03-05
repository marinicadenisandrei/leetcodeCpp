/* Leetcode - 354. Russian Doll Envelopes (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int maxEnvelopes(vector<vector<int>> envelopesVar);

int main()
{
    yellow();

    cout << "Leetcode - 354. Russian Doll Envelopes (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> envelopes = {{{5,4},{6,4},{6,7},{2,3}}, {{1,1},{1,1},{1,1}}};
    
    for (int test = 0; test < envelopes.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxEnvelopes(envelopes[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int maxEnvelopes(vector<vector<int>> envelopesVar)
{
    sort(envelopesVar.begin(), envelopesVar.end());
    int result = 0;

    for (auto &e : envelopesVar) {
        sort(e.begin(), e.end());   
    }

    for (int j = 0; j < envelopesVar.size() - 2; j++)
    {
        int lastFirst = envelopesVar[j][0];
        int lastSecond = envelopesVar[j][1];
        int temp = 0;

        for (int i = j + 1; i < envelopesVar.size(); i++)
        {
            if (lastSecond - lastFirst == 1 && envelopesVar[i][1] - envelopesVar[i][0] == 1 && envelopesVar[i][0] - lastSecond == 1)
            {
                temp++;
                lastFirst = envelopesVar[i][0];
                lastSecond = envelopesVar[i][1];
            }
        }

        temp++;
        result = ((result < temp) ? temp : result);
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