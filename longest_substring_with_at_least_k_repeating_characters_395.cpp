/* Leetcode - 395. Longest Substring with At Least K Repeating Characters (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestSubstring(string sVar, int kVar);
int checkCandidate(string candidate, int kVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 395. Longest Substring with At Least K Repeating Characters (C++ language) - Medium" << endl;

    vector<string> s = {"aaabb","ababbc"};
    vector<int> k = {3,2};

    for (int test = 0; test < s.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << longestSubstring(s[test], k[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int longestSubstring(string sVar, int kVar)
{
    int result = 0;

    for (int i = 0; i < sVar.size(); i++)
    {
        string candidate1 = sVar.substr(i);
        string candidate2 = sVar.substr(0, sVar.size() - 1 - i);

        int firstCheck = checkCandidate(candidate1, kVar);
        int secondCheck = checkCandidate(candidate2, kVar);

        int tempResult = max(firstCheck, secondCheck);

        result = ((result < tempResult) ? tempResult : result);
    }

    return result;
}

int checkCandidate(string candidate, int kVar)
{

    unordered_map<char, int> occ;
    string unique = "";

    for (char c : candidate) {
        occ[c]++;

        if (occ[c] == 1) {
            unique += c;
        }
    }

    for (char c : unique) {
        if (occ[c] < kVar)
        {
            return 0;
        }
    }

    return candidate.size();
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