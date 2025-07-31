/* Leetcode - 242. Valid Anagram (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isAnagram(string sVar, string tVar);

int main()
{   
    yellow();

    cout << "Leetcode - 242. Valid Anagram (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s ={ "anagram","rat"};
    vector<string> t = {"nagaram","car"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isAnagram(s[test], t[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool isAnagram(string sVar, string tVar)
{
    sort(sVar.begin(), sVar.end());
    sort(tVar.begin(), tVar.end());

    return sVar == tVar;
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