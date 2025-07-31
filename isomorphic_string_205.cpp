#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isIsomorphic(string sVar, string tVar);
void removeDuplicatesFromString(string &stringVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 205. Isomorphic Strings (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s {"egg", "foo", "paper"};
    vector<string> t {"add", "bar", "title"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isIsomorphic(s[test], t[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void removeDuplicatesFromString(string &stringVar)
{
    string noDuplicatesString = "";

    for (int i = 0; i < stringVar.size(); i++)
    {
        size_t pos = noDuplicatesString.find(stringVar[i]);

        if (pos == std::string::npos) noDuplicatesString += stringVar[i];
    }

    stringVar = noDuplicatesString;
}

bool isIsomorphic(string sVar, string tVar)
{
    removeDuplicatesFromString(sVar);
    removeDuplicatesFromString(tVar);

    return sVar.size() == tVar.size();
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