#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string &s);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 125. Valid Palindrome (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s = {"A man, a plan, a canal: Panama","race a car"," "};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isPalindrome(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

bool isPalindrome(string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return c < 'a' || c > 'z'; }), s.end());
    
    string original = s;
    reverse(s.begin(), s.end());
    
    if (original == s)
    {
        return true;
    }
    
    return false;
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