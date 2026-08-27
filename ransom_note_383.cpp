/* Leetcode - 383. Ransom Note (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool canConstruct(string ransomNoteVar, string magazineVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    cout << boolalpha;
    
    yellow();

    cout << "Leetcode - 383. Ransom Note (C++ language) - ";

    green();

    cout << "Easy\n";

    vector<string> ransomNote = {"a","aa","aa"};
    vector<string> magazine = {"b","ab","aab"}; 

    for (int test = 0; test < ransomNote.size(); test++)
    {
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << canConstruct(ransomNote[test], magazine[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool canConstruct(string ransomNoteVar, string magazineVar)
{
    std::string noDuplicatesRansomNoteVar;
    std::unordered_set<char> seen;

    for (char c : ransomNoteVar) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            noDuplicatesRansomNoteVar += c;
        }
    }

    for (char c : noDuplicatesRansomNoteVar) {
        int ransomNoteOcc = std::count(ransomNoteVar.begin(), ransomNoteVar.end(), c);
        int magazineOcc = std::count(magazineVar.begin(), magazineVar.end(), c);

        if (ransomNoteOcc > magazineOcc)
        {
            return false;
        }
    }

    return true;
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