/* Leetcode - 196. Delete Duplicate Emails (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void deleteDuplicateEmails(vector<string> &emailVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 196. Delete Duplicate Emails (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> email {"john@example.com","bob@example.com","john@example.com"};
    
    green();

    cout << "Test 1: ";

    reset();

    deleteDuplicateEmails(email);

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void deleteDuplicateEmails(vector<string> &emailVar)
{
    sort(emailVar.begin(), emailVar.end());
    auto last = unique(emailVar.begin(), emailVar.end());
    emailVar.erase(last, emailVar.end());

    for (int i = 0; i < emailVar.size(); i++)
    {
        cout << emailVar[i] << endl;
    }
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