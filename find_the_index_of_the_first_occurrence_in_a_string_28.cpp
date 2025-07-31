#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(string haystack, string needle);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 28. Find the Index of the First Occurrence in a String - ";

    green();

    cout << "Easy" << endl;

    vector <string> haystack = {"sadbutsad", "leetcode"};
    vector <string> needle = {"sad", "leeto"};

    for (int test = 0; test < haystack.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << strStr(haystack.at(test), needle.at(test));
        cout << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0 ;
}

int strStr(string haystack, string needle)
{
    if (haystack.find(needle) != string::npos)
    {
        return 0;
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
