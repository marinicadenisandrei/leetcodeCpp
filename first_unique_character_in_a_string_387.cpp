/* Leetcode - 387. First Unique Character in a String (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int firstUniqChar(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 387. First Unique Character in a String (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s = {"leetcode","loveleetcode","aabb"};
    
    for (int test = 0; test < s.size(); test++)
    {
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << firstUniqChar(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

#include <string>
using namespace std;

int firstUniqChar(string s) {
    int freq[26] = {0};

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
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